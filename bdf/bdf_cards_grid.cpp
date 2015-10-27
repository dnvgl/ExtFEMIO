// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF GRID cards.

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

#include <deque>
#include <string>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<long> grid::_ID(
  "ID",
  bdf::type_bounds::bound<long>(make_unique<long>(1).get(),
            make_unique<long>(100000000).get()));
const entry_type<long> grid::_CP(
  "CP", bdf::type_bounds::bound<long>(make_unique<long>(1).get(),
                               nullptr,
                               make_unique<long>(-1).get()));
const entry_type<double> grid::_X1(
  "X1",
  bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
const entry_type<double> grid::_X2(
  "X2",
  bdf::type_bounds::bound<double>(nullptr, nullptr,
              make_unique<double>(0.).get()));
const entry_type<double> grid::_X3(
  "X3",
  bdf::type_bounds::bound<double>(nullptr, nullptr,
              make_unique<double>(0.).get()));
const entry_type<long> grid::_CD(
  "CD",
  bdf::type_bounds::bound<long>(make_unique<long>(-1).get(), nullptr,
            make_unique<long>(-2).get()));
const entry_type<std::deque<int>> grid::_PS("PS");
const entry_type<long> grid::_SEID(
  "SEID",
  bdf::type_bounds::bound<long>(make_unique<long>(-1).get(), nullptr,
            make_unique<long>(0).get()));


grid::grid(const deque<std::string> &inp) : card(inp) {

  auto pos = inp.rbegin();


  SEID = nullptr;
  PS = nullptr;
  CD = nullptr;

  switch (inp.size()-1) {
  case 8:
    SEID = get_val<long>(_SEID, *(pos++));
  case 7:
    PS = get_val<std::deque<int> >(_PS, *(pos++));
  case 6:
    CD = get_val<long>(_CD, *(pos++));
  case 5:
    X3 = get_val<double>(_X3, *(pos++));
    X2 = get_val<double>(_X2, *(pos++));
    X1 = get_val<double>(_X1, *(pos++));
    CP = get_val<long>(_CP, *(pos++));
    ID = get_val<long>(_ID, *pos);
    break;
  default:
    throw bdf_parse_error("GRID", "Illegal number of entries.");
  }

  if (!SEID) SEID = get_val<long>(_SEID, "");
}

grid::grid(long &_ID, long &_CP, double &_X1, double &_X2, double &_X3) : card() {
  ID = make_unique<long>(_ID);
  CP = make_unique<long>(_CP);
  X1 = make_unique<double>(_X1);
  X2 = make_unique<double>(_X2);
  X3 = make_unique<double>(_X3);
  CD = nullptr;
  PS = nullptr;
  SEID = nullptr;
}

const std::ostream& grid::operator << (std::ostream& os) const {
  throw bdf_error("can't write GRID.");
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
