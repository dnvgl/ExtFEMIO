/**
   \file bdf_cards_cmass2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF CMASS2 cards.

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
   long static const cl1 = 1;
   long static const cl0 = 0;
   double static const cd0 = 0.;
}

namespace dnvgl {
   namespace extfem {
      namespace bdf {

         using namespace type_bounds;
         using types::entry_type;

         namespace cards {

            const entry_type<long> cmass2::form_EID(
               "EID", bdf::type_bounds::bound<long>(&cl1));
            const entry_type<double> cmass2::form_M("M");
            const entry_type<long> cmass2::form_G1(
               "G1", bound<long>(nullptr, nullptr, nullptr, true));
            const entry_type<std::list<int> > cmass2::form_C1("C1");
            const entry_type<long> cmass2::form_G2(
               "G2", bound<long>(nullptr, nullptr, nullptr, true));
            const entry_type<std::list<int> > cmass2::form_C2("C2");

            cmass2::cmass2(void) :
               card(),
               EID(nullptr), M(nullptr), G1(nullptr), C1(nullptr),
               G2(nullptr), C2(nullptr) {}

            cmass2::cmass2(std::list<std::string> const &inp) :
               card(inp) {
               this->read(inp);
            }

            cmass2::cmass2(long const *EID, double const *M,
                           long const *G1, std::list<int> const *C1,
                           long const *G2/*=nullptr*/, std::list<int> const *C2/*=nullptr*/) :
               card(),
               EID(EID), M(M), G1(G1), C1(C1), G2(G2), C2(C2) {
               if (((long)this->EID < 1l) || ((long)this->EID > 100000000l))
                  throw errors::error("CMASS2", "EID not in valid range");
               if (this->G1 && this->C1.value.size() == 0)
                  throw errors::error("CMASS2", "G1 requires C1 value");
               if (this->G2 && this->C2.value.size() == 0)
                  throw errors::error("CMASS2", "G2 requires C2 value");
            }

            __base::card const *cmass2::operator() (
               long const *EID, double const *M,
               long const *G1, std::list<int> const *C1,
               long const *G2/*=nullptr*/, std::list<int> const *C2/*=nullptr*/) {
               this->EID = EID;
               this->M = *M;
               this->G1 = *G1;
               this->C1 = *C1;
               if (G2)
                  this->G2 = *G2;
               else
                  this->G2 = nullptr;
               if (C2)
                  this->C2 = *C2;
               else
                  this->C2 = nullptr;
               return this;
            }

            bdf::types::card cmass2::head = bdf::types::card("CMASS2");

            void cmass2::read(std::list<std::string> const &inp) {
               auto pos = inp.begin();

               form_G1.set_value(G1, "");
               form_C1.set_value(C1, "");
               form_G2.set_value(G2, "");
               form_C2.set_value(C2, "");

               if (pos == inp.end()) goto invalid;
               ++pos;
               if (pos == inp.end()) goto invalid;
               form_EID.set_value(EID, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_M.set_value(M, *(pos++));
               if (pos == inp.end()) goto end;
               form_G1.set_value(G1, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_C1.set_value(C1, *(pos++));
               if (pos == inp.end()) goto end;
               form_G2.set_value(G2, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_C2.set_value(C2, *pos);
               goto end;

            invalid:
               throw errors::parse_error("CMASS2", "Illegal number of entries.");
            end: ;
            }

            const types cmass2::card_type(void) const {
               return CMASS2;
            }

            void cmass2::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {

               if (!EID) return;

               res.push_back(format(cmass2::head));

               res.push_back(format<long>(form_EID, EID));
               res.push_back(format<double>(form_M, M));
               if (G1 || G2) {
                  res.push_back(format<long>(form_G1, G1));
                  res.push_back(format<std::list<int> >(form_C1, C1));
               }
               if (G2) {
                  res.push_back(format<long>(form_G2, G2));
                  res.push_back(format<std::list<int> >(form_C2, C2));
               }

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
