// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF PBAR card class.

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
  return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
  return ex;
}

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF PBAR definitions.",
          "[bdf_PBAR]") {

  SECTION("Free Field Format (generic)") {

    ::std::deque<string> data;
    data.push_back(
      "PBAR,1,2,3.,4.,5.,6.,7.,,9.,10.,11.,12.,13.,14.,15.,16.,17.,"
      "18.,19.\n");
    ::std::deque<string> lines = bdf_card::card_split(data);
    pbar probe(lines);

    CHECK(*probe.PID ==  1);
    CHECK(*probe.MID ==  2);
    CHECK(*probe.A ==   3.);
    CHECK(*probe.I1 ==  4.);
    CHECK(*probe.I2 ==  5.);
    CHECK(*probe.J ==   6.);
    CHECK(*probe.NSM == 7.);
    CHECK(*probe.C1 ==  9.);
    CHECK(*probe.C2 == 10.);
    CHECK(*probe.D1 == 11.);
    CHECK(*probe.D2 == 12.);
    CHECK(*probe.E1 == 13.);
    CHECK(*probe.E2 == 14.);
    CHECK(*probe.F1 == 15.);
    CHECK(*probe.F2 == 16.);
    CHECK(*probe.K1 == 17.);
    CHECK(*probe.K2 == 18.);
    CHECK(*probe.I12 == 19.);
  }

  SECTION("Small Field Format 1") {

    ::std::deque<string> data;
    data.push_back(
      "PBAR    4000001 3       1.046+4 9.369+7 1.694+6 1.316+6\n");
    data.push_back(
      "                        6.856+6\n");
    ::std::deque<string> lines = bdf_card::card_split(data);
    pbar probe(lines);

    CHECK(*probe.PID == 4000001);
    CHECK(*probe.MID == 3);
    CHECK(*probe.A == 10460.);
    CHECK(*probe.I1 == 93690000.);
    CHECK(*probe.I2 == 1694000.);
    CHECK(*probe.J == 1316000.);
    CHECK(*probe.NSM == 0.);
    CHECK(*probe.C1 == 0.);
    CHECK(*probe.C2 == 0.);
    CHECK(*probe.D1 == 6.856e6);
    CHECK(*probe.D2 == 0.);
    CHECK(*probe.E1 == 0.);
    CHECK(*probe.E2 == 0.);
    CHECK(*probe.F1 == 0.);
    CHECK(*probe.F2 == 0.);
    CHECK_FALSE(probe.K1);
    CHECK_FALSE(probe.K2);
    CHECK(*probe.I12 == 0.);
  }

  SECTION("Small Field Format 2") {

    ::std::deque<string> data;
    data.push_back(
//     1234567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
      "PBAR          29       6     2.9            5.97                                \n");
    data.push_back(
      "                             2.0     4.0                                        \n");
    ::std::deque<string> lines = bdf_card::card_split(data);
    pbar probe(lines);

    CHECK(*probe.PID == 29);
    CHECK(*probe.MID == 6);
    CHECK(*probe.A == 2.9);
    CHECK(*probe.I1 == 0.);
    CHECK(*probe.I2 == 5.97);
    CHECK(*probe.J == 0.);
    CHECK(*probe.NSM == 0.);
    CHECK(*probe.C1 == 0.);
    CHECK(*probe.C2 == 0.);
    CHECK(*probe.D1 == 2.);
    CHECK(*probe.D2 == 4.);
    CHECK(*probe.E1 == 0.);
    CHECK(*probe.E2 == 0.);
    CHECK(*probe.F1 == 0.);
    CHECK(*probe.F2 == 0.);
    CHECK_FALSE(probe.K1);
    CHECK_FALSE(probe.K2);
    CHECK(*probe.I12 == 0.);
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
