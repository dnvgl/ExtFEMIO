// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PBEAM cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<double> pbeam::_A("A");
const entry_type<double> pbeam::_I1("I1");
const entry_type<double> pbeam::_I2("I2");
const entry_type<double> pbeam::_I12(
  "I12", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_J(
  "J", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_NSM(
  "NSM", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_C1(
  "C1", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_C2(
  "C1", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_D1(
  "D1", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_D2(
  "D2", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_E1(
  "E1", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_E2(
  "E2", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_F1(
  "F1", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_F2(
  "F2", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
// fields that might appear more than once
namespace {
  static const size_t SO_len = 3;
  const char* SO_init[SO_len] = { "YES", "YESA", "NO" };
  const std::set<std::string> SO_set(SO_init, SO_init + SO_len);
}
const entry_type<std::string> pbeam::_SO("SO", bdf::type_bounds::bound<std::string>(SO_set));
const entry_type<double> pbeam::_X_XB(
  "X/XB",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
// fields_finish
const entry_type<double> pbeam::_K1(
  "K1", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(1.).get()));
const entry_type<double> pbeam::_K2(
  "K2", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(1.).get()));
const entry_type<double> pbeam::_S1(
  "S1", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_S2(
  "S2", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_NSI_A(
  "NSI_A", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_NSI_B(
  "NSI_B", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_CW_A(
  "CW_A", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_CW_B(
  "CW_B", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_M1_A(
  "M1_A", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_M2_A(
  "M2_A", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_M1_B(
  "M1_B", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_M2_B(
  "M2_B", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_N1_A(
  "N1_A", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_N2_A(
  "N2_A", bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbeam::_N1_B(
  "N1_B", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::_N2_B(
  "N2_B", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));

pbeam::pbeam(const deque<std::string> &inp) : beam_prop(inp) {

  auto pos = inp.rbegin();

  auto div_val = ldiv(static_cast<long>(inp.size())-1, 16);

  auto block_cnt = div_val.quot;
  auto block_rem = div_val.rem;

  K1 = nullptr;
  S1 = nullptr;
  S2 = nullptr;
  NSI_A = nullptr;
  NSI_B = nullptr;
  CW_A = nullptr;
  CW_B = nullptr;
  M1_A = nullptr;
  M2_A = nullptr;
  M1_B = nullptr;
  M2_B = nullptr;
  N1_A = nullptr;
  N2_A = nullptr;
  N1_B = nullptr;
  N2_B = nullptr;

  if (block_rem == 0) {
    block_rem = 16;
  }

  if (block_cnt > 1) {
    switch (block_rem) {
    case 16:
      N2_B = bdf::types::get_val<double>(_N2_B, *(pos++));
    case 15:
      N1_B = bdf::types::get_val<double>(_N1_B, *(pos++));
    case 14:
      N2_A = bdf::types::get_val<double>(_N2_A, *(pos++));
    case 13:
      N1_A = bdf::types::get_val<double>(_N1_A, *(pos++));
    case 12:
      M2_B = bdf::types::get_val<double>(_M2_B, *(pos++));
    case 11:
      M1_B = bdf::types::get_val<double>(_M1_B, *(pos++));
    case 10:
      M2_A = bdf::types::get_val<double>(_M2_A, *(pos++));
    case 9:
      M1_A = bdf::types::get_val<double>(_M1_A, *(pos++));
    case 8:
      CW_B = bdf::types::get_val<double>(_CW_B, *(pos++));
    case 7:
      CW_A = bdf::types::get_val<double>(_CW_A, *(pos++));
    case 6:
      NSI_B = bdf::types::get_val<double>(_NSI_B, *(pos++));
    case 5:
      NSI_A = bdf::types::get_val<double>(_NSI_A, *(pos++));
    case 4:
      S2 = bdf::types::get_val<double>(_S2, *(pos++));
    case 3:
      S1 = bdf::types::get_val<double>(_S1, *(pos++));
    case 2:
      K2 = bdf::types::get_val<double>(_K2, *(pos++));
    case 1:
      K1 = bdf::types::get_val<double>(_K1, *(pos++));
    }
    block_rem = 16;
  }

  for (size_t i = block_cnt; i > 2; --i ) {
    switch (block_rem) {
    case 16:
      F2.push_front(bdf::types::get_val<double>(_F2, *(pos++)));
    case 15:
      F1.push_front(bdf::types::get_val<double>(_F1, *(pos++)));
    case 14:
      E2.push_front(bdf::types::get_val<double>(_E2, *(pos++)));
    case 13:
      E1.push_front(bdf::types::get_val<double>(_E1, *(pos++)));
    case 12:
      D2.push_front(bdf::types::get_val<double>(_D2, *(pos++)));
    case 11:
      D1.push_front(bdf::types::get_val<double>(_D1, *(pos++)));
    case 10:
      C2.push_front(bdf::types::get_val<double>(_C2, *(pos++)));
    case 9:
      C1.push_front(bdf::types::get_val<double>(_C1, *(pos++)));
    case 8:
      NSM.push_front(bdf::types::get_val<double>(_NSM, *(pos++)));
      J.push_front(bdf::types::get_val<double>(_J, *(pos++)));
      I12.push_front(bdf::types::get_val<double>(_I12, *(pos++)));
      I2.push_front(bdf::types::get_val<double>(_I2, *(pos++)));
      I1.push_front(bdf::types::get_val<double>(_I1, *(pos++)));
      A.push_front(bdf::types::get_val<double>(_A, *(pos++)));
      X_XB.push_front(bdf::types::get_val<double>(_X_XB, *(pos++)));
      SO.push_front(bdf::types::get_val<std::string>(_SO, *(pos++)));
    }
  }

  switch (block_rem) {
  case 16:
    F2.push_front(bdf::types::get_val<double>(_F2, *(pos++)));
  case 15:
    F1.push_front(bdf::types::get_val<double>(_F1, *(pos++)));
  case 14:
    E2.push_front(bdf::types::get_val<double>(_E2, *(pos++)));
  case 13:
    E1.push_front(bdf::types::get_val<double>(_E1, *(pos++)));
  case 12:
    D2.push_front(bdf::types::get_val<double>(_D2, *(pos++)));
  case 11:
    D1.push_front(bdf::types::get_val<double>(_D1, *(pos++)));
  case 10:
    C2.push_front(bdf::types::get_val<double>(_C2, *(pos++)));
  case 9:
    C1.push_front(bdf::types::get_val<double>(_C1, *(pos++)));
  case 8:
    NSM.push_front(bdf::types::get_val<double>(_NSM, *(pos++)));
  case 7:
    J.push_front(bdf::types::get_val<double>(_J, *(pos++)));
  case 6:
    I12.push_front(bdf::types::get_val<double>(_I12, *(pos++)));
  case 5:
    I2.push_front(bdf::types::get_val<double>(_I2, *(pos++)));
    I1.push_front(bdf::types::get_val<double>(_I1, *(pos++)));
    A.push_front(bdf::types::get_val<double>(_A, *(pos++)));
    MID = bdf::types::get_val<long>(_MID, *(pos++));
    PID = bdf::types::get_val<long>(_PID, *(pos));
    break;
  default:
    throw errors::parse_error("PBEAM", "Illegal number of entries.");
  }
  if (J.size() == 0)
    J.push_front(NULL);
}

const std::ostream& pbeam::operator << (std::ostream& os) const {
  throw errors::error("can't write PBEAM.");
  return os;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
