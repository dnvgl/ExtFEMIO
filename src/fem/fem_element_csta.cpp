/**
   \file fem/fem_element_csta.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for csta.

   Plane Constant Strain Triangle
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

const long csta::nnodes = 3;

el_types csta::get_type() const {return CSTA;}

namespace {
   const size_t procs_len = 4;
   el_processor procs[procs_len] = {general, Prefem, Sestra, ADVANCE};
}
const ::std::set<el_processor> csta::processors(procs, procs+procs_len);

csta::csta(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

csta::csta(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End: