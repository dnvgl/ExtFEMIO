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

namespace dnvgl {
   namespace extfem {
      namespace fem {

         using namespace cards;

         namespace elements {
            namespace {
               const size_t procs_len = 7;
               el_processor procs[procs_len] = { Poseidon, ADVANCE, Pretube, Prefem, Platework, Sestra, general };
            }

            long fqus_ffq::nnodes(void) const {return 4;}

            el_types fqus_ffq::get_type(void) const {return FQUS_FFQ;}

            const std::set<el_processor> fqus_ffq::processors(
               procs, procs+procs_len);

            fqus_ffq::fqus_ffq(void) : fem_thin_shell() {}

            fqus_ffq::fqus_ffq(long const eleno,
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

            fqus_ffq::fqus_ffq(const cards::gelmnt1 *data) : fem_thin_shell(data) {}

            fqus_ffq::fqus_ffq(const cards::gelref1 *data) : fem_thin_shell(data) {}

            fqus_ffq::fqus_ffq(const __base::elem *data) : __base::fem_thin_shell(data) {}
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