/**
   \file fem/fem_cards_ident.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `IDENT` cards.

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
#include "fem/errors.h"

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

            const fem::types::card ident::head("IDENT");

            const entry_type<long> ident::_form_SLEVEL("SLEVEL");
            const entry_type<long> ident::_form_SELTYP("SELTYP");
            const entry_type<long> ident::_form_SELMOD("SELMOD");

            ident::ident(const std::deque<std::string> &inp) :
               card(inp) {

               if (inp.size() < 5)
                  throw errors::parse_error(
                     "IDENT", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               SLEVEL = _form_SLEVEL(*(pos++));
               SELTYP = _form_SELTYP(*(pos++));
               switch (_form_SELMOD(*(pos++))) {
               case 0:
               case 3:
                  SELMOD = DIM_3D;
                  break;
               case 2:
                  SELMOD = DIM_2D;
                  break;
               default:
                  throw dnvgl::extfem::fem::errors::parse_error("IDENT", "Error in selmod, value not 0, 2, or 3.");
               }
            }

            ident::ident(
               const long &SLEVEL, const long &SELTYP,
               const ident::mod_type &SELMOD) :
               SLEVEL(SLEVEL), SELTYP(SELTYP), SELMOD(SELMOD) {};

            const types
            ident::card_type(void) const { return IDENT; };

            const std::ostream&
            ident::operator<<(std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<<(std::ostream &os, const ident &card) {

               os << ident::head.format()
                  << card._form_SLEVEL.format(card.SLEVEL)
                  << card._form_SELTYP.format(card.SELTYP)
                  << card._form_SELMOD.format(card.SELMOD)
                  << ident::empty.format() << std::endl;

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
