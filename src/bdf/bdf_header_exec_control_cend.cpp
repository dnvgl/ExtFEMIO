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
   const char cID_bdf_header_exec_control_cend[]
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

               std::ostream &cend::put(std::ostream &os) const {
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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
