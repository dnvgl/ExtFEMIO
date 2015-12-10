/**
   \file fem/fem_cards_gsetmemb.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GSETMEMB` cards.

   Detailed description
*/

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

            const fem::types::card gsetmemb::head("GSETMEMB");

            const entry_type<long> gsetmemb::_form_NFIELD("NFIELD");
            const entry_type<long> gsetmemb::_form_ISREF("ISREF");
            const entry_type<long> gsetmemb::_form_INDEX("INDEX");
            const entry_type<long> gsetmemb::_form_ISTYPE("ISTYPE");
            const entry_type<long> gsetmemb::_form_ISORIG("ISORIG");
            const entry_type<long> gsetmemb::_form_IRMEMB("IRMEMB");

            gsetmemb::gsetmemb(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;

               NFIELD = _form_NFIELD(*(pos++));
               ISREF = _form_ISREF(*(pos++));
               INDEX = _form_INDEX(*(pos++));
               ISTYPE = _form_ISTYPE(*(pos++));
               ISORIG = _form_ISORIG(*(pos++));
               IRMEMB.resize(NFIELD - 5);
               for (long i = 0; i < NFIELD - 5; i++)
                  IRMEMB[i] = _form_IRMEMB(*(pos++));
            }

            gsetmemb::gsetmemb(const long &NFIELD,
                               const long &ISREF,
                               const long &INDEX,
                               const long &ISTYPE,
                               const long &ISORIG,
                               const ::std::deque<long> &IRMEMB) :
               card(), NFIELD(NFIELD), ISREF(ISREF), INDEX(INDEX),
               ISTYPE(ISTYPE), ISORIG(ISORIG), IRMEMB(IRMEMB) {}

            gsetmemb::gsetmemb(const long &NFIELD,
                               const long &ISREF,
                               const long &INDEX,
                               const long &ISTYPE,
                               const long &ISORIG) :
               card(), NFIELD(NFIELD), ISREF(ISREF), INDEX(INDEX),
               ISTYPE(ISTYPE), ISORIG(ISORIG), IRMEMB(::std::deque<long>()) {}

            gsetmemb::gsetmemb(const long &ISREF,
                               const long &INDEX,
                               const long &ISTYPE,
                               const long &ISORIG,
                               const ::std::deque<long> &IRMEMB) :
               card(), NFIELD(IRMEMB.size() + 5), ISREF(ISREF), INDEX(INDEX),
               ISTYPE(ISTYPE), ISORIG(ISORIG), IRMEMB(IRMEMB) {}

            gsetmemb::gsetmemb(const long &ISREF,
                               const long &INDEX,
                               const long &ISTYPE,
                               const long &ISORIG) :
               card(), NFIELD(5), ISREF(ISREF), INDEX(INDEX),
               ISTYPE(ISTYPE), ISORIG(ISORIG), IRMEMB(::std::deque<long>()) {}

            const ::dnvgl::extfem::fem::cards::types
            gsetmemb::card_type(void) const {return GSETMEMB;}

            const ::std::ostream&
            gsetmemb::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const gsetmemb &card) {
               os << gsetmemb::head.format()
                  << card._form_NFIELD.format(card.NFIELD)
                  << card._form_ISREF.format(card.ISREF)
                  << card._form_INDEX.format(card.INDEX)
                  << card._form_ISTYPE.format(card.ISTYPE)
                  << ::std::endl << ::dnvgl::extfem::fem::types::card().format()
                  << card._form_ISORIG.format(card.ISORIG);
               long cnt = 1;
               for (long i = 0; i < card.NFIELD - 5; i++) {
                  if (cnt == 4) {
                     os << ::std::endl << ::dnvgl::extfem::fem::types::card().format();
                     cnt = 0;
                  }
                  os << card._form_IRMEMB.format(card.IRMEMB[i]);
                  cnt += 1;
               }
               for (long i=cnt; i < 4; i++)
                  os << card.empty.format();
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
