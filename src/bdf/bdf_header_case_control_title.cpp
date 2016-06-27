/**
   \file bdf/bdf_header_case_control_title.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for CASE TITLE

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
            namespace case_control {
               title::title(std::string const &title) :
                  name(title) {}

               const std::ostream&
               title::operator<< (std::ostream& os) const {
                  return os << *this;
               }

               std::ostream &operator<<(
                  std::ostream &os, title const &entry) {
                  return os << "TITLE = " << entry.name << std::endl;
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
