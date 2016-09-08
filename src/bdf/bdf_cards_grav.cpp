/**
   \file bdf/bdf_cards_grav.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF GRAV cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id: bdf_cards_grav.cpp 402 2016-07-01 16:03:47Z berhol $";
}

#include <cassert>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
   static const long cl0 = 0;
   static const long cl1 = 1;
}

using dnvgl::extfem::bdf::types::entry_type;
using dnvgl::extfem::bdf::types::entry_value;

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

            const entry_type<long> grav::form_SID(
               "SID", bdf::type_bounds::bound<long>(&cl1));
            const entry_type<long> grav::form_CID(
               "CID", bdf::type_bounds::bound<long>(&cl0));
            const entry_type<double> grav::form_A("A");
            const entry_type<double> grav::form_Ni("Ni");
            const entry_type<long> grav::form_MB(
               "MB",
               bdf::type_bounds::bound<long>(nullptr, nullptr, &cl0));

            grav::grav(const std::list<std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               if (pos == inp.end()) goto invalid;
               ++pos;
               if (pos == inp.end()) goto invalid;
               form_SID.set_value(SID, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_CID.set_value(CID, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_A.set_value(A, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_Ni.set_value(N1, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_Ni.set_value(N2, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_Ni.set_value(N3, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_MB.set_value(MB, *(pos++));
               goto end;

            invalid:
               throw errors::parse_error("GRAV", "Illegal number of entries.");
            end: ;
            }

            grav::grav(const long *SID, const long *CID, const double *A,
                       const double *N1, const double *N2, const double *N3,
                       const long *MB/*=NULL*/) :
               card(),
               SID(SID), CID(CID), A(A), N1(N1), N2(N2), N3(N3), MB(MB) {}

            grav::grav(const long *SID, const long *CID, const double *A,
                       const std::vector<double> *N,
                       const long *MB/*=NULL*/) :
               grav(SID, CID, A, &(*N)[0], &(*N)[1], &(*N)[2], MB) {
               if (N->size() != 3)
                  throw errors::error("GRAV N requires 3 entries.");
            }

            bdf::types::card grav::head = bdf::types::card("GRAV");

            const types grav::card_type(void) const {
               return GRAV;
            }

            void grav::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {

               res.push_back(format(grav::head));

               res.push_back(format<long>(form_SID, SID));
               res.push_back(format<long>(form_CID, CID));
               res.push_back(format<double>(form_A, A));
               res.push_back(format<double>(form_Ni, N1));
               res.push_back(format<double>(form_Ni, N2));
               res.push_back(format<double>(form_Ni, N3));
               if (MB)
                  res.push_back(format<long>(form_MB, MB));

               return;
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
