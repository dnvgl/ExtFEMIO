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

            const fem::types::card gbarm::head("GBARM");

            const entry_type<double> gbarm::_form_HZ("HZ");
            const entry_type<double> gbarm::_form_BT("BT");
            const entry_type<double> gbarm::_form_BB("BB");
            const entry_type<double> gbarm::_form_SFY("SFY");
            const entry_type<double> gbarm::_form_SFZ("SFZ");
            const entry_type<long> gbarm::_form_NLOBY("NLOBY");
            const entry_type<long> gbarm::_form_NLOBZ("NLOBZ");

            gbarm::gbarm(const std::list<std::string> &inp) :
               base_beam_prop(inp), NLOBY(0), NLOBZ(0) {

               if (inp.size() < 9)
                  throw errors::parse_error(
                     "GBARM", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               HZ = _form_HZ(*(pos++));
               BT = _form_BT(*(pos++));
               BB = _form_BB(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NLOBY = _form_NLOBY(*(pos++));
               else
                  pos++;
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NLOBZ = _form_NLOBZ(*(pos++));
            }

            gbarm::gbarm(void) :
               gbarm(-1, 0, 0, 0, 0, 0, 0, 0) {}

            gbarm::gbarm(
               const long &GEONO,
               const double &HZ, const double &BT, const double &BB,
               const double &SFY, const double &SFZ,
               const long &NLOBY/*=0*/, const long &NLOBZ/*=0*/) :
               base_beam_prop(GEONO), HZ(HZ), BT(BT), BB(BB),
               SFY(SFY), SFZ(SFZ), NLOBY(NLOBY), NLOBZ(NLOBZ) {}

            const dnvgl::extfem::fem::cards::types
            gbarm::card_type(void) const {return GBARM;}

            std::ostream &gbarm::put(std::ostream& os) const {
               if (this->GEONO == -1) return os;
               os << gbarm::head.format()
                  << this->_form_GEONO.format(this->GEONO)
                  << this->_form_HZ.format(this->HZ)
                  << this->_form_BT.format(this->BT)
                  << this->_form_BB.format(this->BB)
                  << std::endl << fem::types::card("").format()
                  << this->_form_SFY.format(this->SFY)
                  << this->_form_SFZ.format(this->SFZ);
               if ((this->NLOBY || this->NLOBZ))
                  os << this->_form_NLOBY.format(this->NLOBY)
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
// compile-command: "make -C ../.. check -j8"
// End:
