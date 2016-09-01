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


/**
   General Hexahedron, define with nodes 1 to 20 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 27 at pos 21
*/

            ghex100::ghex100(void) :
            ghex() {};

            ghex100::ghex100(
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

            long ghex100::nnodes(void) const {
               return 21;
            }

            el_types ghex100::get_type() const {
               return GHEX100;
            }

            const std::set<el_processor> ghex100::processors(procs, procs+procs_len);

            ghex100::ghex100(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex100::ghex100(
               const cards::gelref1 *data) : ghex(data) {}

            ghex100::ghex100(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 27 at pos 22
*/

            ghex101::ghex101(void) :
            ghex() {};

            ghex101::ghex101(
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

            long ghex101::nnodes(void) const {
               return 22;
            }

            el_types ghex101::get_type() const {
               return GHEX101;
            }

            const std::set<el_processor> ghex101::processors(procs, procs+procs_len);

            ghex101::ghex101(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex101::ghex101(
               const cards::gelref1 *data) : ghex(data) {}

            ghex101::ghex101(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 27 at pos 22
*/

            ghex102::ghex102(void) :
            ghex() {};

            ghex102::ghex102(
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

            long ghex102::nnodes(void) const {
               return 22;
            }

            el_types ghex102::get_type() const {
               return GHEX102;
            }

            const std::set<el_processor> ghex102::processors(procs, procs+procs_len);

            ghex102::ghex102(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex102::ghex102(
               const cards::gelref1 *data) : ghex(data) {}

            ghex102::ghex102(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 27 at pos 23
*/

            ghex103::ghex103(void) :
            ghex() {};

            ghex103::ghex103(
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

            long ghex103::nnodes(void) const {
               return 23;
            }

            el_types ghex103::get_type() const {
               return GHEX103;
            }

            const std::set<el_processor> ghex103::processors(procs, procs+procs_len);

            ghex103::ghex103(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex103::ghex103(
               const cards::gelref1 *data) : ghex(data) {}

            ghex103::ghex103(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 27 at pos 22
*/

            ghex104::ghex104(void) :
            ghex() {};

            ghex104::ghex104(
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

            long ghex104::nnodes(void) const {
               return 22;
            }

            el_types ghex104::get_type() const {
               return GHEX104;
            }

            const std::set<el_processor> ghex104::processors(procs, procs+procs_len);

            ghex104::ghex104(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex104::ghex104(
               const cards::gelref1 *data) : ghex(data) {}

            ghex104::ghex104(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
*/

            ghex105::ghex105(void) :
            ghex() {};

            ghex105::ghex105(
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

            long ghex105::nnodes(void) const {
               return 23;
            }

            el_types ghex105::get_type() const {
               return GHEX105;
            }

            const std::set<el_processor> ghex105::processors(procs, procs+procs_len);

            ghex105::ghex105(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex105::ghex105(
               const cards::gelref1 *data) : ghex(data) {}

            ghex105::ghex105(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
*/

            ghex106::ghex106(void) :
            ghex() {};

            ghex106::ghex106(
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

            long ghex106::nnodes(void) const {
               return 23;
            }

            el_types ghex106::get_type() const {
               return GHEX106;
            }

            const std::set<el_processor> ghex106::processors(procs, procs+procs_len);

            ghex106::ghex106(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex106::ghex106(
               const cards::gelref1 *data) : ghex(data) {}

            ghex106::ghex106(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 27 at pos 24
*/

            ghex107::ghex107(void) :
            ghex() {};

            ghex107::ghex107(
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

            long ghex107::nnodes(void) const {
               return 24;
            }

            el_types ghex107::get_type() const {
               return GHEX107;
            }

            const std::set<el_processor> ghex107::processors(procs, procs+procs_len);

            ghex107::ghex107(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex107::ghex107(
               const cards::gelref1 *data) : ghex(data) {}

            ghex107::ghex107(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 27 at pos 22
*/

            ghex108::ghex108(void) :
            ghex() {};

            ghex108::ghex108(
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

            long ghex108::nnodes(void) const {
               return 22;
            }

            el_types ghex108::get_type() const {
               return GHEX108;
            }

            const std::set<el_processor> ghex108::processors(procs, procs+procs_len);

            ghex108::ghex108(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex108::ghex108(
               const cards::gelref1 *data) : ghex(data) {}

            ghex108::ghex108(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
*/

            ghex109::ghex109(void) :
            ghex() {};

            ghex109::ghex109(
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

            long ghex109::nnodes(void) const {
               return 23;
            }

            el_types ghex109::get_type() const {
               return GHEX109;
            }

            const std::set<el_processor> ghex109::processors(procs, procs+procs_len);

            ghex109::ghex109(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex109::ghex109(
               const cards::gelref1 *data) : ghex(data) {}

            ghex109::ghex109(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
*/

            ghex110::ghex110(void) :
            ghex() {};

            ghex110::ghex110(
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

            long ghex110::nnodes(void) const {
               return 23;
            }

            el_types ghex110::get_type() const {
               return GHEX110;
            }

            const std::set<el_processor> ghex110::processors(procs, procs+procs_len);

            ghex110::ghex110(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex110::ghex110(
               const cards::gelref1 *data) : ghex(data) {}

            ghex110::ghex110(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
*/

            ghex111::ghex111(void) :
            ghex() {};

            ghex111::ghex111(
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

            long ghex111::nnodes(void) const {
               return 24;
            }

            el_types ghex111::get_type() const {
               return GHEX111;
            }

            const std::set<el_processor> ghex111::processors(procs, procs+procs_len);

            ghex111::ghex111(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex111::ghex111(
               const cards::gelref1 *data) : ghex(data) {}

            ghex111::ghex111(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
*/

            ghex112::ghex112(void) :
            ghex() {};

            ghex112::ghex112(
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

            long ghex112::nnodes(void) const {
               return 23;
            }

            el_types ghex112::get_type() const {
               return GHEX112;
            }

            const std::set<el_processor> ghex112::processors(procs, procs+procs_len);

            ghex112::ghex112(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex112::ghex112(
               const cards::gelref1 *data) : ghex(data) {}

            ghex112::ghex112(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
*/

            ghex113::ghex113(void) :
            ghex() {};

            ghex113::ghex113(
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

            long ghex113::nnodes(void) const {
               return 24;
            }

            el_types ghex113::get_type() const {
               return GHEX113;
            }

            const std::set<el_processor> ghex113::processors(procs, procs+procs_len);

            ghex113::ghex113(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex113::ghex113(
               const cards::gelref1 *data) : ghex(data) {}

            ghex113::ghex113(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
*/

            ghex114::ghex114(void) :
            ghex() {};

            ghex114::ghex114(
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

            long ghex114::nnodes(void) const {
               return 24;
            }

            el_types ghex114::get_type() const {
               return GHEX114;
            }

            const std::set<el_processor> ghex114::processors(procs, procs+procs_len);

            ghex114::ghex114(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex114::ghex114(
               const cards::gelref1 *data) : ghex(data) {}

            ghex114::ghex114(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 27 at pos 25
*/

            ghex115::ghex115(void) :
            ghex() {};

            ghex115::ghex115(
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

            long ghex115::nnodes(void) const {
               return 25;
            }

            el_types ghex115::get_type() const {
               return GHEX115;
            }

            const std::set<el_processor> ghex115::processors(procs, procs+procs_len);

            ghex115::ghex115(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex115::ghex115(
               const cards::gelref1 *data) : ghex(data) {}

            ghex115::ghex115(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 27 at pos 22
*/

            ghex116::ghex116(void) :
            ghex() {};

            ghex116::ghex116(
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

            long ghex116::nnodes(void) const {
               return 22;
            }

            el_types ghex116::get_type() const {
               return GHEX116;
            }

            const std::set<el_processor> ghex116::processors(procs, procs+procs_len);

            ghex116::ghex116(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex116::ghex116(
               const cards::gelref1 *data) : ghex(data) {}

            ghex116::ghex116(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

            ghex117::ghex117(void) :
            ghex() {};

            ghex117::ghex117(
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

            long ghex117::nnodes(void) const {
               return 23;
            }

            el_types ghex117::get_type() const {
               return GHEX117;
            }

            const std::set<el_processor> ghex117::processors(procs, procs+procs_len);

            ghex117::ghex117(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex117::ghex117(
               const cards::gelref1 *data) : ghex(data) {}

            ghex117::ghex117(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

            ghex118::ghex118(void) :
            ghex() {};

            ghex118::ghex118(
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

            long ghex118::nnodes(void) const {
               return 23;
            }

            el_types ghex118::get_type() const {
               return GHEX118;
            }

            const std::set<el_processor> ghex118::processors(procs, procs+procs_len);

            ghex118::ghex118(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex118::ghex118(
               const cards::gelref1 *data) : ghex(data) {}

            ghex118::ghex118(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

            ghex119::ghex119(void) :
            ghex() {};

            ghex119::ghex119(
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

            long ghex119::nnodes(void) const {
               return 24;
            }

            el_types ghex119::get_type() const {
               return GHEX119;
            }

            const std::set<el_processor> ghex119::processors(procs, procs+procs_len);

            ghex119::ghex119(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex119::ghex119(
               const cards::gelref1 *data) : ghex(data) {}

            ghex119::ghex119(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

            ghex120::ghex120(void) :
            ghex() {};

            ghex120::ghex120(
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

            long ghex120::nnodes(void) const {
               return 23;
            }

            el_types ghex120::get_type() const {
               return GHEX120;
            }

            const std::set<el_processor> ghex120::processors(procs, procs+procs_len);

            ghex120::ghex120(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex120::ghex120(
               const cards::gelref1 *data) : ghex(data) {}

            ghex120::ghex120(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

            ghex121::ghex121(void) :
            ghex() {};

            ghex121::ghex121(
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

            long ghex121::nnodes(void) const {
               return 24;
            }

            el_types ghex121::get_type() const {
               return GHEX121;
            }

            const std::set<el_processor> ghex121::processors(procs, procs+procs_len);

            ghex121::ghex121(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex121::ghex121(
               const cards::gelref1 *data) : ghex(data) {}

            ghex121::ghex121(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

            ghex122::ghex122(void) :
            ghex() {};

            ghex122::ghex122(
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

            long ghex122::nnodes(void) const {
               return 24;
            }

            el_types ghex122::get_type() const {
               return GHEX122;
            }

            const std::set<el_processor> ghex122::processors(procs, procs+procs_len);

            ghex122::ghex122(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex122::ghex122(
               const cards::gelref1 *data) : ghex(data) {}

            ghex122::ghex122(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
*/

            ghex123::ghex123(void) :
            ghex() {};

            ghex123::ghex123(
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

            long ghex123::nnodes(void) const {
               return 25;
            }

            el_types ghex123::get_type() const {
               return GHEX123;
            }

            const std::set<el_processor> ghex123::processors(procs, procs+procs_len);

            ghex123::ghex123(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex123::ghex123(
               const cards::gelref1 *data) : ghex(data) {}

            ghex123::ghex123(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

            ghex124::ghex124(void) :
            ghex() {};

            ghex124::ghex124(
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

            long ghex124::nnodes(void) const {
               return 23;
            }

            el_types ghex124::get_type() const {
               return GHEX124;
            }

            const std::set<el_processor> ghex124::processors(procs, procs+procs_len);

            ghex124::ghex124(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex124::ghex124(
               const cards::gelref1 *data) : ghex(data) {}

            ghex124::ghex124(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

            ghex125::ghex125(void) :
            ghex() {};

            ghex125::ghex125(
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

            long ghex125::nnodes(void) const {
               return 24;
            }

            el_types ghex125::get_type() const {
               return GHEX125;
            }

            const std::set<el_processor> ghex125::processors(procs, procs+procs_len);

            ghex125::ghex125(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex125::ghex125(
               const cards::gelref1 *data) : ghex(data) {}

            ghex125::ghex125(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

            ghex126::ghex126(void) :
            ghex() {};

            ghex126::ghex126(
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

            long ghex126::nnodes(void) const {
               return 24;
            }

            el_types ghex126::get_type() const {
               return GHEX126;
            }

            const std::set<el_processor> ghex126::processors(procs, procs+procs_len);

            ghex126::ghex126(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex126::ghex126(
               const cards::gelref1 *data) : ghex(data) {}

            ghex126::ghex126(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
*/

            ghex127::ghex127(void) :
            ghex() {};

            ghex127::ghex127(
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

            long ghex127::nnodes(void) const {
               return 25;
            }

            el_types ghex127::get_type() const {
               return GHEX127;
            }

            const std::set<el_processor> ghex127::processors(procs, procs+procs_len);

            ghex127::ghex127(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex127::ghex127(
               const cards::gelref1 *data) : ghex(data) {}

            ghex127::ghex127(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

            ghex128::ghex128(void) :
            ghex() {};

            ghex128::ghex128(
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

            long ghex128::nnodes(void) const {
               return 24;
            }

            el_types ghex128::get_type() const {
               return GHEX128;
            }

            const std::set<el_processor> ghex128::processors(procs, procs+procs_len);

            ghex128::ghex128(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex128::ghex128(
               const cards::gelref1 *data) : ghex(data) {}

            ghex128::ghex128(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
*/

            ghex129::ghex129(void) :
            ghex() {};

            ghex129::ghex129(
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

            long ghex129::nnodes(void) const {
               return 25;
            }

            el_types ghex129::get_type() const {
               return GHEX129;
            }

            const std::set<el_processor> ghex129::processors(procs, procs+procs_len);

            ghex129::ghex129(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex129::ghex129(
               const cards::gelref1 *data) : ghex(data) {}

            ghex129::ghex129(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
*/

            ghex130::ghex130(void) :
            ghex() {};

            ghex130::ghex130(
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

            long ghex130::nnodes(void) const {
               return 25;
            }

            el_types ghex130::get_type() const {
               return GHEX130;
            }

            const std::set<el_processor> ghex130::processors(procs, procs+procs_len);

            ghex130::ghex130(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex130::ghex130(
               const cards::gelref1 *data) : ghex(data) {}

            ghex130::ghex130(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 25 at pos 25
                    - node 27 at pos 26
*/

            ghex131::ghex131(void) :
            ghex() {};

            ghex131::ghex131(
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

            long ghex131::nnodes(void) const {
               return 26;
            }

            el_types ghex131::get_type() const {
               return GHEX131;
            }

            const std::set<el_processor> ghex131::processors(procs, procs+procs_len);

            ghex131::ghex131(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex131::ghex131(
               const cards::gelref1 *data) : ghex(data) {}

            ghex131::ghex131(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 26 at pos 21
                    - node 27 at pos 22
*/

            ghex132::ghex132(void) :
            ghex() {};

            ghex132::ghex132(
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

            long ghex132::nnodes(void) const {
               return 22;
            }

            el_types ghex132::get_type() const {
               return GHEX132;
            }

            const std::set<el_processor> ghex132::processors(procs, procs+procs_len);

            ghex132::ghex132(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex132::ghex132(
               const cards::gelref1 *data) : ghex(data) {}

            ghex132::ghex132(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

            ghex133::ghex133(void) :
            ghex() {};

            ghex133::ghex133(
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

            long ghex133::nnodes(void) const {
               return 23;
            }

            el_types ghex133::get_type() const {
               return GHEX133;
            }

            const std::set<el_processor> ghex133::processors(procs, procs+procs_len);

            ghex133::ghex133(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex133::ghex133(
               const cards::gelref1 *data) : ghex(data) {}

            ghex133::ghex133(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

            ghex134::ghex134(void) :
            ghex() {};

            ghex134::ghex134(
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

            long ghex134::nnodes(void) const {
               return 23;
            }

            el_types ghex134::get_type() const {
               return GHEX134;
            }

            const std::set<el_processor> ghex134::processors(procs, procs+procs_len);

            ghex134::ghex134(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex134::ghex134(
               const cards::gelref1 *data) : ghex(data) {}

            ghex134::ghex134(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex135::ghex135(void) :
            ghex() {};

            ghex135::ghex135(
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

            long ghex135::nnodes(void) const {
               return 24;
            }

            el_types ghex135::get_type() const {
               return GHEX135;
            }

            const std::set<el_processor> ghex135::processors(procs, procs+procs_len);

            ghex135::ghex135(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex135::ghex135(
               const cards::gelref1 *data) : ghex(data) {}

            ghex135::ghex135(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

            ghex136::ghex136(void) :
            ghex() {};

            ghex136::ghex136(
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

            long ghex136::nnodes(void) const {
               return 23;
            }

            el_types ghex136::get_type() const {
               return GHEX136;
            }

            const std::set<el_processor> ghex136::processors(procs, procs+procs_len);

            ghex136::ghex136(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex136::ghex136(
               const cards::gelref1 *data) : ghex(data) {}

            ghex136::ghex136(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex137::ghex137(void) :
            ghex() {};

            ghex137::ghex137(
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

            long ghex137::nnodes(void) const {
               return 24;
            }

            el_types ghex137::get_type() const {
               return GHEX137;
            }

            const std::set<el_processor> ghex137::processors(procs, procs+procs_len);

            ghex137::ghex137(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex137::ghex137(
               const cards::gelref1 *data) : ghex(data) {}

            ghex137::ghex137(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex138::ghex138(void) :
            ghex() {};

            ghex138::ghex138(
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

            long ghex138::nnodes(void) const {
               return 24;
            }

            el_types ghex138::get_type() const {
               return GHEX138;
            }

            const std::set<el_processor> ghex138::processors(procs, procs+procs_len);

            ghex138::ghex138(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex138::ghex138(
               const cards::gelref1 *data) : ghex(data) {}

            ghex138::ghex138(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex139::ghex139(void) :
            ghex() {};

            ghex139::ghex139(
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

            long ghex139::nnodes(void) const {
               return 25;
            }

            el_types ghex139::get_type() const {
               return GHEX139;
            }

            const std::set<el_processor> ghex139::processors(procs, procs+procs_len);

            ghex139::ghex139(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex139::ghex139(
               const cards::gelref1 *data) : ghex(data) {}

            ghex139::ghex139(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

            ghex140::ghex140(void) :
            ghex() {};

            ghex140::ghex140(
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

            long ghex140::nnodes(void) const {
               return 23;
            }

            el_types ghex140::get_type() const {
               return GHEX140;
            }

            const std::set<el_processor> ghex140::processors(procs, procs+procs_len);

            ghex140::ghex140(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex140::ghex140(
               const cards::gelref1 *data) : ghex(data) {}

            ghex140::ghex140(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex141::ghex141(void) :
            ghex() {};

            ghex141::ghex141(
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

            long ghex141::nnodes(void) const {
               return 24;
            }

            el_types ghex141::get_type() const {
               return GHEX141;
            }

            const std::set<el_processor> ghex141::processors(procs, procs+procs_len);

            ghex141::ghex141(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex141::ghex141(
               const cards::gelref1 *data) : ghex(data) {}

            ghex141::ghex141(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex142::ghex142(void) :
            ghex() {};

            ghex142::ghex142(
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

            long ghex142::nnodes(void) const {
               return 24;
            }

            el_types ghex142::get_type() const {
               return GHEX142;
            }

            const std::set<el_processor> ghex142::processors(procs, procs+procs_len);

            ghex142::ghex142(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex142::ghex142(
               const cards::gelref1 *data) : ghex(data) {}

            ghex142::ghex142(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex143::ghex143(void) :
            ghex() {};

            ghex143::ghex143(
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

            long ghex143::nnodes(void) const {
               return 25;
            }

            el_types ghex143::get_type() const {
               return GHEX143;
            }

            const std::set<el_processor> ghex143::processors(procs, procs+procs_len);

            ghex143::ghex143(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex143::ghex143(
               const cards::gelref1 *data) : ghex(data) {}

            ghex143::ghex143(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex144::ghex144(void) :
            ghex() {};

            ghex144::ghex144(
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

            long ghex144::nnodes(void) const {
               return 24;
            }

            el_types ghex144::get_type() const {
               return GHEX144;
            }

            const std::set<el_processor> ghex144::processors(procs, procs+procs_len);

            ghex144::ghex144(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex144::ghex144(
               const cards::gelref1 *data) : ghex(data) {}

            ghex144::ghex144(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex145::ghex145(void) :
            ghex() {};

            ghex145::ghex145(
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

            long ghex145::nnodes(void) const {
               return 25;
            }

            el_types ghex145::get_type() const {
               return GHEX145;
            }

            const std::set<el_processor> ghex145::processors(procs, procs+procs_len);

            ghex145::ghex145(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex145::ghex145(
               const cards::gelref1 *data) : ghex(data) {}

            ghex145::ghex145(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex146::ghex146(void) :
            ghex() {};

            ghex146::ghex146(
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

            long ghex146::nnodes(void) const {
               return 25;
            }

            el_types ghex146::get_type() const {
               return GHEX146;
            }

            const std::set<el_processor> ghex146::processors(procs, procs+procs_len);

            ghex146::ghex146(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex146::ghex146(
               const cards::gelref1 *data) : ghex(data) {}

            ghex146::ghex146(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
*/

            ghex147::ghex147(void) :
            ghex() {};

            ghex147::ghex147(
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

            long ghex147::nnodes(void) const {
               return 26;
            }

            el_types ghex147::get_type() const {
               return GHEX147;
            }

            const std::set<el_processor> ghex147::processors(procs, procs+procs_len);

            ghex147::ghex147(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex147::ghex147(
               const cards::gelref1 *data) : ghex(data) {}

            ghex147::ghex147(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

            ghex148::ghex148(void) :
            ghex() {};

            ghex148::ghex148(
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

            long ghex148::nnodes(void) const {
               return 23;
            }

            el_types ghex148::get_type() const {
               return GHEX148;
            }

            const std::set<el_processor> ghex148::processors(procs, procs+procs_len);

            ghex148::ghex148(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex148::ghex148(
               const cards::gelref1 *data) : ghex(data) {}

            ghex148::ghex148(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex149::ghex149(void) :
            ghex() {};

            ghex149::ghex149(
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

            long ghex149::nnodes(void) const {
               return 24;
            }

            el_types ghex149::get_type() const {
               return GHEX149;
            }

            const std::set<el_processor> ghex149::processors(procs, procs+procs_len);

            ghex149::ghex149(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex149::ghex149(
               const cards::gelref1 *data) : ghex(data) {}

            ghex149::ghex149(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex150::ghex150(void) :
            ghex() {};

            ghex150::ghex150(
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

            long ghex150::nnodes(void) const {
               return 24;
            }

            el_types ghex150::get_type() const {
               return GHEX150;
            }

            const std::set<el_processor> ghex150::processors(procs, procs+procs_len);

            ghex150::ghex150(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex150::ghex150(
               const cards::gelref1 *data) : ghex(data) {}

            ghex150::ghex150(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex151::ghex151(void) :
            ghex() {};

            ghex151::ghex151(
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

            long ghex151::nnodes(void) const {
               return 25;
            }

            el_types ghex151::get_type() const {
               return GHEX151;
            }

            const std::set<el_processor> ghex151::processors(procs, procs+procs_len);

            ghex151::ghex151(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex151::ghex151(
               const cards::gelref1 *data) : ghex(data) {}

            ghex151::ghex151(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex152::ghex152(void) :
            ghex() {};

            ghex152::ghex152(
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

            long ghex152::nnodes(void) const {
               return 24;
            }

            el_types ghex152::get_type() const {
               return GHEX152;
            }

            const std::set<el_processor> ghex152::processors(procs, procs+procs_len);

            ghex152::ghex152(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex152::ghex152(
               const cards::gelref1 *data) : ghex(data) {}

            ghex152::ghex152(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex153::ghex153(void) :
            ghex() {};

            ghex153::ghex153(
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

            long ghex153::nnodes(void) const {
               return 25;
            }

            el_types ghex153::get_type() const {
               return GHEX153;
            }

            const std::set<el_processor> ghex153::processors(procs, procs+procs_len);

            ghex153::ghex153(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex153::ghex153(
               const cards::gelref1 *data) : ghex(data) {}

            ghex153::ghex153(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex154::ghex154(void) :
            ghex() {};

            ghex154::ghex154(
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

            long ghex154::nnodes(void) const {
               return 25;
            }

            el_types ghex154::get_type() const {
               return GHEX154;
            }

            const std::set<el_processor> ghex154::processors(procs, procs+procs_len);

            ghex154::ghex154(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex154::ghex154(
               const cards::gelref1 *data) : ghex(data) {}

            ghex154::ghex154(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
*/

            ghex155::ghex155(void) :
            ghex() {};

            ghex155::ghex155(
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

            long ghex155::nnodes(void) const {
               return 26;
            }

            el_types ghex155::get_type() const {
               return GHEX155;
            }

            const std::set<el_processor> ghex155::processors(procs, procs+procs_len);

            ghex155::ghex155(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex155::ghex155(
               const cards::gelref1 *data) : ghex(data) {}

            ghex155::ghex155(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

            ghex156::ghex156(void) :
            ghex() {};

            ghex156::ghex156(
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

            long ghex156::nnodes(void) const {
               return 24;
            }

            el_types ghex156::get_type() const {
               return GHEX156;
            }

            const std::set<el_processor> ghex156::processors(procs, procs+procs_len);

            ghex156::ghex156(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex156::ghex156(
               const cards::gelref1 *data) : ghex(data) {}

            ghex156::ghex156(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex157::ghex157(void) :
            ghex() {};

            ghex157::ghex157(
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

            long ghex157::nnodes(void) const {
               return 25;
            }

            el_types ghex157::get_type() const {
               return GHEX157;
            }

            const std::set<el_processor> ghex157::processors(procs, procs+procs_len);

            ghex157::ghex157(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex157::ghex157(
               const cards::gelref1 *data) : ghex(data) {}

            ghex157::ghex157(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex158::ghex158(void) :
            ghex() {};

            ghex158::ghex158(
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

            long ghex158::nnodes(void) const {
               return 25;
            }

            el_types ghex158::get_type() const {
               return GHEX158;
            }

            const std::set<el_processor> ghex158::processors(procs, procs+procs_len);

            ghex158::ghex158(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex158::ghex158(
               const cards::gelref1 *data) : ghex(data) {}

            ghex158::ghex158(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
*/

            ghex159::ghex159(void) :
            ghex() {};

            ghex159::ghex159(
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

            long ghex159::nnodes(void) const {
               return 26;
            }

            el_types ghex159::get_type() const {
               return GHEX159;
            }

            const std::set<el_processor> ghex159::processors(procs, procs+procs_len);

            ghex159::ghex159(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex159::ghex159(
               const cards::gelref1 *data) : ghex(data) {}

            ghex159::ghex159(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
*/

            ghex160::ghex160(void) :
            ghex() {};

            ghex160::ghex160(
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

            long ghex160::nnodes(void) const {
               return 25;
            }

            el_types ghex160::get_type() const {
               return GHEX160;
            }

            const std::set<el_processor> ghex160::processors(procs, procs+procs_len);

            ghex160::ghex160(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex160::ghex160(
               const cards::gelref1 *data) : ghex(data) {}

            ghex160::ghex160(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
*/

            ghex161::ghex161(void) :
            ghex() {};

            ghex161::ghex161(
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

            long ghex161::nnodes(void) const {
               return 26;
            }

            el_types ghex161::get_type() const {
               return GHEX161;
            }

            const std::set<el_processor> ghex161::processors(procs, procs+procs_len);

            ghex161::ghex161(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex161::ghex161(
               const cards::gelref1 *data) : ghex(data) {}

            ghex161::ghex161(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
*/

            ghex162::ghex162(void) :
            ghex() {};

            ghex162::ghex162(
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

            long ghex162::nnodes(void) const {
               return 26;
            }

            el_types ghex162::get_type() const {
               return GHEX162;
            }

            const std::set<el_processor> ghex162::processors(procs, procs+procs_len);

            ghex162::ghex162(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex162::ghex162(
               const cards::gelref1 *data) : ghex(data) {}

            ghex162::ghex162(
               const __base::elem *data) :
            ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 25 at pos 25
                    - node 26 at pos 26
                    - node 27 at pos 27
*/

            ghex163::ghex163(void) :
            ghex() {};

            ghex163::ghex163(
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

            long ghex163::nnodes(void) const {
               return 27;
            }

            el_types ghex163::get_type() const {
               return GHEX163;
            }

            const std::set<el_processor> ghex163::processors(procs, procs+procs_len);

            ghex163::ghex163(
               const cards::gelmnt1 *data) : ghex(data) {}

            ghex163::ghex163(
               const cards::gelref1 *data) : ghex(data) {}

            ghex163::ghex163(
               const __base::elem *data) :
            ghex(data) {}

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