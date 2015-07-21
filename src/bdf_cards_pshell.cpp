// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PSHELL cards.

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

bdf_int pshell::_PID("PID", num<long>(make_unique<long>(1).get()));
bdf_int pshell::_MID1(
  "MID1",
  num<long>(make_unique<long>(1).get(), nullptr, nullptr, true));
bdf_float pshell::_T(
  "T", num<double>(nullptr, nullptr, nullptr, true));
bdf_int pshell::_MID2(
  "MID2",
  num<long>(make_unique<long>(-1).get(), nullptr, nullptr, true));
bdf_float pshell::_12I_T__3(
  "12I/T**3",
  num<double>(make_unique<double>(0.).get(), nullptr,
              make_unique<double>(1.).get()));
bdf_int pshell::_MID3(
  "MID3",
  num<long>(make_unique<long>(1).get(), nullptr, nullptr, true));
bdf_float pshell::_TS_T(
  "TS/T", num<double>(make_unique<double>(0.).get(), nullptr,
                      make_unique<double>(.833333).get()));
bdf_float pshell::_NSM(
  "NSM", num<double>(nullptr, nullptr, nullptr, true));
bdf_float pshell::_Z1(
  "Z1", num<double>(nullptr, nullptr, nullptr, true));
bdf_float pshell::_Z2(
  "Z2", num<double>(nullptr, nullptr, nullptr, true));
bdf_int pshell::_MID4(
  "MID4", num<long>(make_unique<long>(1).get(),
                      nullptr, nullptr, true));



pshell::pshell(const deque<::std::string> &inp) : bdf_card(inp) {

  long *l_ptr;
  double *d_ptr;

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

  switch (inp.size()-1) {
  case 16:
    ++pos;
  case 15:
    ++pos;
  case 14:
    ++pos;
  case 13:
    ++pos;
  case 12:
    ++pos;
  case 11:
    l_ptr = _MID4(*pos);
    MID4 = (l_ptr == nullptr) ? nullptr : make_unique<long>(*l_ptr);
    ++pos;
  case 10:
    d_ptr = _Z2(*pos);
    Z2 = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    ++pos;
  case 9:
    d_ptr = _Z1(*pos);
    Z1 = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    ++pos;
  case 8:
    d_ptr = _NSM(*pos);
    NSM = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    ++pos;
    d_ptr = _TS_T(*pos);
    TS_T = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    ++pos;
    l_ptr = _MID3(*pos);
    MID3 = (l_ptr == nullptr) ? nullptr : make_unique<long>(*l_ptr);
    ++pos;
    d_ptr = _12I_T__3(*pos);
    x12I_T__3 = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    ++pos;
    l_ptr = _MID2(*pos);
    MID2 = (l_ptr == nullptr) ? nullptr : make_unique<long>(*l_ptr);
    ++pos;
    d_ptr = _T(*pos);
    T = (d_ptr == nullptr) ? nullptr : make_unique<double>(*d_ptr);
    ++pos;
    l_ptr = _MID1(*pos);
    MID1 = (l_ptr == nullptr) ? nullptr : make_unique<long>(*l_ptr);
    ++pos;
    l_ptr = _PID(*pos);
    PID = (l_ptr == nullptr) ? nullptr : make_unique<long>(*l_ptr);
    break;
  default:
    throw "Illegal number of entries for PSHELL\n";
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
