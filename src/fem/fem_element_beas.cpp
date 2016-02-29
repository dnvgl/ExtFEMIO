/**
   \file fem/fem_element_beas.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for beas.

   3-D, 2 Node Beam
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

using namespace ::dnvgl::extfem::fem::elements;

const long beas::nnodes = 2;

el_types beas::get_type() const {return BEAS;}

namespace {
   const size_t procs_len = 11;
   el_processor procs[
      procs_len] = {general, Preframe, Prefem, Sestra, ADVANCE,
                    Framework, Launch, Platework, Pretube, Wadam,
                    Poseidon};
}
const ::std::set<el_processor> beas::processors(procs, procs+procs_len);

beas::beas(const ::dnvgl::extfem::fem::cards::gelmnt1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

beas::beas(const ::dnvgl::extfem::fem::cards::gelref1 *data) :
   ::dnvgl::extfem::fem::elements::__base(data) {}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
