/**
   \file bdf/qbdf_header_case_echo.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implement output for CASE ECHO

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
               echo::echo(std::string const &oper) :
                  oper(oper) {}

               const std::ostream&
               echo::operator<< (std::ostream& os) const {
                  return os << *this;
               }

               std::ostream &operator<<(
                  std::ostream &os, echo const &entry) {
                  return os << "ECHO=" << entry.oper << std::endl;
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
