/**
   \file bdf/bdf_header_case_control_subtitle.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for BDF SUBTILE case control entry.

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

               subtitle::subtitle(std::string const &title) :
                  title(title) {}

               const std::ostream& subtitle::operator<< (std::ostream &os) const {
                  return os << this;
               }

               std::ostream const &subtitle::put(std::ostream &os) const {
                  os << "SUBTITLE = " << this->title;
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
// compile-command: "make -C ../.. check -j 8"
// End:
