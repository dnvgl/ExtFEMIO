/**
   \file fem/fem_element_ipri.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ipri.

   Isoparametric Triangular Prism
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

const long ipri::nnodes = 15;

el_types ipri::get_type() const {return IPRI;}

namespace {
   const size_t procs_len = 4;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra, ADVANCE};
}
const ::std::set<el_processor> ipri::processors(procs, procs+procs_len);

ipri::ipri(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
