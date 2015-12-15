/**
   \file fem/fem_types_int.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for SESAM FEM data entry types.

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

#include <sstream>

#include "fem/types.h"
#include "fem/errors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl;
using namespace extfem;
using fem::types::entry_type;

entry_type<long>::entry_type(const std::string &name) :
   fem::types::base(name), bounds() {}

entry_type<long>::entry_type(
   const std::string &name,
   const fem::type_bounds::bound<long> &bounds) :
   fem::types::base(name), bounds(bounds) {}

const
#if HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
entry_type<long>::int_re(
//  "[[:space:]]*[\\+-]?[1-9][0-9]*[[:space:]]*",
   "[[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2}[[:digit:][:space:]]",
#ifdef HAVE_BOOST_REGEX_HPP
   boost::regex_constants::ECMAScript);
#else
std::regex_constants::ECMAScript);
#endif

// Convert string to long
long entry_type<long>::operator() (const std::string &inp) const {
   double value;

   if (inp.length() == 0) {
      if (!this->bounds.has_default())
         throw errors::int_error(name, "empty entry without default");
      return this->bounds.get_default();
   } else {
      if (! regex_match(inp, int_re)) {
         std::string msg("illegal input (""");
         throw errors::int_error(name, msg + inp + """), no integer!");
      }

      conv.str(inp);
      conv.seekg(0);
      conv >> value;
   }
   if (!this->bounds.in_bounds(long(value))) {
      std::string msg("boundary condition violated (");
      throw errors::int_error(
         name, msg + name + ")\n(""" + inp + """)");
   }
   return long(value);
}

std::string entry_type<long>::format(const long &inp) const {

   std::ostringstream res;

#ifdef _MSC_VER
   // Set output to two digit exponetial format.
   unsigned int ext_exp_format = _set_output_format(_TWO_DIGIT_EXPONENT);
#endif

   res.setf(ios_base::showpos);
   res.setf(ios_base::scientific, ios_base::floatfield);
   res.setf(ios_base::adjustfield, ios::left);

   res.precision(8);
   res.width(16);
   res.fill(' ');

   res << double(inp);
   std::string out(res.str());
   if (out.size() != 16) {
      std::ostringstream msg("output string for value ", std::ostringstream::ate);
      msg << double(inp) << " of incorrect size, got length of " << out.size()
          << " instead of allowed length of 16." << out;
      throw errors::int_error(name, msg.str());
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
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
