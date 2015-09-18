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

using namespace std;
using namespace ::bdf;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<long> bdf_shell::_EID(
  "EID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> bdf_shell::_PID(
  "PID",
  bdf::type_bounds::bound<long>(make_unique<long>(1).get(),
                                  nullptr, nullptr, true));
const entry_type<long> bdf_shell::_G1(
  "G1", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> bdf_shell::_G2(
  "G2", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> bdf_shell::_G3(
  "G3", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> bdf_shell::_G4(
  "G4", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> bdf_shell::_MCID(
  "MCID", bdf::type_bounds::bound<long>(make_unique<long>(0).get()));
const entry_type<double> bdf_shell::_THETA(
  "MCID", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.0).get()));
const entry_type<double> bdf_shell::_ZOFFS(
  "ZOFFS", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.0).get()));
const entry_type<long> bdf_shell::_TFLAG(
  "TFLAG",
  bdf::type_bounds::bound<long>(
    make_unique<long>(0).get(), make_unique<long>(1).get(), 
    make_unique<long>(0).get()));
const entry_type<double> bdf_shell::_T1(
  "T1",
  bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get(), nullptr, nullptr, true));
const entry_type<double> bdf_shell::_T2(
  "T2",
  bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get(), nullptr, nullptr, true));
const entry_type<double> bdf_shell::_T3(
  "T3",
  bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get(), nullptr, nullptr, true));
const entry_type<double> bdf_shell::_T4(
  "T4",
  bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get(), nullptr, nullptr, true));

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
