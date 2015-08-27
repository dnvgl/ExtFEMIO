// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PSHELL cards.

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

#include <memory>

using namespace ::std;
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;
using namespace ::bdf::type_bounds;

entry_type<long> pshell::_PID("PID", ::bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
entry_type<long> pshell::_MID1(
  "MID1",
  ::bdf::type_bounds::bound<long>(make_unique<long>(1).get(), nullptr, nullptr, true));
entry_type<double> pshell::_T(
  "T", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<long> pshell::_MID2(
  "MID2",
  ::bdf::type_bounds::bound<long>(make_unique<long>(-1).get(), nullptr, nullptr, true));
entry_type<double> pshell::_12I_T__3(
  "12I/T**3",
  ::bdf::type_bounds::bound<double>(make_unique<double>(0.).get(), nullptr,
              make_unique<double>(1.).get()));
entry_type<long> pshell::_MID3(
  "MID3",
  ::bdf::type_bounds::bound<long>(make_unique<long>(1).get(), nullptr, nullptr, true));
entry_type<double> pshell::_TS_T(
  "TS/T", ::bdf::type_bounds::bound<double>(make_unique<double>(0.).get(), nullptr,
                      make_unique<double>(.833333).get()));
entry_type<double> pshell::_NSM(
  "NSM", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<double> pshell::_Z1(
  "Z1", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<double> pshell::_Z2(
  "Z2", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<long> pshell::_MID4(
  "MID4", ::bdf::type_bounds::bound<long>(make_unique<long>(1).get(),
                      nullptr, nullptr, true));

pshell::pshell(const deque<::std::string> &inp) : bdf_card(inp) {

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

  switch (inp.size()-1) {
  case 16:
    ++pos;
  case 15:
    ++pos;
  case 14:
    ++pos;
  case 13:
    ++pos;
  case 12:
    ++pos;
  case 11:
    MID4 = get_val<long>(_MID4, *(pos++));
  case 10:
    Z2 = get_val<double>(_Z2, *(pos++));
  case 9:
    Z1 = get_val<double>(_Z1, *(pos++));
  case 8:
    NSM = get_val<double>(_NSM, *(pos++));
  case 7:
    TS_T = get_val<double>(_TS_T, *(pos++));
  case 6:
    MID3 = get_val<long>(_MID3, *(pos++));
  case 5:
    x12I_T__3 = get_val<double>(_12I_T__3, *(pos++));
    MID2 = get_val<long>(_MID2, *(pos++));
    T = get_val<double>(_T, *(pos++));
    MID1 = get_val<long>(_MID1, *(pos++));
    PID = get_val<long>(_PID, *pos);
    break;
  default:
    throw bdf_parse_error("PSHELL", "Illegal number of entries.");
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
