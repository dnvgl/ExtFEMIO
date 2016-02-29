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

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_MAXVER
#endif

#ifndef EXTFEM_IGNORE_STINGRAY
#include "NDStingrayVersions.h"
#if  _StingrayVersion >= 1000
   #define NO_TARGETING
#endif
#include "CRT4VS2005.h"
#undef NO_TARGETING
#endif // EXTFEM_IGNORE_STINGRAY

#define VC_EXTRALEAN    // Exclude rarely-used stuff from Windows headers

// #include <afx.h>

#include <deque>
#include <string>
#include <set>
#include <map>
#include <utility>

#include <regex>

#endif

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
