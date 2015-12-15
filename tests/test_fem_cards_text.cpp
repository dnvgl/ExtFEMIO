/**
   \file tests/test_fem_cards_text.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `TEXT` cards.

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

TEST_CASE("FEM TEXT definitions.", "[fem_text]" ) {

   ::std::deque<string> lines;
   
   SECTION("TEXT (1)") {
      ::std::deque<string> data;
      data.push_back(
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001");
      data.push_back(
         "        CONVERSION DETAILS:");
      data.push_back(
         "        Msc Nastran File Format -> Sesam Interface File.");
      data.push_back(
         "        Input  : \\test_01.bdt");
      data.push_back(
         "        Log    : \\test_01.txt");

      card::card_split(data, lines);
      text probe(lines);

      CHECK(probe.TYPE == 0);
      CHECK(probe.SUBTYPE == 0);
      CHECK(probe.NRECS == 4);
      CHECK(probe.NBYTE == 72);
      CHECK(probe.CONT[0] ==
            //        1         2         3         4         5         6
            // 34567890123456789012345678901234567890123456789012345678901234
            "CONVERSION DETAILS:                                             ");
      CHECK(probe.CONT[1] ==
            "Msc Nastran File Format -> Sesam Interface File.                ");
      CHECK(probe.CONT[2] ==
            "Input  : \\test_01.bdt                                           ");
      CHECK(probe.CONT[3] ==
            "Log    : \\test_01.txt                                           ");
   }

   SECTION("TEXT (2)") {
      ::std::deque<string> data;
      data.push_back(
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "TEXT     0.00000000e+00  0.00000000e+00  4.00000000e+00  7.20000000e+01 ");
      data.push_back(
         "        CONVERSION DETAILS:");
      data.push_back(
         "        Msc Nastran File Format -> Sesam Interface File.");
      data.push_back(
         "        Input  : \\test_01.bdt");
      data.push_back(
         "        Log    : \\test_01.txt");

      card::card_split(data, lines);
      text probe(lines);

      CHECK(probe.TYPE == 0);
      CHECK(probe.SUBTYPE == 0);
      CHECK(probe.NRECS == 4);
      CHECK(probe.NBYTE == 72);
      CHECK(probe.CONT[0] ==
            //        1         2         3         4         5         6
            // 34567890123456789012345678901234567890123456789012345678901234
            "CONVERSION DETAILS:                                             ");
      CHECK(probe.CONT[1] ==
            "Msc Nastran File Format -> Sesam Interface File.                ");
      CHECK(probe.CONT[2] ==
            "Input  : \\test_01.bdt                                           ");
      CHECK(probe.CONT[3] ==
            "Log    : \\test_01.txt                                           ");
   }
}

TEST_CASE("FEM TEXT types output.", "[fem_text,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      deque<::std::string> CONT;
      CONT.push_back("CONVERSION DETAILS:");
      CONT.push_back(
         "Msc Nastran File Format -> Sesam Interface File.");
      CONT.push_back(
         "Input  : \\test_01.bdt");
      CONT.push_back(
         "Log    : \\test_01.txt");
      text probe(0, 0, 4, 72, CONT);
      test << probe;
      CHECK(test.str() ==
            //        1         2         3         4         5         6         7
            // 3456789012345678901234567890123456789012345678901234567890123456789012
            "TEXT    +0.00000000e+00 +0.00000000e+00 +4.00000000e+00 +7.20000000e+01 \n"
            "        CONVERSION DETAILS:                                             \n"
            "        Msc Nastran File Format -> Sesam Interface File.                \n"
            "        Input  : \\test_01.bdt                                           \n"
            "        Log    : \\test_01.txt                                           \n");
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
