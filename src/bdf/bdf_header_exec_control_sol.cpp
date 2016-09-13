/**
   \file bdf/bdf_header_exec_control_sol.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for EXEC SOL

   Detailed description
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

#include <sstream>

#include "bdf/header.h"
#include "bdf/errors.h"

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace header {
            namespace executive_control {
               sol::sol(long const &sol_no) :
                  sol_no(sol::sol_no_type_conv::from_long(sol_no)) {}

               sol::sol(
                  sol::sol_no_type const &sol_no) :
                  sol_no(sol_no) {}

               std::ostream &sol::put(std::ostream &os) const {
                  return os << "SOL "
                            << sol::sol_no_type_conv::to_long(this->sol_no)
                            << std::endl;
               }

               sol::sol_no_type
               sol::sol_no_type_conv::from_long(long const &inp) {
                  switch (inp) {
                     /** Statics with Options:
                           Linear Steady State Heat Transfer
                           Alternate Reduction
                           Inertia Relief */
                  case 101: return SESTATIC;
                     /// Normal Modes
                  case 103: return SEMODES;
                     /** Buckling with options:
                           Static Analysis
                           Alternate Reduction
                           Inertia Relief */
                  case 105: return SEBUCKL;
                     /// Nonlinear or Linear Statics
                  case 106: return NLSTATIC;
                     /// Direct Complex Eigenvalues
                  case 107: return SEDCEIG;
                     /// Direct Frequency Response
                  case 108: return SEDFREQ;
                     /// Direct Transient Response
                  case 109: return SEDTRAN;
                     /// Modal Complex Eigenvalues
                  case 110: return SEMCEIG;
                     /// Modal Frequency Response
                  case 111: return SEMFREQ;
                     /// Modal Transient Response
                  case 112: return SEMTRAN;
                     /** Cyclic Statics with Option:
                           Alternate Reduction */
                  case 114: return CYCSTATX;
                     /// Cyclic Normal Modes
                  case 115: return CYCMODE;
                     /// Cyclic Buckling
                  case 116: return CYCBUCKL;
                     /// Cyclic Direct Frequency Response
                  case 118: return CYCFREQ;
                     /// Nonlinear or Linear Transient Response
                  case 129: return NLTRAN;
                     /// Static Aeroelastic Response
                  case 144: return AESTAT;
                     /// Aerodynamic Flutter
                  case 145: return SEFLUTTR;
                     /// Aeroelastic Response
                  case 146: return SEAERO;
                     /** Static Structural and/or Steady State Heat Transfer Analysis
                         with Options:
                           Linear or Nonlinear Analysis */
                  case 153: return NLSCSH;
                     /** Transient Structural and/or Transient Heat Transfer Analysis
                         with Options:
                           Linear or Nonlinear Analysis */
                  case 159: return NLTCSH;
                     /** Database Transfer, “Output Description” on page 373 of the
                         MSC.Nastran Reference Guide. */
                  case 190: return DBTRANS;
                     /// Design Optimization
                  case 200: return DESOPT;
                     /// Nonlinear static and transient analysis
                  case 400: return NONLIN;
                  default:
                     {
                        std::ostringstream msg("invalid solution value ",
                                               std::ostringstream::ate);
                        msg << inp;
                        throw errors::error("HEAD", msg.str());
                        break;
                     }
                  }
               }

               long sol::sol_no_type_conv::to_long(sol::sol_no_type const &inp) {
                  return +inp;
               }
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
