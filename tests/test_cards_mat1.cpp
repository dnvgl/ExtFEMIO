// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF MAT1 cards classes.

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

TEST_CASE("BDF MAT1 definitions. (Free Field Format)",
          "[bdf_mat1]" ) {

  ::std::deque<string> data;

  SECTION("first mat1") {
    data.empty();
    data.push_back("MAT1,1,2.,3.,.4,5.,6.,7.,8.,9.,10.,11.,12\n");

    ::std::deque<string> lines = bdf_card::card_split(data);
    mat1 probe(lines);

    CHECK(*probe.MID == 1);
    CHECK(*probe.E == 2.);
    CHECK(*probe.G == 3.);
    CHECK(*probe.NU == .4);
    CHECK(*probe.RHO == 5.);
    CHECK(*probe.A == 6.);
    CHECK(*probe.TREF == 7.);
    CHECK(*probe.GE == 8.);
    CHECK(*probe.ST == 9.);
    CHECK(*probe.SC == 10.);
    CHECK(*probe.SS == 11.);
    CHECK(*probe.MCSID == 12);
  }

  SECTION("mat1 with missing entries") {
    data.empty();
    data.push_back(
      "MAT1,1,2.070+5,80000.0,0.3,7.850-6\n");
    ::std::deque<string> lines = bdf_card::card_split(data);
    mat1 probe(lines);

    CHECK(*probe.MID == 1);
    CHECK(*probe.E == 2.070e5);
    CHECK(*probe.G == 8e4);
    CHECK(*probe.NU == .3);
    CHECK(*probe.RHO == 7.85e-6);
    CHECK_FALSE(probe.A);
    CHECK_FALSE(probe.TREF);
    CHECK_FALSE(probe.GE);
    CHECK_FALSE(probe.ST);
    CHECK_FALSE(probe.SC);
    CHECK_FALSE(probe.SS);
    CHECK_FALSE(probe.MCSID);
  }

  SECTION("mat1 default values 1") {
    data.empty();
    data.push_back(
      "MAT1,1,2.070+5\n");
    ::std::deque<string> lines = bdf_card::card_split(data);
    mat1 probe(lines);

    CHECK(*probe.MID == 1);
    CHECK(*probe.E == 2.070e5);
    CHECK(*probe.G == 0.);
    CHECK(*probe.NU == 0.);
    CHECK_FALSE(probe.RHO);
    CHECK_FALSE(probe.A);
    CHECK_FALSE(probe.TREF);
    CHECK_FALSE(probe.GE);
    CHECK_FALSE(probe.ST);
    CHECK_FALSE(probe.SC);
    CHECK_FALSE(probe.SS);
    CHECK_FALSE(probe.MCSID);
  }

  SECTION("mat1 default values 2") {
    data.empty();
    data.push_back(
      "MAT1    1       2.070+5 80000.0\n");
    ::std::deque<string> lines = bdf_card::card_split(data);
    mat1 probe(lines);

    CHECK(*probe.MID == 1);
    CHECK(*probe.E == 2.070e5);
    CHECK(*probe.G == 8e4);
    CHECK(*probe.NU == Approx(0.29375));
    CHECK_FALSE(probe.RHO);
    CHECK_FALSE(probe.A);
    CHECK_FALSE(probe.TREF);
    CHECK_FALSE(probe.GE);
    CHECK_FALSE(probe.ST);
    CHECK_FALSE(probe.SC);
    CHECK_FALSE(probe.SS);
    CHECK_FALSE(probe.MCSID);
  }

  SECTION("mat1 default values 3") {
    data.empty();
    data.push_back("MAT1,1,2.070+5,,.3\n");
    ::std::deque<string> lines = bdf_card::card_split(data);
    mat1 probe(lines);

    CHECK(*probe.MID == 1);
    CHECK(*probe.E == 2.070e5);
    CHECK(*probe.G == Approx(79615.));
    CHECK(*probe.NU == 0.3);
    CHECK_FALSE(probe.RHO);
    CHECK_FALSE(probe.A);
    CHECK_FALSE(probe.TREF);
    CHECK_FALSE(probe.GE);
    CHECK_FALSE(probe.ST);
    CHECK_FALSE(probe.SC);
    CHECK_FALSE(probe.SS);
    CHECK_FALSE(probe.MCSID);
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
