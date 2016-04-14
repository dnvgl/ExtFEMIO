/**
   \file fem/fem_cards_bsell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BSELL` cards.

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

            const fem::types::card bsell::head("BSELL");

            const entry_type<long> bsell::_form_LC("LC");
            const entry_type<long> bsell::_form_SUBNO("SUBNO");
            const entry_type<long> bsell::_form_LLC("LLC");
            const entry_type<double> bsell::_form_FACT("FACT");

            bsell::bsell(const std::deque<std::string> &inp) :
               card(inp) {

               long tmp;

               if (inp.size() < 7)
                  throw errors::parse_error(
                     "BSELL", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               LC = _form_LC(*(pos++));
               SUBNO = _form_SUBNO(*(pos++));

               pos++;
               pos++;
               while (pos != inp.end()) {
                  tmp = _form_LLC(*(pos++));
                  if (tmp == 0) break;
                  LLC.push_back(tmp);
                  FACT.push_back(_form_FACT(*(pos++)));
               }
            }

            bsell::bsell(void) :
               bsell(-1, 0, {}, {}) {}

            bsell::bsell(const long &LC,
                         const long &SUBNO,
                         const std::deque<long> &LLC,
                         const std::deque<double> &FACT) :
               card(), LC(LC), SUBNO(SUBNO), LLC(LLC), FACT(FACT) {}

            const dnvgl::extfem::fem::cards::types
            bsell::card_type(void) const {
               return BSELL;
            }

            std::ostream&
            operator<< (std::ostream &os, const bsell &card) {
               if (card.LC == -1) return os;
               os << bsell::head.format()
                  << card._form_LC.format(card.LC)
                  << card._form_SUBNO.format(card.SUBNO)
                  << card.empty.format()
                  << card.empty.format()
                  << std::endl;
               for (size_t i = 0; i < card.LLC.size(); i+=2) {
                  os << dnvgl::extfem::fem::types::card().format()
                     << card._form_LLC.format(card.LLC[i])
                     << card._form_FACT.format(card.FACT[i]);
                  if (i+1 < card.LLC.size())
                     os << card._form_LLC.format(card.LLC[i+1])
                        << card._form_FACT.format(card.FACT[i+1]);
                  else
                     os << card.empty.format()
                        << card.empty.format();
                     os << std::endl;
               }
               return os;
            }

            const std::ostream&
            bsell::operator<< (std::ostream& os) const {
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
// compile-command: "make -C ../.. check"
// End:
