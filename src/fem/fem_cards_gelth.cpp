/**
   \file fem_cards_gelth.cpp
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

            gelth::gelth(const std::deque<std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               TH = _form_TH(*(pos++));
               NINT = _form_NINT(*(pos++));
            }

            gelth::gelth(
               const long &GEONO,
               const double &TH, const long &NINT) :
               card(), GEONO(GEONO), TH(TH), NINT(NINT) {}

            const dnvgl::extfem::fem::cards::types
            gelth::card_type(void) const {return GELTH;}

            const std::ostream&
            gelth::operator<< (std::ostream& os) const {
               os << this;
               return os;
            }

            std::ostream&
            operator<< (std::ostream &os, const gelth &data) {
               os << gelth::head.format()
                  << data._form_GEONO.format(data.GEONO)
                  << data._form_TH.format(data.TH)
                  << data._form_NINT.format(data.NINT)
                  << data.empty.format() << std::endl;
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
// compile-command: "make -C ../.. check -j 8"
// End:
