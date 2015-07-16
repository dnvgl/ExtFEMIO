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

bdf_int bdf_shell::_EID(
  bdf_int("EID", type_bounds::num<long>(make_unique<long>(1).get())));
bdf_int bdf_shell::_PID(
  bdf_int("PID",
          type_bounds::num<long>(make_unique<long>(1).get(), nullptr, nullptr, true)));
bdf_int bdf_shell::_G1(bdf_int("G1", type_bounds::num<long>(make_unique<long>(1).get())));
bdf_int bdf_shell::_G2(bdf_int("G2", type_bounds::num<long>(make_unique<long>(1).get())));
bdf_int bdf_shell::_G3(bdf_int("G3", type_bounds::num<long>(make_unique<long>(1).get())));
bdf_int bdf_shell::_MCID(bdf_int("MCID", type_bounds::num<long>(make_unique<long>(0).get())));
bdf_float bdf_shell::_THETA(
  bdf_float("MCID", type_bounds::num<double>(nullptr, nullptr, make_unique<double>(0.0).get())));
bdf_float bdf_shell::_ZOFFS(bdf_float("ZOFFS", type_bounds::num<double>(nullptr, nullptr, make_unique<double>(0.0).get())));
bdf_int bdf_shell::_TFLAG(
  bdf_int("TFLAG",
          type_bounds::num<long>(make_unique<long>(1).get(), make_unique<long>(2).get(), nullptr, true)));
bdf_float bdf_shell::_T1(
  bdf_float("T1", type_bounds::num<double>(
              make_unique<double>(0.).get(), nullptr, nullptr, true)));
bdf_float bdf_shell::_T2(
  bdf_float("T2", type_bounds::num<double>(
              make_unique<double>(0.).get(), nullptr, nullptr, true)));
bdf_float bdf_shell::_T3(
  bdf_float("T3", type_bounds::num<double>(
              make_unique<double>(0.).get(), nullptr, nullptr, true)));


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
