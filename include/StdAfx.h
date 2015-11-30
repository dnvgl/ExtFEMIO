// StdAfx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#ifdef _MSC_VER

#pragma once

#include "NDStingrayVersions.h"
#if  _StingrayVersion >= 1000
   #define NO_TARGETING
#endif
#include "CRT4VS2005.h"
#undef NO_TARGETING

#define VC_EXTRALEAN    // Exclude rarely-used stuff from Windows headers

#include <afx.h>

#include <deque>
#include <string>
#include <set>
#include <map>
#include <utility>

#include <regex>

#include "catch.hpp"
#include "my_c++14.h"
#include "bdf/cards.h"
#include "bdf/cards_elements.h"
#include "bdf/cards_properties.h"
#include "bdf/errors.h"
#include "bdf/file.h"
#include "extfem_string.h"
#include "bdf/type_bounds.h"
#include "bdf/types.h"

#endif
