/**
   \file tests/test_fem_cards_bnbcd.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `BNBCD` cards.

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

TEST_CASE("FEM BNBCD definitions.", "[fem_bnbcd]" ) {

   std::list<std::string> lines;

   SECTION("BNBCD (1)") {
      std::list<std::string> data({
         "BNBCD    8.31700000e+003 6.00000000e+000 1.00000000e+000 1.00000000e+000\n",
         "         1.00000000e+000 1.00000000e+000 0.00000000e+000 1.00000000e+000\n"});
      __base::card::card_split(data, lines);
      bnbcd probe(lines);

      CHECK(probe.NODENO == 8317);
      CHECK(probe.NDOF == 6);
      CHECK(probe.FIX == std::vector<long>({1, 1, 1, 1, 0, 1}));
   }

   SECTION("BNBCD (2)") {
      std::list<std::string> data({
         "BNBCD    8.31700000e+03  6.000000000e+00 1.000000000e+00 1.000000000e+00\n",
         "         1.000000000e+00 1.000000000e+00 0.000000000e+00 1.000000000e+00\n"});
      __base::card::card_split(data, lines);
      bnbcd probe(lines);

      CHECK(probe.NODENO == 8317);
      CHECK(probe.NDOF == 6);
      CHECK(probe.FIX == std::vector<long>({1, 1, 1, 1, 0, 1}));
   }

   SECTION("BNBCD (2)") {
      std::list<std::string> data({
         "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n",
         "        +3.000000000e+00\n"});
      __base::card::card_split(data, lines);
      bnbcd probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.NDOF == 3);
      CHECK(probe.FIX == std::vector<long>({1, 2, 3}));
   }
}

TEST_CASE("FEM BNBCD types output.", "[fem_bnbcd,out]" ) {

   std::ostringstream test;

   long inp_fix[6] = {1, 2, 3, 4, 5, 6};

   SECTION("empty") {
      bnbcd probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("simple") {
      bnbcd probe(1, 6, std::vector<long>(inp_fix, inp_fix + 6));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n");
   }

   SECTION("simple (const)") {
      bnbcd probe(1, 6, {1, 2, 3, 4, 5, 6});
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n");
   }

   SECTION("simple (2)") {
      bnbcd probe(1, 3, std::vector<long>(inp_fix, inp_fix + 3));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
            "        +3.000000000e+00\n");
   }

   SECTION("calc ndof") {
      bnbcd probe(1, std::vector<long>(inp_fix, inp_fix + 6));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n");
   }

   SECTION("calc ndof (2)") {
      bnbcd probe(1, std::vector<long>(inp_fix, inp_fix + 3));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n"
            "        +3.000000000e+00\n");
   }
   SECTION("calc ndof (2)") {
      bnbcd probe(1, true, false, true, false, true, false);
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+0.000000000e+00\n"
            "        +1.000000000e+00+0.000000000e+00+1.000000000e+00+0.000000000e+00\n");
   }
}

TEST_CASE("FEM BNBCD conversion from own output.", "[fem_bnbcd,in/out]") {

   std::list<std::string> lines;

   SECTION("BNBCD (1)") {
      std::list<std::string> data({
            "BNBCD   +1.000000000e+00+3.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00\n"});
      __base::card::card_split(data, lines);
      bnbcd probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.NDOF == 3);
      CHECK(probe.FIX == std::vector<long>({1, 2, 3}));
   }

   SECTION("BNBCD (2)") {
      std::list<std::string> data({
            "BNBCD   +1.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n"});
      __base::card::card_split(data, lines);
      bnbcd probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.NDOF == 6);
      CHECK(probe.FIX == std::vector<long>({1, 2, 3, 4, 5, 6}));
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
