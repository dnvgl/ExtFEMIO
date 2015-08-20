// Copyright © 2015 by DNV GL SE

// Helper functions for string manipulation.

// Author: Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID: $Id$

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#if !defined _BERHOL20150618_BDF_STRING
#define _BERHOL20150618_BDF_STRING

#include <string>
#include <algorithm>

#include "bdf_errors.h"

#ifdef _MSC_VER
#define DllExport __declspec( dllexport )
#else
#define DllExport
#endif

namespace bdf {

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

#endif // _BERHOL20150618_BDF_STRING

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
