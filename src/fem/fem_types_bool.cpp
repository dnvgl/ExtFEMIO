/**
   \file fem_types_bool.cpp
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

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace types {

            const
#if HAVE_BOOST_REGEX_HPP
            boost::regex
#else
            std::regex
#endif
            entry_type<bool>::bool_re(
               "[[:space:]\\+-][[:digit:]][.][[:digit:]]{8}[eE][\\+-][[:digit:]]{2}[[:digit:][:space:]]",
#ifdef HAVE_BOOST_REGEX_HPP
               boost::regex_constants::ECMAScript);
#else
               std::regex_constants::ECMAScript);
#endif

            entry_type<bool>::entry_type(const std::string &name) :
               fem::types::base(name), bounds() {}

            bool entry_type<bool>::operator() (
               std::string const &inp) const {
               double value;

               if (inp.length() == 0) {
                  if (!this->bounds.has_default())
                     throw errors::bool_error(name, "empty entry without default");
                  return this->bounds.get_default();
               } else {
                  if (! regex_match(inp, bool_re)) {
                     std::string msg("illegal input (""");
                     throw errors::bool_error(name, msg + inp + """), no bool!");
                  }

                  conv.str(inp);
                  conv.seekg(0);
                  conv >> value;
               }
               if (value == 1.) return true;
               else if  (value == 0.) return false;
               else {
                  std::string msg("boundary condition violated (");
                  throw errors::bool_error(
                     name, msg + name + ")\n(""" + inp + """)");
               }
            }

            ::std::string entry_type<bool>::format(bool const &inp) const {
               if (inp) return " 1.00000000e+00 ";
               else return " 0.00000000e+00 ";
            }
         }
      }
   }
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8
// End:
