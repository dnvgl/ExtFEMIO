/**
   \file fem/fem_element_tess.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for tess.

   Truss Element
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
         namespace elements {
            using namespace dnvgl::extfem::fem::cards;

            namespace {
               const size_t procs_len = 6;
               el_processor procs[procs_len] = {
                  general, Preframe, Prefem, Sestra, ADVANCE, Poseidon};
            }

            long tess::nnodes(void) const {return 2;}

            el_types tess::get_type(void) const {return TESS;}

            const std::set<el_processor> tess::processors(procs, procs+procs_len);

            tess::tess(const gelmnt1 *data) : __base::elem(data) {}

            tess::tess(const gelref1 *data) : __base::elem(data) {}

            tess::tess(const __base::elem *p) : __base::elem(p) {}
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
