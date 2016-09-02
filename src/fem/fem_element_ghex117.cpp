   /**
   \file fem/fem_element_ghex117.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ghex117.

   General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 27 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id: fem_element.cpp 438 2016-09-01 15:15:08Z berhol $";
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
               el_processor procs[procs_len] = { Sestra, general };
            }

            long ghex117::nnodes(void) const {return 23;}

            el_types ghex117::get_type(void) const {return GHEX117;}

            const std::set<el_processor> ghex117::processors(
               procs, procs+procs_len);

            ghex117::ghex117(void) : elem() {}

            ghex117::ghex117(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  elem(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ghex117::ghex117(const cards::gelmnt1 *data) : elem(data) {}

            ghex117::ghex117(const cards::gelref1 *data) : elem(data) {}

            ghex117::ghex117(const __base::elem *data) : __base::elem(data) {}
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End: