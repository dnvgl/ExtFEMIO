/**
   \file fem/fem_element_rpbq.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for rpbq.

   Rect. Plate. Bending Modes
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

            long rpbq::nnodes(void) const {return 4;}

            el_types rpbq::get_type(void) const {return RPBQ;}

            const std::set<el_processor> rpbq::processors(
               procs, procs+procs_len);

            rpbq::rpbq(const gelmnt1 *data) : __base::elem(data) {}

            rpbq::rpbq(const gelref1 *data) : __base::elem(data) {}

            rpbq::rpbq(const __base::elem *data) : __base::elem(data) {}
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
