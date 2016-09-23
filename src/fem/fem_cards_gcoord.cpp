/**
   \file fem/fem_cards_gcoord.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GCOORD` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_cards_gcoord[]
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

            const fem::types::card gcoord::head("GCOORD");

            const entry_type<long> gcoord::_form_NODENO("NODENO");
            const entry_type<double> gcoord::_form_XCOORD("XCOORD");
            const entry_type<double> gcoord::_form_YCOORD("YCOORD");
            const entry_type<double> gcoord::_form_ZCOORD("ZCOORD");

            gcoord::gcoord(const std::list<std::string> &inp) :
               card(inp) {

               if (inp.size() < 5)
                  throw errors::parse_error(
                     "GCOORD", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               NODENO = _form_NODENO(*(pos++));
               XCOORD = _form_XCOORD(*(pos++));
               YCOORD = _form_YCOORD(*(pos++));
               ZCOORD = _form_ZCOORD(*(pos++));
            }

            gcoord::gcoord(void) :
               gcoord(-1, 0., 0., 0.) {}

            gcoord::gcoord(
               const long &NODENO,
               const double &XCOORD, const double &YCOORD, const double &ZCOORD) :
               NODENO(NODENO),
               XCOORD(XCOORD), YCOORD(YCOORD), ZCOORD(ZCOORD) {}

            const dnvgl::extfem::fem::cards::types
            gcoord::card_type(void) const {return types::GCOORD;}

            std::ostream &gcoord::put(std::ostream& os) const {
               if (this->NODENO == -1) return os;
               os << gcoord::head.format()
                  << this->_form_NODENO.format(this->NODENO)
                  << this->_form_XCOORD.format(this->XCOORD)
                  << this->_form_YCOORD.format(this->YCOORD)
                  << this->_form_ZCOORD.format(this->ZCOORD);
               return os << std::endl;
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
