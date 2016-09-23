/**
   \file fem/fem_cards_tdsupnam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `TDSUPNAM` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_cards_tdsupnam[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef max
#undef max
#endif // max

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

            const fem::types::card tdsupnam::head("TDSUPNAM");

            const entry_type<long> tdsupnam::_form_NFIELD("NFIELD");
            const entry_type<long> tdsupnam::_form_IHREF("IHREF");
            const entry_type<long> tdsupnam::_form_CODNAM("CODNAM");
            const entry_type<long> tdsupnam::_form_CODTXT("CODTXT");
            const entry_type<std::string> tdsupnam::_form_SUP_NAME("SUP_NAME");
            const entry_type<std::string> tdsupnam::_form_CONT("CONT");

            tdsupnam::tdsupnam(const std::list<std::string> &inp) :
               card(inp) {
               if (inp.size() < 9)
                  throw errors::parse_error(
                     "TDSUPNAM", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               NFIELD = _form_NFIELD(*(pos++));
               if (NFIELD != 4) {
                  std::ostringstream msg(
                     "Only NFIELD values of 4 are supported, "
                     "but got value of ",
                     std::ostringstream::ate);
                  msg << NFIELD;
                  errors::parse_error("TDSUPNAM", msg.str());
               }
               IHREF = _form_IHREF(*(pos++));
               CODNAM = _form_CODNAM(*(pos++));
               CODTXT = _form_CODTXT(*(pos++));

               auto div_val = ldiv(CODNAM, 100);
               nlnam = div_val.quot != 0;
               ncnam = div_val.rem;
               div_val = ldiv(CODTXT, 100);
               nltxt = div_val.quot;
               nctxt = div_val.rem;

               if (nlnam) {
                  auto pos_0 = *pos++;
                  auto pos_1 = *pos++;
                  auto pos_2 = *pos++;
                  auto pos_3 = *pos++;
                  SUP_NAME = _form_SUP_NAME(
                     pos_0, pos_1, pos_2, pos_3);
                  SUP_NAME.resize(ncnam, ' ');
               } else (((pos++)++)++)++;
               for (long i=0; i < nltxt; i++) {
                  auto pos_0 = *pos++;
                  auto pos_1 = *pos++;
                  auto pos_2 = *pos++;
                  auto pos_3 = *pos++;
                  std::string cont = _form_CONT(
                     pos_0, pos_1, pos_2, pos_3);
                  cont.resize(nctxt, ' ');
                  CONT.push_back(cont);
               }
            }

            tdsupnam::tdsupnam(void) :
               tdsupnam(-1, 0, 0, 0, {}, {}) {}

            tdsupnam::tdsupnam(const long &NFIELD,
                               const long &IHREF,
                               const long &CODNAM,
                               const long &CODTXT,
                               const std::string &SUP_NAME,
                               const std::vector<std::string> &CONT) :
               card(), NFIELD(NFIELD), IHREF(IHREF),
               CODNAM(CODNAM), CODTXT(CODTXT),
               SUP_NAME(SUP_NAME), CONT(CONT) {
               auto div_val = ldiv(CODNAM, 100);
               nlnam = div_val.quot != 0;
               ncnam = div_val.rem;
               div_val = ldiv(CODTXT, 100);
               nltxt = div_val.quot;
               nctxt = div_val.rem;
            }

            tdsupnam::tdsupnam(const long &IHREF,
                               const std::string &SUP_NAME,
                               const std::vector<std::string> &CONT) :
               card(), NFIELD(4), IHREF(IHREF),
               SUP_NAME(SUP_NAME), CONT(CONT) {

               nlnam = true;
               ncnam = (long)SUP_NAME.size();
               CODNAM = 100 + ncnam;
               nltxt = (long)CONT.size();
               nctxt = 0;
               for (auto &p : CONT)
                  nctxt = std::max(nctxt, (long)p.size());
               for (auto &p : this->CONT)
                  p.resize(nctxt, ' ');
               CODTXT = (100 * nltxt) + nctxt;
            }

            tdsupnam::tdsupnam(const long &NFIELD,
                               const long &IHREF,
                               const long &CODNAM,
                               const std::string &SUP_NAME) :
               card() , NFIELD(NFIELD), IHREF(IHREF),
               CODNAM(CODNAM), CODTXT(0),
               SUP_NAME(SUP_NAME), CONT() {
               auto div_val = ldiv(CODNAM, 100);
               nlnam = div_val.quot != 0;
               ncnam = div_val.rem;
               nltxt = 0;
               nctxt = 0;
            }

            tdsupnam::tdsupnam(const long &IHREF,
                               const std::string &SUP_NAME) :
               card() , NFIELD(4), IHREF(IHREF),
               CODTXT(0),
               SUP_NAME(SUP_NAME), CONT() {
               nlnam = true;
               ncnam = (long)SUP_NAME.size();
               CODNAM = 100 + ncnam;
               nltxt = 0;
               nctxt = 0;
            }

            const dnvgl::extfem::fem::cards::types
            tdsupnam::card_type(void) const { return types::TDSUPNAM; };

            std::ostream &tdsupnam::put(std::ostream& os) const {
               if (this->NFIELD == -1) return os;
               os << tdsupnam::head.format()
                  << this->_form_NFIELD.format(this->NFIELD)
                  << this->_form_IHREF.format(this->IHREF)
                  << this->_form_CODNAM.format(this->CODNAM)
                  << this->_form_CODTXT.format(this->CODTXT)
                  << std::endl;
               if (this->nlnam)
                  os << dnvgl::extfem::fem::types::card().format()
                     << this->_form_SUP_NAME.format(this->SUP_NAME, this->ncnam+8)
                     << std::endl;
               for (auto p : this->CONT)
                  os << dnvgl::extfem::fem::types::card().format()
                     << this->_form_CONT.format(p, this->nctxt+8)
                     << std::endl;
               return os;
            }
         }
      }
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
