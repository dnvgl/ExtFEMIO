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

#include "config.h"

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

TEST_CASE("FEM TEXT definitions.", "[fem_text]" ) {

   std::list<std::string> lines;

   SECTION("TEXT (1)") {
      std::list<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001",
               "        CONVERSION DETAILS:",
               "        Msc Nastran File Format -> Sesam Interface File.",
               "        Input  : \\test_01.bdt",
               "        Log    : \\test_01.txt"});

      __base::card::card_split(data, lines);
      text probe(lines);

      CHECK(probe.TYPE == 0);
      CHECK(probe.SUBTYPE == 0);
      CHECK(probe.NRECS == 4);
      CHECK(probe.NBYTE == 72);
      CHECK(probe.CONT == std::vector<std::string>({
               //        1         2         3         4         5         6         7
               // 3456789012345678901234567890123456789012345678901234567890123456789012
               "CONVERSION DETAILS:                                                     ",
               "Msc Nastran File Format -> Sesam Interface File.                        ",
               "Input  : \\test_01.bdt                                                   ",
               "Log    : \\test_01.txt                                                   "}));
   }

   SECTION("TEXT (2)") {
      std::list<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TEXT     0.000000000e+00 0.000000000e+00 4.000000000e+00 7.200000000e+01",
            "        CONVERSION DETAILS:",
            "        Msc Nastran File Format -> Sesam Interface File.",
            "        Input  : \\test_01.bdt",
            "        Log    : \\test_01.txt"});

      __base::card::card_split(data, lines);
      text probe(lines);

      CHECK(probe.TYPE == 0);
      CHECK(probe.SUBTYPE == 0);
      CHECK(probe.NRECS == 4);
      CHECK(probe.NBYTE == 72);
      CHECK(probe.CONT == std::vector<std::string>({
               //        1         2         3         4         5         6         7
               // 3456789012345678901234567890123456789012345678901234567890123456789012
               "CONVERSION DETAILS:                                                     ",
               "Msc Nastran File Format -> Sesam Interface File.                        ",
               "Input  : \\test_01.bdt                                                   ",
               "Log    : \\test_01.txt                                                   "}));
   }
}

TEST_CASE("FEM TEXT types output.", "[fem_text,out]" ) {

   std::stringstream test;
   std::vector<std::string> CONT({
         "CONVERSION DETAILS:",
         "Msc Nastran File Format -> Sesam Interface File.",
         "Input  : \\test_01.bdt",
         "Log    : \\test_01.txt"});

   SECTION("simple (empty)") {
      text probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("simple") {
      text probe(0, 0, 4, 72, CONT);
      test << probe;
      CHECK(test.str() ==
         //        1         2         3         4         5         6         7
         // 3456789012345678901234567890123456789012345678901234567890123456789012
         "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+7.200000000e+01\n"
         "        CONVERSION DETAILS:                                             \n"
         "        Msc Nastran File Format -> Sesam Interface File.                \n"
         "        Input  : \\test_01.bdt                                           \n"
         "        Log    : \\test_01.txt                                           \n");
   }

   SECTION("simple (auto dim)") {
      text probe(0, 0, CONT);
      test << probe;
      CHECK(test.str() ==
         //        1         2         3         4         5         6         7
         // 3456789012345678901234567890123456789012345678901234567890123456789012
         "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n"
         "        CONVERSION DETAILS:                             \n"
         "        Msc Nastran File Format -> Sesam Interface File.\n"
         "        Input  : \\test_01.bdt                           \n"
         "        Log    : \\test_01.txt                           \n");
   }
}

TEST_CASE("FEM TEXT conversion from own output.", "[fem_text,in/out]") {

   std::list<std::string> lines;

   SECTION("TEXT (1)") {
      std::list<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n",
            "        CONVERSION DETAILS:                             \n",
            "        Msc Nastran File Format -> Sesam Interface File.\n",
            "        Input  : \\test_01.bdt                           \n",
            "        Log    : \\test_01.txt                           \n"});
      __base::card::card_split(data, lines);
      text probe(lines);

      CHECK(probe.TYPE == 0);
      CHECK(probe.SUBTYPE == 0);
      CHECK(probe.NRECS == 4);
      CHECK(probe.NBYTE == 56);
      CHECK(probe.CONT == std::vector<std::string>({
               //        1         2         3         4         5         6         7
               // 3456789012345678901234567890123456789012345678901234567890123456789012
               "CONVERSION DETAILS:                                     ",
               "Msc Nastran File Format -> Sesam Interface File.        ",
               "Input  : \\test_01.bdt                                   ",
               "Log    : \\test_01.txt                                   "}));
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
