/**
   \file fem/fem_cards_gelmnt1.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GELMNT1` cards.

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

            const fem::types::card gelmnt1::head("GELMNT1");

            const entry_type<long> gelmnt1::_form_ELNOX("ELNOX");
            const entry_type<long> gelmnt1::_form_ELNO("ELNO");
            const entry_type<long> gelmnt1::_form_ELTYP("ELTYP");
            const entry_type<long> gelmnt1::_form_ELTYAD("ELTYAD");
            const entry_type<long> gelmnt1::_form_NODIN("NODIN");

            gelmnt1::gelmnt1(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               long tmp;

               ++pos;
               ELNOX = _form_ELNOX(*(pos++));
               ELNO = _form_ELNO(*(pos++));
               ELTYP = _form_ELTYP(*(pos++));
               ELTYAD = _form_ELTYAD(*(pos++));
               while (pos != inp.end()) {
                  tmp = _form_NODIN(*(pos++));
                  if (tmp == 0) break;
                  NODIN.push_back(tmp);
               }
            }

            gelmnt1::gelmnt1(
               const long &ELNOX, const long &ELNO,
               const long &ELTYP, const long &ELTYAD,
               const ::std::deque<long> &NODIN) :
               card(),
               ELNOX(ELNOX), ELNO(ELNO), ELTYP(ELTYP), ELTYAD(ELTYAD),
               NODIN(NODIN) {}

            const ::dnvgl::extfem::fem::cards::types
            gelmnt1::card_type(void) const { return GELMNT1; }

            ::std::ostream&
            operator<< (::std::ostream &os, const gelmnt1 &card) {

               os << gelmnt1::head.format()
                  << card._form_ELNOX.format(card.ELNOX)
                  << card._form_ELNO.format(card.ELNO)
                  << card._form_ELTYP.format(card.ELTYP)
                  << card._form_ELTYAD.format(card.ELTYAD);
               size_t i = 5;
               for (auto p : card.NODIN) {
                  if (i++ >= 4) {
                     i = 1;
                     os << std::endl << ::dnvgl::extfem::fem::types::card().format();
                  }
                  os << card._form_NODIN.format(p);
               }
               while (i++ < 4)
                  os << card.empty.format();
               os << std::endl;
               return os;
            }

            const ::std::ostream&
            gelmnt1::operator<< (::std::ostream& os) const {
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
