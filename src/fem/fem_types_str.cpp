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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
entry_type<std::string>::operator() (const std::string &inp) const {
   std::string sval = extfem::string::string(inp).trim();

   if (sval.length() == 0)
      sval = bounds.get_default();

   if (!bounds.is_allowed(sval))
      throw errors::str_error(name, "!" + sval + "! Value not in list of allowed values.");

   return sval;
}

std::string entry_type<std::string>::format(const std::string &inp, const size_t &len) const {

   std::ostringstream res;

   res.setf(ios_base::left, ios_base::adjustfield);
   res.fill(' ');
   res.width(len-8);

   res << inp;
   std::string out(res.str());
   if (out.size() != len-8) {
      std::ostringstream msg("output string for value ", std::ostringstream::ate);
      msg << inp << " of incorrect size, got length of " << out.size()
          << " instead of allowed length of 72.";
      throw errors::int_error(name, msg.str());
   }
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
