/**
   \file fem/fem_element_rpbq.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for rpbq.

   Rect. Plate. Bending Modes
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

const long rpbq::nnodes = 4;

el_types rpbq::get_type() const {return RPBQ;}

namespace {
   const size_t procs_len = 1;
   el_processor procs[procs_len] = {general};
}
const ::std::set<el_processor> rpbq::processors(procs, procs+procs_len);

rpbq::rpbq(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
