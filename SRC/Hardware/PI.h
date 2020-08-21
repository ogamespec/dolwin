// Flipper Processor Interface (to Gekko)

// TODO: While exploring the Flipper architecture, I misunderstood the purpose of the PI and MEM (MI) components. 
// In fact, PI is used to access Flipper's memory and registers from the Gekko side. MEM is used by various Flipper subsystems to access main memory (1T-SRAM). 
// Now all memory access handlers are in the MI.cpp module, but in theory they should be in PI.cpp. Let's leave it as it is for now.

#pragma once

// Address spaces
#define PI_MEMSPACE_MAINMEM     0x0000'0000         // 1T-SRAM main memory
#define PI_MEMSPACE_EFB         0x0800'0000         // GX eFB base address
#define PI_REGSPACE_PE          0x0C00'1000         // GX Pixel Engine regs mapped to physical memory
#define PI_REGSPACE_GX_FIFO     0x0C00'8000         // GX streaming fifo

#define PI_REG8_TO_SPACE(space, id)     (space | ((uint32_t)(id)))
#define PI_REG16_TO_SPACE(space, id)    (space | ((uint32_t)(id) << 1))
#define PI_REG32_TO_SPACE(space, id)    (space | ((uint32_t)(id) << 2))

// Efb Z-plane select
#define PI_EFB_ZPLANE       0x0040'0000 

// Mask EFB address
#define PI_EFB_ADDRESS_MASK 0xFF80'0000

#define PI_INTSR            0x0C003000      // master interrupt reg
#define PI_INTMR            0x0C003004      // master interrupt mask
#define PI_BASE             0x0C00300C      // PI fifo base
#define PI_TOP              0x0C003010      // PI fifo top
#define PI_WRPTR            0x0C003014      // PI fifo write pointer
#define PI_RST_CODE         0x0C003024      // reset code (mentioned in patents as "PI General Reset Register")
#define PI_MB_REV           0x0C00302C      // console revision

// PI interrupt regs mask
#define PI_INTERRUPT_HSP        0x2000      // high-speed port
#define PI_INTERRUPT_DEBUG      0x1000      // debug hardware
#define PI_INTERRUPT_CP         0x0800      // command fifo
#define PI_INTERRUPT_PE_FINISH  0x0400      // PE finish command (draw done)
#define PI_INTERRUPT_PE_TOKEN   0x0200      // PE token parsed (draw sync)
#define PI_INTERRUPT_VI         0x0100      // 4 VI line ints (only first is used)
#define PI_INTERRUPT_MEM        0x0080      // memory protection failed
#define PI_INTERRUPT_DSP        0x0040      // various DSP (ARAM, AI FIFO, DSP)
#define PI_INTERRUPT_AI         0x0020      // DVD streaming trigger interrupt
#define PI_INTERRUPT_EXI        0x0010      // EXI transfer complete
#define PI_INTERRUPT_SI         0x0008      // serial interrupts
#define PI_INTERRUPT_DI         0x0004      // DVD cover, break, transfer complete
#define PI_INTERRUPT_RSW        0x0002      // reset "switch"
#define PI_INTERRUPT_ERROR      0x0001      // GP verify failed

// PI write pointer wrap bit
#define PI_WRPTR_WRAP   0x0400'0000

// ---------------------------------------------------------------------------
// hardware API

// PI state (registers and other data)
struct PIControl
{
    volatile uint32_t    intsr;          // interrupt cause
    volatile uint32_t    intmr;          // interrupt mask
    bool        rswhack;        // reset "switch" hack
    bool        log;            // log interrupts
    uint32_t    consoleVer;     // console version
    // PI FIFO
    volatile uint32_t    base;
    volatile uint32_t    top;
    volatile uint32_t    wrptr;          // also WRAP bit
};

extern  PIControl pi;

void    PIAssertInt(uint32_t mask);  // set interrupt(s)
void    PIClearInt(uint32_t mask);   // clear interrupt(s)
void    PIOpen(HWConfig * config);
void    DumpPIFIFO();
