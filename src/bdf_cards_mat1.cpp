// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF MAT1 cards.

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

using namespace ::std;
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;

bdf_int mat1::_MID(
  bdf_int("MID", type_bounds::num<long>(new long(1))));
bdf_float mat1::_E(
  bdf_float("E", type_bounds::num<double>(new double(0.))));
bdf_float mat1::_G(
  bdf_float("G", type_bounds::num<double>(new double(0.))));
bdf_float mat1::_NU(
  bdf_float(
    "NU", type_bounds::num<double>(new double(-1.), new double(.5))));
bdf_float mat1::_RHO(bdf_float("RHO"));
bdf_float mat1::_A(bdf_float("A"));
bdf_float mat1::_TREF(bdf_float("TREF"));
bdf_float mat1::_GE(bdf_float("GE"));
bdf_float mat1::_ST(bdf_float("ST"));
bdf_float mat1::_SC(
  bdf_float("SC", type_bounds::num<double>(new double(0.))));
bdf_float mat1::_SS(
  bdf_float("SS", type_bounds::num<double>(new double(0.))));
bdf_int mat1::_MCSID(
  bdf_int("MCSID", type_bounds::num<long>(new long(0))));

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
    MCSID = _MCSID.parse(inp.back());
    inp.pop_back();
  case 11:
    SS = _SS.parse(inp.back());
    inp.pop_back();
  case 10:
    SC = _SC.parse(inp.back());
    inp.pop_back();
  case 9:
    ST = _ST.parse(inp.back());
    inp.pop_back();
  case 8:
    GE = _GE.parse(inp.back());
    inp.pop_back();
  case 7:
    TREF = _TREF.parse(inp.back());
    inp.pop_back();
  case 6:
    A = _A.parse(inp.back());
    inp.pop_back();
  case 5:
    RHO = _RHO.parse(inp.back());
    inp.pop_back();
  case 4:
    NU = _NU.parse(inp.back());
    inp.pop_back();
  case 3:
    G = _G.parse(inp.back());
    inp.pop_back();
  case 2:
    E = _E.parse(inp.back());
    inp.pop_back();
  case 1:
    MID = _MID.parse(inp.back());
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
