﻿// AnalyzeInfo structure definitions for X86-16, X86-32, and X64 architectures.
// There is no instruction analyzer (decoder) here yet.

// Everything related to Intel VT, SGX and other similar things is not supported.

#pragma once

namespace IntelCore
{

	/// <summary>
	/// List of Intel instructions for all architectures. 
	/// </summary>
	enum class Instruction : int
	{
		Unknown = -1,

		// General-Purpose Instructions

		mov,
		mov_sr,				// Move to/from Segment Registers
		cmove,
		cmovz = cmove,
		cmovne,
		cmovnz = cmovne,
		cmova,
		cmovnbe = cmova,
		cmovae,
		cmovnb = cmovae,
		cmovb,
		cmovnae = cmovb,
		cmovbe,
		cmovna = cmovbe,
		cmovg,
		cmovnle = cmovg,
		cmovge,
		cmovnl = cmovge,
		cmovl,
		cmovnge = cmovl,
		cmovle,
		cmovng = cmovle,
		cmovc,
		cmovnc,
		cmovo,
		cmovno,
		cmovs,
		cmovns,
		cmovp,
		cmovpe = cmovp,
		cmovnp,
		cmovpo = cmovnp,
		xchg,
		bswap,
		xadd,
		cmpxchg,
		cmpxchg8b,
		push,
		push_sr,			// Push Segment Register onto the Stack
		pop,
		pop_sr,				// Pop a Segment Register from the Stack
		pusha,
		pushad,
		popa,
		popad,
		cwd,
		cdq,
		cbw,
		cwde,
		movsx,
		movsxd,
		movzx,
		adcx,
		adox,
		add,
		adc,
		sub,
		sbb,
		imul,
		mul,
		idiv,
		div,
		inc,
		dec,
		neg,
		cmp,
		daa,
		das,
		aaa,
		aas,
		aam,
		aad,
		_and,
		_or,
		_xor,
		_not,
		sar,
		shr,
		sal,
		shl,
		shrd,
		shld,
		ror,
		rol,
		rcr,
		rcl,
		bt,
		bts,
		btr,
		btc,
		bsf,
		bsr,
		sete,
		setz = sete,
		setne,
		setnz = setne,
		seta,
		setnbe = seta,
		setae,
		setnb = setae,
		setnc = setae,
		setb,
		setnae = setb,
		setc = setb,
		setbe,
		setna = setbe,
		setg,
		setnle = setg,
		setge,
		setnl = setge,
		setl,
		setnge = setl,
		setle,
		setng = setle,
		sets,
		setns,
		seto,
		setno,
		setpe,
		setp = setpe,
		setpo,
		setnp = setpo,
		test,
		crc32,
		popcnt,
		jmp,				// in same segment
		jmpfar,				// in other segment
		je,
		jz = je,
		jne,
		jnz = jne,
		ja ,
		jnbe = ja,
		jae,
		jnb = jae,
		jb,
		jnae = jb,
		jbe,
		jna = jbe,
		jg, 
		jnle = jg,
		jge, 
		jnl = jge,
		jl, 
		jnge = jl,
		jle, 
		jng = jle,
		jc,
		jnc,
		jo,
		jno,
		js,
		jns,
		jpo,
		jnp = jpo,
		jpe, 
		jp = jpe,
		jcxz, 
		jecxz = jcxz,
		loop,
		loopz, 
		loope = loopz,
		loopnz, 
		loopne = loopnz,
		call,				// in same segment
		callfar,			// in other segment
		ret,				// in same segment
		retfar,				// in other segment
		iret,
		_int,
		int3,
		into,
		bound,
		enter,
		leave,
		movsb,
		movsw,
		cmpsb,
		cmpsw,
		scasb,
		scasw,
		scasd,
		lodsb,
		lodsw,
		lodsd,
		stosb,
		stosw,
		stosd,
		//rep,					// Treated as a prefix 
		//repe,					// Treated as a prefix 
		//repz = repe,			// Treated as a prefix 
		//repne,				// Treated as a prefix 
		//repnz = repne,		// Treated as a prefix 
		in,
		out,
		insb,
		insw,
		insd,
		outsb,
		outsw,
		outsd,
		stc,
		clc,
		cmc,
		cld,
		std,
		lahf,
		sahf,
		pushf,
		pushfd,
		popf,
		popfd,
		sti,
		cli,
		lds,
		les,
		lfs,
		lgs,
		lss,
		lea,
		nop,
		ud,
		xlat,
		xlatb = xlat,
		cpuid,
		movbe,
		prefetchw,
		prefetchwt1,
		clflush,
		clflushopt,
		rdrand,
		rdseed,

