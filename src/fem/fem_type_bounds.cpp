/**
   \file fem/fem_type_bounds.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implementation of type bounds for Seasam FEM IO.

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

#include <string>

#include "fem/type_bounds.h"

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace type_bounds {

            base::~base () {};

            bool base::has_min() const {
               return _has_min;
            }

            void base::got_min() {
               _has_min = true;
            }

            bool base::has_max() const {
               return _has_max;
            }

            void base::got_max() {
               _has_max = true;
            }

            void base::got_default() {
               _has_default = true;
            }


            base::base() :
               _has_min(false), _has_max(false), _has_default(false)
            {}

            bool base::has_default() const {
               return _has_default;
            }

            bound<std::string>::bound() {}

            bound<std::string>::bound(::std::set<::std::string> allowed) :
               base(), allowed(allowed) {}

            bound<std::string>::bound(
               ::std::set<::std::string> allowed, ::
               std::string default_val) :
               base(), allowed(allowed), default_val(default_val) {
               got_default();
            }

            bound<std::string>::bound(::std::string default_val) :
               base(), default_val(default_val) {
               got_default();
            }

            bool bound<std::string>::is_allowed(
               const ::std::string probe) const {
               if (allowed.size() == 0)
                  return true;
               return !(allowed.find(probe) == allowed.end());
            }

            ::std::string bound<std::string>::get_default(void) const {
               if (!has_default())
                  throw ::dnvgl::extfem::fem::errors::types_error("** ERROR **: No default value avaliable.");
               return this->default_val;
            }

            bound<bool>::bound() {};

            bound<bool>::bound(bool &_default) : default_val(_default) {
               got_default();
            }

            bool bound<bool>::get_default(void) const {
               if (!has_default())
                  throw ::dnvgl::extfem::fem::errors::types_error(
                     "** ERROR **: No default value avaliable.");
               return this->default_val;
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
// compile-command: "make -C ../.. check -j8"
// End:
