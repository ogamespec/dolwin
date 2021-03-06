﻿// AnalyzeInfo structure definitions for X86-16, X86-32, and X64 architectures.
// There is no instruction analyzer (decoder) here yet.

// The AVX-512 is not supported because it is mainly used on server processors, while we are targeting the desktop market.

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
		cqo,
		cbw,
		cwde,
		cdqe,
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
		jnc = jae,
		jb,
		jnae = jb,
		jc = jb,
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
		jrcxz = jcxz,
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
		iretd,
		iretq,
		_int,
		int3,
		into,
		int1,
		bound,
		enter,
		leave,
		movsb,
		movsw,
		movsd,
		movsq,
		cmpsb,
		cmpsw,
		cmpsd,
		cmpsq,
		scasb,
		scasw,
		scasd,
		scasq,
		lodsb,
		lodsw,
		lodsd,
		lodsq,
		stosb,
		stosw,
		stosd,
		stosq,
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
		pushfq,
		popf,
		popfd,
		popfq,
		sti,
		cli,
		lds,
		les,
		lfs,
		lgs,
		lss,
		lea,
		nop,
		ud0,
		ud1,
		ud2,
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
		mov_tr,				// MOV – Move to/from Test Registers
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
		swapgs,
		syscall,
		sysret,
		sysretq,

		// 64-Bit Mode Instructions

		cmpxchg16b,
		movzx_64,

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

		FpuInstrStart,
		fld, fst, fstp, fild, fist, fistp, fbld, fbstp, fxch, fcmove, fcmovne, fcmovb, fcmovbe, fcmovnb, fcmovnbe, fcmovu, fcmovnu,
		fadd, faddp, fiadd, fsub, fsubp, fisub, fsubr, fsubrp, fisubr, fmul, fmulp, fimul, fdiv, fdivp, fidiv, fdivr, fdivrp, fidivr, fprem, fprem1, fabs, fchs, frndint, fscale, fsqrt, fxtract,
		fcom, fcomp, fcompp, fucom, fucomp, fucompp, ficom, ficomp, fcomi, fucomi, fcomip, fucomip, ftst, fxam,
		fsin, fcos, fsincos, fptan, fpatan, f2xm1, fyl2x, fyl2xp1,
		fld1, fldz, fldpi, fldl2e, fldln2, fldl2t, fldlg2,
		fincstp, fdecstp, ffree, finit, fninit, fclex, fnclex, fstcw, fnstcw, fldcw, fstenv, fnstenv, fldenv, fsave, fnsave, frstor, fstsw, fnstsw, wait, fwait = wait, fnop,
		fxsave, fxsave64, fxrstor, fxrstor64,
		FpuInstrEnd,

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

		// SSE Instructions

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
		movsd_sse,
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
		cmpsd_sse,
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

	};

	/// <summary>
	/// Used to set the instruction prefixes.
	/// </summary>
	enum class Prefix : int
	{
		NoPrefix = 0,
		AddressSize,	// 0x67
		Lock,
		OperandSize,    // 0x66
		SegCs,
		SegDs,
		SegEs,
		SegFs,
		SegGs,
		SegSs,
		Rep,
		Repe = Rep,
		Repz = Rep,
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

		// immediate

		ImmStart,			// Special constant to quickly define the category of a parameter. Do not use. 
		imm8,
		imm16,
		imm32,
		imm64,
		simm8_as16,			// Used for instructions where you want to sign extension of immediate 8 to 16 bits. 
		simm8_as32,			// Used for instructions where you want to sign extension of immediate 8 to 32 bits. 
		simm8_as64,			// Used for instructions where you want to sign extension of immediate 8 to 64 bits. 
		ImmEnd,				// Special constant to quickly define the category of a parameter. Do not use. 

		// relative (CALL)

		RelStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		rel8,
		rel16,
		rel32,
		RelEnd,			// Special constant to quickly define the category of a parameter. Do not use. 

		// far pointer (CALL far)

		FarPtrStart,	// Special constant to quickly define the category of a parameter. Do not use. 
		farptr16,			// eg. call far 0x1234:0x1234
		farptr32,			// eg. call far 0x1234:0x12345678
		FarPtrEnd,		// Special constant to quickly define the category of a parameter. Do not use. 

		// moffs (MOV)

		MoffsStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		moffs16,			// mov al, [0x1234]
		moffs32,			// mov al, [0x12345678]
		moffs64,			// mov al, [0x12345678aabbccdd]
		MoffsEnd,		// Special constant to quickly define the category of a parameter. Do not use. 

		// reg

		RegStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		al, cl, dl, bl, ah, ch, dh, bh,
		ax, cx, dx, bx, sp, bp, si, di,
		eax, ecx, edx, ebx, esp, ebp, esi, edi,
		// Long Mode regs
		spl, bpl, sil, dil,			// instead ah, ch, dh, bh
		r8b, r9b, r10b, r11b, r12b, r13b, r14b, r15b,
		r8w, r9w, r10w, r11w, r12w, r13w, r14w, r15w,
		r8d, r9d, r10d, r11d, r12d, r13d, r14d, r15d,
		rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14, r15,
		RegEnd,			// Special constant to quickly define the category of a parameter. Do not use. 

		// Sreg

		SregStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		es, cs, ss, ds, fs, gs,
		SregEnd,		// Special constant to quickly define the category of a parameter. Do not use. 

		// CR, DR, TR

		CRStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		cr0, cr1, cr2, cr3, cr4, cr5, cr6, cr7, cr8,
		CREnd,			// Special constant to quickly define the category of a parameter. Do not use. 

		DRStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		dr0, dr1, dr2, dr3, dr4, dr5, dr6, dr7,
		DREnd,			// Special constant to quickly define the category of a parameter. Do not use. 

		TRStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		tr0, tr1, tr2, tr3, tr4, tr5, tr6, tr7,
		TREnd,			// Special constant to quickly define the category of a parameter. Do not use. 

		// x87 registers

		X87Start,		// Special constant to quickly define the category of a parameter. Do not use. 
		st0, st = st0, st1, st2, st3, st4, st5, st6, st7,
		X87End,			// Special constant to quickly define the category of a parameter. Do not use. 

		// 16-bit mem
		// If you need memory addressing like [BP + DI] and so on. similar, look here.

		MemStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		Mem16Start,		// Special constant to quickly define the category of a parameter. Do not use. 
		m_bx_si, m_bx_di, m_bp_si, m_bp_di, m_si, m_di, m_disp16 /* disp16 instead bp */, m_bx,
		m_bx_si_disp8, m_bx_di_disp8, m_bp_si_disp8, m_bp_di_disp8, m_si_disp8, m_di_disp8, m_bp_disp8, m_bx_disp8,
		m_bx_si_disp16, m_bx_di_disp16, m_bp_si_disp16, m_bp_di_disp16, m_si_disp16, m_di_disp16, m_bp_disp16, m_bx_disp16,
		Mem16End,		// Special constant to quickly define the category of a parameter. Do not use. 

		// 32-bit mem
		// If you need simple 32-bit addressing like [ESI], see here. 

		Mem32Start,		// Special constant to quickly define the category of a parameter. Do not use. 
		m_eax, m_ecx, m_edx, m_ebx, /*see sib_, */ m_disp32 /* disp32 instead ebp */, m_esi, m_edi,
		m_eax_disp8, m_ecx_disp8, m_edx_disp8, m_ebx_disp8, /*see sib_x_disp8, */ m_ebp_disp8, m_esi_disp8, m_edi_disp8,
		m_eax_disp32, m_ecx_disp32, m_edx_disp32, m_ebx_disp32, /*see sib_x_disp32, */ m_ebp_disp32, m_esi_disp32, m_edi_disp32,
		Mem32End,		// Special constant to quickly define the category of a parameter. Do not use. 

		// 64-bit mem

		Mem64Start,		// Special constant to quickly define the category of a parameter. Do not use. 
		m_rax, m_rcx, m_rdx, m_rbx, /*see sib_, */ m_rip_disp32 /* RIP-relative addressing (Instead m_disp32. Use sib_none_disp32 if you need disp32 addressing) */, m_rsi, m_rdi,
		m_rax_disp8, m_rcx_disp8, m_rdx_disp8, m_rbx_disp8, /*see sib_x_disp8, */ m_rbp_disp8, m_rsi_disp8, m_rdi_disp8,
		m_rax_disp32, m_rcx_disp32, m_rdx_disp32, m_rbx_disp32, /*see sib_x_disp32, */ m_rbp_disp32, m_rsi_disp32, m_rdi_disp32,
		m_eip_disp32,
		Mem64End,		// Special constant to quickly define the category of a parameter. Do not use. 

		// If you need 32-bit addressing using the ScaleIndexBase mechanism like [EAX * 2 + ECX], see here. 

		SibStart,		// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib32Scale1Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_eax, sib_eax_ecx, sib_eax_edx, sib_eax_ebx, sib_eax_esp, sib_eax_disp32 /* disp32 instead ebp */, sib_eax_esi, sib_eax_edi, sib_eax_r8d, sib_eax_r9d, sib_eax_r10d, sib_eax_r11d, sib_eax_r12d, sib_eax_r13d, sib_eax_r14d, sib_eax_r15d,
		sib_ecx_eax, sib_ecx_ecx, sib_ecx_edx, sib_ecx_ebx, sib_ecx_esp, sib_ecx_disp32 /* disp32 instead ebp */, sib_ecx_esi, sib_ecx_edi, sib_ecx_r8d, sib_ecx_r9d, sib_ecx_r10d, sib_ecx_r11d, sib_ecx_r12d, sib_ecx_r13d, sib_ecx_r14d, sib_ecx_r15d,
		sib_edx_eax, sib_edx_ecx, sib_edx_edx, sib_edx_ebx, sib_edx_esp, sib_edx_disp32 /* disp32 instead ebp */, sib_edx_esi, sib_edx_edi, sib_edx_r8d, sib_edx_r9d, sib_edx_r10d, sib_edx_r11d, sib_edx_r12d, sib_edx_r13d, sib_edx_r14d, sib_edx_r15d,
		sib_ebx_eax, sib_ebx_ecx, sib_ebx_edx, sib_ebx_ebx, sib_ebx_esp, sib_ebx_disp32 /* disp32 instead ebp */, sib_ebx_esi, sib_ebx_edi, sib_ebx_r8d, sib_ebx_r9d, sib_ebx_r10d, sib_ebx_r11d, sib_ebx_r12d, sib_ebx_r13d, sib_ebx_r14d, sib_ebx_r15d,
		sib_none_eax, sib_none_ecx, sib_none_edx, sib_none_ebx, sib_none_esp, sib_none_disp32 /* disp32 instead ebp */, sib_none_esi, sib_none_edi, sib_none_r8d, sib_none_r9d, sib_none_r10d, sib_none_r11d, sib_none_r12d, sib_none_r13d, sib_none_r14d, sib_none_r15d,
		sib_ebp_eax, sib_ebp_ecx, sib_ebp_edx, sib_ebp_ebx, sib_ebp_esp, sib_ebp_disp32 /* disp32 instead ebp */, sib_ebp_esi, sib_ebp_edi, sib_ebp_r8d, sib_ebp_r9d, sib_ebp_r10d, sib_ebp_r11d, sib_ebp_r12d, sib_ebp_r13d, sib_ebp_r14d, sib_ebp_r15d,
		sib_esi_eax, sib_esi_ecx, sib_esi_edx, sib_esi_ebx, sib_esi_esp, sib_esi_disp32 /* disp32 instead ebp */, sib_esi_esi, sib_esi_edi, sib_esi_r8d, sib_esi_r9d, sib_esi_r10d, sib_esi_r11d, sib_esi_r12d, sib_esi_r13d, sib_esi_r14d, sib_esi_r15d,
		sib_edi_eax, sib_edi_ecx, sib_edi_edx, sib_edi_ebx, sib_edi_esp, sib_edi_disp32 /* disp32 instead ebp */, sib_edi_esi, sib_edi_edi, sib_edi_r8d, sib_edi_r9d, sib_edi_r10d, sib_edi_r11d, sib_edi_r12d, sib_edi_r13d, sib_edi_r14d, sib_edi_r15d,
		sib_r8d_eax, sib_r8d_ecx, sib_r8d_edx, sib_r8d_ebx, sib_r8d_esp, sib_r8d_disp32 /* disp32 instead ebp */, sib_r8d_esi, sib_r8d_edi, sib_r8d_r8d, sib_r8d_r9d, sib_r8d_r10d, sib_r8d_r11d, sib_r8d_r12d, sib_r8d_r13d, sib_r8d_r14d, sib_r8d_r15d,
		sib_r9d_eax, sib_r9d_ecx, sib_r9d_edx, sib_r9d_ebx, sib_r9d_esp, sib_r9d_disp32 /* disp32 instead ebp */, sib_r9d_esi, sib_r9d_edi, sib_r9d_r8d, sib_r9d_r9d, sib_r9d_r10d, sib_r9d_r11d, sib_r9d_r12d, sib_r9d_r13d, sib_r9d_r14d, sib_r9d_r15d,
		sib_r10d_eax, sib_r10d_ecx, sib_r10d_edx, sib_r10d_ebx, sib_r10d_esp, sib_r10d_disp32 /* disp32 instead ebp */, sib_r10d_esi, sib_r10d_edi, sib_r10d_r8d, sib_r10d_r9d, sib_r10d_r10d, sib_r10d_r11d, sib_r10d_r12d, sib_r10d_r13d, sib_r10d_r14d, sib_r10d_r15d,
		sib_r11d_eax, sib_r11d_ecx, sib_r11d_edx, sib_r11d_ebx, sib_r11d_esp, sib_r11d_disp32 /* disp32 instead ebp */, sib_r11d_esi, sib_r11d_edi, sib_r11d_r8d, sib_r11d_r9d, sib_r11d_r10d, sib_r11d_r11d, sib_r11d_r12d, sib_r11d_r13d, sib_r11d_r14d, sib_r11d_r15d,
		sib_r12d_eax, sib_r12d_ecx, sib_r12d_edx, sib_r12d_ebx, sib_r12d_esp, sib_r12d_disp32 /* disp32 instead ebp */, sib_r12d_esi, sib_r12d_edi, sib_r12d_r8d, sib_r12d_r9d, sib_r12d_r10d, sib_r12d_r11d, sib_r12d_r12d, sib_r12d_r13d, sib_r12d_r14d, sib_r12d_r15d,
		sib_r13d_eax, sib_r13d_ecx, sib_r13d_edx, sib_r13d_ebx, sib_r13d_esp, sib_r13d_disp32 /* disp32 instead ebp */, sib_r13d_esi, sib_r13d_edi, sib_r13d_r8d, sib_r13d_r9d, sib_r13d_r10d, sib_r13d_r11d, sib_r13d_r12d, sib_r13d_r13d, sib_r13d_r14d, sib_r13d_r15d,
		sib_r14d_eax, sib_r14d_ecx, sib_r14d_edx, sib_r14d_ebx, sib_r14d_esp, sib_r14d_disp32 /* disp32 instead ebp */, sib_r14d_esi, sib_r14d_edi, sib_r14d_r8d, sib_r14d_r9d, sib_r14d_r10d, sib_r14d_r11d, sib_r14d_r12d, sib_r14d_r13d, sib_r14d_r14d, sib_r14d_r15d,
		sib_r15d_eax, sib_r15d_ecx, sib_r15d_edx, sib_r15d_ebx, sib_r15d_esp, sib_r15d_disp32 /* disp32 instead ebp */, sib_r15d_esi, sib_r15d_edi, sib_r15d_r8d, sib_r15d_r9d, sib_r15d_r10d, sib_r15d_r11d, sib_r15d_r12d, sib_r15d_r13d, sib_r15d_r14d, sib_r15d_r15d,
		MemSib32Scale1End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale2Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_2_eax, sib_eax_2_ecx, sib_eax_2_edx, sib_eax_2_ebx, sib_eax_2_esp, sib_eax_2_disp32 /* disp32 instead ebp */, sib_eax_2_esi, sib_eax_2_edi, sib_eax_2_r8d, sib_eax_2_r9d, sib_eax_2_r10d, sib_eax_2_r11d, sib_eax_2_r12d, sib_eax_2_r13d, sib_eax_2_r14d, sib_eax_2_r15d,
		sib_ecx_2_eax, sib_ecx_2_ecx, sib_ecx_2_edx, sib_ecx_2_ebx, sib_ecx_2_esp, sib_ecx_2_disp32 /* disp32 instead ebp */, sib_ecx_2_esi, sib_ecx_2_edi, sib_ecx_2_r8d, sib_ecx_2_r9d, sib_ecx_2_r10d, sib_ecx_2_r11d, sib_ecx_2_r12d, sib_ecx_2_r13d, sib_ecx_2_r14d, sib_ecx_2_r15d,
		sib_edx_2_eax, sib_edx_2_ecx, sib_edx_2_edx, sib_edx_2_ebx, sib_edx_2_esp, sib_edx_2_disp32 /* disp32 instead ebp */, sib_edx_2_esi, sib_edx_2_edi, sib_edx_2_r8d, sib_edx_2_r9d, sib_edx_2_r10d, sib_edx_2_r11d, sib_edx_2_r12d, sib_edx_2_r13d, sib_edx_2_r14d, sib_edx_2_r15d,
		sib_ebx_2_eax, sib_ebx_2_ecx, sib_ebx_2_edx, sib_ebx_2_ebx, sib_ebx_2_esp, sib_ebx_2_disp32 /* disp32 instead ebp */, sib_ebx_2_esi, sib_ebx_2_edi, sib_ebx_2_r8d, sib_ebx_2_r9d, sib_ebx_2_r10d, sib_ebx_2_r11d, sib_ebx_2_r12d, sib_ebx_2_r13d, sib_ebx_2_r14d, sib_ebx_2_r15d,
		sib_none_2_eax, sib_none_2_ecx, sib_none_2_edx, sib_none_2_ebx, sib_none_2_esp, sib_none_2_disp32 /* disp32 instead ebp */, sib_none_2_esi, sib_none_2_edi, sib_none_2_r8d, sib_none_2_r9d, sib_none_2_r10d, sib_none_2_r11d, sib_none_2_r12d, sib_none_2_r13d, sib_none_2_r14d, sib_none_2_r15d,
		sib_ebp_2_eax, sib_ebp_2_ecx, sib_ebp_2_edx, sib_ebp_2_ebx, sib_ebp_2_esp, sib_ebp_2_disp32 /* disp32 instead ebp */, sib_ebp_2_esi, sib_ebp_2_edi, sib_ebp_2_r8d, sib_ebp_2_r9d, sib_ebp_2_r10d, sib_ebp_2_r11d, sib_ebp_2_r12d, sib_ebp_2_r13d, sib_ebp_2_r14d, sib_ebp_2_r15d,
		sib_esi_2_eax, sib_esi_2_ecx, sib_esi_2_edx, sib_esi_2_ebx, sib_esi_2_esp, sib_esi_2_disp32 /* disp32 instead ebp */, sib_esi_2_esi, sib_esi_2_edi, sib_esi_2_r8d, sib_esi_2_r9d, sib_esi_2_r10d, sib_esi_2_r11d, sib_esi_2_r12d, sib_esi_2_r13d, sib_esi_2_r14d, sib_esi_2_r15d,
		sib_edi_2_eax, sib_edi_2_ecx, sib_edi_2_edx, sib_edi_2_ebx, sib_edi_2_esp, sib_edi_2_disp32 /* disp32 instead ebp */, sib_edi_2_esi, sib_edi_2_edi, sib_edi_2_r8d, sib_edi_2_r9d, sib_edi_2_r10d, sib_edi_2_r11d, sib_edi_2_r12d, sib_edi_2_r13d, sib_edi_2_r14d, sib_edi_2_r15d,
		sib_r8d_2_eax, sib_r8d_2_ecx, sib_r8d_2_edx, sib_r8d_2_ebx, sib_r8d_2_esp, sib_r8d_2_disp32 /* disp32 instead ebp */, sib_r8d_2_esi, sib_r8d_2_edi, sib_r8d_2_r8d, sib_r8d_2_r9d, sib_r8d_2_r10d, sib_r8d_2_r11d, sib_r8d_2_r12d, sib_r8d_2_r13d, sib_r8d_2_r14d, sib_r8d_2_r15d,
		sib_r9d_2_eax, sib_r9d_2_ecx, sib_r9d_2_edx, sib_r9d_2_ebx, sib_r9d_2_esp, sib_r9d_2_disp32 /* disp32 instead ebp */, sib_r9d_2_esi, sib_r9d_2_edi, sib_r9d_2_r8d, sib_r9d_2_r9d, sib_r9d_2_r10d, sib_r9d_2_r11d, sib_r9d_2_r12d, sib_r9d_2_r13d, sib_r9d_2_r14d, sib_r9d_2_r15d,
		sib_r10d_2_eax, sib_r10d_2_ecx, sib_r10d_2_edx, sib_r10d_2_ebx, sib_r10d_2_esp, sib_r10d_2_disp32 /* disp32 instead ebp */, sib_r10d_2_esi, sib_r10d_2_edi, sib_r10d_2_r8d, sib_r10d_2_r9d, sib_r10d_2_r10d, sib_r10d_2_r11d, sib_r10d_2_r12d, sib_r10d_2_r13d, sib_r10d_2_r14d, sib_r10d_2_r15d,
		sib_r11d_2_eax, sib_r11d_2_ecx, sib_r11d_2_edx, sib_r11d_2_ebx, sib_r11d_2_esp, sib_r11d_2_disp32 /* disp32 instead ebp */, sib_r11d_2_esi, sib_r11d_2_edi, sib_r11d_2_r8d, sib_r11d_2_r9d, sib_r11d_2_r10d, sib_r11d_2_r11d, sib_r11d_2_r12d, sib_r11d_2_r13d, sib_r11d_2_r14d, sib_r11d_2_r15d,
		sib_r12d_2_eax, sib_r12d_2_ecx, sib_r12d_2_edx, sib_r12d_2_ebx, sib_r12d_2_esp, sib_r12d_2_disp32 /* disp32 instead ebp */, sib_r12d_2_esi, sib_r12d_2_edi, sib_r12d_2_r8d, sib_r12d_2_r9d, sib_r12d_2_r10d, sib_r12d_2_r11d, sib_r12d_2_r12d, sib_r12d_2_r13d, sib_r12d_2_r14d, sib_r12d_2_r15d,
		sib_r13d_2_eax, sib_r13d_2_ecx, sib_r13d_2_edx, sib_r13d_2_ebx, sib_r13d_2_esp, sib_r13d_2_disp32 /* disp32 instead ebp */, sib_r13d_2_esi, sib_r13d_2_edi, sib_r13d_2_r8d, sib_r13d_2_r9d, sib_r13d_2_r10d, sib_r13d_2_r11d, sib_r13d_2_r12d, sib_r13d_2_r13d, sib_r13d_2_r14d, sib_r13d_2_r15d,
		sib_r14d_2_eax, sib_r14d_2_ecx, sib_r14d_2_edx, sib_r14d_2_ebx, sib_r14d_2_esp, sib_r14d_2_disp32 /* disp32 instead ebp */, sib_r14d_2_esi, sib_r14d_2_edi, sib_r14d_2_r8d, sib_r14d_2_r9d, sib_r14d_2_r10d, sib_r14d_2_r11d, sib_r14d_2_r12d, sib_r14d_2_r13d, sib_r14d_2_r14d, sib_r14d_2_r15d,
		sib_r15d_2_eax, sib_r15d_2_ecx, sib_r15d_2_edx, sib_r15d_2_ebx, sib_r15d_2_esp, sib_r15d_2_disp32 /* disp32 instead ebp */, sib_r15d_2_esi, sib_r15d_2_edi, sib_r15d_2_r8d, sib_r15d_2_r9d, sib_r15d_2_r10d, sib_r15d_2_r11d, sib_r15d_2_r12d, sib_r15d_2_r13d, sib_r15d_2_r14d, sib_r15d_2_r15d,
		MemSib32Scale2End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale4Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_4_eax, sib_eax_4_ecx, sib_eax_4_edx, sib_eax_4_ebx, sib_eax_4_esp, sib_eax_4_disp32 /* disp32 instead ebp */, sib_eax_4_esi, sib_eax_4_edi, sib_eax_4_r8d, sib_eax_4_r9d, sib_eax_4_r10d, sib_eax_4_r11d, sib_eax_4_r12d, sib_eax_4_r13d, sib_eax_4_r14d, sib_eax_4_r15d,
		sib_ecx_4_eax, sib_ecx_4_ecx, sib_ecx_4_edx, sib_ecx_4_ebx, sib_ecx_4_esp, sib_ecx_4_disp32 /* disp32 instead ebp */, sib_ecx_4_esi, sib_ecx_4_edi, sib_ecx_4_r8d, sib_ecx_4_r9d, sib_ecx_4_r10d, sib_ecx_4_r11d, sib_ecx_4_r12d, sib_ecx_4_r13d, sib_ecx_4_r14d, sib_ecx_4_r15d,
		sib_edx_4_eax, sib_edx_4_ecx, sib_edx_4_edx, sib_edx_4_ebx, sib_edx_4_esp, sib_edx_4_disp32 /* disp32 instead ebp */, sib_edx_4_esi, sib_edx_4_edi, sib_edx_4_r8d, sib_edx_4_r9d, sib_edx_4_r10d, sib_edx_4_r11d, sib_edx_4_r12d, sib_edx_4_r13d, sib_edx_4_r14d, sib_edx_4_r15d,
		sib_ebx_4_eax, sib_ebx_4_ecx, sib_ebx_4_edx, sib_ebx_4_ebx, sib_ebx_4_esp, sib_ebx_4_disp32 /* disp32 instead ebp */, sib_ebx_4_esi, sib_ebx_4_edi, sib_ebx_4_r8d, sib_ebx_4_r9d, sib_ebx_4_r10d, sib_ebx_4_r11d, sib_ebx_4_r12d, sib_ebx_4_r13d, sib_ebx_4_r14d, sib_ebx_4_r15d,
		sib_none_4_eax, sib_none_4_ecx, sib_none_4_edx, sib_none_4_ebx, sib_none_4_esp, sib_none_4_disp32 /* disp32 instead ebp */, sib_none_4_esi, sib_none_4_edi, sib_none_4_r8d, sib_none_4_r9d, sib_none_4_r10d, sib_none_4_r11d, sib_none_4_r12d, sib_none_4_r13d, sib_none_4_r14d, sib_none_4_r15d,
		sib_ebp_4_eax, sib_ebp_4_ecx, sib_ebp_4_edx, sib_ebp_4_ebx, sib_ebp_4_esp, sib_ebp_4_disp32 /* disp32 instead ebp */, sib_ebp_4_esi, sib_ebp_4_edi, sib_ebp_4_r8d, sib_ebp_4_r9d, sib_ebp_4_r10d, sib_ebp_4_r11d, sib_ebp_4_r12d, sib_ebp_4_r13d, sib_ebp_4_r14d, sib_ebp_4_r15d,
		sib_esi_4_eax, sib_esi_4_ecx, sib_esi_4_edx, sib_esi_4_ebx, sib_esi_4_esp, sib_esi_4_disp32 /* disp32 instead ebp */, sib_esi_4_esi, sib_esi_4_edi, sib_esi_4_r8d, sib_esi_4_r9d, sib_esi_4_r10d, sib_esi_4_r11d, sib_esi_4_r12d, sib_esi_4_r13d, sib_esi_4_r14d, sib_esi_4_r15d,
		sib_edi_4_eax, sib_edi_4_ecx, sib_edi_4_edx, sib_edi_4_ebx, sib_edi_4_esp, sib_edi_4_disp32 /* disp32 instead ebp */, sib_edi_4_esi, sib_edi_4_edi, sib_edi_4_r8d, sib_edi_4_r9d, sib_edi_4_r10d, sib_edi_4_r11d, sib_edi_4_r12d, sib_edi_4_r13d, sib_edi_4_r14d, sib_edi_4_r15d,
		sib_r8d_4_eax, sib_r8d_4_ecx, sib_r8d_4_edx, sib_r8d_4_ebx, sib_r8d_4_esp, sib_r8d_4_disp32 /* disp32 instead ebp */, sib_r8d_4_esi, sib_r8d_4_edi, sib_r8d_4_r8d, sib_r8d_4_r9d, sib_r8d_4_r10d, sib_r8d_4_r11d, sib_r8d_4_r12d, sib_r8d_4_r13d, sib_r8d_4_r14d, sib_r8d_4_r15d,
		sib_r9d_4_eax, sib_r9d_4_ecx, sib_r9d_4_edx, sib_r9d_4_ebx, sib_r9d_4_esp, sib_r9d_4_disp32 /* disp32 instead ebp */, sib_r9d_4_esi, sib_r9d_4_edi, sib_r9d_4_r8d, sib_r9d_4_r9d, sib_r9d_4_r10d, sib_r9d_4_r11d, sib_r9d_4_r12d, sib_r9d_4_r13d, sib_r9d_4_r14d, sib_r9d_4_r15d,
		sib_r10d_4_eax, sib_r10d_4_ecx, sib_r10d_4_edx, sib_r10d_4_ebx, sib_r10d_4_esp, sib_r10d_4_disp32 /* disp32 instead ebp */, sib_r10d_4_esi, sib_r10d_4_edi, sib_r10d_4_r8d, sib_r10d_4_r9d, sib_r10d_4_r10d, sib_r10d_4_r11d, sib_r10d_4_r12d, sib_r10d_4_r13d, sib_r10d_4_r14d, sib_r10d_4_r15d,
		sib_r11d_4_eax, sib_r11d_4_ecx, sib_r11d_4_edx, sib_r11d_4_ebx, sib_r11d_4_esp, sib_r11d_4_disp32 /* disp32 instead ebp */, sib_r11d_4_esi, sib_r11d_4_edi, sib_r11d_4_r8d, sib_r11d_4_r9d, sib_r11d_4_r10d, sib_r11d_4_r11d, sib_r11d_4_r12d, sib_r11d_4_r13d, sib_r11d_4_r14d, sib_r11d_4_r15d,
		sib_r12d_4_eax, sib_r12d_4_ecx, sib_r12d_4_edx, sib_r12d_4_ebx, sib_r12d_4_esp, sib_r12d_4_disp32 /* disp32 instead ebp */, sib_r12d_4_esi, sib_r12d_4_edi, sib_r12d_4_r8d, sib_r12d_4_r9d, sib_r12d_4_r10d, sib_r12d_4_r11d, sib_r12d_4_r12d, sib_r12d_4_r13d, sib_r12d_4_r14d, sib_r12d_4_r15d,
		sib_r13d_4_eax, sib_r13d_4_ecx, sib_r13d_4_edx, sib_r13d_4_ebx, sib_r13d_4_esp, sib_r13d_4_disp32 /* disp32 instead ebp */, sib_r13d_4_esi, sib_r13d_4_edi, sib_r13d_4_r8d, sib_r13d_4_r9d, sib_r13d_4_r10d, sib_r13d_4_r11d, sib_r13d_4_r12d, sib_r13d_4_r13d, sib_r13d_4_r14d, sib_r13d_4_r15d,
		sib_r14d_4_eax, sib_r14d_4_ecx, sib_r14d_4_edx, sib_r14d_4_ebx, sib_r14d_4_esp, sib_r14d_4_disp32 /* disp32 instead ebp */, sib_r14d_4_esi, sib_r14d_4_edi, sib_r14d_4_r8d, sib_r14d_4_r9d, sib_r14d_4_r10d, sib_r14d_4_r11d, sib_r14d_4_r12d, sib_r14d_4_r13d, sib_r14d_4_r14d, sib_r14d_4_r15d,
		sib_r15d_4_eax, sib_r15d_4_ecx, sib_r15d_4_edx, sib_r15d_4_ebx, sib_r15d_4_esp, sib_r15d_4_disp32 /* disp32 instead ebp */, sib_r15d_4_esi, sib_r15d_4_edi, sib_r15d_4_r8d, sib_r15d_4_r9d, sib_r15d_4_r10d, sib_r15d_4_r11d, sib_r15d_4_r12d, sib_r15d_4_r13d, sib_r15d_4_r14d, sib_r15d_4_r15d,
		MemSib32Scale4End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_8_eax, sib_eax_8_ecx, sib_eax_8_edx, sib_eax_8_ebx, sib_eax_8_esp, sib_eax_8_disp32 /* disp32 instead ebp */, sib_eax_8_esi, sib_eax_8_edi, sib_eax_8_r8d, sib_eax_8_r9d, sib_eax_8_r10d, sib_eax_8_r11d, sib_eax_8_r12d, sib_eax_8_r13d, sib_eax_8_r14d, sib_eax_8_r15d,
		sib_ecx_8_eax, sib_ecx_8_ecx, sib_ecx_8_edx, sib_ecx_8_ebx, sib_ecx_8_esp, sib_ecx_8_disp32 /* disp32 instead ebp */, sib_ecx_8_esi, sib_ecx_8_edi, sib_ecx_8_r8d, sib_ecx_8_r9d, sib_ecx_8_r10d, sib_ecx_8_r11d, sib_ecx_8_r12d, sib_ecx_8_r13d, sib_ecx_8_r14d, sib_ecx_8_r15d,
		sib_edx_8_eax, sib_edx_8_ecx, sib_edx_8_edx, sib_edx_8_ebx, sib_edx_8_esp, sib_edx_8_disp32 /* disp32 instead ebp */, sib_edx_8_esi, sib_edx_8_edi, sib_edx_8_r8d, sib_edx_8_r9d, sib_edx_8_r10d, sib_edx_8_r11d, sib_edx_8_r12d, sib_edx_8_r13d, sib_edx_8_r14d, sib_edx_8_r15d,
		sib_ebx_8_eax, sib_ebx_8_ecx, sib_ebx_8_edx, sib_ebx_8_ebx, sib_ebx_8_esp, sib_ebx_8_disp32 /* disp32 instead ebp */, sib_ebx_8_esi, sib_ebx_8_edi, sib_ebx_8_r8d, sib_ebx_8_r9d, sib_ebx_8_r10d, sib_ebx_8_r11d, sib_ebx_8_r12d, sib_ebx_8_r13d, sib_ebx_8_r14d, sib_ebx_8_r15d,
		sib_none_8_eax, sib_none_8_ecx, sib_none_8_edx, sib_none_8_ebx, sib_none_8_esp, sib_none_8_disp32 /* disp32 instead ebp */, sib_none_8_esi, sib_none_8_edi, sib_none_8_r8d, sib_none_8_r9d, sib_none_8_r10d, sib_none_8_r11d, sib_none_8_r12d, sib_none_8_r13d, sib_none_8_r14d, sib_none_8_r15d,
		sib_ebp_8_eax, sib_ebp_8_ecx, sib_ebp_8_edx, sib_ebp_8_ebx, sib_ebp_8_esp, sib_ebp_8_disp32 /* disp32 instead ebp */, sib_ebp_8_esi, sib_ebp_8_edi, sib_ebp_8_r8d, sib_ebp_8_r9d, sib_ebp_8_r10d, sib_ebp_8_r11d, sib_ebp_8_r12d, sib_ebp_8_r13d, sib_ebp_8_r14d, sib_ebp_8_r15d,
		sib_esi_8_eax, sib_esi_8_ecx, sib_esi_8_edx, sib_esi_8_ebx, sib_esi_8_esp, sib_esi_8_disp32 /* disp32 instead ebp */, sib_esi_8_esi, sib_esi_8_edi, sib_esi_8_r8d, sib_esi_8_r9d, sib_esi_8_r10d, sib_esi_8_r11d, sib_esi_8_r12d, sib_esi_8_r13d, sib_esi_8_r14d, sib_esi_8_r15d,
		sib_edi_8_eax, sib_edi_8_ecx, sib_edi_8_edx, sib_edi_8_ebx, sib_edi_8_esp, sib_edi_8_disp32 /* disp32 instead ebp */, sib_edi_8_esi, sib_edi_8_edi, sib_edi_8_r8d, sib_edi_8_r9d, sib_edi_8_r10d, sib_edi_8_r11d, sib_edi_8_r12d, sib_edi_8_r13d, sib_edi_8_r14d, sib_edi_8_r15d,
		sib_r8d_8_eax, sib_r8d_8_ecx, sib_r8d_8_edx, sib_r8d_8_ebx, sib_r8d_8_esp, sib_r8d_8_disp32 /* disp32 instead ebp */, sib_r8d_8_esi, sib_r8d_8_edi, sib_r8d_8_r8d, sib_r8d_8_r9d, sib_r8d_8_r10d, sib_r8d_8_r11d, sib_r8d_8_r12d, sib_r8d_8_r13d, sib_r8d_8_r14d, sib_r8d_8_r15d,
		sib_r9d_8_eax, sib_r9d_8_ecx, sib_r9d_8_edx, sib_r9d_8_ebx, sib_r9d_8_esp, sib_r9d_8_disp32 /* disp32 instead ebp */, sib_r9d_8_esi, sib_r9d_8_edi, sib_r9d_8_r8d, sib_r9d_8_r9d, sib_r9d_8_r10d, sib_r9d_8_r11d, sib_r9d_8_r12d, sib_r9d_8_r13d, sib_r9d_8_r14d, sib_r9d_8_r15d,
		sib_r10d_8_eax, sib_r10d_8_ecx, sib_r10d_8_edx, sib_r10d_8_ebx, sib_r10d_8_esp, sib_r10d_8_disp32 /* disp32 instead ebp */, sib_r10d_8_esi, sib_r10d_8_edi, sib_r10d_8_r8d, sib_r10d_8_r9d, sib_r10d_8_r10d, sib_r10d_8_r11d, sib_r10d_8_r12d, sib_r10d_8_r13d, sib_r10d_8_r14d, sib_r10d_8_r15d,
		sib_r11d_8_eax, sib_r11d_8_ecx, sib_r11d_8_edx, sib_r11d_8_ebx, sib_r11d_8_esp, sib_r11d_8_disp32 /* disp32 instead ebp */, sib_r11d_8_esi, sib_r11d_8_edi, sib_r11d_8_r8d, sib_r11d_8_r9d, sib_r11d_8_r10d, sib_r11d_8_r11d, sib_r11d_8_r12d, sib_r11d_8_r13d, sib_r11d_8_r14d, sib_r11d_8_r15d,
		sib_r12d_8_eax, sib_r12d_8_ecx, sib_r12d_8_edx, sib_r12d_8_ebx, sib_r12d_8_esp, sib_r12d_8_disp32 /* disp32 instead ebp */, sib_r12d_8_esi, sib_r12d_8_edi, sib_r12d_8_r8d, sib_r12d_8_r9d, sib_r12d_8_r10d, sib_r12d_8_r11d, sib_r12d_8_r12d, sib_r12d_8_r13d, sib_r12d_8_r14d, sib_r12d_8_r15d,
		sib_r13d_8_eax, sib_r13d_8_ecx, sib_r13d_8_edx, sib_r13d_8_ebx, sib_r13d_8_esp, sib_r13d_8_disp32 /* disp32 instead ebp */, sib_r13d_8_esi, sib_r13d_8_edi, sib_r13d_8_r8d, sib_r13d_8_r9d, sib_r13d_8_r10d, sib_r13d_8_r11d, sib_r13d_8_r12d, sib_r13d_8_r13d, sib_r13d_8_r14d, sib_r13d_8_r15d,
		sib_r14d_8_eax, sib_r14d_8_ecx, sib_r14d_8_edx, sib_r14d_8_ebx, sib_r14d_8_esp, sib_r14d_8_disp32 /* disp32 instead ebp */, sib_r14d_8_esi, sib_r14d_8_edi, sib_r14d_8_r8d, sib_r14d_8_r9d, sib_r14d_8_r10d, sib_r14d_8_r11d, sib_r14d_8_r12d, sib_r14d_8_r13d, sib_r14d_8_r14d, sib_r14d_8_r15d,
		sib_r15d_8_eax, sib_r15d_8_ecx, sib_r15d_8_edx, sib_r15d_8_ebx, sib_r15d_8_esp, sib_r15d_8_disp32 /* disp32 instead ebp */, sib_r15d_8_esi, sib_r15d_8_edi, sib_r15d_8_r8d, sib_r15d_8_r9d, sib_r15d_8_r10d, sib_r15d_8_r11d, sib_r15d_8_r12d, sib_r15d_8_r13d, sib_r15d_8_r14d, sib_r15d_8_r15d,
		MemSib32Scale8End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Disp8Start,		// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib32Scale1Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_eax_disp8, sib_eax_ecx_disp8, sib_eax_edx_disp8, sib_eax_ebx_disp8, sib_eax_esp_disp8, sib_eax_ebp_disp8, sib_eax_esi_disp8, sib_eax_edi_disp8, sib_eax_r8d_disp8, sib_eax_r9d_disp8, sib_eax_r10d_disp8, sib_eax_r11d_disp8, sib_eax_r12d_disp8, sib_eax_r13d_disp8, sib_eax_r14d_disp8, sib_eax_r15d_disp8,
		sib_ecx_eax_disp8, sib_ecx_ecx_disp8, sib_ecx_edx_disp8, sib_ecx_ebx_disp8, sib_ecx_esp_disp8, sib_ecx_ebp_disp8, sib_ecx_esi_disp8, sib_ecx_edi_disp8, sib_ecx_r8d_disp8, sib_ecx_r9d_disp8, sib_ecx_r10d_disp8, sib_ecx_r11d_disp8, sib_ecx_r12d_disp8, sib_ecx_r13d_disp8, sib_ecx_r14d_disp8, sib_ecx_r15d_disp8,
		sib_edx_eax_disp8, sib_edx_ecx_disp8, sib_edx_edx_disp8, sib_edx_ebx_disp8, sib_edx_esp_disp8, sib_edx_ebp_disp8, sib_edx_esi_disp8, sib_edx_edi_disp8, sib_edx_r8d_disp8, sib_edx_r9d_disp8, sib_edx_r10d_disp8, sib_edx_r11d_disp8, sib_edx_r12d_disp8, sib_edx_r13d_disp8, sib_edx_r14d_disp8, sib_edx_r15d_disp8,
		sib_ebx_eax_disp8, sib_ebx_ecx_disp8, sib_ebx_edx_disp8, sib_ebx_ebx_disp8, sib_ebx_esp_disp8, sib_ebx_ebp_disp8, sib_ebx_esi_disp8, sib_ebx_edi_disp8, sib_ebx_r8d_disp8, sib_ebx_r9d_disp8, sib_ebx_r10d_disp8, sib_ebx_r11d_disp8, sib_ebx_r12d_disp8, sib_ebx_r13d_disp8, sib_ebx_r14d_disp8, sib_ebx_r15d_disp8,
		sib_none_eax_disp8, sib_none_ecx_disp8, sib_none_edx_disp8, sib_none_ebx_disp8, sib_none_esp_disp8, sib_none_ebp_disp8, sib_none_esi_disp8, sib_none_edi_disp8, sib_none_r8d_disp8, sib_none_r9d_disp8, sib_none_r10d_disp8, sib_none_r11d_disp8, sib_none_r12d_disp8, sib_none_r13d_disp8, sib_none_r14d_disp8, sib_none_r15d_disp8,
		sib_ebp_eax_disp8, sib_ebp_ecx_disp8, sib_ebp_edx_disp8, sib_ebp_ebx_disp8, sib_ebp_esp_disp8, sib_ebp_ebp_disp8, sib_ebp_esi_disp8, sib_ebp_edi_disp8, sib_ebp_r8d_disp8, sib_ebp_r9d_disp8, sib_ebp_r10d_disp8, sib_ebp_r11d_disp8, sib_ebp_r12d_disp8, sib_ebp_r13d_disp8, sib_ebp_r14d_disp8, sib_ebp_r15d_disp8,
		sib_esi_eax_disp8, sib_esi_ecx_disp8, sib_esi_edx_disp8, sib_esi_ebx_disp8, sib_esi_esp_disp8, sib_esi_ebp_disp8, sib_esi_esi_disp8, sib_esi_edi_disp8, sib_esi_r8d_disp8, sib_esi_r9d_disp8, sib_esi_r10d_disp8, sib_esi_r11d_disp8, sib_esi_r12d_disp8, sib_esi_r13d_disp8, sib_esi_r14d_disp8, sib_esi_r15d_disp8,
		sib_edi_eax_disp8, sib_edi_ecx_disp8, sib_edi_edx_disp8, sib_edi_ebx_disp8, sib_edi_esp_disp8, sib_edi_ebp_disp8, sib_edi_esi_disp8, sib_edi_edi_disp8, sib_edi_r8d_disp8, sib_edi_r9d_disp8, sib_edi_r10d_disp8, sib_edi_r11d_disp8, sib_edi_r12d_disp8, sib_edi_r13d_disp8, sib_edi_r14d_disp8, sib_edi_r15d_disp8,
		sib_r8d_eax_disp8, sib_r8d_ecx_disp8, sib_r8d_edx_disp8, sib_r8d_ebx_disp8, sib_r8d_esp_disp8, sib_r8d_ebp_disp8, sib_r8d_esi_disp8, sib_r8d_edi_disp8, sib_r8d_r8d_disp8, sib_r8d_r9d_disp8, sib_r8d_r10d_disp8, sib_r8d_r11d_disp8, sib_r8d_r12d_disp8, sib_r8d_r13d_disp8, sib_r8d_r14d_disp8, sib_r8d_r15d_disp8,
		sib_r9d_eax_disp8, sib_r9d_ecx_disp8, sib_r9d_edx_disp8, sib_r9d_ebx_disp8, sib_r9d_esp_disp8, sib_r9d_ebp_disp8, sib_r9d_esi_disp8, sib_r9d_edi_disp8, sib_r9d_r8d_disp8, sib_r9d_r9d_disp8, sib_r9d_r10d_disp8, sib_r9d_r11d_disp8, sib_r9d_r12d_disp8, sib_r9d_r13d_disp8, sib_r9d_r14d_disp8, sib_r9d_r15d_disp8,
		sib_r10d_eax_disp8, sib_r10d_ecx_disp8, sib_r10d_edx_disp8, sib_r10d_ebx_disp8, sib_r10d_esp_disp8, sib_r10d_ebp_disp8, sib_r10d_esi_disp8, sib_r10d_edi_disp8, sib_r10d_r8d_disp8, sib_r10d_r9d_disp8, sib_r10d_r10d_disp8, sib_r10d_r11d_disp8, sib_r10d_r12d_disp8, sib_r10d_r13d_disp8, sib_r10d_r14d_disp8, sib_r10d_r15d_disp8,
		sib_r11d_eax_disp8, sib_r11d_ecx_disp8, sib_r11d_edx_disp8, sib_r11d_ebx_disp8, sib_r11d_esp_disp8, sib_r11d_ebp_disp8, sib_r11d_esi_disp8, sib_r11d_edi_disp8, sib_r11d_r8d_disp8, sib_r11d_r9d_disp8, sib_r11d_r10d_disp8, sib_r11d_r11d_disp8, sib_r11d_r12d_disp8, sib_r11d_r13d_disp8, sib_r11d_r14d_disp8, sib_r11d_r15d_disp8,
		sib_r12d_eax_disp8, sib_r12d_ecx_disp8, sib_r12d_edx_disp8, sib_r12d_ebx_disp8, sib_r12d_esp_disp8, sib_r12d_ebp_disp8, sib_r12d_esi_disp8, sib_r12d_edi_disp8, sib_r12d_r8d_disp8, sib_r12d_r9d_disp8, sib_r12d_r10d_disp8, sib_r12d_r11d_disp8, sib_r12d_r12d_disp8, sib_r12d_r13d_disp8, sib_r12d_r14d_disp8, sib_r12d_r15d_disp8,
		sib_r13d_eax_disp8, sib_r13d_ecx_disp8, sib_r13d_edx_disp8, sib_r13d_ebx_disp8, sib_r13d_esp_disp8, sib_r13d_ebp_disp8, sib_r13d_esi_disp8, sib_r13d_edi_disp8, sib_r13d_r8d_disp8, sib_r13d_r9d_disp8, sib_r13d_r10d_disp8, sib_r13d_r11d_disp8, sib_r13d_r12d_disp8, sib_r13d_r13d_disp8, sib_r13d_r14d_disp8, sib_r13d_r15d_disp8,
		sib_r14d_eax_disp8, sib_r14d_ecx_disp8, sib_r14d_edx_disp8, sib_r14d_ebx_disp8, sib_r14d_esp_disp8, sib_r14d_ebp_disp8, sib_r14d_esi_disp8, sib_r14d_edi_disp8, sib_r14d_r8d_disp8, sib_r14d_r9d_disp8, sib_r14d_r10d_disp8, sib_r14d_r11d_disp8, sib_r14d_r12d_disp8, sib_r14d_r13d_disp8, sib_r14d_r14d_disp8, sib_r14d_r15d_disp8,
		sib_r15d_eax_disp8, sib_r15d_ecx_disp8, sib_r15d_edx_disp8, sib_r15d_ebx_disp8, sib_r15d_esp_disp8, sib_r15d_ebp_disp8, sib_r15d_esi_disp8, sib_r15d_edi_disp8, sib_r15d_r8d_disp8, sib_r15d_r9d_disp8, sib_r15d_r10d_disp8, sib_r15d_r11d_disp8, sib_r15d_r12d_disp8, sib_r15d_r13d_disp8, sib_r15d_r14d_disp8, sib_r15d_r15d_disp8,
		MemSib32Scale1Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale2Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_2_eax_disp8, sib_eax_2_ecx_disp8, sib_eax_2_edx_disp8, sib_eax_2_ebx_disp8, sib_eax_2_esp_disp8, sib_eax_2_ebp_disp8, sib_eax_2_esi_disp8, sib_eax_2_edi_disp8, sib_eax_2_r8d_disp8, sib_eax_2_r9d_disp8, sib_eax_2_r10d_disp8, sib_eax_2_r11d_disp8, sib_eax_2_r12d_disp8, sib_eax_2_r13d_disp8, sib_eax_2_r14d_disp8, sib_eax_2_r15d_disp8,
		sib_ecx_2_eax_disp8, sib_ecx_2_ecx_disp8, sib_ecx_2_edx_disp8, sib_ecx_2_ebx_disp8, sib_ecx_2_esp_disp8, sib_ecx_2_ebp_disp8, sib_ecx_2_esi_disp8, sib_ecx_2_edi_disp8, sib_ecx_2_r8d_disp8, sib_ecx_2_r9d_disp8, sib_ecx_2_r10d_disp8, sib_ecx_2_r11d_disp8, sib_ecx_2_r12d_disp8, sib_ecx_2_r13d_disp8, sib_ecx_2_r14d_disp8, sib_ecx_2_r15d_disp8,
		sib_edx_2_eax_disp8, sib_edx_2_ecx_disp8, sib_edx_2_edx_disp8, sib_edx_2_ebx_disp8, sib_edx_2_esp_disp8, sib_edx_2_ebp_disp8, sib_edx_2_esi_disp8, sib_edx_2_edi_disp8, sib_edx_2_r8d_disp8, sib_edx_2_r9d_disp8, sib_edx_2_r10d_disp8, sib_edx_2_r11d_disp8, sib_edx_2_r12d_disp8, sib_edx_2_r13d_disp8, sib_edx_2_r14d_disp8, sib_edx_2_r15d_disp8,
		sib_ebx_2_eax_disp8, sib_ebx_2_ecx_disp8, sib_ebx_2_edx_disp8, sib_ebx_2_ebx_disp8, sib_ebx_2_esp_disp8, sib_ebx_2_ebp_disp8, sib_ebx_2_esi_disp8, sib_ebx_2_edi_disp8, sib_ebx_2_r8d_disp8, sib_ebx_2_r9d_disp8, sib_ebx_2_r10d_disp8, sib_ebx_2_r11d_disp8, sib_ebx_2_r12d_disp8, sib_ebx_2_r13d_disp8, sib_ebx_2_r14d_disp8, sib_ebx_2_r15d_disp8,
		sib_none_2_eax_disp8, sib_none_2_ecx_disp8, sib_none_2_edx_disp8, sib_none_2_ebx_disp8, sib_none_2_esp_disp8, sib_none_2_ebp_disp8, sib_none_2_esi_disp8, sib_none_2_edi_disp8, sib_none_2_r8d_disp8, sib_none_2_r9d_disp8, sib_none_2_r10d_disp8, sib_none_2_r11d_disp8, sib_none_2_r12d_disp8, sib_none_2_r13d_disp8, sib_none_2_r14d_disp8, sib_none_2_r15d_disp8,
		sib_ebp_2_eax_disp8, sib_ebp_2_ecx_disp8, sib_ebp_2_edx_disp8, sib_ebp_2_ebx_disp8, sib_ebp_2_esp_disp8, sib_ebp_2_ebp_disp8, sib_ebp_2_esi_disp8, sib_ebp_2_edi_disp8, sib_ebp_2_r8d_disp8, sib_ebp_2_r9d_disp8, sib_ebp_2_r10d_disp8, sib_ebp_2_r11d_disp8, sib_ebp_2_r12d_disp8, sib_ebp_2_r13d_disp8, sib_ebp_2_r14d_disp8, sib_ebp_2_r15d_disp8,
		sib_esi_2_eax_disp8, sib_esi_2_ecx_disp8, sib_esi_2_edx_disp8, sib_esi_2_ebx_disp8, sib_esi_2_esp_disp8, sib_esi_2_ebp_disp8, sib_esi_2_esi_disp8, sib_esi_2_edi_disp8, sib_esi_2_r8d_disp8, sib_esi_2_r9d_disp8, sib_esi_2_r10d_disp8, sib_esi_2_r11d_disp8, sib_esi_2_r12d_disp8, sib_esi_2_r13d_disp8, sib_esi_2_r14d_disp8, sib_esi_2_r15d_disp8,
		sib_edi_2_eax_disp8, sib_edi_2_ecx_disp8, sib_edi_2_edx_disp8, sib_edi_2_ebx_disp8, sib_edi_2_esp_disp8, sib_edi_2_ebp_disp8, sib_edi_2_esi_disp8, sib_edi_2_edi_disp8, sib_edi_2_r8d_disp8, sib_edi_2_r9d_disp8, sib_edi_2_r10d_disp8, sib_edi_2_r11d_disp8, sib_edi_2_r12d_disp8, sib_edi_2_r13d_disp8, sib_edi_2_r14d_disp8, sib_edi_2_r15d_disp8,
		sib_r8d_2_eax_disp8, sib_r8d_2_ecx_disp8, sib_r8d_2_edx_disp8, sib_r8d_2_ebx_disp8, sib_r8d_2_esp_disp8, sib_r8d_2_ebp_disp8, sib_r8d_2_esi_disp8, sib_r8d_2_edi_disp8, sib_r8d_2_r8d_disp8, sib_r8d_2_r9d_disp8, sib_r8d_2_r10d_disp8, sib_r8d_2_r11d_disp8, sib_r8d_2_r12d_disp8, sib_r8d_2_r13d_disp8, sib_r8d_2_r14d_disp8, sib_r8d_2_r15d_disp8,
		sib_r9d_2_eax_disp8, sib_r9d_2_ecx_disp8, sib_r9d_2_edx_disp8, sib_r9d_2_ebx_disp8, sib_r9d_2_esp_disp8, sib_r9d_2_ebp_disp8, sib_r9d_2_esi_disp8, sib_r9d_2_edi_disp8, sib_r9d_2_r8d_disp8, sib_r9d_2_r9d_disp8, sib_r9d_2_r10d_disp8, sib_r9d_2_r11d_disp8, sib_r9d_2_r12d_disp8, sib_r9d_2_r13d_disp8, sib_r9d_2_r14d_disp8, sib_r9d_2_r15d_disp8,
		sib_r10d_2_eax_disp8, sib_r10d_2_ecx_disp8, sib_r10d_2_edx_disp8, sib_r10d_2_ebx_disp8, sib_r10d_2_esp_disp8, sib_r10d_2_ebp_disp8, sib_r10d_2_esi_disp8, sib_r10d_2_edi_disp8, sib_r10d_2_r8d_disp8, sib_r10d_2_r9d_disp8, sib_r10d_2_r10d_disp8, sib_r10d_2_r11d_disp8, sib_r10d_2_r12d_disp8, sib_r10d_2_r13d_disp8, sib_r10d_2_r14d_disp8, sib_r10d_2_r15d_disp8,
		sib_r11d_2_eax_disp8, sib_r11d_2_ecx_disp8, sib_r11d_2_edx_disp8, sib_r11d_2_ebx_disp8, sib_r11d_2_esp_disp8, sib_r11d_2_ebp_disp8, sib_r11d_2_esi_disp8, sib_r11d_2_edi_disp8, sib_r11d_2_r8d_disp8, sib_r11d_2_r9d_disp8, sib_r11d_2_r10d_disp8, sib_r11d_2_r11d_disp8, sib_r11d_2_r12d_disp8, sib_r11d_2_r13d_disp8, sib_r11d_2_r14d_disp8, sib_r11d_2_r15d_disp8,
		sib_r12d_2_eax_disp8, sib_r12d_2_ecx_disp8, sib_r12d_2_edx_disp8, sib_r12d_2_ebx_disp8, sib_r12d_2_esp_disp8, sib_r12d_2_ebp_disp8, sib_r12d_2_esi_disp8, sib_r12d_2_edi_disp8, sib_r12d_2_r8d_disp8, sib_r12d_2_r9d_disp8, sib_r12d_2_r10d_disp8, sib_r12d_2_r11d_disp8, sib_r12d_2_r12d_disp8, sib_r12d_2_r13d_disp8, sib_r12d_2_r14d_disp8, sib_r12d_2_r15d_disp8,
		sib_r13d_2_eax_disp8, sib_r13d_2_ecx_disp8, sib_r13d_2_edx_disp8, sib_r13d_2_ebx_disp8, sib_r13d_2_esp_disp8, sib_r13d_2_ebp_disp8, sib_r13d_2_esi_disp8, sib_r13d_2_edi_disp8, sib_r13d_2_r8d_disp8, sib_r13d_2_r9d_disp8, sib_r13d_2_r10d_disp8, sib_r13d_2_r11d_disp8, sib_r13d_2_r12d_disp8, sib_r13d_2_r13d_disp8, sib_r13d_2_r14d_disp8, sib_r13d_2_r15d_disp8,
		sib_r14d_2_eax_disp8, sib_r14d_2_ecx_disp8, sib_r14d_2_edx_disp8, sib_r14d_2_ebx_disp8, sib_r14d_2_esp_disp8, sib_r14d_2_ebp_disp8, sib_r14d_2_esi_disp8, sib_r14d_2_edi_disp8, sib_r14d_2_r8d_disp8, sib_r14d_2_r9d_disp8, sib_r14d_2_r10d_disp8, sib_r14d_2_r11d_disp8, sib_r14d_2_r12d_disp8, sib_r14d_2_r13d_disp8, sib_r14d_2_r14d_disp8, sib_r14d_2_r15d_disp8,
		sib_r15d_2_eax_disp8, sib_r15d_2_ecx_disp8, sib_r15d_2_edx_disp8, sib_r15d_2_ebx_disp8, sib_r15d_2_esp_disp8, sib_r15d_2_ebp_disp8, sib_r15d_2_esi_disp8, sib_r15d_2_edi_disp8, sib_r15d_2_r8d_disp8, sib_r15d_2_r9d_disp8, sib_r15d_2_r10d_disp8, sib_r15d_2_r11d_disp8, sib_r15d_2_r12d_disp8, sib_r15d_2_r13d_disp8, sib_r15d_2_r14d_disp8, sib_r15d_2_r15d_disp8,
		MemSib32Scale2Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale4Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_4_eax_disp8, sib_eax_4_ecx_disp8, sib_eax_4_edx_disp8, sib_eax_4_ebx_disp8, sib_eax_4_esp_disp8, sib_eax_4_ebp_disp8, sib_eax_4_esi_disp8, sib_eax_4_edi_disp8, sib_eax_4_r8d_disp8, sib_eax_4_r9d_disp8, sib_eax_4_r10d_disp8, sib_eax_4_r11d_disp8, sib_eax_4_r12d_disp8, sib_eax_4_r13d_disp8, sib_eax_4_r14d_disp8, sib_eax_4_r15d_disp8,
		sib_ecx_4_eax_disp8, sib_ecx_4_ecx_disp8, sib_ecx_4_edx_disp8, sib_ecx_4_ebx_disp8, sib_ecx_4_esp_disp8, sib_ecx_4_ebp_disp8, sib_ecx_4_esi_disp8, sib_ecx_4_edi_disp8, sib_ecx_4_r8d_disp8, sib_ecx_4_r9d_disp8, sib_ecx_4_r10d_disp8, sib_ecx_4_r11d_disp8, sib_ecx_4_r12d_disp8, sib_ecx_4_r13d_disp8, sib_ecx_4_r14d_disp8, sib_ecx_4_r15d_disp8,
		sib_edx_4_eax_disp8, sib_edx_4_ecx_disp8, sib_edx_4_edx_disp8, sib_edx_4_ebx_disp8, sib_edx_4_esp_disp8, sib_edx_4_ebp_disp8, sib_edx_4_esi_disp8, sib_edx_4_edi_disp8, sib_edx_4_r8d_disp8, sib_edx_4_r9d_disp8, sib_edx_4_r10d_disp8, sib_edx_4_r11d_disp8, sib_edx_4_r12d_disp8, sib_edx_4_r13d_disp8, sib_edx_4_r14d_disp8, sib_edx_4_r15d_disp8,
		sib_ebx_4_eax_disp8, sib_ebx_4_ecx_disp8, sib_ebx_4_edx_disp8, sib_ebx_4_ebx_disp8, sib_ebx_4_esp_disp8, sib_ebx_4_ebp_disp8, sib_ebx_4_esi_disp8, sib_ebx_4_edi_disp8, sib_ebx_4_r8d_disp8, sib_ebx_4_r9d_disp8, sib_ebx_4_r10d_disp8, sib_ebx_4_r11d_disp8, sib_ebx_4_r12d_disp8, sib_ebx_4_r13d_disp8, sib_ebx_4_r14d_disp8, sib_ebx_4_r15d_disp8,
		sib_none_4_eax_disp8, sib_none_4_ecx_disp8, sib_none_4_edx_disp8, sib_none_4_ebx_disp8, sib_none_4_esp_disp8, sib_none_4_ebp_disp8, sib_none_4_esi_disp8, sib_none_4_edi_disp8, sib_none_4_r8d_disp8, sib_none_4_r9d_disp8, sib_none_4_r10d_disp8, sib_none_4_r11d_disp8, sib_none_4_r12d_disp8, sib_none_4_r13d_disp8, sib_none_4_r14d_disp8, sib_none_4_r15d_disp8,
		sib_ebp_4_eax_disp8, sib_ebp_4_ecx_disp8, sib_ebp_4_edx_disp8, sib_ebp_4_ebx_disp8, sib_ebp_4_esp_disp8, sib_ebp_4_ebp_disp8, sib_ebp_4_esi_disp8, sib_ebp_4_edi_disp8, sib_ebp_4_r8d_disp8, sib_ebp_4_r9d_disp8, sib_ebp_4_r10d_disp8, sib_ebp_4_r11d_disp8, sib_ebp_4_r12d_disp8, sib_ebp_4_r13d_disp8, sib_ebp_4_r14d_disp8, sib_ebp_4_r15d_disp8,
		sib_esi_4_eax_disp8, sib_esi_4_ecx_disp8, sib_esi_4_edx_disp8, sib_esi_4_ebx_disp8, sib_esi_4_esp_disp8, sib_esi_4_ebp_disp8, sib_esi_4_esi_disp8, sib_esi_4_edi_disp8, sib_esi_4_r8d_disp8, sib_esi_4_r9d_disp8, sib_esi_4_r10d_disp8, sib_esi_4_r11d_disp8, sib_esi_4_r12d_disp8, sib_esi_4_r13d_disp8, sib_esi_4_r14d_disp8, sib_esi_4_r15d_disp8,
		sib_edi_4_eax_disp8, sib_edi_4_ecx_disp8, sib_edi_4_edx_disp8, sib_edi_4_ebx_disp8, sib_edi_4_esp_disp8, sib_edi_4_ebp_disp8, sib_edi_4_esi_disp8, sib_edi_4_edi_disp8, sib_edi_4_r8d_disp8, sib_edi_4_r9d_disp8, sib_edi_4_r10d_disp8, sib_edi_4_r11d_disp8, sib_edi_4_r12d_disp8, sib_edi_4_r13d_disp8, sib_edi_4_r14d_disp8, sib_edi_4_r15d_disp8,
		sib_r8d_4_eax_disp8, sib_r8d_4_ecx_disp8, sib_r8d_4_edx_disp8, sib_r8d_4_ebx_disp8, sib_r8d_4_esp_disp8, sib_r8d_4_ebp_disp8, sib_r8d_4_esi_disp8, sib_r8d_4_edi_disp8, sib_r8d_4_r8d_disp8, sib_r8d_4_r9d_disp8, sib_r8d_4_r10d_disp8, sib_r8d_4_r11d_disp8, sib_r8d_4_r12d_disp8, sib_r8d_4_r13d_disp8, sib_r8d_4_r14d_disp8, sib_r8d_4_r15d_disp8,
		sib_r9d_4_eax_disp8, sib_r9d_4_ecx_disp8, sib_r9d_4_edx_disp8, sib_r9d_4_ebx_disp8, sib_r9d_4_esp_disp8, sib_r9d_4_ebp_disp8, sib_r9d_4_esi_disp8, sib_r9d_4_edi_disp8, sib_r9d_4_r8d_disp8, sib_r9d_4_r9d_disp8, sib_r9d_4_r10d_disp8, sib_r9d_4_r11d_disp8, sib_r9d_4_r12d_disp8, sib_r9d_4_r13d_disp8, sib_r9d_4_r14d_disp8, sib_r9d_4_r15d_disp8,
		sib_r10d_4_eax_disp8, sib_r10d_4_ecx_disp8, sib_r10d_4_edx_disp8, sib_r10d_4_ebx_disp8, sib_r10d_4_esp_disp8, sib_r10d_4_ebp_disp8, sib_r10d_4_esi_disp8, sib_r10d_4_edi_disp8, sib_r10d_4_r8d_disp8, sib_r10d_4_r9d_disp8, sib_r10d_4_r10d_disp8, sib_r10d_4_r11d_disp8, sib_r10d_4_r12d_disp8, sib_r10d_4_r13d_disp8, sib_r10d_4_r14d_disp8, sib_r10d_4_r15d_disp8,
		sib_r11d_4_eax_disp8, sib_r11d_4_ecx_disp8, sib_r11d_4_edx_disp8, sib_r11d_4_ebx_disp8, sib_r11d_4_esp_disp8, sib_r11d_4_ebp_disp8, sib_r11d_4_esi_disp8, sib_r11d_4_edi_disp8, sib_r11d_4_r8d_disp8, sib_r11d_4_r9d_disp8, sib_r11d_4_r10d_disp8, sib_r11d_4_r11d_disp8, sib_r11d_4_r12d_disp8, sib_r11d_4_r13d_disp8, sib_r11d_4_r14d_disp8, sib_r11d_4_r15d_disp8,
		sib_r12d_4_eax_disp8, sib_r12d_4_ecx_disp8, sib_r12d_4_edx_disp8, sib_r12d_4_ebx_disp8, sib_r12d_4_esp_disp8, sib_r12d_4_ebp_disp8, sib_r12d_4_esi_disp8, sib_r12d_4_edi_disp8, sib_r12d_4_r8d_disp8, sib_r12d_4_r9d_disp8, sib_r12d_4_r10d_disp8, sib_r12d_4_r11d_disp8, sib_r12d_4_r12d_disp8, sib_r12d_4_r13d_disp8, sib_r12d_4_r14d_disp8, sib_r12d_4_r15d_disp8,
		sib_r13d_4_eax_disp8, sib_r13d_4_ecx_disp8, sib_r13d_4_edx_disp8, sib_r13d_4_ebx_disp8, sib_r13d_4_esp_disp8, sib_r13d_4_ebp_disp8, sib_r13d_4_esi_disp8, sib_r13d_4_edi_disp8, sib_r13d_4_r8d_disp8, sib_r13d_4_r9d_disp8, sib_r13d_4_r10d_disp8, sib_r13d_4_r11d_disp8, sib_r13d_4_r12d_disp8, sib_r13d_4_r13d_disp8, sib_r13d_4_r14d_disp8, sib_r13d_4_r15d_disp8,
		sib_r14d_4_eax_disp8, sib_r14d_4_ecx_disp8, sib_r14d_4_edx_disp8, sib_r14d_4_ebx_disp8, sib_r14d_4_esp_disp8, sib_r14d_4_ebp_disp8, sib_r14d_4_esi_disp8, sib_r14d_4_edi_disp8, sib_r14d_4_r8d_disp8, sib_r14d_4_r9d_disp8, sib_r14d_4_r10d_disp8, sib_r14d_4_r11d_disp8, sib_r14d_4_r12d_disp8, sib_r14d_4_r13d_disp8, sib_r14d_4_r14d_disp8, sib_r14d_4_r15d_disp8,
		sib_r15d_4_eax_disp8, sib_r15d_4_ecx_disp8, sib_r15d_4_edx_disp8, sib_r15d_4_ebx_disp8, sib_r15d_4_esp_disp8, sib_r15d_4_ebp_disp8, sib_r15d_4_esi_disp8, sib_r15d_4_edi_disp8, sib_r15d_4_r8d_disp8, sib_r15d_4_r9d_disp8, sib_r15d_4_r10d_disp8, sib_r15d_4_r11d_disp8, sib_r15d_4_r12d_disp8, sib_r15d_4_r13d_disp8, sib_r15d_4_r14d_disp8, sib_r15d_4_r15d_disp8,
		MemSib32Scale4Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale8Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_8_eax_disp8, sib_eax_8_ecx_disp8, sib_eax_8_edx_disp8, sib_eax_8_ebx_disp8, sib_eax_8_esp_disp8, sib_eax_8_ebp_disp8, sib_eax_8_esi_disp8, sib_eax_8_edi_disp8, sib_eax_8_r8d_disp8, sib_eax_8_r9d_disp8, sib_eax_8_r10d_disp8, sib_eax_8_r11d_disp8, sib_eax_8_r12d_disp8, sib_eax_8_r13d_disp8, sib_eax_8_r14d_disp8, sib_eax_8_r15d_disp8,
		sib_ecx_8_eax_disp8, sib_ecx_8_ecx_disp8, sib_ecx_8_edx_disp8, sib_ecx_8_ebx_disp8, sib_ecx_8_esp_disp8, sib_ecx_8_ebp_disp8, sib_ecx_8_esi_disp8, sib_ecx_8_edi_disp8, sib_ecx_8_r8d_disp8, sib_ecx_8_r9d_disp8, sib_ecx_8_r10d_disp8, sib_ecx_8_r11d_disp8, sib_ecx_8_r12d_disp8, sib_ecx_8_r13d_disp8, sib_ecx_8_r14d_disp8, sib_ecx_8_r15d_disp8,
		sib_edx_8_eax_disp8, sib_edx_8_ecx_disp8, sib_edx_8_edx_disp8, sib_edx_8_ebx_disp8, sib_edx_8_esp_disp8, sib_edx_8_ebp_disp8, sib_edx_8_esi_disp8, sib_edx_8_edi_disp8, sib_edx_8_r8d_disp8, sib_edx_8_r9d_disp8, sib_edx_8_r10d_disp8, sib_edx_8_r11d_disp8, sib_edx_8_r12d_disp8, sib_edx_8_r13d_disp8, sib_edx_8_r14d_disp8, sib_edx_8_r15d_disp8,
		sib_ebx_8_eax_disp8, sib_ebx_8_ecx_disp8, sib_ebx_8_edx_disp8, sib_ebx_8_ebx_disp8, sib_ebx_8_esp_disp8, sib_ebx_8_ebp_disp8, sib_ebx_8_esi_disp8, sib_ebx_8_edi_disp8, sib_ebx_8_r8d_disp8, sib_ebx_8_r9d_disp8, sib_ebx_8_r10d_disp8, sib_ebx_8_r11d_disp8, sib_ebx_8_r12d_disp8, sib_ebx_8_r13d_disp8, sib_ebx_8_r14d_disp8, sib_ebx_8_r15d_disp8,
		sib_none_8_eax_disp8, sib_none_8_ecx_disp8, sib_none_8_edx_disp8, sib_none_8_ebx_disp8, sib_none_8_esp_disp8, sib_none_8_ebp_disp8, sib_none_8_esi_disp8, sib_none_8_edi_disp8, sib_none_8_r8d_disp8, sib_none_8_r9d_disp8, sib_none_8_r10d_disp8, sib_none_8_r11d_disp8, sib_none_8_r12d_disp8, sib_none_8_r13d_disp8, sib_none_8_r14d_disp8, sib_none_8_r15d_disp8,
		sib_ebp_8_eax_disp8, sib_ebp_8_ecx_disp8, sib_ebp_8_edx_disp8, sib_ebp_8_ebx_disp8, sib_ebp_8_esp_disp8, sib_ebp_8_ebp_disp8, sib_ebp_8_esi_disp8, sib_ebp_8_edi_disp8, sib_ebp_8_r8d_disp8, sib_ebp_8_r9d_disp8, sib_ebp_8_r10d_disp8, sib_ebp_8_r11d_disp8, sib_ebp_8_r12d_disp8, sib_ebp_8_r13d_disp8, sib_ebp_8_r14d_disp8, sib_ebp_8_r15d_disp8,
		sib_esi_8_eax_disp8, sib_esi_8_ecx_disp8, sib_esi_8_edx_disp8, sib_esi_8_ebx_disp8, sib_esi_8_esp_disp8, sib_esi_8_ebp_disp8, sib_esi_8_esi_disp8, sib_esi_8_edi_disp8, sib_esi_8_r8d_disp8, sib_esi_8_r9d_disp8, sib_esi_8_r10d_disp8, sib_esi_8_r11d_disp8, sib_esi_8_r12d_disp8, sib_esi_8_r13d_disp8, sib_esi_8_r14d_disp8, sib_esi_8_r15d_disp8,
		sib_edi_8_eax_disp8, sib_edi_8_ecx_disp8, sib_edi_8_edx_disp8, sib_edi_8_ebx_disp8, sib_edi_8_esp_disp8, sib_edi_8_ebp_disp8, sib_edi_8_esi_disp8, sib_edi_8_edi_disp8, sib_edi_8_r8d_disp8, sib_edi_8_r9d_disp8, sib_edi_8_r10d_disp8, sib_edi_8_r11d_disp8, sib_edi_8_r12d_disp8, sib_edi_8_r13d_disp8, sib_edi_8_r14d_disp8, sib_edi_8_r15d_disp8,
		sib_r8d_8_eax_disp8, sib_r8d_8_ecx_disp8, sib_r8d_8_edx_disp8, sib_r8d_8_ebx_disp8, sib_r8d_8_esp_disp8, sib_r8d_8_ebp_disp8, sib_r8d_8_esi_disp8, sib_r8d_8_edi_disp8, sib_r8d_8_r8d_disp8, sib_r8d_8_r9d_disp8, sib_r8d_8_r10d_disp8, sib_r8d_8_r11d_disp8, sib_r8d_8_r12d_disp8, sib_r8d_8_r13d_disp8, sib_r8d_8_r14d_disp8, sib_r8d_8_r15d_disp8,
		sib_r9d_8_eax_disp8, sib_r9d_8_ecx_disp8, sib_r9d_8_edx_disp8, sib_r9d_8_ebx_disp8, sib_r9d_8_esp_disp8, sib_r9d_8_ebp_disp8, sib_r9d_8_esi_disp8, sib_r9d_8_edi_disp8, sib_r9d_8_r8d_disp8, sib_r9d_8_r9d_disp8, sib_r9d_8_r10d_disp8, sib_r9d_8_r11d_disp8, sib_r9d_8_r12d_disp8, sib_r9d_8_r13d_disp8, sib_r9d_8_r14d_disp8, sib_r9d_8_r15d_disp8,
		sib_r10d_8_eax_disp8, sib_r10d_8_ecx_disp8, sib_r10d_8_edx_disp8, sib_r10d_8_ebx_disp8, sib_r10d_8_esp_disp8, sib_r10d_8_ebp_disp8, sib_r10d_8_esi_disp8, sib_r10d_8_edi_disp8, sib_r10d_8_r8d_disp8, sib_r10d_8_r9d_disp8, sib_r10d_8_r10d_disp8, sib_r10d_8_r11d_disp8, sib_r10d_8_r12d_disp8, sib_r10d_8_r13d_disp8, sib_r10d_8_r14d_disp8, sib_r10d_8_r15d_disp8,
		sib_r11d_8_eax_disp8, sib_r11d_8_ecx_disp8, sib_r11d_8_edx_disp8, sib_r11d_8_ebx_disp8, sib_r11d_8_esp_disp8, sib_r11d_8_ebp_disp8, sib_r11d_8_esi_disp8, sib_r11d_8_edi_disp8, sib_r11d_8_r8d_disp8, sib_r11d_8_r9d_disp8, sib_r11d_8_r10d_disp8, sib_r11d_8_r11d_disp8, sib_r11d_8_r12d_disp8, sib_r11d_8_r13d_disp8, sib_r11d_8_r14d_disp8, sib_r11d_8_r15d_disp8,
		sib_r12d_8_eax_disp8, sib_r12d_8_ecx_disp8, sib_r12d_8_edx_disp8, sib_r12d_8_ebx_disp8, sib_r12d_8_esp_disp8, sib_r12d_8_ebp_disp8, sib_r12d_8_esi_disp8, sib_r12d_8_edi_disp8, sib_r12d_8_r8d_disp8, sib_r12d_8_r9d_disp8, sib_r12d_8_r10d_disp8, sib_r12d_8_r11d_disp8, sib_r12d_8_r12d_disp8, sib_r12d_8_r13d_disp8, sib_r12d_8_r14d_disp8, sib_r12d_8_r15d_disp8,
		sib_r13d_8_eax_disp8, sib_r13d_8_ecx_disp8, sib_r13d_8_edx_disp8, sib_r13d_8_ebx_disp8, sib_r13d_8_esp_disp8, sib_r13d_8_ebp_disp8, sib_r13d_8_esi_disp8, sib_r13d_8_edi_disp8, sib_r13d_8_r8d_disp8, sib_r13d_8_r9d_disp8, sib_r13d_8_r10d_disp8, sib_r13d_8_r11d_disp8, sib_r13d_8_r12d_disp8, sib_r13d_8_r13d_disp8, sib_r13d_8_r14d_disp8, sib_r13d_8_r15d_disp8,
		sib_r14d_8_eax_disp8, sib_r14d_8_ecx_disp8, sib_r14d_8_edx_disp8, sib_r14d_8_ebx_disp8, sib_r14d_8_esp_disp8, sib_r14d_8_ebp_disp8, sib_r14d_8_esi_disp8, sib_r14d_8_edi_disp8, sib_r14d_8_r8d_disp8, sib_r14d_8_r9d_disp8, sib_r14d_8_r10d_disp8, sib_r14d_8_r11d_disp8, sib_r14d_8_r12d_disp8, sib_r14d_8_r13d_disp8, sib_r14d_8_r14d_disp8, sib_r14d_8_r15d_disp8,
		sib_r15d_8_eax_disp8, sib_r15d_8_ecx_disp8, sib_r15d_8_edx_disp8, sib_r15d_8_ebx_disp8, sib_r15d_8_esp_disp8, sib_r15d_8_ebp_disp8, sib_r15d_8_esi_disp8, sib_r15d_8_edi_disp8, sib_r15d_8_r8d_disp8, sib_r15d_8_r9d_disp8, sib_r15d_8_r10d_disp8, sib_r15d_8_r11d_disp8, sib_r15d_8_r12d_disp8, sib_r15d_8_r13d_disp8, sib_r15d_8_r14d_disp8, sib_r15d_8_r15d_disp8,
		MemSib32Scale8Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib32Disp8End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib32Scale1Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_eax_disp32, sib_eax_ecx_disp32, sib_eax_edx_disp32, sib_eax_ebx_disp32, sib_eax_esp_disp32, sib_eax_ebp_disp32, sib_eax_esi_disp32, sib_eax_edi_disp32, sib_eax_r8d_disp32, sib_eax_r9d_disp32, sib_eax_r10d_disp32, sib_eax_r11d_disp32, sib_eax_r12d_disp32, sib_eax_r13d_disp32, sib_eax_r14d_disp32, sib_eax_r15d_disp32,
		sib_ecx_eax_disp32, sib_ecx_ecx_disp32, sib_ecx_edx_disp32, sib_ecx_ebx_disp32, sib_ecx_esp_disp32, sib_ecx_ebp_disp32, sib_ecx_esi_disp32, sib_ecx_edi_disp32, sib_ecx_r8d_disp32, sib_ecx_r9d_disp32, sib_ecx_r10d_disp32, sib_ecx_r11d_disp32, sib_ecx_r12d_disp32, sib_ecx_r13d_disp32, sib_ecx_r14d_disp32, sib_ecx_r15d_disp32,
		sib_edx_eax_disp32, sib_edx_ecx_disp32, sib_edx_edx_disp32, sib_edx_ebx_disp32, sib_edx_esp_disp32, sib_edx_ebp_disp32, sib_edx_esi_disp32, sib_edx_edi_disp32, sib_edx_r8d_disp32, sib_edx_r9d_disp32, sib_edx_r10d_disp32, sib_edx_r11d_disp32, sib_edx_r12d_disp32, sib_edx_r13d_disp32, sib_edx_r14d_disp32, sib_edx_r15d_disp32,
		sib_ebx_eax_disp32, sib_ebx_ecx_disp32, sib_ebx_edx_disp32, sib_ebx_ebx_disp32, sib_ebx_esp_disp32, sib_ebx_ebp_disp32, sib_ebx_esi_disp32, sib_ebx_edi_disp32, sib_ebx_r8d_disp32, sib_ebx_r9d_disp32, sib_ebx_r10d_disp32, sib_ebx_r11d_disp32, sib_ebx_r12d_disp32, sib_ebx_r13d_disp32, sib_ebx_r14d_disp32, sib_ebx_r15d_disp32,
		sib_none_eax_disp32, sib_none_ecx_disp32, sib_none_edx_disp32, sib_none_ebx_disp32, sib_none_esp_disp32, sib_none_ebp_disp32, sib_none_esi_disp32, sib_none_edi_disp32, sib_none_r8d_disp32, sib_none_r9d_disp32, sib_none_r10d_disp32, sib_none_r11d_disp32, sib_none_r12d_disp32, sib_none_r13d_disp32, sib_none_r14d_disp32, sib_none_r15d_disp32,
		sib_ebp_eax_disp32, sib_ebp_ecx_disp32, sib_ebp_edx_disp32, sib_ebp_ebx_disp32, sib_ebp_esp_disp32, sib_ebp_ebp_disp32, sib_ebp_esi_disp32, sib_ebp_edi_disp32, sib_ebp_r8d_disp32, sib_ebp_r9d_disp32, sib_ebp_r10d_disp32, sib_ebp_r11d_disp32, sib_ebp_r12d_disp32, sib_ebp_r13d_disp32, sib_ebp_r14d_disp32, sib_ebp_r15d_disp32,
		sib_esi_eax_disp32, sib_esi_ecx_disp32, sib_esi_edx_disp32, sib_esi_ebx_disp32, sib_esi_esp_disp32, sib_esi_ebp_disp32, sib_esi_esi_disp32, sib_esi_edi_disp32, sib_esi_r8d_disp32, sib_esi_r9d_disp32, sib_esi_r10d_disp32, sib_esi_r11d_disp32, sib_esi_r12d_disp32, sib_esi_r13d_disp32, sib_esi_r14d_disp32, sib_esi_r15d_disp32,
		sib_edi_eax_disp32, sib_edi_ecx_disp32, sib_edi_edx_disp32, sib_edi_ebx_disp32, sib_edi_esp_disp32, sib_edi_ebp_disp32, sib_edi_esi_disp32, sib_edi_edi_disp32, sib_edi_r8d_disp32, sib_edi_r9d_disp32, sib_edi_r10d_disp32, sib_edi_r11d_disp32, sib_edi_r12d_disp32, sib_edi_r13d_disp32, sib_edi_r14d_disp32, sib_edi_r15d_disp32,
		sib_r8d_eax_disp32, sib_r8d_ecx_disp32, sib_r8d_edx_disp32, sib_r8d_ebx_disp32, sib_r8d_esp_disp32, sib_r8d_ebp_disp32, sib_r8d_esi_disp32, sib_r8d_edi_disp32, sib_r8d_r8d_disp32, sib_r8d_r9d_disp32, sib_r8d_r10d_disp32, sib_r8d_r11d_disp32, sib_r8d_r12d_disp32, sib_r8d_r13d_disp32, sib_r8d_r14d_disp32, sib_r8d_r15d_disp32,
		sib_r9d_eax_disp32, sib_r9d_ecx_disp32, sib_r9d_edx_disp32, sib_r9d_ebx_disp32, sib_r9d_esp_disp32, sib_r9d_ebp_disp32, sib_r9d_esi_disp32, sib_r9d_edi_disp32, sib_r9d_r8d_disp32, sib_r9d_r9d_disp32, sib_r9d_r10d_disp32, sib_r9d_r11d_disp32, sib_r9d_r12d_disp32, sib_r9d_r13d_disp32, sib_r9d_r14d_disp32, sib_r9d_r15d_disp32,
		sib_r10d_eax_disp32, sib_r10d_ecx_disp32, sib_r10d_edx_disp32, sib_r10d_ebx_disp32, sib_r10d_esp_disp32, sib_r10d_ebp_disp32, sib_r10d_esi_disp32, sib_r10d_edi_disp32, sib_r10d_r8d_disp32, sib_r10d_r9d_disp32, sib_r10d_r10d_disp32, sib_r10d_r11d_disp32, sib_r10d_r12d_disp32, sib_r10d_r13d_disp32, sib_r10d_r14d_disp32, sib_r10d_r15d_disp32,
		sib_r11d_eax_disp32, sib_r11d_ecx_disp32, sib_r11d_edx_disp32, sib_r11d_ebx_disp32, sib_r11d_esp_disp32, sib_r11d_ebp_disp32, sib_r11d_esi_disp32, sib_r11d_edi_disp32, sib_r11d_r8d_disp32, sib_r11d_r9d_disp32, sib_r11d_r10d_disp32, sib_r11d_r11d_disp32, sib_r11d_r12d_disp32, sib_r11d_r13d_disp32, sib_r11d_r14d_disp32, sib_r11d_r15d_disp32,
		sib_r12d_eax_disp32, sib_r12d_ecx_disp32, sib_r12d_edx_disp32, sib_r12d_ebx_disp32, sib_r12d_esp_disp32, sib_r12d_ebp_disp32, sib_r12d_esi_disp32, sib_r12d_edi_disp32, sib_r12d_r8d_disp32, sib_r12d_r9d_disp32, sib_r12d_r10d_disp32, sib_r12d_r11d_disp32, sib_r12d_r12d_disp32, sib_r12d_r13d_disp32, sib_r12d_r14d_disp32, sib_r12d_r15d_disp32,
		sib_r13d_eax_disp32, sib_r13d_ecx_disp32, sib_r13d_edx_disp32, sib_r13d_ebx_disp32, sib_r13d_esp_disp32, sib_r13d_ebp_disp32, sib_r13d_esi_disp32, sib_r13d_edi_disp32, sib_r13d_r8d_disp32, sib_r13d_r9d_disp32, sib_r13d_r10d_disp32, sib_r13d_r11d_disp32, sib_r13d_r12d_disp32, sib_r13d_r13d_disp32, sib_r13d_r14d_disp32, sib_r13d_r15d_disp32,
		sib_r14d_eax_disp32, sib_r14d_ecx_disp32, sib_r14d_edx_disp32, sib_r14d_ebx_disp32, sib_r14d_esp_disp32, sib_r14d_ebp_disp32, sib_r14d_esi_disp32, sib_r14d_edi_disp32, sib_r14d_r8d_disp32, sib_r14d_r9d_disp32, sib_r14d_r10d_disp32, sib_r14d_r11d_disp32, sib_r14d_r12d_disp32, sib_r14d_r13d_disp32, sib_r14d_r14d_disp32, sib_r14d_r15d_disp32,
		sib_r15d_eax_disp32, sib_r15d_ecx_disp32, sib_r15d_edx_disp32, sib_r15d_ebx_disp32, sib_r15d_esp_disp32, sib_r15d_ebp_disp32, sib_r15d_esi_disp32, sib_r15d_edi_disp32, sib_r15d_r8d_disp32, sib_r15d_r9d_disp32, sib_r15d_r10d_disp32, sib_r15d_r11d_disp32, sib_r15d_r12d_disp32, sib_r15d_r13d_disp32, sib_r15d_r14d_disp32, sib_r15d_r15d_disp32,
		MemSib32Scale1Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale2Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_2_eax_disp32, sib_eax_2_ecx_disp32, sib_eax_2_edx_disp32, sib_eax_2_ebx_disp32, sib_eax_2_esp_disp32, sib_eax_2_ebp_disp32, sib_eax_2_esi_disp32, sib_eax_2_edi_disp32, sib_eax_2_r8d_disp32, sib_eax_2_r9d_disp32, sib_eax_2_r10d_disp32, sib_eax_2_r11d_disp32, sib_eax_2_r12d_disp32, sib_eax_2_r13d_disp32, sib_eax_2_r14d_disp32, sib_eax_2_r15d_disp32,
		sib_ecx_2_eax_disp32, sib_ecx_2_ecx_disp32, sib_ecx_2_edx_disp32, sib_ecx_2_ebx_disp32, sib_ecx_2_esp_disp32, sib_ecx_2_ebp_disp32, sib_ecx_2_esi_disp32, sib_ecx_2_edi_disp32, sib_ecx_2_r8d_disp32, sib_ecx_2_r9d_disp32, sib_ecx_2_r10d_disp32, sib_ecx_2_r11d_disp32, sib_ecx_2_r12d_disp32, sib_ecx_2_r13d_disp32, sib_ecx_2_r14d_disp32, sib_ecx_2_r15d_disp32,
		sib_edx_2_eax_disp32, sib_edx_2_ecx_disp32, sib_edx_2_edx_disp32, sib_edx_2_ebx_disp32, sib_edx_2_esp_disp32, sib_edx_2_ebp_disp32, sib_edx_2_esi_disp32, sib_edx_2_edi_disp32, sib_edx_2_r8d_disp32, sib_edx_2_r9d_disp32, sib_edx_2_r10d_disp32, sib_edx_2_r11d_disp32, sib_edx_2_r12d_disp32, sib_edx_2_r13d_disp32, sib_edx_2_r14d_disp32, sib_edx_2_r15d_disp32,
		sib_ebx_2_eax_disp32, sib_ebx_2_ecx_disp32, sib_ebx_2_edx_disp32, sib_ebx_2_ebx_disp32, sib_ebx_2_esp_disp32, sib_ebx_2_ebp_disp32, sib_ebx_2_esi_disp32, sib_ebx_2_edi_disp32, sib_ebx_2_r8d_disp32, sib_ebx_2_r9d_disp32, sib_ebx_2_r10d_disp32, sib_ebx_2_r11d_disp32, sib_ebx_2_r12d_disp32, sib_ebx_2_r13d_disp32, sib_ebx_2_r14d_disp32, sib_ebx_2_r15d_disp32,
		sib_none_2_eax_disp32, sib_none_2_ecx_disp32, sib_none_2_edx_disp32, sib_none_2_ebx_disp32, sib_none_2_esp_disp32, sib_none_2_ebp_disp32, sib_none_2_esi_disp32, sib_none_2_edi_disp32, sib_none_2_r8d_disp32, sib_none_2_r9d_disp32, sib_none_2_r10d_disp32, sib_none_2_r11d_disp32, sib_none_2_r12d_disp32, sib_none_2_r13d_disp32, sib_none_2_r14d_disp32, sib_none_2_r15d_disp32,
		sib_ebp_2_eax_disp32, sib_ebp_2_ecx_disp32, sib_ebp_2_edx_disp32, sib_ebp_2_ebx_disp32, sib_ebp_2_esp_disp32, sib_ebp_2_ebp_disp32, sib_ebp_2_esi_disp32, sib_ebp_2_edi_disp32, sib_ebp_2_r8d_disp32, sib_ebp_2_r9d_disp32, sib_ebp_2_r10d_disp32, sib_ebp_2_r11d_disp32, sib_ebp_2_r12d_disp32, sib_ebp_2_r13d_disp32, sib_ebp_2_r14d_disp32, sib_ebp_2_r15d_disp32,
		sib_esi_2_eax_disp32, sib_esi_2_ecx_disp32, sib_esi_2_edx_disp32, sib_esi_2_ebx_disp32, sib_esi_2_esp_disp32, sib_esi_2_ebp_disp32, sib_esi_2_esi_disp32, sib_esi_2_edi_disp32, sib_esi_2_r8d_disp32, sib_esi_2_r9d_disp32, sib_esi_2_r10d_disp32, sib_esi_2_r11d_disp32, sib_esi_2_r12d_disp32, sib_esi_2_r13d_disp32, sib_esi_2_r14d_disp32, sib_esi_2_r15d_disp32,
		sib_edi_2_eax_disp32, sib_edi_2_ecx_disp32, sib_edi_2_edx_disp32, sib_edi_2_ebx_disp32, sib_edi_2_esp_disp32, sib_edi_2_ebp_disp32, sib_edi_2_esi_disp32, sib_edi_2_edi_disp32, sib_edi_2_r8d_disp32, sib_edi_2_r9d_disp32, sib_edi_2_r10d_disp32, sib_edi_2_r11d_disp32, sib_edi_2_r12d_disp32, sib_edi_2_r13d_disp32, sib_edi_2_r14d_disp32, sib_edi_2_r15d_disp32,
		sib_r8d_2_eax_disp32, sib_r8d_2_ecx_disp32, sib_r8d_2_edx_disp32, sib_r8d_2_ebx_disp32, sib_r8d_2_esp_disp32, sib_r8d_2_ebp_disp32, sib_r8d_2_esi_disp32, sib_r8d_2_edi_disp32, sib_r8d_2_r8d_disp32, sib_r8d_2_r9d_disp32, sib_r8d_2_r10d_disp32, sib_r8d_2_r11d_disp32, sib_r8d_2_r12d_disp32, sib_r8d_2_r13d_disp32, sib_r8d_2_r14d_disp32, sib_r8d_2_r15d_disp32,
		sib_r9d_2_eax_disp32, sib_r9d_2_ecx_disp32, sib_r9d_2_edx_disp32, sib_r9d_2_ebx_disp32, sib_r9d_2_esp_disp32, sib_r9d_2_ebp_disp32, sib_r9d_2_esi_disp32, sib_r9d_2_edi_disp32, sib_r9d_2_r8d_disp32, sib_r9d_2_r9d_disp32, sib_r9d_2_r10d_disp32, sib_r9d_2_r11d_disp32, sib_r9d_2_r12d_disp32, sib_r9d_2_r13d_disp32, sib_r9d_2_r14d_disp32, sib_r9d_2_r15d_disp32,
		sib_r10d_2_eax_disp32, sib_r10d_2_ecx_disp32, sib_r10d_2_edx_disp32, sib_r10d_2_ebx_disp32, sib_r10d_2_esp_disp32, sib_r10d_2_ebp_disp32, sib_r10d_2_esi_disp32, sib_r10d_2_edi_disp32, sib_r10d_2_r8d_disp32, sib_r10d_2_r9d_disp32, sib_r10d_2_r10d_disp32, sib_r10d_2_r11d_disp32, sib_r10d_2_r12d_disp32, sib_r10d_2_r13d_disp32, sib_r10d_2_r14d_disp32, sib_r10d_2_r15d_disp32,
		sib_r11d_2_eax_disp32, sib_r11d_2_ecx_disp32, sib_r11d_2_edx_disp32, sib_r11d_2_ebx_disp32, sib_r11d_2_esp_disp32, sib_r11d_2_ebp_disp32, sib_r11d_2_esi_disp32, sib_r11d_2_edi_disp32, sib_r11d_2_r8d_disp32, sib_r11d_2_r9d_disp32, sib_r11d_2_r10d_disp32, sib_r11d_2_r11d_disp32, sib_r11d_2_r12d_disp32, sib_r11d_2_r13d_disp32, sib_r11d_2_r14d_disp32, sib_r11d_2_r15d_disp32,
		sib_r12d_2_eax_disp32, sib_r12d_2_ecx_disp32, sib_r12d_2_edx_disp32, sib_r12d_2_ebx_disp32, sib_r12d_2_esp_disp32, sib_r12d_2_ebp_disp32, sib_r12d_2_esi_disp32, sib_r12d_2_edi_disp32, sib_r12d_2_r8d_disp32, sib_r12d_2_r9d_disp32, sib_r12d_2_r10d_disp32, sib_r12d_2_r11d_disp32, sib_r12d_2_r12d_disp32, sib_r12d_2_r13d_disp32, sib_r12d_2_r14d_disp32, sib_r12d_2_r15d_disp32,
		sib_r13d_2_eax_disp32, sib_r13d_2_ecx_disp32, sib_r13d_2_edx_disp32, sib_r13d_2_ebx_disp32, sib_r13d_2_esp_disp32, sib_r13d_2_ebp_disp32, sib_r13d_2_esi_disp32, sib_r13d_2_edi_disp32, sib_r13d_2_r8d_disp32, sib_r13d_2_r9d_disp32, sib_r13d_2_r10d_disp32, sib_r13d_2_r11d_disp32, sib_r13d_2_r12d_disp32, sib_r13d_2_r13d_disp32, sib_r13d_2_r14d_disp32, sib_r13d_2_r15d_disp32,
		sib_r14d_2_eax_disp32, sib_r14d_2_ecx_disp32, sib_r14d_2_edx_disp32, sib_r14d_2_ebx_disp32, sib_r14d_2_esp_disp32, sib_r14d_2_ebp_disp32, sib_r14d_2_esi_disp32, sib_r14d_2_edi_disp32, sib_r14d_2_r8d_disp32, sib_r14d_2_r9d_disp32, sib_r14d_2_r10d_disp32, sib_r14d_2_r11d_disp32, sib_r14d_2_r12d_disp32, sib_r14d_2_r13d_disp32, sib_r14d_2_r14d_disp32, sib_r14d_2_r15d_disp32,
		sib_r15d_2_eax_disp32, sib_r15d_2_ecx_disp32, sib_r15d_2_edx_disp32, sib_r15d_2_ebx_disp32, sib_r15d_2_esp_disp32, sib_r15d_2_ebp_disp32, sib_r15d_2_esi_disp32, sib_r15d_2_edi_disp32, sib_r15d_2_r8d_disp32, sib_r15d_2_r9d_disp32, sib_r15d_2_r10d_disp32, sib_r15d_2_r11d_disp32, sib_r15d_2_r12d_disp32, sib_r15d_2_r13d_disp32, sib_r15d_2_r14d_disp32, sib_r15d_2_r15d_disp32,
		MemSib32Scale2Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale4Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_4_eax_disp32, sib_eax_4_ecx_disp32, sib_eax_4_edx_disp32, sib_eax_4_ebx_disp32, sib_eax_4_esp_disp32, sib_eax_4_ebp_disp32, sib_eax_4_esi_disp32, sib_eax_4_edi_disp32, sib_eax_4_r8d_disp32, sib_eax_4_r9d_disp32, sib_eax_4_r10d_disp32, sib_eax_4_r11d_disp32, sib_eax_4_r12d_disp32, sib_eax_4_r13d_disp32, sib_eax_4_r14d_disp32, sib_eax_4_r15d_disp32,
		sib_ecx_4_eax_disp32, sib_ecx_4_ecx_disp32, sib_ecx_4_edx_disp32, sib_ecx_4_ebx_disp32, sib_ecx_4_esp_disp32, sib_ecx_4_ebp_disp32, sib_ecx_4_esi_disp32, sib_ecx_4_edi_disp32, sib_ecx_4_r8d_disp32, sib_ecx_4_r9d_disp32, sib_ecx_4_r10d_disp32, sib_ecx_4_r11d_disp32, sib_ecx_4_r12d_disp32, sib_ecx_4_r13d_disp32, sib_ecx_4_r14d_disp32, sib_ecx_4_r15d_disp32,
		sib_edx_4_eax_disp32, sib_edx_4_ecx_disp32, sib_edx_4_edx_disp32, sib_edx_4_ebx_disp32, sib_edx_4_esp_disp32, sib_edx_4_ebp_disp32, sib_edx_4_esi_disp32, sib_edx_4_edi_disp32, sib_edx_4_r8d_disp32, sib_edx_4_r9d_disp32, sib_edx_4_r10d_disp32, sib_edx_4_r11d_disp32, sib_edx_4_r12d_disp32, sib_edx_4_r13d_disp32, sib_edx_4_r14d_disp32, sib_edx_4_r15d_disp32,
		sib_ebx_4_eax_disp32, sib_ebx_4_ecx_disp32, sib_ebx_4_edx_disp32, sib_ebx_4_ebx_disp32, sib_ebx_4_esp_disp32, sib_ebx_4_ebp_disp32, sib_ebx_4_esi_disp32, sib_ebx_4_edi_disp32, sib_ebx_4_r8d_disp32, sib_ebx_4_r9d_disp32, sib_ebx_4_r10d_disp32, sib_ebx_4_r11d_disp32, sib_ebx_4_r12d_disp32, sib_ebx_4_r13d_disp32, sib_ebx_4_r14d_disp32, sib_ebx_4_r15d_disp32,
		sib_none_4_eax_disp32, sib_none_4_ecx_disp32, sib_none_4_edx_disp32, sib_none_4_ebx_disp32, sib_none_4_esp_disp32, sib_none_4_ebp_disp32, sib_none_4_esi_disp32, sib_none_4_edi_disp32, sib_none_4_r8d_disp32, sib_none_4_r9d_disp32, sib_none_4_r10d_disp32, sib_none_4_r11d_disp32, sib_none_4_r12d_disp32, sib_none_4_r13d_disp32, sib_none_4_r14d_disp32, sib_none_4_r15d_disp32,
		sib_ebp_4_eax_disp32, sib_ebp_4_ecx_disp32, sib_ebp_4_edx_disp32, sib_ebp_4_ebx_disp32, sib_ebp_4_esp_disp32, sib_ebp_4_ebp_disp32, sib_ebp_4_esi_disp32, sib_ebp_4_edi_disp32, sib_ebp_4_r8d_disp32, sib_ebp_4_r9d_disp32, sib_ebp_4_r10d_disp32, sib_ebp_4_r11d_disp32, sib_ebp_4_r12d_disp32, sib_ebp_4_r13d_disp32, sib_ebp_4_r14d_disp32, sib_ebp_4_r15d_disp32,
		sib_esi_4_eax_disp32, sib_esi_4_ecx_disp32, sib_esi_4_edx_disp32, sib_esi_4_ebx_disp32, sib_esi_4_esp_disp32, sib_esi_4_ebp_disp32, sib_esi_4_esi_disp32, sib_esi_4_edi_disp32, sib_esi_4_r8d_disp32, sib_esi_4_r9d_disp32, sib_esi_4_r10d_disp32, sib_esi_4_r11d_disp32, sib_esi_4_r12d_disp32, sib_esi_4_r13d_disp32, sib_esi_4_r14d_disp32, sib_esi_4_r15d_disp32,
		sib_edi_4_eax_disp32, sib_edi_4_ecx_disp32, sib_edi_4_edx_disp32, sib_edi_4_ebx_disp32, sib_edi_4_esp_disp32, sib_edi_4_ebp_disp32, sib_edi_4_esi_disp32, sib_edi_4_edi_disp32, sib_edi_4_r8d_disp32, sib_edi_4_r9d_disp32, sib_edi_4_r10d_disp32, sib_edi_4_r11d_disp32, sib_edi_4_r12d_disp32, sib_edi_4_r13d_disp32, sib_edi_4_r14d_disp32, sib_edi_4_r15d_disp32,
		sib_r8d_4_eax_disp32, sib_r8d_4_ecx_disp32, sib_r8d_4_edx_disp32, sib_r8d_4_ebx_disp32, sib_r8d_4_esp_disp32, sib_r8d_4_ebp_disp32, sib_r8d_4_esi_disp32, sib_r8d_4_edi_disp32, sib_r8d_4_r8d_disp32, sib_r8d_4_r9d_disp32, sib_r8d_4_r10d_disp32, sib_r8d_4_r11d_disp32, sib_r8d_4_r12d_disp32, sib_r8d_4_r13d_disp32, sib_r8d_4_r14d_disp32, sib_r8d_4_r15d_disp32,
		sib_r9d_4_eax_disp32, sib_r9d_4_ecx_disp32, sib_r9d_4_edx_disp32, sib_r9d_4_ebx_disp32, sib_r9d_4_esp_disp32, sib_r9d_4_ebp_disp32, sib_r9d_4_esi_disp32, sib_r9d_4_edi_disp32, sib_r9d_4_r8d_disp32, sib_r9d_4_r9d_disp32, sib_r9d_4_r10d_disp32, sib_r9d_4_r11d_disp32, sib_r9d_4_r12d_disp32, sib_r9d_4_r13d_disp32, sib_r9d_4_r14d_disp32, sib_r9d_4_r15d_disp32,
		sib_r10d_4_eax_disp32, sib_r10d_4_ecx_disp32, sib_r10d_4_edx_disp32, sib_r10d_4_ebx_disp32, sib_r10d_4_esp_disp32, sib_r10d_4_ebp_disp32, sib_r10d_4_esi_disp32, sib_r10d_4_edi_disp32, sib_r10d_4_r8d_disp32, sib_r10d_4_r9d_disp32, sib_r10d_4_r10d_disp32, sib_r10d_4_r11d_disp32, sib_r10d_4_r12d_disp32, sib_r10d_4_r13d_disp32, sib_r10d_4_r14d_disp32, sib_r10d_4_r15d_disp32,
		sib_r11d_4_eax_disp32, sib_r11d_4_ecx_disp32, sib_r11d_4_edx_disp32, sib_r11d_4_ebx_disp32, sib_r11d_4_esp_disp32, sib_r11d_4_ebp_disp32, sib_r11d_4_esi_disp32, sib_r11d_4_edi_disp32, sib_r11d_4_r8d_disp32, sib_r11d_4_r9d_disp32, sib_r11d_4_r10d_disp32, sib_r11d_4_r11d_disp32, sib_r11d_4_r12d_disp32, sib_r11d_4_r13d_disp32, sib_r11d_4_r14d_disp32, sib_r11d_4_r15d_disp32,
		sib_r12d_4_eax_disp32, sib_r12d_4_ecx_disp32, sib_r12d_4_edx_disp32, sib_r12d_4_ebx_disp32, sib_r12d_4_esp_disp32, sib_r12d_4_ebp_disp32, sib_r12d_4_esi_disp32, sib_r12d_4_edi_disp32, sib_r12d_4_r8d_disp32, sib_r12d_4_r9d_disp32, sib_r12d_4_r10d_disp32, sib_r12d_4_r11d_disp32, sib_r12d_4_r12d_disp32, sib_r12d_4_r13d_disp32, sib_r12d_4_r14d_disp32, sib_r12d_4_r15d_disp32,
		sib_r13d_4_eax_disp32, sib_r13d_4_ecx_disp32, sib_r13d_4_edx_disp32, sib_r13d_4_ebx_disp32, sib_r13d_4_esp_disp32, sib_r13d_4_ebp_disp32, sib_r13d_4_esi_disp32, sib_r13d_4_edi_disp32, sib_r13d_4_r8d_disp32, sib_r13d_4_r9d_disp32, sib_r13d_4_r10d_disp32, sib_r13d_4_r11d_disp32, sib_r13d_4_r12d_disp32, sib_r13d_4_r13d_disp32, sib_r13d_4_r14d_disp32, sib_r13d_4_r15d_disp32,
		sib_r14d_4_eax_disp32, sib_r14d_4_ecx_disp32, sib_r14d_4_edx_disp32, sib_r14d_4_ebx_disp32, sib_r14d_4_esp_disp32, sib_r14d_4_ebp_disp32, sib_r14d_4_esi_disp32, sib_r14d_4_edi_disp32, sib_r14d_4_r8d_disp32, sib_r14d_4_r9d_disp32, sib_r14d_4_r10d_disp32, sib_r14d_4_r11d_disp32, sib_r14d_4_r12d_disp32, sib_r14d_4_r13d_disp32, sib_r14d_4_r14d_disp32, sib_r14d_4_r15d_disp32,
		sib_r15d_4_eax_disp32, sib_r15d_4_ecx_disp32, sib_r15d_4_edx_disp32, sib_r15d_4_ebx_disp32, sib_r15d_4_esp_disp32, sib_r15d_4_ebp_disp32, sib_r15d_4_esi_disp32, sib_r15d_4_edi_disp32, sib_r15d_4_r8d_disp32, sib_r15d_4_r9d_disp32, sib_r15d_4_r10d_disp32, sib_r15d_4_r11d_disp32, sib_r15d_4_r12d_disp32, sib_r15d_4_r13d_disp32, sib_r15d_4_r14d_disp32, sib_r15d_4_r15d_disp32,
		MemSib32Scale4Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib32Scale8Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_eax_8_eax_disp32, sib_eax_8_ecx_disp32, sib_eax_8_edx_disp32, sib_eax_8_ebx_disp32, sib_eax_8_esp_disp32, sib_eax_8_ebp_disp32, sib_eax_8_esi_disp32, sib_eax_8_edi_disp32, sib_eax_8_r8d_disp32, sib_eax_8_r9d_disp32, sib_eax_8_r10d_disp32, sib_eax_8_r11d_disp32, sib_eax_8_r12d_disp32, sib_eax_8_r13d_disp32, sib_eax_8_r14d_disp32, sib_eax_8_r15d_disp32,
		sib_ecx_8_eax_disp32, sib_ecx_8_ecx_disp32, sib_ecx_8_edx_disp32, sib_ecx_8_ebx_disp32, sib_ecx_8_esp_disp32, sib_ecx_8_ebp_disp32, sib_ecx_8_esi_disp32, sib_ecx_8_edi_disp32, sib_ecx_8_r8d_disp32, sib_ecx_8_r9d_disp32, sib_ecx_8_r10d_disp32, sib_ecx_8_r11d_disp32, sib_ecx_8_r12d_disp32, sib_ecx_8_r13d_disp32, sib_ecx_8_r14d_disp32, sib_ecx_8_r15d_disp32,
		sib_edx_8_eax_disp32, sib_edx_8_ecx_disp32, sib_edx_8_edx_disp32, sib_edx_8_ebx_disp32, sib_edx_8_esp_disp32, sib_edx_8_ebp_disp32, sib_edx_8_esi_disp32, sib_edx_8_edi_disp32, sib_edx_8_r8d_disp32, sib_edx_8_r9d_disp32, sib_edx_8_r10d_disp32, sib_edx_8_r11d_disp32, sib_edx_8_r12d_disp32, sib_edx_8_r13d_disp32, sib_edx_8_r14d_disp32, sib_edx_8_r15d_disp32,
		sib_ebx_8_eax_disp32, sib_ebx_8_ecx_disp32, sib_ebx_8_edx_disp32, sib_ebx_8_ebx_disp32, sib_ebx_8_esp_disp32, sib_ebx_8_ebp_disp32, sib_ebx_8_esi_disp32, sib_ebx_8_edi_disp32, sib_ebx_8_r8d_disp32, sib_ebx_8_r9d_disp32, sib_ebx_8_r10d_disp32, sib_ebx_8_r11d_disp32, sib_ebx_8_r12d_disp32, sib_ebx_8_r13d_disp32, sib_ebx_8_r14d_disp32, sib_ebx_8_r15d_disp32,
		sib_none_8_eax_disp32, sib_none_8_ecx_disp32, sib_none_8_edx_disp32, sib_none_8_ebx_disp32, sib_none_8_esp_disp32, sib_none_8_ebp_disp32, sib_none_8_esi_disp32, sib_none_8_edi_disp32, sib_none_8_r8d_disp32, sib_none_8_r9d_disp32, sib_none_8_r10d_disp32, sib_none_8_r11d_disp32, sib_none_8_r12d_disp32, sib_none_8_r13d_disp32, sib_none_8_r14d_disp32, sib_none_8_r15d_disp32,
		sib_ebp_8_eax_disp32, sib_ebp_8_ecx_disp32, sib_ebp_8_edx_disp32, sib_ebp_8_ebx_disp32, sib_ebp_8_esp_disp32, sib_ebp_8_ebp_disp32, sib_ebp_8_esi_disp32, sib_ebp_8_edi_disp32, sib_ebp_8_r8d_disp32, sib_ebp_8_r9d_disp32, sib_ebp_8_r10d_disp32, sib_ebp_8_r11d_disp32, sib_ebp_8_r12d_disp32, sib_ebp_8_r13d_disp32, sib_ebp_8_r14d_disp32, sib_ebp_8_r15d_disp32,
		sib_esi_8_eax_disp32, sib_esi_8_ecx_disp32, sib_esi_8_edx_disp32, sib_esi_8_ebx_disp32, sib_esi_8_esp_disp32, sib_esi_8_ebp_disp32, sib_esi_8_esi_disp32, sib_esi_8_edi_disp32, sib_esi_8_r8d_disp32, sib_esi_8_r9d_disp32, sib_esi_8_r10d_disp32, sib_esi_8_r11d_disp32, sib_esi_8_r12d_disp32, sib_esi_8_r13d_disp32, sib_esi_8_r14d_disp32, sib_esi_8_r15d_disp32,
		sib_edi_8_eax_disp32, sib_edi_8_ecx_disp32, sib_edi_8_edx_disp32, sib_edi_8_ebx_disp32, sib_edi_8_esp_disp32, sib_edi_8_ebp_disp32, sib_edi_8_esi_disp32, sib_edi_8_edi_disp32, sib_edi_8_r8d_disp32, sib_edi_8_r9d_disp32, sib_edi_8_r10d_disp32, sib_edi_8_r11d_disp32, sib_edi_8_r12d_disp32, sib_edi_8_r13d_disp32, sib_edi_8_r14d_disp32, sib_edi_8_r15d_disp32,
		sib_r8d_8_eax_disp32, sib_r8d_8_ecx_disp32, sib_r8d_8_edx_disp32, sib_r8d_8_ebx_disp32, sib_r8d_8_esp_disp32, sib_r8d_8_ebp_disp32, sib_r8d_8_esi_disp32, sib_r8d_8_edi_disp32, sib_r8d_8_r8d_disp32, sib_r8d_8_r9d_disp32, sib_r8d_8_r10d_disp32, sib_r8d_8_r11d_disp32, sib_r8d_8_r12d_disp32, sib_r8d_8_r13d_disp32, sib_r8d_8_r14d_disp32, sib_r8d_8_r15d_disp32,
		sib_r9d_8_eax_disp32, sib_r9d_8_ecx_disp32, sib_r9d_8_edx_disp32, sib_r9d_8_ebx_disp32, sib_r9d_8_esp_disp32, sib_r9d_8_ebp_disp32, sib_r9d_8_esi_disp32, sib_r9d_8_edi_disp32, sib_r9d_8_r8d_disp32, sib_r9d_8_r9d_disp32, sib_r9d_8_r10d_disp32, sib_r9d_8_r11d_disp32, sib_r9d_8_r12d_disp32, sib_r9d_8_r13d_disp32, sib_r9d_8_r14d_disp32, sib_r9d_8_r15d_disp32,
		sib_r10d_8_eax_disp32, sib_r10d_8_ecx_disp32, sib_r10d_8_edx_disp32, sib_r10d_8_ebx_disp32, sib_r10d_8_esp_disp32, sib_r10d_8_ebp_disp32, sib_r10d_8_esi_disp32, sib_r10d_8_edi_disp32, sib_r10d_8_r8d_disp32, sib_r10d_8_r9d_disp32, sib_r10d_8_r10d_disp32, sib_r10d_8_r11d_disp32, sib_r10d_8_r12d_disp32, sib_r10d_8_r13d_disp32, sib_r10d_8_r14d_disp32, sib_r10d_8_r15d_disp32,
		sib_r11d_8_eax_disp32, sib_r11d_8_ecx_disp32, sib_r11d_8_edx_disp32, sib_r11d_8_ebx_disp32, sib_r11d_8_esp_disp32, sib_r11d_8_ebp_disp32, sib_r11d_8_esi_disp32, sib_r11d_8_edi_disp32, sib_r11d_8_r8d_disp32, sib_r11d_8_r9d_disp32, sib_r11d_8_r10d_disp32, sib_r11d_8_r11d_disp32, sib_r11d_8_r12d_disp32, sib_r11d_8_r13d_disp32, sib_r11d_8_r14d_disp32, sib_r11d_8_r15d_disp32,
		sib_r12d_8_eax_disp32, sib_r12d_8_ecx_disp32, sib_r12d_8_edx_disp32, sib_r12d_8_ebx_disp32, sib_r12d_8_esp_disp32, sib_r12d_8_ebp_disp32, sib_r12d_8_esi_disp32, sib_r12d_8_edi_disp32, sib_r12d_8_r8d_disp32, sib_r12d_8_r9d_disp32, sib_r12d_8_r10d_disp32, sib_r12d_8_r11d_disp32, sib_r12d_8_r12d_disp32, sib_r12d_8_r13d_disp32, sib_r12d_8_r14d_disp32, sib_r12d_8_r15d_disp32,
		sib_r13d_8_eax_disp32, sib_r13d_8_ecx_disp32, sib_r13d_8_edx_disp32, sib_r13d_8_ebx_disp32, sib_r13d_8_esp_disp32, sib_r13d_8_ebp_disp32, sib_r13d_8_esi_disp32, sib_r13d_8_edi_disp32, sib_r13d_8_r8d_disp32, sib_r13d_8_r9d_disp32, sib_r13d_8_r10d_disp32, sib_r13d_8_r11d_disp32, sib_r13d_8_r12d_disp32, sib_r13d_8_r13d_disp32, sib_r13d_8_r14d_disp32, sib_r13d_8_r15d_disp32,
		sib_r14d_8_eax_disp32, sib_r14d_8_ecx_disp32, sib_r14d_8_edx_disp32, sib_r14d_8_ebx_disp32, sib_r14d_8_esp_disp32, sib_r14d_8_ebp_disp32, sib_r14d_8_esi_disp32, sib_r14d_8_edi_disp32, sib_r14d_8_r8d_disp32, sib_r14d_8_r9d_disp32, sib_r14d_8_r10d_disp32, sib_r14d_8_r11d_disp32, sib_r14d_8_r12d_disp32, sib_r14d_8_r13d_disp32, sib_r14d_8_r14d_disp32, sib_r14d_8_r15d_disp32,
		sib_r15d_8_eax_disp32, sib_r15d_8_ecx_disp32, sib_r15d_8_edx_disp32, sib_r15d_8_ebx_disp32, sib_r15d_8_esp_disp32, sib_r15d_8_ebp_disp32, sib_r15d_8_esi_disp32, sib_r15d_8_edi_disp32, sib_r15d_8_r8d_disp32, sib_r15d_8_r9d_disp32, sib_r15d_8_r10d_disp32, sib_r15d_8_r11d_disp32, sib_r15d_8_r12d_disp32, sib_r15d_8_r13d_disp32, sib_r15d_8_r14d_disp32, sib_r15d_8_r15d_disp32,
		MemSib32Scale8Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib32Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib32End,	// Special constant to quickly define the category of a parameter. Do not use. 

		// Long Mode with SIB

		MemSib64Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib64Scale1Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_rax, sib_rax_rcx, sib_rax_rdx, sib_rax_rbx, sib_rax_rsp, sib_rax_disp32 /* disp32 instead rbp */, sib_rax_rsi, sib_rax_rdi, sib_rax_r8, sib_rax_r9, sib_rax_r10, sib_rax_r11, sib_rax_r12, sib_rax_r13, sib_rax_r14, sib_rax_r15, 
		sib_rcx_rax, sib_rcx_rcx, sib_rcx_rdx, sib_rcx_rbx, sib_rcx_rsp, sib_rcx_disp32 /* disp32 instead rbp */, sib_rcx_rsi, sib_rcx_rdi, sib_rcx_r8, sib_rcx_r9, sib_rcx_r10, sib_rcx_r11, sib_rcx_r12, sib_rcx_r13, sib_rcx_r14, sib_rcx_r15, 
		sib_rdx_rax, sib_rdx_rcx, sib_rdx_rdx, sib_rdx_rbx, sib_rdx_rsp, sib_rdx_disp32 /* disp32 instead rbp */, sib_rdx_rsi, sib_rdx_rdi, sib_rdx_r8, sib_rdx_r9, sib_rdx_r10, sib_rdx_r11, sib_rdx_r12, sib_rdx_r13, sib_rdx_r14, sib_rdx_r15, 
		sib_rbx_rax, sib_rbx_rcx, sib_rbx_rdx, sib_rbx_rbx, sib_rbx_rsp, sib_rbx_disp32 /* disp32 instead rbp */, sib_rbx_rsi, sib_rbx_rdi, sib_rbx_r8, sib_rbx_r9, sib_rbx_r10, sib_rbx_r11, sib_rbx_r12, sib_rbx_r13, sib_rbx_r14, sib_rbx_r15, 
		sib_none_rax, sib_none_rcx, sib_none_rdx, sib_none_rbx, sib_none_rsp, sib_none_disp32_64 /* disp32 instead rbp */, sib_none_rsi, sib_none_rdi, sib_none_r8, sib_none_r9, sib_none_r10, sib_none_r11, sib_none_r12, sib_none_r13, sib_none_r14, sib_none_r15, 
		sib_rbp_rax, sib_rbp_rcx, sib_rbp_rdx, sib_rbp_rbx, sib_rbp_rsp, sib_rbp_disp32 /* disp32 instead rbp */, sib_rbp_rsi, sib_rbp_rdi, sib_rbp_r8, sib_rbp_r9, sib_rbp_r10, sib_rbp_r11, sib_rbp_r12, sib_rbp_r13, sib_rbp_r14, sib_rbp_r15, 
		sib_rsi_rax, sib_rsi_rcx, sib_rsi_rdx, sib_rsi_rbx, sib_rsi_rsp, sib_rsi_disp32 /* disp32 instead rbp */, sib_rsi_rsi, sib_rsi_rdi, sib_rsi_r8, sib_rsi_r9, sib_rsi_r10, sib_rsi_r11, sib_rsi_r12, sib_rsi_r13, sib_rsi_r14, sib_rsi_r15, 
		sib_rdi_rax, sib_rdi_rcx, sib_rdi_rdx, sib_rdi_rbx, sib_rdi_rsp, sib_rdi_disp32 /* disp32 instead rbp */, sib_rdi_rsi, sib_rdi_rdi, sib_rdi_r8, sib_rdi_r9, sib_rdi_r10, sib_rdi_r11, sib_rdi_r12, sib_rdi_r13, sib_rdi_r14, sib_rdi_r15, 
		sib_r8_rax, sib_r8_rcx, sib_r8_rdx, sib_r8_rbx, sib_r8_rsp, sib_r8_disp32 /* disp32 instead rbp */, sib_r8_rsi, sib_r8_rdi, sib_r8_r8, sib_r8_r9, sib_r8_r10, sib_r8_r11, sib_r8_r12, sib_r8_r13, sib_r8_r14, sib_r8_r15, 
		sib_r9_rax, sib_r9_rcx, sib_r9_rdx, sib_r9_rbx, sib_r9_rsp, sib_r9_disp32 /* disp32 instead rbp */, sib_r9_rsi, sib_r9_rdi, sib_r9_r8, sib_r9_r9, sib_r9_r10, sib_r9_r11, sib_r9_r12, sib_r9_r13, sib_r9_r14, sib_r9_r15, 
		sib_r10_rax, sib_r10_rcx, sib_r10_rdx, sib_r10_rbx, sib_r10_rsp, sib_r10_disp32 /* disp32 instead rbp */, sib_r10_rsi, sib_r10_rdi, sib_r10_r8, sib_r10_r9, sib_r10_r10, sib_r10_r11, sib_r10_r12, sib_r10_r13, sib_r10_r14, sib_r10_r15, 
		sib_r11_rax, sib_r11_rcx, sib_r11_rdx, sib_r11_rbx, sib_r11_rsp, sib_r11_disp32 /* disp32 instead rbp */, sib_r11_rsi, sib_r11_rdi, sib_r11_r8, sib_r11_r9, sib_r11_r10, sib_r11_r11, sib_r11_r12, sib_r11_r13, sib_r11_r14, sib_r11_r15, 
		sib_r12_rax, sib_r12_rcx, sib_r12_rdx, sib_r12_rbx, sib_r12_rsp, sib_r12_disp32 /* disp32 instead rbp */, sib_r12_rsi, sib_r12_rdi, sib_r12_r8, sib_r12_r9, sib_r12_r10, sib_r12_r11, sib_r12_r12, sib_r12_r13, sib_r12_r14, sib_r12_r15, 
		sib_r13_rax, sib_r13_rcx, sib_r13_rdx, sib_r13_rbx, sib_r13_rsp, sib_r13_disp32 /* disp32 instead rbp */, sib_r13_rsi, sib_r13_rdi, sib_r13_r8, sib_r13_r9, sib_r13_r10, sib_r13_r11, sib_r13_r12, sib_r13_r13, sib_r13_r14, sib_r13_r15, 
		sib_r14_rax, sib_r14_rcx, sib_r14_rdx, sib_r14_rbx, sib_r14_rsp, sib_r14_disp32 /* disp32 instead rbp */, sib_r14_rsi, sib_r14_rdi, sib_r14_r8, sib_r14_r9, sib_r14_r10, sib_r14_r11, sib_r14_r12, sib_r14_r13, sib_r14_r14, sib_r14_r15, 
		sib_r15_rax, sib_r15_rcx, sib_r15_rdx, sib_r15_rbx, sib_r15_rsp, sib_r15_disp32 /* disp32 instead rbp */, sib_r15_rsi, sib_r15_rdi, sib_r15_r8, sib_r15_r9, sib_r15_r10, sib_r15_r11, sib_r15_r12, sib_r15_r13, sib_r15_r14, sib_r15_r15, 
		MemSib64Scale1End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale2Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_2_rax, sib_rax_2_rcx, sib_rax_2_rdx, sib_rax_2_rbx, sib_rax_2_rsp, sib_rax_2_disp32 /* disp32 instead rbp */, sib_rax_2_rsi, sib_rax_2_rdi, sib_rax_2_r8, sib_rax_2_r9, sib_rax_2_r10, sib_rax_2_r11, sib_rax_2_r12, sib_rax_2_r13, sib_rax_2_r14, sib_rax_2_r15,
		sib_rcx_2_rax, sib_rcx_2_rcx, sib_rcx_2_rdx, sib_rcx_2_rbx, sib_rcx_2_rsp, sib_rcx_2_disp32 /* disp32 instead rbp */, sib_rcx_2_rsi, sib_rcx_2_rdi, sib_rcx_2_r8, sib_rcx_2_r9, sib_rcx_2_r10, sib_rcx_2_r11, sib_rcx_2_r12, sib_rcx_2_r13, sib_rcx_2_r14, sib_rcx_2_r15,
		sib_rdx_2_rax, sib_rdx_2_rcx, sib_rdx_2_rdx, sib_rdx_2_rbx, sib_rdx_2_rsp, sib_rdx_2_disp32 /* disp32 instead rbp */, sib_rdx_2_rsi, sib_rdx_2_rdi, sib_rdx_2_r8, sib_rdx_2_r9, sib_rdx_2_r10, sib_rdx_2_r11, sib_rdx_2_r12, sib_rdx_2_r13, sib_rdx_2_r14, sib_rdx_2_r15,
		sib_rbx_2_rax, sib_rbx_2_rcx, sib_rbx_2_rdx, sib_rbx_2_rbx, sib_rbx_2_rsp, sib_rbx_2_disp32 /* disp32 instead rbp */, sib_rbx_2_rsi, sib_rbx_2_rdi, sib_rbx_2_r8, sib_rbx_2_r9, sib_rbx_2_r10, sib_rbx_2_r11, sib_rbx_2_r12, sib_rbx_2_r13, sib_rbx_2_r14, sib_rbx_2_r15,
		sib_none_2_rax, sib_none_2_rcx, sib_none_2_rdx, sib_none_2_rbx, sib_none_2_rsp, sib_none_2_disp32_64 /* disp32 instead rbp */, sib_none_2_rsi, sib_none_2_rdi, sib_none_2_r8, sib_none_2_r9, sib_none_2_r10, sib_none_2_r11, sib_none_2_r12, sib_none_2_r13, sib_none_2_r14, sib_none_2_r15,
		sib_rbp_2_rax, sib_rbp_2_rcx, sib_rbp_2_rdx, sib_rbp_2_rbx, sib_rbp_2_rsp, sib_rbp_2_disp32 /* disp32 instead rbp */, sib_rbp_2_rsi, sib_rbp_2_rdi, sib_rbp_2_r8, sib_rbp_2_r9, sib_rbp_2_r10, sib_rbp_2_r11, sib_rbp_2_r12, sib_rbp_2_r13, sib_rbp_2_r14, sib_rbp_2_r15,
		sib_rsi_2_rax, sib_rsi_2_rcx, sib_rsi_2_rdx, sib_rsi_2_rbx, sib_rsi_2_rsp, sib_rsi_2_disp32 /* disp32 instead rbp */, sib_rsi_2_rsi, sib_rsi_2_rdi, sib_rsi_2_r8, sib_rsi_2_r9, sib_rsi_2_r10, sib_rsi_2_r11, sib_rsi_2_r12, sib_rsi_2_r13, sib_rsi_2_r14, sib_rsi_2_r15,
		sib_rdi_2_rax, sib_rdi_2_rcx, sib_rdi_2_rdx, sib_rdi_2_rbx, sib_rdi_2_rsp, sib_rdi_2_disp32 /* disp32 instead rbp */, sib_rdi_2_rsi, sib_rdi_2_rdi, sib_rdi_2_r8, sib_rdi_2_r9, sib_rdi_2_r10, sib_rdi_2_r11, sib_rdi_2_r12, sib_rdi_2_r13, sib_rdi_2_r14, sib_rdi_2_r15,
		sib_r8_2_rax, sib_r8_2_rcx, sib_r8_2_rdx, sib_r8_2_rbx, sib_r8_2_rsp, sib_r8_2_disp32 /* disp32 instead rbp */,		  sib_r8_2_rsi,  sib_r8_2_rdi,  sib_r8_2_r8,  sib_r8_2_r9,  sib_r8_2_r10,  sib_r8_2_r11,  sib_r8_2_r12,  sib_r8_2_r13,  sib_r8_2_r14,  sib_r8_2_r15,
		sib_r9_2_rax, sib_r9_2_rcx, sib_r9_2_rdx, sib_r9_2_rbx, sib_r9_2_rsp, sib_r9_2_disp32 /* disp32 instead rbp */,		  sib_r9_2_rsi,  sib_r9_2_rdi,  sib_r9_2_r8,  sib_r9_2_r9,  sib_r9_2_r10,  sib_r9_2_r11,  sib_r9_2_r12,  sib_r9_2_r13,  sib_r9_2_r14,  sib_r9_2_r15,
		sib_r10_2_rax, sib_r10_2_rcx, sib_r10_2_rdx, sib_r10_2_rbx, sib_r10_2_rsp, sib_r10_2_disp32 /* disp32 instead rbp */, sib_r10_2_rsi, sib_r10_2_rdi, sib_r10_2_r8, sib_r10_2_r9, sib_r10_2_r10, sib_r10_2_r11, sib_r10_2_r12, sib_r10_2_r13, sib_r10_2_r14, sib_r10_2_r15,
		sib_r11_2_rax, sib_r11_2_rcx, sib_r11_2_rdx, sib_r11_2_rbx, sib_r11_2_rsp, sib_r11_2_disp32 /* disp32 instead rbp */, sib_r11_2_rsi, sib_r11_2_rdi, sib_r11_2_r8, sib_r11_2_r9, sib_r11_2_r10, sib_r11_2_r11, sib_r11_2_r12, sib_r11_2_r13, sib_r11_2_r14, sib_r11_2_r15,
		sib_r12_2_rax, sib_r12_2_rcx, sib_r12_2_rdx, sib_r12_2_rbx, sib_r12_2_rsp, sib_r12_2_disp32 /* disp32 instead rbp */, sib_r12_2_rsi, sib_r12_2_rdi, sib_r12_2_r8, sib_r12_2_r9, sib_r12_2_r10, sib_r12_2_r11, sib_r12_2_r12, sib_r12_2_r13, sib_r12_2_r14, sib_r12_2_r15,
		sib_r13_2_rax, sib_r13_2_rcx, sib_r13_2_rdx, sib_r13_2_rbx, sib_r13_2_rsp, sib_r13_2_disp32 /* disp32 instead rbp */, sib_r13_2_rsi, sib_r13_2_rdi, sib_r13_2_r8, sib_r13_2_r9, sib_r13_2_r10, sib_r13_2_r11, sib_r13_2_r12, sib_r13_2_r13, sib_r13_2_r14, sib_r13_2_r15,
		sib_r14_2_rax, sib_r14_2_rcx, sib_r14_2_rdx, sib_r14_2_rbx, sib_r14_2_rsp, sib_r14_2_disp32 /* disp32 instead rbp */, sib_r14_2_rsi, sib_r14_2_rdi, sib_r14_2_r8, sib_r14_2_r9, sib_r14_2_r10, sib_r14_2_r11, sib_r14_2_r12, sib_r14_2_r13, sib_r14_2_r14, sib_r14_2_r15,
		sib_r15_2_rax, sib_r15_2_rcx, sib_r15_2_rdx, sib_r15_2_rbx, sib_r15_2_rsp, sib_r15_2_disp32 /* disp32 instead rbp */, sib_r15_2_rsi, sib_r15_2_rdi, sib_r15_2_r8, sib_r15_2_r9, sib_r15_2_r10, sib_r15_2_r11, sib_r15_2_r12, sib_r15_2_r13, sib_r15_2_r14, sib_r15_2_r15,
		MemSib64Scale2End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale4Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_4_rax, sib_rax_4_rcx, sib_rax_4_rdx, sib_rax_4_rbx, sib_rax_4_rsp, sib_rax_4_disp32 /* disp32 instead rbp */, sib_rax_4_rsi, sib_rax_4_rdi, sib_rax_4_r8, sib_rax_4_r9, sib_rax_4_r10, sib_rax_4_r11, sib_rax_4_r12, sib_rax_4_r13, sib_rax_4_r14, sib_rax_4_r15,
		sib_rcx_4_rax, sib_rcx_4_rcx, sib_rcx_4_rdx, sib_rcx_4_rbx, sib_rcx_4_rsp, sib_rcx_4_disp32 /* disp32 instead rbp */, sib_rcx_4_rsi, sib_rcx_4_rdi, sib_rcx_4_r8, sib_rcx_4_r9, sib_rcx_4_r10, sib_rcx_4_r11, sib_rcx_4_r12, sib_rcx_4_r13, sib_rcx_4_r14, sib_rcx_4_r15,
		sib_rdx_4_rax, sib_rdx_4_rcx, sib_rdx_4_rdx, sib_rdx_4_rbx, sib_rdx_4_rsp, sib_rdx_4_disp32 /* disp32 instead rbp */, sib_rdx_4_rsi, sib_rdx_4_rdi, sib_rdx_4_r8, sib_rdx_4_r9, sib_rdx_4_r10, sib_rdx_4_r11, sib_rdx_4_r12, sib_rdx_4_r13, sib_rdx_4_r14, sib_rdx_4_r15,
		sib_rbx_4_rax, sib_rbx_4_rcx, sib_rbx_4_rdx, sib_rbx_4_rbx, sib_rbx_4_rsp, sib_rbx_4_disp32 /* disp32 instead rbp */, sib_rbx_4_rsi, sib_rbx_4_rdi, sib_rbx_4_r8, sib_rbx_4_r9, sib_rbx_4_r10, sib_rbx_4_r11, sib_rbx_4_r12, sib_rbx_4_r13, sib_rbx_4_r14, sib_rbx_4_r15,
		sib_none_4_rax, sib_none_4_rcx, sib_none_4_rdx, sib_none_4_rbx, sib_none_4_rsp, sib_none_4_disp32_64 /* disp32 instead rbp */, sib_none_4_rsi, sib_none_4_rdi, sib_none_4_r8, sib_none_4_r9, sib_none_4_r10, sib_none_4_r11, sib_none_4_r12, sib_none_4_r13, sib_none_4_r14, sib_none_4_r15,
		sib_rbp_4_rax, sib_rbp_4_rcx, sib_rbp_4_rdx, sib_rbp_4_rbx, sib_rbp_4_rsp, sib_rbp_4_disp32 /* disp32 instead rbp */, sib_rbp_4_rsi, sib_rbp_4_rdi, sib_rbp_4_r8, sib_rbp_4_r9, sib_rbp_4_r10, sib_rbp_4_r11, sib_rbp_4_r12, sib_rbp_4_r13, sib_rbp_4_r14, sib_rbp_4_r15,
		sib_rsi_4_rax, sib_rsi_4_rcx, sib_rsi_4_rdx, sib_rsi_4_rbx, sib_rsi_4_rsp, sib_rsi_4_disp32 /* disp32 instead rbp */, sib_rsi_4_rsi, sib_rsi_4_rdi, sib_rsi_4_r8, sib_rsi_4_r9, sib_rsi_4_r10, sib_rsi_4_r11, sib_rsi_4_r12, sib_rsi_4_r13, sib_rsi_4_r14, sib_rsi_4_r15,
		sib_rdi_4_rax, sib_rdi_4_rcx, sib_rdi_4_rdx, sib_rdi_4_rbx, sib_rdi_4_rsp, sib_rdi_4_disp32 /* disp32 instead rbp */, sib_rdi_4_rsi, sib_rdi_4_rdi, sib_rdi_4_r8, sib_rdi_4_r9, sib_rdi_4_r10, sib_rdi_4_r11, sib_rdi_4_r12, sib_rdi_4_r13, sib_rdi_4_r14, sib_rdi_4_r15,
		sib_r8_4_rax, sib_r8_4_rcx, sib_r8_4_rdx, sib_r8_4_rbx, sib_r8_4_rsp, sib_r8_4_disp32 /* disp32 instead rbp */,		  sib_r8_4_rsi,  sib_r8_4_rdi,  sib_r8_4_r8,  sib_r8_4_r9,  sib_r8_4_r10,  sib_r8_4_r11,  sib_r8_4_r12,  sib_r8_4_r13,  sib_r8_4_r14,  sib_r8_4_r15,
		sib_r9_4_rax, sib_r9_4_rcx, sib_r9_4_rdx, sib_r9_4_rbx, sib_r9_4_rsp, sib_r9_4_disp32 /* disp32 instead rbp */,		  sib_r9_4_rsi,  sib_r9_4_rdi,  sib_r9_4_r8,  sib_r9_4_r9,  sib_r9_4_r10,  sib_r9_4_r11,  sib_r9_4_r12,  sib_r9_4_r13,  sib_r9_4_r14,  sib_r9_4_r15,
		sib_r10_4_rax, sib_r10_4_rcx, sib_r10_4_rdx, sib_r10_4_rbx, sib_r10_4_rsp, sib_r10_4_disp32 /* disp32 instead rbp */, sib_r10_4_rsi, sib_r10_4_rdi, sib_r10_4_r8, sib_r10_4_r9, sib_r10_4_r10, sib_r10_4_r11, sib_r10_4_r12, sib_r10_4_r13, sib_r10_4_r14, sib_r10_4_r15,
		sib_r11_4_rax, sib_r11_4_rcx, sib_r11_4_rdx, sib_r11_4_rbx, sib_r11_4_rsp, sib_r11_4_disp32 /* disp32 instead rbp */, sib_r11_4_rsi, sib_r11_4_rdi, sib_r11_4_r8, sib_r11_4_r9, sib_r11_4_r10, sib_r11_4_r11, sib_r11_4_r12, sib_r11_4_r13, sib_r11_4_r14, sib_r11_4_r15,
		sib_r12_4_rax, sib_r12_4_rcx, sib_r12_4_rdx, sib_r12_4_rbx, sib_r12_4_rsp, sib_r12_4_disp32 /* disp32 instead rbp */, sib_r12_4_rsi, sib_r12_4_rdi, sib_r12_4_r8, sib_r12_4_r9, sib_r12_4_r10, sib_r12_4_r11, sib_r12_4_r12, sib_r12_4_r13, sib_r12_4_r14, sib_r12_4_r15,
		sib_r13_4_rax, sib_r13_4_rcx, sib_r13_4_rdx, sib_r13_4_rbx, sib_r13_4_rsp, sib_r13_4_disp32 /* disp32 instead rbp */, sib_r13_4_rsi, sib_r13_4_rdi, sib_r13_4_r8, sib_r13_4_r9, sib_r13_4_r10, sib_r13_4_r11, sib_r13_4_r12, sib_r13_4_r13, sib_r13_4_r14, sib_r13_4_r15,
		sib_r14_4_rax, sib_r14_4_rcx, sib_r14_4_rdx, sib_r14_4_rbx, sib_r14_4_rsp, sib_r14_4_disp32 /* disp32 instead rbp */, sib_r14_4_rsi, sib_r14_4_rdi, sib_r14_4_r8, sib_r14_4_r9, sib_r14_4_r10, sib_r14_4_r11, sib_r14_4_r12, sib_r14_4_r13, sib_r14_4_r14, sib_r14_4_r15,
		sib_r15_4_rax, sib_r15_4_rcx, sib_r15_4_rdx, sib_r15_4_rbx, sib_r15_4_rsp, sib_r15_4_disp32 /* disp32 instead rbp */, sib_r15_4_rsi, sib_r15_4_rdi, sib_r15_4_r8, sib_r15_4_r9, sib_r15_4_r10, sib_r15_4_r11, sib_r15_4_r12, sib_r15_4_r13, sib_r15_4_r14, sib_r15_4_r15,
		MemSib64Scale4End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_8_rax, sib_rax_8_rcx, sib_rax_8_rdx, sib_rax_8_rbx, sib_rax_8_rsp, sib_rax_8_disp32 /* disp32 instead rbp */, sib_rax_8_rsi, sib_rax_8_rdi, sib_rax_8_r8, sib_rax_8_r9, sib_rax_8_r10, sib_rax_8_r11, sib_rax_8_r12, sib_rax_8_r13, sib_rax_8_r14, sib_rax_8_r15,
		sib_rcx_8_rax, sib_rcx_8_rcx, sib_rcx_8_rdx, sib_rcx_8_rbx, sib_rcx_8_rsp, sib_rcx_8_disp32 /* disp32 instead rbp */, sib_rcx_8_rsi, sib_rcx_8_rdi, sib_rcx_8_r8, sib_rcx_8_r9, sib_rcx_8_r10, sib_rcx_8_r11, sib_rcx_8_r12, sib_rcx_8_r13, sib_rcx_8_r14, sib_rcx_8_r15,
		sib_rdx_8_rax, sib_rdx_8_rcx, sib_rdx_8_rdx, sib_rdx_8_rbx, sib_rdx_8_rsp, sib_rdx_8_disp32 /* disp32 instead rbp */, sib_rdx_8_rsi, sib_rdx_8_rdi, sib_rdx_8_r8, sib_rdx_8_r9, sib_rdx_8_r10, sib_rdx_8_r11, sib_rdx_8_r12, sib_rdx_8_r13, sib_rdx_8_r14, sib_rdx_8_r15,
		sib_rbx_8_rax, sib_rbx_8_rcx, sib_rbx_8_rdx, sib_rbx_8_rbx, sib_rbx_8_rsp, sib_rbx_8_disp32 /* disp32 instead rbp */, sib_rbx_8_rsi, sib_rbx_8_rdi, sib_rbx_8_r8, sib_rbx_8_r9, sib_rbx_8_r10, sib_rbx_8_r11, sib_rbx_8_r12, sib_rbx_8_r13, sib_rbx_8_r14, sib_rbx_8_r15,
		sib_none_8_rax, sib_none_8_rcx, sib_none_8_rdx, sib_none_8_rbx, sib_none_8_rsp, sib_none_8_disp32_64 /* disp32 instead rbp */, sib_none_8_rsi, sib_none_8_rdi, sib_none_8_r8, sib_none_8_r9, sib_none_8_r10, sib_none_8_r11, sib_none_8_r12, sib_none_8_r13, sib_none_8_r14, sib_none_8_r15,
		sib_rbp_8_rax, sib_rbp_8_rcx, sib_rbp_8_rdx, sib_rbp_8_rbx, sib_rbp_8_rsp, sib_rbp_8_disp32 /* disp32 instead rbp */, sib_rbp_8_rsi, sib_rbp_8_rdi, sib_rbp_8_r8, sib_rbp_8_r9, sib_rbp_8_r10, sib_rbp_8_r11, sib_rbp_8_r12, sib_rbp_8_r13, sib_rbp_8_r14, sib_rbp_8_r15,
		sib_rsi_8_rax, sib_rsi_8_rcx, sib_rsi_8_rdx, sib_rsi_8_rbx, sib_rsi_8_rsp, sib_rsi_8_disp32 /* disp32 instead rbp */, sib_rsi_8_rsi, sib_rsi_8_rdi, sib_rsi_8_r8, sib_rsi_8_r9, sib_rsi_8_r10, sib_rsi_8_r11, sib_rsi_8_r12, sib_rsi_8_r13, sib_rsi_8_r14, sib_rsi_8_r15,
		sib_rdi_8_rax, sib_rdi_8_rcx, sib_rdi_8_rdx, sib_rdi_8_rbx, sib_rdi_8_rsp, sib_rdi_8_disp32 /* disp32 instead rbp */, sib_rdi_8_rsi, sib_rdi_8_rdi, sib_rdi_8_r8, sib_rdi_8_r9, sib_rdi_8_r10, sib_rdi_8_r11, sib_rdi_8_r12, sib_rdi_8_r13, sib_rdi_8_r14, sib_rdi_8_r15,
		sib_r8_8_rax, sib_r8_8_rcx, sib_r8_8_rdx, sib_r8_8_rbx, sib_r8_8_rsp, sib_r8_8_disp32 /* disp32 instead rbp */,		  sib_r8_8_rsi,  sib_r8_8_rdi,  sib_r8_8_r8,  sib_r8_8_r9,  sib_r8_8_r10,  sib_r8_8_r11,  sib_r8_8_r12,  sib_r8_8_r13,  sib_r8_8_r14,  sib_r8_8_r15,
		sib_r9_8_rax, sib_r9_8_rcx, sib_r9_8_rdx, sib_r9_8_rbx, sib_r9_8_rsp, sib_r9_8_disp32 /* disp32 instead rbp */,		  sib_r9_8_rsi,  sib_r9_8_rdi,  sib_r9_8_r8,  sib_r9_8_r9,  sib_r9_8_r10,  sib_r9_8_r11,  sib_r9_8_r12,  sib_r9_8_r13,  sib_r9_8_r14,  sib_r9_8_r15,
		sib_r10_8_rax, sib_r10_8_rcx, sib_r10_8_rdx, sib_r10_8_rbx, sib_r10_8_rsp, sib_r10_8_disp32 /* disp32 instead rbp */, sib_r10_8_rsi, sib_r10_8_rdi, sib_r10_8_r8, sib_r10_8_r9, sib_r10_8_r10, sib_r10_8_r11, sib_r10_8_r12, sib_r10_8_r13, sib_r10_8_r14, sib_r10_8_r15,
		sib_r11_8_rax, sib_r11_8_rcx, sib_r11_8_rdx, sib_r11_8_rbx, sib_r11_8_rsp, sib_r11_8_disp32 /* disp32 instead rbp */, sib_r11_8_rsi, sib_r11_8_rdi, sib_r11_8_r8, sib_r11_8_r9, sib_r11_8_r10, sib_r11_8_r11, sib_r11_8_r12, sib_r11_8_r13, sib_r11_8_r14, sib_r11_8_r15,
		sib_r12_8_rax, sib_r12_8_rcx, sib_r12_8_rdx, sib_r12_8_rbx, sib_r12_8_rsp, sib_r12_8_disp32 /* disp32 instead rbp */, sib_r12_8_rsi, sib_r12_8_rdi, sib_r12_8_r8, sib_r12_8_r9, sib_r12_8_r10, sib_r12_8_r11, sib_r12_8_r12, sib_r12_8_r13, sib_r12_8_r14, sib_r12_8_r15,
		sib_r13_8_rax, sib_r13_8_rcx, sib_r13_8_rdx, sib_r13_8_rbx, sib_r13_8_rsp, sib_r13_8_disp32 /* disp32 instead rbp */, sib_r13_8_rsi, sib_r13_8_rdi, sib_r13_8_r8, sib_r13_8_r9, sib_r13_8_r10, sib_r13_8_r11, sib_r13_8_r12, sib_r13_8_r13, sib_r13_8_r14, sib_r13_8_r15,
		sib_r14_8_rax, sib_r14_8_rcx, sib_r14_8_rdx, sib_r14_8_rbx, sib_r14_8_rsp, sib_r14_8_disp32 /* disp32 instead rbp */, sib_r14_8_rsi, sib_r14_8_rdi, sib_r14_8_r8, sib_r14_8_r9, sib_r14_8_r10, sib_r14_8_r11, sib_r14_8_r12, sib_r14_8_r13, sib_r14_8_r14, sib_r14_8_r15,
		sib_r15_8_rax, sib_r15_8_rcx, sib_r15_8_rdx, sib_r15_8_rbx, sib_r15_8_rsp, sib_r15_8_disp32 /* disp32 instead rbp */, sib_r15_8_rsi, sib_r15_8_rdi, sib_r15_8_r8, sib_r15_8_r9, sib_r15_8_r10, sib_r15_8_r11, sib_r15_8_r12, sib_r15_8_r13, sib_r15_8_r14, sib_r15_8_r15,
		MemSib64Scale8End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Disp8Start,		// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib64Scale1Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_rax_disp8, sib_rax_rcx_disp8, sib_rax_rdx_disp8, sib_rax_rbx_disp8, sib_rax_rsp_disp8, sib_rax_rbp_disp8, sib_rax_rsi_disp8, sib_rax_rdi_disp8, sib_rax_r8_disp8, sib_rax_r9_disp8, sib_rax_r10_disp8, sib_rax_r11_disp8, sib_rax_r12_disp8, sib_rax_r13_disp8, sib_rax_r14_disp8, sib_rax_r15_disp8, 
		sib_rcx_rax_disp8, sib_rcx_rcx_disp8, sib_rcx_rdx_disp8, sib_rcx_rbx_disp8, sib_rcx_rsp_disp8, sib_rcx_rbp_disp8, sib_rcx_rsi_disp8, sib_rcx_rdi_disp8, sib_rcx_r8_disp8, sib_rcx_r9_disp8, sib_rcx_r10_disp8, sib_rcx_r11_disp8, sib_rcx_r12_disp8, sib_rcx_r13_disp8, sib_rcx_r14_disp8, sib_rcx_r15_disp8, 
		sib_rdx_rax_disp8, sib_rdx_rcx_disp8, sib_rdx_rdx_disp8, sib_rdx_rbx_disp8, sib_rdx_rsp_disp8, sib_rdx_rbp_disp8, sib_rdx_rsi_disp8, sib_rdx_rdi_disp8, sib_rdx_r8_disp8, sib_rdx_r9_disp8, sib_rdx_r10_disp8, sib_rdx_r11_disp8, sib_rdx_r12_disp8, sib_rdx_r13_disp8, sib_rdx_r14_disp8, sib_rdx_r15_disp8, 
		sib_rbx_rax_disp8, sib_rbx_rcx_disp8, sib_rbx_rdx_disp8, sib_rbx_rbx_disp8, sib_rbx_rsp_disp8, sib_rbx_rbp_disp8, sib_rbx_rsi_disp8, sib_rbx_rdi_disp8, sib_rbx_r8_disp8, sib_rbx_r9_disp8, sib_rbx_r10_disp8, sib_rbx_r11_disp8, sib_rbx_r12_disp8, sib_rbx_r13_disp8, sib_rbx_r14_disp8, sib_rbx_r15_disp8, 
		sib_none_rax_disp8, sib_none_rcx_disp8, sib_none_rdx_disp8, sib_none_rbx_disp8, sib_none_rsp_disp8, sib_none_rbp_disp8, sib_none_rsi_disp8, sib_none_rdi_disp8, sib_none_r8_disp8, sib_none_r9_disp8, sib_none_r10_disp8, sib_none_r11_disp8, sib_none_r12_disp8, sib_none_r13_disp8, sib_none_r14_disp8, sib_none_r15_disp8,
		sib_rbp_rax_disp8, sib_rbp_rcx_disp8, sib_rbp_rdx_disp8, sib_rbp_rbx_disp8, sib_rbp_rsp_disp8, sib_rbp_rbp_disp8, sib_rbp_rsi_disp8, sib_rbp_rdi_disp8, sib_rbp_r8_disp8, sib_rbp_r9_disp8, sib_rbp_r10_disp8, sib_rbp_r11_disp8, sib_rbp_r12_disp8, sib_rbp_r13_disp8, sib_rbp_r14_disp8, sib_rbp_r15_disp8, 
		sib_rsi_rax_disp8, sib_rsi_rcx_disp8, sib_rsi_rdx_disp8, sib_rsi_rbx_disp8, sib_rsi_rsp_disp8, sib_rsi_rbp_disp8, sib_rsi_rsi_disp8, sib_rsi_rdi_disp8, sib_rsi_r8_disp8, sib_rsi_r9_disp8, sib_rsi_r10_disp8, sib_rsi_r11_disp8, sib_rsi_r12_disp8, sib_rsi_r13_disp8, sib_rsi_r14_disp8, sib_rsi_r15_disp8, 
		sib_rdi_rax_disp8, sib_rdi_rcx_disp8, sib_rdi_rdx_disp8, sib_rdi_rbx_disp8, sib_rdi_rsp_disp8, sib_rdi_rbp_disp8, sib_rdi_rsi_disp8, sib_rdi_rdi_disp8, sib_rdi_r8_disp8, sib_rdi_r9_disp8, sib_rdi_r10_disp8, sib_rdi_r11_disp8, sib_rdi_r12_disp8, sib_rdi_r13_disp8, sib_rdi_r14_disp8, sib_rdi_r15_disp8, 
		sib_r8_rax_disp8, sib_r8_rcx_disp8, sib_r8_rdx_disp8, sib_r8_rbx_disp8, sib_r8_rsp_disp8, sib_r8_rbp_disp8, sib_r8_rsi_disp8, sib_r8_rdi_disp8, sib_r8_r8_disp8, sib_r8_r9_disp8, sib_r8_r10_disp8, sib_r8_r11_disp8, sib_r8_r12_disp8, sib_r8_r13_disp8, sib_r8_r14_disp8, sib_r8_r15_disp8, 
		sib_r9_rax_disp8, sib_r9_rcx_disp8, sib_r9_rdx_disp8, sib_r9_rbx_disp8, sib_r9_rsp_disp8, sib_r9_rbp_disp8, sib_r9_rsi_disp8, sib_r9_rdi_disp8, sib_r9_r8_disp8, sib_r9_r9_disp8, sib_r9_r10_disp8, sib_r9_r11_disp8, sib_r9_r12_disp8, sib_r9_r13_disp8, sib_r9_r14_disp8, sib_r9_r15_disp8, 
		sib_r10_rax_disp8, sib_r10_rcx_disp8, sib_r10_rdx_disp8, sib_r10_rbx_disp8, sib_r10_rsp_disp8, sib_r10_rbp_disp8, sib_r10_rsi_disp8, sib_r10_rdi_disp8, sib_r10_r8_disp8, sib_r10_r9_disp8, sib_r10_r10_disp8, sib_r10_r11_disp8, sib_r10_r12_disp8, sib_r10_r13_disp8, sib_r10_r14_disp8, sib_r10_r15_disp8, 
		sib_r11_rax_disp8, sib_r11_rcx_disp8, sib_r11_rdx_disp8, sib_r11_rbx_disp8, sib_r11_rsp_disp8, sib_r11_rbp_disp8, sib_r11_rsi_disp8, sib_r11_rdi_disp8, sib_r11_r8_disp8, sib_r11_r9_disp8, sib_r11_r10_disp8, sib_r11_r11_disp8, sib_r11_r12_disp8, sib_r11_r13_disp8, sib_r11_r14_disp8, sib_r11_r15_disp8, 
		sib_r12_rax_disp8, sib_r12_rcx_disp8, sib_r12_rdx_disp8, sib_r12_rbx_disp8, sib_r12_rsp_disp8, sib_r12_rbp_disp8, sib_r12_rsi_disp8, sib_r12_rdi_disp8, sib_r12_r8_disp8, sib_r12_r9_disp8, sib_r12_r10_disp8, sib_r12_r11_disp8, sib_r12_r12_disp8, sib_r12_r13_disp8, sib_r12_r14_disp8, sib_r12_r15_disp8, 
		sib_r13_rax_disp8, sib_r13_rcx_disp8, sib_r13_rdx_disp8, sib_r13_rbx_disp8, sib_r13_rsp_disp8, sib_r13_rbp_disp8, sib_r13_rsi_disp8, sib_r13_rdi_disp8, sib_r13_r8_disp8, sib_r13_r9_disp8, sib_r13_r10_disp8, sib_r13_r11_disp8, sib_r13_r12_disp8, sib_r13_r13_disp8, sib_r13_r14_disp8, sib_r13_r15_disp8, 
		sib_r14_rax_disp8, sib_r14_rcx_disp8, sib_r14_rdx_disp8, sib_r14_rbx_disp8, sib_r14_rsp_disp8, sib_r14_rbp_disp8, sib_r14_rsi_disp8, sib_r14_rdi_disp8, sib_r14_r8_disp8, sib_r14_r9_disp8, sib_r14_r10_disp8, sib_r14_r11_disp8, sib_r14_r12_disp8, sib_r14_r13_disp8, sib_r14_r14_disp8, sib_r14_r15_disp8, 
		sib_r15_rax_disp8, sib_r15_rcx_disp8, sib_r15_rdx_disp8, sib_r15_rbx_disp8, sib_r15_rsp_disp8, sib_r15_rbp_disp8, sib_r15_rsi_disp8, sib_r15_rdi_disp8, sib_r15_r8_disp8, sib_r15_r9_disp8, sib_r15_r10_disp8, sib_r15_r11_disp8, sib_r15_r12_disp8, sib_r15_r13_disp8, sib_r15_r14_disp8, sib_r15_r15_disp8, 
		MemSib64Scale1Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale2Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_2_rax_disp8, sib_rax_2_rcx_disp8, sib_rax_2_rdx_disp8, sib_rax_2_rbx_disp8, sib_rax_2_rsp_disp8, sib_rax_2_rbp_disp8, sib_rax_2_rsi_disp8, sib_rax_2_rdi_disp8, sib_rax_2_r8_disp8, sib_rax_2_r9_disp8, sib_rax_2_r10_disp8, sib_rax_2_r11_disp8, sib_rax_2_r12_disp8, sib_rax_2_r13_disp8, sib_rax_2_r14_disp8, sib_rax_2_r15_disp8,
		sib_rcx_2_rax_disp8, sib_rcx_2_rcx_disp8, sib_rcx_2_rdx_disp8, sib_rcx_2_rbx_disp8, sib_rcx_2_rsp_disp8, sib_rcx_2_rbp_disp8, sib_rcx_2_rsi_disp8, sib_rcx_2_rdi_disp8, sib_rcx_2_r8_disp8, sib_rcx_2_r9_disp8, sib_rcx_2_r10_disp8, sib_rcx_2_r11_disp8, sib_rcx_2_r12_disp8, sib_rcx_2_r13_disp8, sib_rcx_2_r14_disp8, sib_rcx_2_r15_disp8,
		sib_rdx_2_rax_disp8, sib_rdx_2_rcx_disp8, sib_rdx_2_rdx_disp8, sib_rdx_2_rbx_disp8, sib_rdx_2_rsp_disp8, sib_rdx_2_rbp_disp8, sib_rdx_2_rsi_disp8, sib_rdx_2_rdi_disp8, sib_rdx_2_r8_disp8, sib_rdx_2_r9_disp8, sib_rdx_2_r10_disp8, sib_rdx_2_r11_disp8, sib_rdx_2_r12_disp8, sib_rdx_2_r13_disp8, sib_rdx_2_r14_disp8, sib_rdx_2_r15_disp8,
		sib_rbx_2_rax_disp8, sib_rbx_2_rcx_disp8, sib_rbx_2_rdx_disp8, sib_rbx_2_rbx_disp8, sib_rbx_2_rsp_disp8, sib_rbx_2_rbp_disp8, sib_rbx_2_rsi_disp8, sib_rbx_2_rdi_disp8, sib_rbx_2_r8_disp8, sib_rbx_2_r9_disp8, sib_rbx_2_r10_disp8, sib_rbx_2_r11_disp8, sib_rbx_2_r12_disp8, sib_rbx_2_r13_disp8, sib_rbx_2_r14_disp8, sib_rbx_2_r15_disp8,
		sib_none_2_rax_disp8, sib_none_2_rcx_disp8, sib_none_2_rdx_disp8, sib_none_2_rbx_disp8, sib_none_2_rsp_disp8, sib_none_2_rbp_disp8, sib_none_2_rsi_disp8, sib_none_2_rdi_disp8, sib_none_2_r8_disp8, sib_none_2_r9_disp8, sib_none_2_r10_disp8, sib_none_2_r11_disp8, sib_none_2_r12_disp8, sib_none_2_r13_disp8, sib_none_2_r14_disp8, sib_none_2_r15_disp8,
		sib_rbp_2_rax_disp8, sib_rbp_2_rcx_disp8, sib_rbp_2_rdx_disp8, sib_rbp_2_rbx_disp8, sib_rbp_2_rsp_disp8, sib_rbp_2_rbp_disp8, sib_rbp_2_rsi_disp8, sib_rbp_2_rdi_disp8, sib_rbp_2_r8_disp8, sib_rbp_2_r9_disp8, sib_rbp_2_r10_disp8, sib_rbp_2_r11_disp8, sib_rbp_2_r12_disp8, sib_rbp_2_r13_disp8, sib_rbp_2_r14_disp8, sib_rbp_2_r15_disp8,
		sib_rsi_2_rax_disp8, sib_rsi_2_rcx_disp8, sib_rsi_2_rdx_disp8, sib_rsi_2_rbx_disp8, sib_rsi_2_rsp_disp8, sib_rsi_2_rbp_disp8, sib_rsi_2_rsi_disp8, sib_rsi_2_rdi_disp8, sib_rsi_2_r8_disp8, sib_rsi_2_r9_disp8, sib_rsi_2_r10_disp8, sib_rsi_2_r11_disp8, sib_rsi_2_r12_disp8, sib_rsi_2_r13_disp8, sib_rsi_2_r14_disp8, sib_rsi_2_r15_disp8,
		sib_rdi_2_rax_disp8, sib_rdi_2_rcx_disp8, sib_rdi_2_rdx_disp8, sib_rdi_2_rbx_disp8, sib_rdi_2_rsp_disp8, sib_rdi_2_rbp_disp8, sib_rdi_2_rsi_disp8, sib_rdi_2_rdi_disp8, sib_rdi_2_r8_disp8, sib_rdi_2_r9_disp8, sib_rdi_2_r10_disp8, sib_rdi_2_r11_disp8, sib_rdi_2_r12_disp8, sib_rdi_2_r13_disp8, sib_rdi_2_r14_disp8, sib_rdi_2_r15_disp8,
		sib_r8_2_rax_disp8, sib_r8_2_rcx_disp8, sib_r8_2_rdx_disp8, sib_r8_2_rbx_disp8, sib_r8_2_rsp_disp8, sib_r8_2_rbp_disp8, sib_r8_2_rsi_disp8,  sib_r8_2_rdi_disp8,  sib_r8_2_r8_disp8,  sib_r8_2_r9_disp8,  sib_r8_2_r10_disp8,  sib_r8_2_r11_disp8,  sib_r8_2_r12_disp8,  sib_r8_2_r13_disp8,  sib_r8_2_r14_disp8,  sib_r8_2_r15_disp8,
		sib_r9_2_rax_disp8, sib_r9_2_rcx_disp8, sib_r9_2_rdx_disp8, sib_r9_2_rbx_disp8, sib_r9_2_rsp_disp8, sib_r9_2_rbp_disp8, sib_r9_2_rsi_disp8,  sib_r9_2_rdi_disp8,  sib_r9_2_r8_disp8,  sib_r9_2_r9_disp8,  sib_r9_2_r10_disp8,  sib_r9_2_r11_disp8,  sib_r9_2_r12_disp8,  sib_r9_2_r13_disp8,  sib_r9_2_r14_disp8,  sib_r9_2_r15_disp8,
		sib_r10_2_rax_disp8, sib_r10_2_rcx_disp8, sib_r10_2_rdx_disp8, sib_r10_2_rbx_disp8, sib_r10_2_rsp_disp8, sib_r10_2_rbp_disp8, sib_r10_2_rsi_disp8, sib_r10_2_rdi_disp8, sib_r10_2_r8_disp8, sib_r10_2_r9_disp8, sib_r10_2_r10_disp8, sib_r10_2_r11_disp8, sib_r10_2_r12_disp8, sib_r10_2_r13_disp8, sib_r10_2_r14_disp8, sib_r10_2_r15_disp8,
		sib_r11_2_rax_disp8, sib_r11_2_rcx_disp8, sib_r11_2_rdx_disp8, sib_r11_2_rbx_disp8, sib_r11_2_rsp_disp8, sib_r11_2_rbp_disp8, sib_r11_2_rsi_disp8, sib_r11_2_rdi_disp8, sib_r11_2_r8_disp8, sib_r11_2_r9_disp8, sib_r11_2_r10_disp8, sib_r11_2_r11_disp8, sib_r11_2_r12_disp8, sib_r11_2_r13_disp8, sib_r11_2_r14_disp8, sib_r11_2_r15_disp8,
		sib_r12_2_rax_disp8, sib_r12_2_rcx_disp8, sib_r12_2_rdx_disp8, sib_r12_2_rbx_disp8, sib_r12_2_rsp_disp8, sib_r12_2_rbp_disp8, sib_r12_2_rsi_disp8, sib_r12_2_rdi_disp8, sib_r12_2_r8_disp8, sib_r12_2_r9_disp8, sib_r12_2_r10_disp8, sib_r12_2_r11_disp8, sib_r12_2_r12_disp8, sib_r12_2_r13_disp8, sib_r12_2_r14_disp8, sib_r12_2_r15_disp8,
		sib_r13_2_rax_disp8, sib_r13_2_rcx_disp8, sib_r13_2_rdx_disp8, sib_r13_2_rbx_disp8, sib_r13_2_rsp_disp8, sib_r13_2_rbp_disp8, sib_r13_2_rsi_disp8, sib_r13_2_rdi_disp8, sib_r13_2_r8_disp8, sib_r13_2_r9_disp8, sib_r13_2_r10_disp8, sib_r13_2_r11_disp8, sib_r13_2_r12_disp8, sib_r13_2_r13_disp8, sib_r13_2_r14_disp8, sib_r13_2_r15_disp8,
		sib_r14_2_rax_disp8, sib_r14_2_rcx_disp8, sib_r14_2_rdx_disp8, sib_r14_2_rbx_disp8, sib_r14_2_rsp_disp8, sib_r14_2_rbp_disp8, sib_r14_2_rsi_disp8, sib_r14_2_rdi_disp8, sib_r14_2_r8_disp8, sib_r14_2_r9_disp8, sib_r14_2_r10_disp8, sib_r14_2_r11_disp8, sib_r14_2_r12_disp8, sib_r14_2_r13_disp8, sib_r14_2_r14_disp8, sib_r14_2_r15_disp8,
		sib_r15_2_rax_disp8, sib_r15_2_rcx_disp8, sib_r15_2_rdx_disp8, sib_r15_2_rbx_disp8, sib_r15_2_rsp_disp8, sib_r15_2_rbp_disp8, sib_r15_2_rsi_disp8, sib_r15_2_rdi_disp8, sib_r15_2_r8_disp8, sib_r15_2_r9_disp8, sib_r15_2_r10_disp8, sib_r15_2_r11_disp8, sib_r15_2_r12_disp8, sib_r15_2_r13_disp8, sib_r15_2_r14_disp8, sib_r15_2_r15_disp8,
		MemSib64Scale2Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale4Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_4_rax_disp8, sib_rax_4_rcx_disp8, sib_rax_4_rdx_disp8, sib_rax_4_rbx_disp8, sib_rax_4_rsp_disp8, sib_rax_4_rbp_disp8, sib_rax_4_rsi_disp8, sib_rax_4_rdi_disp8, sib_rax_4_r8_disp8, sib_rax_4_r9_disp8, sib_rax_4_r10_disp8, sib_rax_4_r11_disp8, sib_rax_4_r12_disp8, sib_rax_4_r13_disp8, sib_rax_4_r14_disp8, sib_rax_4_r15_disp8,
		sib_rcx_4_rax_disp8, sib_rcx_4_rcx_disp8, sib_rcx_4_rdx_disp8, sib_rcx_4_rbx_disp8, sib_rcx_4_rsp_disp8, sib_rcx_4_rbp_disp8, sib_rcx_4_rsi_disp8, sib_rcx_4_rdi_disp8, sib_rcx_4_r8_disp8, sib_rcx_4_r9_disp8, sib_rcx_4_r10_disp8, sib_rcx_4_r11_disp8, sib_rcx_4_r12_disp8, sib_rcx_4_r13_disp8, sib_rcx_4_r14_disp8, sib_rcx_4_r15_disp8,
		sib_rdx_4_rax_disp8, sib_rdx_4_rcx_disp8, sib_rdx_4_rdx_disp8, sib_rdx_4_rbx_disp8, sib_rdx_4_rsp_disp8, sib_rdx_4_rbp_disp8, sib_rdx_4_rsi_disp8, sib_rdx_4_rdi_disp8, sib_rdx_4_r8_disp8, sib_rdx_4_r9_disp8, sib_rdx_4_r10_disp8, sib_rdx_4_r11_disp8, sib_rdx_4_r12_disp8, sib_rdx_4_r13_disp8, sib_rdx_4_r14_disp8, sib_rdx_4_r15_disp8,
		sib_rbx_4_rax_disp8, sib_rbx_4_rcx_disp8, sib_rbx_4_rdx_disp8, sib_rbx_4_rbx_disp8, sib_rbx_4_rsp_disp8, sib_rbx_4_rbp_disp8, sib_rbx_4_rsi_disp8, sib_rbx_4_rdi_disp8, sib_rbx_4_r8_disp8, sib_rbx_4_r9_disp8, sib_rbx_4_r10_disp8, sib_rbx_4_r11_disp8, sib_rbx_4_r12_disp8, sib_rbx_4_r13_disp8, sib_rbx_4_r14_disp8, sib_rbx_4_r15_disp8,
		sib_none_4_rax_disp8, sib_none_4_rcx_disp8, sib_none_4_rdx_disp8, sib_none_4_rbx_disp8, sib_none_4_rsp_disp8, sib_none_4_rbp_disp8, sib_none_4_rsi_disp8, sib_none_4_rdi_disp8, sib_none_4_r8_disp8, sib_none_4_r9_disp8, sib_none_4_r10_disp8, sib_none_4_r11_disp8, sib_none_4_r12_disp8, sib_none_4_r13_disp8, sib_none_4_r14_disp8, sib_none_4_r15_disp8,
		sib_rbp_4_rax_disp8, sib_rbp_4_rcx_disp8, sib_rbp_4_rdx_disp8, sib_rbp_4_rbx_disp8, sib_rbp_4_rsp_disp8, sib_rbp_4_rbp_disp8, sib_rbp_4_rsi_disp8, sib_rbp_4_rdi_disp8, sib_rbp_4_r8_disp8, sib_rbp_4_r9_disp8, sib_rbp_4_r10_disp8, sib_rbp_4_r11_disp8, sib_rbp_4_r12_disp8, sib_rbp_4_r13_disp8, sib_rbp_4_r14_disp8, sib_rbp_4_r15_disp8,
		sib_rsi_4_rax_disp8, sib_rsi_4_rcx_disp8, sib_rsi_4_rdx_disp8, sib_rsi_4_rbx_disp8, sib_rsi_4_rsp_disp8, sib_rsi_4_rbp_disp8, sib_rsi_4_rsi_disp8, sib_rsi_4_rdi_disp8, sib_rsi_4_r8_disp8, sib_rsi_4_r9_disp8, sib_rsi_4_r10_disp8, sib_rsi_4_r11_disp8, sib_rsi_4_r12_disp8, sib_rsi_4_r13_disp8, sib_rsi_4_r14_disp8, sib_rsi_4_r15_disp8,
		sib_rdi_4_rax_disp8, sib_rdi_4_rcx_disp8, sib_rdi_4_rdx_disp8, sib_rdi_4_rbx_disp8, sib_rdi_4_rsp_disp8, sib_rdi_4_rbp_disp8, sib_rdi_4_rsi_disp8, sib_rdi_4_rdi_disp8, sib_rdi_4_r8_disp8, sib_rdi_4_r9_disp8, sib_rdi_4_r10_disp8, sib_rdi_4_r11_disp8, sib_rdi_4_r12_disp8, sib_rdi_4_r13_disp8, sib_rdi_4_r14_disp8, sib_rdi_4_r15_disp8,
		sib_r8_4_rax_disp8, sib_r8_4_rcx_disp8, sib_r8_4_rdx_disp8, sib_r8_4_rbx_disp8, sib_r8_4_rsp_disp8, sib_r8_4_rbp_disp8, sib_r8_4_rsi_disp8,  sib_r8_4_rdi_disp8,  sib_r8_4_r8_disp8,  sib_r8_4_r9_disp8,  sib_r8_4_r10_disp8,  sib_r8_4_r11_disp8,  sib_r8_4_r12_disp8,  sib_r8_4_r13_disp8,  sib_r8_4_r14_disp8,  sib_r8_4_r15_disp8,
		sib_r9_4_rax_disp8, sib_r9_4_rcx_disp8, sib_r9_4_rdx_disp8, sib_r9_4_rbx_disp8, sib_r9_4_rsp_disp8, sib_r9_4_rbp_disp8, sib_r9_4_rsi_disp8,  sib_r9_4_rdi_disp8,  sib_r9_4_r8_disp8,  sib_r9_4_r9_disp8,  sib_r9_4_r10_disp8,  sib_r9_4_r11_disp8,  sib_r9_4_r12_disp8,  sib_r9_4_r13_disp8,  sib_r9_4_r14_disp8,  sib_r9_4_r15_disp8,
		sib_r10_4_rax_disp8, sib_r10_4_rcx_disp8, sib_r10_4_rdx_disp8, sib_r10_4_rbx_disp8, sib_r10_4_rsp_disp8, sib_r10_4_rbp_disp8, sib_r10_4_rsi_disp8, sib_r10_4_rdi_disp8, sib_r10_4_r8_disp8, sib_r10_4_r9_disp8, sib_r10_4_r10_disp8, sib_r10_4_r11_disp8, sib_r10_4_r12_disp8, sib_r10_4_r13_disp8, sib_r10_4_r14_disp8, sib_r10_4_r15_disp8,
		sib_r11_4_rax_disp8, sib_r11_4_rcx_disp8, sib_r11_4_rdx_disp8, sib_r11_4_rbx_disp8, sib_r11_4_rsp_disp8, sib_r11_4_rbp_disp8, sib_r11_4_rsi_disp8, sib_r11_4_rdi_disp8, sib_r11_4_r8_disp8, sib_r11_4_r9_disp8, sib_r11_4_r10_disp8, sib_r11_4_r11_disp8, sib_r11_4_r12_disp8, sib_r11_4_r13_disp8, sib_r11_4_r14_disp8, sib_r11_4_r15_disp8,
		sib_r12_4_rax_disp8, sib_r12_4_rcx_disp8, sib_r12_4_rdx_disp8, sib_r12_4_rbx_disp8, sib_r12_4_rsp_disp8, sib_r12_4_rbp_disp8, sib_r12_4_rsi_disp8, sib_r12_4_rdi_disp8, sib_r12_4_r8_disp8, sib_r12_4_r9_disp8, sib_r12_4_r10_disp8, sib_r12_4_r11_disp8, sib_r12_4_r12_disp8, sib_r12_4_r13_disp8, sib_r12_4_r14_disp8, sib_r12_4_r15_disp8,
		sib_r13_4_rax_disp8, sib_r13_4_rcx_disp8, sib_r13_4_rdx_disp8, sib_r13_4_rbx_disp8, sib_r13_4_rsp_disp8, sib_r13_4_rbp_disp8, sib_r13_4_rsi_disp8, sib_r13_4_rdi_disp8, sib_r13_4_r8_disp8, sib_r13_4_r9_disp8, sib_r13_4_r10_disp8, sib_r13_4_r11_disp8, sib_r13_4_r12_disp8, sib_r13_4_r13_disp8, sib_r13_4_r14_disp8, sib_r13_4_r15_disp8,
		sib_r14_4_rax_disp8, sib_r14_4_rcx_disp8, sib_r14_4_rdx_disp8, sib_r14_4_rbx_disp8, sib_r14_4_rsp_disp8, sib_r14_4_rbp_disp8, sib_r14_4_rsi_disp8, sib_r14_4_rdi_disp8, sib_r14_4_r8_disp8, sib_r14_4_r9_disp8, sib_r14_4_r10_disp8, sib_r14_4_r11_disp8, sib_r14_4_r12_disp8, sib_r14_4_r13_disp8, sib_r14_4_r14_disp8, sib_r14_4_r15_disp8,
		sib_r15_4_rax_disp8, sib_r15_4_rcx_disp8, sib_r15_4_rdx_disp8, sib_r15_4_rbx_disp8, sib_r15_4_rsp_disp8, sib_r15_4_rbp_disp8, sib_r15_4_rsi_disp8, sib_r15_4_rdi_disp8, sib_r15_4_r8_disp8, sib_r15_4_r9_disp8, sib_r15_4_r10_disp8, sib_r15_4_r11_disp8, sib_r15_4_r12_disp8, sib_r15_4_r13_disp8, sib_r15_4_r14_disp8, sib_r15_4_r15_disp8,
		MemSib64Scale4Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale8Disp8Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_8_rax_disp8, sib_rax_8_rcx_disp8, sib_rax_8_rdx_disp8, sib_rax_8_rbx_disp8, sib_rax_8_rsp_disp8, sib_rax_8_rbp_disp8, sib_rax_8_rsi_disp8, sib_rax_8_rdi_disp8, sib_rax_8_r8_disp8, sib_rax_8_r9_disp8, sib_rax_8_r10_disp8, sib_rax_8_r11_disp8, sib_rax_8_r12_disp8, sib_rax_8_r13_disp8, sib_rax_8_r14_disp8, sib_rax_8_r15_disp8,
		sib_rcx_8_rax_disp8, sib_rcx_8_rcx_disp8, sib_rcx_8_rdx_disp8, sib_rcx_8_rbx_disp8, sib_rcx_8_rsp_disp8, sib_rcx_8_rbp_disp8, sib_rcx_8_rsi_disp8, sib_rcx_8_rdi_disp8, sib_rcx_8_r8_disp8, sib_rcx_8_r9_disp8, sib_rcx_8_r10_disp8, sib_rcx_8_r11_disp8, sib_rcx_8_r12_disp8, sib_rcx_8_r13_disp8, sib_rcx_8_r14_disp8, sib_rcx_8_r15_disp8,
		sib_rdx_8_rax_disp8, sib_rdx_8_rcx_disp8, sib_rdx_8_rdx_disp8, sib_rdx_8_rbx_disp8, sib_rdx_8_rsp_disp8, sib_rdx_8_rbp_disp8, sib_rdx_8_rsi_disp8, sib_rdx_8_rdi_disp8, sib_rdx_8_r8_disp8, sib_rdx_8_r9_disp8, sib_rdx_8_r10_disp8, sib_rdx_8_r11_disp8, sib_rdx_8_r12_disp8, sib_rdx_8_r13_disp8, sib_rdx_8_r14_disp8, sib_rdx_8_r15_disp8,
		sib_rbx_8_rax_disp8, sib_rbx_8_rcx_disp8, sib_rbx_8_rdx_disp8, sib_rbx_8_rbx_disp8, sib_rbx_8_rsp_disp8, sib_rbx_8_rbp_disp8, sib_rbx_8_rsi_disp8, sib_rbx_8_rdi_disp8, sib_rbx_8_r8_disp8, sib_rbx_8_r9_disp8, sib_rbx_8_r10_disp8, sib_rbx_8_r11_disp8, sib_rbx_8_r12_disp8, sib_rbx_8_r13_disp8, sib_rbx_8_r14_disp8, sib_rbx_8_r15_disp8,
		sib_none_8_rax_disp8, sib_none_8_rcx_disp8, sib_none_8_rdx_disp8, sib_none_8_rbx_disp8, sib_none_8_rsp_disp8, sib_none_8_rbp_disp8, sib_none_8_rsi_disp8, sib_none_8_rdi_disp8, sib_none_8_r8_disp8, sib_none_8_r9_disp8, sib_none_8_r10_disp8, sib_none_8_r11_disp8, sib_none_8_r12_disp8, sib_none_8_r13_disp8, sib_none_8_r14_disp8, sib_none_8_r15_disp8,
		sib_rbp_8_rax_disp8, sib_rbp_8_rcx_disp8, sib_rbp_8_rdx_disp8, sib_rbp_8_rbx_disp8, sib_rbp_8_rsp_disp8, sib_rbp_8_rbp_disp8, sib_rbp_8_rsi_disp8, sib_rbp_8_rdi_disp8, sib_rbp_8_r8_disp8, sib_rbp_8_r9_disp8, sib_rbp_8_r10_disp8, sib_rbp_8_r11_disp8, sib_rbp_8_r12_disp8, sib_rbp_8_r13_disp8, sib_rbp_8_r14_disp8, sib_rbp_8_r15_disp8,
		sib_rsi_8_rax_disp8, sib_rsi_8_rcx_disp8, sib_rsi_8_rdx_disp8, sib_rsi_8_rbx_disp8, sib_rsi_8_rsp_disp8, sib_rsi_8_rbp_disp8, sib_rsi_8_rsi_disp8, sib_rsi_8_rdi_disp8, sib_rsi_8_r8_disp8, sib_rsi_8_r9_disp8, sib_rsi_8_r10_disp8, sib_rsi_8_r11_disp8, sib_rsi_8_r12_disp8, sib_rsi_8_r13_disp8, sib_rsi_8_r14_disp8, sib_rsi_8_r15_disp8,
		sib_rdi_8_rax_disp8, sib_rdi_8_rcx_disp8, sib_rdi_8_rdx_disp8, sib_rdi_8_rbx_disp8, sib_rdi_8_rsp_disp8, sib_rdi_8_rbp_disp8, sib_rdi_8_rsi_disp8, sib_rdi_8_rdi_disp8, sib_rdi_8_r8_disp8, sib_rdi_8_r9_disp8, sib_rdi_8_r10_disp8, sib_rdi_8_r11_disp8, sib_rdi_8_r12_disp8, sib_rdi_8_r13_disp8, sib_rdi_8_r14_disp8, sib_rdi_8_r15_disp8,
		sib_r8_8_rax_disp8, sib_r8_8_rcx_disp8, sib_r8_8_rdx_disp8, sib_r8_8_rbx_disp8, sib_r8_8_rsp_disp8, sib_r8_8_rbp_disp8, sib_r8_8_rsi_disp8,  sib_r8_8_rdi_disp8,  sib_r8_8_r8_disp8,  sib_r8_8_r9_disp8,  sib_r8_8_r10_disp8,  sib_r8_8_r11_disp8,  sib_r8_8_r12_disp8,  sib_r8_8_r13_disp8,  sib_r8_8_r14_disp8,  sib_r8_8_r15_disp8,
		sib_r9_8_rax_disp8, sib_r9_8_rcx_disp8, sib_r9_8_rdx_disp8, sib_r9_8_rbx_disp8, sib_r9_8_rsp_disp8, sib_r9_8_rbp_disp8, sib_r9_8_rsi_disp8,  sib_r9_8_rdi_disp8,  sib_r9_8_r8_disp8,  sib_r9_8_r9_disp8,  sib_r9_8_r10_disp8,  sib_r9_8_r11_disp8,  sib_r9_8_r12_disp8,  sib_r9_8_r13_disp8,  sib_r9_8_r14_disp8,  sib_r9_8_r15_disp8,
		sib_r10_8_rax_disp8, sib_r10_8_rcx_disp8, sib_r10_8_rdx_disp8, sib_r10_8_rbx_disp8, sib_r10_8_rsp_disp8, sib_r10_8_rbp_disp8, sib_r10_8_rsi_disp8, sib_r10_8_rdi_disp8, sib_r10_8_r8_disp8, sib_r10_8_r9_disp8, sib_r10_8_r10_disp8, sib_r10_8_r11_disp8, sib_r10_8_r12_disp8, sib_r10_8_r13_disp8, sib_r10_8_r14_disp8, sib_r10_8_r15_disp8,
		sib_r11_8_rax_disp8, sib_r11_8_rcx_disp8, sib_r11_8_rdx_disp8, sib_r11_8_rbx_disp8, sib_r11_8_rsp_disp8, sib_r11_8_rbp_disp8, sib_r11_8_rsi_disp8, sib_r11_8_rdi_disp8, sib_r11_8_r8_disp8, sib_r11_8_r9_disp8, sib_r11_8_r10_disp8, sib_r11_8_r11_disp8, sib_r11_8_r12_disp8, sib_r11_8_r13_disp8, sib_r11_8_r14_disp8, sib_r11_8_r15_disp8,
		sib_r12_8_rax_disp8, sib_r12_8_rcx_disp8, sib_r12_8_rdx_disp8, sib_r12_8_rbx_disp8, sib_r12_8_rsp_disp8, sib_r12_8_rbp_disp8, sib_r12_8_rsi_disp8, sib_r12_8_rdi_disp8, sib_r12_8_r8_disp8, sib_r12_8_r9_disp8, sib_r12_8_r10_disp8, sib_r12_8_r11_disp8, sib_r12_8_r12_disp8, sib_r12_8_r13_disp8, sib_r12_8_r14_disp8, sib_r12_8_r15_disp8,
		sib_r13_8_rax_disp8, sib_r13_8_rcx_disp8, sib_r13_8_rdx_disp8, sib_r13_8_rbx_disp8, sib_r13_8_rsp_disp8, sib_r13_8_rbp_disp8, sib_r13_8_rsi_disp8, sib_r13_8_rdi_disp8, sib_r13_8_r8_disp8, sib_r13_8_r9_disp8, sib_r13_8_r10_disp8, sib_r13_8_r11_disp8, sib_r13_8_r12_disp8, sib_r13_8_r13_disp8, sib_r13_8_r14_disp8, sib_r13_8_r15_disp8,
		sib_r14_8_rax_disp8, sib_r14_8_rcx_disp8, sib_r14_8_rdx_disp8, sib_r14_8_rbx_disp8, sib_r14_8_rsp_disp8, sib_r14_8_rbp_disp8, sib_r14_8_rsi_disp8, sib_r14_8_rdi_disp8, sib_r14_8_r8_disp8, sib_r14_8_r9_disp8, sib_r14_8_r10_disp8, sib_r14_8_r11_disp8, sib_r14_8_r12_disp8, sib_r14_8_r13_disp8, sib_r14_8_r14_disp8, sib_r14_8_r15_disp8,
		sib_r15_8_rax_disp8, sib_r15_8_rcx_disp8, sib_r15_8_rdx_disp8, sib_r15_8_rbx_disp8, sib_r15_8_rsp_disp8, sib_r15_8_rbp_disp8, sib_r15_8_rsi_disp8, sib_r15_8_rdi_disp8, sib_r15_8_r8_disp8, sib_r15_8_r9_disp8, sib_r15_8_r10_disp8, sib_r15_8_r11_disp8, sib_r15_8_r12_disp8, sib_r15_8_r13_disp8, sib_r15_8_r14_disp8, sib_r15_8_r15_disp8,
		MemSib64Scale8Disp8End,		// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib64Disp8End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib64Scale1Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_rax_disp32, sib_rax_rcx_disp32, sib_rax_rdx_disp32, sib_rax_rbx_disp32, sib_rax_rsp_disp32, sib_rax_rbp_disp32, sib_rax_rsi_disp32, sib_rax_rdi_disp32, sib_rax_r8_disp32, sib_rax_r9_disp32, sib_rax_r10_disp32, sib_rax_r11_disp32, sib_rax_r12_disp32, sib_rax_r13_disp32, sib_rax_r14_disp32, sib_rax_r15_disp32, 
		sib_rcx_rax_disp32, sib_rcx_rcx_disp32, sib_rcx_rdx_disp32, sib_rcx_rbx_disp32, sib_rcx_rsp_disp32, sib_rcx_rbp_disp32, sib_rcx_rsi_disp32, sib_rcx_rdi_disp32, sib_rcx_r8_disp32, sib_rcx_r9_disp32, sib_rcx_r10_disp32, sib_rcx_r11_disp32, sib_rcx_r12_disp32, sib_rcx_r13_disp32, sib_rcx_r14_disp32, sib_rcx_r15_disp32, 
		sib_rdx_rax_disp32, sib_rdx_rcx_disp32, sib_rdx_rdx_disp32, sib_rdx_rbx_disp32, sib_rdx_rsp_disp32, sib_rdx_rbp_disp32, sib_rdx_rsi_disp32, sib_rdx_rdi_disp32, sib_rdx_r8_disp32, sib_rdx_r9_disp32, sib_rdx_r10_disp32, sib_rdx_r11_disp32, sib_rdx_r12_disp32, sib_rdx_r13_disp32, sib_rdx_r14_disp32, sib_rdx_r15_disp32, 
		sib_rbx_rax_disp32, sib_rbx_rcx_disp32, sib_rbx_rdx_disp32, sib_rbx_rbx_disp32, sib_rbx_rsp_disp32, sib_rbx_rbp_disp32, sib_rbx_rsi_disp32, sib_rbx_rdi_disp32, sib_rbx_r8_disp32, sib_rbx_r9_disp32, sib_rbx_r10_disp32, sib_rbx_r11_disp32, sib_rbx_r12_disp32, sib_rbx_r13_disp32, sib_rbx_r14_disp32, sib_rbx_r15_disp32, 
		sib_none_rax_disp32, sib_none_rcx_disp32, sib_none_rdx_disp32, sib_none_rbx_disp32, sib_none_rsp_disp32, sib_none_rbp_disp32, sib_none_rsi_disp32, sib_none_rdi_disp32, sib_none_r8_disp32, sib_none_r9_disp32, sib_none_r10_disp32, sib_none_r11_disp32, sib_none_r12_disp32, sib_none_r13_disp32, sib_none_r14_disp32, sib_none_r15_disp32,
		sib_rbp_rax_disp32, sib_rbp_rcx_disp32, sib_rbp_rdx_disp32, sib_rbp_rbx_disp32, sib_rbp_rsp_disp32, sib_rbp_rbp_disp32, sib_rbp_rsi_disp32, sib_rbp_rdi_disp32, sib_rbp_r8_disp32, sib_rbp_r9_disp32, sib_rbp_r10_disp32, sib_rbp_r11_disp32, sib_rbp_r12_disp32, sib_rbp_r13_disp32, sib_rbp_r14_disp32, sib_rbp_r15_disp32, 
		sib_rsi_rax_disp32, sib_rsi_rcx_disp32, sib_rsi_rdx_disp32, sib_rsi_rbx_disp32, sib_rsi_rsp_disp32, sib_rsi_rbp_disp32, sib_rsi_rsi_disp32, sib_rsi_rdi_disp32, sib_rsi_r8_disp32, sib_rsi_r9_disp32, sib_rsi_r10_disp32, sib_rsi_r11_disp32, sib_rsi_r12_disp32, sib_rsi_r13_disp32, sib_rsi_r14_disp32, sib_rsi_r15_disp32, 
		sib_rdi_rax_disp32, sib_rdi_rcx_disp32, sib_rdi_rdx_disp32, sib_rdi_rbx_disp32, sib_rdi_rsp_disp32, sib_rdi_rbp_disp32, sib_rdi_rsi_disp32, sib_rdi_rdi_disp32, sib_rdi_r8_disp32, sib_rdi_r9_disp32, sib_rdi_r10_disp32, sib_rdi_r11_disp32, sib_rdi_r12_disp32, sib_rdi_r13_disp32, sib_rdi_r14_disp32, sib_rdi_r15_disp32, 
		sib_r8_rax_disp32, sib_r8_rcx_disp32, sib_r8_rdx_disp32, sib_r8_rbx_disp32, sib_r8_rsp_disp32, sib_r8_rbp_disp32, sib_r8_rsi_disp32, sib_r8_rdi_disp32, sib_r8_r8_disp32, sib_r8_r9_disp32, sib_r8_r10_disp32, sib_r8_r11_disp32, sib_r8_r12_disp32, sib_r8_r13_disp32, sib_r8_r14_disp32, sib_r8_r15_disp32, 
		sib_r9_rax_disp32, sib_r9_rcx_disp32, sib_r9_rdx_disp32, sib_r9_rbx_disp32, sib_r9_rsp_disp32, sib_r9_rbp_disp32, sib_r9_rsi_disp32, sib_r9_rdi_disp32, sib_r9_r8_disp32, sib_r9_r9_disp32, sib_r9_r10_disp32, sib_r9_r11_disp32, sib_r9_r12_disp32, sib_r9_r13_disp32, sib_r9_r14_disp32, sib_r9_r15_disp32, 
		sib_r10_rax_disp32, sib_r10_rcx_disp32, sib_r10_rdx_disp32, sib_r10_rbx_disp32, sib_r10_rsp_disp32, sib_r10_rbp_disp32, sib_r10_rsi_disp32, sib_r10_rdi_disp32, sib_r10_r8_disp32, sib_r10_r9_disp32, sib_r10_r10_disp32, sib_r10_r11_disp32, sib_r10_r12_disp32, sib_r10_r13_disp32, sib_r10_r14_disp32, sib_r10_r15_disp32, 
		sib_r11_rax_disp32, sib_r11_rcx_disp32, sib_r11_rdx_disp32, sib_r11_rbx_disp32, sib_r11_rsp_disp32, sib_r11_rbp_disp32, sib_r11_rsi_disp32, sib_r11_rdi_disp32, sib_r11_r8_disp32, sib_r11_r9_disp32, sib_r11_r10_disp32, sib_r11_r11_disp32, sib_r11_r12_disp32, sib_r11_r13_disp32, sib_r11_r14_disp32, sib_r11_r15_disp32, 
		sib_r12_rax_disp32, sib_r12_rcx_disp32, sib_r12_rdx_disp32, sib_r12_rbx_disp32, sib_r12_rsp_disp32, sib_r12_rbp_disp32, sib_r12_rsi_disp32, sib_r12_rdi_disp32, sib_r12_r8_disp32, sib_r12_r9_disp32, sib_r12_r10_disp32, sib_r12_r11_disp32, sib_r12_r12_disp32, sib_r12_r13_disp32, sib_r12_r14_disp32, sib_r12_r15_disp32, 
		sib_r13_rax_disp32, sib_r13_rcx_disp32, sib_r13_rdx_disp32, sib_r13_rbx_disp32, sib_r13_rsp_disp32, sib_r13_rbp_disp32, sib_r13_rsi_disp32, sib_r13_rdi_disp32, sib_r13_r8_disp32, sib_r13_r9_disp32, sib_r13_r10_disp32, sib_r13_r11_disp32, sib_r13_r12_disp32, sib_r13_r13_disp32, sib_r13_r14_disp32, sib_r13_r15_disp32, 
		sib_r14_rax_disp32, sib_r14_rcx_disp32, sib_r14_rdx_disp32, sib_r14_rbx_disp32, sib_r14_rsp_disp32, sib_r14_rbp_disp32, sib_r14_rsi_disp32, sib_r14_rdi_disp32, sib_r14_r8_disp32, sib_r14_r9_disp32, sib_r14_r10_disp32, sib_r14_r11_disp32, sib_r14_r12_disp32, sib_r14_r13_disp32, sib_r14_r14_disp32, sib_r14_r15_disp32, 
		sib_r15_rax_disp32, sib_r15_rcx_disp32, sib_r15_rdx_disp32, sib_r15_rbx_disp32, sib_r15_rsp_disp32, sib_r15_rbp_disp32, sib_r15_rsi_disp32, sib_r15_rdi_disp32, sib_r15_r8_disp32, sib_r15_r9_disp32, sib_r15_r10_disp32, sib_r15_r11_disp32, sib_r15_r12_disp32, sib_r15_r13_disp32, sib_r15_r14_disp32, sib_r15_r15_disp32, 
		MemSib64Scale1Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale2Disp32Start,	 // Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_2_rax_disp32, sib_rax_2_rcx_disp32, sib_rax_2_rdx_disp32, sib_rax_2_rbx_disp32, sib_rax_2_rsp_disp32, sib_rax_2_rbp_disp32, sib_rax_2_rsi_disp32, sib_rax_2_rdi_disp32, sib_rax_2_r8_disp32, sib_rax_2_r9_disp32, sib_rax_2_r10_disp32, sib_rax_2_r11_disp32, sib_rax_2_r12_disp32, sib_rax_2_r13_disp32, sib_rax_2_r14_disp32, sib_rax_2_r15_disp32,
		sib_rcx_2_rax_disp32, sib_rcx_2_rcx_disp32, sib_rcx_2_rdx_disp32, sib_rcx_2_rbx_disp32, sib_rcx_2_rsp_disp32, sib_rcx_2_rbp_disp32, sib_rcx_2_rsi_disp32, sib_rcx_2_rdi_disp32, sib_rcx_2_r8_disp32, sib_rcx_2_r9_disp32, sib_rcx_2_r10_disp32, sib_rcx_2_r11_disp32, sib_rcx_2_r12_disp32, sib_rcx_2_r13_disp32, sib_rcx_2_r14_disp32, sib_rcx_2_r15_disp32,
		sib_rdx_2_rax_disp32, sib_rdx_2_rcx_disp32, sib_rdx_2_rdx_disp32, sib_rdx_2_rbx_disp32, sib_rdx_2_rsp_disp32, sib_rdx_2_rbp_disp32, sib_rdx_2_rsi_disp32, sib_rdx_2_rdi_disp32, sib_rdx_2_r8_disp32, sib_rdx_2_r9_disp32, sib_rdx_2_r10_disp32, sib_rdx_2_r11_disp32, sib_rdx_2_r12_disp32, sib_rdx_2_r13_disp32, sib_rdx_2_r14_disp32, sib_rdx_2_r15_disp32,
		sib_rbx_2_rax_disp32, sib_rbx_2_rcx_disp32, sib_rbx_2_rdx_disp32, sib_rbx_2_rbx_disp32, sib_rbx_2_rsp_disp32, sib_rbx_2_rbp_disp32, sib_rbx_2_rsi_disp32, sib_rbx_2_rdi_disp32, sib_rbx_2_r8_disp32, sib_rbx_2_r9_disp32, sib_rbx_2_r10_disp32, sib_rbx_2_r11_disp32, sib_rbx_2_r12_disp32, sib_rbx_2_r13_disp32, sib_rbx_2_r14_disp32, sib_rbx_2_r15_disp32,
		sib_none_2_rax_disp32, sib_none_2_rcx_disp32, sib_none_2_rdx_disp32, sib_none_2_rbx_disp32, sib_none_2_rsp_disp32, sib_none_2_rbp_disp32, sib_none_2_rsi_disp32, sib_none_2_rdi_disp32, sib_none_2_r8_disp32, sib_none_2_r9_disp32, sib_none_2_r10_disp32, sib_none_2_r11_disp32, sib_none_2_r12_disp32, sib_none_2_r13_disp32, sib_none_2_r14_disp32, sib_none_2_r15_disp32,
		sib_rbp_2_rax_disp32, sib_rbp_2_rcx_disp32, sib_rbp_2_rdx_disp32, sib_rbp_2_rbx_disp32, sib_rbp_2_rsp_disp32, sib_rbp_2_rbp_disp32, sib_rbp_2_rsi_disp32, sib_rbp_2_rdi_disp32, sib_rbp_2_r8_disp32, sib_rbp_2_r9_disp32, sib_rbp_2_r10_disp32, sib_rbp_2_r11_disp32, sib_rbp_2_r12_disp32, sib_rbp_2_r13_disp32, sib_rbp_2_r14_disp32, sib_rbp_2_r15_disp32,
		sib_rsi_2_rax_disp32, sib_rsi_2_rcx_disp32, sib_rsi_2_rdx_disp32, sib_rsi_2_rbx_disp32, sib_rsi_2_rsp_disp32, sib_rsi_2_rbp_disp32, sib_rsi_2_rsi_disp32, sib_rsi_2_rdi_disp32, sib_rsi_2_r8_disp32, sib_rsi_2_r9_disp32, sib_rsi_2_r10_disp32, sib_rsi_2_r11_disp32, sib_rsi_2_r12_disp32, sib_rsi_2_r13_disp32, sib_rsi_2_r14_disp32, sib_rsi_2_r15_disp32,
		sib_rdi_2_rax_disp32, sib_rdi_2_rcx_disp32, sib_rdi_2_rdx_disp32, sib_rdi_2_rbx_disp32, sib_rdi_2_rsp_disp32, sib_rdi_2_rbp_disp32, sib_rdi_2_rsi_disp32, sib_rdi_2_rdi_disp32, sib_rdi_2_r8_disp32, sib_rdi_2_r9_disp32, sib_rdi_2_r10_disp32, sib_rdi_2_r11_disp32, sib_rdi_2_r12_disp32, sib_rdi_2_r13_disp32, sib_rdi_2_r14_disp32, sib_rdi_2_r15_disp32,
		sib_r8_2_rax_disp32, sib_r8_2_rcx_disp32, sib_r8_2_rdx_disp32, sib_r8_2_rbx_disp32, sib_r8_2_rsp_disp32, sib_r8_2_rbp_disp32, sib_r8_2_rsi_disp32,  sib_r8_2_rdi_disp32,  sib_r8_2_r8_disp32,  sib_r8_2_r9_disp32,  sib_r8_2_r10_disp32,  sib_r8_2_r11_disp32,  sib_r8_2_r12_disp32,  sib_r8_2_r13_disp32,  sib_r8_2_r14_disp32,  sib_r8_2_r15_disp32,
		sib_r9_2_rax_disp32, sib_r9_2_rcx_disp32, sib_r9_2_rdx_disp32, sib_r9_2_rbx_disp32, sib_r9_2_rsp_disp32, sib_r9_2_rbp_disp32, sib_r9_2_rsi_disp32,  sib_r9_2_rdi_disp32,  sib_r9_2_r8_disp32,  sib_r9_2_r9_disp32,  sib_r9_2_r10_disp32,  sib_r9_2_r11_disp32,  sib_r9_2_r12_disp32,  sib_r9_2_r13_disp32,  sib_r9_2_r14_disp32,  sib_r9_2_r15_disp32,
		sib_r10_2_rax_disp32, sib_r10_2_rcx_disp32, sib_r10_2_rdx_disp32, sib_r10_2_rbx_disp32, sib_r10_2_rsp_disp32, sib_r10_2_rbp_disp32, sib_r10_2_rsi_disp32, sib_r10_2_rdi_disp32, sib_r10_2_r8_disp32, sib_r10_2_r9_disp32, sib_r10_2_r10_disp32, sib_r10_2_r11_disp32, sib_r10_2_r12_disp32, sib_r10_2_r13_disp32, sib_r10_2_r14_disp32, sib_r10_2_r15_disp32,
		sib_r11_2_rax_disp32, sib_r11_2_rcx_disp32, sib_r11_2_rdx_disp32, sib_r11_2_rbx_disp32, sib_r11_2_rsp_disp32, sib_r11_2_rbp_disp32, sib_r11_2_rsi_disp32, sib_r11_2_rdi_disp32, sib_r11_2_r8_disp32, sib_r11_2_r9_disp32, sib_r11_2_r10_disp32, sib_r11_2_r11_disp32, sib_r11_2_r12_disp32, sib_r11_2_r13_disp32, sib_r11_2_r14_disp32, sib_r11_2_r15_disp32,
		sib_r12_2_rax_disp32, sib_r12_2_rcx_disp32, sib_r12_2_rdx_disp32, sib_r12_2_rbx_disp32, sib_r12_2_rsp_disp32, sib_r12_2_rbp_disp32, sib_r12_2_rsi_disp32, sib_r12_2_rdi_disp32, sib_r12_2_r8_disp32, sib_r12_2_r9_disp32, sib_r12_2_r10_disp32, sib_r12_2_r11_disp32, sib_r12_2_r12_disp32, sib_r12_2_r13_disp32, sib_r12_2_r14_disp32, sib_r12_2_r15_disp32,
		sib_r13_2_rax_disp32, sib_r13_2_rcx_disp32, sib_r13_2_rdx_disp32, sib_r13_2_rbx_disp32, sib_r13_2_rsp_disp32, sib_r13_2_rbp_disp32, sib_r13_2_rsi_disp32, sib_r13_2_rdi_disp32, sib_r13_2_r8_disp32, sib_r13_2_r9_disp32, sib_r13_2_r10_disp32, sib_r13_2_r11_disp32, sib_r13_2_r12_disp32, sib_r13_2_r13_disp32, sib_r13_2_r14_disp32, sib_r13_2_r15_disp32,
		sib_r14_2_rax_disp32, sib_r14_2_rcx_disp32, sib_r14_2_rdx_disp32, sib_r14_2_rbx_disp32, sib_r14_2_rsp_disp32, sib_r14_2_rbp_disp32, sib_r14_2_rsi_disp32, sib_r14_2_rdi_disp32, sib_r14_2_r8_disp32, sib_r14_2_r9_disp32, sib_r14_2_r10_disp32, sib_r14_2_r11_disp32, sib_r14_2_r12_disp32, sib_r14_2_r13_disp32, sib_r14_2_r14_disp32, sib_r14_2_r15_disp32,
		sib_r15_2_rax_disp32, sib_r15_2_rcx_disp32, sib_r15_2_rdx_disp32, sib_r15_2_rbx_disp32, sib_r15_2_rsp_disp32, sib_r15_2_rbp_disp32, sib_r15_2_rsi_disp32, sib_r15_2_rdi_disp32, sib_r15_2_r8_disp32, sib_r15_2_r9_disp32, sib_r15_2_r10_disp32, sib_r15_2_r11_disp32, sib_r15_2_r12_disp32, sib_r15_2_r13_disp32, sib_r15_2_r14_disp32, sib_r15_2_r15_disp32,
		MemSib64Scale2Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale4Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_4_rax_disp32, sib_rax_4_rcx_disp32, sib_rax_4_rdx_disp32, sib_rax_4_rbx_disp32, sib_rax_4_rsp_disp32, sib_rax_4_rbp_disp32, sib_rax_4_rsi_disp32, sib_rax_4_rdi_disp32, sib_rax_4_r8_disp32, sib_rax_4_r9_disp32, sib_rax_4_r10_disp32, sib_rax_4_r11_disp32, sib_rax_4_r12_disp32, sib_rax_4_r13_disp32, sib_rax_4_r14_disp32, sib_rax_4_r15_disp32,
		sib_rcx_4_rax_disp32, sib_rcx_4_rcx_disp32, sib_rcx_4_rdx_disp32, sib_rcx_4_rbx_disp32, sib_rcx_4_rsp_disp32, sib_rcx_4_rbp_disp32, sib_rcx_4_rsi_disp32, sib_rcx_4_rdi_disp32, sib_rcx_4_r8_disp32, sib_rcx_4_r9_disp32, sib_rcx_4_r10_disp32, sib_rcx_4_r11_disp32, sib_rcx_4_r12_disp32, sib_rcx_4_r13_disp32, sib_rcx_4_r14_disp32, sib_rcx_4_r15_disp32,
		sib_rdx_4_rax_disp32, sib_rdx_4_rcx_disp32, sib_rdx_4_rdx_disp32, sib_rdx_4_rbx_disp32, sib_rdx_4_rsp_disp32, sib_rdx_4_rbp_disp32, sib_rdx_4_rsi_disp32, sib_rdx_4_rdi_disp32, sib_rdx_4_r8_disp32, sib_rdx_4_r9_disp32, sib_rdx_4_r10_disp32, sib_rdx_4_r11_disp32, sib_rdx_4_r12_disp32, sib_rdx_4_r13_disp32, sib_rdx_4_r14_disp32, sib_rdx_4_r15_disp32,
		sib_rbx_4_rax_disp32, sib_rbx_4_rcx_disp32, sib_rbx_4_rdx_disp32, sib_rbx_4_rbx_disp32, sib_rbx_4_rsp_disp32, sib_rbx_4_rbp_disp32, sib_rbx_4_rsi_disp32, sib_rbx_4_rdi_disp32, sib_rbx_4_r8_disp32, sib_rbx_4_r9_disp32, sib_rbx_4_r10_disp32, sib_rbx_4_r11_disp32, sib_rbx_4_r12_disp32, sib_rbx_4_r13_disp32, sib_rbx_4_r14_disp32, sib_rbx_4_r15_disp32,
		sib_none_4_rax_disp32, sib_none_4_rcx_disp32, sib_none_4_rdx_disp32, sib_none_4_rbx_disp32, sib_none_4_rsp_disp32, sib_none_4_rbp_disp32, sib_none_4_rsi_disp32, sib_none_4_rdi_disp32, sib_none_4_r8_disp32, sib_none_4_r9_disp32, sib_none_4_r10_disp32, sib_none_4_r11_disp32, sib_none_4_r12_disp32, sib_none_4_r13_disp32, sib_none_4_r14_disp32, sib_none_4_r15_disp32,
		sib_rbp_4_rax_disp32, sib_rbp_4_rcx_disp32, sib_rbp_4_rdx_disp32, sib_rbp_4_rbx_disp32, sib_rbp_4_rsp_disp32, sib_rbp_4_rbp_disp32, sib_rbp_4_rsi_disp32, sib_rbp_4_rdi_disp32, sib_rbp_4_r8_disp32, sib_rbp_4_r9_disp32, sib_rbp_4_r10_disp32, sib_rbp_4_r11_disp32, sib_rbp_4_r12_disp32, sib_rbp_4_r13_disp32, sib_rbp_4_r14_disp32, sib_rbp_4_r15_disp32,
		sib_rsi_4_rax_disp32, sib_rsi_4_rcx_disp32, sib_rsi_4_rdx_disp32, sib_rsi_4_rbx_disp32, sib_rsi_4_rsp_disp32, sib_rsi_4_rbp_disp32, sib_rsi_4_rsi_disp32, sib_rsi_4_rdi_disp32, sib_rsi_4_r8_disp32, sib_rsi_4_r9_disp32, sib_rsi_4_r10_disp32, sib_rsi_4_r11_disp32, sib_rsi_4_r12_disp32, sib_rsi_4_r13_disp32, sib_rsi_4_r14_disp32, sib_rsi_4_r15_disp32,
		sib_rdi_4_rax_disp32, sib_rdi_4_rcx_disp32, sib_rdi_4_rdx_disp32, sib_rdi_4_rbx_disp32, sib_rdi_4_rsp_disp32, sib_rdi_4_rbp_disp32, sib_rdi_4_rsi_disp32, sib_rdi_4_rdi_disp32, sib_rdi_4_r8_disp32, sib_rdi_4_r9_disp32, sib_rdi_4_r10_disp32, sib_rdi_4_r11_disp32, sib_rdi_4_r12_disp32, sib_rdi_4_r13_disp32, sib_rdi_4_r14_disp32, sib_rdi_4_r15_disp32,
		sib_r8_4_rax_disp32, sib_r8_4_rcx_disp32, sib_r8_4_rdx_disp32, sib_r8_4_rbx_disp32, sib_r8_4_rsp_disp32, sib_r8_4_rbp_disp32, sib_r8_4_rsi_disp32,  sib_r8_4_rdi_disp32,  sib_r8_4_r8_disp32,  sib_r8_4_r9_disp32,  sib_r8_4_r10_disp32,  sib_r8_4_r11_disp32,  sib_r8_4_r12_disp32,  sib_r8_4_r13_disp32,  sib_r8_4_r14_disp32,  sib_r8_4_r15_disp32,
		sib_r9_4_rax_disp32, sib_r9_4_rcx_disp32, sib_r9_4_rdx_disp32, sib_r9_4_rbx_disp32, sib_r9_4_rsp_disp32, sib_r9_4_rbp_disp32, sib_r9_4_rsi_disp32,  sib_r9_4_rdi_disp32,  sib_r9_4_r8_disp32,  sib_r9_4_r9_disp32,  sib_r9_4_r10_disp32,  sib_r9_4_r11_disp32,  sib_r9_4_r12_disp32,  sib_r9_4_r13_disp32,  sib_r9_4_r14_disp32,  sib_r9_4_r15_disp32,
		sib_r10_4_rax_disp32, sib_r10_4_rcx_disp32, sib_r10_4_rdx_disp32, sib_r10_4_rbx_disp32, sib_r10_4_rsp_disp32, sib_r10_4_rbp_disp32, sib_r10_4_rsi_disp32, sib_r10_4_rdi_disp32, sib_r10_4_r8_disp32, sib_r10_4_r9_disp32, sib_r10_4_r10_disp32, sib_r10_4_r11_disp32, sib_r10_4_r12_disp32, sib_r10_4_r13_disp32, sib_r10_4_r14_disp32, sib_r10_4_r15_disp32,
		sib_r11_4_rax_disp32, sib_r11_4_rcx_disp32, sib_r11_4_rdx_disp32, sib_r11_4_rbx_disp32, sib_r11_4_rsp_disp32, sib_r11_4_rbp_disp32, sib_r11_4_rsi_disp32, sib_r11_4_rdi_disp32, sib_r11_4_r8_disp32, sib_r11_4_r9_disp32, sib_r11_4_r10_disp32, sib_r11_4_r11_disp32, sib_r11_4_r12_disp32, sib_r11_4_r13_disp32, sib_r11_4_r14_disp32, sib_r11_4_r15_disp32,
		sib_r12_4_rax_disp32, sib_r12_4_rcx_disp32, sib_r12_4_rdx_disp32, sib_r12_4_rbx_disp32, sib_r12_4_rsp_disp32, sib_r12_4_rbp_disp32, sib_r12_4_rsi_disp32, sib_r12_4_rdi_disp32, sib_r12_4_r8_disp32, sib_r12_4_r9_disp32, sib_r12_4_r10_disp32, sib_r12_4_r11_disp32, sib_r12_4_r12_disp32, sib_r12_4_r13_disp32, sib_r12_4_r14_disp32, sib_r12_4_r15_disp32,
		sib_r13_4_rax_disp32, sib_r13_4_rcx_disp32, sib_r13_4_rdx_disp32, sib_r13_4_rbx_disp32, sib_r13_4_rsp_disp32, sib_r13_4_rbp_disp32, sib_r13_4_rsi_disp32, sib_r13_4_rdi_disp32, sib_r13_4_r8_disp32, sib_r13_4_r9_disp32, sib_r13_4_r10_disp32, sib_r13_4_r11_disp32, sib_r13_4_r12_disp32, sib_r13_4_r13_disp32, sib_r13_4_r14_disp32, sib_r13_4_r15_disp32,
		sib_r14_4_rax_disp32, sib_r14_4_rcx_disp32, sib_r14_4_rdx_disp32, sib_r14_4_rbx_disp32, sib_r14_4_rsp_disp32, sib_r14_4_rbp_disp32, sib_r14_4_rsi_disp32, sib_r14_4_rdi_disp32, sib_r14_4_r8_disp32, sib_r14_4_r9_disp32, sib_r14_4_r10_disp32, sib_r14_4_r11_disp32, sib_r14_4_r12_disp32, sib_r14_4_r13_disp32, sib_r14_4_r14_disp32, sib_r14_4_r15_disp32,
		sib_r15_4_rax_disp32, sib_r15_4_rcx_disp32, sib_r15_4_rdx_disp32, sib_r15_4_rbx_disp32, sib_r15_4_rsp_disp32, sib_r15_4_rbp_disp32, sib_r15_4_rsi_disp32, sib_r15_4_rdi_disp32, sib_r15_4_r8_disp32, sib_r15_4_r9_disp32, sib_r15_4_r10_disp32, sib_r15_4_r11_disp32, sib_r15_4_r12_disp32, sib_r15_4_r13_disp32, sib_r15_4_r14_disp32, sib_r15_4_r15_disp32,
		MemSib64Scale4Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 

		MemSib64Scale8Disp32Start,	// Special constant to quickly define the category of a parameter. Do not use. 
		sib_rax_8_rax_disp32, sib_rax_8_rcx_disp32, sib_rax_8_rdx_disp32, sib_rax_8_rbx_disp32, sib_rax_8_rsp_disp32, sib_rax_8_rbp_disp32, sib_rax_8_rsi_disp32, sib_rax_8_rdi_disp32, sib_rax_8_r8_disp32, sib_rax_8_r9_disp32, sib_rax_8_r10_disp32, sib_rax_8_r11_disp32, sib_rax_8_r12_disp32, sib_rax_8_r13_disp32, sib_rax_8_r14_disp32, sib_rax_8_r15_disp32,
		sib_rcx_8_rax_disp32, sib_rcx_8_rcx_disp32, sib_rcx_8_rdx_disp32, sib_rcx_8_rbx_disp32, sib_rcx_8_rsp_disp32, sib_rcx_8_rbp_disp32, sib_rcx_8_rsi_disp32, sib_rcx_8_rdi_disp32, sib_rcx_8_r8_disp32, sib_rcx_8_r9_disp32, sib_rcx_8_r10_disp32, sib_rcx_8_r11_disp32, sib_rcx_8_r12_disp32, sib_rcx_8_r13_disp32, sib_rcx_8_r14_disp32, sib_rcx_8_r15_disp32,
		sib_rdx_8_rax_disp32, sib_rdx_8_rcx_disp32, sib_rdx_8_rdx_disp32, sib_rdx_8_rbx_disp32, sib_rdx_8_rsp_disp32, sib_rdx_8_rbp_disp32, sib_rdx_8_rsi_disp32, sib_rdx_8_rdi_disp32, sib_rdx_8_r8_disp32, sib_rdx_8_r9_disp32, sib_rdx_8_r10_disp32, sib_rdx_8_r11_disp32, sib_rdx_8_r12_disp32, sib_rdx_8_r13_disp32, sib_rdx_8_r14_disp32, sib_rdx_8_r15_disp32,
		sib_rbx_8_rax_disp32, sib_rbx_8_rcx_disp32, sib_rbx_8_rdx_disp32, sib_rbx_8_rbx_disp32, sib_rbx_8_rsp_disp32, sib_rbx_8_rbp_disp32, sib_rbx_8_rsi_disp32, sib_rbx_8_rdi_disp32, sib_rbx_8_r8_disp32, sib_rbx_8_r9_disp32, sib_rbx_8_r10_disp32, sib_rbx_8_r11_disp32, sib_rbx_8_r12_disp32, sib_rbx_8_r13_disp32, sib_rbx_8_r14_disp32, sib_rbx_8_r15_disp32,
		sib_none_8_rax_disp32, sib_none_8_rcx_disp32, sib_none_8_rdx_disp32, sib_none_8_rbx_disp32, sib_none_8_rsp_disp32, sib_none_8_rbp_disp32, sib_none_8_rsi_disp32, sib_none_8_rdi_disp32, sib_none_8_r8_disp32, sib_none_8_r9_disp32, sib_none_8_r10_disp32, sib_none_8_r11_disp32, sib_none_8_r12_disp32, sib_none_8_r13_disp32, sib_none_8_r14_disp32, sib_none_8_r15_disp32,
		sib_rbp_8_rax_disp32, sib_rbp_8_rcx_disp32, sib_rbp_8_rdx_disp32, sib_rbp_8_rbx_disp32, sib_rbp_8_rsp_disp32, sib_rbp_8_rbp_disp32, sib_rbp_8_rsi_disp32, sib_rbp_8_rdi_disp32, sib_rbp_8_r8_disp32, sib_rbp_8_r9_disp32, sib_rbp_8_r10_disp32, sib_rbp_8_r11_disp32, sib_rbp_8_r12_disp32, sib_rbp_8_r13_disp32, sib_rbp_8_r14_disp32, sib_rbp_8_r15_disp32,
		sib_rsi_8_rax_disp32, sib_rsi_8_rcx_disp32, sib_rsi_8_rdx_disp32, sib_rsi_8_rbx_disp32, sib_rsi_8_rsp_disp32, sib_rsi_8_rbp_disp32, sib_rsi_8_rsi_disp32, sib_rsi_8_rdi_disp32, sib_rsi_8_r8_disp32, sib_rsi_8_r9_disp32, sib_rsi_8_r10_disp32, sib_rsi_8_r11_disp32, sib_rsi_8_r12_disp32, sib_rsi_8_r13_disp32, sib_rsi_8_r14_disp32, sib_rsi_8_r15_disp32,
		sib_rdi_8_rax_disp32, sib_rdi_8_rcx_disp32, sib_rdi_8_rdx_disp32, sib_rdi_8_rbx_disp32, sib_rdi_8_rsp_disp32, sib_rdi_8_rbp_disp32, sib_rdi_8_rsi_disp32, sib_rdi_8_rdi_disp32, sib_rdi_8_r8_disp32, sib_rdi_8_r9_disp32, sib_rdi_8_r10_disp32, sib_rdi_8_r11_disp32, sib_rdi_8_r12_disp32, sib_rdi_8_r13_disp32, sib_rdi_8_r14_disp32, sib_rdi_8_r15_disp32,
		sib_r8_8_rax_disp32, sib_r8_8_rcx_disp32, sib_r8_8_rdx_disp32, sib_r8_8_rbx_disp32, sib_r8_8_rsp_disp32, sib_r8_8_rbp_disp32, sib_r8_8_rsi_disp32,  sib_r8_8_rdi_disp32,  sib_r8_8_r8_disp32,  sib_r8_8_r9_disp32,  sib_r8_8_r10_disp32,  sib_r8_8_r11_disp32,  sib_r8_8_r12_disp32,  sib_r8_8_r13_disp32,  sib_r8_8_r14_disp32,  sib_r8_8_r15_disp32,
		sib_r9_8_rax_disp32, sib_r9_8_rcx_disp32, sib_r9_8_rdx_disp32, sib_r9_8_rbx_disp32, sib_r9_8_rsp_disp32, sib_r9_8_rbp_disp32, sib_r9_8_rsi_disp32,  sib_r9_8_rdi_disp32,  sib_r9_8_r8_disp32,  sib_r9_8_r9_disp32,  sib_r9_8_r10_disp32,  sib_r9_8_r11_disp32,  sib_r9_8_r12_disp32,  sib_r9_8_r13_disp32,  sib_r9_8_r14_disp32,  sib_r9_8_r15_disp32,
		sib_r10_8_rax_disp32, sib_r10_8_rcx_disp32, sib_r10_8_rdx_disp32, sib_r10_8_rbx_disp32, sib_r10_8_rsp_disp32, sib_r10_8_rbp_disp32, sib_r10_8_rsi_disp32, sib_r10_8_rdi_disp32, sib_r10_8_r8_disp32, sib_r10_8_r9_disp32, sib_r10_8_r10_disp32, sib_r10_8_r11_disp32, sib_r10_8_r12_disp32, sib_r10_8_r13_disp32, sib_r10_8_r14_disp32, sib_r10_8_r15_disp32,
		sib_r11_8_rax_disp32, sib_r11_8_rcx_disp32, sib_r11_8_rdx_disp32, sib_r11_8_rbx_disp32, sib_r11_8_rsp_disp32, sib_r11_8_rbp_disp32, sib_r11_8_rsi_disp32, sib_r11_8_rdi_disp32, sib_r11_8_r8_disp32, sib_r11_8_r9_disp32, sib_r11_8_r10_disp32, sib_r11_8_r11_disp32, sib_r11_8_r12_disp32, sib_r11_8_r13_disp32, sib_r11_8_r14_disp32, sib_r11_8_r15_disp32,
		sib_r12_8_rax_disp32, sib_r12_8_rcx_disp32, sib_r12_8_rdx_disp32, sib_r12_8_rbx_disp32, sib_r12_8_rsp_disp32, sib_r12_8_rbp_disp32, sib_r12_8_rsi_disp32, sib_r12_8_rdi_disp32, sib_r12_8_r8_disp32, sib_r12_8_r9_disp32, sib_r12_8_r10_disp32, sib_r12_8_r11_disp32, sib_r12_8_r12_disp32, sib_r12_8_r13_disp32, sib_r12_8_r14_disp32, sib_r12_8_r15_disp32,
		sib_r13_8_rax_disp32, sib_r13_8_rcx_disp32, sib_r13_8_rdx_disp32, sib_r13_8_rbx_disp32, sib_r13_8_rsp_disp32, sib_r13_8_rbp_disp32, sib_r13_8_rsi_disp32, sib_r13_8_rdi_disp32, sib_r13_8_r8_disp32, sib_r13_8_r9_disp32, sib_r13_8_r10_disp32, sib_r13_8_r11_disp32, sib_r13_8_r12_disp32, sib_r13_8_r13_disp32, sib_r13_8_r14_disp32, sib_r13_8_r15_disp32,
		sib_r14_8_rax_disp32, sib_r14_8_rcx_disp32, sib_r14_8_rdx_disp32, sib_r14_8_rbx_disp32, sib_r14_8_rsp_disp32, sib_r14_8_rbp_disp32, sib_r14_8_rsi_disp32, sib_r14_8_rdi_disp32, sib_r14_8_r8_disp32, sib_r14_8_r9_disp32, sib_r14_8_r10_disp32, sib_r14_8_r11_disp32, sib_r14_8_r12_disp32, sib_r14_8_r13_disp32, sib_r14_8_r14_disp32, sib_r14_8_r15_disp32,
		sib_r15_8_rax_disp32, sib_r15_8_rcx_disp32, sib_r15_8_rdx_disp32, sib_r15_8_rbx_disp32, sib_r15_8_rsp_disp32, sib_r15_8_rbp_disp32, sib_r15_8_rsi_disp32, sib_r15_8_rdi_disp32, sib_r15_8_r8_disp32, sib_r15_8_r9_disp32, sib_r15_8_r10_disp32, sib_r15_8_r11_disp32, sib_r15_8_r12_disp32, sib_r15_8_r13_disp32, sib_r15_8_r14_disp32, sib_r15_8_r15_disp32,
		MemSib64Scale8Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib64Disp32End,	// Special constant to quickly define the category of a parameter. Do not use. 
		MemSib64End,	// Special constant to quickly define the category of a parameter. Do not use. 

		SibEnd,				// Special constant to quickly define the category of a parameter. Do not use. 

		MemEnd,				// Special constant to quickly define the category of a parameter. Do not use. 

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
	/// A special hint for instructions in which it is impossible to understand the size of the addressable memory from the parameter.
	/// For example `dec byte ptr [bx]` and `dec word ptr [bx]` are encoded by different opcodes, but without this hint it is impossible to do this.
	/// In fact, this is a crutch for the crutchy x86 architecture.
	/// Take it steady, calm and cool. Architecture is soon 50 years old, it will not stand up to your criticism. 
	/// </summary>
	enum class PtrHint : size_t
	{
		NoHint = 0,
		BytePtr,
		WordPtr,
		DwordPtr,
		QwordPtr,
		XwordPtr,		// m80fp
		M14Ptr, M28Ptr,		// m14/28byte (FPU)
		M94Ptr, M108Ptr,	// m14/28byte (FPU)
	};

	/// <summary>
	/// The structure contains all information about the instruction, including possible prefixes and a parameter list.
	/// This is a deliberate abstraction from the very alien definition of ModRM. All possible combinations of parameters are specified by the Param enumeration.
	/// </summary>
	struct AnalyzeInfo
	{
		size_t clearingPaddy;

		/// <summary>
		/// It is set by the analyzer, for other cases it is not necessary to set it. 
		/// </summary>
		Category category;

		// When analyzing the flow of instructions, prefixes are separated from instruction,
		// so the total size of the code batch will be equal to the size of all prefixes + the size of the instruction itself. 

		/// <summary>
		/// An input prefix list that is used by the assembler to form the output byte array and other purposes. 
		/// </summary>
		Prefix prefixes[PrefixMaxSize];
		size_t numPrefixes;

		/// <summary>
		/// Raw array of bytes (encoded prefixes).
		/// </summary>
		uint8_t prefixBytes[PrefixMaxSize];
		size_t prefixSize;

		/// <summary>
		/// The instruction to which the given structure corresponds. 
		/// </summary>
		Instruction instr;

		/// <summary>
		/// Instruction encoded bytes. The assembler generates instruction bytes based on the parameters and the instruction type. The size is determined by the `instrSize` property. 
		/// </summary>
		uint8_t instrBytes[InstrMaxSize];
		size_t instrSize;

		/// <summary>
		/// List of instruction parameters. The number of parameters is determined by the `numParams` property. 
		/// </summary>
		Param params[ParamsMax];
		size_t numParams;

		/// <summary>
		/// Some instructions contain an offset (displacement) as part of one of the parameters. The offset can be one of disp8, disp16, or disp32. 
		/// </summary>
		union
		{
			uint8_t disp8;
			uint16_t disp16;
			uint32_t disp32;
			uint64_t disp64;
		} Disp;

		/// <summary>
		/// The instruction can contain an immediate parameter.
		/// </summary>
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

		/// <summary>
		/// A special hint for instructions in which it is impossible to understand the size of the addressable memory from the parameter.
		/// </summary>
		PtrHint ptrHint;
	};

}
