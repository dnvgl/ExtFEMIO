/**
   \file tests/test_fem_cards_tdsupnam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing input and output for Sesam FEM `TDSUPNAM` cards.

   Detailed description
*/

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id: test_fem_cards_tdsupnam.cpp 261 2015-12-15 11:55:50Z berhol $";
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

TEST_CASE("FEM TDSUPNAM definitions.", "[fem_tdsupnam]" ) {

   ::std::deque<string> lines;

   SECTION("TDSUPNAM (1)") {
      ::std::deque<string> data;
      data.push_back(
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "TDSUPNAM 4.00000000e+000 1.80000000e+002 1.21000000e+002 0.00000000e+000\n");
      data.push_back(
         "        PLAN_No6_STR(5445A/B)\n");

      card::card_split(data, lines);
      tdsupnam probe(lines);

      CHECK(probe.NFIELD == 4);
      CHECK(probe.IHREF == 180);
      CHECK(probe.CODNAM == 121);
      CHECK(probe.CODTXT == 0);
      CHECK(probe.SUP_NAME == "PLAN_No6_STR(5445A/B)");
      CHECK(probe.CONT.size() == 0);
   }

   SECTION("TDSUPNAM (2)") {
      ::std::deque<string> data;
      data.push_back(
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "TDSUPNAM 4.00000000e+00  1.80000000e+02  1.21000000e+02  0.00000000e+00 \n");
      data.push_back(
         "        PLAN_No6_STR(5445A/B)\n");

      card::card_split(data, lines);
      tdsupnam probe(lines);

      CHECK(probe.NFIELD == 4);
      CHECK(probe.IHREF == 180);
      CHECK(probe.CODNAM == 121);
      CHECK(probe.CODTXT == 0);
      CHECK(probe.SUP_NAME == "PLAN_No6_STR(5445A/B)");
      CHECK(probe.CONT.size() == 0);
   }

   SECTION("TDSUPNAM (2)") {
      ::std::deque<string> data;
      data.push_back(
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "TDSUPNAM 4.00000000e+00  1.80000000e+02  1.21000000e+02  2.64000000e+02 \n");
      data.push_back(
         "        PLAN_No6_STR(5445A/B)\n");
      data.push_back(
         "        Meaningles comment.\n");
      data.push_back(
         "        abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+\n");

      card::card_split(data, lines);
      tdsupnam probe(lines);

      CHECK(probe.NFIELD == 4);
      CHECK(probe.IHREF == 180);
      CHECK(probe.CODNAM == 121);
      CHECK(probe.CODTXT == 264);
      CHECK(probe.SUP_NAME == "PLAN_No6_STR(5445A/B)");
      CHECK(probe.CONT.size() == 2);
      CHECK(probe.CONT[0] == "Meaningles comment.                                             ");
      //                      1234567891123456789212345678931234567894123456789512345678961234
      CHECK(probe.CONT[1] == "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+");
   }
}

TEST_CASE("FEM TDSUPNAM types output.", "[fem_tdsupnam,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      tdsupnam probe(4, 123, 122, "1234567890123456789012");
      test << probe;
      CHECK(test.str() ==
            "TDSUPNAM+4.00000000e+00 +1.23000000e+02 +1.22000000e+02 +0.00000000e+00 \n"
            "        1234567890123456789012\n");
   }

   SECTION("calc internal values") {
      tdsupnam probe(123, "1234567890123456789012");
      test << probe;
      CHECK(test.str() ==
            "TDSUPNAM+4.00000000e+00 +1.23000000e+02 +1.22000000e+02 +0.00000000e+00 \n"
            "        1234567890123456789012\n");
   }

   SECTION("with comment") {
      ::std::deque<::std::string> comments(2);
      comments[0] = "test";
      comments[1] = "123456789112345678921234567893123";
      tdsupnam probe(4, 123, 122, 233, "1234567890123456789012", comments);
      test << probe;
      CHECK(test.str() ==
            "TDSUPNAM+4.00000000e+00 +1.23000000e+02 +1.22000000e+02 +2.33000000e+02 \n"
            "        1234567890123456789012\n"
            "        test                             \n"
            "        123456789112345678921234567893123\n");
   }

   SECTION("with comment (calc internal values)") {
      ::std::deque<::std::string> comments(2);
      comments[0] = "test";
      comments[1] = "123456789112345678921234567893123";
      tdsupnam probe(123, "1234567890123456789012", comments);
      test << probe;
      CHECK(test.str() ==
            "TDSUPNAM+4.00000000e+00 +1.23000000e+02 +1.22000000e+02 +2.33000000e+02 \n"
            "        1234567890123456789012\n"
            "        test                             \n"
            "        123456789112345678921234567893123\n");
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
