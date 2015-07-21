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
using namespace ::bdf::type_bounds;

cquad4::cquad4(const deque<::std::string> &inp) : bdf_shell(inp) {

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

  THETA = nullptr;
  MCID = nullptr;
  ZOFFS = nullptr;
  TFLAG = nullptr;
  T1 = nullptr;
  T2 = nullptr;
  T3 = nullptr;
  T4 = nullptr;

  switch (inp.size()-1) {
  case 16:
    ++pos;
  case 15:
    ++pos;
  case 14:
    T4 = make_unique<double>(*_T4(*pos));
    ++pos;
  case 13:
    T3 = make_unique<double>(*_T3(*pos));
    ++pos;
  case 12:
    T2 = make_unique<double>(*_T2(*pos));
    ++pos;
  case 11:
    T1 = make_unique<double>(*_T1(*pos));
    ++pos;
  case 10:
    TFLAG = make_unique<long>(*_TFLAG(*pos));
    ++pos;
  case 9:
    ++pos;
  case 8:
    ZOFFS = make_unique<double>(*_ZOFFS(*pos));
    ++pos;
  case 7:
    try {
      THETA = make_unique<double>(*_THETA(*pos));
      MCID = nullptr;
      choose_mcid_theta = has_THETA;
    }
    catch (bdf_float_error) {
      try {
        MCID = make_unique<long>(*_MCID(*pos));
        THETA = nullptr;
        choose_mcid_theta = has_MCID;
      }
      catch (bdf_int_error) {
        THETA = make_unique<double>(0.0);
        MCID = nullptr;
        choose_mcid_theta = has_THETA;
      }
    }
    ++pos;
  case 6:
    G4 = make_unique<long>(*_G4(*pos));
    ++pos;
    G3 = make_unique<long>(*_G3(*pos));
    ++pos;
    G2 = make_unique<long>(*_G2(*pos));
    ++pos;
    G1 = make_unique<long>(*_G1(*pos));
    ++pos;
    PID = make_unique<long>(*_PID(*pos));
    ++pos;
    EID = make_unique<long>(*_EID(*pos));
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
