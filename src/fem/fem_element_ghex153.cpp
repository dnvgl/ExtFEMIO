/**
   \file fem/fem_element_ghex153.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ghex153.

   General Hexahedron, define with nodes 1 to 20, node 21, node 23, node 25, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

        - node 21 at pos 21
        - node 23 at pos 22
        - node 25 at pos 23
        - node 26 at pos 24
        - node 27 at pos 25
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

using namespace ::dnvgl::extfem::fem::elements;

const long ghex153::nnodes = 25;

el_types ghex153::get_type() const {return GHEX153;}

namespace {
   const size_t procs_len = 2;
   el_processor procs[
      procs_len] = {general, Sestra};
}
const ::std::set<el_processor> ghex153::processors(procs, procs+procs_len);

ghex153::ghex153(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {}

ghex153::ghex153(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
