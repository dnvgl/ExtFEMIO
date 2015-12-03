/**
   \file bdf/bdf_types_str.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing of string entries from Nastran BDF files.

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

#include "bdf/types.h"
#include "bdf/errors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem;
using bdf::types::entry_type;
using bdf::types::entry_value;

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace types {
            template <>
            entry_value<::std::string>::entry_value(
               const ::std::string *value) {
               if (!value) {
                  this->is_value = false;
                  this->value = "";
               } else {
                  this->is_value = true;
                  this->value = *value;
               }
            }

            void entry_type<::std::string>::set_value(
               entry_value<std::string> &val, std::string const &inp) const {
               val = this->operator() (inp);
            }
         }
      }
   }
}

entry_type<std::string>::entry_type(const std::string &name) :
   bdf::types::base(name), bounds(bdf::type_bounds::bound<std::string>()) {}

entry_type<std::string>::entry_type(
   const std::string &name,
   const bdf::type_bounds::bound<std::string> &bounds) :
   bdf::types::base(name), bounds(bounds) {}

entry_value<std::string>
entry_type<std::string>::operator() (const std::string &inp) const {
   auto sval = extfem::string::string(inp).trim();

   if (sval.length() == 0)
      sval = bounds.get_default();

   if (!bounds.is_allowed(sval))
      throw errors::str_error(name, "!" + sval + "! Value not in list of allowed values.");

   return entry_value<std::string>(sval, true);
}

::std::string entry_type<std::string>::format(const void *v) const {
   if (!v)
      return ::dnvgl::extfem::bdf::types::empty().format(nullptr);
   else {
      entry_value<::std::string> val((std::string*)v);
      return this->format(val);
   }
}

std::string entry_type<std::string>::format(const entry_value<std::string> &inp) const {

   if (!inp)
      return bdf::types::empty().format(nullptr);

   std::ostringstream res;

   switch (out_form) {
   case LONG:
      res.setf(ios_base::left, ios_base::adjustfield);
      res.fill(' ');
      break;
   case SHORT:
      res.setf(ios_base::left, ios_base::adjustfield);
      res.fill(' ');
      break;
   case FREE:
      break;
   }
   res.width(out_form);

   res << (::std::string)inp;
   std::string out(res.str());
   if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
      std::ostringstream msg("output string for value ", std::ostringstream::ate);
      msg << (::std::string)inp << " of incorrect size, got length of " << out.size()
          << " instead of allowed length of " << out_form << ".";
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
