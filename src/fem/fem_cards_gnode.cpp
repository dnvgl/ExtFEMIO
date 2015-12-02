/**
   \file fem/fem_cards_gnode.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GNODE` cards.

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

using namespace ::dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card gnode::head("GNODE");

            const entry_type<long> gnode::_NODEX("NODEX");
            const entry_type<long> gnode::_NODENO("NODENO");
            const entry_type<long> gnode::_NDOF("NDOF");
            const entry_type<::std::deque<int>> gnode::_ODOF("ODOF");

            gnode::gnode(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               NODEX = _NODEX(*(pos++));
               NODENO = _NODENO(*(pos++));
               NDOF = _NDOF(*(pos++));
               ODOF = ::std::deque<int>(*_ODOF(*(pos++)));
            }

            gnode::gnode(
               const long &NODEX, const long &NODENO,
               const long &NDOF, const ::std::deque<int> &ODOF) :
               NODEX(NODEX), NODENO(NODENO), NDOF(NDOF),
               ODOF(ODOF.begin(), ODOF.end()) {
               ::std::sort(this->ODOF.begin(), this->ODOF.end());
            };

            gnode::gnode(
               const long &NODEX, const long &NODENO,
               const ::std::deque<int> &ODOF) :
               NODEX(NODEX), NODENO(NODENO),
               ODOF(ODOF.begin(), ODOF.end()) {
               NDOF = static_cast<long>(this->ODOF.size());
               ::std::sort(this->ODOF.begin(), this->ODOF.end());
            };

            const ::std::ostream&
            gnode::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            const ::dnvgl::extfem::fem::cards::types
            gnode::card_type(void) const {return GNODE;}

            ::std::ostream&
            operator<< (::std::ostream &os, const gnode &card) {
               os << gnode::head.format()
                  << card._NODEX.format(card.NODEX)
                  << card._NODENO.format(card.NODENO)
                  << card._NDOF.format(card.NDOF)
                  << card._ODOF.format(card.ODOF) << std::endl;

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
