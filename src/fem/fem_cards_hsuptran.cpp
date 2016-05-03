/**
   \file fem/fem_cards_hsuptran.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `HSUPTRAN` cards.

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

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace cards {

            const fem::types::card hsuptran::head("HSUPTRAN");

            const entry_type<long> hsuptran::_form_NFIELD("NFIELD");
            const entry_type<long> hsuptran::_form_ITREF("ITREF");
            const entry_type<double> hsuptran::_form_T("T");

            hsuptran::hsuptran(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 15)
                  throw errors::parse_error(
                     "HSUPTRAN", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               NFIELD = _form_NFIELD(*(pos++));
               ITREF = _form_ITREF(*(pos++));
               T[0][0] = _form_T(*(pos++));
               T[0][1] = _form_T(*(pos++));
               T[0][2] = _form_T(*(pos++));
               T[0][3] = _form_T(*(pos++));
               T[1][0] = _form_T(*(pos++));
               T[1][1] = _form_T(*(pos++));
               T[1][2] = _form_T(*(pos++));
               T[1][3] = _form_T(*(pos++));
               T[2][0] = _form_T(*(pos++));
               T[2][1] = _form_T(*(pos++));
               T[2][2] = _form_T(*(pos++));
               T[2][3] = _form_T(*(pos++));
               T[3][0] = _form_T(*(pos++));
               T[3][1] = _form_T(*(pos++));
               T[3][2] = _form_T(*(pos++));
               T[3][3] = _form_T(*(pos++));
            }

            hsuptran::hsuptran(void) :
               hsuptran(-1, 0, NULL) {}


            hsuptran::hsuptran(const long &NFIELD,
                               const long &ITREF,
                               const double &T11,
                               const double &T21,
                               const double &T31,
                               const double &T41,
                               const double &T12,
                               const double &T22,
                               const double &T32,
                               const double &T42,
                               const double &T13,
                               const double &T23,
                               const double &T33,
                               const double &T43,
                               const double &T14,
                               const double &T24,
                               const double &T34,
                               const double &T44) :
               card(), NFIELD(NFIELD), ITREF(ITREF) {

               T[0][0] = T11;
               T[0][1] = T21;
               T[0][2] = T31;
               T[0][3] = T41;
               T[1][0] = T12;
               T[1][1] = T22;
               T[1][2] = T32;
               T[1][3] = T42;
               T[2][0] = T13;
               T[2][1] = T23;
               T[2][2] = T33;
               T[2][3] = T43;
               T[3][0] = T14;
               T[3][1] = T24;
               T[3][2] = T34;
               T[3][3] = T44;
            }

            hsuptran::hsuptran(const long &NFIELD,
                               const long &ITREF,
                               const double T[4][4]) :
               card(), NFIELD(NFIELD), ITREF(ITREF) {
               if (this->NFIELD != -1)
                  for (int i=0; i<4; i++)
                     for (int j=0; j<4; j++)
                        this->T[i][j] = T[i][j];
            }

            const dnvgl::extfem::fem::cards::types
            hsuptran::card_type(void) const {
               return HSUPTRAN;
            }

            std::ostream&
            operator<< (std::ostream &os, const hsuptran &card) {
               if (card.NFIELD == -1) return os;
               os << hsuptran::head.format()
                  << card._form_NFIELD.format(card.NFIELD)
                  << card._form_ITREF.format(card.ITREF)
                  << card._form_T.format(card.T[0][0])
                  << card._form_T.format(card.T[0][1]) << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_T.format(card.T[0][2])
                  << card._form_T.format(card.T[0][3])
                  << card._form_T.format(card.T[1][0])
                  << card._form_T.format(card.T[1][1]) << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_T.format(card.T[1][2])
                  << card._form_T.format(card.T[1][3])
                  << card._form_T.format(card.T[2][0])
                  << card._form_T.format(card.T[2][1]) << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_T.format(card.T[2][2])
                  << card._form_T.format(card.T[2][3])
                  << card._form_T.format(card.T[3][0])
                  << card._form_T.format(card.T[3][1]) << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_T.format(card.T[3][2])
                  << card._form_T.format(card.T[3][3])
                  << std::endl;
               return os;
            }

            const std::ostream&
            hsuptran::operator<< (std::ostream& os) const {
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
// compile-command: "make -C ../../ check -j8"
// End:
