/**
   \file fem/fem_cards_gelmnt2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `GELMNT2` cards.

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

            const fem::types::card gelmnt2::head("GELMNT2");

            const entry_type<long> gelmnt2::_form_SUBNO("SUBNO");
            const entry_type<long> gelmnt2::_form_SLEVEL("SLEVEL");
            const entry_type<long> gelmnt2::_form_STYPE("STYPE");
            const entry_type<long> gelmnt2::_form_ADDNO("ADDNO");
            const entry_type<double> gelmnt2::_form_T("T");
            const entry_type<long> gelmnt2::_form_NNOD("NNOD");
            const entry_type<long> gelmnt2::_form_NOD("NOD");

            gelmnt2::gelmnt2(const std::deque<std::string> &inp) :
               card(inp) {
               auto pos = inp.begin();

               ++pos;

               SUBNO = _form_SUBNO(*(pos++));
               SLEVEL = _form_SLEVEL(*(pos++));
               STYPE = _form_STYPE(*(pos++));
               ADDNO = _form_ADDNO(*(pos++));
               for (int i = 0; i<4; i++)
                  for (int j = 0; j<3; j++)
                     T[i][j] = _form_T(*(pos++));
               for (int i = 0; i<3; i++)
                  T[i][3] = 0.;
               T[3][3] = 1.;
               NNOD = _form_NNOD(*(pos++));
               for (int i = 0; i<NNOD; i++)
                  NOD.push_back(_form_NOD(*(pos++)));
            }

            gelmnt2::gelmnt2(const long &SUBNO,
                             const long &SLEVEL,
                             const long &STYPE,
                             const long &ADDNO,
                             const double T[4][4],
                             const long &NNOD,
                             const std::deque<long> &NOD) :
               card(), SUBNO(SUBNO), SLEVEL(SLEVEL), STYPE(STYPE),
               ADDNO(ADDNO), NNOD(NNOD), NOD(NOD) {
               if (this->NOD.size() != (size_t)this->NNOD)
                  throw dnvgl::extfem::fem::errors::usage_error(
                     "GELMNT2", "NOD not of size NNOD");
               for (int i=0; i<4; i++)
                  for (int j=0; j<4; j++)
                     this->T[j][i] = T[j][i];
            }

            gelmnt2::gelmnt2(const long &SUBNO,
                             const long &SLEVEL,
                             const long &STYPE,
                             const long &ADDNO,
                             const double T[4][4],
                             const std::deque<long> &NOD) :
               card(), SUBNO(SUBNO), SLEVEL(SLEVEL), STYPE(STYPE),
               ADDNO(ADDNO), NNOD(long(NOD.size())), NOD(NOD) {
               for (int i=0; i<4; i++)
                  for (int j=0; j<4; j++)
                     this->T[j][i] = T[j][i];
            }

            gelmnt2::gelmnt2(const long &SUBNO,
                             const long &SLEVEL,
                             const long &STYPE,
                             const long &ADDNO,
                             const double &T11,
                             const double &T21,
                             const double &T31,
                             const double &T12,
                             const double &T22,
                             const double &T32,
                             const double &T13,
                             const double &T23,
                             const double &T33,
                             const double &T14,
                             const double &T24,
                             const double &T34,
                             const long &NNOD,
                             const std::deque<long> &NOD) :
               card(), SUBNO(SUBNO), SLEVEL(SLEVEL), STYPE(STYPE),
               ADDNO(ADDNO), NNOD(NNOD), NOD(NOD) {
               if (this->NOD.size() != (size_t)this->NNOD)
                  throw dnvgl::extfem::fem::errors::usage_error(
                     "GELREF2","NOD not of size NNOD");
               T[0][0] = T11;
               T[1][0] = T21;
               T[2][0] = T31;
               T[3][0] = 0.;
               T[0][1] = T12;
               T[1][1] = T22;
               T[2][1] = T32;
               T[3][1] = 0.;
               T[0][2] = T13;
               T[1][2] = T23;
               T[2][2] = T33;
               T[3][2] = 0.;
               T[0][3] = T14;
               T[1][3] = T24;
               T[2][3] = T34;
               T[3][3] = 1.;
            }

            gelmnt2::gelmnt2(const long &SUBNO,
                             const long &SLEVEL,
                             const long &STYPE,
                             const long &ADDNO,
                             const double &T11,
                             const double &T21,
                             const double &T31,
                             const double &T12,
                             const double &T22,
                             const double &T32,
                             const double &T13,
                             const double &T23,
                             const double &T33,
                             const double &T14,
                             const double &T24,
                             const double &T34,
                             const std::deque<long> &NOD) :
               card(), SUBNO(SUBNO), SLEVEL(SLEVEL), STYPE(STYPE),
               ADDNO(ADDNO), NOD(NOD) {
               this->NNOD = long(this->NOD.size());
               T[0][0] = T11;
               T[1][0] = T21;
               T[2][0] = T31;
               T[3][0] = 0.;
               T[0][1] = T12;
               T[1][1] = T22;
               T[2][1] = T32;
               T[3][1] = 0.;
               T[0][2] = T13;
               T[1][2] = T23;
               T[2][2] = T33;
               T[3][2] = 0.;
               T[0][3] = T14;
               T[1][3] = T24;
               T[2][3] = T34;
               T[3][3] = 1.;
            }

            const dnvgl::extfem::fem::cards::types
            gelmnt2::card_type(void) const {
               return GELMNT2;
            }

            std::ostream&
            operator<< (std::ostream &os, const gelmnt2 &card) {
               os << gelmnt2::head.format()
                  << card._form_SUBNO.format(card.SUBNO)
                  << card._form_SLEVEL.format(card.SLEVEL)
                  << card._form_STYPE.format(card.STYPE)
                  << card._form_ADDNO.format(card.ADDNO)
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_T.format(card.T[0][0])
                  << card._form_T.format(card.T[1][0])
                  << card._form_T.format(card.T[2][0])
                  << card._form_T.format(card.T[0][1])
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_T.format(card.T[1][1])
                  << card._form_T.format(card.T[2][1])
                  << card._form_T.format(card.T[0][2])
                  << card._form_T.format(card.T[1][2])
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_T.format(card.T[2][2])
                  << card._form_T.format(card.T[0][3])
                  << card._form_T.format(card.T[1][3])
                  << card._form_T.format(card.T[2][3])
                  << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << card._form_NNOD.format(card.NNOD);
               size_t num = 1;
               for (int i = 0; i<card.NNOD; i++) {
                  if (num == 4) {
                     num = 0;
                     os << std::endl
                        << dnvgl::extfem::fem::types::card().format();
                  }
                  num++;
                  os << card._form_NOD.format(card.NOD[i]);
               }
               while (num < 4) {
                  num++;
                  os << card.empty.format();
               }
               os << std::endl;

               return os;
            }

            const std::ostream&
            gelmnt2::operator<< (std::ostream& os) const {
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
// compile-command: "make -C ../.. check"
// End:
