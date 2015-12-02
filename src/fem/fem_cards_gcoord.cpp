/**
   \file fem/fem_cards_gcoord.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM GCOORD cards.

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

            const fem::types::card gcoord::head("GCOORD");

            const entry_type<long> gcoord::_NODENO("NODENO");
            const entry_type<double> gcoord::_XCOORD("XCOORD");
            const entry_type<double> gcoord::_YCOORD("YCOORD");
            const entry_type<double> gcoord::_ZCOORD("ZCOORD");

            gcoord::gcoord(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               NODENO = _NODENO(*(pos++));
               XCOORD = _XCOORD(*(pos++));
               YCOORD = _YCOORD(*(pos++));
               ZCOORD = _ZCOORD(*(pos++));
            }

            gcoord::gcoord(
               const long &NODENO,
               const double &XCOORD, const double &YCOORD, const double &ZCOORD) :
               NODENO(NODENO),
               XCOORD(XCOORD), YCOORD(YCOORD), ZCOORD(ZCOORD) {}

            const ::std::ostream&
            gcoord::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            const ::dnvgl::extfem::fem::cards::types
            gcoord::card_type(void) const {return GCOORD;}

            ::std::ostream&
            operator<< (::std::ostream &os, const gcoord &card) {
               os << gcoord::head.format()
                  << card._NODENO.format(card.NODENO)
                  << card._XCOORD.format(card.XCOORD)
                  << card._YCOORD.format(card.YCOORD)
                  << card._ZCOORD.format(card.ZCOORD) << std::endl;

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
