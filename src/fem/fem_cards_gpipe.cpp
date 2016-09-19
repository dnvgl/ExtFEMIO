/**
   \file fem/fem_cards_gpipe.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GPIPE` cards.

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

            const fem::types::card gpipe::head("GPIPE");

            const entry_type<double> gpipe::_form_DI("DI");
            const entry_type<double> gpipe::_form_DY("DY");
            const entry_type<double> gpipe::_form_T("T");
            const entry_type<double> gpipe::_form_SFY("SFY");
            const entry_type<double> gpipe::_form_SFZ("SFZ");
            const entry_type<long> gpipe::_form_NCIR("NCIR");
            const entry_type<long> gpipe::_form_NRAD("NRAD");

            gpipe::gpipe(std::list<std::string> const &inp) :
               __base::beam_prop(inp), NCIR(0), NRAD(0) {

               if (inp.size() < 7)
                  throw errors::parse_error(
                     "GPIPE", "Illegal number of entries.");

               auto pos = inp.begin();

               ++pos;
               GEONO = _form_GEONO(*(pos++));
               DI = _form_DI(*(pos++));
               DY = _form_DY(*(pos++));
               T = _form_T(*(pos++));
               SFY = _form_SFY(*(pos++));
               SFZ = _form_SFZ(*(pos++));
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NCIR = _form_NCIR(*(pos++));
               else
                  pos++;
               if (pos == inp.end()) return;
               if (*pos != "                ")
                  NRAD = _form_NRAD(*pos);
            }

            gpipe::gpipe(void) :
               gpipe(-1, 0., 0., 0., 0., 0.) {}

            gpipe::gpipe(const long &GEONO, const double &DI,
                         const double &DY,
                         const double &T, const double &SFY,
                         const double &SFZ,
                         const long &NCIR/*=0*/, const long &NRAD/*=0*/) :
               __base::beam_prop(GEONO),
               DI(DI), DY(DY), T(T),
               SFY(SFY), SFZ(SFZ),
               NCIR(NCIR), NRAD(NRAD) {}

            const dnvgl::extfem::fem::cards::types
            gpipe::card_type(void) const {return GPIPE;}

            std::ostream &gpipe::put(std::ostream& os) const {
               if (this->GEONO == -1) return os;
               os << gpipe::head.format()
                  << this->_form_GEONO.format(this->GEONO)
                  << this->_form_DI.format(this->DI)
                  << this->_form_DY.format(this->DY)
                  << this->_form_T.format(this->T)
                  << std::endl << dnvgl::extfem::fem::types::card().format()
                  << this->_form_SFY.format(this->SFY)
                  << this->_form_SFZ.format(this->SFZ);
               if ((this->NCIR || this->NRAD))
                  os << this->_form_NCIR.format(this->NCIR)
                     << this->_form_NRAD.format(this->NRAD);
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
