/**
   \file fem/fem_cards_geccen.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GECCEN` cards.

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

            const fem::types::card geccen::head("GECCEN");


            const entry_type<long> geccen::_form_ECCNO("ECCNO");
            const entry_type<double> geccen::_form_EX("EX");
            const entry_type<double> geccen::_form_EY("EY");
            const entry_type<double> geccen::_form_EZ("EZ");

            geccen::geccen(void) : geccen(-1, 0., 0., 0.) {}

            geccen::geccen(geccen const *that) :
               geccen(that->ECCNO, that->EX, that->EY, that->EZ) {}

            geccen::geccen(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 5)
                  throw errors::parse_error(
                     "GECCEN", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               ECCNO = _form_ECCNO(*(pos++));
               EX = _form_EX(*(pos++));
               EY = _form_EY(*(pos++));
               EZ = _form_EZ(*(pos++));
            }

            geccen::geccen(
               long const &ECCNO,
               double const &EX, double const &EY, double const &EZ) :
               card(), ECCNO(ECCNO), EX(EX), EY(EY), EZ(EZ) {}

            geccen::geccen(long const &ECCNO,
                           std::vector<double> const &pos) :
               card(), ECCNO(ECCNO), EX(0.), EY(0.), EZ(0.) {
               assert(pos.size() == 3);
               EX = pos[0];
               EY = pos[1];
               EZ = pos[2];
            }

            const dnvgl::extfem::fem::cards::types
            geccen::card_type(void) const {return GECCEN;}

            const std::ostream&
            geccen::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
               operator<< (std::ostream &os, geccen const &card) {
               if (card.ECCNO == -1) return os;
               os << geccen::head.format()
                  << card._form_ECCNO.format(card.ECCNO)
                  << card._form_EX.format(card.EX)
                  << card._form_EY.format(card.EY)
                  << card._form_EZ.format(card.EZ) << std::endl;
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
