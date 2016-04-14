/**
   \file fem/fem_cards_date.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `DATE` cards.

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

            const fem::types::card date::head("DATE");

            const entry_type<long> date::_form_TYPE("TYPE");
            const entry_type<long> date::_form_SUBTYPE("SUBTYPE");
            const entry_type<long> date::_form_NRECS("NRECS");
            const entry_type<long> date::_form_NBYTE("NBYTE");
            const entry_type<std::string> date::_form_CONT("CONT");

            date::date(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 8)
                  throw errors::parse_error(
                     "DATE", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               TYPE = _form_TYPE(*(pos++));
               SUBTYPE = _form_SUBTYPE(*(pos++));
               NRECS = _form_NRECS(*(pos++));
               NBYTE = _form_NBYTE(*(pos++));

               for (int i = 0; i < NRECS; i++) {
                  std::string cont = _form_CONT(
                     *pos, *(pos+1), *(pos+2), *(pos+3));
                  cont.resize(NBYTE, ' ');
                  CONT.push_back(cont);
                  pos += 4;
               }
            }

            date::date() :
               date(-1, 0, 0, 0, {}) {}

            date::date(const long &TYPE, const long &SUBTYPE,
                       const long &NRECS, const long &NBYTE,
                       const std::deque<std::string> &CONT) :
               TYPE(TYPE), SUBTYPE(SUBTYPE), NRECS(NRECS),
               NBYTE(NBYTE), CONT(CONT) {
               for (auto &p : this->CONT)
                  p.resize(NBYTE-8, ' ');
            }

            date::date(const long &TYPE, const long &SUBTYPE,
                       const std::deque<std::string> &CONT) :
               card(),
               TYPE(TYPE), SUBTYPE(SUBTYPE), CONT(CONT) {
               NRECS = static_cast<long>(this->CONT.size());
               NBYTE = 0;
               for (auto &p : this->CONT)
                  NBYTE = std::max(NBYTE, (long)p.size());
               for (auto &p : this->CONT)
                  p.resize(NBYTE, ' ');
               NBYTE += 8;
            }

            const types
            date::card_type(void) const { return DATE; };

            const std::ostream&
            date::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const date &card) {
               if (card.TYPE == -1) return os;
               os << date::head.format()
                  << card._form_TYPE.format(card.TYPE)
                  << card._form_SUBTYPE.format(card.SUBTYPE)
                  << card._form_NRECS.format(card.NRECS)
                  << card._form_NBYTE.format(card.NBYTE) << std::endl;
               for (auto p : card.CONT)
                  os << dnvgl::extfem::fem::types::card().format()
                     << card._form_CONT.format(p, card.NBYTE)
                     << std::endl;
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
