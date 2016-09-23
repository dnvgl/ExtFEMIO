/**
   \file fem/fem_cards_hsupstat.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `HSUPSTAT` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_cards_hsupstat[]
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

            const fem::types::card hsupstat::head("HSUPSTAT");

            const entry_type<long> hsupstat::_form_NFIELD("NFIELD");
            const entry_type<long> hsupstat::_form_ISELTY("ISELTY");
            const entry_type<long> hsupstat::_form_NIDOF("NIDOF");
            const entry_type<long> hsupstat::_form_NRDOF("NRDOF");
            const entry_type<long> hsupstat::_form_NBAND("NBAND");
            const entry_type<long> hsupstat::_form_NELT("NELT");
            const entry_type<long> hsupstat::_form_LINDEP("LINDEP");
            const entry_type<long> hsupstat::_form_RELOADC("RELOADC");
            const entry_type<long> hsupstat::_form_COMPLC("COMPLC");

            hsupstat::hsupstat(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 10)
                  throw errors::parse_error(
                     "HSUPSTAT", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               NFIELD = _form_NFIELD(*(pos++));
               ISELTY = _form_ISELTY(*(pos++));
               NIDOF = _form_NIDOF(*(pos++));
               NRDOF = _form_NRDOF(*(pos++));
               NBAND = _form_NBAND(*(pos++));
               NELT = _form_NELT(*(pos++));
               LINDEP = _form_LINDEP(*(pos++));
               RELOADC = _form_RELOADC(*(pos++));
               COMPLC = _form_COMPLC(*(pos++));
            }

            hsupstat::hsupstat(void) :
               hsupstat(-1, 0, 0, 0, 0, 0, 0, 0, 0) {}


            hsupstat::hsupstat(const long &NFIELD,
                               const long &ISELTY,
                               const long &NIDOF,
                               const long &NRDOF,
                               const long &NBAND,
                               const long &NELT,
                               const long &LINDEP,
                               const long &RELOADC,
                               const long &COMPLC) :
               card(), NFIELD(NFIELD), ISELTY(ISELTY), NIDOF(NIDOF),
               NRDOF(NRDOF), NBAND(NBAND), NELT(NELT), LINDEP(LINDEP),
               RELOADC(RELOADC), COMPLC(COMPLC) {}

            const dnvgl::extfem::fem::cards::types
            hsupstat::card_type(void) const {
               return types::HSUPSTAT;
            }

            std::ostream &hsupstat::put(std::ostream& os) const {
               if (this->NFIELD == -1) return os;
               os << hsupstat::head.format()
                  << this->_form_NFIELD.format(this->NFIELD)
                  << this->_form_ISELTY.format(this->ISELTY)
                  << this->_form_NIDOF.format(this->NIDOF)
                  << this->_form_NRDOF.format(this->NRDOF) << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << this->_form_NBAND.format(this->NBAND)
                  << this->_form_NELT.format(this->NELT)
                  << this->_form_LINDEP.format(this->LINDEP)
                  << this->_form_RELOADC.format(this->RELOADC) << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << this->_form_COMPLC.format(this->COMPLC)
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
