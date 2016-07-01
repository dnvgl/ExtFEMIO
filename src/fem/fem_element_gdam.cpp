/**
   \file fem/fem_element_gdam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for gdam.

   Damper to Ground
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

#include "fem/elements.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace dnvgl {
   namespace extfem {
      namespace fem {

         using namespace cards;

         namespace elements {
            namespace {
               const size_t procs_len = 5;
               el_processor procs[procs_len] = {
                  general, Preframe, Prefem, Sestra, Poseidon};
            }

            el_types gdam::get_type(void) const {return GDAM;}

            long gdam::nnodes(void) const {return 1;}

            const std::set<el_processor> gdam::processors(
               procs, procs+procs_len);

            gdam::gdam(const gelmnt1 *data) :
               __base::elem(data) {}

            gdam::gdam(const gelref1 *data) :
               __base::elem(data) {}

            gdam::gdam(const __base::elem *data) :
               __base::elem(data) {}
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
