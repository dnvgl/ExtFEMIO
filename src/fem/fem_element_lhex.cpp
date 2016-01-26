/**
   \file fem/fem_element_lhex.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for lhex.

   Linear Hexahedron
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

const long lhex::nnodes = 8;

el_types lhex::get_type() const {return LHEX;}

namespace {
   const size_t procs_len = 5;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra, ADVANCE, Framework};
}
const ::std::set<el_processor> lhex::processors(procs, procs+procs_len);

lhex::lhex(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

lhex::lhex(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
