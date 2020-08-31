// DSP analyzer
#include "pch.h"

namespace DSP
{
	void Analyzer::ResetInfo(AnalyzeInfo& info)
	{
		info.sizeInBytes = 0;

		info.parallel = false;
		info.parallelMemInstr = DspParallelMemInstruction::Unknown;
		info.instr = DspRegularInstruction::Unknown;

		info.numParameters = 0;
		info.numParametersEx = 0;

		info.flowControl = false;
	}

	void Analyzer::AddParam(AnalyzeInfo& info, DspParameter param)
	{
		assert(info.numParameters < DspAnalyzeNumParam);

		info.params[info.numParameters] = param;
		info.numParameters++;
	}

	void Analyzer::AddParamEx(AnalyzeInfo& info, DspParameter param)
	{
		assert(info.numParametersEx < DspAnalyzeNumParam);

		info.paramsEx[info.numParametersEx] = param;
		info.numParametersEx++;
	}

	void Analyzer::AddImmOperand(AnalyzeInfo& info, DspParameter param, uint8_t imm)
	{
		AddParam(info, param);
		if (param == DspParameter::Byte)
			info.ImmOperand.Byte = imm;
		else if (param == DspParameter::Byte2)
			info.ImmOperand2.Byte = imm;
	}

	void Analyzer::AddImmOperand(AnalyzeInfo& info, DspParameter param, int8_t imm)
	{
		AddParam(info, param);
		if (param == DspParameter::SignedByte)
			info.ImmOperand.SignedByte = imm;
		else if (param == DspParameter::SignedByte2)
			info.ImmOperand2.SignedByte = imm;
	}

	void Analyzer::AddImmOperand(AnalyzeInfo& info, DspParameter param, uint16_t imm)
	{
		AddParam(info, param);
		if (param == DspParameter::UnsignedShort)
			info.ImmOperand.UnsignedShort = imm;
		else if (param == DspParameter::UnsignedShort2)
			info.ImmOperand2.UnsignedShort = imm;
	}

	void Analyzer::AddImmOperand(AnalyzeInfo& info, DspParameter param, int16_t imm)
	{
		AddParam(info, param);
		if (param == DspParameter::SignedShort)
			info.ImmOperand.SignedShort = imm;
		else if (param == DspParameter::SignedShort2)
			info.ImmOperand2.SignedShort = imm;
	}

	void Analyzer::AddImmOperand(AnalyzeInfo& info, DspParameter param, DspAddress imm)
	{
		AddParam(info, param);
		if (param == DspParameter::Address)
			info.ImmOperand.Address = imm;
		else if (param == DspParameter::Address2)
			info.ImmOperand2.Address = imm;
	}

	void Analyzer::AddBytes(uint8_t* instrPtr, size_t bytes, AnalyzeInfo& info)
	{
		assert(info.sizeInBytes < sizeof(info.bytes));

		memcpy(&info.bytes[info.sizeInBytes], instrPtr, bytes);
		info.sizeInBytes += bytes;
	}

