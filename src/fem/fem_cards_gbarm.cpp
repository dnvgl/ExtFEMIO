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

            const entry_type<long> gbarm::_GEONO("GEONO");
            const entry_type<double> gbarm::_HZ("HZ");
            const entry_type<double> gbarm::_BT("BT");
            const entry_type<double> gbarm::_BB("BB");
            const entry_type<double> gbarm::_SFY("SFY");
            const entry_type<double> gbarm::_SFZ("SFZ");
            const entry_type<long> gbarm::_NLOBY("NLOBY");
            const entry_type<long> gbarm::_NLOBZ("NLOBZ");

            gbarm::gbarm(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               GEONO = _GEONO(*(pos++));
               HZ = _HZ(*(pos++));
               BT = _BT(*(pos++));
               BB = _BB(*(pos++));
               SFY = _SFY(*(pos++));
               SFZ = _SFZ(*(pos++));
               NLOBY = _NLOBY(*(pos++));
               NLOBZ = _NLOBZ(*(pos++));
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
                  << card._GEONO.format(card.GEONO)
                  << card._HZ.format(card.HZ)
                  << card._BT.format(card.BT)
                  << card._BB.format(card.BB)
                  << ::std::endl << fem::types::card("").format()
                  << card._SFY.format(card.SFY)
                  << card._SFZ.format(card.SFZ)
                  << card._NLOBY.format(card.NLOBY)
                  << card._NLOBZ.format(card.NLOBZ) << ::std::endl;
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
