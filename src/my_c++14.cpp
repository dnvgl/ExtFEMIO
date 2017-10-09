/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for helper functions.

   Detailed description
*/
#include "extfemio_stdafx.h"
#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_my_cpp14[]) =
        "@(#) $Id$";
}

#ifdef __GNUC__
#include "config.h"
#endif

#if _MSC_VER <= 1700

#include <cmath>

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
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
