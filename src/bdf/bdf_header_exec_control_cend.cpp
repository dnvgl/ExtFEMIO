/**
   \file bdf/bdf_header_exec_control_cend.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for EXEC CEND

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
            namespace executive_control {
               cend::cend() {}

               const std::ostream&
               cend::operator<< (std::ostream& os) const {
                  return os << *this;
               }

               std::ostream&
               operator<<(std::ostream &os, cend const &entry) {
                  return os << "CEND" << std::endl;
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
