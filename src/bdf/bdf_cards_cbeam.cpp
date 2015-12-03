/**
   \file bdf/bdf_cards_cbeam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Defintions for Patran CBEAM cards.

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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace bdf::cards;
using bdf::types::entry_type;

namespace {
   static const long lc1 = 1;
   static const double dc0 = 0.;
}

const entry_type<long> cbeam::form_EID("EID",
                                   bdf::type_bounds::bound<long>(&lc1));
const entry_type<long> cbeam::form_PID("PID");
const entry_type<long> cbeam::form_GA("GA");
const entry_type<long> cbeam::form_GB("GB");
const entry_type<double> cbeam::form_X1("X1");
const entry_type<long> cbeam::form_G0(
   "G0", bdf::type_bounds::bound<long>(&lc1));
const entry_type<double> cbeam::form_X2(
   "X2",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> cbeam::form_X3(
   "X3",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> cbeam::form_BIT(
   "BIT", bdf::type_bounds::bound<double>());
namespace {
   const char* OFFTinit[8] = {
      "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO" };
   const std::set<std::string> OFFT_set(OFFTinit, OFFTinit + 8);
}
const entry_type<std::string> cbeam::form_OFFT(
   "OFFT", bdf::type_bounds::bound<std::string>(OFFT_set, "GGG"));

const entry_type<deque<int>> cbeam::form_PA("PA"); // maxelem=5, minval=1, maxval=6, uniq=True);
const entry_type<deque<int>> cbeam::form_PB("PB"); // maxelem=5, minval=1, maxval=6, uniq=True);
const entry_type<double> cbeam::form_W1A(
   "W1A",
   bdf::type_bounds::bound<double>(nullptr, nullptr, &dc0)); // default=0.),
const entry_type<double> cbeam::form_W2A(
   "W2A",
   bdf::type_bounds::bound<double>(nullptr, nullptr, &dc0)); // default=0.),
const entry_type<double> cbeam::form_W3A(
   "W3A",
   bdf::type_bounds::bound<double>(nullptr, nullptr, &dc0)); // default=0.),
const entry_type<double> cbeam::form_W1B(
   "W1B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, &dc0)); // default=0.),
const entry_type<double> cbeam::form_W2B(
   "W2B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, &dc0)); // default=0.),
const entry_type<double> cbeam::form_W3B(
   "W3B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, &dc0)); // default=0.),
const entry_type<long> cbeam::form_SA(
   "SA",
   bdf::type_bounds::bound<long>(&lc1, nullptr, nullptr, true)); // minval=1, default=None)
const entry_type<long> cbeam::form_SB(
   "SB",
   bdf::type_bounds::bound<long>(&lc1, nullptr, nullptr, true)); // minval=1, default=None)

cbeam::cbeam(const deque<std::string> &inp) :
   card(inp) {

   auto pos = inp.rbegin();

   form_SB.set_value(SB, "");
   form_SA.set_value(SA, "");
   form_W3B.set_value(W3B, "");
   form_W2B.set_value(W2B, "");
   form_W1B.set_value(W1B, "");
   form_W3A.set_value(W3A, "");
   form_W2A.set_value(W2A, "");
   form_W1A.set_value(W1A, "");
   form_PB.set_value(PB, "");
   form_PA.set_value(PA, "");
   OFFT.is_value = false;
   BIT.is_value = false;

   switch (inp.size()-1) {
   case 24:
      pos++;
   case 23:
      pos++;
   case 22:
      pos++;
   case 21:
      pos++;
   case 20:
      pos++;
   case 19:
      pos++;
   case 18:
      form_SB.set_value(SB, *(pos++));
   case 17:
      form_SA.set_value(SA, *(pos++));
   case 16:
      form_W3B.set_value(W3B, *(pos++));
   case 15:
      form_W2B.set_value(W2B, *(pos++));
   case 14:
      form_W1B.set_value(W1B, *(pos++));
   case 13:
      form_W3A.set_value(W3A, *(pos++));
   case 12:
      form_W2A.set_value(W2A, *(pos++));
   case 11:
      form_W1A.set_value(W1A, *(pos++));
   case 10:
      form_PB.set_value(PB, *(pos++));
   case 9:
      form_PA.set_value(PA, *(pos++));
   case 8:
      try {
         form_BIT.set_value(BIT, *pos);
         OFFT.is_value = false;
         choose_offt_bit = has_BIT;
      }
      catch (errors::float_error) {
         form_OFFT.set_value(OFFT, *pos);
         BIT.is_value = false;
         choose_offt_bit = has_OFFT;
      }
      ++pos;
   case 7:
      form_X3.set_value(X3, *(pos++));
   case 6:
      form_X2.set_value(X2, *(pos++));
   case 5:
      try {
         form_X1.set_value(X1, *(pos));
         if (!X2.is_value || !X3.is_value) {
            throw errors::parse_error(
               "CBEAM", "Incomplete direction vector.");
         }
         G0.is_value = false;
         choose_dir_code = has_DVEC;
      }
      catch (errors::float_error) {
         form_G0.set_value(G0, *pos);
         X1.is_value = false;
         choose_dir_code = has_DCODE;
      }
      ++pos;
      form_GB.set_value(GB, *(pos++));
      form_GA.set_value(GA, *(pos++));
      form_PID.set_value(PID, *(pos++));
      form_EID.set_value(EID, *(pos++));
      break;
   default:
      throw errors::parse_error(
         "CBEAM", "Illegal number of entries for CBEAM");
   }

   if (!W3B.is_value) form_W3B.set_value(W3B, "");
   if (!W2B.is_value) form_W2B.set_value(W2B, "");
   if (!W1B.is_value) form_W1B.set_value(W1B, "");
   if (!W3A.is_value) form_W3A.set_value(W3A, "");
   if (!W2A.is_value) form_W2A.set_value(W2A, "");
   if (!W1A.is_value) form_W1A.set_value(W1A, "");
   if (!PB.is_value) form_PB.set_value(PB, "");
   if (!PA.is_value) form_PA.set_value(PA, "");
   if (!(BIT.is_value || OFFT.is_value)) {
      choose_offt_bit = has_OFFT;
      form_OFFT.set_value(OFFT, "");
   }
};

const std::ostream& cbeam::operator << (std::ostream& os) const {
   throw errors::error("can't write CBEAM.");
   return os;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
