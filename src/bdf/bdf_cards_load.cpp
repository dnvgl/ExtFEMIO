/**
   \file bdf/bdf_cards_load.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF LOAD cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
   const char cID_bdf_cards_load[]
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
   static const long cl1 = 1;
}

namespace dnvgl {
   namespace extfem {

      using bdf::types::entry_type;
      using bdf::types::entry_value;

      namespace bdf {
         namespace cards {

            const entry_type<long> load::form_SID(
               "SID", bdf::type_bounds::bound<long>(&cl1));
            const entry_type<double> load::form_S("S");
            const entry_type<double> load::form_Si("Si");
            const entry_type<long> load::form_Li(
               "Li", bdf::type_bounds::bound<long>(&cl1));

            load::load() :
               SID(nullptr), S(nullptr), Si(), Li() {}

            load::load(const std::list<std::string> &inp) :
               card(inp) {
               this->read(inp);
            }

            load::load(const long *SID, const double *S,
                       const std::list<double> *Si, const std::list<long> *Li) :
               SID(*SID), S(*S), Si(), Li() {
               if (Si)
                  copy(Si->begin(), Si->end(), back_inserter(this->Si));
               if (Li)
                  copy(Li->begin(), Li->end(), back_inserter(this->Li));
            }

            __base::card const *load::operator() (
               const long *SID, const double *S,
               const std::list<double> *Si, const std::list<long> *Li) {

               this->Si.clear();
               this->Li.clear();

               this->SID = *SID;
               this->S = *S;
               if (Si)
                  copy(Si->begin(), Si->end(), back_inserter(this->Si));
               if (Li)
                  copy(Li->begin(), Li->end(), back_inserter(this->Li));
               return this;
            }

            bdf::types::card load::head = bdf::types::card("LOAD");

            const types load::card_type(void) const {
               return types::LOAD;
            }

            void load::read(std::list<std::string> const &inp) {
               auto pos = inp.begin();

               Si.clear();
               Li.clear();

               if (pos == inp.end()) goto invalid;
               ++pos;
               if (pos == inp.end()) goto invalid;
               form_SID.set_value(SID, *(pos++));
               if (pos == inp.end()) goto invalid;
               form_S.set_value(S, *(pos++));
               if (pos == inp.end()) goto invalid;
               while (pos != inp.end() && extfem::string::string(*pos) != "") {
                  Si.push_back(form_Si(*(pos++)));
                  if (pos == inp.end()) goto invalid;
                  Li.push_back(form_Li(*(pos++)));
               }
               goto end;

            invalid:
               throw errors::parse_error("LOAD", "Illegal number of entries.");
            end: ;
            }

            void load::collect_outdata(
               std::list<std::unique_ptr<format_entry> > &res) const {

               if (static_cast<long>(SID) <= 0 ) return;

               res.push_back(format(load::head));

               res.push_back(format<long>(form_SID, SID));
               res.push_back(format<double>(form_S, S));

               assert(Si.size() == Li.size());

               auto pS = Si.begin();
               for (auto pL=Li.begin(); pL != Li.end(); ++pL) {
                  res.push_back(format<double>(form_Si, &(*pS)));
                  res.push_back(format<long>(form_Li, &(*pL))); //
                  ++pS;
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
