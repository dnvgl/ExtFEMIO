/**
   \file fem/fem_cards_gelth.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GELTH` cards.

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

            const fem::types::card gelth::head("GELTH");


            const entry_type<long> gelth::_form_GEONO("GENO");
            const entry_type<double> gelth::_form_TH("TH");
            const entry_type<long> gelth::_form_NINT("NINT");

            gelth::gelth(const std::list<std::string> &inp) :
               card(inp), NINT(0) {

               if (inp.size() < 4)
                  throw errors::parse_error(
                     "GELTH", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;

               GEONO = _form_GEONO(*(pos++));
               TH = _form_TH(*(pos++));
               if (*pos != "                ")
                  NINT = _form_NINT(*pos);
            }

            gelth::gelth(void) :
               gelth(-1, 0) {}

            gelth::gelth(
               const long &GEONO,
               const double &TH, const long &NINT/*=0*/) :
               card(), GEONO(GEONO), TH(TH), NINT(NINT) {}

            const dnvgl::extfem::fem::cards::types
            gelth::card_type(void) const {return GELTH;}

            std::ostream &gelth::put(std::ostream& os) const {
               if (this->GEONO == -1) return os;
               os << gelth::head.format()
                  << this->_form_GEONO.format(this->GEONO)
                  << this->_form_TH.format(this->TH);
               if (this->NINT)
                  os << this->_form_NINT.format(this->NINT);
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
// compile-command: "make -C ../.. check -j8"
// End:
