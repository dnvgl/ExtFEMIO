// Copyright © 2015 by DNV GL SE

// Purpose: Defintions for Patran CROD cards.

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
#include "bdf/types.h"
#include "bdf/errors.h"

using namespace std;
using namespace bdf::cards;
using bdf::types::entry_type;

const entry_type<long> crod::_EID(
  "EID", bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> crod::_PID("PID");
const entry_type<long> crod::_G1("G1");
const entry_type<long> crod::_G2("G2");

crod::crod(const deque<std::string> &inp) :
  card(inp) {

  auto pos = inp.rbegin();

  switch (inp.size()-1) {
  case 8:
    ++pos;
  case 7:
    ++pos;
  case 6:
    ++pos;
  case 5:
    ++pos;
  case 4:
    G2 = get_val<long>(_G2, *(pos++));
    G1 = get_val<long>(_G1, *(pos++));
    PID = get_val<long>(_PID, *(pos++));
    EID = get_val<long>(_EID, *pos);
    break;
  default:
    throw bdf_parse_error(
      "CROD", "Illegal number of entries for CROD");
  }
};

const std::ostream& crod::operator << (std::ostream& os) const {
  throw bdf_error("can't write CROD.");
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
