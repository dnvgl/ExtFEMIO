// Copyright © 2015 by DNV GL SE

// Purpose: Common definitions for Nastran BDF CTRIA3 and CQUAD4 cards.

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

using namespace ::std;
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;
using namespace ::bdf::type_bounds;

bdf_int bdf_shell::_EID("EID", num<long>(make_unique<long>(1).get()));
bdf_int bdf_shell::_PID(
  "PID", num<long>(make_unique<long>(1).get(), nullptr, nullptr, true));
bdf_int bdf_shell::_G1("G1", num<long>(make_unique<long>(1).get()));
bdf_int bdf_shell::_G2("G2", num<long>(make_unique<long>(1).get()));
bdf_int bdf_shell::_G3("G3", num<long>(make_unique<long>(1).get()));
bdf_int bdf_shell::_MCID("MCID", num<long>(make_unique<long>(0).get()));
bdf_float bdf_shell::_THETA(
  "MCID", num<double>(nullptr, nullptr, make_unique<double>(0.0).get()));
bdf_float bdf_shell::_ZOFFS(
  "ZOFFS", num<double>(nullptr, nullptr, make_unique<double>(0.0).get()));
bdf_int bdf_shell::_TFLAG(
  "TFLAG",
  num<long>(make_unique<long>(1).get(), make_unique<long>(2).get(), nullptr, true));
bdf_float bdf_shell::_T1(
  "T1", num<double>(make_unique<double>(0.).get(), nullptr, nullptr, true));
bdf_float bdf_shell::_T2(
  "T2", num<double>(make_unique<double>(0.).get(), nullptr, nullptr, true));
bdf_float bdf_shell::_T3(
  "T3", num<double>(make_unique<double>(0.).get(), nullptr, nullptr, true));


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
