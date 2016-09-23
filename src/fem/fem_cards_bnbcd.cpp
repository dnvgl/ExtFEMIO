/**
   \file fem/fem_cards_bnbcd.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BNBCD` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_cards_bnbcd[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef FIX
#undef FIX
#endif // FIX

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

            const fem::types::card bnbcd::head("BNBCD");

            const entry_type<long> bnbcd::_form_NODENO("NODENO");
            const entry_type<long> bnbcd::_form_NDOF("NDOF");
            const entry_type<long> bnbcd::_form_FIX("FIX");

            bnbcd::bnbcd(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 4)
                  throw errors::parse_error(
                     "BNBCD", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               NODENO = _form_NODENO(*(pos++));
               NDOF = _form_NDOF(*(pos++));

               for (long i = 0; i < NDOF; i++)
                  FIX.push_back(_form_FIX(*(pos++)));
            }

            bnbcd::bnbcd(void) :
               bnbcd(-1, {}) {}

            bnbcd::bnbcd(const long &NODENO,
                         const long &NDOF,
                         const std::vector<long> &FIX) :
               card(), NODENO(NODENO), NDOF(NDOF), FIX(FIX) {}

            bnbcd::bnbcd(
               const long &NODENO,
               const std::vector<long> &FIX) :
               bnbcd(NODENO, (long)FIX.size(), FIX) {}

            bnbcd::bnbcd(long const &NODENO,
                         long const &FIX1, long const &FIX2, long const &FIX3,
                         long const &FIX4, long const &FIX5, long const &FIX6) :
               bnbcd(NODENO, 6, std::vector<long>({
                        FIX1, FIX2, FIX3, FIX4, FIX5, FIX6})) {}

            const dnvgl::extfem::fem::cards::types
            bnbcd::card_type(void) const {return types::BNBCD;}

            std::ostream &bnbcd::put(std::ostream& os) const {
               if (this->NODENO == -1) return os;
               os << bnbcd::head.format()
                  << this->_form_NODENO.format(this->NODENO)
                  << this->_form_NDOF.format(this->NDOF);
               long cnt = 2;
               for (long i = 0; i < this->NDOF; i++) {
                  if (cnt == 4) {
                     os << std::endl << dnvgl::extfem::fem::types::card().format();
                     cnt = 0;
                  }
                  os << this->_form_FIX.format(this->FIX[i]);
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
