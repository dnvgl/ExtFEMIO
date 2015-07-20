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
bdf_float mat1::_RHO(
  bdf_float("RHO",
            type_bounds::num<double>(nullptr, nullptr, nullptr, true)));
bdf_float mat1::_A(
  bdf_float("A",
            type_bounds::num<double>(nullptr, nullptr, nullptr, true)));
bdf_float mat1::_TREF(
  bdf_float("TREF",
            type_bounds::num<double>(nullptr, nullptr, nullptr, true)));
bdf_float mat1::_GE(
  bdf_float("GE",
            type_bounds::num<double>(nullptr, nullptr, nullptr, true)));
bdf_float mat1::_ST(
  bdf_float("ST",
            type_bounds::num<double>(nullptr, nullptr, nullptr, true)));
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
  long *l_ptr;
  double *d_ptr;

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
    l_ptr = _MCSID(inp.back());
    MCSID = (l_ptr == nullptr) ? nullptr : make_unique<long>(*l_ptr);
    inp.pop_back();
  case 11:
    d_ptr = _SS(inp.back());
    SS = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    inp.pop_back();
  case 10:
    d_ptr = _SC(inp.back());
    SC = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    inp.pop_back();
  case 9:
    d_ptr = _ST(inp.back());
    ST = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    inp.pop_back();
  case 8:
    d_ptr = _GE(inp.back());
    GE = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    inp.pop_back();
  case 7:
    d_ptr = _TREF(inp.back());
    TREF = (d_ptr == nullptr) ? nullptr :  make_unique<double>(*d_ptr);
    inp.pop_back();
  case 6:
    d_ptr = _A(inp.back());
    A = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    inp.pop_back();
  case 5:
    d_ptr = _RHO(inp.back());
    RHO = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
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
