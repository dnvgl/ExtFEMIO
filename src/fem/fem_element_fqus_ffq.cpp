/**
   \file fem/fem_element_fqus_ffq.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for fqus_ffq.

   Flat Quadrilateral Thin Shell / Free Formulation Quadrilateral Shell
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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem::elements;

const long fqus_ffq::nnodes = 4;

el_types fqus_ffq::get_type(void) {return FQUS_FFQ;}

namespace {
   const size_t procs_len = 7;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra, ADVANCE, Platework,
                    Pretube, Poseidon};
}
const std::set<el_processor> fqus_ffq::processors(
   procs, procs+procs_len);

fqus_ffq::fqus_ffq(dnvgl::extfem::fem::cards::gelmnt1 const *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

fqus_ffq::fqus_ffq(dnvgl::extfem::fem::cards::gelref1 const *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

fqus_ffq::fqus_ffq(dnvgl::extfem::fem::elements::__base const *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
