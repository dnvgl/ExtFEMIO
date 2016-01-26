/**
   \file fem/elements_ghex.h
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief ghex* element card representation for Sesam FEM.

   Detailed description
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

            /** General Hexahedron, define with nodes 1 to 20 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 27 at pos 21
             */
            class ghex100: public ghex {
            public:
               ghex100(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex100(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 27 at pos 22
             */
            class ghex101: public ghex {
            public:
               ghex101(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex101(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 27 at pos 22
             */
            class ghex102: public ghex {
            public:
               ghex102(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex102(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 22 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 27 at pos 23
             */
            class ghex103: public ghex {
            public:
               ghex103(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex103(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 27 at pos 22
             */
            class ghex104: public ghex {
            public:
               ghex104(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex104(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 23 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
             */
            class ghex105: public ghex {
            public:
               ghex105(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex105(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 23 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
             */
            class ghex106: public ghex {
            public:
               ghex106(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex106(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex107(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex107(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 27 at pos 22
             */
            class ghex108: public ghex {
            public:
               ghex108(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex108(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex109: public ghex {
            public:
               ghex109(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex109(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex110: public ghex {
            public:
               ghex110(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex110(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex111(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex111(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 24 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
             */
            class ghex112: public ghex {
            public:
               ghex112(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex112(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex113(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex113(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex114(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex114(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex115(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex115(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 27 at pos 22
             */
            class ghex116: public ghex {
            public:
               ghex116(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex116(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex117: public ghex {
            public:
               ghex117(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex117(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex118: public ghex {
            public:
               ghex118(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex118(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex119(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex119(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex120: public ghex {
            public:
               ghex120(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex120(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex121(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex121(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex122(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex122(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex123(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex123(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 24, node 25 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
             */
            class ghex124: public ghex {
            public:
               ghex124(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex124(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex125(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex125(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex126(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex126(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex127(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex127(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex128(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex128(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex129(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex129(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex130(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex130(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex131(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex131(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 26 at pos 21
                    - node 27 at pos 22
             */
            class ghex132: public ghex {
            public:
               ghex132(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex132(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 21, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex133: public ghex {
            public:
               ghex133(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex133(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 22, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex134: public ghex {
            public:
               ghex134(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex134(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex135(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex135(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 23, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex136: public ghex {
            public:
               ghex136(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex136(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex137(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex137(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex138(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex138(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex139(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex139(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 24, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex140: public ghex {
            public:
               ghex140(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex140(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex141(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex141(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex142(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex142(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex143(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex143(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex144(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex144(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex145(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex145(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex146(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex146(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex147(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex147(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

            /** General Hexahedron, define with nodes 1 to 20, node 25, node 26 and node 27 present.

                Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
             */
            class ghex148: public ghex {
            public:
               ghex148(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex148(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex149(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex149(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex150(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex150(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex151(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex151(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex152(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex152(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex153(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex153(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex154(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex154(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex155(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex155(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex156(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex156(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex157(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex157(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex158(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex158(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex159(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex159(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex160(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex160(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex161(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex161(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex162(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex162(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
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
               ghex163(const ::dnvgl::extfem::fem::cards::gelmnt1*);
               ghex163(const ::dnvgl::extfem::fem::cards::gelref1*);
               static const long nnodes;
               el_types get_type(void) const;
               static const ::std::set<el_processor> processors;
            };

         }
      }
   }
}
#endif // _FEM_CARDS_ELEMENTS_GHEX_H_

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
