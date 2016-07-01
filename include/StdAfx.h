/**
   \file StdAfx.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Precompiled header definitions.

   Detailed description
*/


// StdAfx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#ifdef _MSC_VER

#pragma once

#ifdef _X64
   #define NTDDI_VERSION    NTDDI_WIN7SP4
#else
   #ifdef _DEBUG
      #define NTDDI_VERSION    NTDDI_WIN7SP4
   #else
      #define NTDDI_VERSION    NTDDI_WINXPSP4
      #define _WIN32_WINNT     _WIN32_WINNT_WINXP
   #endif
#endif


#define VC_EXTRALEAN    // Exclude rarely-used stuff from Windows headers

#ifdef _MFC_VER
#include <afx.h>
#endif

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <deque>
#include <string>
#include <set>
#include <map>
#include <utility>

#include <regex>

#pragma message(">--- ExtFEMIO settings ---------------------------------------------<")
#define __PRAGMASTRING2(x) #x
#define __PRAGMASTRING(x) __PRAGMASTRING2(x)
#pragma message("Operating System:")
#pragma message("   NTDDI_VERSION == " __PRAGMASTRING(NTDDI_VERSION))
#pragma message("   WINVER        >= " __PRAGMASTRING(WINVER))
#pragma message("   _WIN32_WINNT  == " __PRAGMASTRING(_WIN32_WINNT))
#pragma message("   _WIN32_IE     == " __PRAGMASTRING(_WIN32_IE))
#pragma message("Compiler:")
#pragma message("   _MSC_VER      == " __PRAGMASTRING(_MSC_VER))
#pragma message("Libraries:")
#pragma message(">------------------------------------------------------------------<")

#endif

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
