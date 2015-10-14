// Copyright © 2015 by DNV GL SE

// Purpose: Defintions for Patran CBAR cards.

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
#include "bdf_types.h"
#include "bdf_errors.h"

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<long> cbar::_EID(
  "EID",
  bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> cbar::_PID("PID");
const entry_type<long> cbar::_GA("GA");
const entry_type<long> cbar::_GB("GB");
const entry_type<double> cbar::_X1("X1");
const entry_type<long> cbar::_G0(
  "G0", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<double> cbar::_X2(
  "X2",
  bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> cbar::_X3(
  "X3",
  bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
namespace {
  const char* initVals[8] = {
    "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO" };
  const set<std::string> OFFT_set(initVals, initVals + 8);
}
const entry_type<std::string> cbar::_OFFT(
  "OFFT", bdf::type_bounds::bound<std::string>(OFFT_set, "GGG"));

const entry_type<deque<int>> cbar::_PA("PA");
const entry_type<deque<int>> cbar::_PB("PB");
const entry_type<double> cbar::_W1A(
  "W1A",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> cbar::_W2A(
  "W2A",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> cbar::_W3A(
  "W3A",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> cbar::_W1B(
  "W1B",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> cbar::_W2B(
  "W2B",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> cbar::_W3B(
  "W3B",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));

cbar::cbar(const deque<std::string> &inp) :
  card(inp) {

  auto pos = inp.rbegin();

  W1A = nullptr;
  W3B = nullptr;
  W2B = nullptr;
  W1B = nullptr;
  W3A = nullptr;
  W2A = nullptr;
  W1A = nullptr;
  PB = nullptr;
  PA = nullptr;
  OFFT = nullptr;

  switch (inp.size()-1) {
  case 16:
    W3B = get_val<double>(_W3B, *(pos++));
  case 15:
    W2B = get_val<double>(_W2B, *(pos++));
  case 14:
    W1B = get_val<double>(_W1B, *(pos++));
  case 13:
    W3A = get_val<double>(_W3A, *(pos++));
  case 12:
    W2A = get_val<double>(_W2A, *(pos++));
  case 11:
    W1A = get_val<double>(_W1A, *(pos++));
  case 10:
    PB = get_val<deque<int>>(_PB, *(pos++));
  case 9:
    PA = get_val<deque<int>>(_PA, *(pos++));
  case 8:
    OFFT = get_val<std::string>(_OFFT, *(pos++));
  case 7:
    X3 = get_val<double>(_X3, *(pos++));
  case 6:
    X2 = get_val<double>(_X2, *(pos++));
 case 5:
    try {
      X1 = get_val<double>(_X1, *pos);
      if (!X2 || !X3) {
        throw bdf_parse_error(
          "CBAR", "Incomplete direction vector.");
      }
      G0 = nullptr;
      choose_dir_code = has_DVEC;
    }
    catch (bdf_float_error) {
      G0 = get_val<long>(_G0, *pos);
      X1 = nullptr;
      choose_dir_code = has_DCODE;
    }
    ++pos;
    GB = get_val<long>(_GB, *(pos++));
    GA = get_val<long>(_GA, *(pos++));
    PID = get_val<long>(_PID, *(pos++));
    EID = get_val<long>(_EID, *(pos++));
    break;
  default:
    throw bdf_parse_error(
      "CBAR", "Illegal number of entries.");
  }

  if (!W3B) W3B = get_val<double>(_W3B, "");
  if (!W2B) W2B = get_val<double>(_W2B, "");
  if (!W1B) W1B = get_val<double>(_W1B, "");
  if (!W3A) W3A = get_val<double>(_W3A, "");
  if (!W2A) W2A = get_val<double>(_W2A, "");
  if (!W1A) W1A = get_val<double>(_W2A, "");
  if (!PB) PB = get_val<deque<int>>(_PB, "");
  if (!PA) PA = get_val<deque<int>>(_PA, "");
  if (!OFFT) OFFT = get_val<std::string>(_OFFT, "");
};

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
