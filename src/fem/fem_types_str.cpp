/**
   \file fem/fem_types_str.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing of string entries from Sesam FEM files.

   Detailed description
*/

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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
#include "fem/errors.h"
#include "extfem_string.h"

using namespace ::std;
using namespace ::dnvgl::extfem;
using fem::types::entry_type;

entry_type<std::string>::entry_type(const std::string &name) :
   fem::types::base(name), bounds() {}

entry_type<std::string>::entry_type(
   const std::string &name,
   const fem::type_bounds::bound<std::string> &bounds) :
   fem::types::base(name), bounds(bounds) {}

std::string
entry_type<std::string>::operator() (
   const std::string &inp1, const std::string &inp2,
   const std::string &inp3, const std::string &inp4) const {

   std::string sval = extfem::string::string(
      inp1 + inp2 + inp3 + inp4).trim();

   if (sval.length() == 0)
      sval = bounds.get_default();

   return sval;
}

std::string entry_type<std::string>::format(const std::string &inp, const size_t &len) const {

   std::ostringstream res;

   res.setf(ios_base::left, ios_base::adjustfield);
   res.fill(' ');
   res.width(len-8);

   res << inp;
   std::string out(res.str());
   if (out.size() > len) {
      std::ostringstream msg("output string for value ", std::ostringstream::ate);
      msg << inp << " of incorrect size, got length of " << out.size()
          << " instead of allowed length of " << len << ".";
      throw errors::int_error(name, msg.str());
   }
   out.resize(len, ' ');
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
