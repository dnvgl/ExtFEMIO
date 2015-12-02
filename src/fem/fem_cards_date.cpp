/**
   \file fem/fem_cards_date.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM DATE cards.

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

#ifdef _TYPE
#undef _TYPE
#endif

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card date::head("DATE");

            const entry_type<long> date::_TYPE("TYPE");
            const entry_type<long> date::_SUBTYPE("SUBTYPE");
            const entry_type<long> date::_NRECS("NRECS");
            const entry_type<long> date::_NBYTE("NBYTE");
            const entry_type<::std::string> date::_CONT("CONT");

            date::date(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               TYPE = _TYPE(*(pos++));
               SUBTYPE = _SUBTYPE(*(pos++));
               NRECS = _NRECS(*(pos++));
               NBYTE = _NBYTE(*(pos++));

               while (pos != inp.end()) {
                  ::std::string res("");
                  for (int i=0; i < 4 && pos != inp.end(); i++)
                     res += *(pos++);
                  CONT.push_back(res);
               }
            }

            date::date(
               const long &TYPE, const long &SUBTYPE,
               const long &NRECS, const long &NBYTE,
               const ::std::deque<::std::string> &CONT) :
               TYPE(TYPE), SUBTYPE(SUBTYPE), NRECS(NRECS),
               NBYTE(NBYTE), CONT(CONT) {}

            date::date(
               const long &TYPE, const long &SUBTYPE,
               const ::std::deque<::std::string> &CONT) :
               TYPE(TYPE), SUBTYPE(SUBTYPE), CONT(CONT) {
               NRECS = static_cast<long>(CONT.size());
               NBYTE = 0;
               for (auto &p : CONT)
                  NBYTE = (NBYTE < (long)p.size()) ? (long)p.size() : NBYTE;
            };

            const types
            date::card_type(void) const { return DATE; };

            const ::std::ostream&
            date::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const date &card) {

               os << date::head.format()
                  << card._TYPE.format(card.TYPE)
                  << card._SUBTYPE.format(card.SUBTYPE)
                  << card._NRECS.format(card.NRECS)
                  << card._NBYTE.format(card.NBYTE) << std::endl;

               for (auto p : card.CONT)
                  os << ::dnvgl::extfem::fem::types::card().format()
                     << card._CONT.format(p, card.NBYTE)
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