		// System Instructions

		clac,
		stac,
		lgdt,
		sgdt,
		lldt,
		sldt,
		ltr,
		str,
		lidt,
		sidt,
		mov_cr,				// Move to/from Control Registers
		lmsw,
		smsw,
		clts,
		arpl,
		lar,
		lsl,
		verr,
		verw,
		mov_dr,				// MOV – Move to/from Debug Registers
		invd,
		wbinvd,
		invlpg,
		invpcid,
		//lock,				// Treated as a prefix 
		hlt,
		rsm,
		rdmsr,
		wrmsr,
		rdpmc,
		rdtsc,
		rdtscp,
		sysenter,
		sysexit,
		xsave,
		xsavec,
		xsaveopt,
		xsaves,
		xrstor,
		xrstors,
		xgetbv,
		xsetbv,
		rdfsbase,
		rdgsbase,
		wrfsbase,
		wrgsbase,

		// 64-Bit Mode Instructions

		cdqe,
		cmpsq,
		cmpxchg16b,
		lodsq,
		movsq,
		movzx_64,
		stosq,
		swapgs,
		syscall,
		sysret,

		// BMI1, BMI2

		andn,
		bextr,
		blsi,
		blsmsk,
		blsr,
		bzhi,
		lzcnt,
		mulx,
		pdep,
		pext,
		rorx,
		sarx,
		shlx,
		shrx,
		tzcnt,

		// x87 FPU Instructions

		fld,
		fst,
		fstp,
		fild,
		fist,
		fistp,
		fbld,
		fbstp,
		fxch,
		fcmove,
		fcmovne,
		fcmovb,
		fcmovbe,
		fcmovnb,
		fcmovnbe,
		fcmovu,
		fcmovnu,
		fadd,
		faddp,
		fiadd,
		fsub,
		fsubp,
		fisub,
		fsubr,
		fsubrp,
		fisubr,
		fmul,
		fmulp,
		fimul,
		fdiv,
		fdivp,
		fidiv,
		fdivr,
		fdivrp,
		fidivr,
		fprem,
		fprem1,
		fabs,
		fchs,
		frndint,
		fscale,
		fsqrt,
		fxtract,
		fcom,
		fcomp,
		fcompp,
		fucom,
		fucomp,
		fucompp,
		ficom,
		ficomp,
		fcomi,
		fucomi,
		fcomip,
		fucomip,
		ftst,
		fxam,
		fsin,
		fcos,
		fsincos,
		fptan,
		fpatan,
		f2xm1,
		fyl2x,
		fyl2xp1,
		fld1,
		fldz,
		fldpi,
		fldl2e,
		fldln2,
		fldl2t,
		fldlg2,
		fincstp,
		fdecstp,
		ffree,
		finit,
		fninit,
		fclex,
		fnclex,
		fstcw,
		fnstcw,
		fldcw,
		fstenv,
		fnstenv,
		fldenv,
		fsave,
		fnsave,
		frstor,
		fstsw,
		fnstsw,
		wait,
		fwait = wait,
		fnop,
		fxsave,
		fxrstor,

		// MMX™ Instructions

