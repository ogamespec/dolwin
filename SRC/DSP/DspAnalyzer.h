// DSP analyzer.
// Can be used by disassembler as well as by interpreter/jitc.

#pragma once

namespace DSP
{
	// DSP instructions are in a hybrid format: some instructions occupy a full 16-bit word, and some can be packed as two parallel instructions per word.

	// Regular instructions (single-word)

	enum class DspRegularInstruction
	{
		Unknown = -1,

		jmp,		// Jump conditionally
		call,		// Call conditionally
		rets,		// Return conditionally
		reti,		// Return interrupt conditionally
		trap,		// Trap
		wait,		// Wait any interrupt
		exec,		// Execute next instruction conditionally
		loop,		// Loop until end address
		rep,		// Repeat next instruction
		pld,		// Load from IMEM
		nop,		// No operation
		mr,			// Modify address register (non-parallel)
		adsi,		// Add short immediate
		adli,		// Add long immediate
		cmpsi,		// Compare short immediate
		cmpli,		// Compare long immediate
		lsfi,		// Logic shift immediate (directed by sign)
		asfi,		// Arithmetic shift immediate (directed by sign)
		xorli,		// Xor long immediate
		anli,		// And long immediate
		orli,		// Or long immediate
		norm,		// Normalize step
		div,		// Division step
		addc,		// Add with carry
		subc,		// Sub with carry
		negc,		// Negate with carry
		max,		// Max
		lsf,		// Logic shift directed by sign
		asf,		// Arithmetic shift directed by sign
		ld,			// Load from DMEM
		st,			// Store to DMEM
		ldsa,		// Load from DMEM by short address
		stsa,		// Store to DMEM by short address
		ldla,		// Load from DMEM by long address
		stla,		// Store to DMEM by long address
		mv,			// Move register (non-parallel)
		mvsi,		// Move short immediate
		mvli,		// Move long immediate
		stli,		// Store long immedate to DMEM by short address
		clr,		// Clear PSR bit
		set,		// Set PSR bit
		btstl,		// Test bit clear
		btsth,		// Test bit set
	};

	// Parallel instructions that occupy the upper part (in the lower part there is a parallel Load / Store / Move instruction)

	enum class DspParallelInstruction
	{
		Unknown = -1,

		add,		// Add
		addl,		// Add to accumulator low word
		sub,		// Sub
		amv,		// Arithmetic move
		cmp,		// Compare
		inc,		// Increment
		dec,		// Decrement
		abs,		// Absolute value
		neg,		// Negate
		clr,		// Clear accumulator/product/psr_bit
		rnd,		// Round accumulator/product
		rndp,		// Round product
		tst,		// Test 
		lsl16,		// Logical shift left 16
		lsr16,		// Logical shift right 16
		asr16,		// Arithmetic shift right 16
		addp,		// Add x/y with product
		nop,		// Parallel nop
		set,		// Set psr_bit
		mpy,		// Mixed multiply
		mac,		// Multiply and accumulate
		macn,		// Multiply and accumulate with negation
		mvmpy,		// Move product and mixed multiply
		rnmpy,		// Round product and mixed multiply
		admpy,		// Add product with destination and mixed multiply
		_not,		// Logical not
		_xor,		// Logical xor
		_and,		// Logical and
		_or,		// Logical or
		lsf,		// Logical shift directed by sign
		asf,		// Arithmetic shift directed by sign
	};

	// Parallel mem opcodes (low part)

	enum class DspParallelMemInstruction
	{
		Unknown = -1,

		ldd,
		ls,
		ld,
		st,
		mv,
		mr
	};

	enum class DspParameter
	{
		Unknown = -1,

		// Registers

		regs,
		r0 = regs,	// Address register 0 (circular addressing)
		r1,		// Address register 1 (circular addressing)
		r2,		// Address register 2 (circular addressing)
		r3,		// Address register 3 (circular addressing)
		m0,		// Modifier value 0 (circular addressing)
		m1,		// Modifier value 1 (circular addressing)
		m2,		// Modifier value 2 (circular addressing)
		m3,		// Modifier value 3 (circular addressing)
		l0,		// Buffer length 0 (circular addressing)
		l1,		// Buffer length 1 (circular addressing)
		l2,		// Buffer length 2 (circular addressing)
		l3,		// Buffer length 3 (circular addressing)
		pcs,	// Program counter stack
		pss,	// Program status stack
		eas,	// End address stack
		lcs,	// Loop count stack
		a2,		// 40-bit accumulator a high 8 bits
		b2,		// 40-bit accumulator b high 8 bits
		dpp,	// Used as high 8-bits of address for some load/store instructions
		psr,	// Program status register
		ps0,	// Product partial sum low part
		ps1,	// Product partial sum middle part
		ps2,	// Product partial sum high part (8 bits)
		pc1,	// Product partial carry 1 middle part
		x0,		// ALU/Multiplier input operand x low part
		y0,		// ALU/Multiplier input operand y low part
		x1,		// ALU/Multiplier input operand x high part
		y1,		// ALU/Multiplier input operand y high part
		a0,		// 40-bit accumulator a low 16 bits
		b0,		// 40-bit accumulator b low 16 bits
		a1,		// 40-bit accumulator a middle 16 bits
		b1,		// 40-bit accumulator b middle 16 bits

		// Accumulator (40-bit)

		a,		// Whole a accumulator
		b,		// Whole b accumulator

		// Input operands (32-bit)

		x,		// Whole x operand
		y,		// Whole y operand

		// Folded multiply product

		prod,

		// Indexed by register

		Indexed_regs,
		Indexed_r0 = Indexed_regs,	// @ Addressing register 0 
		Indexed_r1,			// @ Addressing register 1 
		Indexed_r2,			// @ Addressing register 2 
		Indexed_r3,			// @ Addressing register 3 

