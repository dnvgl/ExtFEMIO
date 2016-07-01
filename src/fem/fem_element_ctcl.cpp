/**
   \file fem/fem_element_ctcl.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ctcl.

   4-Noded Contact Element
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
               const size_t procs_len = 1;
               el_processor procs[procs_len] = {general};
            }

            long ctcl::nnodes(void) const {return 4;}

            el_types ctcl::get_type(void) const {return CTCL;}

            const std::set<el_processor> ctcl::processors(
               procs, procs+procs_len);

            ctcl::ctcl(const gelmnt1 *data) : __base::elem(data) {}

            ctcl::ctcl(const gelref1 *data) : __base::elem(data) {}

            ctcl::ctcl(const __base::elem *data) : __base::elem(data) {}
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
