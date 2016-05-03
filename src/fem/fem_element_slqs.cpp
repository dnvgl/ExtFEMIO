/**
   \file fem/fem_element_slqs.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for slqs.

   Semiloof Quadrilateral Curved Thin Shell (32 d.o.fs)
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

long slqs::nnodes(void) const {return 8;}

el_types slqs::get_type(void) const {return SLQS;}

namespace {
   const size_t procs_len = 1;
   el_processor procs[
      procs_len] = {general};
}
const std::set<el_processor> slqs::processors(procs, procs+procs_len);

slqs::slqs(const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

slqs::slqs(const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

slqs::slqs(const dnvgl::extfem::fem::elements::__base *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
