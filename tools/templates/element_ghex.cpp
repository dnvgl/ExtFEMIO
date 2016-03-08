/**
   \file fem/fem_element_ghex.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ghex1*.

   General Hexahedon elements defined with 21 to 27 nodes.
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

ghex::ghex(const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   __base(data) {}

ghex::ghex(const dnvgl::extfem::fem::cards::gelref1 *data) :
   __base(data) {}

ghex::ghex(const __base *p) :
   __base(p) {}

namespace {
   const size_t procs_len = 2;
   el_processor procs[procs_len] = {general, Sestra};
}

{% for num, pos in res %}
/**
   General Hexahedron, define with nodes 1 to 20{{ gen_extnodes(pos[:-1]) }} and node 27 present.

   Position of node in node array for element node numbers > 20:

{{ gen_nodepos(pos, 20 * " ") }}
*/

const long ghex1{{ "%02d"|format(num) }}::nnodes = {{ pos|length + 20 }};

el_types ghex1{{ "%02d"|format(num) }}::get_type() const {
   return GHEX1{{ "%02d"|format(num) }};
}

const std::set<el_processor> ghex1{{ "%02d"|format(num) }}::processors(procs, procs+procs_len);

ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(
   const dnvgl::extfem::fem::cards::gelmnt1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(
   const dnvgl::extfem::fem::cards::gelref1 *data) :
   dnvgl::extfem::fem::elements::ghex(data) {}

ghex1{{ "%02d"|format(num) }}::ghex1{{ "%02d"|format(num) }}(
   const __base *data) :
   ghex(data) {}
{% endfor %}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
