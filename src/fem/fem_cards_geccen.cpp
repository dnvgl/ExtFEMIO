/**
   \file fem_cards_geccen.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GECCEN` cards.

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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card geccen::head("GECCEN");


            const entry_type<long> geccen::_form_ECCNO("ECCNO");
            const entry_type<double> geccen::_form_EX("EX");
            const entry_type<double> geccen::_form_EY("EY");
            const entry_type<double> geccen::_form_EZ("EZ");

            geccen::geccen(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               ECCNO = _form_ECCNO(*(pos++));
               EX = _form_EX(*(pos++));
               EY = _form_EY(*(pos++));
               EZ = _form_EZ(*(pos++));
            }

            geccen::geccen(
               const long &ECCNO,
               const double &EX, const double &EY, const double &EZ) :
               card(), ECCNO(ECCNO), EX(EX), EY(EY), EZ(EZ) {}

            const ::dnvgl::extfem::fem::cards::types
            geccen::card_type(void) const {return GECCEN;}

            const ::std::ostream&
            geccen::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const geccen &card) {
               os << geccen::head.format()
                  << card._form_ECCNO.format(card.ECCNO)
                  << card._form_EX.format(card.EX)
                  << card._form_EY.format(card.EY)
                  << card._form_EZ.format(card.EZ) << ::std::endl;
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
