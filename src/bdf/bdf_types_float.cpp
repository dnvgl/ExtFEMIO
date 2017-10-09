/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

   Detailed description
   */
// ReSharper disable once CppUnusedIncludeDirective
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf_types_float[]) =
        "@(#) $Id$";
}

#ifdef __GNUC__
#include "config.h"
#endif

#ifdef HAVE_BOOST_REGEX_HPP
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include "bdf/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

#ifdef HAVE_BOOST_REGEX_HPP
using namespace boost;
using namespace boost::regex_constants;
#else
using namespace std;
using namespace regex_constants;
#endif

const regex dnvgl::extfem::bdf::types::float_exp_re(
    "([\\+-]?[.0-9]+)([+-][0-9]+)", ECMAScript);

const regex dnvgl::extfem::bdf::types::float_re(
    "([\\+-]?((0|([1-9][0-9]*))?[.][0-9]*)|"
    "[.][0-9]+)(((E[+-]?)|[+-])[0-9]+)?", ECMAScript);

const regex dnvgl::extfem::bdf::types::float_lead_dot(
    "^[\\+-]?[.][0-9]+", ECMAScript);

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