	void Analyzer::Group0(uint8_t* instrPtr, size_t instrMaxSize, AnalyzeInfo& info, uint16_t instrBits)
	{
		static DspParameter addressreg[] = {
			DspParameter::r0,
			DspParameter::r1,
			DspParameter::r2,
			DspParameter::r3,
		};

		static DspParameter topreg[] = {
			DspParameter::x0,
			DspParameter::y0,
			DspParameter::x1,
			DspParameter::y1,
			DspParameter::a0,
			DspParameter::b0,
			DspParameter::a1,
			DspParameter::b1,
		};

		static DspParameter modifier[] = {	// pld
			DspParameter::mod_none,
			DspParameter::mod_dec,
			DspParameter::mod_inc,
			DspParameter::mod_plus_m,
		};

		switch ((instrBits >> 8) & 0xf)
		{
			//|nop         |0000 0000 0[00]0 0000|
			//|mr rn,mn    |0000 0000 0[00]m mmrr|
			//|trap        |0000 0000 0[01]0 0000|
			//|wait        |0000 0000 0[01]0 0001|
			//|repr reg    |0000 0000 0[10]r rrrr|
			//|loopr reg,ea|0000 0000 0[11]r rrrr aaaa aaaa aaaa aaaa|
			//|mvli d,li   |0000 0000 1[00]d dddd iiii iiii iiii iiii|
			//|ldla d,la   |0000 0000 1[10]d dddd aaaa aaaa aaaa aaaa|
			//|stla la,s   |0000 0000 1[11]s ssss aaaa aaaa aaaa aaaa|

			case 0:
				if ((instrBits & 0x80) == 0)
				{
					switch ((instrBits >> 5) & 3)
					{
						case 0:		// nop, mr
						{
							int r = instrBits & 3;
							int m = (instrBits >> 2) & 7;
							if ((r == 0) && (m == 0))
							{
								info.instr = DspRegularInstruction::nop;
							}
							else
							{
								info.instr = DspRegularInstruction::mr;
								AddParam(info, addressreg[r]);
								AddParam(info, (DspParameter)((int)DspParameter::mod_base + m));
							}
							break;
						}
						case 1:		// trap, wait
						{
							info.instr = (instrBits & 1) == 0 ? DspRegularInstruction::trap : DspRegularInstruction::wait;
							info.flowControl = true;
							break;
						}
						case 2:		// repr
						{
							info.instr = DspRegularInstruction::rep;
							info.flowControl = true;
							int r = instrBits & 0x1f;
							AddParam(info, (DspParameter)((int)DspParameter::regs + r));
							break;
						}
						case 3:		// loopr
						{
							info.instr = DspRegularInstruction::loop;
							info.flowControl = true;
							int r = instrBits & 0x1f;
							AddParam(info, (DspParameter)((int)DspParameter::regs + r));
							DspAddress addr = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
							AddBytes(instrPtr, sizeof(uint16_t), info);
							AddImmOperand(info, DspParameter::Address, addr);
							break;
						}
					}
				}
				else
				{
					switch ((instrBits >> 5) & 3)
					{
						case 0:		// mvli
						{
							info.instr = DspRegularInstruction::mvli;
							int r = instrBits & 0x1f;
							uint16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
							AddBytes(instrPtr, sizeof(uint16_t), info);
							AddParam(info, (DspParameter)((int)DspParameter::regs + r));
							AddImmOperand(info, DspParameter::UnsignedShort, imm);
							break;
						}
						case 1:
							// Reserved
							break;
						case 2:		// ldla
						{
							info.instr = DspRegularInstruction::ldla;
							int r = instrBits & 0x1f;
							DspAddress addr = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
							AddBytes(instrPtr, sizeof(uint16_t), info);
							AddParam(info, (DspParameter)((int)DspParameter::regs + r));
							AddImmOperand(info, DspParameter::Address, addr);
							break;
						}
						case 3:		// stla
						{
							info.instr = DspRegularInstruction::stla;
							int r = instrBits & 0x1f;
							DspAddress addr = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
							AddBytes(instrPtr, sizeof(uint16_t), info);
							AddImmOperand(info, DspParameter::Address, addr);
							AddParam(info, (DspParameter)((int)DspParameter::regs + r));
							break;
						}
					}
				}
				break;

			case 1:
				// Reserved
				break;

			//|adli d,li   |0000 001d 0000 0000 iiii iiii iiii iiii|
			//|norm d,rn   |0000 001d 0000 01rr|
			//|negc d      |0000 001d 0000 1101|
			//|pld d,rn,mn |0000 001d 0001 mmrr|
			//|xorli d,li  |0000 001d 0010 0000 iiii iiii iiii iiii|
			
			//|anli d,li   |0000 001d 0100 0000 iiii iiii iiii iiii|
			//|orli d,li   |0000 001d 0110 0000 iiii iiii iiii iiii|
			//|div d,s     |0000 001d 0ss0 1000|
			//|max d,s     |0000 001d 0ss0 1001|
			//|lsf d,s     |0000 001d 01s0 1010|
			//|asf d,s     |0000 001d 01s0 1011|

			//|exec(cc)    |0000 0010 0111 cccc|
			//|cmpli s,li  |0000 001s 1000 0000 iiii iiii iiii iiii|
			//|addc d,s    |0000 001d 10s0 1100|
			//|subc d,s    |0000 001d 10s0 1101|
			//|jmp(cc) ta  |0000 0010 1001 cccc aaaa aaaa aaaa aaaa|
			//|btstl d,bs  |0000 001d 1010 0000 bbbb bbbb bbbb bbbb|
			//|call(cc) ta |0000 0010 1011 cccc aaaa aaaa aaaa aaaa|
			//|btsth d,bs  |0000 001d 1100 0000 bbbb bbbb bbbb bbbb|
			//|lsf d,s     |0000 001d 1100 1010|
			//|asf d,s     |0000 001d 1100 1011|
			//|rets(cc)    |0000 0010 1101 cccc|
			//|reti(cc)    |0000 0010 1111 cccc|

			case 2:
			case 3:
				switch ((instrBits >> 4) & 0xf)
				{
					case 0:		// adli, norm, negc + div, max
						switch (instrBits & 0xf)
						{
							case 0:		// adli
							{
								info.instr = DspRegularInstruction::adli;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
								AddBytes(instrPtr, sizeof(uint16_t), info);
								AddImmOperand(info, DspParameter::SignedShort, imm);
								break;
							}
							case 4:		// norm
							case 5:
							case 6:
							case 7:
							{
								info.instr = DspRegularInstruction::norm;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int r = instrBits & 3;
								AddParam(info, addressreg[r]);
								break;
							}
							case 8:		// div
							{
								info.instr = DspRegularInstruction::div;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
							case 9:		// max
							{
								info.instr = DspRegularInstruction::max;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
							case 0xd:	// negc
							{
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								break;
							}
						}
						break;
					case 1:		// pld
					{
						info.instr = DspRegularInstruction::pld;
						int d = (instrBits & 0x100) ? 1 : 0;
						AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
						int r = instrBits & 3;
						AddParam(info, addressreg[r]);
						int m = (instrBits >> 2) & 3;
						AddParam(info, modifier[m]);
						break;
					}
					case 2:		// xorli + div, max
						switch (instrBits & 0xf)
						{
							case 0:		// xorli
							{
								info.instr = DspRegularInstruction::xorli;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								uint16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
								AddBytes(instrPtr, sizeof(uint16_t), info);
								AddImmOperand(info, DspParameter::UnsignedShort, imm);
								break;
							}
							case 8:		// div
							{
								info.instr = DspRegularInstruction::div;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
							case 9:		// max
							{
								info.instr = DspRegularInstruction::max;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
						}
						break;
					case 3:
					case 5:
						// Reserved
						break;

					case 4:		// anli + div, max + lsf, asf
						switch (instrBits & 0xf)
						{
							case 0:		// anli
							{
								info.instr = DspRegularInstruction::anli;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								uint16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
								AddBytes(instrPtr, sizeof(uint16_t), info);
								AddImmOperand(info, DspParameter::UnsignedShort, imm);
								break;
							}
							case 8:		// div
							{
								info.instr = DspRegularInstruction::div;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
							case 9:		// max
							{
								info.instr = DspRegularInstruction::max;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
							case 0xa:		// lsf
							{
								info.instr = DspRegularInstruction::lsf;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x1 : DspParameter::y1);
								break;
							}
							case 0xb:		// asf
							{
								info.instr = DspRegularInstruction::asf;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x1 : DspParameter::y1);
								break;
							}
						}
						break;
					case 6:		// orli + div, max + lsf, asf
						switch (instrBits & 0xf)
						{
							case 0:		// orli
							{
								info.instr = DspRegularInstruction::anli;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								uint16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
								AddBytes(instrPtr, sizeof(uint16_t), info);
								AddImmOperand(info, DspParameter::UnsignedShort, imm);
								break;
							}
							case 8:		// div
							{
								info.instr = DspRegularInstruction::div;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
							case 9:		// max
							{
								info.instr = DspRegularInstruction::max;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits >> 5) & 3;
								AddParam(info, topreg[s]);
								break;
							}
							case 0xa:		// lsf
							{
								info.instr = DspRegularInstruction::lsf;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x1 : DspParameter::y1);
								break;
							}
							case 0xb:		// asf
							{
								info.instr = DspRegularInstruction::asf;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x1 : DspParameter::y1);
								break;
							}
						}
						break;

					case 7:		// exec
					{
						info.instr = DspRegularInstruction::exec;
						info.flowControl = true;
						info.cc = (ConditionCode)(instrBits & 0xf);
						break;
					}
					case 8:		// cmpli + addc, subc
						switch (instrBits & 0xf)
						{
							case 0:		// cmpli
							{
								info.instr = DspRegularInstruction::cmpli;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
								AddBytes(instrPtr, sizeof(uint16_t), info);
								AddImmOperand(info, DspParameter::SignedShort, imm);
								break;
							}
							case 0xc:		// addc
							{
								info.instr = DspRegularInstruction::addc;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x : DspParameter::y);
								break;
							}
							case 0xd:		// subc
							{
								info.instr = DspRegularInstruction::subc;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x : DspParameter::y);
								break;
							}
						}
						break;
					case 9:		// jmp
					{
						info.instr = DspRegularInstruction::jmp;
						info.flowControl = true;
						info.cc = (ConditionCode)(instrBits & 0xf);
						DspAddress addr = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
						AddBytes(instrPtr, sizeof(uint16_t), info);
						AddImmOperand(info, DspParameter::Address, addr);
						break;
					}
					case 0xa:	// btstl + addc, subc
						switch (instrBits & 0xf)
						{
							case 0:		// btstl
							{
								info.instr = DspRegularInstruction::btstl;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								uint16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
								AddBytes(instrPtr, sizeof(uint16_t), info);
								AddImmOperand(info, DspParameter::UnsignedShort, imm);
								break;
							}
							case 0xc:		// addc
							{
								info.instr = DspRegularInstruction::addc;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x : DspParameter::y);
								break;
							}
							case 0xd:		// subc
							{
								info.instr = DspRegularInstruction::subc;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								int s = (instrBits & 0x20) ? 1 : 0;
								AddParam(info, s == 0 ? DspParameter::x : DspParameter::y);
								break;
							}
						}
						break;
					case 0xb:	// call
					{
						info.instr = DspRegularInstruction::call;
						info.flowControl = true;
						info.cc = (ConditionCode)(instrBits & 0xf);
						DspAddress addr = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
						AddBytes(instrPtr, sizeof(uint16_t), info);
						AddImmOperand(info, DspParameter::Address, addr);
						break;
					}
					case 0xc:	// btsth, lsf, asf
						switch (instrBits & 0xf)
						{
							case 0:		// btsth
							{
								info.instr = DspRegularInstruction::btsth;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								uint16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
								AddBytes(instrPtr, sizeof(uint16_t), info);
								AddImmOperand(info, DspParameter::UnsignedShort, imm);
								break;
							}
							case 0xa:		// lsf
							{
								info.instr = DspRegularInstruction::lsf;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								AddParam(info, d == 0 ? DspParameter::b1 : DspParameter::a1);
								break;
							}
							case 0xb:		// asf
							{
								info.instr = DspRegularInstruction::asf;
								int d = (instrBits & 0x100) ? 1 : 0;
								AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
								AddParam(info, d == 0 ? DspParameter::b1 : DspParameter::a1);
								break;
							}
						}
						break;
					case 0xd:	// rets
					{
						info.instr = DspRegularInstruction::rets;
						info.flowControl = true;
						info.cc = (ConditionCode)(instrBits & 0xf);
						break;
					}
					case 0xe:
						// Reserved
						break;
					case 0xf:	// reti
					{
						info.instr = DspRegularInstruction::reti;
						info.flowControl = true;
						info.cc = (ConditionCode)(instrBits & 0xf);
						break;
					}
				}
				break;

			//|adsi d,si   |0000 010d iiii iiii|

			case 4:
			case 5:
			{
				info.instr = DspRegularInstruction::adsi;
				int r = (instrBits & 0x100) ? 1 : 0;
				AddParam(info, r == 0 ? DspParameter::a : DspParameter::b);
				AddImmOperand(info, DspParameter::SignedByte, (int8_t)instrBits);
				break;
			}

			//|cmpsi s,si  |0000 011s iiii iiii|

			case 6:
			case 7:
			{
				info.instr = DspRegularInstruction::cmpsi;
				int r = (instrBits & 0x100) ? 1 : 0;
				AddParam(info, r == 0 ? DspParameter::a : DspParameter::b);
				AddImmOperand(info, DspParameter::SignedByte, (int8_t)instrBits);
				break;
			}

			//|mvsi d,si   |0000 1ddd iiii iiii|

			case 8:
			case 9:
			case 0xa:
			case 0xb:
			case 0xc:
			case 0xd:
			case 0xe:
			case 0xf:
			{
				info.instr = DspRegularInstruction::mvsi;
				AddParam(info, topreg[(instrBits >> 8) & 7]);
				AddImmOperand(info, DspParameter::SignedByte, (int8_t)instrBits);
				break;
			}
		}
	}

	void Analyzer::Group1(uint8_t* instrPtr, size_t instrMaxSize, AnalyzeInfo& info, uint16_t instrBits)
	{
		static DspParameter addressreg[] = {
			DspParameter::r0,
			DspParameter::r1,
			DspParameter::r2,
			DspParameter::r3,
		};

		static DspParameter modifier[] = {
			DspParameter::mod_none,
			DspParameter::mod_dec,
			DspParameter::mod_inc,
			DspParameter::mod_plus_m,
		};

		//|rep rc      |0001 0000 cccc cccc|
		//|loop lc,ea  |0001 0001 cccc cccc aaaa aaaa aaaa aaaa|
		//|clr b       |0001 0010 0000 0bbb|
		//|set b       |0001 0011 0000 0bbb|
		//|lsfi d,si   |0001 010d 0iii iiii|
		//|asfi d,si   |0001 010d 1iii iiii|
		//|stli sa,li  |0001 0110 aaaa aaaa iiii iiii iiii iiii|
		//|jmp(cc) rn  |0001 0111 0rr0 cccc|
		//|call(cc) rn |0001 0111 0rr1 cccc|
		//|ld d,r,m    |0001 100m mrrd dddd|
		//|st r,m,s    |0001 101m mrrs ssss|
		//|mv d,s      |0001 11dd ddds ssss|

		switch ((instrBits >> 8) & 0xf)
		{
			case 0:		// rep
			{
				info.instr = DspRegularInstruction::rep;
				info.flowControl = true;
				AddImmOperand(info, DspParameter::Byte, (uint8_t)instrBits);
				break;
			}
			case 1:		// loop
			{
				info.instr = DspRegularInstruction::rep;
				info.flowControl = true;
				AddImmOperand(info, DspParameter::Byte, (uint8_t)instrBits);
				DspAddress addr = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
				AddBytes(instrPtr, sizeof(uint16_t), info);
				AddImmOperand(info, DspParameter::Address2, addr);
				break;
			}
			case 2:		// clr
			{
				int b = instrBits & 7;
				if (b != 7)
				{
					info.instr = DspRegularInstruction::clr;
					AddParam(info, (DspParameter)((int)DspParameter::psr_tb + b));
				}
				break;
			}
			case 3:		// set
			{
				int b = instrBits & 7;
				if (b != 7)
				{
					info.instr = DspRegularInstruction::set;
					AddParam(info, (DspParameter)((int)DspParameter::psr_tb + b));
				}
				break;
			}
			case 4:		// lsfi, asfi
			case 5:
			{
				int d = (instrBits & 0x100) ? 1 : 0;

				int8_t si = instrBits & 0x7f;
				if (si & 0x40)
				{
					si |= 0x80;
				}

				info.instr = (instrBits & 0x80) == 0 ? DspRegularInstruction::lsfi : DspRegularInstruction::asfi;
				AddParam(info, d == 0 ? DspParameter::a : DspParameter::b);
				AddImmOperand(info, DspParameter::SignedByte, si);
				break;
			}
			case 6:		// stli
			{
				info.instr = DspRegularInstruction::stli;
				DspAddress addr = 0xff00 | (instrBits & 0xff);
				AddImmOperand(info, DspParameter::Address, addr);
				uint16_t imm = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);
				AddBytes(instrPtr, sizeof(uint16_t), info);
				AddImmOperand(info, DspParameter::UnsignedShort2, imm);
				break;
			}
			case 7:		// jmp, call
			{
				info.instr = (instrBits & 0x10) == 0 ? DspRegularInstruction::jmp : DspRegularInstruction::call;
				info.flowControl = true;
				info.cc = (ConditionCode)(instrBits & 0xf);
				int r = (instrBits >> 5) & 3;
				AddParam(info, addressreg[r]);
				break;
			}
			case 8:		// ld
			case 9:
			{
				info.instr = DspRegularInstruction::ld;
				int d = instrBits & 0x1f;
				AddParam(info, (DspParameter)((int)DspParameter::regs + d));
				int r = (instrBits >> 5) & 3;
				AddParam(info, addressreg[r]);
				int m = (instrBits >> 7) & 3;
				AddParam(info, modifier[m]);
				break;
			}
			case 0xa:	// st
			case 0xb:
			{
				info.instr = DspRegularInstruction::st;
				int r = (instrBits >> 5) & 3;
				AddParam(info, addressreg[r]);
				int m = (instrBits >> 7) & 3;
				AddParam(info, modifier[m]);
				int s = instrBits & 0x1f;
				AddParam(info, (DspParameter)((int)DspParameter::regs + s));
				break;
			}
			case 0xc:	// mv
			case 0xd:
			case 0xe:
			case 0xf:
			{
				info.instr = DspRegularInstruction::mv;
				int d = (instrBits >> 5) & 0x1f;
				AddParam(info, (DspParameter)((int)DspParameter::regs + d));
				int s = instrBits & 0x1f;
				AddParam(info, (DspParameter)((int)DspParameter::regs + s));
				break;
			}
		}
	}

	void Analyzer::Group2(AnalyzeInfo& info, uint16_t instrBits)
	{
		static DspParameter ldsa_reg[] = {
			DspParameter::x0,
			DspParameter::y0,
			DspParameter::x1,
			DspParameter::y1,
			DspParameter::a0,
			DspParameter::b0,
			DspParameter::a1,
			DspParameter::b1,
		};

		static DspParameter stsa_reg[] = {
			DspParameter::a2,
			DspParameter::b2,
			DspParameter::Unknown,
			DspParameter::Unknown,
			DspParameter::a0,
			DspParameter::b0,
			DspParameter::a1,
			DspParameter::b1,
		};

		//|ldsa d,sa   |0010 0ddd aaaa aaaa|
		//|stsa sa,s   |0010 1sss aaaa aaaa|

		if ((instrBits & 0x800) == 0)
		{
			// ldsa
			info.instr = DspRegularInstruction::ldsa;
			int d = (instrBits >> 8) & 7;
			AddParam(info, ldsa_reg[d]);
			AddImmOperand(info, DspParameter::Address, (DspAddress)(uint8_t)instrBits);
		}
		else
		{
			// stsa
			info.instr = DspRegularInstruction::ldsa;
			AddImmOperand(info, DspParameter::Address, (DspAddress)(uint8_t)instrBits);
			int s = (instrBits >> 8) & 7;
			AddParam(info, stsa_reg[s]);
		}
	}

	void Analyzer::Group3(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|xor d,s      |0011 00sd 0xxx xxxx|
		//|xor d,s      |0011 000d 1xxx xxxx|
		//|not d        |0011 001d 1xxx xxxx|
		//|and d,s      |0011 01sd 0xxx xxxx|
		//|lsf d,s      |0011 01sd 1xxx xxxx|
		//|or d,s       |0011 10sd 0xxx xxxx|
		//|asf d,s      |0011 10sd 1xxx xxxx|
		//|and d,s      |0011 110d 0xxx xxxx|
		//|lsf d,s      |0011 110d 1xxx xxxx|
		//|or d,s       |0011 111d 0xxx xxxx|
		//|asf d,s      |0011 111d 1xxx xxxx|
	}

	void Analyzer::Group4(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|add d,s      |0100 sssd xxxx xxxx|
	}

	void Analyzer::Group5(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|sub d,s      |0101 sssd xxxx xxxx|
	}

	void Analyzer::Group6(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|amv d,s      |0110 sssd xxxx xxxx|
	}

	void Analyzer::Group7(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|addl d,s     |0111 00sd xxxx xxxx|
		//|inc d        |0111 01dd xxxx xxxx|
		//|dec d        |0111 10dd xxxx xxxx|
		//|neg d        |0111 110d xxxx xxxx|
		//|neg d,p      |0111 111d xxxx xxxx|
	}

	void Analyzer::Group8(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|nop          |1000 0000 xxxx xxxx|
		//|clr d        |1000 d001 xxxx xxxx|
		//|cmp a,b      |1000 0010 xxxx xxxx|
		//|mpy x1,x1    |1000 0011 xxxx xxxx|
		//|clr p        |1000 0100 xxxx xxxx|
		//|tst p        |1000 0101 xxxx xxxx|
		//|tst s        |1000 011s xxxx xxxx|
		//|clr im       |1000 1010 xxxx xxxx|
		//|set im       |1000 1011 xxxx xxxx|
		//|clr dp       |1000 1100 xxxx xxxx|
		//|set dp       |1000 1101 xxxx xxxx|
		//|clr xl       |1000 1110 xxxx xxxx|
		//|set xl       |1000 1111 xxxx xxxx|
	}

	void Analyzer::Group9(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|asr16 d      |1001 d001 xxxx xxxx|
	}

	void Analyzer::GroupA(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|abs d        |1010 d001 xxxx xxxx|
	}

	void Analyzer::GroupB(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|tst s        |1011 s001 xxxx xxxx|
	}

	void Analyzer::GroupCD(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|cmp d,s      |110s d001 xxxx xxxx|
	}

	void Analyzer::GroupE(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|mac s1,s2    |1110 00ss xxxx xxxx|
		//|mac s1,s2    |1110 10ss xxxx xxxx|
		//|macn s1,s2   |1110 01ss xxxx xxxx|
		//|macn s1,s2   |1110 11ss xxxx xxxx|
	}

	void Analyzer::GroupF(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|lsl16 d      |1111 000d xxxx xxxx|
		//|mac s1,s2    |1111 001s xxxx xxxx|
		//|lsr16 d      |1111 010d xxxx xxxx|
		//|macn s1,s2   |1111 011s xxxx xxxx|
		//|addp d,s     |1111 10sd xxxx xxxx|
		//|rnd d        |1111 110d xxxx xxxx|
		//|rndp d       |1111 111d xxxx xxxx|
	}

	void Analyzer::GroupMpy(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|mpy s1,s2    |1sss s000 xxxx xxxx|
		//|rnmpy d,s1,s2|1sss s01d xxxx xxxx|
		//|admpy d,s1,s2|1sss s10d xxxx xxxx|
		//|mvmpy d,s1,s2|1sss s11d xxxx xxxx|
	}

	void Analyzer::GroupMemOps7(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|mr rn,mn               |0011 xxxx x000 mmrr|
		//|mv d,s                 |0011 xxxx x001 ddss|
		//|st rn,mn,s             |0011 xxxx x01s smrr|
		//|ld d,rn,mn             |0011 xxxx x1dd dmrr|
	}

	void Analyzer::GroupMemOps8(AnalyzeInfo& info, uint16_t instrBits)
	{
		//|mr rn,mn               |01xx xxxx 0000 mmrr|
		//|mr rn,mn               |1xxx xxxx 0000 mmrr|
		//|mv d,s                 |01xx xxxx 0001 ddss|
		//|mv d,s                 |1xxx xxxx 0001 ddss|
		//|st rn,mn,s             |01xx xxxx 001s smrr|
		//|st rn,mn,s             |1xxx xxxx 001s smrr|
		//|ld d,rn,mn             |01xx xxxx 01dd dmrr|
		//|ld d,rn,mn             |1xxx xxxx 01dd dmrr|
		//|ls d,r,m r,m,s         |01xx xxxx 10dd mn0s|
		//|ls2 d,r,m r,m,s        |01xx xxxx 10dd mn1s|
		//|ls d,r,m r,m,s         |1xxx xxxx 10dd mn0s|
		//|ls2 d,r,m r,m,s        |1xxx xxxx 10dd mn1s|
		//|ldd d1,rn,mn d2,r3,m3  |01xx xxxx 11dd mnrr|
		//|ldd d1,rn,mn d2,r3,m3  |1xxx xxxx 11dd mnrr|
		//|ldd2 d1,rn,mn d2,r3,m3 |1xxx xxxx 11rd mn11|
	}

	void Analyzer::Analyze(uint8_t* instrPtr, size_t instrMaxSize, AnalyzeInfo& info)
	{
		// Reset info

		ResetInfo(info);

		// Get opcode and determine its group

		uint16_t instrBits = _BYTESWAP_UINT16(*(uint16_t*)instrPtr);

		AddBytes(instrPtr, sizeof(uint16_t), info);

		instrPtr += sizeof(instrBits);
		instrMaxSize -= sizeof(instrBits);

		int group = (instrBits >> 12);

		// Select by group. Groups 3-F are parallel instructions.

		info.parallel = group >= 3;

		// Group mixed multiply (8-F)?

		if ((instrBits & 0x8000) != 0)
		{
			switch ((instrBits >> 8) & 7)
			{
				case 0:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
					GroupMpy(info, instrBits);
					return;
			}
		}

		// Other

		switch (group)
		{
			case 0:
				Group0(instrPtr, instrMaxSize, info, instrBits);
				break;
			case 1:
				Group1(instrPtr, instrMaxSize, info, instrBits);
				break;
			case 2:
				Group2(info, instrBits);
				break;
			case 3:
				Group3(info, instrBits);
				break;
			case 4:
				Group4(info, instrBits);
				break;
			case 5:
				Group5(info, instrBits);
				break;
			case 6:
				Group6(info, instrBits);
				break;
			case 7:
				Group7(info, instrBits);
				break;
			case 8:
				Group8(info, instrBits);
				break;
			case 9:
				Group9(info, instrBits);
				break;
			case 0xa:
				GroupA(info, instrBits);
				break;
			case 0xb:
				GroupB(info, instrBits);
				break;
			case 0xc:
			case 0xd:
				GroupCD(info, instrBits);
				break;
			case 0xe:
				GroupE(info, instrBits);
				break;
			case 0xf:
				GroupF(info, instrBits);
				break;
		}
	}

}
