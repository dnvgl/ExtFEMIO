// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF CTRIA3 cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "StdAfx.h"

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/errors.h"

#include <memory>

using namespace std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf::cards;
using bdf::types::entry_type;


ctria3::ctria3(const deque<std::string> &inp) : base_shell(inp) {

  auto pos = inp.rbegin();

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
    ++pos;
  case 13:
    T3 = bdf::types::get_val<double>(_T3, *pos);
    T4 = bdf::types::get_val<double>(_T4, *(pos++));
  case 12:
    T2 = bdf::types::get_val<double>(_T2, *(pos++));
  case 11:
    T1 = bdf::types::get_val<double>(_T1, *(pos++));
  case 10:
    TFLAG = bdf::types::get_val<long>(_TFLAG, *(pos++));
  case 9:
    ++pos;
  case 8:
    ++pos;
  case 7:
    ZOFFS = bdf::types::get_val<double>(_ZOFFS, *(pos++));
  case 6:
    try {
      THETA = bdf::types::get_val<double>(_THETA, *pos);
      MCID = nullptr;
      choose_mcid_theta = has_THETA;
    }
    catch (errors::float_error) {
      try {
        MCID = bdf::types::get_val<long>(_MCID, *pos);
        THETA = nullptr;
        choose_mcid_theta = has_MCID;
      }
      catch (errors::int_error) {
        THETA = make_unique<double>(0.0);
        MCID = nullptr;
        choose_mcid_theta = has_THETA;
      }
    }
    ++pos;
  case 5:
    G3 = bdf::types::get_val<long>(_G3, *pos);
    G4 = bdf::types::get_val<long>(_G4, *(pos++));
    G2 = bdf::types::get_val<long>(_G2, *(pos++));
    G1 = bdf::types::get_val<long>(_G1, *(pos++));
    PID = bdf::types::get_val<long>(_PID, *(pos++));
    EID = bdf::types::get_val<long>(_EID, *pos);
    break;
  default:
    throw errors::parse_error("CTRIA3", "Illegal number of entries.");
  }

  if (!THETA && !MCID)
    THETA = bdf::types::get_val<double>(_THETA, "");
  if (TFLAG) {
    if (!T1) T1 = bdf::types::get_val<double>(_T1, "");
    if (!T2) T2 = bdf::types::get_val<double>(_T2, "");
    if (!T3) T3 = bdf::types::get_val<double>(_T3, "");
    if (!T4) T4 = bdf::types::get_val<double>(_T4, "");
  }

}

const std::ostream& ctria3::operator << (std::ostream& os) const {
  throw errors::error("can't write cbeam.");
  return os;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
