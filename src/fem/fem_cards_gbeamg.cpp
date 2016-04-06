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

            const fem::types::card gbeamg::head("GBEAMG");

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

            gbeamg::gbeamg(const std::deque<std::string> &inp) :
               BeamProp(inp) {

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
               BeamProp(),
               AREA(AREA), IX(IX), IY(IY), IZ(IZ), IYZ(IYZ),
               WXMIN(WXMIN), WYMIN(WYMIN), WZMIN(WZMIN),
               SHARY(SHARY), SHARZ(SHARZ),
               SHCENY(SHCENY), SHCENZ(SHCENZ), SY(SY),
               SZ(SZ) {
               this->GEONO = GEONO;
            }

            const dnvgl::extfem::fem::cards::types
            gbeamg::card_type(void) const {return GBEAMG;}

            const std::ostream&
            gbeamg::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const gbeamg &data) {
               os << gbeamg::head.format()
                  << data._form_GEONO.format(data.GEONO)
                  << data.empty.format()
                  << data._form_AREA.format(data.AREA)
                  << data._form_IX.format(data.IX)
                  << std::endl << fem::types::card("").format()
                  << data._form_IY.format(data.IY)
                  << data._form_IZ.format(data.IZ)
                  << data._form_IYZ.format(data.IYZ)
                  << data._form_WXMIN.format(data.WXMIN)
                  << std::endl << fem::types::card("").format()
                  << data._form_WYMIN.format(data.WYMIN)
                  << data._form_WZMIN.format(data.WZMIN)
                  << data._form_SHARY.format(data.SHARY)
                  << data._form_SHARZ.format(data.SHARZ)
                  << std::endl << fem::types::card("").format()
                  << data._form_SHCENY.format(data.SHCENY)
                  << data._form_SHCENZ.format(data.SHCENZ)
                  << data._form_SY.format(data.SY)
                  << data._form_SZ.format(data.SZ) << std::endl;
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
