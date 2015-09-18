// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PBEAML cards.

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

#include <cstdlib>
#include <memory>

#ifdef _TYPE
#undef _TYPE
#endif

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<std::string> pbeaml::_GROUP(
  "GROUP", bdf::type_bounds::bound<std::string>("MSCBML0"));
namespace {
  static const size_t TYPE_len = 22;
  const char* TYPEinit[TYPE_len] = {
    "T", "TW", "I", "L", "ROD", "TUBE", "CHAN", "BOX", "BAR", "CROSS",
    "H", "T1", "I1", "CHAN1", "Z", "CHAN2", "T2", "BOX1", "HEXA",
    "HAT", "HAT1", "DBOX"};
  const set<std::string> TYPE_set(TYPEinit, TYPEinit + TYPE_len);
}
const entry_type<std::string> pbeaml::_TYPE(
  "TYPE", bdf::type_bounds::bound<std::string>(TYPE_set));
const entry_type<double> pbeaml::_DIM(
  "DIM", bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get()));
const entry_type<double> pbeaml::_NSM(
  "NSM", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));
namespace {
  static const size_t SO_len = 2;
  const char* SO_init[SO_len] = { "YES", "NO" };
  const set<std::string> SO_set(SO_init, SO_init + SO_len);
}
const entry_type<std::string> pbeaml::_SO(
  "SO", bdf::type_bounds::bound<std::string>(SO_set, "YES"));
const entry_type<double> pbeaml::_X_XB(
  "X/XB", bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get(), nullptr,
    make_unique<double>(1.).get()));

pbeaml::pbeaml(const deque<std::string> &inp) : bdf_beam_prop(inp) {

  size_t dim_num = 0;
  size_t i, j = 0;

  auto pos = inp.begin();

  if (pos == inp.end()) goto invalid;
  ++pos;
  if (pos == inp.end()) goto invalid;
  PID = get_val<long>(_PID, *(pos++));
  if (pos == inp.end()) goto invalid;
  MID = get_val<long>(_MID, *(pos++));
  if (pos == inp.end()) goto invalid;
  GROUP = get_val<std::string>(_GROUP, *(pos++));
  if (*GROUP != "MSCBML0")
    throw bdf_parse_error(
      "PBEAML", "Currently only GROUP==MSCBML0 is supported.");
  if (pos == inp.end()) goto invalid;
  TYPE = get_val<std::string>(_TYPE, *(pos++));
  if (pos == inp.end()) goto invalid;
  if (dimnum1.find(*TYPE) != dimnum1.end())
    dim_num = 1;
  else if (dimnum2.find(*TYPE) != dimnum2.end())
    dim_num = 2;
  else if (dimnum3.find(*TYPE) != dimnum3.end())
    dim_num = 3;
  else if (dimnum4.find(*TYPE) != dimnum4.end())
    dim_num = 4;
  else if (dimnum5.find(*TYPE) != dimnum5.end())
    dim_num = 5;
  else if (dimnum6.find(*TYPE) != dimnum6.end())
    dim_num = 6;
  else if (dimnum10.find(*TYPE) != dimnum10.end())
    dim_num = 10;
  else
    throw bdf_parse_error(
      "PBEAML", "Unknown beam type " + *TYPE + ".");

  ++pos;
  for (i=1; i<4; i++) {
    if (pos == inp.end()) goto invalid;
    ++pos;
  }

  DIM.push_back(new deque<std::unique_ptr<double>>);
  for (i=0; i < dim_num; i++) {
    if (pos == inp.end()) goto invalid;
    (*DIM[0]).push_back(get_val<double>(_DIM, *(pos++)));
  }
  if (pos == inp.end()) goto end;
  NSM.push_back(get_val<double>(_NSM, *(pos++)));

  // Read further cross section definitions for tapered beams. The
  // 'goto's are used because SO, and X/XB have default values. This
  // code is required because it is valid to have only one cross
  // section description defined with attached empty cells. Then the
  // code first assumes that more definitions are defined, using
  // default values for SO and X/XB, only to determine that no DIMs
  // are defined, so no further cross sections are available and
  // cleaning up SO and X/XB afterwards. This should raise an error
  // when SO and/or X/XB are given, but no DIM's, but it does not.
  while (pos != inp.end()) {
    if (pos == inp.end()) goto end;
    j++;
    DIM.push_back(new deque<unique_ptr<double>>);
    try {
      SO.push_back(get_val<std::string>(_SO, *(pos++)));
    } catch (bdf_error) {
      goto clean_SO;
    };
    if (pos == inp.end()) goto clean_X_XB;
    try {
      X_XB.push_back(get_val<double>(_X_XB, *(pos++)));
    } catch (bdf_error) {
      goto clean_X_XB;
    }
    if (pos == inp.end()) goto clean;
    try {
      (*DIM[j]).push_back(get_val<double>(_DIM, *(pos++)));
    } catch (bdf_error) {
      goto clean;
    }
    for (i=1; i < dim_num; i++) {
      if (pos == inp.end()) goto invalid;
      (*DIM[j]).push_back(get_val<double>(_DIM, *(pos++)));
    }
    if (pos == inp.end()) goto end;
    NSM.push_back(get_val<double>(_NSM, *(pos++)));
  }

  goto end;

 invalid:
  throw bdf_parse_error("PBEAML", "Illegal number of entries.");
 clean:
  X_XB.pop_back();
 clean_X_XB:
  SO.pop_back();
 clean_SO:
  DIM.pop_back();
 end: ;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
