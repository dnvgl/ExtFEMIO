/**
   \file bdf_header_case_control_begin_bulk.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of the BDF case cotrol "BEGIN BULK" entries.

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
               begin_bulk::begin_bulk() {};

               std::ostream &begin_bulk::put(std::ostream &os) const {
                  return os << "BEGIN BULK" << std::endl;
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
