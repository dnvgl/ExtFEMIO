/**
   \file fem/fem_cards_gbarm.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GBARM` cards.

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

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card gbarm::head("GBARM");

            const entry_type<long> gbarm::_form_GEONO("GEONO");
            const entry_type<double> gbarm::_form_HZ("HZ");
            const entry_type<double> gbarm::_form_BT("BT");
            const entry_type<double> gbarm::_form_BB("BB");
            const entry_type<double> gbarm::_form_SFY("SFY");
            const entry_type<double> gbarm::_form_SFZ("SFZ");
            const entry_type<long> gbarm::_form_NLOBY("NLOBY");
            const entry_type<long> gbarm::_form_NLOBZ("NLOBZ");

            gbarm::gbarm(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               HZ = _form_HZ(*(pos++));
               BT = _form_BT(*(pos++));
               BB = _form_BB(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               NLOBY = _form_NLOBY(*(pos++));
               NLOBZ = _form_NLOBZ(*(pos++));
            }

            gbarm::gbarm(
                  const long &GEONO,
                  const double &HZ, const double &BT, const double &BB,
                  const double &SFY, const double &SFZ,
                  const long &NLOBY, const long &NLOBZ) :
               GEONO(GEONO), HZ(HZ), BT(BT), BB(BB),
               SFY(SFY), SFZ(SFZ), NLOBY(NLOBY), NLOBZ(NLOBZ) {}

            const ::std::ostream&
            gbarm::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            const ::dnvgl::extfem::fem::cards::types
            gbarm::card_type(void) const {return GBARM;}

            ::std::ostream&
            operator<< (::std::ostream &os, const gbarm &card) {
               os << gbarm::head.format()
                  << card._form_GEONO.format(card.GEONO)
                  << card._form_HZ.format(card.HZ)
                  << card._form_BT.format(card.BT)
                  << card._form_BB.format(card.BB)
                  << ::std::endl << fem::types::card("").format()
                  << card._form_SFY.format(card.SFY)
                  << card._form_SFZ.format(card.SFZ)
                  << card._form_NLOBY.format(card.NLOBY)
                  << card._form_NLOBZ.format(card.NLOBZ) << ::std::endl;
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
