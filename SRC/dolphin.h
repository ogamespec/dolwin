// general include file for whole project. must be included first.

#pragma once

// ---------------------------------------------------------------------------
// compiler and SDK include files.

#include <assert.h>
#include <stdint.h>
#include <direct.h>
#include <setjmp.h>
#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <commctrl.h>
#include <intrin.h>
#include "resource.h"

// ---------------------------------------------------------------------------
// compile-time triggers.

// version info, used everywhere in emu.
#define APPNAME     "Dolwin"
#define APPDESC     "Nintendo Gamecube Emulator for Windows"
#define APPVER      "0.11"

// ---------------------------------------------------------------------------
// Dolwin includes

#include "Core/Memory.h"
#include "Core/Gekko.h"
#include "Core/Interpreter.h"
#include "Hardware/Hardware.h"
#include "HighLevel/HighLevel.h"
#include "Debugger/Debugger.h"
#include "UserMenu/User.h"