		// PSR bits

		psr_c,		// Carry
		psr_v,		// Overflow
		psr_z,		// Zero
		psr_n,		// Negative
		psr_e,		// Extension
		psr_u,		// Unnormalization
		psr_tb,		// Test bit (btstl/btsth instructions)
		psr_sv,		// Sticky overflow
		psr_te0,	// Interrupt enable 0
		psr_te1,	// Interrupt enable 1
		psr_te2,	// Interrupt enable 2
		psr_te3,	// Interrupt enable 3
		psr_et,		// Global interrupt enable
		psr_im,		// Integer/fraction mode
		psr_xl,		// Extension limit mode
		psr_dp,		// Double precision mode

		// Modifier

		mod_base,
		mod_none = mod_base,	// 0
		mod_dec,	// -1
		mod_inc,	// +1
		mod_minus_m,		// -m
		mod_plus_m0,	// +m0
		mod_plus_m1,	// +m1
		mod_plus_m2,	// +m2
		mod_plus_m3,	// +m3
		mod_plus_m,		// +m

		// Immediates

		Byte,
		SignedByte,
		UnsignedShort,
		SignedShort,
		Address,

		Byte2,
		SignedByte2,
		UnsignedShort2,
		SignedShort2,
		Address2,

		Max,
	};

	enum ConditionCode
	{
		ge = 0b0000,		// Greater than or equal 
		lt = 0b0001,		// Less than 
		gt = 0b0010,		// Greater than 
		le = 0b0011,		// Less than or equal 
		nz = 0b0100,		// Not equal 
		z = 0b0101,			// Equal 
		nc = 0b0110,		// Not carry 
		c = 0b0111,			// Carry 
		ne = 0b1000,		// Below s32 
		e = 0b1001,			// Above s32 
		nm = 0b1010,		// Normalized
		m = 0b1011,			// Unnormalized
		nt = 0b1100,		// Bit Test Not OK
		t = 0b1101,			// Bit Test OK
		v = 0b1110,			// Overflow
		always = 0b1111,	// Always
	};

	#define DspAnalyzeNumParam 6

	struct AnalyzeInfo
	{
		uint32_t clearingPaddy;		// To use {0} on structure

		bool parallel;			// To select the format of the next union, either one regular instruction or a pair of parallel instructions.

		// Processed instruction (ready to output)

		union
		{
			DspRegularInstruction instr;

			struct
			{
				DspParallelInstruction parallelInstr;
				DspParallelMemInstruction parallelMemInstr;
			};
		};

		uint8_t bytes[0x10];	// Saved instruction bytes, including immediate operands
		size_t sizeInBytes;		// Total size of instruction, including immediate/address operands (in bytes)

		size_t numParameters;		// Number of instruction parameters
		size_t numParametersEx;		// Number of parallel mem instruction parameters

		DspParameter params[DspAnalyzeNumParam];		// Processed parameters (ready to output)
		DspParameter paramsEx[DspAnalyzeNumParam];		// Processed parallel mem opcode parameters (ready to output)

		bool flowControl;		// Call, jump or another flow control instruction

		// Immediate/address operand, followed by instruction Word (or contained inside instruction)

		union
		{
			uint8_t		Byte;
			int8_t		SignedByte;
			uint16_t	UnsignedShort;
			int16_t		SignedShort;
			DspAddress	Address;		// For loop, call etc.
		} ImmOperand;

		// Second immediate/address operand (required by small amount of instructions)

		union
		{
			uint8_t		Byte;
			int8_t		SignedByte;
			uint16_t	UnsignedShort;
			int16_t		SignedShort;
			DspAddress	Address;		// For loop
		} ImmOperand2;

		ConditionCode cc;		// Some instructions has condition code

	};

	class Analyzer
	{
		// Internal helpers

		static void ResetInfo(AnalyzeInfo& info);

		static void Group0(uint8_t* instrPtr, size_t instrMaxSize, AnalyzeInfo& info, uint16_t instrBits);
		static void Group1(uint8_t* instrPtr, size_t instrMaxSize, AnalyzeInfo& info, uint16_t instrBits);
		static void Group2(AnalyzeInfo& info, uint16_t instrBits);
		static void Group3(AnalyzeInfo& info, uint16_t instrBits);
		static void Group4(AnalyzeInfo& info, uint16_t instrBits);
		static void Group5(AnalyzeInfo& info, uint16_t instrBits);
		static void Group6(AnalyzeInfo& info, uint16_t instrBits);
		static void Group7(AnalyzeInfo& info, uint16_t instrBits);
		static void Group8(AnalyzeInfo& info, uint16_t instrBits);
		static void Group9(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupA(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupB(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupCD(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupE(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupF(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupMpy(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupMemOps7(AnalyzeInfo& info, uint16_t instrBits);
		static void GroupMemOps8(AnalyzeInfo& info, uint16_t instrBits);

		static void AddParam(AnalyzeInfo& info, DspParameter param);
		static void AddParamEx(AnalyzeInfo& info, DspParameter param);

		static void AddImmOperand(AnalyzeInfo& info, DspParameter param, uint8_t imm);
		static void AddImmOperand(AnalyzeInfo& info, DspParameter param, int8_t imm);
		static void AddImmOperand(AnalyzeInfo& info, DspParameter param, uint16_t imm);
		static void AddImmOperand(AnalyzeInfo& info, DspParameter param, int16_t imm);
		static void AddImmOperand(AnalyzeInfo& info, DspParameter param, DspAddress imm);

		static void AddBytes(uint8_t* instrPtr, size_t bytes, AnalyzeInfo& info);

	public:

		static void Analyze(uint8_t* instrPtr, size_t instrMaxSize, AnalyzeInfo& info);
	};
}
