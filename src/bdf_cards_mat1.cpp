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
using namespace ::bdf::type_bounds;

entry_type<long> mat1::_MID(
  "MID", ::bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
entry_type<double> mat1::_E(
  "E", ::bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get(), nullptr, nullptr, true));
entry_type<double> mat1::_G(
  "G", ::bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get(), nullptr, nullptr, true));
entry_type<double> mat1::_NU(
  "NU", ::bdf::type_bounds::bound<double>(make_unique<double>(-1.).get(),
                    make_unique<double>(.5).get(), nullptr, true));
entry_type<double> mat1::_RHO(
  "RHO", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<double> mat1::_A(
  "A", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<double> mat1::_TREF(
  "TREF", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<double> mat1::_GE(
  "GE", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
entry_type<double> mat1::_ST(
  "ST",
  ::bdf::type_bounds::bound<double>(make_unique<double>(0.).get(), nullptr, nullptr, true));
entry_type<double> mat1::_SC(
  "SC",
  ::bdf::type_bounds::bound<double>(make_unique<double>(0.).get(), nullptr, nullptr, true));
entry_type<double> mat1::_SS(
  "SS",
  ::bdf::type_bounds::bound<double>(make_unique<double>(0.).get(), nullptr, nullptr, true));
entry_type<long> mat1::_MCSID(
  "MCSID",
  ::bdf::type_bounds::bound<long>(make_unique<long>(0).get(), nullptr, nullptr, true));

mat1::mat1(const deque<::std::string> &inp) : bdf_card(inp) {

  MCSID = nullptr;
  SS = nullptr;
  SC = nullptr;
  ST = nullptr;
  GE = nullptr;
  TREF = nullptr;
  A = nullptr;
  RHO = nullptr;
  NU = nullptr;
  G = nullptr;

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
    MCSID = get_val<long>(_MCSID, *(pos++));
  case 11:
    SS = get_val<double>(_SS, *(pos++));
  case 10:
    SC = get_val<double>(_SC, *(pos++));
  case 9:
    ST = get_val<double>(_ST, *(pos++));
  case 8:
    GE = get_val<double>(_GE, *(pos++));
  case 7:
    TREF = get_val<double>(_TREF, *(pos++));
  case 6:
    A = get_val<double>(_A, *(pos++));
  case 5:
    RHO = get_val<double>(_RHO, *(pos++));
  case 4:
    NU = get_val<double>(_NU, *(pos++));
  case 3:
    G = get_val<double>(_G, *(pos++));
  case 2:
    E = get_val<double>(_E, *(pos++));
    MID = get_val<long>(_MID, *(pos));
    break;
  default:
    throw bdf_parse_error("MAT1", "Illegal number of entries.");
  }

  // remark 2
  if (!E && !G)
    throw bdf_parse_error(
      "MAT1", "Either G or E has to be given.");
  if (!NU) {
    if (!E) {
      NU = make_unique<double>(0.);
      E = make_unique<double>(0.);
    } else if (!G) {
      NU = make_unique<double>(0.);
      G = make_unique<double>(0.);
    } else
      NU = make_unique<double>((*E / 2. / *G) - 1.);
  } else if (!E)
    E = make_unique<double>((2. * (1 + *NU) * *G));
  else if (!G)
    G = make_unique<double>(*E / (2. * (1 + *NU)));
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
