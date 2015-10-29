// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran BDF PBARL cards.

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

#include <cstdlib>
#include <memory>

#ifdef _TYPE
#undef _TYPE
#endif

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<std::string> pbarl::_GROUP(
  "GROUP", bdf::type_bounds::bound<std::string>("MSCBML0"));
namespace {
  static const size_t TYPE_len = 22;
  const char* TYPEinit[TYPE_len] = {
    "T", "TW", "I", "L", "ROD", "TUBE", "CHAN", "BOX", "BAR", "CROSS",
    "H", "T1", "I1", "CHAN1", "Z", "CHAN2", "T2", "BOX1", "HEXA",
    "HAT", "HAT1", "DBOX"};
  const std::set<std::string> TYPE_set(TYPEinit, TYPEinit + TYPE_len);
}
const entry_type<std::string> pbarl::_TYPE(
  "TYPE", bdf::type_bounds::bound<std::string>(TYPE_set));
const entry_type<double> pbarl::_DIM(
  "DIM", bdf::type_bounds::bound<double>(
    make_unique<double>(0.).get()));
const entry_type<double> pbarl::_NSM(
  "NSM", bdf::type_bounds::bound<double>(
    nullptr, nullptr, make_unique<double>(0.).get()));

pbarl::pbarl(const deque<std::string> &inp) : bar_prop(inp) {

  size_t dim_num = 0;
  size_t i = 0;

  auto pos = inp.begin();

  if (pos == inp.end()) goto invalid;
  ++pos;
  if (pos == inp.end()) goto invalid;
  PID = bdf::types::get_val<long>(_PID, *(pos++));
  if (pos == inp.end()) goto invalid;
  MID = bdf::types::get_val<long>(_MID, *(pos++));
  if (pos == inp.end()) goto invalid;
  GROUP = bdf::types::get_val<std::string>(_GROUP, *(pos++));
  if (*GROUP != "MSCBML0")
    throw bdf_parse_error(
      "PBARL", "Currently only GROUP==MSCBML0 is supported.");
  if (pos == inp.end()) goto invalid;
  TYPE = bdf::types::get_val<std::string>(_TYPE, *(pos++));
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
      "PBARL", "Unknown beam type " + *TYPE + ".");

  ++pos;
  for (i=1; i<4; i++) {
    if (pos == inp.end()) goto invalid;
    ++pos;
  }

  for (i=0; i < dim_num; i++) {
    if (pos == inp.end()) goto invalid;
    DIM.push_back(bdf::types::get_val<double>(_DIM, *(pos++)));
  }
  if (pos == inp.end()) goto end;
  NSM = bdf::types::get_val<double>(_NSM, *(pos));

  goto end;

 invalid:
  throw bdf_parse_error("PBARL", "Illegal number of entries.");
 end: ;
}

const std::ostream& pbarl::operator << (std::ostream& os) const {
  throw bdf_error("can't write PBARL.");
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
