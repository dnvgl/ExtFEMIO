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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GUNIVEC definitions.", "[fem_gunivec]" ) {

   double c_ref_rload[6] = {0., 0., 2.e6, 0., 0., 0.};
   std::deque<double> ref_rload(c_ref_rload, c_ref_rload + 6);
   std::deque<std::string> lines;

   SECTION("GUNIVEC (1)") {
      std::deque<std::string> data({
         "GUNIVEC  5.34000000e+002 0.00000000e+000 0.00000000e+000-1.00000000e+000\n"});
      card::card_split(data, lines);
      gunivec probe(lines);

      CHECK(probe.TRANSNO == 534);
      CHECK(probe.UNIX == 0.);
      CHECK(probe.UNIY == 0.);
      CHECK(probe.UNIZ == -1.);
   }

   SECTION("GUNIVEC (2)") {
      std::deque<std::string> data({
         "GUNIVEC  5.34000000e+02  0.00000000e+00  0.00000000e+00 -1.00000000e+00 \n"});
      card::card_split(data, lines);
      gunivec probe(lines);

      CHECK(probe.TRANSNO == 534);
      CHECK(probe.UNIX == 0.);
      CHECK(probe.UNIY == 0.);
      CHECK(probe.UNIZ == -1.);
   }
}

TEST_CASE("FEM GUNIVEC types output.", "[fem_gunivec,out]" ) {

   std::ostringstream test;

   SECTION("empty") {
      gunivec probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("simple") {
      gunivec probe(1, 2., 3., 4.);
      test << probe;
      CHECK(test.str() ==
            "GUNIVEC +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n");
   }
}

TEST_CASE("FEM GUNIVEC conversion from own output.", "[fem_gunivec,in/out]") {

   std::deque<std::string> lines;

   SECTION("GUNIVEC (1)") {
      std::deque<std::string> data({
            "GUNIVEC +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"});
      card::card_split(data, lines);
      gunivec probe(lines);

      CHECK(probe.TRANSNO == 1);
      CHECK(probe.UNIX == 2.);
      CHECK(probe.UNIY == 3.);
      CHECK(probe.UNIZ == 4.);
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
