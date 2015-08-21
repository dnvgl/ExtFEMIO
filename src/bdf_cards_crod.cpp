// Copyright © 2015 by DNV GL SE

// Purpose: Defintions for Patran CROD cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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
using namespace ::bdf;
using namespace ::bdf::cards;
using namespace ::bdf::types;
using namespace ::bdf::type_bounds;

bdf_int crod::_EID("EID",
                    num<long>(make_unique<long>(1).get()));
bdf_int crod::_PID("PID");
bdf_int crod::_G1("G1");
bdf_int crod::_G2("G2");

crod::crod(const ::std::deque<::std::string> &inp) :
  bdf_card(inp) {
/*
  typedef enum {has_DVEC, has_DCODE} CHOOSE_DIR_CODE;
  CHOOSE_DIR_CODE choose_dir_code;
*/

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
    G2 = make_unique<long>(*_G2(*pos));
    ++pos;
    G1 = make_unique<long>(*_G1(*pos));
    ++pos;
    PID = make_unique<long>(*_PID(*pos));
    ++pos;
    EID = make_unique<long>(*_EID(*pos));
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
