/**
   \file fem/fem_cards_bnload.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BNLOAD` cards.

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

            const fem::types::card bnload::head("BNLOAD");

            const entry_type<long> bnload::_form_LLC("LLC");
            const entry_type<long> bnload::_form_LOTYP("LOTYP");
            const entry_type<bool> bnload::_form_COMPLX("COMPLX");
            const entry_type<long> bnload::_form_NODENO("NODENO");
            const entry_type<long> bnload::_form_NDOF("NDOF");
            const entry_type<double> bnload::_form_RLOAD("RLOAD");
            const entry_type<double> bnload::_form_ILOAD("ILOAD");

            bnload::bnload(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;

               LLC = _form_LLC(*(pos++));
               LOTYP = _form_LOTYP (*(pos++));
               COMPLX = _form_COMPLX(*(pos++));
               ++pos;
               NODENO = _form_NODENO(*(pos++));
               NDOF = _form_NDOF(*(pos++));
               for (long i = 0; i < NDOF; i++)
                  RLOAD.push_back(_form_RLOAD(*(pos++)));

               if (COMPLX)
                  ILOAD.push_back(_form_ILOAD(*(pos++)));
            }

            bnload::bnload(const long &LLC,
                             const long &LOTYP,
                             const bool &COMPLX,
                             const long &NODENO,
                             const long &NDOF,
                             const ::std::deque<double> &RLOAD,
                             const ::std::deque<double> &ILOAD) :
               card(), LLC(LLC), LOTYP(LOTYP), COMPLX(COMPLX),
               NODENO(NODENO), NDOF(NDOF),
               RLOAD(RLOAD), ILOAD(ILOAD) {}


            bnload::bnload(const long &LLC,
                             const long &LOTYP,
                             const bool &COMPLX,
                             const long &NODENO,
                             const ::std::deque<double> &RLOAD,
                             const ::std::deque<double> &ILOAD):
               card(), LLC(LLC), LOTYP(LOTYP), COMPLX(COMPLX),
               NODENO(NODENO), NDOF(RLOAD.size()),
               RLOAD(RLOAD), ILOAD(ILOAD) {}

            bnload::bnload(const long &LLC,
                             const long &LOTYP,
                             const long &NODENO,
                             const long &NDOF,
                             const ::std::deque<double> &RLOAD,
                             const ::std::deque<double> &ILOAD) :
               card(), LLC(LLC), LOTYP(LOTYP),
               COMPLX(ILOAD.size() > 0),
               NODENO(NODENO), NDOF(NDOF),
               RLOAD(RLOAD), ILOAD(ILOAD) {}


            bnload::bnload(const long &LLC,
                             const long &LOTYP,
                             const long &NODENO,
                             const ::std::deque<double> &RLOAD,
                             const ::std::deque<double> &ILOAD) :
               card(), LLC(LLC), LOTYP(LOTYP),
               COMPLX(ILOAD.size() > 0),
               NODENO(NODENO), NDOF(RLOAD.size()),
               RLOAD(RLOAD), ILOAD(ILOAD) {}

            const ::dnvgl::extfem::fem::cards::types
            bnload::card_type(void) const {return BNLOAD;}

            const ::std::ostream&
            bnload::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const bnload &card) {
               os << bnload::head.format()
                  << card._form_LLC.format(card.LLC)
                  << card._form_LOTYP.format(card.LOTYP)
                  << card._form_COMPLX.format(card.COMPLX)
                  << card.empty.format() << ::std::endl
                  << ::dnvgl::extfem::fem::types::card().format()
                  << card._form_NODENO.format(card.NODENO)
                  << card._form_NDOF.format(card.NDOF);
               long cnt = 2;
               for (long i = 0; i < card.NDOF; i++) {
                  if (cnt == 4) {
                     os << ::std::endl << ::dnvgl::extfem::fem::types::card().format();
                     cnt = 0;
                  }
                  os << card._form_RLOAD.format(card.RLOAD[i]);
                  cnt += 1;
               }
               if (card.COMPLX)
                  for (long i = 0; i < card.NDOF; i++) {
                     if (cnt == 4) {
                        os << ::std::endl << ::dnvgl::extfem::fem::types::card().format();
                        cnt = 0;
                     }
                     os << card._form_ILOAD.format(card.ILOAD[i]);
                     cnt += 1;
                  }
               while (cnt < 4) {
                  os << card.empty.format();
                  cnt += 1;
               }
               os << ::std::endl;
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
