/**
   \file fem/fem_element_ftrs_fftr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ftrs_fftr.

   Detailed description
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

const long ftrs_fftr::nnodes = 3;

namespace {
   const size_t procs_len = 5;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra, ADVANCE, Platework};
}
const ::std::set<el_processor> ftrs_fftr::processors(procs, procs+procs_len);

ftrs_fftr::ftrs_fftr(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
