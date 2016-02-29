/**
   \file fem_cards_glsec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GLSEC` cards.

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

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card glsec::head("GLSEC");

            const entry_type<long> glsec::_form_GEONO("GEONO");
            const entry_type<double> glsec::_form_HZ("HZ");
            const entry_type<double> glsec::_form_TY("TY");
            const entry_type<double> glsec::_form_BY("BY");
            const entry_type<double> glsec::_form_TZ("TZ");
            const entry_type<double> glsec::_form_SFY("SFY");
            const entry_type<double> glsec::_form_SFZ("SFZ");
            const entry_type<bool> glsec::_form_K("K");
            const entry_type<long> glsec::_form_NLOBY("NLOBY");
            const entry_type<long> glsec::_form_NLOBZ("NLOBZ");

            glsec::glsec(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               HZ = _form_HZ(*(pos++));
               TY = _form_TY(*(pos++));
               BY = _form_BY(*(pos++));
               TZ = _form_TZ(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               K = _form_K(*(pos++));
               NLOBY = _form_NLOBY(*(pos++));
               NLOBZ = _form_NLOBZ(*pos);
            }

            glsec::glsec(const long &GEONO, const double &HZ,
                         const double &TY, const double &BY,
                         const double &TZ, const double &SFY,
                         const double &SFZ, const bool &K,
                         const long &NLOBY, const long &NLOBZ) :
               card(), GEONO(GEONO),
               HZ(HZ), TY(TY), BY(BY), TZ(TZ),
               SFY(SFY), SFZ(SFZ),
               K(K), NLOBY(NLOBY), NLOBZ(NLOBZ) {}

            const ::dnvgl::extfem::fem::cards::types
            glsec::card_type(void) const {return GLSEC;}

            const ::std::ostream&
            glsec::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const glsec &card) {
               os << glsec::head.format()
                  << card._form_GEONO.format(card.GEONO)
                  << card._form_HZ.format(card.HZ)
                  << card._form_TY.format(card.TY)
                  << card._form_BY.format(card.BY)
                  << ::std::endl << ::dnvgl::extfem::fem::types::card().format()
                  << card._form_TZ.format(card.TZ)
                  << card._form_SFY.format(card.SFY)
                  << card._form_SFZ.format(card.SFZ)
                  << card._form_K.format(card.K)
                  << ::std::endl << ::dnvgl::extfem::fem::types::card().format()
                  << card._form_NLOBY.format(card.NLOBY)
                  << card._form_NLOBZ.format(card.NLOBZ)
                  << card.empty.format() << card.empty.format()
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
