// Copyright © 2015 by DNV GL SE

// Purpose: Defintions for Patran CBEAM cards.

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

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<long> cbeam::_EID("EID",
                    bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> cbeam::_PID("PID");
const entry_type<long> cbeam::_GA("GA");
const entry_type<long> cbeam::_GB("GB");
const entry_type<double> cbeam::_X1("X1");
const entry_type<long> cbeam::_G0(
  "G0", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<double> cbeam::_X2(
  "X2", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> cbeam::_X3(
  "X3", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> cbeam::_BIT("BIT");
namespace {
  const char* OFFTinit[8] = {
    "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO" };
  const std::set<std::string> OFFT_set(OFFTinit, OFFTinit + 8);
}
const entry_type<std::string> cbeam::_OFFT("OFFT", bdf::type_bounds::bound<std::string>(OFFT_set, "GGG"));

const entry_type<deque<int>> cbeam::_PA("PA"); // maxelem=5, minval=1, maxval=6, uniq=True);
const entry_type<deque<int>> cbeam::_PB("PB"); // maxelem=5, minval=1, maxval=6, uniq=True);
const entry_type<double> cbeam::_W1A(
  "W1A",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
const entry_type<double> cbeam::_W2A(
  "W2A",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
const entry_type<double> cbeam::_W3A(
  "W3A",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
const entry_type<double> cbeam::_W1B(
  "W1B",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
const entry_type<double> cbeam::_W2B(
  "W2B",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
const entry_type<double> cbeam::_W3B(
  "W3B",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get())); // default=0.),
const entry_type<long> cbeam::_SA(
  "SA",
  bdf::type_bounds::bound<long>(make_unique<long>(1).get(), nullptr, nullptr, true)); // minval=1, default=None)
const entry_type<long> cbeam::_SB(
  "SB",
  bdf::type_bounds::bound<long>(make_unique<long>(1).get(), nullptr, nullptr, true)); // minval=1, default=None)

cbeam::cbeam(const deque<std::string> &inp) :
  card(inp) {

  auto pos = inp.rbegin();

  SB = nullptr;
  SA = nullptr;
  W3B = get_val<double>(_W3B, "");
  W2B = get_val<double>(_W2B, "");
  W1B = get_val<double>(_W1B, "");
  W3A = get_val<double>(_W3A, "");
  W2A = get_val<double>(_W2A, "");
  W1A = get_val<double>(_W1A, "");
  PB = nullptr;
  PA = nullptr;
  OFFT = nullptr;
  BIT = nullptr;

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
    SB = get_val<long>(_SB, *(pos++));
  case 17:
    SA = get_val<long>(_SA, *(pos++));
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
    try {
      BIT = get_val<double>(_BIT, *(pos));
      OFFT = nullptr;
      choose_offt_bit = has_BIT;
    }
    catch (bdf_float_error) {
      OFFT = get_val<std::string>(_OFFT, *pos);
      BIT = nullptr;
      choose_offt_bit = has_OFFT;
    }
    ++pos;
  case 7:
    X3 = get_val<double>(_X3, *(pos++));
  case 6:
    X2 = get_val<double>(_X2, *(pos++));
  case 5:
    try {
      X1 = get_val<double>(_X1, *(pos));
      if (!X2 || !X3) {
        throw bdf_parse_error(
          "CBEAM", "Incomplete direction vector.");
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
      "CBEAM", "Illegal number of entries for CBEAM");
  }

  if (!W3B) W3B = get_val<double>(_W3B, "");
  if (!W2B) W2B = get_val<double>(_W2B, "");
  if (!W1B) W1B = get_val<double>(_W1B, "");
  if (!W3A) W3A = get_val<double>(_W3A, "");
  if (!W2A) W2A = get_val<double>(_W2A, "");
  if (!W1A) W1A = get_val<double>(_W1A, "");
  if (!PB) PB = get_val<deque<int>>(_PB, "");
  if (!PA) PA = get_val<deque<int>>(_PA, "");
  if (!BIT && !OFFT) OFFT = get_val<std::string>(_OFFT, "");
};

const std::ostream& cbeam::operator << (std::ostream& os) const {
  throw bdf_error("can't write CBEAM.");
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
