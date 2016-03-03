/**
   \file fem/fem_cards_text.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `TEXT` cards.

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

            const fem::types::card text::head("TEXT");

            const entry_type<long> text::_form_TYPE("TYPE");
            const entry_type<long> text::_form_SUBTYPE("SUBTYPE");
            const entry_type<long> text::_form_NRECS("NRECS");
            const entry_type<long> text::_form_NBYTE("NBYTE");
            const entry_type<std::string> text::_form_CONT("CONT");

            text::text(const std::deque<std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               TYPE = _form_TYPE(*(pos++));
               SUBTYPE = _form_SUBTYPE(*(pos++));
               NRECS = _form_NRECS(*(pos++));
               NBYTE = _form_NBYTE(*(pos++));

               for (int i = 0; i < NRECS; i++) {
                  std::string cont = _form_CONT(
                     *pos, *(pos+1), *(pos+2), *(pos+3));
                  cont.resize(NBYTE-8, ' ');
                  CONT.push_back(cont);
                  pos += 4;
               }
            }

            text::text(const long &TYPE, const long &SUBTYPE,
                       const long &NRECS, const long &NBYTE,
                       const std::deque<std::string> &CONT) :
               TYPE(TYPE), SUBTYPE(SUBTYPE), NRECS(NRECS),
               NBYTE(NBYTE), CONT(CONT) {
               for (auto &p : this->CONT)
                  p.resize(NBYTE-8, ' ');
            }

            text::text(const long &TYPE, const long &SUBTYPE,
                       const std::deque<std::string> &CONT) :
               card(),
               TYPE(TYPE), SUBTYPE(SUBTYPE), CONT(CONT) {
               NRECS = static_cast<long>(this->CONT.size());
               NBYTE = 0;
               for (auto &p : CONT)
                  NBYTE = std::max(NBYTE, (long)p.size());
               for (auto &p : this->CONT)
                  p.resize(NBYTE-8, ' ');
            }

            const dnvgl::extfem::fem::cards::types
            text::card_type(void) const { return TEXT; };

            const std::ostream&
            text::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const text &card) {

               os << text::head.format()
                  << card._form_TYPE.format(card.TYPE)
                  << card._form_SUBTYPE.format(card.SUBTYPE)
                  << card._form_NRECS.format(card.NRECS)
                  << card._form_NBYTE.format(card.NBYTE) << std::endl;
               for (auto p : card.CONT)
                  os << dnvgl::extfem::fem::types::card().format()
                     << card._form_CONT.format(p, card.NBYTE-8)
                     <<  std::endl;
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
