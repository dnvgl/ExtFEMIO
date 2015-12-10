/**
   \file test_fem_cards_gunivec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GUNIVEC` cards.

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

TEST_CASE("FEM GUNIVEC definitions.", "[fem_gunivec]" ) {

   double c_ref_rload[6] = {0., 0., 2.e6, 0., 0., 0.};
   ::std::deque<double> ref_rload(c_ref_rload, c_ref_rload + 6);

   SECTION("GUNIVEC (1)") {
      ::std::deque<string> data;

      data.push_back(
         "GUNIVEC  5.34000000e+002 0.00000000e+000 0.00000000e+000-1.00000000e+000\n");
      ::std::deque<string> lines = card::card_split(data);
      gunivec probe(lines);

      CHECK(probe.TRANSNO == 534);
      CHECK(probe.UNIX == 0.);
      CHECK(probe.UNIY == 0.);
      CHECK(probe.UNIZ == -1.);
   }

   SECTION("GUNIVEC (2)") {
      ::std::deque<string> data;

      data.push_back(
         "GUNIVEC  5.34000000e+02  0.00000000e+00  0.00000000e+00 -1.00000000e+00 \n");
      ::std::deque<string> lines = card::card_split(data);
      gunivec probe(lines);

      CHECK(probe.TRANSNO == 534);
      CHECK(probe.UNIX == 0.);
      CHECK(probe.UNIY == 0.);
      CHECK(probe.UNIZ == -1.);
   }
}

TEST_CASE("FEM GUNIVEC types output.", "[fem_gunivec,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      gunivec probe(1, 2., 3., 4.);
      test << probe;
      CHECK(test.str() ==
            "GUNIVEC +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n");
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
