/**
   \file test_fem_cards_geccen.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GECCEN` cards.

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

TEST_CASE("FEM GECCEN definitions.", "[fem_geccen]" ) {

   SECTION("GECCEN (1)") {
      ::std::deque<string> data;
      data.push_back("GECCEN   1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n");
      ::std::deque<string> lines = card::card_split(data);
      geccen probe(lines);

      CHECK(probe.ECCNO == 1);
      CHECK(probe.EX == 1.);
      CHECK(probe.EY == 3.);
      CHECK(probe.EZ == 134.);
   }

   SECTION("GECCEN (2)") {
      ::std::deque<string> data;
      data.push_back("GECCEN   1.00000000e+00  1.00000000e+00  3.00000000e+00  1.34000000e+02 \n");
      ::std::deque<string> lines = card::card_split(data);
      geccen probe(lines);

      CHECK(probe.ECCNO == 1);
      CHECK(probe.EX == 1.);
      CHECK(probe.EY == 3.);
      CHECK(probe.EZ == 134.);
   }
}

TEST_CASE("FEM GECCEN types output.", "[fem_geccen,out]" ) {

   std::ostringstream test;

   long ECCNO(1);
   double EX(1.), EY(3.), EZ(134.);

   SECTION("simple") {
      geccen probe(ECCNO, EX, EY, EZ);
      test << probe;
      CHECK(test.str() == "GECCEN  +1.00000000e+00 +1.00000000e+00 +3.00000000e+00 +1.34000000e+02 \n");
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
