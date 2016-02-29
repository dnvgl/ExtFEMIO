/**
   \file fem/fem_cards_bldep.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BLDEP` cards.

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

#if defined(__AFX_H__) && defined(_DEBUG)
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

            const fem::types::card bldep::head("BLDEP");

            const entry_type<long> bldep::_form_NODENO("NODENO");
            const entry_type<long> bldep::_form_CNOD("CNOD");
            const entry_type<long> bldep::_form_NDDOF("NDDOF");
            const entry_type<long> bldep::_form_NDEP("NDEP");
            const entry_type<long> bldep::_form_DEPDOF("DEPDOF");
            const entry_type<long> bldep::_form_INDEPDOF("INDEPDOF");
            const entry_type<double> bldep::_form_b("b");

            bldep::bldep(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;

               NODENO = _form_NODENO(*(pos++));
               CNOD = _form_CNOD(*(pos++));
               NDDOF = _form_NDDOF(*(pos++));
               NDEP = _form_NDEP(*(pos++));
               if (NDDOF == 0) NDDOF = NDEP;

               for (long i = 0; i < NDEP; i++) {
                  DEPDOF.push_back(_form_DEPDOF(*(pos++)));
                  INDEPDOF.push_back(_form_INDEPDOF(*(pos++)));
                  b.push_back(_form_b(*(pos++)));
                  pos++;
               }
            }

            bldep::bldep(
               const long &NODENO,
               const long &CNOD,
               const long &NDDOF,
               const long &NDEP,
               const ::std::deque<long> &DEPDOF,
               const ::std::deque<long> &INDEPDOF,
               const ::std::deque<double> &b) :
               NODENO(NODENO), CNOD(CNOD), NDDOF(NDDOF), NDEP(NDEP),
               DEPDOF(DEPDOF),INDEPDOF(INDEPDOF), b(b) {}

            const ::dnvgl::extfem::fem::cards::types
            bldep::card_type(void) const {return BLDEP;}

            const ::std::ostream&
            bldep::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const bldep &card) {
               os << bldep::head.format()
                  << card._form_NODENO.format(card.NODENO)
                  << card._form_CNOD.format(card.CNOD)
                  << card._form_NDDOF.format(card.NDDOF)
                  << card._form_NDEP.format(card.NDEP)
                  << ::std::endl;
               for (long i = 0; i < card.NDDOF; i++)
                  os << ::dnvgl::extfem::fem::types::card().format()
                     << card._form_DEPDOF.format(card.DEPDOF[i])
                     << card._form_INDEPDOF.format(card.INDEPDOF[i])
                     << card._form_b.format(card.b[i])
                     << card.empty.format()
                     << ::std::endl;
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
