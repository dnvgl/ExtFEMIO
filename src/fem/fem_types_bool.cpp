/**
   \file fem/fem_types_bool.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implemention of bool boundaries for Sesam FEM IO.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include <sstream>

#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace types {

            const
#ifdef HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            std::regex
#endif
            bool_re(
               "([[:space:]]*[[:space:]\\+-]?[01][.][0]*([eE][\\+-][[:digit:]]{2,3})?[[:space:]]*)",
#ifdef HAVE_BOOST_REGEX_HPP
               boost::regex_constants::ECMAScript
#else
               std::regex_constants::ECMAScript
#endif
               );
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
