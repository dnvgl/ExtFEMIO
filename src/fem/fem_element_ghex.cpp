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

using namespace dnvgl::extfem::fem::elements;

namespace {
   const size_t procs_len = 2;
   el_processor procs[procs_len] = {general, Sestra};
}


/**
   General Hexahedron, define with nodes 1 to 20 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 27 at pos 21
*/

const long ghex100::nnodes = 21;

el_types ghex100::get_type() const {
   return GHEX100;
}

const std::set<el_processor> ghex100::processors(procs, procs+procs_len);

ghex100::ghex100(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex100::ghex100(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex100::ghex100(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 27 at pos 22
*/

const long ghex101::nnodes = 22;

el_types ghex101::get_type() const {
   return GHEX101;
}

const std::set<el_processor> ghex101::processors(procs, procs+procs_len);

ghex101::ghex101(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex101::ghex101(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex101::ghex101(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 27 at pos 22
*/

const long ghex102::nnodes = 22;

el_types ghex102::get_type() const {
   return GHEX102;
}

const std::set<el_processor> ghex102::processors(procs, procs+procs_len);

ghex102::ghex102(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex102::ghex102(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex102::ghex102(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 27 at pos 23
*/

const long ghex103::nnodes = 23;

el_types ghex103::get_type() const {
   return GHEX103;
}

const std::set<el_processor> ghex103::processors(procs, procs+procs_len);

ghex103::ghex103(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex103::ghex103(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex103::ghex103(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 27 at pos 22
*/

const long ghex104::nnodes = 22;

el_types ghex104::get_type() const {
   return GHEX104;
}

const std::set<el_processor> ghex104::processors(procs, procs+procs_len);

ghex104::ghex104(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex104::ghex104(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex104::ghex104(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
*/

const long ghex105::nnodes = 23;

el_types ghex105::get_type() const {
   return GHEX105;
}

const std::set<el_processor> ghex105::processors(procs, procs+procs_len);

ghex105::ghex105(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex105::ghex105(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex105::ghex105(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 27 at pos 23
*/

const long ghex106::nnodes = 23;

el_types ghex106::get_type() const {
   return GHEX106;
}

const std::set<el_processor> ghex106::processors(procs, procs+procs_len);

ghex106::ghex106(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex106::ghex106(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex106::ghex106(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 23 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 23 at pos 23
                    - node 27 at pos 24
*/

const long ghex107::nnodes = 24;

el_types ghex107::get_type() const {
   return GHEX107;
}

const std::set<el_processor> ghex107::processors(procs, procs+procs_len);

ghex107::ghex107(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex107::ghex107(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex107::ghex107(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 27 at pos 22
*/

const long ghex108::nnodes = 22;

el_types ghex108::get_type() const {
   return GHEX108;
}

const std::set<el_processor> ghex108::processors(procs, procs+procs_len);

ghex108::ghex108(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex108::ghex108(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex108::ghex108(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
*/

const long ghex109::nnodes = 23;

el_types ghex109::get_type() const {
   return GHEX109;
}

const std::set<el_processor> ghex109::processors(procs, procs+procs_len);

ghex109::ghex109(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex109::ghex109(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex109::ghex109(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
*/

const long ghex110::nnodes = 23;

el_types ghex110::get_type() const {
   return GHEX110;
}

const std::set<el_processor> ghex110::processors(procs, procs+procs_len);

ghex110::ghex110(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex110::ghex110(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex110::ghex110(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
*/

const long ghex111::nnodes = 24;

el_types ghex111::get_type() const {
   return GHEX111;
}

const std::set<el_processor> ghex111::processors(procs, procs+procs_len);

ghex111::ghex111(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex111::ghex111(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex111::ghex111(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 27 at pos 23
*/

const long ghex112::nnodes = 23;

el_types ghex112::get_type() const {
   return GHEX112;
}

const std::set<el_processor> ghex112::processors(procs, procs+procs_len);

ghex112::ghex112(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex112::ghex112(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex112::ghex112(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
*/

const long ghex113::nnodes = 24;

el_types ghex113::get_type() const {
   return GHEX113;
}

const std::set<el_processor> ghex113::processors(procs, procs+procs_len);

ghex113::ghex113(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex113::ghex113(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex113::ghex113(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 24 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 24 at pos 23
                    - node 27 at pos 24
*/

const long ghex114::nnodes = 24;

el_types ghex114::get_type() const {
   return GHEX114;
}

const std::set<el_processor> ghex114::processors(procs, procs+procs_len);

ghex114::ghex114(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex114::ghex114(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex114::ghex114(
   const __base *data) :
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

const long ghex115::nnodes = 25;

el_types ghex115::get_type() const {
   return GHEX115;
}

const std::set<el_processor> ghex115::processors(procs, procs+procs_len);

ghex115::ghex115(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex115::ghex115(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex115::ghex115(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 27 at pos 22
*/

const long ghex116::nnodes = 22;

el_types ghex116::get_type() const {
   return GHEX116;
}

const std::set<el_processor> ghex116::processors(procs, procs+procs_len);

ghex116::ghex116(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex116::ghex116(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex116::ghex116(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

const long ghex117::nnodes = 23;

el_types ghex117::get_type() const {
   return GHEX117;
}

const std::set<el_processor> ghex117::processors(procs, procs+procs_len);

ghex117::ghex117(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex117::ghex117(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex117::ghex117(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

const long ghex118::nnodes = 23;

el_types ghex118::get_type() const {
   return GHEX118;
}

const std::set<el_processor> ghex118::processors(procs, procs+procs_len);

ghex118::ghex118(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex118::ghex118(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex118::ghex118(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

const long ghex119::nnodes = 24;

el_types ghex119::get_type() const {
   return GHEX119;
}

const std::set<el_processor> ghex119::processors(procs, procs+procs_len);

ghex119::ghex119(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex119::ghex119(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex119::ghex119(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

const long ghex120::nnodes = 23;

el_types ghex120::get_type() const {
   return GHEX120;
}

const std::set<el_processor> ghex120::processors(procs, procs+procs_len);

ghex120::ghex120(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex120::ghex120(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex120::ghex120(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

const long ghex121::nnodes = 24;

el_types ghex121::get_type() const {
   return GHEX121;
}

const std::set<el_processor> ghex121::processors(procs, procs+procs_len);

ghex121::ghex121(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex121::ghex121(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex121::ghex121(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

const long ghex122::nnodes = 24;

el_types ghex122::get_type() const {
   return GHEX122;
}

const std::set<el_processor> ghex122::processors(procs, procs+procs_len);

ghex122::ghex122(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex122::ghex122(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex122::ghex122(
   const __base *data) :
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

const long ghex123::nnodes = 25;

el_types ghex123::get_type() const {
   return GHEX123;
}

const std::set<el_processor> ghex123::processors(procs, procs+procs_len);

ghex123::ghex123(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex123::ghex123(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex123::ghex123(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 27 at pos 23
*/

const long ghex124::nnodes = 23;

el_types ghex124::get_type() const {
   return GHEX124;
}

const std::set<el_processor> ghex124::processors(procs, procs+procs_len);

ghex124::ghex124(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex124::ghex124(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex124::ghex124(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

const long ghex125::nnodes = 24;

el_types ghex125::get_type() const {
   return GHEX125;
}

const std::set<el_processor> ghex125::processors(procs, procs+procs_len);

ghex125::ghex125(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex125::ghex125(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex125::ghex125(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

const long ghex126::nnodes = 24;

el_types ghex126::get_type() const {
   return GHEX126;
}

const std::set<el_processor> ghex126::processors(procs, procs+procs_len);

ghex126::ghex126(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex126::ghex126(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex126::ghex126(
   const __base *data) :
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

const long ghex127::nnodes = 25;

el_types ghex127::get_type() const {
   return GHEX127;
}

const std::set<el_processor> ghex127::processors(procs, procs+procs_len);

ghex127::ghex127(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex127::ghex127(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex127::ghex127(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 25 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 25 at pos 23
                    - node 27 at pos 24
*/

const long ghex128::nnodes = 24;

el_types ghex128::get_type() const {
   return GHEX128;
}

const std::set<el_processor> ghex128::processors(procs, procs+procs_len);

ghex128::ghex128(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex128::ghex128(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex128::ghex128(
   const __base *data) :
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

const long ghex129::nnodes = 25;

el_types ghex129::get_type() const {
   return GHEX129;
}

const std::set<el_processor> ghex129::processors(procs, procs+procs_len);

ghex129::ghex129(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex129::ghex129(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex129::ghex129(
   const __base *data) :
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

const long ghex130::nnodes = 25;

el_types ghex130::get_type() const {
   return GHEX130;
}

const std::set<el_processor> ghex130::processors(procs, procs+procs_len);

ghex130::ghex130(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex130::ghex130(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex130::ghex130(
   const __base *data) :
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

const long ghex131::nnodes = 26;

el_types ghex131::get_type() const {
   return GHEX131;
}

const std::set<el_processor> ghex131::processors(procs, procs+procs_len);

ghex131::ghex131(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex131::ghex131(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex131::ghex131(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 26 at pos 21
                    - node 27 at pos 22
*/

const long ghex132::nnodes = 22;

el_types ghex132::get_type() const {
   return GHEX132;
}

const std::set<el_processor> ghex132::processors(procs, procs+procs_len);

ghex132::ghex132(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex132::ghex132(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex132::ghex132(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

const long ghex133::nnodes = 23;

el_types ghex133::get_type() const {
   return GHEX133;
}

const std::set<el_processor> ghex133::processors(procs, procs+procs_len);

ghex133::ghex133(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex133::ghex133(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex133::ghex133(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

const long ghex134::nnodes = 23;

el_types ghex134::get_type() const {
   return GHEX134;
}

const std::set<el_processor> ghex134::processors(procs, procs+procs_len);

ghex134::ghex134(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex134::ghex134(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex134::ghex134(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 22, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 22 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex135::nnodes = 24;

el_types ghex135::get_type() const {
   return GHEX135;
}

const std::set<el_processor> ghex135::processors(procs, procs+procs_len);

ghex135::ghex135(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex135::ghex135(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex135::ghex135(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

const long ghex136::nnodes = 23;

el_types ghex136::get_type() const {
   return GHEX136;
}

const std::set<el_processor> ghex136::processors(procs, procs+procs_len);

ghex136::ghex136(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex136::ghex136(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex136::ghex136(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex137::nnodes = 24;

el_types ghex137::get_type() const {
   return GHEX137;
}

const std::set<el_processor> ghex137::processors(procs, procs+procs_len);

ghex137::ghex137(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex137::ghex137(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex137::ghex137(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 23 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex138::nnodes = 24;

el_types ghex138::get_type() const {
   return GHEX138;
}

const std::set<el_processor> ghex138::processors(procs, procs+procs_len);

ghex138::ghex138(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex138::ghex138(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex138::ghex138(
   const __base *data) :
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

const long ghex139::nnodes = 25;

el_types ghex139::get_type() const {
   return GHEX139;
}

const std::set<el_processor> ghex139::processors(procs, procs+procs_len);

ghex139::ghex139(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex139::ghex139(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex139::ghex139(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

const long ghex140::nnodes = 23;

el_types ghex140::get_type() const {
   return GHEX140;
}

const std::set<el_processor> ghex140::processors(procs, procs+procs_len);

ghex140::ghex140(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex140::ghex140(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex140::ghex140(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex141::nnodes = 24;

el_types ghex141::get_type() const {
   return GHEX141;
}

const std::set<el_processor> ghex141::processors(procs, procs+procs_len);

ghex141::ghex141(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex141::ghex141(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex141::ghex141(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex142::nnodes = 24;

el_types ghex142::get_type() const {
   return GHEX142;
}

const std::set<el_processor> ghex142::processors(procs, procs+procs_len);

ghex142::ghex142(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex142::ghex142(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex142::ghex142(
   const __base *data) :
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

const long ghex143::nnodes = 25;

el_types ghex143::get_type() const {
   return GHEX143;
}

const std::set<el_processor> ghex143::processors(procs, procs+procs_len);

ghex143::ghex143(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex143::ghex143(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex143::ghex143(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 24, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 24 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex144::nnodes = 24;

el_types ghex144::get_type() const {
   return GHEX144;
}

const std::set<el_processor> ghex144::processors(procs, procs+procs_len);

ghex144::ghex144(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex144::ghex144(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex144::ghex144(
   const __base *data) :
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

const long ghex145::nnodes = 25;

el_types ghex145::get_type() const {
   return GHEX145;
}

const std::set<el_processor> ghex145::processors(procs, procs+procs_len);

ghex145::ghex145(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex145::ghex145(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex145::ghex145(
   const __base *data) :
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

const long ghex146::nnodes = 25;

el_types ghex146::get_type() const {
   return GHEX146;
}

const std::set<el_processor> ghex146::processors(procs, procs+procs_len);

ghex146::ghex146(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex146::ghex146(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex146::ghex146(
   const __base *data) :
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

const long ghex147::nnodes = 26;

el_types ghex147::get_type() const {
   return GHEX147;
}

const std::set<el_processor> ghex147::processors(procs, procs+procs_len);

ghex147::ghex147(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex147::ghex147(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex147::ghex147(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 25 at pos 21
                    - node 26 at pos 22
                    - node 27 at pos 23
*/

const long ghex148::nnodes = 23;

el_types ghex148::get_type() const {
   return GHEX148;
}

const std::set<el_processor> ghex148::processors(procs, procs+procs_len);

ghex148::ghex148(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex148::ghex148(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex148::ghex148(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 21, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 21 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex149::nnodes = 24;

el_types ghex149::get_type() const {
   return GHEX149;
}

const std::set<el_processor> ghex149::processors(procs, procs+procs_len);

ghex149::ghex149(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex149::ghex149(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex149::ghex149(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 22, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 22 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex150::nnodes = 24;

el_types ghex150::get_type() const {
   return GHEX150;
}

const std::set<el_processor> ghex150::processors(procs, procs+procs_len);

ghex150::ghex150(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex150::ghex150(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex150::ghex150(
   const __base *data) :
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

const long ghex151::nnodes = 25;

el_types ghex151::get_type() const {
   return GHEX151;
}

const std::set<el_processor> ghex151::processors(procs, procs+procs_len);

ghex151::ghex151(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex151::ghex151(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex151::ghex151(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 23, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 23 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex152::nnodes = 24;

el_types ghex152::get_type() const {
   return GHEX152;
}

const std::set<el_processor> ghex152::processors(procs, procs+procs_len);

ghex152::ghex152(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex152::ghex152(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex152::ghex152(
   const __base *data) :
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

const long ghex153::nnodes = 25;

el_types ghex153::get_type() const {
   return GHEX153;
}

const std::set<el_processor> ghex153::processors(procs, procs+procs_len);

ghex153::ghex153(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex153::ghex153(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex153::ghex153(
   const __base *data) :
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

const long ghex154::nnodes = 25;

el_types ghex154::get_type() const {
   return GHEX154;
}

const std::set<el_processor> ghex154::processors(procs, procs+procs_len);

ghex154::ghex154(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex154::ghex154(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex154::ghex154(
   const __base *data) :
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

const long ghex155::nnodes = 26;

el_types ghex155::get_type() const {
   return GHEX155;
}

const std::set<el_processor> ghex155::processors(procs, procs+procs_len);

ghex155::ghex155(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex155::ghex155(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex155::ghex155(
   const __base *data) :
   ghex(data) {}

/**
   General Hexahedron, define with nodes 1 to 20, node 24, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

                    - node 24 at pos 21
                    - node 25 at pos 22
                    - node 26 at pos 23
                    - node 27 at pos 24
*/

const long ghex156::nnodes = 24;

el_types ghex156::get_type() const {
   return GHEX156;
}

const std::set<el_processor> ghex156::processors(procs, procs+procs_len);

ghex156::ghex156(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex156::ghex156(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex156::ghex156(
   const __base *data) :
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

const long ghex157::nnodes = 25;

el_types ghex157::get_type() const {
   return GHEX157;
}

const std::set<el_processor> ghex157::processors(procs, procs+procs_len);

ghex157::ghex157(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex157::ghex157(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex157::ghex157(
   const __base *data) :
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

const long ghex158::nnodes = 25;

el_types ghex158::get_type() const {
   return GHEX158;
}

const std::set<el_processor> ghex158::processors(procs, procs+procs_len);

ghex158::ghex158(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex158::ghex158(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex158::ghex158(
   const __base *data) :
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

const long ghex159::nnodes = 26;

el_types ghex159::get_type() const {
   return GHEX159;
}

const std::set<el_processor> ghex159::processors(procs, procs+procs_len);

ghex159::ghex159(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex159::ghex159(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex159::ghex159(
   const __base *data) :
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

const long ghex160::nnodes = 25;

el_types ghex160::get_type() const {
   return GHEX160;
}

const std::set<el_processor> ghex160::processors(procs, procs+procs_len);

ghex160::ghex160(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex160::ghex160(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex160::ghex160(
   const __base *data) :
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

const long ghex161::nnodes = 26;

el_types ghex161::get_type() const {
   return GHEX161;
}

const std::set<el_processor> ghex161::processors(procs, procs+procs_len);

ghex161::ghex161(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex161::ghex161(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex161::ghex161(
   const __base *data) :
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

const long ghex162::nnodes = 26;

el_types ghex162::get_type() const {
   return GHEX162;
}

const std::set<el_processor> ghex162::processors(procs, procs+procs_len);

ghex162::ghex162(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex162::ghex162(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex162::ghex162(
   const __base *data) :
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

const long ghex163::nnodes = 27;

el_types ghex163::get_type() const {
   return GHEX163;
}

const std::set<el_processor> ghex163::processors(procs, procs+procs_len);

ghex163::ghex163(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex163::ghex163(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex163::ghex163(
   const __base *data) :
   ghex(data) {}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End: