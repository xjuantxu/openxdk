// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xhal.h
// *
// * note : XBox Hardware Abstraction Layer
// *
// ******************************************************************
#ifndef XHAL_H
#define XHAL_H

#if defined(__cplusplus)
extern "C"
{
#endif

// ******************************************************************
// * XVGA
// ******************************************************************
#include	"xvga.h"

// ******************************************************************
// * XFile
// ******************************************************************
#include	"xfile.h"

// ******************************************************************
// * XOHCI
// ******************************************************************
#include    "xohci.h"

// ******************************************************************
// * The user application starts here
// ******************************************************************
extern VOID XBoxStartup();

#if defined(__cplusplus)
}
#endif

#endif
