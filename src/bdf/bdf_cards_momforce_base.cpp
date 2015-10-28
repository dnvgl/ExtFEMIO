// Copyright © 2015 by DNV GL SE

// Purpose: Common definitions for Nastran BDF FORCE and MOMENT cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<long> momforce_base::_SID(
  "SID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> momforce_base::_G(
  "G", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> momforce_base::_CID(
  "CID", bdf::type_bounds::bound<long>(
    make_unique<long>(0).get(), nullptr, make_unique<long>(0).get()));
const entry_type<double> momforce_base::_F("F");
const entry_type<double> momforce_base::_N1(
  "N1",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> momforce_base::_N2(
  "N2",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> momforce_base::_N3(
  "N3",
  bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));

momforce_base::momforce_base(const std::deque<std::string> &inp) :
  card(inp) {

  auto pos = inp.rbegin();

  SID = nullptr;
  G = nullptr;
  CID = nullptr;
  F = nullptr;
  N1 = nullptr;
  N2 = nullptr;
  N3 = nullptr;

  switch (inp.size()-1) {
  case 8:
    ++pos;
  case 7:
    N3 = get_val<double>(_N3, *(pos++));
  case 6:
    N2 = get_val<double>(_N2, *(pos++));
  case 5:
    N1 = get_val<double>(_N1, *(pos++));
    if (*N1 == 0. && *N2 == 0. && *N3 == 0.) {
      throw bdf_parse_error(
        "FORCE", "At least one of N1, N2, and N3 has to be != 0..");
    }
    F = get_val<double>(_F, *(pos++));
    CID = get_val<long>(_CID, *(pos++));
    G = get_val<long>(_G, *(pos++));
    SID = get_val<long>(_SID, *(pos++));
    break;
  default:
    throw bdf_parse_error("FORCE", "Illegal number of entries.");
  }
}

momforce_base::momforce_base(long &SID, long &G, long &CID,
                             double &F,
                             double &N1, double &N2, double &N3) {};

const std::ostream& momforce_base::operator << (std::ostream& os) const {
  return os;
}

const std::ostream& force::operator << (std::ostream& os) const {
  return os;
}

const std::ostream& moment::operator << (std::ostream& os) const {
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
