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

            const fem::types::card gbeamg::head("GBEAMG");

            const entry_type<long> gbeamg::_form_GEONO("GEONO");
            const entry_type<double> gbeamg::_form_AREA("AREA");
            const entry_type<double> gbeamg::_form_IX("IX");
            const entry_type<double> gbeamg::_form_IY("IY");
            const entry_type<double> gbeamg::_form_IZ("IZ");
            const entry_type<double> gbeamg::_form_IYZ("IYZ");
            const entry_type<double> gbeamg::_form_WXMIN("WXMIN");
            const entry_type<double> gbeamg::_form_WYMIN("WYMIN");
            const entry_type<double> gbeamg::_form_WZMIN("WZMIN");
            const entry_type<double> gbeamg::_form_SHARY("SHARY");
            const entry_type<double> gbeamg::_form_SHARZ("SHARZ");
            const entry_type<double> gbeamg::_form_SHCENY("SHCENY");
            const entry_type<double> gbeamg::_form_SHCENZ("SHCENZ");
            const entry_type<double> gbeamg::_form_SY("SY");
            const entry_type<double> gbeamg::_form_SZ("SZ");

            gbeamg::gbeamg(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               ++pos;
               AREA = _form_AREA(*(pos++));
               IX = _form_IX(*(pos++));
               IY = _form_IY(*(pos++));
               IZ = _form_IZ(*(pos++));
               IYZ = _form_IYZ(*(pos++));
               WXMIN = _form_WXMIN(*(pos++));
               WYMIN = _form_WYMIN(*(pos++));
               WZMIN = _form_WZMIN(*(pos++));
               SHARY = _form_SHARY(*(pos++));
               SHARZ = _form_SHARZ(*(pos++));
               SHCENY = _form_SHCENY(*(pos++));
               SHCENZ = _form_SHCENZ(*(pos++));
               SY = _form_SY(*(pos++));
               SZ = _form_SZ(*(pos++));
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
                  << card._form_GEONO.format(card.GEONO)
                  << card.empty.format()
                  << card._form_AREA.format(card.AREA)
                  << card._form_IX.format(card.IX)
                  << ::std::endl << fem::types::card("").format()
                  << card._form_IY.format(card.IY)
                  << card._form_IZ.format(card.IZ)
                  << card._form_IYZ.format(card.IYZ)
                  << card._form_WXMIN.format(card.WXMIN)
                  << ::std::endl << fem::types::card("").format()
                  << card._form_WYMIN.format(card.WYMIN)
                  << card._form_WZMIN.format(card.WZMIN)
                  << card._form_SHARY.format(card.SHARY)
                  << card._form_SHARZ.format(card.SHARZ)
                  << ::std::endl << fem::types::card("").format()
                  << card._form_SHCENY.format(card.SHCENY)
                  << card._form_SHCENZ.format(card.SHCENZ)
                  << card._form_SY.format(card.SY)
                  << card._form_SZ.format(card.SZ) << ::std::endl;
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
