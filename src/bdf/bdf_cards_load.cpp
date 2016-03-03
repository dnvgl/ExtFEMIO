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
   static const long cl1 = 1;
}

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;
using bdf::types::entry_value;

const entry_type<long> load::form_SID(
   "SID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<double> load::form_S("S");
const entry_type<double> load::form_Si("Si");
const entry_type<long> load::form_Li(
   "Li", bdf::type_bounds::bound<long>(&cl1));

load::load(const std::deque<std::string> &inp) :
   card(inp) {

   auto pos = inp.begin();

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

load::load(const long *SID, const double *S,
           const std::deque<double> *Si, const std::deque<long> *Li) :
   SID(*SID), S(*S) {
   if (Si)
      copy(Si->begin(), Si->end(), back_inserter(this->Si));
   if (Li)
      copy(Li->begin(), Li->end(), back_inserter(this->Li));
}

namespace dnvgl {
   namespace extfem {
      namespace bdf {
         namespace cards {

            bdf::types::card load::head = bdf::types::card("LOAD");

            const std::ostream&
            load::operator<< (std::ostream& os) const {
               return os << *this;
            }

            std::ostream
            &operator<<(std::ostream &os, const load &card) {

               std::deque<std::unique_ptr<format_entry>> entries;

               entries.push_back(format(load::head));

               entries.push_back(format<long>(card.form_SID, card.SID));
               entries.push_back(format<double>(card.form_S, card.S));

               assert(card.Si.size() == card.Li.size());

               auto pS = card.Si.begin();
               for (auto pL=card.Li.begin(); pL != card.Li.end(); ++pL) {
                  entries.push_back(format<double>(card.form_Si, &(*pS)));
                  entries.push_back(format<long>(card.form_Li, &(*pL))); //
                  ++pS;
               }

               os << card.format_outlist(entries) << std::endl;

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
