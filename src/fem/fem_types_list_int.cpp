/**
   \file fem/fem_types_list_int.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Sesam FEM data entry types.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_types_list_int[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef __GNUC__
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include <list>
#include <sstream>
#include <algorithm>

#include "fem/types.h"
#include "fem/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem::types;

const
#ifdef HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
entry_type<std::vector<int> >::list_int_re(
    "(            0.00)|"
    "([[:space:]][[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2})|"
    "([[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2}[[:digit:][:space:]])|"
    "([[:space:]\\+-][[:digit:]][.][[:digit:]]{9}[eE][\\+-][[:digit:]]{2})",
#ifdef HAVE_BOOST_REGEX_HPP
    boost::regex_constants::ECMAScript
#else
    std::regex_constants::ECMAScript
#endif
    );

fem_types const entry_type<std::vector<int> >::_type = fem_types::List;

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
