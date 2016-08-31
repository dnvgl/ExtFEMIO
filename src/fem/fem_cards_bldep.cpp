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
#include <cassert>

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

            const fem::types::card bldep::head("BLDEP");

            const entry_type<long> bldep::_form_NODENO("NODENO");
            const entry_type<long> bldep::_form_CNOD("CNOD");
            const entry_type<long> bldep::_form_NDDOF("NDDOF");
            const entry_type<long> bldep::_form_NDEP("NDEP");
            const entry_type<long> bldep::_form_DEPDOF("DEPDOF");
            const entry_type<long> bldep::_form_INDEPDOF("INDEPDOF");
            const entry_type<double> bldep::_form_b("b");

            bldep::bldep(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 9)
                  throw errors::parse_error(
                     "BLDEP", "Illegal number of entries.");

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

            bldep::bldep(void) :
               bldep(-1, 0, 0, 0, {}, {}, {}) {}

            bldep::bldep(
               long const &NODENO,
               long const &CNOD,
               long const &NDDOF,
               long const &NDEP,
               std::vector<long> const &DEPDOF,
               std::vector<long> const &INDEPDOF,
               std::vector<double> const &b) :
               NODENO(NODENO), CNOD(CNOD), NDDOF(NDDOF), NDEP(NDEP),
               DEPDOF(DEPDOF), INDEPDOF(INDEPDOF), b(b) {
               assert(DEPDOF.size() == INDEPDOF.size());
               assert(DEPDOF.size() == b.size());
            }

            bldep::bldep(
               long const &NODENO,
               long const &CNOD,
               long const &NDDOF,
               std::vector<long> const &DEPDOF,
               std::vector<long> const &INDEPDOF,
               std::vector<double> const &b) :
               bldep(NODENO, CNOD, NDDOF,
                     static_cast<long>(DEPDOF.size()),
                     DEPDOF, INDEPDOF, b) {}

            bldep::bldep(
               long const &NODENO,
               long const &CNOD,
               std::vector<long> const &DEPDOF,
               std::vector<long> const &INDEPDOF,
               std::vector<double> const &b) :
               bldep(NODENO, CNOD, static_cast<long>(DEPDOF.size()),
                     static_cast<long>(DEPDOF.size()),
                     DEPDOF, INDEPDOF, b) {}

            const dnvgl::extfem::fem::cards::types
            bldep::card_type(void) const {return BLDEP;}

            std::ostream &bldep::put(std::ostream& os) const {
               if (this->NODENO == -1) return os;
               os << bldep::head.format()
                  << this->_form_NODENO.format(this->NODENO)
                  << this->_form_CNOD.format(this->CNOD)
                  << this->_form_NDDOF.format(this->NDDOF)
                  << this->_form_NDEP.format(this->NDEP)
                  << std::endl;
               for (long i = 0; i < this->NDEP; i++)
                  os << dnvgl::extfem::fem::types::card().format()
                     << this->_form_DEPDOF.format(this->DEPDOF[i])
                     << this->_form_INDEPDOF.format(this->INDEPDOF[i])
                     << this->_form_b.format(this->b[i])
                     << this->empty.format()
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
