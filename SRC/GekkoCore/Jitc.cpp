#include "pch.h"

namespace Gekko
{
	Jitc::Jitc(GekkoCore* _core)
	{
		core = _core;
	}

	Jitc::~Jitc()
	{
		InvalidateAll();
	}

	CodeSegment* Jitc::SegmentCompiled(uint32_t addr)
	{
		auto it = segments.find(addr >> 2);

		if (it != segments.end())
		{
			return it->second;
		}

		return nullptr;
	}

	CodeSegment* Jitc::CompileSegment(uint32_t addr)
	{
		AnalyzeInfo info = { 0 };
		CodeSegment* segment = new CodeSegment();

		segment->addr = addr;
		segment->code.reserve(0x100);
		segment->core = core;

		Prolog(segment);

		size_t n = maxInstructions;

		while (n--)
		{
			if (core->TestBreakpointForJitc(addr))
				break;

			int WIMG;
			uint32_t physicalAddress = core->EffectiveToPhysical(addr, MmuAccess::Execute, WIMG);
			uint32_t instr;

			// TODO: This moment needs to be rethinked. It makes little sense to generate ISI in the compilation process, 
			// you need to do this in the process of executing compiled code.
			// Most likely you need to inject code to generate ISI and break segment compilation.

			if (physicalAddress == BadAddress)
			{
				core->Exception(Exception::ISI);
				break;
			}

			PIReadWord(physicalAddress, &instr);

			Analyzer::AnalyzeFast(addr, instr, &info);

			CompileInstr(&info, segment);

			addr += 4;
			segment->size += 4;

			if (info.flow)
				break;
		}

		Epilog(segment);

		segments[segment->addr >> 2] = segment;

#ifdef _WINDOWS
		DWORD notNeeded;
		VirtualProtect(segment->code.data(), segment->code.size(), PAGE_EXECUTE_READWRITE, &notNeeded);
#endif

#ifdef _LINUX
		// TODO
#endif

		core->compiledSegments++;

		return segment;
	}

	void CodeSegment::Run()
	{
		//DBReport2(DbgChannel::CPU, "Run code segment: 0x%08X, segs: %i\n", addr, core->segmentsExecuted);

		void (*codePtr)() = (void (*)())code.data();
		codePtr();

		core->executedSegments++;
	}

	void CodeSegment::Write8(uint8_t data)
	{
		code.push_back(data);
	}

	void CodeSegment::Write16(uint16_t data)
	{
		Write8((uint8_t)data);
		Write8((uint8_t)(data >> 8));
	}

	void CodeSegment::Write32(uint32_t data)
	{
		Write16((uint16_t)data);
		Write16((uint16_t)(data >> 16));
	}

	void CodeSegment::Write64(uint64_t data)
	{
		Write32((uint32_t)data);
		Write32((uint32_t)(data >> 32));
	}

	void CodeSegment::Write(const IntelCore::AnalyzeInfo& info)
	{
		for (size_t i = 0; i < info.prefixSize; i++)
		{
			code.push_back(info.prefixBytes[i]);
		}

		for (size_t i = 0; i < info.instrSize; i++)
		{
			code.push_back(info.instrBytes[i]);
		}
	}

	void Jitc::InvalidateAll()
	{
		for (auto it = segments.begin(); it != segments.end(); ++it)
		{
			if (it->second)
			{
				if (it->second == currentSegment)
				{
					continue;
				}

				delete it->second;
				it->second = nullptr;
			}
		}
		segments.clear();
	}

	void Jitc::Invalidate(uint32_t addr, size_t size)
	{
		for (auto it = segments.begin(); it != segments.end(); ++it)
		{
			CodeSegment* seg = it->second;
			if (seg != nullptr)
			{
				// If a invalidated region crosses a segment somehow, invalidate the entire segment.

				if (addr >= seg->addr && seg->addr < (addr + size))
				{
					if (it->second != currentSegment)
					{
						delete it->second;
						it->second = nullptr;
						continue;
					}
				}

				if (seg->addr >= addr && addr < (seg->addr + seg->size))
				{
					if (it->second != currentSegment)
					{
						delete it->second;
						it->second = nullptr;
						continue;
					}
				}
			}
		}
	}

	void Jitc::Execute()
	{
		currentSegment = SegmentCompiled(core->regs.pc);
		if (currentSegment == nullptr)
		{
			currentSegment = CompileSegment(core->regs.pc);
		}
		assert(currentSegment);

		currentSegment->Run();

		// Branch-specific checks

		if (!core->exception)
		{
			if (core->intFlag && (core->regs.msr & MSR_EE))
			{
				core->Exception(Gekko::Exception::INTERRUPT);
				return;
			}

			if (core->decreq && (core->regs.msr & MSR_EE))
			{
				core->decreq = false;
				core->Exception(Gekko::Exception::DECREMENTER);
			}
		}

		core->exception = false;

		if (core->resetInstructionCounter)
		{
			core->resetInstructionCounter = false;
			core->ops = 0;
		}
	}

	bool Jitc::ExecuteInterpeterFallback()
	{
		return Gekko->interp->ExecuteInterpeterFallback();
	}

	void Jitc::Reset()
	{
		InvalidateAll();
	}

	void Jitc::Tick()
	{
		Gekko->Tick();
		Gekko->ops++;
	}

	void Jitc::CompileInstr(AnalyzeInfo* info, CodeSegment* seg)
	{
		switch (info->instr)
		{
			case Instruction::add: Add(info, seg); break;
			//case Instruction::add_d: Addd(info, seg); break;
			//case Instruction::addo: Addo(info, seg); break;
			//case Instruction::addo_d: Addod(info, seg); break;

			case Instruction::b: Branch(info, seg, false); break;
			case Instruction::ba: Branch(info, seg, false); break;
			case Instruction::bl: Branch(info, seg, true); break;
			case Instruction::bla: Branch(info, seg, true); break;

			case Instruction::lbz: LoadImm(info, seg, ReadByte); break;
			case Instruction::lhz: LoadImm(info, seg, ReadHalf); break;
			case Instruction::lwz: LoadImm(info, seg, ReadWord); break;

			case Instruction::rlwinm: Rlwinm(info, seg); break;

			case Instruction::ps_add: PsAdd(info, seg); break;
			case Instruction::ps_sub: PsSub(info, seg); break;
			case Instruction::ps_merge00: PsMerge00(info, seg); break;
			case Instruction::ps_merge01: PsMerge01(info, seg); break;
			case Instruction::ps_merge10: PsMerge10(info, seg); break;
			case Instruction::ps_merge11: PsMerge11(info, seg); break;

			//case Instruction::psq_l: PSQLoad(info, seg); break;

			default:
#if GEKKOCORE_JITC_HALT_ON_UNIMPLEMENTED_OPCODE
				Debug::Halt("Unimplemented opcode %s\n", Gekko::GekkoDisasm::InstrToString(info).c_str());
#else
				FallbackStub(info, seg);
#endif
				break;
		}
	}

}
