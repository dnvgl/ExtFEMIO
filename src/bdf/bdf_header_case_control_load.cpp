/**
   \file bdf/bdf_header_case_control_load.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implemention of LOAD for case control.

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

#include "bdf/header.h"

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace header {
            namespace case_control {
               load::load(long const &n) : n(n) {}

               const std::ostream& load::operator<<(std::ostream &os) const {
                  return os << *this;
               }

               std::ostream&
               operator<<(std::ostream &os, const load &entry) {
                  os << "LOAD = " << entry.n;
                  return os << std::endl;
               }

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
// compile-command: "make test"
// End: