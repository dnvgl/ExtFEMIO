// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF GRID cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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

using namespace std;
using namespace bdf;
using namespace bdf::cards;

grid::grid(deque<::std::string> inp) :
  bdf_card(),
  ID(::bdf::types::bdf_int("ID", type_bounds::num<long>(new long(1), new long(100000000)))),
  CP(::bdf::types::bdf_int("CP", type_bounds::num<long>(new long(1), NULL, new long(-1)))),
  X1(::bdf::types::bdf_float("X1", type_bounds::num<double>(NULL, NULL, new double(0.)))),
  X2(::bdf::types::bdf_float("X2", type_bounds::num<double>(NULL, NULL, new double(0.)))),
  X3(::bdf::types::bdf_float("X3", type_bounds::num<double>(NULL, NULL, new double(0.)))),
  CD(::bdf::types::bdf_int("CD", type_bounds::num<long>(new long(-1), NULL, new long(-2)))),
  PS(::bdf::types::bdf_list<int>("PS")),
  SEID(::bdf::types::bdf_int("SEID", type_bounds::num<long>(new long(0), NULL, new long(0)))) {
  switch (inp.size()) {
  case 8:
    SEID.parse(inp.back());
    inp.pop_back();
  case 7:
    PS.parse(inp.back());
    inp.pop_back();
  case 6:
    CD.parse(inp.back());
    inp.pop_back();
  case 5:
    X3.parse(inp.back());
    inp.pop_back();
    X2.parse(inp.back());
    inp.pop_back();
    X1.parse(inp.back());
    inp.pop_back();
    CP.parse(inp.back());
    inp.pop_back();
    ID.parse(inp.back());
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
// compile-command: "make -C .. check -j 7"
// End:
