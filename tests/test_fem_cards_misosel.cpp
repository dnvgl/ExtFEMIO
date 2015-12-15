/**
   \file test_fem_cards_misosel.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `MISOSEL` cards.

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

TEST_CASE("FEM MISOSEL definitions.", "[fem_misosel]" ) {

   double c_ref_rload[6] = {0., 0., 2.e6, 0., 0., 0.};
   ::std::deque<double> ref_rload(c_ref_rload, c_ref_rload + 6);
   ::std::deque<::std::string> lines;

   SECTION("MISOSEL (1)") {
      ::std::deque<string> data;

      data.push_back(
         "MISOSEL  4.10000000e+001 2.06000000e+008 3.00032000e-001 7.80000000e+000\n");
      data.push_back(
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n");
      card::card_split(data, lines);
      misosel probe(lines);

      CHECK(probe.MATNO == 41);
      CHECK(probe.YOUNG == 2.06e8);
      CHECK(probe.POISS == 3.00032e-1);
      CHECK(probe.RHO == 7.8);
      CHECK(probe.DAMP == 0.);
      CHECK(probe.ALPHA == 0.);
   }

   SECTION("MISOSEL (2)") {
      ::std::deque<string> data;

      data.push_back(
         "MISOSEL  4.10000000e+01  2.06000000e+08  3.00032000e-01  7.80000000e+00 \n");
      data.push_back(
         "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
      card::card_split(data, lines);
      misosel probe(lines);

      CHECK(probe.MATNO == 41);
      CHECK(probe.YOUNG == 2.06e8);
      CHECK(probe.POISS == 3.00032e-1);
      CHECK(probe.RHO == 7.8);
      CHECK(probe.DAMP == 0.);
      CHECK(probe.ALPHA == 0.);
   }
}

TEST_CASE("FEM MISOSEL types output.", "[fem_misosel,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      misosel probe(1, 2., 3., 4., 5., 6.);
      test << probe;
      CHECK(test.str() ==
            "MISOSEL +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
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
