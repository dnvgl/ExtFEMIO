/**
   \file bdf/bdf_types.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

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

#include <iomanip>
#include <locale>

#include "config.h"

#include "bdf/types.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace types {

            std::istringstream base::conv;

            base::base(const std::string &name) : name(name) {};

            /// std::set input and output locale for conv and outp
            static imbue_helper _imbue_helper(std::locale::classic());

            out_form_type base::out_form = SHORT;

            std::string card::format(const void* d) const {
               std::ostringstream outp;

               outp << std::resetiosflags(std::ios::adjustfield);
               switch (out_form) {
               case LONG:
                  outp << std::setiosflags(std::ios::left) << std::setfill(' ')
                       << std::setw(8) << (name + "*");
                  break;
               case SHORT:
                  outp << std::setiosflags(std::ios_base::left) << std::setfill(' ')
                       << std::setw(8) << name;
                  break;
               case FREE:
                  outp << name;
                  break;
               }

               return outp.str();
            }

            empty::empty(void) : base("<empty>") {}

            std::string empty::format(const void* d) const {
               std::ostringstream outp;

               switch (out_form) {
               case LONG:
               case SHORT:
                  outp << std::setfill(' ') << std::setw(out_form) << " ";
                  break;
               case FREE:
                  break;
               }
               return outp.str();
            }

            std::string empty::format() const {
               return this->format(nullptr);
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