		movd,
		movq,
		packsswb,
		packssdw,
		packuswb,
		punpckhbw,
		punpckhwd,
		punpckhdq,
		punpcklbw,
		punpcklwd,
		punpckldq,
		paddb,
		paddw,
		paddd,
		paddsb,
		paddsw,
		paddusb,
		paddusw,
		psubb,
		psubw,
		psubd,
		psubsb,
		psubsw,
		psubusb,
		psubusw,
		pmulhw,
		pmullw,
		pmaddwd,
		pcmpeqb,
		pcmpeqw,
		pcmpeqd,
		pcmpgtb,
		pcmpgtw,
		pcmpgtd,
		pand,
		pandn,
		por,
		pxor,
		psllw,
		pslld,
		psllq,
		psrlw,
		psrld,
		psrlq,
		psraw,
		psrad,
		emms,

		// TODO: The definitions of SSE/AVX instructions now look a little chaotic, when it comes to them they will be put in order.

		// SSE (™?) Instructions

		movaps,
		movups,
		movhps,
		movhlps,
		movlps,
		movlhps,
		movmskps,
		movss,
		addps,
		addss,
		subps,
		subss,
		mulps,
		mulss,
		divps,
		divss,
		rcpps,
		rcpss,
		sqrtps,
		sqrtss,
		rsqrtps,
		rsqrtss,
		maxps,
		maxss,
		minps,
		minss,
		cmpps,
		cmpss,
		comiss,
		ucomiss,
		andps,
		andnps,
		orps,
		xorps,
		shufps,
		unpckhps,
		unpcklps,
		cvtpi2ps,
		cvtsi2ss,
		cvtps2pi,
		cvttps2pi,
		cvtss2si,
		cvttss2si,
		ldmxcsr,
		stmxcsr,
		pavgb,
		pavgw,
		pextrw,
		pinsrw,
		pmaxub,
		pmaxsw,
		pminub,
		pminsw,
		pmovmskb,
		pmulhuw,
		psadbw,
		pshufw,
		maskmovq,
		movntq,
		movntps,
		prefetchh,
		sfence,

		// SSE2 Instructions

		movapd,
		movupd,
		movhpd,
		movlpd,
		movmskpd,
		movsd,
		addpd,
		addsd,
		subpd,
		subsd,
		mulpd,
		mulsd,
		divpd,
		divsd,
		sqrtpd,
		sqrtsd,
		maxpd,
		maxsd,
		minpd,
		minsd,
		andpd,
		andnpd,
		orpd,
		xorpd,
		cmppd,
		cmpsd,
		comisd,
		ucomisd,
		shufpd,
		unpckhpd,
		unpcklpd,
		cvtpd2pi,
		cvttpd2pi,
		cvtpi2pd,
		cvtpd2dq,
		cvttpd2dq,
		cvtdq2pd,
		cvtps2pd,
		cvtpd2ps,
		cvtss2sd,
		cvtsd2ss,
		cvtsd2si,
		cvttsd2si,
		cvtsi2sd,
		cvtdq2ps,
		cvtps2dq,
		cvttps2dq,
		movdqa,
		movdqu,
		movq2dq,
		movdq2q,
		pmuludq,
		paddq,
		psubq,
		pshuflw,
		pshufhw,
		pshufd,
		pslldq,
		psrldq,
		punpckhqdq,
		punpcklqdq,
		lfence,
		mfence,
		pause,
		maskmovdqu,
		movntpd,
		movntdq,
		movnti,

		// SSE3 Instructions

		fisttp,
		lddqu,
		addsubps,
		addsubpd,
		haddps,
		hsubps,
		haddpd,
		hsubpd,
		movshdup,
		movsldup,
		movddup,
		monitor,
		mwait,

		// Supplemental Streaming SIMD Extensions 3 (SSSE3) Instructions

		phaddw,
		phaddsw,
		phaddd,
		phsubw,
		phsubsw,
		phsubd,
		pabsb,
		pabsw,
		pabsd,
		pmaddubsw,
		pmulhrsw,
		pshufb,
		psignb,
		psignw,
		psignd,
		palignr,

		// SSE4.1 Instructions

