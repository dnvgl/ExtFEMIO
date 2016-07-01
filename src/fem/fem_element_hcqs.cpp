/**
   \file fem/fem_element_hcqs.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for hcqs.

   9-Noded Shell Element
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
               const size_t procs_len = 3;
               el_processor procs[procs_len] = {
                  general, Prefem, Pretube};
            }

            long hcqs::nnodes(void) const {return 9;}

            el_types hcqs::get_type(void) const {return HCQS;}

            const std::set<el_processor> hcqs::processors(
               procs, procs+procs_len);

            hcqs::hcqs(const gelmnt1 *data) : __base::elem(data) {}

            hcqs::hcqs(const cards::gelref1 *data) : __base::elem(data) {}

            hcqs::hcqs(const __base::elem *data) : __base::elem(data) {}
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
