/**
   \file fem/fem_cards_mgsprng.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `MGSPRNG` cards.

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

            const fem::types::card mgsprng::head("MGSPRNG");

            const entry_type<long> mgsprng::_form_MATNO("MATNO");
            const entry_type<long> mgsprng::_form_NDOF("NDOF");
            const entry_type<double> mgsprng::_form_K("K");

            mgsprng::mgsprng(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;

               MATNO = _form_MATNO(*(pos++));
               NDOF = _form_NDOF (*(pos++));
               K.resize(NDOF);
               for (long i = 0; i < NDOF; i++) {
                  K[i] = ::std::deque<double>(NDOF);
                  if (i > 0) {
                     for (long j = 0; j < i; j++)
                        K[i][j] = K[j][i];
                  }
                  for (long j = i; j < NDOF; j++)
                     K[i][j] = _form_K(*(pos++));
               }
            }

            mgsprng::mgsprng(const long &MATNO,
                             const long &NDOF,
                             const ::std::deque<::std::deque<double>> &K) :
               card(), MATNO(MATNO), NDOF(NDOF), K(K) {}

            mgsprng::mgsprng(const long &MATNO,
                             const ::std::deque<::std::deque<double>> &K) :
               card(), MATNO(MATNO), NDOF((long)K.size()), K(K) {}

            const ::dnvgl::extfem::fem::cards::types
            mgsprng::card_type(void) const {return MGSPRNG;}

            const ::std::ostream&
            mgsprng::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const mgsprng &card) {
               os << mgsprng::head.format()
                  << card._form_MATNO.format(card.MATNO)
                  << card._form_NDOF.format(card.NDOF);
               long cnt = 2;
               for (long i = 0; i < card.NDOF; i++) {
                  for (long j = i; j < card.NDOF; j++) {
                     if (cnt == 4) {
                        os << ::std::endl << ::dnvgl::extfem::fem::types::card().format();
                        cnt = 0;
                     }
                     os << card._form_K.format(card.K[i][j]);
                     cnt += 1;
                  }
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
