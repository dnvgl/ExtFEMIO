/**
   \file fem/fem_element_lqua.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for lqua.

   Plane Quadrilateral Membrane Element
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
                  general, Prefem, Sestra, ADVANCE, Poseidon};
            }

            long lqua::nnodes(void) const {return 4;}

            el_types lqua::get_type(void) const {return LQUA;}

            const std::set<el_processor> lqua::processors(
               procs, procs+procs_len);

            lqua::lqua(const gelmnt1 *data) : __base::elem(data) {}

            lqua::lqua(const gelref1 *data) : __base::elem(data) {}

            lqua::lqua(const __base::elem *p) : __base::elem(p) {}
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
