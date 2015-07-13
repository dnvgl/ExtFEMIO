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

#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_cards.h"

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF MAT1 definitions. (Free Field Format)", "[bdf_mat1]" ) {

  ::std::deque<string> data;
  SECTION("first mat1") {
    data.empty();
    data.push_back("MAT1,1,2.,3.,.4,5.,6.,7.,8.,9.,10.,11.,12\n");

    ::std::deque<string> lines = bdf_card::card_split(data);
    lines.pop_front();
    mat1 probe(lines);

    CHECK(probe.MID == 1);
    CHECK(probe.E == 2.);
    CHECK(probe.G == 3.);
    CHECK(probe.NU == .4);
    CHECK(probe.RHO == 5.);
    CHECK(probe.A == 6.);
    CHECK(probe.TREF == 7.);
    CHECK(probe.GE == 8.);
    CHECK(probe.ST == 9.);
    CHECK(probe.SC == 10.);
    CHECK(probe.SS == 11.);
    CHECK(probe.MCSID == 12);
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
