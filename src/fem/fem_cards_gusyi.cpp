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
   const char cID_fem_cards_gusyi[]
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

            gusyi::gusyi(const std::list<std::string> &inp) :
               __base::beam_prop(inp), NLOBYT(0), NLOBYB(0), NLOBZ(0) {

               if (inp.size() < 12)
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
               __base::beam_prop(GEONO),
               HZ(HZ), TY(TY),
               BT(BT), B1(B1), TT(TT),
               BB(BB), B2(B2),TB(TB),
               SFY(SFY), SFZ(SFZ),
               NLOBYT(NLOBYT), NLOBYB(NLOBYB), NLOBZ(NLOBZ) {}

            const dnvgl::extfem::fem::cards::types
            gusyi::card_type(void) const {return types::GUSYI;}

            std::ostream &gusyi::put(std::ostream& os) const {
               if (this->GEONO == -1) return os;
               os << gusyi::head.format()
                  << this->_form_GEONO.format(this->GEONO)
                  << this->_form_HZ.format(this->HZ)
                  << this->_form_TY.format(this->TY)
                  << this->_form_BT.format(this->BT)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << this->_form_B1.format(this->B1)
                  << this->_form_TT.format(this->TT)
                  << this->_form_BB.format(this->BB)
                  << this->_form_B2.format(this->B2)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << this->_form_TB.format(this->TB)
                  << this->_form_SFY.format(this->SFY)
                  << this->_form_SFZ.format(this->SFZ);
               if ((this->NLOBYT || this->NLOBYB || this->NLOBZ))
                  os << this->_form_NLOBYT.format(this->NLOBYT)
                     << std::endl << dnvgl::extfem::fem::types::card().format()
                     << this->_form_NLOBYB.format(this->NLOBYB)
                     << this->_form_NLOBZ.format(this->NLOBZ);
               os << std::endl;
               return os;
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
