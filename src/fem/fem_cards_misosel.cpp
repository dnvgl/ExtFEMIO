/**
   \file fem/fem_cards_misosel.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `MISOSEL` cards.

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

#include <memory>
#include <algorithm>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card misosel::head("MISOSEL");

            const entry_type<long> misosel::_form_MATNO("MATNO");
            const entry_type<double> misosel::_form_YOUNG("YOUNG");
            const entry_type<double> misosel::_form_POISS("POISS");
            const entry_type<double> misosel::_form_RHO("RHO");
            const entry_type<double> misosel::_form_DAMP("DAMP");
            const entry_type<double> misosel::_form_ALPHA("ALPHA");
            const entry_type<double> misosel::_form_DUMMY("DUMMY");
            const entry_type<double> misosel::_form_YIELD("YIELD");

            misosel::misosel(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 7)
                  throw errors::parse_error(
                     "MISOSEL", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               MATNO = _form_MATNO(*(pos++));
               YOUNG = _form_YOUNG(*(pos++));
               POISS = _form_POISS(*(pos++));
               RHO = _form_RHO(*(pos++));
               DAMP = _form_DAMP(*(pos++));
               ALPHA = _form_ALPHA(*(pos++));
               DUMMY = _form_DUMMY(*(pos++));
               YIELD = _form_YIELD(*(pos++));
            }

            misosel::misosel(void) :
               misosel(-1, 0., 0., 0., 0., 0., 0., 0.) {}

            misosel::misosel(const long &MATNO,
                             const double &YOUNG,
                             const double &POISS,
                             const double &RHO,
                             const double &DAMP,
                             const double &ALPHA,
                             const double &DUMMY,
                             const double &YIELD) :
               card(), MATNO(MATNO), YOUNG(YOUNG), POISS(POISS),
               RHO(RHO), DAMP(DAMP), ALPHA(ALPHA), DUMMY(DUMMY),
               YIELD(YIELD) {}

            const dnvgl::extfem::fem::cards::types
            misosel::card_type(void) const {return MISOSEL;}

            const std::ostream&
            misosel::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const misosel &card) {
               if (card.MATNO == -1) return os;
               os << misosel::head.format()
                  << card._form_MATNO.format(card.MATNO)
                  << card._form_YOUNG.format(card.YOUNG)
                  << card._form_POISS.format(card.POISS)
                  << card._form_RHO.format(card.RHO)
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_DAMP.format(card.DAMP)
                  << card._form_ALPHA.format(card.ALPHA)
                  << card._form_DUMMY.format(card.DUMMY)
                  << card._form_YIELD.format(card.YIELD)
                  << std::endl;
               return os;
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
