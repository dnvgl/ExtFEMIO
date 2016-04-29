/**
   \file fem/fem_cards_giorh.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GIORH` cards.

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

            const fem::types::card giorh::head("GIORH");


            const entry_type<double> giorh::_form_HZ("HZ");
            const entry_type<double> giorh::_form_TY("TY");
            const entry_type<double> giorh::_form_BT("BT");
            const entry_type<double> giorh::_form_TT("TT");
            const entry_type<double> giorh::_form_BB("BB");
            const entry_type<double> giorh::_form_TB("TB");
            const entry_type<double> giorh::_form_SFY("SFY");
            const entry_type<double> giorh::_form_SFZ("SFZ");
            const entry_type<long> giorh::_form_NLOBYT("NLOBYT");
            const entry_type<long> giorh::_form_NLOBYB("NLOBYB");
            const entry_type<long> giorh::_form_NLOBZ("NLOBZ");


            giorh::giorh(const std::deque<std::string> &inp) :
               BeamProp(inp), NLOBYT(0), NLOBYB(0), NLOBZ(0) {

               if (inp.size() < 13)
                  throw errors::parse_error(
                     "GIORH", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               HZ = _form_HZ(*(pos++));
               TY = _form_TY(*(pos++));
               BT = _form_BT(*(pos++));
               TT = _form_TT(*(pos++));
               BB = _form_BB(*(pos++));
               TB = _form_TB(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NLOBYT = _form_NLOBYT(*(pos++));
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NLOBYB = _form_NLOBYB(*(pos++));
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NLOBZ = _form_NLOBZ(*pos);
            }
            giorh::giorh(void) :
               giorh(-1, 0., 0., 0., 0., 0., 0., 0., 0.) {}

            giorh::giorh(const long &GEONO, const double &HZ,
                         const double &TY, const double &BT,
                         const double &TT, const double &BB,
                         const double &TB, const double &SFY,
                         const double &SFZ,
                         const long &NLOBYT/*=0*/, const long &NLOBYB/*=0*/, const long &NLOBZ/*=0*/) :
               BeamProp(GEONO),
               HZ(HZ), TY(TY), BT(BT), TT(TT), BB(BB), TB(TB),
               SFY(SFY), SFZ(SFZ),
               NLOBYT(NLOBYT), NLOBYB(NLOBYB), NLOBZ(NLOBZ) {}

            const dnvgl::extfem::fem::cards::types
            giorh::card_type(void) const {return GIORH;}

            const std::ostream&
            giorh::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const giorh &card) {
               if (card.GEONO == -1) return os;
               os << giorh::head.format()
                  << card._form_GEONO.format(card.GEONO)
                  << card._form_HZ.format(card.HZ)
                  << card._form_TY.format(card.TY)
                  << card._form_BT.format(card.BT)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << card._form_TT.format(card.TT)
                  << card._form_BB.format(card.BB)
                  << card._form_TB.format(card.TB)
                  << card._form_SFY.format(card.SFY)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << card._form_SFZ.format(card.SFZ)
                  << card._form_NLOBYT.format(card.NLOBYT)
                  << card._form_NLOBYB.format(card.NLOBYB)
                  << card._form_NLOBZ.format(card.NLOBZ) << std::endl;
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
