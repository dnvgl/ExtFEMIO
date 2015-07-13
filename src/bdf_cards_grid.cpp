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

#include "bdf_cards.h"

using namespace ::std;
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;

bdf_int grid::_ID(
  bdf_int("ID",
          type_bounds::num<long>(new long(1), new long(100000000))));
bdf_int grid::_CP(
  bdf_int("CP",
          type_bounds::num<long>(new long(1), NULL, new long(-1))));
bdf_float grid::_X1(
  bdf_float("X1",
            type_bounds::num<double>(NULL, NULL, new double(0.))));
bdf_float grid::_X2(
  bdf_float("X2",
            type_bounds::num<double>(NULL, NULL, new double(0.))));
bdf_float grid::_X3(
  bdf_float("X3",
            type_bounds::num<double>(NULL, NULL, new double(0.))));
bdf_int grid::_CD(
  bdf_int("CD",
          type_bounds::num<long>(new long(-1), NULL, new long(-2))));
bdf_list<int> grid::_PS(bdf_list<int>("PS"));
bdf_int grid::_SEID(
  bdf_int("SEID",
          type_bounds::num<long>(new long(0), NULL, new long(0))));


grid::grid(deque<::std::string> inp) :
  bdf_card() {
  switch (inp.size()) {
  case 8:
    SEID = _SEID.parse(inp.back());
    inp.pop_back();
  case 7:
    PS = _PS.parse(inp.back());
    inp.pop_back();
  case 6:
    CD = _CD.parse(inp.back());
    inp.pop_back();
  case 5:
    X3 = _X3.parse(inp.back());
    inp.pop_back();
    X2 = _X2.parse(inp.back());
    inp.pop_back();
    X1 = _X1.parse(inp.back());
    inp.pop_back();
    CP = _CP.parse(inp.back());
    inp.pop_back();
    ID = _ID.parse(inp.back());
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
