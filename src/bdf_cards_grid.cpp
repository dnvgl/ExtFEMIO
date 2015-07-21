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
using namespace ::bdf::type_bounds;

bdf_int grid::_ID(
  "ID",
  num<long>(make_unique<long>(1).get(),
            make_unique<long>(100000000).get()));
bdf_int grid::_CP(
  "CP", num<long>(make_unique<long>(1).get(),
                               nullptr,
                               make_unique<long>(-1).get()));
bdf_float grid::_X1(
  "X1",
  num<double>(nullptr, nullptr, make_unique<double>(0.).get()));
bdf_float grid::_X2(
  "X2",
  num<double>(nullptr, nullptr,
              make_unique<double>(0.).get()));
bdf_float grid::_X3(
  "X3",
  num<double>(nullptr, nullptr,
              make_unique<double>(0.).get()));
bdf_int grid::_CD(
  "CD",
  num<long>(make_unique<long>(-1).get(), nullptr,
            make_unique<long>(-2).get()));
bdf_list<int> grid::_PS("PS");
bdf_int grid::_SEID(
  "SEID",
  num<long>(make_unique<long>(-1).get(), nullptr,
            make_unique<long>(0).get()));


grid::grid(const deque<::std::string> &inp) : bdf_card(inp) {

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

  switch (inp.size()-1) {
  case 8:
    SEID = make_unique<long>(*_SEID(*pos));
    ++pos;
  case 7:
    PS = make_unique<deque<int> >(*_PS(*pos));
    ++pos;
  case 6:
    CD = make_unique<long>(*_CD(*pos));
    ++pos;
  case 5:
    X3 = make_unique<double>(*_X3(*pos));
    ++pos;
    X2 = make_unique<double>(*_X2(*pos));
    ++pos;
    X1 = make_unique<double>(*_X1(*pos));
    ++pos;
    CP = make_unique<long>(*_CP(*pos));
    ++pos;
    ID = make_unique<long>(*_ID(*pos));
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
