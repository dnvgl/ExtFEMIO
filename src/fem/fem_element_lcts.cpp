/**
   \file fem/fem_element_lcts.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for lcts.

   Subparam. Layered Curved Triangular Thick Shell
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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "fem/elements.h"

using namespace dnvgl::extfem::fem::elements;

const long lcts::nnodes = 6;

el_types lcts::get_type() const {return LCTS;}

namespace {
   const size_t procs_len = 3;
   el_processor procs[
      procs_len] = {general, Prefem, Sestra};
}
const std::set<el_processor> lcts::processors(procs, procs+procs_len);

lcts::lcts(const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

lcts::lcts(const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
