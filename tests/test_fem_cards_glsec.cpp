/**
   \file test_fem_cards_glsec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GLSEC` cards.

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

TEST_CASE("FEM GLSEC definitions.", "[fem_glsec]" ) {

   ::std::deque<string> lines;

   SECTION("GLSEC (1)") {
      ::std::deque<string> data;
      data.push_back(
         "GLSEC    2.20000000e+001 7.00000000e+002 1.20000000e+001 1.50000000e+002\n");
      data.push_back(
         "         1.20000000e+001 1.00000000e+000 1.00000000e+000 1.00000000e+000\n");
      data.push_back(
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n");
      card::card_split(data, lines);
      glsec probe(lines);

      CHECK(probe.GEONO == 22);
      CHECK(probe.HZ == 700.);
      CHECK(probe.TY == 12);
      CHECK(probe.BY == 150);
      CHECK(probe.TZ == 12.);
      CHECK(probe.SFY == 1.);
      CHECK(probe.SFZ == 1.);
      CHECK(probe.K);
      CHECK(probe.NLOBY == 0);
      CHECK(probe.NLOBZ == 0);
   }

   SECTION("GLSEC (2)") {
      ::std::deque<string> data;
      data.push_back(
         "GLSEC    2.20000000e+01  7.00000000e+02  1.20000000e+01  1.50000000e+02 \n");
      data.push_back(
         "         1.20000000e+01  1.00000000e+00  1.00000000e+00  1.00000000e+00 \n");
      data.push_back(
         "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
      card::card_split(data, lines);
      glsec probe(lines);

      CHECK(probe.GEONO == 22);
      CHECK(probe.HZ == 700.);
      CHECK(probe.TY == 12);
      CHECK(probe.BY == 150);
      CHECK(probe.TZ == 12.);
      CHECK(probe.SFY == 1.);
      CHECK(probe.SFZ == 1.);
      CHECK(probe.K);
      CHECK(probe.NLOBY == 0);
      CHECK(probe.NLOBZ == 0);
   }
}

TEST_CASE("FEM GLSEC types output.", "[fem_glsec,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      glsec probe(1, 2., 3., 4., 5., 6., 7., true, 9, 10);
      test << probe;
      CHECK(test.str() ==
            "GLSEC   +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00 +7.00000000e+00  1.00000000e+00 \n"
            "        +9.00000000e+00 +1.00000000e+01  0.00000000e+00  0.00000000e+00 \n");
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
