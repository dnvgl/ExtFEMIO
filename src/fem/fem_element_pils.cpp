/**
   \file fem/fem_element_pils.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for pils.

   Pile / Soil
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

long pils::nnodes(void) const {return 1;}

el_types pils::get_type(void) const {return PILS;}

namespace {
   const size_t procs_len = 3;
   el_processor procs[
      procs_len] = {general, Preframe, ADVANCE};
}
const std::set<el_processor> pils::processors(procs, procs+procs_len);

pils::pils(const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

pils::pils(const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

pils::pils(const dnvgl::extfem::fem::elements::__base *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
