// Copyright © 2015 by DNV GL SE

// Helper functions for string manipulation.

// Author: Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20150618_EXTFEM_STRING
#define _BERHOL20150618_EXTFEM_STRING

#include <string>
#include <algorithm>

#include "extfem_misc.h"

namespace dnvgl {
  namespace extfem {

    namespace string {

      class string : public std::string {
      public:
        DllExport string(const std::string& in) : std::string(in) {};
        DllExport string trim(const std::string& = " \t");
        string upper();
        string lower();
      };
    }
  }
}

#endif // _BERHOL20150618_EXTFEM_STRING

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
