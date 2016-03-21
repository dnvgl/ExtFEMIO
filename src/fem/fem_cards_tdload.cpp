/**
   \file fem/fem_cards_tdload.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `TDLOAD` cards.

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
#include "extfem_misc.h"

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

            const fem::types::card tdload::head("TDLOAD");

            const entry_type<long> tdload::_form_NFIELD("NFIELD");
            const entry_type<long> tdload::_form_ILREF("ILREF");
            const entry_type<long> tdload::_form_CODNAM("CODNAM");
            const entry_type<long> tdload::_form_CODTXT("CODTXT");
            const entry_type<std::string> tdload::_form_SET_NAME("SET_NAME");
            const entry_type<std::string> tdload::_form_CONT("CONT");

            tdload::tdload(const std::deque<std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               NFIELD = _form_NFIELD(*(pos++));
               if (NFIELD != 4) {
                  std::ostringstream msg(
                     "Only NFIELD values of 4 are supported, "
                     "but got value of ",
                     std::ostringstream::ate);
                  msg << NFIELD;
                  errors::parse_error("TDLOAD", msg.str());
               }
               ILREF = _form_ILREF(*(pos++));
               CODNAM = _form_CODNAM(*(pos++));
               CODTXT = _form_CODTXT(*(pos++));

               auto div_val = ldiv(CODNAM, 100);
               nlnam = div_val.quot != 0;
               ncnam = div_val.rem;
               div_val = ldiv(CODTXT, 100);
               nltxt = div_val.quot;
               nctxt = div_val.rem;

               if (nlnam) {
                  SET_NAME = _form_SET_NAME(
                     *pos, *(pos+1), *(pos+2), *(pos+3));
                  SET_NAME.resize(ncnam, ' ');
               }
               pos += 4;
               for (long i=0; i < nltxt; i++) {
                  std::string cont = _form_CONT(
                     *pos, *(pos+1), *(pos+2), *(pos+3));
                  pos += 4;
                  cont.resize(nctxt, ' ');
                  CONT.push_back(cont);
               }
            }

            tdload::tdload(const long &NFIELD,
                               const long &ILREF,
                               const long &CODNAM,
                               const long &CODTXT,
                               const std::string &SET_NAME,
                               const std::deque<std::string> &CONT) :
               card(), NFIELD(NFIELD), ILREF(ILREF),
               CODNAM(CODNAM), CODTXT(CODTXT),
               SET_NAME(SET_NAME), CONT(CONT) {
               auto div_val = ldiv(CODNAM, 100);
               nlnam = div_val.quot != 0;
               ncnam = div_val.rem;
               div_val = ldiv(CODTXT, 100);
               nltxt = div_val.quot;
               nctxt = div_val.rem;
            }

            tdload::tdload(const long &ILREF,
                               const std::string &SET_NAME,
                               const std::deque<std::string> &CONT) :
               card(), NFIELD(4), ILREF(ILREF),
               SET_NAME(SET_NAME), CONT(CONT) {

               nlnam = true;
               ncnam = (long)SET_NAME.size();
               CODNAM = 100 + ncnam;
               nltxt = (long)CONT.size();
               nctxt = 0;
               for (auto &p : CONT)
                  nctxt = std::max(nctxt, (long)p.size());
               for (auto &p : this->CONT)
                  p.resize(nctxt, ' ');
               CODTXT = (100 * nltxt) + nctxt;
            }

            tdload::tdload(const long &NFIELD,
                               const long &ILREF,
                               const long &CODNAM,
                               const std::string &SET_NAME) :
               card() , NFIELD(NFIELD), ILREF(ILREF),
               CODNAM(CODNAM), CODTXT(0),
               SET_NAME(SET_NAME), CONT() {
               auto div_val = ldiv(CODNAM, 100);
               nlnam = div_val.quot != 0;
               ncnam = div_val.rem;
               nltxt = 0;
               nctxt = 0;
            }

            tdload::tdload(const long &ILREF,
                               const std::string &SET_NAME) :
               card() , NFIELD(4), ILREF(ILREF),
               CODTXT(0),
               SET_NAME(SET_NAME), CONT() {
               nlnam = true;
               ncnam = (long)SET_NAME.size();
               CODNAM = 100 + ncnam;
               nltxt = 0;
               nctxt = 0;
            }

            const dnvgl::extfem::fem::cards::types
            tdload::card_type(void) const { return TDLOAD; };

            const std::ostream&
            tdload::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const tdload &card) {

               os << tdload::head.format()
                  << card._form_NFIELD.format(card.NFIELD)
                  << card._form_ILREF.format(card.ILREF)
                  << card._form_CODNAM.format(card.CODNAM)
                  << card._form_CODTXT.format(card.CODTXT) << std::endl;
               if (card.nlnam)
                  os << dnvgl::extfem::fem::types::card().format()
                     << card._form_SET_NAME.format(card.SET_NAME, card.ncnam+8) << std::endl;
               for (auto p : card.CONT)
                  os << dnvgl::extfem::fem::types::card().format()
                     << card._form_CONT.format(p, card.nctxt+8) << std::endl;

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
