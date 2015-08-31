// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PROD cards.

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

using namespace ::std;
using namespace ::bdf::cards;
using namespace ::bdf::types;

const entry_type<long> prod::_PID(
  "PID", ::bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> prod::_MID(
  "MID", ::bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<double> prod::_A("A");
const entry_type<double> prod::_J(
  "J",
  ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> prod::_C(
  "C", ::bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> prod::_NSM(
  "J",
  ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));

prod::prod(const deque<::std::string> &inp) : bdf_card(inp) {

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

  J = nullptr;
  C = make_unique<double>(0.);
  NSM = nullptr;

  switch (inp.size()-1) {
  case 8:
    ++pos;
  case 7:
    ++pos;
  case 6:
    NSM = get_val<double>(_NSM, *(pos++));
  case 5:
    C = get_val<double>(_C, *(pos++));
  case 4:
    J = get_val<double>(_J, *(pos++));
  case 3:
    A = get_val<double>(_A, *(pos++));
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
