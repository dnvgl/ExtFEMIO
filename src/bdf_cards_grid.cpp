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

#include "bdf_cards.h"
#include "bdf_types.h"

using namespace ::std;
using namespace ::bdf::cards;
using namespace ::bdf::types;

entry_type<long> grid::_ID(
  "ID",
  ::bdf::type_bounds::bound<long>(make_unique<long>(1).get(),
            make_unique<long>(100000000).get()));
entry_type<long> grid::_CP(
  "CP", ::bdf::type_bounds::bound<long>(make_unique<long>(1).get(),
                               nullptr,
                               make_unique<long>(-1).get()));
entry_type<double> grid::_X1(
  "X1",
  ::bdf::type_bounds::bound<double>(nullptr, nullptr, make_unique<double>(0.).get()));
entry_type<double> grid::_X2(
  "X2",
  ::bdf::type_bounds::bound<double>(nullptr, nullptr,
              make_unique<double>(0.).get()));
entry_type<double> grid::_X3(
  "X3",
  ::bdf::type_bounds::bound<double>(nullptr, nullptr,
              make_unique<double>(0.).get()));
entry_type<long> grid::_CD(
  "CD",
  ::bdf::type_bounds::bound<long>(make_unique<long>(-1).get(), nullptr,
            make_unique<long>(-2).get()));
entry_type<::std::deque<int>> grid::_PS("PS");
entry_type<long> grid::_SEID(
  "SEID",
  ::bdf::type_bounds::bound<long>(make_unique<long>(-1).get(), nullptr,
            make_unique<long>(0).get()));


grid::grid(const deque<::std::string> &inp) : bdf_card(inp) {

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

  switch (inp.size()-1) {
  case 8:
    SEID = get_val<long>(_SEID, *(pos++));
  case 7:
    PS = get_val<::std::deque<int> >(_PS, *(pos++));
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
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
