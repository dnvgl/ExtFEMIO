// Copyright © 2015 by DNV GL SE

// Purpose: Defintions for Patran CROD cards.

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
#include "bdf_types.h"
#include "bdf_errors.h"

using namespace ::std;
using namespace ::bdf::cards;
using namespace ::bdf::types;

const entry_type<long> crod::_EID(
  "EID", ::bdf::type_bounds::bound<long>(make_unique<long>(1).get()));
const entry_type<long> crod::_PID("PID");
const entry_type<long> crod::_G1("G1");
const entry_type<long> crod::_G2("G2");

crod::crod(const ::std::deque<::std::string> &inp) :
  bdf_card(inp) {

  deque<::std::string>::const_reverse_iterator pos = inp.rbegin();

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

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
