/**
   \file bdf_cards_cmass4.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF CMASS4 cards.

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

            const entry_type<long> cmass4::form_EID(
               "EID", bdf::type_bounds::bound<long>(&cl1));
            const entry_type<double> cmass4::form_M("M");
            const entry_type<long> cmass4::form_S1("S1");
            const entry_type<long> cmass4::form_S2("S2");

            cmass4::cmass4(const std::list<std::string> &inp) :
               card(inp) {

               auto pos = inp.begin();

               if (pos == inp.end()) goto invalid;
               ++pos;
               if (pos == inp.end()) goto invalid;
               form_EID.set_value(EID, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_M.set_value(M, *(pos++));
               if (pos == inp.end()) goto end;
               form_S1.set_value(S1, *(pos++));
               if (pos == inp.end()) goto end;
               form_S2.set_value(S2, *(pos++));
               goto end;

            invalid:
               throw errors::parse_error("CMASS4", "Illegal number of entries.");
            end: ;
            }

            cmass4::cmass4(long const *EID, double const *M,
                           long const *S1, long const *S2/*=NULL*/) :
               card(),
               EID(EID), M(M), S1(S1), S2(S2) {
               if (((long)this->EID < 1l) || ((long)this->EID > 100000000l))
                  throw errors::error("CMASS4", "EID not in valid range");
            }

            bdf::types::card cmass4::head = bdf::types::card("CMASS4");

            const types cmass4::card_type(void) const {
               return CMASS4;
            }

            void cmass4::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {

               res.push_back(format(cmass4::head));

               res.push_back(format<long>(form_EID, EID));
               res.push_back(format<double>(form_M, M));
               if (S1 || S2)
                  res.push_back(format<long>(form_S1, S1));
               if (S2)
                  res.push_back(format<long>(form_S2, S2));

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
