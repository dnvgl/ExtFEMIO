/**
   \file fem/fem_element_beps.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for beps.

   2-D, 2 Node Beam
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

#include <set>

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
               const size_t procs_len = 3;
               el_processor procs[procs_len] = {
                  general, Preframe, ADVANCE};
            }

            long beps::nnodes(void) const {return 2;}

            el_types beps::get_type(void) const {return BEPS;}

            const std::set<el_processor> beps::processors(procs, procs+procs_len);

            beps::beps(const gelmnt1 *data) : __base::elem(data) {}

            beps::beps(const gelref1 *data) : __base::elem(data) {}

            beps::beps(const __base::elem *data) : __base::elem(data) {}
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
