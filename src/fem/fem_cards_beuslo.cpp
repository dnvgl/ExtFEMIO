/**
   \file fem/fem_cards_beuslo.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BEUSLO` cards.

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

            const fem::types::card beuslo::head("BEUSLO");

            const entry_type<long> beuslo::_form_LLC("LLC");
            const entry_type<long> beuslo::_form_LOTYP("LOTYP");
            const entry_type<bool> beuslo::_form_COMPLX("COMPLX");
            const entry_type<long> beuslo::_form_LAYER("LAYER");
            const entry_type<long> beuslo::_form_ELNO("ELNO");
            const entry_type<long> beuslo::_form_NDOF("NDOF");
            const entry_type<long> beuslo::_form_INTNO("INTNO");
            const entry_type<long> beuslo::_form_SIDE("SIDE");
            const entry_type<double> beuslo::_form_RLOAD("RLOAD");
            const entry_type<double> beuslo::_form_ILOAD("ILOAD");

            beuslo::beuslo(std::deque<std::string> const &inp) :
               card(inp) {

               if (inp.size() < 10)
                  throw errors::parse_error(
                     "BEUSLO", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               LLC = _form_LLC(*(pos++));
               LOTYP = _form_LOTYP(*(pos++));
               COMPLX = _form_COMPLX(*(pos++));
               LAYER = _form_LAYER(*(pos++));
               ELNO = _form_ELNO(*(pos++));
               NDOF = _form_NDOF(*(pos++));
               INTNO = _form_INTNO(*(pos++));
               SIDE = _form_SIDE(*(pos++));
               for (int i = 0; i < NDOF; i++)
                  RLOADi.push_back(_form_RLOAD(*(pos++)));
               if (COMPLX)
                  for (int i = 0; i < NDOF; i++)
                     ILOADi.push_back(_form_ILOAD(*(pos++)));
            };

            beuslo::beuslo() :
               beuslo(-1, 0, 0, 0, 0, 0, 0, 0, {}, {}) {}

            beuslo::beuslo(const long &LLC,
                           const long &LOTYP,
                           const bool &COMPLX,
                           const long &LAYER,
                           const long &ELNO,
                           const long &NDOF,
                           const long &INTNO,
                           const long &SIDE,
                           const std::deque<double> &RLOAD,
                           const std::deque<double> &ILOAD) :
               card(), LLC(LLC), LOTYP(LOTYP), COMPLX(COMPLX),
               LAYER(LAYER), ELNO(ELNO), NDOF(NDOF), INTNO(INTNO),
               SIDE(SIDE), RLOADi(RLOAD), ILOADi(ILOAD) {
               if (!this->COMPLX && this->ILOADi.size() > 0)
                  throw dnvgl::extfem::fem::errors::usage_error(
                     "BEUSLO", "ILOAD data given with COMPLX == false");
               else if (this->COMPLX  && this->ILOADi.size() == 0)
                  throw dnvgl::extfem::fem::errors::usage_error(
                     "BEUSLO", "no ILOAD data given with COMPLX == True");
               if (this->RLOADi.size() != (size_t)this->NDOF)
                  throw dnvgl::extfem::fem::errors::usage_error(
                     "BEUSLO", "RLOAD not of size NDOF");
               if (this->ILOADi.size() > 0 &&
                   this->ILOADi.size() != (size_t)this->NDOF)
                  throw dnvgl::extfem::fem::errors::usage_error(
                     "BEUSLO", "ILOAD not of size NDOF");
            }

            beuslo::beuslo(const long &LLC,
                           const long &LOTYP,
                           const bool &COMPLX,
                           const long &LAYER,
                           const long &ELNO,
                           const long &INTNO,
                           const long &SIDE,
                           const std::deque<double> &RLOAD,
                           const std::deque<double> &ILOAD) :
                           beuslo(LLC, LOTYP, COMPLX, LAYER, ELNO, static_cast<long>(RLOAD.size()),
                      INTNO, SIDE, RLOAD, ILOAD) {}

            beuslo::beuslo(const long &LLC,
                           const long &LOTYP,
                           const long &LAYER,
                           const long &ELNO,
                           const long &NDOF,
                           const long &INTNO,
                           const long &SIDE,
                           const std::deque<double> &RLOAD,
                           const std::deque<double> &ILOAD) :
               beuslo(LLC, LOTYP, ILOAD.size() > 0, LAYER, ELNO, NDOF, INTNO,
                      SIDE, RLOAD, ILOAD) {}

            beuslo::beuslo(const long &LLC,
                           const long &LOTYP,
                           const long &LAYER,
                           const long &ELNO,
                           const long &INTNO,
                           const long &SIDE,
                           const std::deque<double> &RLOAD,
                           const std::deque<double> &ILOAD) :
               beuslo(LLC, LOTYP, ILOAD.size() > 0, LAYER, ELNO, static_cast<long>(RLOAD.size()),
                      INTNO, SIDE, RLOAD, ILOAD) {}

            const dnvgl::extfem::fem::cards::types
            beuslo::card_type(void) const {
               return BEUSLO;
            };

            std::ostream&
            operator<< (std::ostream &os, const beuslo &card) {
               if (card.LLC == -1) return os;
               os << beuslo::head.format()
                  << card._form_LLC.format(card.LLC)
                  << card._form_LOTYP.format(card.LOTYP)
                  << card._form_COMPLX.format(card.COMPLX)
                  << card._form_LAYER.format(card.LAYER)
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_ELNO.format(card.ELNO)
                  << card._form_NDOF.format(card.NDOF)
                  << card._form_INTNO.format(card.INTNO)
                  << card._form_SIDE.format(card.SIDE)
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format();
               size_t num = 0;
               for (int i = 0; i<card.NDOF; i++) {
                  if (num == 4) {
                     num = 0;
                     os << std::endl
                        << dnvgl::extfem::fem::types::card().format();
                  }
                  num++;
                  os << card._form_RLOAD.format(card.RLOADi[i]);
               }
               if (card.COMPLX) {
                  for (int i = 0; i<card.NDOF; i++) {
                     if (num == 4) {
                        num = 0;
                        os << std::endl
                           << dnvgl::extfem::fem::types::card().format();
                     }
                     num++;
                     os << card._form_ILOAD.format(card.ILOADi[i]);
                  }
               }
               os << std::endl;
               return os;
            }

            const std::ostream&
            beuslo::operator<< (std::ostream& os) const {
               os << this;
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
// compile-command: "make -C ../.. check -j8"
// End:
