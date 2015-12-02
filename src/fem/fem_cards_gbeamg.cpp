/**
   \file fem/fem_cards_gbeamg.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GBEAMG` cards.

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

            const fem::types::card gbeamg::head("GBEAMG");

            const entry_type<long> gbeamg::_GEONO("GEONO");
            const entry_type<double> gbeamg::_AREA("AREA");
            const entry_type<double> gbeamg::_IX("IX");
            const entry_type<double> gbeamg::_IY("IY");
            const entry_type<double> gbeamg::_IZ("IZ");
            const entry_type<double> gbeamg::_IYZ("IYZ");
            const entry_type<double> gbeamg::_WXMIN("WXMIN");
            const entry_type<double> gbeamg::_WYMIN("WYMIN");
            const entry_type<double> gbeamg::_WZMIN("WZMIN");
            const entry_type<double> gbeamg::_SHARY("SHARY");
            const entry_type<double> gbeamg::_SHARZ("SHARZ");
            const entry_type<double> gbeamg::_SHCENY("SHCENY");
            const entry_type<double> gbeamg::_SHCENZ("SHCENZ");
            const entry_type<double> gbeamg::_SY("SY");
            const entry_type<double> gbeamg::_SZ("SZ");

            gbeamg::gbeamg(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               GEONO = _GEONO(*(pos++));
               ++pos;
               AREA = _AREA(*(pos++));
               IX = _IX(*(pos++));
               IY = _IY(*(pos++));
               IZ = _IZ(*(pos++));
               IYZ = _IYZ(*(pos++));
               WXMIN = _WXMIN(*(pos++));
               WYMIN = _WYMIN(*(pos++));
               WZMIN = _WZMIN(*(pos++));
               SHARY = _SHARY(*(pos++));
               SHARZ = _SHARZ(*(pos++));
               SHCENY = _SHCENY(*(pos++));
               SHCENZ = _SHCENZ(*(pos++));
               SY = _SY(*(pos++));
               SZ = _SZ(*(pos++));
            }

            gbeamg::gbeamg(
               const long &GEONO,
               const double &AREA,
               const double &IX, const double &IY, const double &IZ, const double &IYZ,
               const double &WXMIN, const double &WYMIN, const double &WZMIN,
               const double &SHARY, const double &SHARZ,
               const double &SHCENY, const double &SHCENZ,
               const double &SY, const double &SZ) :
               card(),
               GEONO(GEONO),
               AREA(AREA), IX(IX), IY(IY), IZ(IZ), IYZ(IYZ),
               WXMIN(WXMIN), WYMIN(WYMIN), WZMIN(WZMIN),
               SHARY(SHARY), SHARZ(SHARZ),
               SHCENY(SHCENY), SHCENZ(SHCENZ), SY(SY),
               SZ(SZ) {}

            const ::dnvgl::extfem::fem::cards::types
            gbeamg::card_type(void) const {return GBEAMG;}

            const ::std::ostream&
            gbeamg::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const gbeamg &card) {
               os << gbeamg::head.format()
                  << card._GEONO.format(card.GEONO)
                  << card.empty.format()
                  << card._AREA.format(card.AREA)
                  << card._IX.format(card.IX)
                  << ::std::endl << fem::types::card("").format()
                  << card._IY.format(card.IY)
                  << card._IZ.format(card.IZ)
                  << card._IYZ.format(card.IYZ)
                  << card._WXMIN.format(card.WXMIN)
                  << ::std::endl << fem::types::card("").format()
                  << card._WYMIN.format(card.WYMIN)
                  << card._WZMIN.format(card.WZMIN)
                  << card._SHARY.format(card.SHARY)
                  << card._SHARZ.format(card.SHARZ)
                  << ::std::endl << fem::types::card("").format()
                  << card._SHCENY.format(card.SHCENY)
                  << card._SHCENZ.format(card.SHCENZ)
                  << card._SY.format(card.SY)
                  << card._SZ.format(card.SZ) << ::std::endl;
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
