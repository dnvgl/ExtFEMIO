/**
   \file fem/fem_cards_bnbcd.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BNBCD` cards.

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

            const fem::types::card bnbcd::head("BNBCD");

            const entry_type<long> bnbcd::_form_NODENO("NODENO");
            const entry_type<long> bnbcd::_form_NDOF("NDOF");
            const entry_type<long> bnbcd::_form_FIX("FIX");

            bnbcd::bnbcd(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;

               NODENO = _form_NODENO(*(pos++));
               NDOF = _form_NDOF(*(pos++));

               for (long i = 0; i < NDOF; i++)
                  FIX.push_back(_form_FIX(*(pos++)));
            }

            bnbcd::bnbcd(
               const long &NODENO,
               const long &NDOF,
               const ::std::deque<long> &FIX) :
               card(), NODENO(NODENO), NDOF(NDOF), FIX(FIX) {}

            bnbcd::bnbcd(
               const long &NODENO,
               const ::std::deque<long> &FIX) :
               card(), NODENO(NODENO), NDOF(FIX.size()), FIX(FIX) {}

            const ::dnvgl::extfem::fem::cards::types
            bnbcd::card_type(void) const {return BNBCD;}

            const ::std::ostream&
            bnbcd::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const bnbcd &card) {
               os << bnbcd::head.format()
                  << card._form_NODENO.format(card.NODENO)
                  << card._form_NDOF.format(card.NDOF);
               long cnt = 2;
               for (long i = 0; i < card.NDOF; i++) {
                  if (cnt == 4) {
                     os << ::std::endl << ::dnvgl::extfem::fem::types::card().format();
                     cnt = 0;
                  }
                  os << card._form_FIX.format(card.FIX[i]);
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
