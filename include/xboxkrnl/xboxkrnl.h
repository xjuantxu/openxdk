// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl.h
// *
// * note : XBox Kernel Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_H
#define XBOXKRNL_H

#if defined(__cplusplus)
extern "C"
{
#endif

// ******************************************************************
// * kernel exports, others import
// ******************************************************************
#ifndef _XBOXKRNL_INTERNAL_
#define NTSYSAPI __declspec( dllimport )
#else
#define NTSYSAPI __declspec( dllexport )
#endif

// ******************************************************************
// * Null
// ******************************************************************
#ifndef	NULL
#define NULL                0
#endif

// ******************************************************************
// * TRUE / FALSE
// ******************************************************************
#ifndef	FALSE
#define	FALSE	0
#endif
#ifndef	TRUE
#define	TRUE	1
#endif

// ******************************************************************
// * CONST
// ******************************************************************
#define CONST               const

// ******************************************************************
// * Basic types
// ******************************************************************
typedef char                CHAR;
typedef unsigned char       UCHAR;
typedef unsigned char       BYTE;
typedef unsigned char       BOOLEAN;
typedef unsigned short      USHORT;
typedef	unsigned short		WORD;
typedef unsigned long       ULONG;
typedef	unsigned long       DWORD;
typedef unsigned long       SIZE_T;
typedef unsigned long       ACCESS_MASK;
typedef unsigned long       PHYSICAL_ADDRESS;
typedef	long				LONG;
typedef long                INT_PTR;
typedef void                VOID;

// ******************************************************************
// * Pointer types
// ******************************************************************
typedef CHAR               *PCHAR;
typedef CHAR               *PCSZ;
typedef BYTE               *PBYTE;
typedef BOOLEAN            *PBOOLEAN;
typedef USHORT             *PUSHORT;
typedef ULONG              *PULONG;
typedef ACCESS_MASK        *PACCESS_MASK;
typedef LONG               *LONG_PTR;
typedef INT_PTR            *PINT_PTR;
typedef VOID               *PVOID;
typedef void               *HANDLE;
typedef HANDLE             *PHANDLE;

// ******************************************************************
// * NTSTATUS
// ******************************************************************
typedef long                NTSTATUS;

// ******************************************************************
// * calling conventions
// ******************************************************************
#define NTAPI               __stdcall
#define CDECL               __cdecl
#define DECLSPEC_NORETURN   __declspec( noreturn )

// ******************************************************************
// * documentation purposes only
// ******************************************************************
#define EXPORTNUM(a)
#define UNALIGNED
#define OPTIONAL
#define IN
#define OUT

// ******************************************************************
// * LARGE_INTEGER
// ******************************************************************
typedef struct _LARGE_INTEGER
{
    DWORD   LowPart;
    LONG    HighPart;
}
LARGE_INTEGER, *PLARGE_INTEGER;

// ******************************************************************
// * STRING
// ******************************************************************
typedef struct _STRING
{
    USHORT  Length;
    USHORT  MaximumLength;
    PCHAR   Buffer;
}
STRING, ANSI_STRING, *PSTRING, *PANSI_STRING;

// ******************************************************************
// * OBJECT_ATTRIBUTES
// ******************************************************************
typedef struct _OBJECT_ATTRIBUTES
{
    HANDLE  RootDirectory;
    PSTRING ObjectName;
    ULONG   Attributes;
}
OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

// ******************************************************************
// * BUS_DATA_TYPE
// ******************************************************************
typedef enum _BUS_DATA_TYPE
{
    ConfigurationSpaceUndefined = 0xFF,
    Cmos                        = 0x0,
    EisaConfiguration           = 0x1,
    Pos                         = 0x2,
    CbusConfiguration           = 0x3,
    PCIConfiguration            = 0x4,
    VMEConfiguration            = 0x5,
    NuBusConfiguration          = 0x6,
    PCMCIAConfiguration         = 0x7,
    MPIConfiguration            = 0x8,
    MPSAConfiguration           = 0x9,
    PNPISAConfiguration         = 0xA,
    SgiInternalConfiguration    = 0xB,
    MaximumBusDataType          = 0xC,
}
BUS_DATA_TYPE;

// ******************************************************************
// * PCI_SLOT_NUMBER
// ******************************************************************
typedef struct _PCI_SLOT_NUMBER
{
    union
    {
        struct
        {
            ULONG   DeviceNumber:5;
            ULONG   FunctionNumber:3;
            ULONG   Reserved:24;
        }
        bits;

        ULONG   AsULONG;
    }u;
}
PCI_SLOT_NUMBER, *PPCI_SLOT_NUMBER;

#define PCI_TYPE0_ADDRESSES             6
#define PCI_TYPE1_ADDRESSES             2
#define PCI_TYPE2_ADDRESSES             5

// ******************************************************************
// * PCI_COMMON_CONFIG
// ******************************************************************
typedef struct _PCI_COMMON_CONFIG
{
    USHORT  VendorID;                   // (ro)
    USHORT  DeviceID;                   // (ro)
    USHORT  Command;                    // Device control
    USHORT  Status;
    UCHAR   RevisionID;                 // (ro)
    UCHAR   ProgIf;                     // (ro)
    UCHAR   SubClass;                   // (ro)
    UCHAR   BaseClass;                  // (ro)
    UCHAR   CacheLineSize;              // (ro+)
    UCHAR   LatencyTimer;               // (ro+)
    UCHAR   HeaderType;                 // (ro)
    UCHAR   BIST;                       // Built in self test

    union
    {
        struct _PCI_HEADER_TYPE_0
        {
            ULONG   BaseAddresses[PCI_TYPE0_ADDRESSES];
            ULONG   CIS;
            USHORT  SubVendorID;
            USHORT  SubSystemID;
            ULONG   ROMBaseAddress;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved1[3];
            ULONG   Reserved2;
            UCHAR   InterruptLine;      //
            UCHAR   InterruptPin;       // (ro)
            UCHAR   MinimumGrant;       // (ro)
            UCHAR   MaximumLatency;     // (ro)
        }
        type0;
    }u;

    UCHAR DeviceSpecific[192];

}
PCI_COMMON_CONFIG, *PPCI_COMMON_CONFIG;

#define FIELD_OFFSET(type, field) ((LONG)(INT_PTR)&(((type *)0)->field))

#define PCI_COMMON_HDR_LENGTH (FIELD_OFFSET (PCI_COMMON_CONFIG, DeviceSpecific))

#define PCI_MAX_DEVICES                     32
#define PCI_MAX_FUNCTION                    8
#define PCI_MAX_BRIDGE_NUMBER               0xFF
#define PCI_INVALID_VENDORID                0xFFFF

// ******************************************************************
// * RETURN_FIRMWARE
// ******************************************************************
typedef enum _RETURN_FIRMWARE
{
    ReturnFirmwareHalt          = 0x0,
    ReturnFirmwareReboot        = 0x1,
    ReturnFirmwareQuickReboot   = 0x2,
    ReturnFirmwareHard          = 0x3,
    ReturnFirmwareFatal         = 0x4,
    ReturnFirmwareAll           = 0x5
}
RETURN_FIRMWARE, *LPRETURN_FIRMWARE;

// ******************************************************************
// * Debug
// ******************************************************************
#include "dbg.h"

// ******************************************************************
// * Executive
// ******************************************************************
#include "ex.h"

// ******************************************************************
// * Hardware Abstraction Layer
// ******************************************************************
#include "hal.h"

// ******************************************************************
// * I/O Manager
// ******************************************************************
#include "io.h"

// ******************************************************************
// * Kernel
// ******************************************************************
#include "kernel.h"

// ******************************************************************
// * Memory Manager
// ******************************************************************
#include "mm.h"

// ******************************************************************
// * NT
// ******************************************************************
#include "nt.h"

// ******************************************************************
// * Object Manager
// ******************************************************************
#include "ob.h"

// ******************************************************************
// * Process Structure
// ******************************************************************
#include "ps.h"

// ******************************************************************
// * Run-time Library
// ******************************************************************
#include "rtl.h"

// ******************************************************************
// * XBox
// ******************************************************************
#include "xbox.h"

#if defined(__cplusplus)
}
#endif

#endif


