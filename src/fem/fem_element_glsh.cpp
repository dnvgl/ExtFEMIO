/**
   \file fem/fem_element_glsh.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for glsh.

   General Spring / Shim Element
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
               const size_t procs_len = 4;
               el_processor procs[procs_len] = {
                  general, Preframe, Sestra, Poseidon};
            }

            long glsh::nnodes(void) const {return 2;}

            el_types glsh::get_type(void) const {return GLSH;}

            const std::set<el_processor> glsh::processors(
               procs, procs+procs_len);

            glsh::glsh(const gelmnt1 *data) : __base::elem(data) {}

            glsh::glsh(const gelref1 *data) : __base::elem(data) {}

            glsh::glsh(const __base::elem *data) : __base::elem(data) {}
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
