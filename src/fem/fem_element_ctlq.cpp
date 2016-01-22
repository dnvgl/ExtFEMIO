/**
   \file fem/fem_element_ctlq.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ctlq.

   8-Noded (4+4) Contact Element
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

const long ctlq::nnodes = 8;

el_types ctlq::get_type() const {return CTLQ;}

namespace {
   const size_t procs_len = 2;
   el_processor procs[
      procs_len] = {general, Pretube};
}
const ::std::set<el_processor> ctlq::processors(procs, procs+procs_len);

ctlq::ctlq(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
