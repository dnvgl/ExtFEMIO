/**
   \file fem/fem_element_adva_2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for adva_2.

   2-Noded Link Element
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
               const size_t procs_len = 2;
               el_processor procs[procs_len] = {general, ADVANCE};
            }

            long adva_2::nnodes(void) const {return 2;}

            el_types adva_2::get_type(void) const {return ADVA_2;}

            const std::set<el_processor> adva_2::processors(
               procs, procs+procs_len);

            adva_2::adva_2(const gelmnt1 *data) : __base::elem(data) {}

            adva_2::adva_2(const gelref1 *data) : __base::elem(data) {}

            adva_2::adva_2(const __base::elem *data) : __base::elem(data) {}
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
