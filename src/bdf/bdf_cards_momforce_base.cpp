/**
   \file bdf/bdf_cards_momforce_base.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF `FORCE` and `MOMENT` cards.

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

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;

namespace {
   static const long cl0 = 0, cl1 = 1;
   static const double cd0 = 0.;
}

const entry_type<long> momforce_base::form_SID(
   "SID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> momforce_base::form_G(
   "G", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> momforce_base::form_CID(
   "CID", bdf::type_bounds::bound<long>(&cl0, nullptr, &cl0));
const entry_type<double> momforce_base::form_F("F");
const entry_type<double> momforce_base::form_N1(
   "N1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> momforce_base::form_N2(
   "N2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> momforce_base::form_N3(
   "N3", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));

momforce_base::momforce_base(const std::deque<std::string> &inp) :
   card(inp) {

   auto pos = inp.rbegin();

   form_N2.set_value(N2, "");
   form_N3.set_value(N3, "");

   switch (inp.size()-1) {
   case 8:
      ++pos;
   case 7:
      form_N3.set_value(N3, *(pos++));
   case 6:
      form_N2.set_value(N2, *(pos++));
   case 5:
      form_N1.set_value(N1, *(pos++));
      if (N1 == 0. && N2 == 0. && N3 == 0.) {
         throw errors::parse_error(
            "FORCE/MOMENT", "At least one of N1, N2, and N3 has to be != 0..");
      }
      form_F.set_value(F, *(pos++));
      form_CID.set_value(CID, *(pos++));
      form_G.set_value(G, *(pos++));
      form_SID.set_value(SID, *(pos++));
      break;
   default:
      throw errors::parse_error("FORCE/MOMENT", "Illegal number of entries.");
   }
}

momforce_base::momforce_base(
   const long *SID, const long *G, const long *CID,
   const double *F,
   const double *N1, const double *N2, const double *N3) :
   SID(*SID), G(*G), CID(*CID), F(*F), N1(N1), N2(N2), N3(N3) {}

void momforce_base::add_collect(
   std::deque<std::unique_ptr<format_entry>> &res,
   const momforce_base &card) const {
   res.push_back(format<long>(card.form_SID, card.SID));
   res.push_back(format<long>(card.form_G, card.G));
   res.push_back(format<long>(card.form_CID, card.CID));
   res.push_back(format<double>(card.form_F, card.F));
   res.push_back(format<double>(card.form_N1, card.N1));
   if (N2 || N3)
      res.push_back(format<double>(card.form_N2, card.N2));
   if (N3)
      res.push_back(format<double>(card.form_N3, card.N3));

}

const std::ostream& momforce_base::operator<<(std::ostream& os) const {
   os << this;
   return os;
}

namespace dnvgl {
   namespace extfem {
      namespace bdf{
         namespace cards{

            bdf::types::card force::head = bdf::types::card("FORCE");

            const std::ostream& force::operator<< (std::ostream& os) const {
               return os << *this;
            }

            bdf::types::card moment::head = bdf::types::card("MOMENT");

            const std::ostream& moment::operator<< (std::ostream& os) const {
               return os << *this;
            }

            std::ostream DECLSPECIFIER &operator<<(std::ostream &os, const force &card) {

               std::deque<std::unique_ptr<format_entry>> entries;

               entries.push_back(format(force::head));

               card.add_collect(entries, card);

               os << card.format_outlist(entries) << std::endl;

               return os;
            }

            std::ostream DECLSPECIFIER &operator<<(std::ostream &os, const moment &card) {

               std::deque<std::unique_ptr<format_entry>> entries;

               entries.push_back(format(moment::head));

               card.add_collect(entries, card);

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
// compile-command: "make -C ../.. check -j 8"
// End:
