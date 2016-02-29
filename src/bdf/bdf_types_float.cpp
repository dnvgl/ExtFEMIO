/**
   \file bdf/bdf_types_float.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

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

#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf::types;

DECLSPECIFIER const
#ifdef HAVE_BOOST_REGEX_HPP
::boost::regex
#else
::std::regex
#endif
dnvgl::extfem::bdf::types::float_exp_re(
   "([\\+-]?[.0-9]+)([+-][0-9]+)",
#ifdef HAVE_BOOST_REGEX_HPP
   ::boost::regex_constants::ECMAScript);
#else
::std::regex_constants::ECMAScript);
#endif

DECLSPECIFIER const
#ifdef HAVE_BOOST_REGEX_HPP
::boost::regex
#else
::std::regex
#endif
dnvgl::extfem::bdf::types::float_re(
   "([\\+-]?((0|([1-9][0-9]*))?[.][0-9]*)|"
   "[.][0-9]+)(((E[+-]?)|[+-])[0-9]+)?",
#ifdef HAVE_BOOST_REGEX_HPP
   ::boost::regex_constants::ECMAScript);
#else
::std::regex_constants::ECMAScript);
#endif

DECLSPECIFIER const
#ifdef HAVE_BOOST_REGEX_HPP
::boost::regex
#else
::std::regex
#endif
dnvgl::extfem::bdf::types::float_lead_dot(
   "^[\\+-]?[.][0-9]+",
#ifdef HAVE_BOOST_REGEX_HPP
   ::boost::regex_constants::ECMAScript);
#else
::std::regex_constants::ECMAScript);
#endif


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
