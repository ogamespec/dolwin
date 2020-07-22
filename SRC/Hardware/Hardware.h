// GC hardware includes

#pragma once

// Config from Ui

#include <tchar.h>

struct HWConfig
{
    // MI
    size_t      ramsize;

    // VI
	void *	    renderTarget;
    bool        vi_log;
    bool        vi_xfb;
    int         videoEncoderFuse;       // 1 - PAL, 0 - NTSC

    // PI
    uint32_t    consoleVer;
    bool        rswhack;

    // EI
    bool        exi_log;
    bool        exi_osReport;
    TCHAR       ansiFilename[0x1000];
    TCHAR       sjisFilename[0x1000];

    // MC
    bool        MemcardA_Connected;
    bool        MemcardB_Connected;
    TCHAR       MemcardA_Filename[0x1000];
    TCHAR       MemcardB_Filename[0x1000];
    bool        Memcard_SyncSave;

    TCHAR       BootromFilename[0x1000];
    TCHAR       DspDromFilename[0x1000];
    TCHAR       DspIromFilename[0x1000];

};

#pragma region "Backends"

#ifdef _WINDOWS
#include "../Backends/DolwinVideo/GX.h"
#include "../Backends/PadSimpleWin32/PAD.h"
#include "../Backends/VideoGdi/VideoOut.h"
#include "../Backends/AudioDirectSound/AX.h"
#endif

#ifdef _PLAYGROUND
#include "../Backends/GraphicsNull/GX.h"
#include "../Backends/PadNull/PAD.h"
#include "../Backends/VideoNull/VideoOut.h"
#include "../Backends/AudioNull/AX.h"
#endif

#pragma endregion "Backends"

#include "../DVD/DVD.h"
#include "../DSP/DspCore.h"
#include "HW.h"
#include "EFB.h"
#include "AI.h"
#include "CP.h"
#include "VI.h"
#include "PI.h"
#include "MI.h"
#include "AR.h"
#include "DI.h"
#include "SI.h"
#include "EXI.h"
#include "MC.h"
#include "IPLDescrambler.h"
