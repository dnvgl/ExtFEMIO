/**
   \file fem/fem_types_float.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for SESAM FEM entry types.

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

#ifdef __GNUC__
#include "config.h"
#endif

#ifdef _MSC_VER
#include <stdio.h>
#endif

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include "fem/types.h"
#include "fem/errors.h"

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
            float_re(
               "([[:space:]]*[[:space:]+-]?[[:digit:]][.][[:digit:]]+[eE][\\+-][[:digit:]]{2,3}[[:space:]]*)",
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
// compile-command: "make -C ../.. check -j8"
// End:
