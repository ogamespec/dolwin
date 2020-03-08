// Emulator controls
#include "dolphin.h"

// emulator state
Emulator emu;

// ---------------------------------------------------------------------------

void EMUGetHwConfig(HWConfig * config)
{
    config->ramsize = RAMSIZE;
    config->hwndMain = wnd.hMainWindow;

    config->vi_log = GetConfigInt(USER_VI_LOG, USER_VI_LOG_DEFAULT) & 1;
    config->vi_xfb = GetConfigInt(USER_VI_XFB, USER_VI_XFB_DEFAULT) & 1;
    config->vi_stretch = GetConfigInt(USER_VI_STRETCH, USER_VI_STRETCH_DEFAULT) & 1;
    config->vcount = GetConfigInt(USER_VI_COUNT, USER_VI_COUNT_DEFAULT);

    config->rswhack = GetConfigInt(USER_PI_RSWHACK, USER_PI_RSWHACK_DEFAULT) & 1;
    config->consoleVer = GetConfigInt(USER_CONSOLE, USER_CONSOLE_DEFAULT);

    config->exi_log = GetConfigInt(USER_EXI_LOG, USER_EXI_LOG_DEFAULT) & 1;
    config->exi_osReport = GetConfigInt(USER_OS_REPORT, USER_OS_REPORT_DEFAULT) & 1;
    config->exi_rtc = GetConfigInt(USER_RTC, USER_RTC_DEFAULT) & 1;

    strcpy(config->ansiFilename, GetConfigString(USER_ANSI, USER_ANSI_DEFAULT));
    strcpy(config->sjisFilename, GetConfigString(USER_SJIS, USER_SJIS_DEFAULT));

    config->MemcardA_Connected = GetConfigInt(MemcardA_Connected_Key, FALSE, HKEY_MEMCARD) & 1;
    config->MemcardB_Connected = GetConfigInt(MemcardB_Connected_Key, FALSE, HKEY_MEMCARD) & 1;
    strcpy(config->MemcardA_Filename, GetConfigString(MemcardA_Filename_Key, "*", HKEY_MEMCARD));
    strcpy(config->MemcardB_Filename, GetConfigString(MemcardB_Filename_Key, "*", HKEY_MEMCARD));
    config->Memcard_SyncSave = GetConfigInt(Memcard_SyncSave_Key, FALSE, HKEY_MEMCARD) & 1;

    config->gxpoll = GetConfigInt(USER_GX_POLL, USER_GX_POLL_DEFAULT) & 1;

    config->dspFakeMode = GetConfigInt(USER_DSP_FAKE, USER_DSP_FAKE_DEFAULT) & 1;

    config->one_second = cpu.one_second;
}

// this function is called once, during Dolwin life-time
void EMUInit()
{
    assert(!emu.running);
    if(emu.initok == true) return;

    MEMInit();
    CPUInit();
    MEMOpen(GetConfigInt(USER_MMU, USER_MMU_DEFAULT));
    MEMSelect(0, 0);

    emu.initok = true;
}

// this function is called last, during Dolwin life-time
void EMUDie()
{
    assert(!emu.running);
    if(emu.initok == false) return;

    CPUFini();
    MEMFini();

    emu.initok = false;
}

// this function calls every time, after user loading new file
void EMUOpen(int bailout, int delay, int counterFactor)
{
    if(emu.running == true) return;
    emu.running = true;

    OnMainWindowOpening();

    // open other sub-systems
    MEMOpen(GetConfigInt(USER_MMU, USER_MMU_DEFAULT));
    MEMSelect(mem.mmu, 0);
    CPUOpen(bailout, delay, counterFactor);
    assert(GXOpen(mem.ram, wnd.hMainWindow));
    assert(AXOpen());
    assert(PADOpen());

    HWConfig hwconfig = { 0 };
    EMUGetHwConfig(&hwconfig);
    HWOpen(&hwconfig);
    ReloadFile();   // PC will be set here
    HLEOpen();

    // debugger has its own core, to control CPU execution
    if (emu.doldebug)
    {
        CPUStart = DBStart;
        CPUException = DBException;
    }

    // take care about user interface
    OnMainWindowOpened();

    // start emulation!
    CPUStart();
}

// this function calls every time, after user stops emulation
void EMUClose()
{
    if(emu.running == false) return;
    emu.running = false;

    // take care about user interface
    OnMainWindowClosing();

    // close other sub-systems
    PADClose();
    AXClose();
    GXClose();
    HLEClose();
    HWClose();
    MEMClose();

    // take care about user interface
    OnMainWindowClosed();
}

// you can use EMUClose(), then EMUOpen() to reset emulator, 
// and reload last used file.
