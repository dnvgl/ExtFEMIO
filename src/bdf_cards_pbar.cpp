// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PBAR cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "stdafx.h"

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_cards.h"

#include <cstdlib>
#include <memory>

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;;

const entry_type<double> pbar::_A(
  "A", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_I1(
  "I1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_I2(
  "I2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_J(
  "J", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_NSM(
  "NSM", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_C1(
  "C1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_C2(
  "C2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_D1(
  "D1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_D2(
  "D2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_E1(
  "E1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_E2(
  "E2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_F1(
  "F1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_F2(
  "F2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> pbar::_K1(
  "K1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, nullptr, true));
const entry_type<double> pbar::_K2(
  "K2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, nullptr, true));
const entry_type<double> pbar::_I12(
  "I12", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));

pbar::pbar(const deque<std::string> &inp) : bar_prop(inp) {

  auto pos = inp.rbegin();

  A = make_unique<double>(0.);
  I1 = make_unique<double>(0.);
  I2 = make_unique<double>(0.);
  J = make_unique<double>(0.);
  NSM = make_unique<double>(0.);
  C1 = make_unique<double>(0.);
  C2 = make_unique<double>(0.);
  D1 = make_unique<double>(0.);
  D2 = make_unique<double>(0.);
  E1 = make_unique<double>(0.);
  E2 = make_unique<double>(0.);
  F1 = make_unique<double>(0.);
  F2 = make_unique<double>(0.);
  K1 = nullptr;
  K2 = nullptr;
  I12 = make_unique<double>(0.);

  switch (inp.size()-1) {
  case 24:
    ++pos;
  case 23:
    ++pos;
  case 22:
    ++pos;
  case 21:
    ++pos;
  case 20:
    ++pos;
  case 19:
    I12 = get_val<double>(_I12, *(pos++));
  case 18:
    K2 = get_val<double>(_K2, *(pos++));
  case 17:
    K1 = get_val<double>(_K1, *(pos++));
  case 16:
    F2 = get_val<double>(_F2, *(pos++));
  case 15:
    F1 = get_val<double>(_F1, *(pos++));
  case 14:
    E2 = get_val<double>(_E2, *(pos++));
  case 13:
    E1 = get_val<double>(_E1, *(pos++));
  case 12:
    D2 = get_val<double>(_D2, *(pos++));
  case 11:
    D1 = get_val<double>(_D1, *(pos++));
  case 10:
    C2 = get_val<double>(_C2, *(pos++));
  case 9:
    C1 = get_val<double>(_C1, *(pos++));
  case 8:
    ++pos;
  case 7:
    NSM = get_val<double>(_NSM, *(pos++));
  case 6:
    J = get_val<double>(_J, *(pos++));
  case 5:
    I2 = get_val<double>(_I2, *(pos++));
  case 4:
    I1 = get_val<double>(_I1, *(pos++));
  case 3:
    A = get_val<double>(_A, *(pos++));
  case 2:
    MID = get_val<long>(_MID, *(pos++));
    PID = get_val<long>(_PID, *(pos));
    break;
  default:
    throw bdf_parse_error(
      "CBAR.", "Illegal number of entries.");
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
