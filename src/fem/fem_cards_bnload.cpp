/**
   \file fem/fem_cards_bnload.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BNLOAD` cards.

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

            const fem::types::card bnload::head("BNLOAD");

            const entry_type<long> bnload::_form_LLC("LLC");
            const entry_type<long> bnload::_form_LOTYP("LOTYP");
            const entry_type<bool> bnload::_form_COMPLX("COMPLX");
            const entry_type<long> bnload::_form_NODENO("NODENO");
            const entry_type<long> bnload::_form_NDOF("NDOF");
            const entry_type<double> bnload::_form_RLOAD("RLOAD");
            const entry_type<double> bnload::_form_ILOAD("ILOAD");

            bnload::bnload(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 8)
                  throw errors::parse_error(
                     "BNLOAD", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               LLC = _form_LLC(*(pos++));
               LOTYP = _form_LOTYP (*(pos++));
               COMPLX = _form_COMPLX(*(pos++));
               ++pos;
               NODENO = _form_NODENO(*(pos++));
               NDOF = _form_NDOF(*(pos++));
               for (long i = 0; i < NDOF; i++)
                  RLOAD.push_back(_form_RLOAD(*(pos++)));
               if (COMPLX)
                  for (long i = 0; i < NDOF; i++)
                     ILOAD.push_back(_form_ILOAD(*(pos++)));
            }

            bnload::bnload(void) :
               bnload(-1, 0, 0, {}) {}

            bnload::bnload(const long &LLC,
                           const long &LOTYP,
                           const bool &COMPLX,
                           const long &NODENO,
                           const long &NDOF,
                           const std::vector<double> &RLOAD,
                           const std::vector<double> &ILOAD) :
               card(), LLC(LLC), LOTYP(LOTYP), COMPLX(COMPLX),
               NODENO(NODENO), NDOF(NDOF),
               RLOAD(RLOAD), ILOAD(ILOAD) {}

            bnload::bnload(const long &LLC,
                           const long &LOTYP,
                           const bool &COMPLX,
                           const long &NODENO,
                           const std::vector<double> &RLOAD,
                           const std::vector<double> &ILOAD):
               card(), LLC(LLC), LOTYP(LOTYP), COMPLX(COMPLX),
               NODENO(NODENO), NDOF((long)RLOAD.size()),
               RLOAD(RLOAD), ILOAD(ILOAD) {}

            bnload::bnload(const long &LLC,
                           const long &LOTYP,
                           const long &NODENO,
                           const long &NDOF,
                           const std::vector<double> &RLOAD,
                           const std::vector<double> &ILOAD) :
               card(), LLC(LLC), LOTYP(LOTYP),
               COMPLX(ILOAD.size() > 0),
               NODENO(NODENO), NDOF(NDOF),
               RLOAD(RLOAD), ILOAD(ILOAD) {}


            bnload::bnload(const long &LLC,
                           const long &LOTYP,
                           const long &NODENO,
                           const std::vector<double> &RLOAD,
                           const std::vector<double> &ILOAD) :
               card(), LLC(LLC), LOTYP(LOTYP),
               COMPLX(ILOAD.size() > 0),
               NODENO(NODENO), NDOF((long)RLOAD.size()),
               RLOAD(RLOAD), ILOAD(ILOAD) {}

            const dnvgl::extfem::fem::cards::types
            bnload::card_type(void) const {return BNLOAD;}

            std::ostream &bnload::put(std::ostream& os) const {
               if (this->LLC == -1) return os;
               os << bnload::head.format()
                  << this->_form_LLC.format(this->LLC)
                  << this->_form_LOTYP.format(this->LOTYP)
                  << this->_form_COMPLX.format(this->COMPLX)
                  << this->empty.format() << std::endl
                  << dnvgl::extfem::fem::types::card().format()
                  << this->_form_NODENO.format(this->NODENO)
                  << this->_form_NDOF.format(this->NDOF);
               long cnt = 2;
               for (long i = 0; i < this->NDOF; i++) {
                  if (cnt == 4) {
                     os << std::endl << dnvgl::extfem::fem::types::card().format();
                     cnt = 0;
                  }
                  os << this->_form_RLOAD.format(this->RLOAD[i]);
                  cnt += 1;
               }
               if (this->COMPLX)
                  for (long i = 0; i < this->NDOF; i++) {
                     if (cnt == 4) {
                        os << std::endl << dnvgl::extfem::fem::types::card().format();
                        cnt = 0;
                     }
                     os << this->_form_ILOAD.format(this->ILOAD[i]);
                     cnt += 1;
                  }
               os << std::endl;
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
