/**
   \brief ghex* element card representation for Sesam FEM.
   \file fem/elements_ghex.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE

   General Hexahedron elements.
*/

// ID: $Id$

#ifndef _FEM_CARDS_ELEMENTS_GHEX_H_
#define _FEM_CARDS_ELEMENTS_GHEX_H_

#include <my_c++14.h>

#include <set>

#include "cards.h"

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace elements {

            /** General Hexahedron
             */
            class ghex : public __base::elem {
            public:
               ghex(void);
               ghex(long const elno,
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
                    std::vector<long> const csys);
               ghex(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex(const dnvgl::extfem::fem::cards::gelref1*);
               ghex(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const = 0;
               virtual el_types get_type(void) const = 0;
            };

            /** General Hexahedron, define with nodes 1 to 20 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 27 at pos 21
             */
            class ghex100: public ghex {
            public:
               ghex100(void);
               ghex100(
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
                  std::vector<long> const csys);
               ghex100(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex100(const dnvgl::extfem::fem::cards::gelref1*);
               ghex100(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 27 at pos 22
             */
            class ghex101: public ghex {
            public:
               ghex101(void);
               ghex101(
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
                  std::vector<long> const csys);
               ghex101(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex101(const dnvgl::extfem::fem::cards::gelref1*);
               ghex101(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 27 at pos 22
             */
            class ghex102: public ghex {
            public:
               ghex102(void);
               ghex102(
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
                  std::vector<long> const csys);
               ghex102(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex102(const dnvgl::extfem::fem::cards::gelref1*);
               ghex102(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 27 at pos 23
             */
            class ghex103: public ghex {
            public:
               ghex103(void);
               ghex103(
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
                  std::vector<long> const csys);
               ghex103(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex103(const dnvgl::extfem::fem::cards::gelref1*);
               ghex103(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 27 at pos 22
             */
            class ghex104: public ghex {
            public:
               ghex104(void);
               ghex104(
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
                  std::vector<long> const csys);
               ghex104(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex104(const dnvgl::extfem::fem::cards::gelref1*);
               ghex104(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
             */
            class ghex105: public ghex {
            public:
               ghex105(void);
               ghex105(
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
                  std::vector<long> const csys);
               ghex105(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex105(const dnvgl::extfem::fem::cards::gelref1*);
               ghex105(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
             */
            class ghex106: public ghex {
            public:
               ghex106(void);
               ghex106(
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
                  std::vector<long> const csys);
               ghex106(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex106(const dnvgl::extfem::fem::cards::gelref1*);
               ghex106(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 27 at pos 24
             */
            class ghex107: public ghex {
            public:
               ghex107(void);
               ghex107(
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
                  std::vector<long> const csys);
               ghex107(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex107(const dnvgl::extfem::fem::cards::gelref1*);
               ghex107(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 27 at pos 22
             */
            class ghex108: public ghex {
            public:
               ghex108(void);
               ghex108(
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
                  std::vector<long> const csys);
               ghex108(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex108(const dnvgl::extfem::fem::cards::gelref1*);
               ghex108(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex109: public ghex {
            public:
               ghex109(void);
               ghex109(
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
                  std::vector<long> const csys);
               ghex109(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex109(const dnvgl::extfem::fem::cards::gelref1*);
               ghex109(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex110: public ghex {
            public:
               ghex110(void);
               ghex110(
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
                  std::vector<long> const csys);
               ghex110(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex110(const dnvgl::extfem::fem::cards::gelref1*);
               ghex110(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
             */
            class ghex111: public ghex {
            public:
               ghex111(void);
               ghex111(
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
                  std::vector<long> const csys);
               ghex111(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex111(const dnvgl::extfem::fem::cards::gelref1*);
               ghex111(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex112: public ghex {
            public:
               ghex112(void);
               ghex112(
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
                  std::vector<long> const csys);
               ghex112(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex112(const dnvgl::extfem::fem::cards::gelref1*);
               ghex112(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
             */
            class ghex113: public ghex {
            public:
               ghex113(void);
               ghex113(
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
                  std::vector<long> const csys);
               ghex113(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex113(const dnvgl::extfem::fem::cards::gelref1*);
               ghex113(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
             */
            class ghex114: public ghex {
            public:
               ghex114(void);
               ghex114(
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
                  std::vector<long> const csys);
               ghex114(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex114(const dnvgl::extfem::fem::cards::gelref1*);
               ghex114(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 27 at pos 25
             */
            class ghex115: public ghex {
            public:
               ghex115(void);
               ghex115(
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
                  std::vector<long> const csys);
               ghex115(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex115(const dnvgl::extfem::fem::cards::gelref1*);
               ghex115(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 27 at pos 22
             */
            class ghex116: public ghex {
            public:
               ghex116(void);
               ghex116(
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
                  std::vector<long> const csys);
               ghex116(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex116(const dnvgl::extfem::fem::cards::gelref1*);
               ghex116(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex117: public ghex {
            public:
               ghex117(void);
               ghex117(
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
                  std::vector<long> const csys);
               ghex117(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex117(const dnvgl::extfem::fem::cards::gelref1*);
               ghex117(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex118: public ghex {
            public:
               ghex118(void);
               ghex118(
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
                  std::vector<long> const csys);
               ghex118(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex118(const dnvgl::extfem::fem::cards::gelref1*);
               ghex118(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex119: public ghex {
            public:
               ghex119(void);
               ghex119(
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
                  std::vector<long> const csys);
               ghex119(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex119(const dnvgl::extfem::fem::cards::gelref1*);
               ghex119(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex120: public ghex {
            public:
               ghex120(void);
               ghex120(
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
                  std::vector<long> const csys);
               ghex120(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex120(const dnvgl::extfem::fem::cards::gelref1*);
               ghex120(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex121: public ghex {
            public:
               ghex121(void);
               ghex121(
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
                  std::vector<long> const csys);
               ghex121(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex121(const dnvgl::extfem::fem::cards::gelref1*);
               ghex121(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex122: public ghex {
            public:
               ghex122(void);
               ghex122(
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
                  std::vector<long> const csys);
               ghex122(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex122(const dnvgl::extfem::fem::cards::gelref1*);
               ghex122(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex123: public ghex {
            public:
               ghex123(void);
               ghex123(
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
                  std::vector<long> const csys);
               ghex123(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex123(const dnvgl::extfem::fem::cards::gelref1*);
               ghex123(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex124: public ghex {
            public:
               ghex124(void);
               ghex124(
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
                  std::vector<long> const csys);
               ghex124(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex124(const dnvgl::extfem::fem::cards::gelref1*);
               ghex124(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex125: public ghex {
            public:
               ghex125(void);
               ghex125(
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
                  std::vector<long> const csys);
               ghex125(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex125(const dnvgl::extfem::fem::cards::gelref1*);
               ghex125(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex126: public ghex {
            public:
               ghex126(void);
               ghex126(
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
                  std::vector<long> const csys);
               ghex126(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex126(const dnvgl::extfem::fem::cards::gelref1*);
               ghex126(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex127: public ghex {
            public:
               ghex127(void);
               ghex127(
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
                  std::vector<long> const csys);
               ghex127(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex127(const dnvgl::extfem::fem::cards::gelref1*);
               ghex127(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
             */
            class ghex128: public ghex {
            public:
               ghex128(void);
               ghex128(
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
                  std::vector<long> const csys);
               ghex128(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex128(const dnvgl::extfem::fem::cards::gelref1*);
               ghex128(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex129: public ghex {
            public:
               ghex129(void);
               ghex129(
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
                  std::vector<long> const csys);
               ghex129(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex129(const dnvgl::extfem::fem::cards::gelref1*);
               ghex129(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 27 at pos 25
             */
            class ghex130: public ghex {
            public:
               ghex130(void);
               ghex130(
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
                  std::vector<long> const csys);
               ghex130(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex130(const dnvgl::extfem::fem::cards::gelref1*);
               ghex130(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 25 at pos 25
                    - node 27 at pos 26
             */
            class ghex131: public ghex {
            public:
               ghex131(void);
               ghex131(
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
                  std::vector<long> const csys);
               ghex131(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex131(const dnvgl::extfem::fem::cards::gelref1*);
               ghex131(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 26 at pos 21
                    - node 27 at pos 22
             */
            class ghex132: public ghex {
            public:
               ghex132(void);
               ghex132(
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
                  std::vector<long> const csys);
               ghex132(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex132(const dnvgl::extfem::fem::cards::gelref1*);
               ghex132(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex133: public ghex {
            public:
               ghex133(void);
               ghex133(
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
                  std::vector<long> const csys);
               ghex133(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex133(const dnvgl::extfem::fem::cards::gelref1*);
               ghex133(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex134: public ghex {
            public:
               ghex134(void);
               ghex134(
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
                  std::vector<long> const csys);
               ghex134(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex134(const dnvgl::extfem::fem::cards::gelref1*);
               ghex134(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex135: public ghex {
            public:
               ghex135(void);
               ghex135(
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
                  std::vector<long> const csys);
               ghex135(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex135(const dnvgl::extfem::fem::cards::gelref1*);
               ghex135(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex136: public ghex {
            public:
               ghex136(void);
               ghex136(
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
                  std::vector<long> const csys);
               ghex136(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex136(const dnvgl::extfem::fem::cards::gelref1*);
               ghex136(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex137: public ghex {
            public:
               ghex137(void);
               ghex137(
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
                  std::vector<long> const csys);
               ghex137(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex137(const dnvgl::extfem::fem::cards::gelref1*);
               ghex137(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex138: public ghex {
            public:
               ghex138(void);
               ghex138(
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
                  std::vector<long> const csys);
               ghex138(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex138(const dnvgl::extfem::fem::cards::gelref1*);
               ghex138(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex139: public ghex {
            public:
               ghex139(void);
               ghex139(
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
                  std::vector<long> const csys);
               ghex139(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex139(const dnvgl::extfem::fem::cards::gelref1*);
               ghex139(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex140: public ghex {
            public:
               ghex140(void);
               ghex140(
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
                  std::vector<long> const csys);
               ghex140(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex140(const dnvgl::extfem::fem::cards::gelref1*);
               ghex140(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex141: public ghex {
            public:
               ghex141(void);
               ghex141(
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
                  std::vector<long> const csys);
               ghex141(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex141(const dnvgl::extfem::fem::cards::gelref1*);
               ghex141(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex142: public ghex {
            public:
               ghex142(void);
               ghex142(
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
                  std::vector<long> const csys);
               ghex142(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex142(const dnvgl::extfem::fem::cards::gelref1*);
               ghex142(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex143: public ghex {
            public:
               ghex143(void);
               ghex143(
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
                  std::vector<long> const csys);
               ghex143(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex143(const dnvgl::extfem::fem::cards::gelref1*);
               ghex143(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex144: public ghex {
            public:
               ghex144(void);
               ghex144(
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
                  std::vector<long> const csys);
               ghex144(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex144(const dnvgl::extfem::fem::cards::gelref1*);
               ghex144(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex145: public ghex {
            public:
               ghex145(void);
               ghex145(
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
                  std::vector<long> const csys);
               ghex145(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex145(const dnvgl::extfem::fem::cards::gelref1*);
               ghex145(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex146: public ghex {
            public:
               ghex146(void);
               ghex146(
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
                  std::vector<long> const csys);
               ghex146(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex146(const dnvgl::extfem::fem::cards::gelref1*);
               ghex146(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex147: public ghex {
            public:
               ghex147(void);
               ghex147(
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
                  std::vector<long> const csys);
               ghex147(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex147(const dnvgl::extfem::fem::cards::gelref1*);
               ghex147(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex148: public ghex {
            public:
               ghex148(void);
               ghex148(
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
                  std::vector<long> const csys);
               ghex148(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex148(const dnvgl::extfem::fem::cards::gelref1*);
               ghex148(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex149: public ghex {
            public:
               ghex149(void);
               ghex149(
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
                  std::vector<long> const csys);
               ghex149(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex149(const dnvgl::extfem::fem::cards::gelref1*);
               ghex149(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex150: public ghex {
            public:
               ghex150(void);
               ghex150(
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
                  std::vector<long> const csys);
               ghex150(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex150(const dnvgl::extfem::fem::cards::gelref1*);
               ghex150(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex151: public ghex {
            public:
               ghex151(void);
               ghex151(
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
                  std::vector<long> const csys);
               ghex151(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex151(const dnvgl::extfem::fem::cards::gelref1*);
               ghex151(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex152: public ghex {
            public:
               ghex152(void);
               ghex152(
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
                  std::vector<long> const csys);
               ghex152(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex152(const dnvgl::extfem::fem::cards::gelref1*);
               ghex152(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex153: public ghex {
            public:
               ghex153(void);
               ghex153(
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
                  std::vector<long> const csys);
               ghex153(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex153(const dnvgl::extfem::fem::cards::gelref1*);
               ghex153(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex154: public ghex {
            public:
               ghex154(void);
               ghex154(
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
                  std::vector<long> const csys);
               ghex154(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex154(const dnvgl::extfem::fem::cards::gelref1*);
               ghex154(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex155: public ghex {
            public:
               ghex155(void);
               ghex155(
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
                  std::vector<long> const csys);
               ghex155(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex155(const dnvgl::extfem::fem::cards::gelref1*);
               ghex155(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
             */
            class ghex156: public ghex {
            public:
               ghex156(void);
               ghex156(
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
                  std::vector<long> const csys);
               ghex156(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex156(const dnvgl::extfem::fem::cards::gelref1*);
               ghex156(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex157: public ghex {
            public:
               ghex157(void);
               ghex157(
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
                  std::vector<long> const csys);
               ghex157(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex157(const dnvgl::extfem::fem::cards::gelref1*);
               ghex157(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex158: public ghex {
            public:
               ghex158(void);
               ghex158(
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
                  std::vector<long> const csys);
               ghex158(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex158(const dnvgl::extfem::fem::cards::gelref1*);
               ghex158(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex159: public ghex {
            public:
               ghex159(void);
               ghex159(
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
                  std::vector<long> const csys);
               ghex159(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex159(const dnvgl::extfem::fem::cards::gelref1*);
               ghex159(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 26 at pos 24
                    - node 27 at pos 25
             */
            class ghex160: public ghex {
            public:
               ghex160(void);
               ghex160(
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
                  std::vector<long> const csys);
               ghex160(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex160(const dnvgl::extfem::fem::cards::gelref1*);
               ghex160(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex161: public ghex {
            public:
               ghex161(void);
               ghex161(
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
                  std::vector<long> const csys);
               ghex161(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex161(const dnvgl::extfem::fem::cards::gelref1*);
               ghex161(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 25 at pos 24
                    - node 26 at pos 25
                    - node 27 at pos 26
             */
            class ghex162: public ghex {
            public:
               ghex162(void);
               ghex162(
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
                  std::vector<long> const csys);
               ghex162(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex162(const dnvgl::extfem::fem::cards::gelref1*);
               ghex162(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23, node 24, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 24 at pos 24
                    - node 25 at pos 25
                    - node 26 at pos 26
                    - node 27 at pos 27
             */
            class ghex163: public ghex {
            public:
               ghex163(void);
               ghex163(
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
                  std::vector<long> const csys);
               ghex163(const dnvgl::extfem::fem::cards::gelmnt1*);
               ghex163(const dnvgl::extfem::fem::cards::gelref1*);
               ghex163(const dnvgl::extfem::fem::elements::__base::elem*);
               virtual long nnodes(void) const;
               virtual el_types get_type(void) const;
               static const std::set<el_processor> processors;
            };

         }
      }
   }
}
#endif // _FEM_CARDS_ELEMENTS_GHEX_H_

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End: