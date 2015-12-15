/**
   \file fem/fem_cards_bndispl.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BNDISPL` cards.

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

            const fem::types::card bndispl::head("BNDISPL");

            const entry_type<long> bndispl::_form_LLC("LLC");
            const entry_type<long> bndispl::_form_DTYPE("DTYPE");
            const entry_type<bool> bndispl::_form_COMPLX("COMPLX");
            const entry_type<long> bndispl::_form_NODENO("NODENO");
            const entry_type<long> bndispl::_form_NDOF("NDOF");
            const entry_type<double> bndispl::_form_RDISP("RDISP");
            const entry_type<double> bndispl::_form_IDISP("IDISP");

            bndispl::bndispl(const ::std::deque<::std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;

               LLC = _form_LLC(*(pos++));
               DTYPE = _form_DTYPE (*(pos++));
               COMPLX = _form_COMPLX(*(pos++));
               ++pos;
               NODENO = _form_NODENO(*(pos++));
               NDOF = _form_NDOF(*(pos++));
               for (long i = 0; i < NDOF; i++)
                  RDISP.push_back(_form_RDISP(*(pos++)));

               if (COMPLX)
                  IDISP.push_back(_form_IDISP(*(pos++)));
            }

            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const bool &COMPLX,
                             const long &NODENO,
                             const long &NDOF,
                             const ::std::deque<double> &RDISP,
                             const ::std::deque<double> &IDISP) :
               card(), LLC(LLC), DTYPE(DTYPE), COMPLX(COMPLX),
               NODENO(NODENO), NDOF(NDOF),
               RDISP(RDISP), IDISP(IDISP) {}


            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const bool &COMPLX,
                             const long &NODENO,
                             const ::std::deque<double> &RDISP,
                             const ::std::deque<double> &IDISP):
               card(), LLC(LLC), DTYPE(DTYPE), COMPLX(COMPLX),
               NODENO(NODENO), NDOF((long)RDISP.size()),
               RDISP(RDISP), IDISP(IDISP) {}

            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const long &NODENO,
                             const long &NDOF,
                             const ::std::deque<double> &RDISP,
                             const ::std::deque<double> &IDISP) :
               card(), LLC(LLC), DTYPE(DTYPE),
               COMPLX(IDISP.size() > 0),
               NODENO(NODENO), NDOF(NDOF),
               RDISP(RDISP), IDISP(IDISP) {}


            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const long &NODENO,
                             const ::std::deque<double> &RDISP,
                             const ::std::deque<double> &IDISP) :
               card(), LLC(LLC), DTYPE(DTYPE),
               COMPLX(IDISP.size() > 0),
               NODENO(NODENO), NDOF((long)RDISP.size()),
               RDISP(RDISP), IDISP(IDISP) {}

            const ::dnvgl::extfem::fem::cards::types
            bndispl::card_type(void) const {return BNDISPL;}

            const ::std::ostream&
            bndispl::operator<< (::std::ostream& os) const {
               os << this;
               return os;
            }

            ::std::ostream&
            operator<< (::std::ostream &os, const bndispl &card) {
               os << bndispl::head.format()
                  << card._form_LLC.format(card.LLC)
                  << card._form_DTYPE.format(card.DTYPE)
                  << card._form_COMPLX.format(card.COMPLX)
                  << card.empty.format() << ::std::endl
                  << ::dnvgl::extfem::fem::types::card().format()
                  << card._form_NODENO.format(card.NODENO)
                  << card._form_NDOF.format(card.NDOF);
               long cnt = 2;
               for (long i = 0; i < card.NDOF; i++) {
                  if (cnt == 4) {
                     os << ::std::endl << ::dnvgl::extfem::fem::types::card().format();
                     cnt = 0;
                  }
                  os << card._form_RDISP.format(card.RDISP[i]);
                  cnt += 1;
               }
               if (card.COMPLX)
                  for (long i = 0; i < card.NDOF; i++) {
                     if (cnt == 4) {
                        os << ::std::endl << ::dnvgl::extfem::fem::types::card().format();
                        cnt = 0;
                     }
                     os << card._form_IDISP.format(card.IDISP[i]);
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
