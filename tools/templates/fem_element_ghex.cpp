/**
   \file fem/fem_element_ghex.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ghex1*.

   General Hexahedon elements defined with 21 to 27 nodes.
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
               el_processor procs[procs_len] = {general, Sestra};
            }

            ghex::ghex(void) : __base::elem() {}

            ghex::ghex(long const elno,
                       long const elident,
                       long const el_add,
                       std::vector<long> const nodes,
                       long const matref,
                       long const add_no,
                       long const intno,
                       long const mass_intno,
                       long const i_strain_ref,
                       long const i_stressef,
                       long const strpoint_ref,
                       std::vector<long> const sections,
                       std::vector<long> const fixations,
                       std::vector<long> const eccentrities,
                       std::vector<long> const csys) :
               __base::elem(elno, elident, el_add, nodes, matref,
                            add_no, intno, mass_intno, i_strain_ref,
                            i_stressef, strpoint_ref, sections,
                            fixations, eccentrities, csys) {}

            ghex::ghex(const cards::gelmnt1 *data) : __base::elem(data) {}

            ghex::ghex(const cards::gelref1 *data) : __base::elem(data) {}

            ghex::ghex(const __base::elem *p) : __base::elem(p) {}

{% for num, pos in res %}
/**
   General Hexahedron, define with nodes 1 to 20{{ gen_extnodes(pos[:-1]) }} and node 27 present.

   Position of node in node array for element node numbers > 20:

{{ gen_nodepos(pos, 20 * " ") }}
*/

            ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(void) :
            ghex() {};

            ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(
               long const elno,
               long const elident,
               long const el_add,
               std::vector<long> const nodes,
               long const matref,
               long const add_no,
               long const intno,
               long const mass_intno,
               long const i_strain_ref,
               long const i_stressef,
               long const strpoint_ref,
               std::vector<long> const sections,
               std::vector<long> const fixations,
               std::vector<long> const eccentrities,
               std::vector<long> const csys) :
            ghex(elno, elident, el_add, nodes, matref, add_no, intno,
                 mass_intno, i_strain_ref, i_stressef, strpoint_ref,
                 sections, fixations, eccentrities, csys) {}

            long ghex1{{ "%02d"|format(num) }}::nnodes(void) const {
               return {{ pos|length + 20 }};
            }

            el_types ghex1{{ "%02d"|format(num) }}::get_type() const {
               return GHEX1{{ "%02d"|format(num) }};
            }

            const std::set<el_processor> ghex1{{ "%02d"|format(num) }}::processors(procs, procs+procs_len);

            ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(
               const cards::gelref1 *data) : ghex(data) {}

            ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(
               const __base::elem *data) :
            ghex(data) {}
{% endfor %}
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