		pmulld,
		pmuldq,
		dppd,
		dpps,
		movntdqa,
		blendpd,
		blendps,
		blendvpd,
		blendvps,
		pblendvb,
		pblendw,
		pminuw,
		pminud,
		pminsb,
		pminsd,
		pmaxuw,
		pmaxud,
		pmaxsb,
		pmaxsd,
		roundps,
		roundpd,
		roundss,
		roundsd,
		extractps,
		insertps,
		pinsrb,
		pinsrd,
		pinsrq,
		pextrb,
		pextrd,
		pextrq,
		pmovsxbw,
		pmovzxbw,
		pmovsxbd,
		pmovzxbd,
		pmovsxwd,
		pmovzxwd,
		pmovsxbq,
		pmovzxbq,
		pmovsxwq,
		pmovzxwq,
		pmovsxdq,
		pmovzxdq,
		mpsadbw,
		phminposuw,
		ptest,
		pcmpeqq,
		packusdw,

		// SSE4.2 Instruction Set

		pcmpestri,
		pcmpestrm,
		pcmpistri,
		pcmpistrm,
		pcmpgtq,

		// Intel® AES-NI and PCLMULQDQ

		aesdec,
		aesdeclast,
		aesenc,
		aesenclast,
		aesimc,
		aeskeygenassist,
		pclmulqdq,

		// Intel® Advanced Vector Extensions (Intel® AVX)

		// TBD

		// 16-bit Floating-Point Conversion

		vcvtph2ps,
		vcvtps2ph,

		// Fused-Multiply-ADD (FMA)

		vfmadd132pd,
		vfmadd213pd,
		vfmadd231pd,
		vfmadd132ps,
		vfmadd213ps,
		vfmadd231ps,
		vfmadd132sd,
		vfmadd213sd,
		vfmadd231sd,
		vfmadd132ss,
		vfmadd213ss,
		vfmadd231ss,
		vfmaddsub132pd,
		vfmaddsub213pd,
		vfmaddsub231pd,
		vfmaddsub132ps,
		vfmaddsub213ps,
		vfmaddsub231ps,
		vfmsubadd132pd,
		vfmsubadd213pd,
		vfmsubadd231pd,
		vfmsubadd132ps,
		vfmsubadd213ps,
		vfmsubadd231ps,
		vfmsub132pd,
		vfmsub213pd,
		vfmsub231pd,
		vfmsub132ps,
		vfmsub213ps,
		vfmsub231ps,
		vfmsub132sd,
		vfmsub213sd,
		vfmsub231sd,
		vfmsub132ss,
		vfmsub213ss,
		vfmsub231ss,
		vfnmadd132pd,
		vfnmadd213pd,
		vfnmadd231pd,
		vfnmadd132ps,
		vfnmadd213ps,
		vfnmadd231ps,
		vfnmadd132sd,
		vfnmadd213sd,
		vfnmadd231sd,
		vfnmadd132ss,
		vfnmadd213ss,
		vfnmadd231ss,
		vfnmsub132pd,
		vfnmsub213pd,
		vfnmsub231pd,
		vfnmsub132ps,
		vfnmsub213ps,
		vfnmsub231ps,
		vfnmsub132sd,
		vfnmsub213sd,
		vfnmsub231sd,
		vfnmsub132ss,
		vfnmsub213ss,
		vfnmsub231ss,

		// Intel® Advanced Vector Extensions 2 (Intel® AVX2)

		// TBD

		// Intel® Advanced Vector Extensions 512 (Intel® AVX-512)

		valignd,
		valignq,
		vblendmpd,
		vblendmps,
		vcompresspd,
		vcompressps,
		vcvtpd2udq,
		vcvttpd2udq,
		vcvtps2udq,
		vcvttps2udq,
		vcvtqq2pd,
		vcvtqq2ps,
		vcvtsd2usi,
		vcvttsd2usi,
		vcvtss2usi,
		vcvttss2usi,
		vcvtudq2pd,
		vcvtudq2ps,
		vcvtusi2usd,
		vcvtusi2uss,
		vexpandpd,
		vexpandps,
		vextractf32x4,
		vextractf64x4,
		vextracti32x4,
		vextracti64x4,
		vfixupimmpd, 
		vfixupimmps,
		vfixupimmsd,
		vfixupimmss,
		vgetexppd,
		vgetexpps,
		vgetexpsd,
		vgetexpss,
		vgetmantpd,
		vgetmantps,
		vgetmantsd,
		vgetmantss,
		vinsertf32x4,
		vinsertf64x4,
		vmovdqa32,
		vmovdqa64,
		vmovdqu32,
		vmovdqu64,
		vpblendmd,
		vpblendmq,
		vpcmpd,
		vpcmud,
		vpcmpq,
		vpcmuq,
		vpcompressq,
		vpcompressd,
		vpermi2d,
		vpermi2q,
		vpermi2pd, 
		vpermi2ps,
		vpermt2d,
		vpermt2q,
		vpermt2pd, 
		vpermt2ps,
		vpexpandd,
		vpexpandq,
		vpmaxsq,
		vpmaxud,
		vpmaxuq,
		vpminsq,
		vpminud,
		vpminuq,
		vpmovqb,
		vpmovsqb,
		vpmovusqb,
		vpmovqw,
		vpmovsqw,
		vpmovusqw,
		vpmovqd,
		vpmovsqd,
		vpmovusqd,
		vpmovdb,
		vpmovsdb,
		vpmovusdb,
		vpmovdw,
		vpscatterdd,
		vpscatterdq,
		vpscatterqd,
		vpscatterqq,
		vpsraq,
		vpsravq,
		vptestnmd,
		vptestnmq,
		vpterlogd,
		vpterlogq,
		vpbroadcastd,
		vpbroadcastq,
		vpmovsdw,
		vpmovusdw,
		vprold,
		vprolq,
		vprolvd,
		vprolvq,
		vprord,
		vprorq,
		vprorrd,
		vprorrq,
		vcvtpd2qq,
		vcvttpd2qq,
		vcvtpd2uqq,
		vcvttpd2uqq,
		vcvtps2qq,
		vcvttps2qq,
		vcvtps2uqq,
		vcvttps2uqq,
		vcvtuqq2pd,
		vcvtuqq2ps,
		vextractf64x2,
		vextracti64x2,
		vfpclasspd,
		vfpclassps,
		vfpclasssd,
		vfpclassss,
		vinsertf64x2,
		vinserti64x2,
		vpmovm2d,
		vpmovm2q,
		vpmovb2d,
		vpmovq2m,
		vpmullq,
		vrangepd,
		vrangeps,
		vrangesd,
		vrangess,
		vreducepd,
		vreduceps,
		vreducesd,
		vreducess,
		vdbpsadbw,
		vmovdqu8,
		vmovdqu16,
		vpblendmb,
		vpblendmw,
		vpbroadcastb,
		vpbroadcastw,
		vpcmpb,
		vpcmub,
		vpcmpw,
		vpcmuw,
		vpermw,
		vpermi2b,
		vpermi2w,
		vpmovm2b,
		vpmovm2w,
		vpmovb2m,
		vpmovw2m,
		vpmovwb,
		vpmovswb,
		vpmovuswb,
		vpsllvw,
		vpsravw,
		vpsrlvw,
		vptestnmb,
		vptestnmw,
		vptestmb,
		vptestmw,
		vpbroadcastm,
		vpconflictd,
		vpconflictq,
		vplzcntd,
		vplzcntq,
		kaddb,
		kaddw,
		kaddd,
		kaddq,
		kandb,
		kandw,
		kandd,
		kandq,
		kandnb,
		kandnw,
		kandnd,
		kandnq,
		kmovb,
		kmovw,
		kmovd,
		kmovq,
		knotb,
		knotw,
		knotd,
		knotq,
		korb,
		korw,
		kord,
		korq,
		kortestb,
		kortestw,
		kortestd,
		kortestq,
		kshiftlb,
		kshiftlw,
		kshiftld,
		kshiftlq,
		kshiftrb,
		kshiftrw,
		kshiftrd,
		kshiftrq,
		ktestb,
		ktestw,
		ktestd,
		ktestq,
		kunpckbw,
		kunpckbwd,
		kunpckbwq,
		kxnorb,
		kxnorw,
		kxnord,
		kxnorq,
		kxorb,
		kxorw,
		kxord,
		kxorq,
		vexp2pd,
		vexp2ps,
		vexp2sd,
		vexp2ss,
		vrcp28pd,
		vrcp28ps,
		vrcp28sd,
		vrcp28ss,
		vrsqrt28pd,
		vrsqrt28ps,
		vrsqrt28sd,
		vrsqrt28ss,
		vgatherpf0dpd,
		vgatherpf0dps,
		vgatherpf0qpd,
		vgatherpf0qps,
		vgatherpf1dpd,
		vgatherpf1dps,
		vgatherpf1qpd,
		vgatherpf1qps,
		vscatterpf0dpd,
		vscatterpf0dps,
		vscatterpf0qpd,
		vscatterpf0qps,
		vscatterpf1dpd,
		vscatterpf1dps,
		vscatterpf1qpd,
		vscatterpf1qps,

	};

	/// <summary>
	/// Used to set the instruction prefixes.
	/// </summary>
	enum class Prefix : int
	{
		NoPrefix = 0,
		AddressSize,
		Lock,
		OperandSize,
		SegCs,
		SegDs,
		SegEs,
		SegFs,
		SegGs,
		SegSs,
		Rep,
		Repe,
		Repz = Repe,
		Repne,
		Repnz = Repne,
	};

	/// <summary>
	/// Category of instructions for additional analysis. 
	/// Of greatest interest are the instructions in the FlowControl category, which affect the construction of a call graph (for example). 
	/// </summary>
	enum class Category : int
	{
		NothingSpecial = 0,		// Nothing special
		FlowControl,			// The instruction can change the flow of execution (jmp, call, ret, etc.) 
		Fpu,					// x87 FPU Instruction
		Mmx,					// MMX Instruction
		Sse,					// SSE (any) Instruction
		Avx,					// AVX (any) Instruction
	};

	/// <summary>
	/// One of the parameters 
	/// </summary>
	enum class Param : int
	{
		Unknown = -1,

		imm8,

	};

	/// <summary>
	/// The maximum number of parameters for the instruction. In the manual, there are 4 max parameters in the tables, but we will be reinsured. 
	/// </summary>
	constexpr auto ParamsMax = 8;

	/// <summary>
	/// The maximum size of all prefixes. (bytes)
	/// </summary>
	constexpr auto PrefixMaxSize = 16;

	/// <summary>
	/// Maximum instruction size excluding prefixes. (bytes)
	/// </summary>
	constexpr auto InstrMaxSize = 16;

	/// <summary>
	/// The structure contains all information about the instruction, including possible prefixes and a parameter list.
	/// This is a deliberate abstraction from the very alien definition of ModRM. All possible combinations of parameters are specified by the Param enumeration.
	/// </summary>
	struct AnalyzeInfo
	{
		Category category;		// It is set by the analyzer, for other cases it is not necessary to set it. 

		// When analyzing the flow of instructions, prefixes are separated from instruction,
		// so the total size of the code batch will be equal to the size of all prefixes + the size of the instruction itself. 

		Prefix prefixes[PrefixMaxSize];
		size_t numPrefixes;
		uint8_t prefixBytes[PrefixMaxSize];
		size_t prefixSize;

		Instruction instr;
		uint8_t instrBytes[InstrMaxSize];
		size_t instrSize;

		Param params[ParamsMax];
		size_t numParams;

		union
		{
			uint8_t disp8;
			uint16_t disp16;
			uint32_t disp32;
			uint64_t disp64;
		} Disp;

		union
		{
			uint8_t uimm8;
			uint16_t uimm16;
			uint32_t uimm32;
			uint64_t uimm64;

			int8_t simm8;
			int16_t simm16;
			int32_t simm32;
			int64_t simm64;
		} Imm;
	};

}
