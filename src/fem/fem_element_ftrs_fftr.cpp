   /**
   \file fem/fem_element_ftrs_fftr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief FEM element definition for ftrs_fftr.

    Flat Triangular Thin Shell / Free Formulation Triangular Shell
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
            namespace {
               const size_t procs_len = 6;
               el_processor procs[procs_len] = { Poseidon, ADVANCE, Prefem, Platework, Sestra, general };
            }

            long ftrs_fftr::nnodes(void) const {return 3;}

            el_types ftrs_fftr::get_type(void) const {return FTRS_FFTR;}

            const std::set<el_processor> ftrs_fftr::processors(
               procs, procs+procs_len);

            ftrs_fftr::ftrs_fftr(void) : fem_thin_shell() {}

            ftrs_fftr::ftrs_fftr(long const eleno,
                          long const elident,
                          long const el_add,
                          std::vector<long> const nodes,
                          long const matref,
                          long const add_no,
                          long const intno,
                          long const mass_intno,
                          long const i_strain_ref,
                          long const i_stress_ref,
                          long const strpoint_ref,
                          std::vector<long> const section,
                          std::vector<long> const fixations,
                          std::vector<long> const eccentrities,
                          std::vector<long> const csys) :
                  fem_thin_shell(
                     eleno, elident, el_add, nodes, matref, add_no,
                     intno, mass_intno, i_strain_ref, i_stress_ref,
                     strpoint_ref, section, fixations, eccentrities,
                     csys) {}

            ftrs_fftr::ftrs_fftr(const cards::gelmnt1 *data) : fem_thin_shell(data) {}

            ftrs_fftr::ftrs_fftr(const cards::gelref1 *data) : fem_thin_shell(data) {}

            ftrs_fftr::ftrs_fftr(const __base::elem *data) : __base::fem_thin_shell(data) {}
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