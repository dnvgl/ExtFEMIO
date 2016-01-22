/**
   \file fem/fem_element_secb.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for secb.

   Subparametric Curved Beam
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

const long secb::nnodes = 3;

el_types secb::get_type() const {return SECB;}

namespace {
   const size_t procs_len = 1;
   el_processor procs[
      procs_len] = {general};
}
const ::std::set<el_processor> secb::processors(procs, procs+procs_len);

secb::secb
(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
