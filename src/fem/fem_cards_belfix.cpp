/**
   \file fem/fem_cards_belfix.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BELFIX` cards.

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
#include "fem/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

namespace {
   long m_one(-1), one(1), two(2);
}

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card belfix::head("BELFIX");

            const fem::types::entry_type<long> belfix::_form_FIXNO("FIXNO");
            const fem::types::entry_type<long> belfix::_form_OPT(
               "OPT", type_bounds::bound<long>(&one, &two));
            const fem::types::entry_type<long> belfix::_form_TRANO(
               "TRANO", type_bounds::bound<long>(&m_one));
            const fem::types::entry_type<double> belfix::_form_A("A");

            belfix::belfix() :
               belfix(-1, belfix::INVALID, 0,
                      {0., 0., 0., 0., 0., 0.}) {}

            belfix::belfix(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 11)
                  throw errors::parse_error(
                     "BELFIX", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               FIXNO = _form_FIXNO(*(pos++));
               long tmp(_form_OPT(*(pos++)));
               if (tmp == 1)
                  OPT = FIXATION;
               else if (tmp == 2)
                  OPT = SPRING;
               else {
                  OPT = INVALID;
                  std::ostringstream msg(
                     "BELFIX: OPT allows only 1 or 2, got ",
                     std::ostringstream::ate);
                  msg << tmp << ".";
                  error_report(msg.str());
               }
               TRANO = _form_TRANO(*(pos++));
               pos++;
               for (int i=0; i<6; i++)
                  A.push_back(_form_A(*(pos++)));
            }

            belfix::belfix(long const &FIXNO,
                           n_opt const &OPT,
                           long const &TRANO,
                           std::deque<double> const &A) :
               card(), FIXNO(FIXNO), OPT(OPT), TRANO(TRANO), A(A) {}

            const std::ostream&
            belfix::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            const dnvgl::extfem::fem::cards::types
            belfix::card_type(void) const {return BELFIX;}

            std::ostream&
            operator<< (std::ostream &os, const belfix &card) {
               if (card.OPT == belfix::INVALID) return os;
               os << belfix::head.format()
                  << card._form_FIXNO.format(card.FIXNO)
                  << card._form_OPT.format(card.OPT)
                  << card._form_TRANO.format(card.TRANO)
                  << card.empty.format()
                  << std::endl << fem::types::card("").format()
                  << card._form_A.format(card.A[0])
                  << card._form_A.format(card.A[1])
                  << card._form_A.format(card.A[2])
                  << card._form_A.format(card.A[3])
                  << std::endl << fem::types::card("").format()
                  << card._form_A.format(card.A[4])
                  << card._form_A.format(card.A[5])
                  << std::endl;
               return os;
            }

            std::string belfix::pos_string(void) const {
               std::ostringstream res;
               if (OPT != FIXATION)
                  throw errors::types_error(
                  "Only BELFIX records with OPT==1 can be transformed to Poseidon BEAM DOFs.");
               for (double a : A) {
                  if (a != 0. && a != 1.)
                     throw errors::types_error(
                     "Only BELFIX fixation values of 0. and 1. can be transformed to Poseidon BEAM DOFs.");
                  res << static_cast<int>(a);
               }
               return res.str();
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
