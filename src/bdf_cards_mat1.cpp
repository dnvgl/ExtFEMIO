// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF MAT1 cards.

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

bdf_int mat1::_MID(
  bdf_int("MID",
          type_bounds::num<long>(make_unique<long>(1).get())));
bdf_float mat1::_E(
  bdf_float("E",
            type_bounds::num<double>(make_unique<double>(0.).get())));
bdf_float mat1::_G(
  bdf_float("G",
            type_bounds::num<double>(make_unique<double>(0.).get())));
bdf_float mat1::_NU(
  bdf_float("NU",
            type_bounds::num<double>(make_unique<double>(-1.).get(),
                                     make_unique<double>(.5).get())));
bdf_float mat1::_RHO(bdf_float("RHO"));
bdf_float mat1::_A(bdf_float("A"));
bdf_float mat1::_TREF(bdf_float("TREF"));
bdf_float mat1::_GE(bdf_float("GE"));
bdf_float mat1::_ST(bdf_float("ST"));
bdf_float mat1::_SC(
  bdf_float("SC",
            type_bounds::num<double>(make_unique<double>(0.).get())));
bdf_float mat1::_SS(
  bdf_float("SS",
            type_bounds::num<double>(make_unique<double>(0.).get())));
bdf_int mat1::_MCSID(
  bdf_int("MCSID",
          type_bounds::num<long>(make_unique<long>(0).get())));

mat1::mat1(deque<::std::string> inp) :
  bdf_card() {
  switch (inp.size()) {
  case 16:
    inp.pop_back();
  case 15:
    inp.pop_back();
  case 14:
    inp.pop_back();
  case 13:
    inp.pop_back();
  case 12:
    MCSID = make_unique<long>(*_MCSID(inp.back()));
    inp.pop_back();
  case 11:
    SS = make_unique<double>(*_SS(inp.back()));
    inp.pop_back();
  case 10:
    SC = make_unique<double>(*_SC(inp.back()));
    inp.pop_back();
  case 9:
    ST = make_unique<double>(*_ST(inp.back()));
    inp.pop_back();
  case 8:
    GE = make_unique<double>(*_GE(inp.back()));
    inp.pop_back();
  case 7:
    TREF = make_unique<double>(*_TREF(inp.back()));
    inp.pop_back();
  case 6:
    A = make_unique<double>(*_A(inp.back()));
    inp.pop_back();
  case 5:
    RHO = make_unique<double>(*_RHO(inp.back()));
    inp.pop_back();
  case 4:
    NU = make_unique<double>(*_NU(inp.back()));
    inp.pop_back();
  case 3:
    G = make_unique<double>(*_G(inp.back()));
    inp.pop_back();
  case 2:
    E = make_unique<double>(*_E(inp.back()));
    inp.pop_back();
  case 1:
    MID = make_unique<long>(*_MID(inp.back()));
    break;
  default:
    throw "Illegal number of entries for MID1\n";
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
