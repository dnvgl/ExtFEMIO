/**
   \file fem/fem_cards_glsec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GLSEC` cards.

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

            const fem::types::card glsec::head("GLSEC");

            const entry_type<double> glsec::_form_HZ("HZ");
            const entry_type<double> glsec::_form_TY("TY");
            const entry_type<double> glsec::_form_BY("BY");
            const entry_type<double> glsec::_form_TZ("TZ");
            const entry_type<double> glsec::_form_SFY("SFY");
            const entry_type<double> glsec::_form_SFZ("SFZ");
            const entry_type<bool> glsec::_form_K("K");
            const entry_type<long> glsec::_form_NLOBY("NLOBY");
            const entry_type<long> glsec::_form_NLOBZ("NLOBZ");

            glsec::glsec(const std::list<std::string> &inp) :
               base_beam_prop(inp), NLOBY(0), NLOBZ(0) {

               if (inp.size() < 9)
                  throw errors::parse_error(
                     "GLSEC", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               HZ = _form_HZ(*(pos++));
               TY = _form_TY(*(pos++));
               BY = _form_BY(*(pos++));
               TZ = _form_TZ(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               K = _form_K(*(pos++));
               if (pos == inp.end()) return;
               NLOBY = _form_NLOBY(*(pos++));
               if (pos == inp.end()) return;
               NLOBZ = _form_NLOBZ(*pos);
            }

            glsec::glsec(void) :
               glsec(-1, 0., 0., 0., 0., 0., 0., false) {}

            glsec::glsec(const long &GEONO, const double &HZ,
                         const double &TY, const double &BY,
                         const double &TZ, const double &SFY,
                         const double &SFZ, const bool &K,
                         const long &NLOBY/*=0*/, const long &NLOBZ/*=0*/) :
               base_beam_prop(GEONO),
               HZ(HZ), TY(TY), BY(BY), TZ(TZ),
               SFY(SFY), SFZ(SFZ),
               K(K), NLOBY(NLOBY), NLOBZ(NLOBZ) {}

            const dnvgl::extfem::fem::cards::types
            glsec::card_type(void) const {return GLSEC;}

            std::ostream &glsec::put(std::ostream& os) const {
               if (this->GEONO == -1) return os;
               os << glsec::head.format()
                  << this->_form_GEONO.format(this->GEONO)
                  << this->_form_HZ.format(this->HZ)
                  << this->_form_TY.format(this->TY)
                  << this->_form_BY.format(this->BY)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << this->_form_TZ.format(this->TZ)
                  << this->_form_SFY.format(this->SFY)
                  << this->_form_SFZ.format(this->SFZ)
                  << this->_form_K.format(this->K)
                  << std::endl;
               if (!(this->NLOBY || this->NLOBZ))
                  return os;
               os << dnvgl::extfem::fem::types::card().format()
                  << this->_form_NLOBY.format(this->NLOBY)
                  << this->_form_NLOBZ.format(this->NLOBZ)
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
