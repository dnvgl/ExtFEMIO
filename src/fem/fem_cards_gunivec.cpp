/**
   \file fem/fem_cards_gunivec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GUNIVEC` cards.

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

            const fem::types::card gunivec::head("GUNIVEC");

            const entry_type<long> gunivec::_form_TRANSNO("TRANSNO");
            const entry_type<double> gunivec::_form_UNIX("UNIX");
            const entry_type<double> gunivec::_form_UNIY("UNIY");
            const entry_type<double> gunivec::_form_UNIZ("UNIZ");

            gunivec::gunivec(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 5)
                  throw errors::parse_error(
                     "GUNIVEC", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               TRANSNO = _form_TRANSNO(*(pos++));
               UNIX = _form_UNIX(*(pos++));
               UNIY = _form_UNIY(*(pos++));
               UNIZ = _form_UNIZ(*(pos++));
            }

            gunivec::gunivec(void) :
               gunivec(-1, 0., 0., 0.) {}

            gunivec::gunivec(const long &TRANSNO,
                             const double &UNIX,
                             const double &UNIY,
                             const double &UNIZ) :
               card(), TRANSNO(TRANSNO),
               UNIX(UNIX), UNIY(UNIY), UNIZ(UNIZ) {}

            const dnvgl::extfem::fem::cards::types
            gunivec::card_type(void) const {return GUNIVEC;}

            std::ostream &gunivec::put(std::ostream& os) const {
               if (this->TRANSNO == -1) return os;
               os << gunivec::head.format()
                  << this->_form_TRANSNO.format(this->TRANSNO)
                  << this->_form_UNIX.format(this->UNIX)
                  << this->_form_UNIY.format(this->UNIY)
                  << this->_form_UNIZ.format(this->UNIZ)
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
// compile-command: "make -C ../.. check -j8"
// End:
