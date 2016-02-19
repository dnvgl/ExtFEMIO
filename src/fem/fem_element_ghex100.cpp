/**
   \file fem/fem_element_ghex100.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ghex100.

   General Hexahedron, define with nodes 1 to 20 and node 27 present.

   Position of node in node array for element node numbers > 20:

        - node 27 at pos 21
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

const long ghex100::nnodes = 21;

el_types ghex100::get_type() const {return GHEX100;}

namespace {
   const size_t procs_len = 2;
   el_processor procs[
      procs_len] = {general, Sestra};
}
const ::std::set<el_processor> ghex100::processors(procs, procs+procs_len);

ghex100::ghex100(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {}

ghex100::ghex100(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::ghex(data) {}

ghex100::ghex100(const __base *data) :
   ghex(data) {}

el_types ghex100::get_type(void) const {
   return GHEX100;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
