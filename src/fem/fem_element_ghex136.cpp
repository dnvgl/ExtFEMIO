/**
   \file fem/fem_element_ghex136.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ghex136.

   General Hexahedron, define with nodes 1 to 20, node 23, node 26 and node 27 present.

   Position of node in node array for element node numbers > 20:

        - node 23 at pos 21
        - node 26 at pos 22
        - node 27 at pos 23
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

const long ghex136::nnodes = 23;

el_types ghex136::get_type() const {return GHEX136;}

namespace {
   const size_t procs_len = 2;
   el_processor procs[
      procs_len] = {general, Sestra};
}
const ::std::set<el_processor> ghex136::processors(procs, procs+procs_len);

ghex136::ghex136(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {}

ghex136::ghex136(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {}

ghex136::ghex136(const __base *data) :
   ghex(data) {}

el_types ghex136::get_type(void) {
   return GHEX136;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
