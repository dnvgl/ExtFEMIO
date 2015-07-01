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

#include <vector>
#include <string>

#include "bdf_cards.h"

using namespace std;
using namespace bdf;
using namespace bdf::cards;

grid::grid(vector<::std::string> inp) :
  _bdf_base_card(),
  ID(types::bdf_int(type_bounds::num<long>(new long(1), new long(100000000)))),
  CP(types::bdf_int(type_bounds::num<long>(new long(1), NULL, new long(-1)))),
  X1(types::bdf_float(type_bounds::num<double>(NULL, NULL, new double(0.)))),
  X2(types::bdf_float(type_bounds::num<double>(NULL, NULL, new double(0.)))),
  X3(types::bdf_float(type_bounds::num<double>(NULL, NULL, new double(0.)))),
  CD(types::bdf_int(type_bounds::num<long>(new long(-1)))),
  PS(types::bdf_list<int>()),
  SEID(types::bdf_int(type_bounds::num<long>(new long(0), NULL, new long(0)))) {
  vector<::std::string> elems = card_split(inp);
  switch (elems.size()) {
  case 8: SEID.parse(elems[7]);
  case 7: PS.parse(elems[6]);
  case 6: CD.parse(elems[5]);
  case 5: X3.parse(elems[4]);
  case 4: X2.parse(elems[3]);
  case 3: X1.parse(elems[2]);
  case 2: CP.parse(elems[1]);
  case 1:
    ID.parse(elems[0]);
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
// compile-command: "make -C .. check -l 7"
// End:
