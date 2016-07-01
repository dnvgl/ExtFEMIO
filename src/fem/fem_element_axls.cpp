/**
   \file fem/fem_element_axls.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for axls.

   Axisymmetric Linear Strain Triangle
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
                  general, Prefem, Sestra};
            }

            long axls::nnodes(void) const {return 6;}

            el_types axls::get_type(void) const {return AXLS;}

            const std::set<el_processor> axls::processors(
               procs, procs+procs_len);

            axls::axls(const gelmnt1 *data) : __base::elem(data) {}

            axls::axls(const gelref1 *data) : __base::elem(data) {}

            axls::axls(const __base::elem *data) : __base::elem(data) {}
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
