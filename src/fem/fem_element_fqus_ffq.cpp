/**
   \file fem/fem_element_fqus_ffq.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for fqus_ffq.

   Flat Quadrilateral Thin Shell / Free Formulation Quadrilateral Shell
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

const long fqus_ffq::nnodes = 4;

el_types fqus_ffq::get_type() const {return FQUS_FFQ;}

namespace {
   const size_t procs_len = 7;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra, ADVANCE, Platework,
                    Pretube, Poseidon};
}
const ::std::set<el_processor> fqus_ffq::processors(
   procs, procs+procs_len);

fqus_ffq::fqus_ffq(const ::dnvgl::extfem::fem::cards::gelmnt1 &data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
