/**
   \file fem/fem_element_adva_2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for adva_2.

   2-Noded Link Element
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

const long adva_2::nnodes = 2;

el_types adva_2::get_type() const {return ADVA_2;}

namespace {
   const size_t procs_len = 2;
   el_processor procs[
      procs_len] = {general, ADVANCE};
}
const ::std::set<el_processor> adva_2::processors(procs, procs+procs_len);

adva_2::adva_2(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
