/**
   \file fem/fem_element_scqs.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for scqs.

   Subparametric Curved Quadrilateral Thick Shell
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

const long scqs::nnodes = 8;

el_types scqs::get_type() const {return SCQS;}

namespace {
   const size_t procs_len = 5;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra, Platework, Pretube};
}
const ::std::set<el_processor> scqs::processors(procs, procs+procs_len);

scqs::scqs(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

scqs::scqs(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
