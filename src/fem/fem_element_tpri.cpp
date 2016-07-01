/**
   \file fem/fem_element_tpri.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for tpri.

   Triangular Prism
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
               const size_t procs_len = 4;
               el_processor procs[procs_len] = {
                  general, Prefem, Sestra, Platework};
            }

            long tpri::nnodes(void) const {return 6;}

            el_types tpri::get_type(void) const {return TPRI;}

            const std::set<el_processor> tpri::processors(procs, procs+procs_len);

            tpri::tpri(const gelmnt1 *data) : __base::elem(data) {}

            tpri::tpri(const gelref1 *data) : __base::elem(data) {}

            tpri::tpri(const __base::elem *data) : __base::elem(data) {}
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
