/**
   \file fem/fem_cards_hierarch.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `HIERARCH` cards.

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

            const fem::types::card hierarch::head("HIERARCH");

            const entry_type<long> hierarch::_form_NFIELD("NFIELD");
            const entry_type<long> hierarch::_form_IHREF("IHREF");
            const entry_type<long> hierarch::_form_ISELTY("ISELTY");
            const entry_type<long> hierarch::_form_INDSEL("INDSEL");
            const entry_type<long> hierarch::_form_ISLEVL("ISLEVL");
            const entry_type<long> hierarch::_form_ITREF("ITREF");
            const entry_type<long> hierarch::_form_IHPREF("IHPREF");
            const entry_type<long> hierarch::_form_NSUB("NSUB");
            const entry_type<long> hierarch::_form_IHSREF("IHSREF");


            hierarch::hierarch(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 10)
                  throw errors::parse_error(
                     "HIERARCH", "Illegal number of entries.");

               auto pos(inp.begin());

               ++pos;

               NFIELD = _form_NFIELD(*(pos++));
               IHREF = _form_IHREF(*(pos++));
               ISELTY = _form_ISELTY(*(pos++));
               INDSEL = _form_INDSEL(*(pos++));
               ISLEVL = _form_ISLEVL(*(pos++));
               ITREF = _form_ITREF(*(pos++));
               IHPREF = _form_IHPREF(*(pos++));
               NSUB = _form_NSUB(*(pos++));
               for (int i = 0; i < NSUB; i++)
                  IHSREFi.push_back(_form_IHSREF(*(pos++)));
            }

            hierarch::hierarch(void) :
               hierarch(-1, 0, 0, 0, 0, 0, 0, {}) {}


            hierarch::hierarch(long const &NFIELD,
                               long const &IHREF,
                               long const &ISELTY,
                               long const &INDSEL,
                               long const &ISLEVL,
                               long const &ITREF,
                               long const &IHPREF,
                               long const &NSUB,
                               std::deque<long> const &IHSREF) :
               card(), NFIELD(NFIELD), IHREF(IHREF), ISELTY(ISELTY),
               INDSEL(INDSEL), ISLEVL(ISLEVL), ITREF(ITREF),
               IHPREF(IHPREF), NSUB(NSUB), IHSREFi(IHSREF) {
               if (this->IHSREFi.size() != (size_t)this->NSUB)
                  throw dnvgl::extfem::fem::errors::usage_error(
                     "HIERARCH", "IHSREF not of size NSUB");
            }

            hierarch::hierarch(const long &NFIELD,
                               const long &IHREF,
                               const long &ISELTY,
                               const long &INDSEL,
                               const long &ISLEVL,
                               const long &ITREF,
                               const long &IHPREF,
                               const std::deque<long> &IHSREF) :
               card(), NFIELD(NFIELD), IHREF(IHREF), ISELTY(ISELTY),
               INDSEL(INDSEL), ISLEVL(ISLEVL), ITREF(ITREF),
               IHPREF(IHPREF), IHSREFi(IHSREF) {
               this->NSUB = long(this->IHSREFi.size());
            }

            const dnvgl::extfem::fem::cards::types
            hierarch::card_type(void) const {
               return HIERARCH;
            }

            std::ostream&
            operator<< (std::ostream &os, const hierarch &card) {
               if (card.NFIELD == -1) return os;
               os << hierarch::head.format()
                  << card._form_NFIELD.format(card.NFIELD)
                  << card._form_IHREF.format(card.IHREF)
                  << card._form_ISELTY.format(card.ISELTY)
                  << card._form_INDSEL.format(card.INDSEL)
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_ISLEVL.format(card.ISLEVL)
                  << card._form_ITREF.format(card.ITREF)
                  << card._form_IHPREF.format(card.IHPREF)
                  << card._form_NSUB.format(card.NSUB)
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format();
               size_t num = 0;
               for (int i = 0; i<card.NSUB; i++) {
                  if (num == 4) {
                     num = 0;
                     os << std::endl
                        << dnvgl::extfem::fem::types::card().format();
                  }
                  num++;
                  os << card._form_IHSREF.format(card.IHSREFi[i]);
               }
               while (num < 4) {
                  num++;
                  os << card.empty.format();
               }
               os << std::endl;
               return os;
            }

            const std::ostream&
            hierarch::operator<< (std::ostream& os) const {
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
