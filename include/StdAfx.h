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

#include <algorithm>
#include <functional>
#include <iterator>
#include <locale>
#include <memory>
#include <utility>

#include <limits>
#include <typeinfo>

#include <iomanip>
#include <iostream>
#include <sstream>

#include <complex>

#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

#include <regex>

#include <cassert>
#include <cmath>
#include <cstdlib>

#include "config.h"

#include "my_c++14.h"
#include "extfem_misc.h"
#include "extfem_string.h"

#endif

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
