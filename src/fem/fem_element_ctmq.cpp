/**
   \file fem/fem_element_ctmq.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ctmq.

   18-Noded (9+9) Contact Element
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
               el_processor procs[procs_len] = {general, Pretube};
            }

            long ctmq::nnodes(void) const {return 18;}

            el_types ctmq::get_type(void) const {return CTMQ;}

            const std::set<el_processor> ctmq::processors(
               procs, procs+procs_len);

            ctmq::ctmq(const gelmnt1 *data) :
               dnvgl::extfem::fem::elements::__base::elem(data) {}

            ctmq::ctmq(const dnvgl::extfem::fem::cards::gelref1 *data) :
               dnvgl::extfem::fem::elements::__base::elem(data) {}

            ctmq::ctmq(const dnvgl::extfem::fem::elements::__base::elem *data) :
               dnvgl::extfem::fem::elements::__base::elem(data) {}
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
