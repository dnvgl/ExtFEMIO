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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::fem::types;

entry_type<double>::entry_type(const std::string &name) :
   fem::types::base(name), bounds() {};

entry_type<double>::entry_type(
   const std::string &name,
   const fem::type_bounds::bound<double> &bounds) :
   fem::types::base(name), bounds(bounds) {};

const
#ifdef HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
entry_type<double>::float_re(
   "[[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2}[[:digit:][:space:]]",
//  "[[:space:]\\+-][0-9][.][0-9]{8}[eE][\\+-][0-9]{2}",
#ifdef HAVE_BOOST_REGEX_HPP
   boost::regex_constants::ECMAScript);
#else
std::regex_constants::ECMAScript);
#endif

// Convert string to double
double entry_type<double>::operator() (const std::string &inp) const {
   double value;

   if (inp.length() == 0) {
      if (!this->bounds.has_default())
         throw errors::float_error(name, "empty entry without default");
      value = this->bounds.get_default();
   } else {
      if (! regex_match(inp, float_re)) {
         std::string msg("illegal input, (""");
         throw errors::float_error(name, msg + inp + """), no float!");
      }

      istringstream conv(inp);
      conv.imbue(locale("C"));
      conv >> value;
   }
   if (!this->bounds.in_bounds(value)) {
      std::string msg("boundary condition violated (");
      throw errors::float_error(
         name, msg + name + ")\n(""" + inp + """)");
   }
   return value;
}

std::string entry_type<double>::format(const double &inp) const {

   std::ostringstream res;

#ifdef _MSC_VER
   // Set output to two digit exponetial format.
   unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

   res.setf(ios_base::showpos);
   res.setf(ios_base::scientific, ios::floatfield);
   res.setf(ios_base::adjustfield, ios::left);

   res.precision(8);
   res.width(16);
   res.fill(' ');

   res << inp;
   std::string out(res.str());
   if (out.size() != 16) {
      std::ostringstream msg("output string for value ", std::ostringstream::ate);
      msg << inp << " of incorrect size, got length of " << out.size()
          << " instead of allowed length of 16.";
      throw errors::output_error(name, msg.str());
   }

#ifdef _MSC_VER
   // Reset exponetial format to former settings.
   _set_output_format(ext_exp_format);
#endif

   return out;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
