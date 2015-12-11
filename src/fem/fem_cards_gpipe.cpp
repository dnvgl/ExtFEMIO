/**
   \file fem/fem_cards_gpipe.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GPIPE` cards.

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

            const fem::types::card gpipe::head("GPIPE");

            const entry_type<long> gpipe::_form_GEONO("GEONO");
            const entry_type<double> gpipe::_form_DI("DI");
            const entry_type<double> gpipe::_form_DY("DY");
            const entry_type<double> gpipe::_form_T("T");
            const entry_type<double> gpipe::_form_SFY("SFY");
            const entry_type<double> gpipe::_form_SFZ("SFZ");
            const entry_type<long> gpipe::_form_NCIR("NCIR");
            const entry_type<long> gpipe::_form_NRAD("NRAD");

            gpipe::gpipe(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               DI = _form_DI(*(pos++));
               DY = _form_DY(*(pos++));
               T = _form_T(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               NCIR = _form_NCIR(*(pos++));
               NRAD = _form_NRAD(*pos);
            }

            gpipe::gpipe(const long &GEONO, const double &DI,
                         const double &DY,
                         const double &T, const double &SFY,
                         const double &SFZ,
                         const long &NCIR, const long &NRAD) :
               card(), GEONO(GEONO),
               DI(DI), DY(DY), T(T),
               SFY(SFY), SFZ(SFZ),
               NCIR(NCIR), NRAD(NRAD) {}

            const ::dnvgl::extfem::fem::cards::types
            gpipe::card_type(void) const {return GPIPE;}

            const ::std::ostream&
            gpipe::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const gpipe &card) {
               os << gpipe::head.format()
                  << card._form_GEONO.format(card.GEONO)
                  << card._form_DI.format(card.DI)
                  << card._form_DY.format(card.DY)
                  << card._form_T.format(card.T)
                  << ::std::endl << ::dnvgl::extfem::fem::types::card().format()
                  << card._form_SFY.format(card.SFY)
                  << card._form_SFZ.format(card.SFZ)
                  << card._form_NCIR.format(card.NCIR)
                  << card._form_NRAD.format(card.NRAD)
                  << ::std::endl;
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
