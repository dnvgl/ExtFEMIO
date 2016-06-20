/**
   \file bdf/bdf_header_case_subcase.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for CASE SUBCASE

   Detailed description
*/

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
            namespace case_ {
               subcase::subcase(long const &n) :
                  n(n) {}

               const std::ostream&
               subcase::operator<< (std::ostream& os) const {
                  return os << *this;
               }

               std::ostream &operator<<(
                  std::ostream &os, subcase const &entry) {
                  return os << "SUBCASE=" << entry.n << std:: endl;
               }
            }
         }
      }
   }
}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
