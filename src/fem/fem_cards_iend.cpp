/**
   \file fem/fem_cards_iend.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `IEND` cards.

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

            const fem::types::card iend::head("IEND");

            const entry_type<long> iend::_form_CONT("SLEVEL");

            iend::iend(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               CONT = _form_CONT(*(pos));
            }

            iend::iend(const long &CONT) : CONT(CONT) {}

            const types
            iend::card_type(void) const { return IEND; };

            const ::std::ostream&
            iend::operator<<(::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<<(::std::ostream &os, const iend &card) {

               os << iend::head.format()
                  << card._form_CONT.format(card.CONT)
                  << iend::empty.format()
                  << iend::empty.format()
                  << iend::empty.format() << ::std::endl;

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
