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
using namespace ::bdf::cards;
using namespace ::bdf::types;

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
    T4 = get_val<double>(_T4, *(pos++));
  case 13:
    T3 = get_val<double>(_T3, *(pos++));
  case 12:
    T2 = get_val<double>(_T2, *(pos++));
  case 11:
    T1 = get_val<double>(_T1, *(pos++));
  case 10:
    TFLAG = get_val<long>(_TFLAG, *(pos++));
  case 9:
    ++pos;
  case 8:
    ZOFFS = get_val<double>(_ZOFFS, *(pos++));
  case 7:
    try {
      THETA = get_val<double>(_THETA, *pos);
      MCID = nullptr;
      choose_mcid_theta = has_THETA;
    }
    catch (bdf_float_error) {
      try {
        MCID = get_val<long>(_MCID, *pos);
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
    G4 = get_val<long>(_G4, *(pos++));
    G3 = get_val<long>(_G3, *(pos++));
    G2 = get_val<long>(_G2, *(pos++));
    G1 = get_val<long>(_G1, *(pos++));
    PID = get_val<long>(_PID, *(pos++));
    EID = get_val<long>(_EID, *pos);
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
