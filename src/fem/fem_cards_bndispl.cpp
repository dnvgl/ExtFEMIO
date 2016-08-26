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

            const fem::types::card bndispl::head("BNDISPL");

            const entry_type<long> bndispl::_form_LLC("LLC");
            const entry_type<long> bndispl::_form_DTYPE("DTYPE");
            const entry_type<bool> bndispl::_form_COMPLX("COMPLX");
            const entry_type<long> bndispl::_form_NODENO("NODENO");
            const entry_type<long> bndispl::_form_NDOF("NDOF");
            const entry_type<double> bndispl::_form_RDISP("RDISP");
            const entry_type<double> bndispl::_form_IDISP("IDISP");

            bndispl::bndispl(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 8)
                  throw errors::parse_error(
                     "BNDISPL", "Illegal number of entries.");

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
                  for (long i = 0; i < NDOF; i++)
                     IDISP.push_back(_form_IDISP(*(pos++)));
            }

            bndispl::bndispl(void) :
               bndispl(-1, 0, false, 0, {}) {}

            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const bool &COMPLX,
                             const long &NODENO,
                             const long &NDOF,
                             const std::vector<double> &RDISP,
                             const std::vector<double> &IDISP) :
               card(), LLC(LLC), DTYPE(DTYPE), COMPLX(COMPLX),
               NODENO(NODENO), NDOF(NDOF),
               RDISP(RDISP), IDISP(IDISP) {}


            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const bool &COMPLX,
                             const long &NODENO,
                             const std::vector<double> &RDISP,
                             const std::vector<double> &IDISP) :
               bndispl(LLC, DTYPE, COMPLX, NODENO, (long)RDISP.size(),
                       RDISP, IDISP) {}

            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const long &NODENO,
                             const long &NDOF,
                             const std::vector<double> &RDISP,
                             const std::vector<double> &IDISP) :
               bndispl(LLC, DTYPE, IDISP.size() > 0, NODENO, NDOF,
                       RDISP, IDISP) {}


            bndispl::bndispl(const long &LLC,
                             const long &DTYPE,
                             const long &NODENO,
                             const std::vector<double> &RDISP,
                             const std::vector<double> &IDISP) :
               bndispl(LLC, DTYPE, NODENO, (long)RDISP.size(),
                       RDISP, IDISP) {}

            const dnvgl::extfem::fem::cards::types
            bndispl::card_type(void) const {return BNDISPL;}

            std::ostream &bndispl::put(std::ostream& os) const {
               if (this->LLC == -1) return os;
               os << bndispl::head.format()
                  << this->_form_LLC.format(this->LLC)
                  << this->_form_DTYPE.format(this->DTYPE)
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
                  os << this->_form_RDISP.format(this->RDISP[i]);
                  cnt += 1;
               }
               if (this->COMPLX) {
                  assert(this->IDISP.size() == (size_t)this->NDOF);
                  for (long i = 0; i < this->NDOF; i++) {
                     if (cnt == 4) {
                        os << std::endl << dnvgl::extfem::fem::types::card().format();
                        cnt = 0;
                     }
                     os << this->_form_IDISP.format(this->IDISP[i]);
                     cnt += 1;
                  }
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
