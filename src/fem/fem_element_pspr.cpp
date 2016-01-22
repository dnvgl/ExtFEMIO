/**
   \file fem/fem_element_pspr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for pspr.

   Plane Spring Element
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

const long pspr::nnodes = 1;

el_types pspr::get_type() const {return PSPR;}

namespace {
   const size_t procs_len = 3;
   el_processor procs[
      procs_len] = {general, Preframe, ADVANCE};
}
const ::std::set<el_processor> pspr::processors(procs, procs+procs_len);

pspr::pspr(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
