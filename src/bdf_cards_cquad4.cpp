// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF CQUAD4 cards.

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

#include "bdf_cards.h"

#include <memory>

using namespace ::std;
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;

bdf_int cquad4::_G4(bdf_int("G4", type_bounds::num<long>(make_unique<long>(1).get())));
bdf_float cquad4::_T4(
  bdf_float("T4", type_bounds::num<double>(
              make_unique<double>(0.).get(), nullptr, nullptr, true)));

cquad4::cquad4(deque<::std::string> inp) : bdf_shell() {
  switch (inp.size()) {
  case 16:
    inp.pop_back();
  case 15:
    inp.pop_back();
  case 14:
    T4 = make_unique<double>(*_T4(inp.back()));
    inp.pop_back();
  case 13:
    T3 = make_unique<double>(*_T3(inp.back()));
    inp.pop_back();
  case 12:
    T2 = make_unique<double>(*_T2(inp.back()));
    inp.pop_back();
  case 11:
    T1 = make_unique<double>(*_T1(inp.back()));
    inp.pop_back();
  case 10:
    TFLAG = make_unique<long>(*_TFLAG(inp.back()));
    inp.pop_back();
  case 9:
    inp.pop_back();
  case 8:
    ZOFFS = make_unique<double>(*_ZOFFS(inp.back()));
    inp.pop_back();
  case 7:
    try {
      THETA = make_unique<double>(*_THETA(inp.back()));
      MCID = nullptr;
      choose_mcid_theta = has_THETA;
    }
    catch (bdf_float_error) {
      try {
        MCID = make_unique<long>(*_MCID(inp.back()));
        THETA = nullptr;
        choose_mcid_theta = has_MCID;
      }
      catch (bdf_int_error) {
        THETA = make_unique<double>(0.0);
        MCID = nullptr;
        choose_mcid_theta = has_THETA;
      }
    }
    inp.pop_back();
  case 6:
    G4 = make_unique<long>(*_G4(inp.back()));
    inp.pop_back();
  case 5:
    G3 = make_unique<long>(*_G3(inp.back()));
    inp.pop_back();
  case 4:
    G2 = make_unique<long>(*_G2(inp.back()));
    inp.pop_back();
  case 3:
    G1 = make_unique<long>(*_G1(inp.back()));
    inp.pop_back();
  case 2:
    PID = make_unique<long>(*_PID(inp.back()));
    inp.pop_back();
  case 1:
    EID = make_unique<long>(*_EID(inp.back()));
    break;
  default:
    throw "Illegal number of entries for CQUAD4\n";
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
