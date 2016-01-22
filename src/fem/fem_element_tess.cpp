/**
   \file fem/fem_element_tess.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for tess.

   Truss Element
*/

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

const long tess::nnodes = 2;
el_types tess::get_type() const {return TESS;}

namespace {
   const size_t procs_len = 6;
   el_processor procs[procs_len] = {general, Preframe, Prefem, Sestra, ADVANCE, Poseidon};
}
const ::std::set<el_processor> tess::processors(procs, procs+procs_len);

tess::tess(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

tess::tess(const ::dnvgl::extfem::fem::cards::gelref1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
