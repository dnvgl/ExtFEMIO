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

            fem::types::card const giorh::head("GIORH");

            entry_type<double> const giorh::_form_HZ("HZ");
            entry_type<double> const giorh::_form_TY("TY");
            entry_type<double> const giorh::_form_BT("BT");
            entry_type<double> const giorh::_form_TT("TT");
            entry_type<double> const giorh::_form_BB("BB");
            entry_type<double> const giorh::_form_TB("TB");
            entry_type<double> const giorh::_form_SFY("SFY");
            entry_type<double> const giorh::_form_SFZ("SFZ");
            entry_type<long> const giorh::_form_NLOBYT("NLOBYT");
            entry_type<long> const giorh::_form_NLOBYB("NLOBYB");
            entry_type<long> const giorh::_form_NLOBZ("NLOBZ");


            giorh::giorh(std::list<std::string> const &inp) :
               base_beam_prop(inp), NLOBYT(0), NLOBYB(0), NLOBZ(0) {

               if (inp.size() < 10)
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
               else
                  pos++;
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NLOBYB = _form_NLOBYB(*(pos++));
               else
                  pos++;
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NLOBZ = _form_NLOBZ(*pos);
            }

            giorh::giorh(void) :
               giorh(-1, 0., 0., 0., 0., 0., 0., 0., 0.) {}

            giorh::giorh(long const &GEONO, double const &HZ,
                         double const &TY, double const &BT,
                         double const &TT, double const &BB,
                         double const &TB, double const &SFY,
                         double const &SFZ,
                         long const &NLOBYT/*=0*/, long const &NLOBYB/*=0*/, long const &NLOBZ/*=0*/) :
               base_beam_prop(GEONO),
               HZ(HZ), TY(TY), BT(BT), TT(TT), BB(BB), TB(TB),
               SFY(SFY), SFZ(SFZ),
               NLOBYT(NLOBYT), NLOBYB(NLOBYB), NLOBZ(NLOBZ) {}

            dnvgl::extfem::fem::cards::types const
            giorh::card_type(void) const {return GIORH;}

            std::ostream &giorh::put(std::ostream& os) const {
               if (this->GEONO == -1) return os;
               os << giorh::head.format()
                  << this->_form_GEONO.format(this->GEONO)
                  << this->_form_HZ.format(this->HZ)
                  << this->_form_TY.format(this->TY)
                  << this->_form_BT.format(this->BT)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << this->_form_TT.format(this->TT)
                  << this->_form_BB.format(this->BB)
                  << this->_form_TB.format(this->TB)
                  << this->_form_SFY.format(this->SFY)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << this->_form_SFZ.format(this->SFZ);
               if ((this->NLOBYT || this->NLOBYB || this->NLOBZ))
                  os << this->_form_NLOBYT.format(this->NLOBYT)
                     << this->_form_NLOBYB.format(this->NLOBYB)
                     << this->_form_NLOBZ.format(this->NLOBZ);
               return os << std::endl;
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
