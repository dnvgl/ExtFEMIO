/**
   \file fem/fem_cards_gnode.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GNODE` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_cards_gnode[]
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

            const fem::types::card gnode::head("GNODE");

            const entry_type<long> gnode::_form_NODEX("NODEX");
            const entry_type<long> gnode::_form_NODENO("NODENO");
            const entry_type<long> gnode::_form_NDOF("NDOF");
            const entry_type<std::vector<int> > gnode::_form_ODOF("ODOF");

            gnode::gnode(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 5)
                  throw errors::parse_error(
                     "GNODE", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               NODEX = _form_NODEX(*(pos++));
               NODENO = _form_NODENO(*(pos++));
               NDOF = _form_NDOF(*(pos++));
               ODOF = std::vector<int>(*_form_ODOF(*(pos++)));
            }

            gnode::gnode(void) :
               gnode(-1, 0, {}) {}

            gnode::gnode(const long &NODEX,
                         const long &NODENO,
                         const long &NDOF,
                         const std::vector<int> &ODOF) :
               card(),
               NODEX(NODEX), NODENO(NODENO), NDOF(NDOF),
               ODOF(ODOF.begin(), ODOF.end()) {
               std::sort(this->ODOF.begin(), this->ODOF.end());
            };

            gnode::gnode(const long &NODEX,
                         const long &NODENO,
                         const std::vector<int> &ODOF) :
               gnode(NODEX, NODENO, static_cast<long>(ODOF.size()), ODOF) {}

            const dnvgl::extfem::fem::cards::types
            gnode::card_type(void) const {return types::GNODE;}

            std::ostream &gnode::put(std::ostream& os) const {
               if (this->NODEX == -1) return os;
               os << gnode::head.format()
                  << this->_form_NODEX.format(this->NODEX)
                  << this->_form_NODENO.format(this->NODENO)
                  << this->_form_NDOF.format(this->NDOF)
                  << this->_form_ODOF.format(this->ODOF) << std::endl;

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
