/**
   \file my_c++14.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for helper functions.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_my_cpp14[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef __GNUC__
#include "config.h"
#endif

#if _MSC_VER <= 1700

#include <cmath>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if _MSC_VER && _MSC_VER <= 1700
namespace std {
   double round(double number) {
   return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
   }
}
#endif

#endif

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
