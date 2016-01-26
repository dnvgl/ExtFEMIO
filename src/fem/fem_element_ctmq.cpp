/**
   \file fem/fem_element_ctmq.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ctmq.

   18-Noded (9+9) Contact Element
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

const long ctmq::nnodes = 18;

el_types ctmq::get_type() const {return CTMQ;}

namespace {
   const size_t procs_len = 2;
   el_processor procs[
      procs_len] = {general, Pretube};
}
const ::std::set<el_processor> ctmq::processors(procs, procs+procs_len);

ctmq::ctmq(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

ctmq::ctmq(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
