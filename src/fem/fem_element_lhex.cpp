/**
   \file fem/fem_element_lhex.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for lhex.

   Linear Hexahedron
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

long lhex::nnodes(void) const {return 8;}

el_types lhex::get_type(void) const {return LHEX;}

namespace {
   const size_t procs_len = 5;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra, ADVANCE, Framework};
}
const std::set<el_processor> lhex::processors(procs, procs+procs_len);

lhex::lhex(const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::__base::elem(data) {}

lhex::lhex(const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::__base::elem(data) {}

lhex::lhex(const dnvgl::extfem::fem::elements::__base::elem *data) :
   dnvgl::extfem::fem::elements::__base::elem(data) {}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
