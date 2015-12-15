/**
   \file bdf/bdf_types_int.cpp
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

#include <sstream>

#include "bdf/types.h"
#include "bdf/errors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;
using namespace ::dnvgl;
using namespace extfem;
using bdf::types::entry_type;
using bdf::types::entry_value;

entry_type<long>::entry_type(const std::string &name) :
   bdf::types::base(name), bounds(0) {};

entry_type<long>::entry_type(
   const std::string &name,
   const bdf::type_bounds::bound<long> &bounds) :
   bdf::types::base(name), bounds(bounds) {};

const
#if HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
entry_type<long>::int_re(
   "[[:space:]]*[\\+-]?[[:digit:]]+[[:space:]]*");

void entry_type<long>::set_value(
   ::dnvgl::extfem::bdf::types::entry_value<long> &val,
   const ::std::string &inp) const {
   auto sval = extfem::string::string(inp).trim();

   if (sval.length() == 0) {
      if (this->bounds.does_allow_empty()) {
         val.is_value = false;
         return;
      };
      if (!this->bounds.has_default())
         throw errors::int_error(name, "empty entry without default");
      val.is_value = true;
      val = this->bounds.get_default();
      return;
   } else {
      if (! regex_match(inp, int_re)) {
         std::string msg("illegal input (""");
         msg += inp;
         msg += """), no integer";
         throw errors::int_error(name, msg);
      }
      conv.str(sval);
      conv.seekg(0);
      conv >> val.value;
      val.is_value = true;
   }
   if (!this->bounds.in_bounds(val)) {
      std::ostringstream msg("boundary condition violated (",
          ::std::ostringstream::ate);
      msg << name << ")\n(""" << inp << ", " << sval << ", " << val.value << """)";
      throw errors::int_error(name, msg.str());
   }
   return;
}

entry_value<long> entry_type<long>::operator() (const std::string &inp) const {
   entry_value<long> val;
   this->set_value(val, inp);
   return val;
}

::std::string entry_type<long>::format(const void *v) const {
   if (!v)
      return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
   else {
      entry_value<long> val((long*)v);
      return this->format(val);
   }
}

::std::string
entry_type<long>::format(const entry_value<long> &inp) const {
   std::ostringstream res;

   switch (out_form) {
   case LONG:
      res.setf(ios_base::right, ios_base::adjustfield);
      res.fill(' ');
      break;
   case SHORT:
      res.setf(ios_base::right, ios_base::adjustfield);
      res.fill(' ');
      break;
   case FREE:
      break;
   }
   res.width(out_form);

   res << inp.value;
   std::string out(res.str());
   if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
      std::ostringstream msg("output string for value ", std::ostringstream::ate);
      msg << inp.value << " of incorrect size, got length of " << out.size()
          << " instead of allowed length of " << out_form << ".";
      throw errors::int_error(name, msg.str());
   }
   return out;
}

::std::string entry_type<long>::format(const long &val) const {
   entry_value<long> tmp(val);
   return format(tmp);
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// coding: utf-8
// End:
