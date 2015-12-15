/**
   \file test_fem_cards_giorh.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GIORH` cards.

   Detailed description
*/

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "fem/cards.h"

using namespace ::std;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GIORH definitions.", "[fem_giorh]" ) {

   ::std::deque<string> lines;

   SECTION("GIORH (1)") {
      ::std::deque<string> data;
      data.push_back(
         "GIORH    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n");
      data.push_back(
         "         1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000\n");
      data.push_back(
         "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n");
      card::card_split(data, lines);
      giorh probe(lines);

      CHECK(probe.GEONO == 5);
      CHECK(probe.HZ == 466.);
      CHECK(probe.TY == 14.5);
      CHECK(probe.BT == 125);
      CHECK(probe.TT == 16.);
      CHECK(probe.BB == 14.5);
      CHECK(probe.TB == 16.);
      CHECK(probe.SFY == 1.);
      CHECK(probe.SFZ == 1.);
      CHECK(probe.NLOBYT == 0);
      CHECK(probe.NLOBYB == 0);
      CHECK(probe.NLOBZ == 0);
   }

   SECTION("GIORH (2)") {
      ::std::deque<string> data;
      data.push_back(
         "GIORH    5.00000000e+00  4.66000000e+02  1.45000000e+01  1.25000000e+02 \n");
      data.push_back(
         "         1.60000000e+01  1.45000000e+01  1.60000000e+01  1.00000000e+00 \n");
      data.push_back(
         "         1.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
      card::card_split(data, lines);
      giorh probe(lines);

      CHECK(probe.GEONO == 5);
      CHECK(probe.HZ == 466.);
      CHECK(probe.TY == 14.5);
      CHECK(probe.BT == 125);
      CHECK(probe.TT == 16.);
      CHECK(probe.BB == 14.5);
      CHECK(probe.TB == 16.);
      CHECK(probe.SFY == 1.);
      CHECK(probe.SFZ == 1.);
      CHECK(probe.NLOBYT == 0);
      CHECK(probe.NLOBYB == 0);
      CHECK(probe.NLOBZ == 0);
   }
}

TEST_CASE("FEM GIORH types output.", "[fem_giorh,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      giorh probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10, 11, 12);
      test << probe;
      CHECK(test.str() ==
            "GIORH   +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00 +7.00000000e+00 +8.00000000e+00 \n"
            "        +9.00000000e+00 +1.00000000e+01 +1.10000000e+01 +1.20000000e+01 \n");
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
