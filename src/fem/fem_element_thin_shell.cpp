/**
   \file fem/fem_element_thin_shell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for fem_thin_shell.

   Flat Quadrilateral/Triangular Thin Shell / Free Formulation
   Quadrilateral/Triangular Shell
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

namespace dnvgl {
   namespace extfem {
      namespace fem {

         using namespace cards;

         namespace elements {
            namespace __base {

               fem_thin_shell::fem_thin_shell(void) : elem() {}

               fem_thin_shell::fem_thin_shell(
                  long const elno,
                  long const elident,
                  long const el_add,
                  std::vector<long> const nodes,
                  long const matref,
                  long const add_no,
                  long const intno,
                  long const mass_intno,
                  long const i_strain_ref,
                  long const i_stressef,
                  long const strpoint_ref,
                  std::vector<long> const sections,
                  std::vector<long> const fixations,
                  std::vector<long> const eccentrities,
                  std::vector<long> const csys) :
                  elem (elno, elident, el_add, nodes, matref, add_no,
                        intno, mass_intno, i_strain_ref, i_stressef,
                        strpoint_ref, sections, fixations,
                        eccentrities, csys) {}

               fem_thin_shell::fem_thin_shell(cards::gelmnt1 const *data) :
                  elem(data) {}

               fem_thin_shell::fem_thin_shell(cards::gelref1 const *data) :
                  elem(data) {}

               fem_thin_shell::fem_thin_shell(__base::elem const *data) :
                  elem(data) {}
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
