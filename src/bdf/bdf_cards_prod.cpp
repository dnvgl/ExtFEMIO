// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PROD cards.

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
#include "bdf/errors.h"

#include <cstdlib>
#include <memory>

using namespace std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf::cards;
using ::dnvgl::extfem::bdf::types::entry_type;

const entry_type<long> prod::_PID(
  "PID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> prod::_MID(
  "MID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<double> prod::_A("A");
const entry_type<double> prod::_J(
  "J",
  bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> prod::_C(
  "C", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> prod::_NSM(
  "J",
  bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));

prod::prod(const deque<std::string> &inp) : card(inp) {

  auto pos = inp.rbegin();

  J = nullptr;
  C = nullptr;
  NSM = nullptr;

  switch (inp.size()-1) {
  case 8:
    ++pos;
  case 7:
    ++pos;
  case 6:
    NSM = bdf::types::get_val<double>(_NSM, *(pos++));
  case 5:
    C = bdf::types::get_val<double>(_C, *(pos++));
  case 4:
    J = bdf::types::get_val<double>(_J, *(pos++));
  case 3:
    A = bdf::types::get_val<double>(_A, *(pos++));
    MID = bdf::types::get_val<long>(_MID, *(pos++));
    PID = bdf::types::get_val<long>(_PID, *(pos));
    break;
  default:
    throw errors::parse_error(
      "CBAR.", "Illegal number of entries.");
  }

  if (!C) C = bdf::types::get_val<double>(_C, "");
}

const std::ostream& prod::operator << (std::ostream& os) const {
  throw errors::error("can't write PROD.");
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
