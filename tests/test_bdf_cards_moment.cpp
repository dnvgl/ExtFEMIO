// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF MOMENT card class.

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

TEST_CASE("BDF MOMENT definitions. (Small Field Format)", "[bdf_moment]" ) {

  ::std::deque<string> data;
  data.push_back(
  // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
    "MOMENT  2       5       6       2.9     0.0     1.9     0.0               \n");
  ::std::deque<string> lines = card::card_split(data);
  moment probe(lines);

  SECTION("first moment") {
    CHECK(*probe.SID == 2);
    CHECK(*probe.G == 5);
    CHECK(*probe.CID == 6);
    CHECK(*probe.F == 2.9);
    CHECK(*probe.N1 == 0.);
    CHECK(*probe.N2 == 1.9);
    CHECK(*probe.N3 == 0.);
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
