/**
   \file fem/fem_cards_gusyi.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `GUSYI` cards.

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

            const fem::types::card gusyi::head("GUSYI");

            entry_type<double> const gusyi::_form_HZ("HZ");
            entry_type<double> const gusyi::_form_TY("TY");
            entry_type<double> const gusyi::_form_BT("BT");
            entry_type<double> const gusyi::_form_B1("B1");
            entry_type<double> const gusyi::_form_TT("TT");
            entry_type<double> const gusyi::_form_BB("BB");
            entry_type<double> const gusyi::_form_B2("B2");
            entry_type<double> const gusyi::_form_TB("TB");
            entry_type<double> const gusyi::_form_SFY("SFY");
            entry_type<double> const gusyi::_form_SFZ("SFZ");
            entry_type<long> const gusyi::_form_NLOBYT("NLOBYT");
            entry_type<long> const gusyi::_form_NLOBYB("NLOBYB");
            entry_type<long> const gusyi::_form_NLOBZ("NLOBZ");

            gusyi::gusyi(const std::deque<std::string> &inp) :
               BeamProp(inp) {

               if (inp.size() < 15)
                  throw errors::parse_error(
                     "GUSYU", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               GEONO = _form_GEONO(*(pos++));
               HZ = _form_HZ(*(pos++));
               TY = _form_TY(*(pos++));
               BT = _form_BT(*(pos++));
               B1 = _form_B1(*(pos++));
               TT = _form_TT(*(pos++));
               BB = _form_BB(*(pos++));
               B2 = _form_B2(*(pos++));
               TB = _form_TB(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               NLOBYT = _form_NLOBYT(*(pos++));
               NLOBYB = _form_NLOBYB(*(pos++));
               NLOBZ = _form_NLOBZ(*(pos++));
            }

            gusyi::gusyi(void) :
               gusyi(-1, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.) {}

            gusyi::gusyi(
               long const &GEONO,
               double const &HZ, double const &TY,
               double const &BT, double const &B1, double const &TT,
               double const &BB, double const &B2, double const &TB,
               double const &SFY, double const &SFZ,
               long const &NLOBYT, long const &NLOBYB, long const &NLOBZ) :
               BeamProp(GEONO),
               HZ(HZ), TY(TY),
               BT(BT), B1(B1), TT(TT),
               BB(BB), B2(B2),TB(TB),
               SFY(SFY), SFZ(SFZ),
               NLOBYT(NLOBYT), NLOBYB(NLOBYB), NLOBZ(NLOBZ) {}

            const dnvgl::extfem::fem::cards::types
            gusyi::card_type(void) const {return GUSYI;}

            const std::ostream&
            gusyi::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const gusyi &card) {
               if (card.GEONO == -1) return os;
               os << gusyi::head.format()
                  << card._form_GEONO.format(card.GEONO)
                  << card._form_HZ.format(card.HZ)
                  << card._form_TY.format(card.TY)
                  << card._form_BT.format(card.BT)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << card._form_B1.format(card.B1)
                  << card._form_TT.format(card.TT)
                  << card._form_BB.format(card.BB)
                  << card._form_B2.format(card.B2)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << card._form_TB.format(card.TB)
                  << card._form_SFY.format(card.SFY)
                  << card._form_SFZ.format(card.SFZ)
                  << card._form_NLOBYT.format(card.NLOBYT)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << card._form_NLOBYB.format(card.NLOBYB)
                  << card._form_NLOBZ.format(card.NLOBZ)
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
