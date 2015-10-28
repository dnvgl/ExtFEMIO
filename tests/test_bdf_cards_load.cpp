// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF MOMENT LOAD class.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf/cards.h"

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/cards.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
  return ex;
}

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF LOAD definitions. (Small Field Format)", "[bdf_load]" ) {

  ::std::deque<string> data;
  data.push_back(
  // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
    "LOAD    101     -0.5    1.0     3       6.2     4                         \n");
  ::std::deque<string> lines = card::card_split(data);
  load probe(lines);

  SECTION("first moment") {
    CHECK(*probe.SID == 101);
    CHECK(*probe.S == -.5);
    CHECK(probe.Si->size() == 2);
    CHECK((*probe.Si)[0] == 1.);
    CHECK((*probe.Si)[1] == 6.2);
    CHECK(probe.Li->size() == 2);
    CHECK((*probe.Li)[0] == 3);
    CHECK((*probe.Li)[1] == 4);
  }
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
