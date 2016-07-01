/**
   \file fem/fem_element_trs3.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for trs3.

   2nd Order Hexahed. Transition Elem., Solid / Shell
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
               const size_t procs_len = 3;
               el_processor procs[
                  procs_len] = {general, Sestra, Pretube};
            }

            long trs3::nnodes(void) const {return 12;}

            el_types trs3::get_type(void) const {return TRS3;}

            const std::set<el_processor> trs3::processors(procs, procs+procs_len);

            trs3::trs3(const gelmnt1 *data) : __base::elem(data) {}

            trs3::trs3(const gelref1 *data) : __base::elem(data) {}

            trs3::trs3(const __base::elem *data) : __base::elem(data) {}
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
