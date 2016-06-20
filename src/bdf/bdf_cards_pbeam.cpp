/**
   \file bdf/bdf_cards_pbeam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBEAM cards.

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

#include <cstdlib>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/type_bounds.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace bdf::cards;
using bdf::types::entry_type;

namespace {
   static const double cd0 = 0., cd1 = 1.;
}

const entry_type<double> pbeam::form_A("A");
const entry_type<double> pbeam::form_I1("I1");
const entry_type<double> pbeam::form_I2("I2");
const entry_type<double> pbeam::form_I12(
   "I12", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_J(
   "J", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_NSM(
   "NSM", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_C1(
   "C1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_C2(
   "C1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_D1(
   "D1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_D2(
   "D2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_E1(
   "E1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_E2(
   "E2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_F1(
   "F1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_F2(
   "F2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
// fields that might appear more than once
namespace {
   static const size_t SO_len = 3;
   const char* SO_init[SO_len] = { "YES", "YESA", "NO" };
   const std::set<std::string> SO_set(SO_init, SO_init + SO_len);
}
const entry_type<std::string> pbeam::form_SO(
   "SO", bdf::type_bounds::bound<std::string>(SO_set));
const entry_type<double> pbeam::form_X_XB(
   "X/XB", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
// fields_finish
const entry_type<double> pbeam::form_K1(
   "K1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd1));
const entry_type<double> pbeam::form_K2(
   "K2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd1));
const entry_type<double> pbeam::form_S1(
   "S1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_S2(
   "S2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_NSI_A(
   "NSI_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_NSI_B(
   "NSI_B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_CW_A(
   "CW_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_CW_B(
   "CW_B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_M1_A(
   "M1_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_M2_A(
   "M2_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_M1_B(
   "M1_B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_M2_B(
   "M2_B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_N1_A(
   "N1_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_N2_A(
   "N2_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_N1_B(
   "N1_B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_N2_B(
   "N2_B",
   bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));

pbeam::pbeam(const std::deque<std::string> &inp) : beam_prop(inp) {

   auto pos = inp.rbegin();

   auto div_val = ldiv(static_cast<long>(inp.size())-1, 16);

   auto block_cnt = div_val.quot;
   auto block_rem = div_val.rem;

   form_K1.set_value(K1, "");
   form_S1.set_value(S1, "");
   form_S2.set_value(S2, "");
   form_NSI_A.set_value(NSI_A, "");
   form_NSI_B.set_value(NSI_B, "");
   form_CW_A.set_value(CW_A, "");
   form_CW_B.set_value(CW_B, "");
   form_M1_A.set_value(M1_A, "");
   form_M2_A.set_value(M2_A, "");
   form_M1_B.set_value(M1_B, "");
   form_M2_B.set_value(M2_B, "");
   form_N1_A.set_value(N1_A, "");
   form_N2_A.set_value(N2_A, "");
   form_N1_B.set_value(N1_B, "");
   form_N2_B.set_value(N2_B, "");

   if (block_rem == 0) {
      block_rem = 16;
   }

   if (block_cnt > 1) {
      switch (block_rem) {
      case 16:
         form_N2_B.set_value(N2_B, *(pos++));
      case 15:
         form_N1_B.set_value(N1_B, *(pos++));
      case 14:
         form_N2_A.set_value(N2_A, *(pos++));
      case 13:
         form_N1_A.set_value(N1_A, *(pos++));
      case 12:
         form_M2_B.set_value(M2_B, *(pos++));
      case 11:
         form_M1_B.set_value(M1_B, *(pos++));
      case 10:
         form_M2_A.set_value(M2_A, *(pos++));
      case 9:
         form_M1_A.set_value(M1_A, *(pos++));
      case 8:
         form_CW_B.set_value(CW_B, *(pos++));
      case 7:
         form_CW_A.set_value(CW_A, *(pos++));
      case 6:
         form_NSI_B.set_value(NSI_B, *(pos++));
      case 5:
         form_NSI_A.set_value(NSI_A, *(pos++));
      case 4:
         form_S2.set_value(S2, *(pos++));
      case 3:
         form_S1.set_value(S1, *(pos++));
      case 2:
         form_K2.set_value(K2, *(pos++));
      case 1:
         form_K1.set_value(K1, *(pos++));
      }
      block_rem = 16;
   }

   for (size_t i = block_cnt; i > 2; --i ) {
      switch (block_rem) {
      case 16:
         F2.push_front(form_F2(*(pos++)));
      case 15:
         F1.push_front(form_F1(*(pos++)));
      case 14:
         E2.push_front(form_E2(*(pos++)));
      case 13:
         E1.push_front(form_E1(*(pos++)));
      case 12:
         D2.push_front(form_D2(*(pos++)));
      case 11:
         D1.push_front(form_D1(*(pos++)));
      case 10:
         C2.push_front(form_C2(*(pos++)));
      case 9:
         C1.push_front(form_C1(*(pos++)));
      case 8:
         NSM.push_front(form_NSM(*(pos++)));
         J.push_front(form_J(*(pos++)));
         I12.push_front(form_I12(*(pos++)));
         I2.push_front(form_I2(*(pos++)));
         I1.push_front(form_I1(*(pos++)));
         A.push_front(form_A(*(pos++)));
         X_XB.push_front(form_X_XB(*(pos++)));
         SO.push_front(form_SO(*(pos++)));
      }
   }

   switch (block_rem) {
   case 16:
      F2.push_front(form_F2(*(pos++)));
   case 15:
      F1.push_front(form_F1(*(pos++)));
   case 14:
      E2.push_front(form_E2(*(pos++)));
   case 13:
      E1.push_front(form_E1(*(pos++)));
   case 12:
      D2.push_front(form_D2(*(pos++)));
   case 11:
      D1.push_front(form_D1(*(pos++)));
   case 10:
      C2.push_front(form_C2(*(pos++)));
   case 9:
      C1.push_front(form_C1(*(pos++)));
   case 8:
      NSM.push_front(form_NSM(*(pos++)));
   case 7:
      J.push_front(form_J(*(pos++)));
   case 6:
      I12.push_front(form_I12(*(pos++)));
   case 5:
      I2.push_front(form_I2(*(pos++)));
      I1.push_front(form_I1(*(pos++)));
      A.push_front(form_A(*(pos++)));
      form_MID.set_value(MID, *(pos++));
      form_PID.set_value(PID, *(pos));
      break;
   default:
      throw errors::parse_error("PBEAM", "Illegal number of entries.");
   }
   if (J.size() == 0)
      J.push_front(dnvgl::extfem::bdf::types::entry_value<double>());
}

std::ostream& pbeam::operator << (std::ostream& os) const {
   throw errors::error("can't write PBEAM.");
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
