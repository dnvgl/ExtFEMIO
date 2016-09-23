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
   const char cID_fem_cards_text[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef max
#undef max
#endif // max

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

            text::text(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 9)
                  throw errors::parse_error(
                     "TEXT", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               TYPE = _form_TYPE(*(pos++));
               SUBTYPE = _form_SUBTYPE(*(pos++));
               NRECS = _form_NRECS(*(pos++));
               NBYTE = _form_NBYTE(*(pos++));

               for (int i = 0; i < NRECS; i++) {
                  auto pos_0 = *pos++;
                  auto pos_1 = *pos++;
                  auto pos_2 = *pos++;
                  auto pos_3 = *pos++;
                  std::string cont = _form_CONT(
                     pos_0, pos_1, pos_2, pos_3);
                  cont.resize(NBYTE, ' ');
                  CONT.push_back(cont);
               }
            }

            text::text(void) :
               text(-1, 0, 0, 0, {}) {}

            text::text(const long &TYPE, const long &SUBTYPE,
                       const long &NRECS, const long &NBYTE,
                       const std::vector<std::string> &CONT) :
               TYPE(TYPE), SUBTYPE(SUBTYPE), NRECS(NRECS),
               NBYTE(NBYTE), CONT(CONT) {
               for (auto &p : this->CONT)
                  p.resize(NBYTE-8, ' ');
            }

            text::text(const long &TYPE, const long &SUBTYPE,
                       const std::vector<std::string> &CONT) :
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
            text::card_type(void) const { return types::TEXT; };

            std::ostream &text::put(std::ostream& os) const {
               if (this->TYPE == -1) return os;
               os << text::head.format()
                  << this->_form_TYPE.format(this->TYPE)
                  << this->_form_SUBTYPE.format(this->SUBTYPE)
                  << this->_form_NRECS.format(this->NRECS)
                  << this->_form_NBYTE.format(this->NBYTE) << std::endl;
               for (auto p : this->CONT)
                  os << dnvgl::extfem::fem::types::card().format()
                     << this->_form_CONT.format(p, this->NBYTE)
                     << std::endl;
               return os;
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
