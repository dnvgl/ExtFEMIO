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
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;

bdf_int grid::_ID(
  bdf_int("ID",
          type_bounds::num<long>(
            make_unique<long>(1).get(),
            make_unique<long>(100000000).get())));
bdf_int grid::_CP(
  bdf_int("CP",
          type_bounds::num<long>(make_unique<long>(1).get(),
                                 nullptr,
                                 make_unique<long>(-1).get())));
bdf_float grid::_X1(
  bdf_float("X1",
            type_bounds::num<double>(nullptr, nullptr,
                                     make_unique<double>(0.).get())));
bdf_float grid::_X2(
  bdf_float("X2",
            type_bounds::num<double>(nullptr, nullptr,
                                     make_unique<double>(0.).get())));
bdf_float grid::_X3(
  bdf_float("X3",
            type_bounds::num<double>(nullptr, nullptr,
                                     make_unique<double>(0.).get())));
bdf_int grid::_CD(
  bdf_int("CD",
          type_bounds::num<long>(make_unique<long>(-1).get(), nullptr,
                                 make_unique<long>(-2).get())));
bdf_list<int> grid::_PS(bdf_list<int>("PS"));
bdf_int grid::_SEID(
  bdf_int("SEID",
          type_bounds::num<long>(make_unique<long>(-1).get(), nullptr,
                                 make_unique<long>(0).get())));


grid::grid(deque<::std::string> inp) : bdf_card() {
  switch (inp.size()) {
  case 8:
    SEID = make_unique<long>(*_SEID(inp.back()));
    inp.pop_back();
  case 7:
    PS = make_unique<deque<int> >(*_PS(inp.back()));
    inp.pop_back();
  case 6:
    CD = make_unique<long>(*_CD(inp.back()));
    inp.pop_back();
  case 5:
    X3 = make_unique<double>(*_X3(inp.back()));
    inp.pop_back();
    X2 = make_unique<double>(*_X2(inp.back()));
    inp.pop_back();
    X1 = make_unique<double>(*_X1(inp.back()));
    inp.pop_back();
    CP = make_unique<long>(*_CP(inp.back()));
    inp.pop_back();
    ID = make_unique<long>(*_ID(inp.back()));
    break;
  default:
    throw "Illegal number of entries for GRID\n";
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
