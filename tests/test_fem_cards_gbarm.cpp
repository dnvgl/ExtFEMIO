/**
   \file test_fem_cards_gbarm.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GBARM` cards.

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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GBARM definitions.", "[fem_gbarm]" ) {

   ::std::deque<string> lines;

   SECTION("GBARM (1)") {
      ::std::deque<string> data;
      data.push_back(
         "GBARM    2.00000000e+000 2.50000000e+002 3.20000000e+001 3.20000000e+001\n");
      data.push_back(
         "         1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n");
      card::card_split(data, lines);
      gbarm probe(lines);

      CHECK(probe.GEONO == 2);
      CHECK(probe.HZ == 250.);
      CHECK(probe.BT == 32.);
      CHECK(probe.BB == 32.);
      CHECK(probe.SFY == 1.);
      CHECK(probe.SFZ == 1.);
      CHECK(probe.NLOBY == 0.);
      CHECK(probe.NLOBZ == 0.);
   }

   SECTION("GBARM (2)") {
      ::std::deque<string> data;
      data.push_back(
         "GBARM    2.00000000e+00  2.50000000e+02  3.20000000e+01  3.20000000e+01 \n");
      data.push_back(
         "         1.00000000e+00  1.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
      card::card_split(data, lines);
      gbarm probe(lines);

      CHECK(probe.GEONO == 2);
      CHECK(probe.HZ == 250.);
      CHECK(probe.BT == 32.);
      CHECK(probe.BB == 32.);
      CHECK(probe.SFY == 1.);
      CHECK(probe.SFZ == 1.);
      CHECK(probe.NLOBY == 0);
      CHECK(probe.NLOBZ == 0);
   }
}

TEST_CASE("FEM GBARM types output.", "[fem_gbarm,out]" ) {

   std::ostringstream test;

   long NODEX(1), NODENO(222), NDOF(3);
   ::std::deque<int> ODOF;
   ODOF.push_back(2);
   ODOF.push_back(6);
   ODOF.push_back(3);

   SECTION("simple") {
      gbarm probe(1, 2., 3., 4., 5., 6., 7, 8);
      test << probe;
      CHECK(test.str() ==
            "GBARM   +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00 +7.00000000e+00 +8.00000000e+00 \n");
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
