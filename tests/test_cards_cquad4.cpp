// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF CQUAD4 cards classes.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>

#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_cards.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF CQUAD4 definitions. (Small Field Format)", "[bdf_cquad4]" ) {

  ::std::deque<string> data;
  data.push_back("CQUAD4  1       1       16      200     141     17\n");
  ::std::deque<string> lines = bdf_card::card_split(data);
  cquad4 probe(lines);

  SECTION("first cquad4") {
    CHECK(*probe.EID == 1);
    CHECK(*probe.PID == 1);
    CHECK(*probe.G1 == 16);
    CHECK(*probe.G2 == 200);
    CHECK(*probe.G3 == 141);
    CHECK(*probe.G4 == 17);
    CHECK(probe.choose_mcid_theta == cquad4::has_THETA);
    CHECK_FALSE(probe.MCID);
    CHECK(*probe.THETA == 0.0);
  }
}


TEST_CASE("BDF CQUAD4 definitions. (Large Field Format)", "[bdf_cquad4]" ) {

  ::std::deque<string> data;
  data.push_back("CQUAD4* 2               1               16              200             *\n");
  data.push_back("*       141             17\n");
  ::std::deque<string> lines = bdf_card::card_split(data);
  cquad4 probe(lines);

  SECTION("first cquad4") {
    CHECK(*probe.EID == 2);
    CHECK(*probe.PID == 1);
    CHECK(*probe.G1 == 16);
    CHECK(*probe.G2 == 200);
    CHECK(*probe.G3 == 141);
    CHECK(*probe.G4 == 17);
    CHECK_FALSE(probe.MCID);
    CHECK(*probe.THETA == 0.0);
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
