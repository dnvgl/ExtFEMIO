/**
   \file test_fem_cards_gelth.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GELTH` cards.

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

TEST_CASE("FEM GELTH definitions.", "[fem_gelth]" ) {

   std::deque<std::string> lines;

   SECTION("GELTH (1)") {
      std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GELTH    6.54394000e+005 1.00000000e-001 0.00000000e+000 0.00000000e+000\n"});
      card::card_split(data, lines);
      gelth probe(lines);

      CHECK(probe.GEONO == 654394);
      CHECK(probe.TH == .1);
      CHECK(probe.NINT == 0);
   }

   SECTION("GELTH (2)") {
      std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GELTH    6.54394000e+05  1.00000000e-01  0.000000000e+00 0.000000000e+00\n"});
      card::card_split(data, lines);
      gelth probe(lines);

      CHECK(probe.GEONO == 654394);
      CHECK(probe.TH == .1);
      CHECK(probe.NINT == 0);
   }
}

TEST_CASE("FEMIO-24: Failing to import line from SESAM GeniE FEM file") {

   std::deque<std::string> lines;

   SECTION("Failing card") {
      std::deque<std::string> data({
            "GELTH     1.00000000E+00  2.99999993E-02\n"});
      card::card_split(data, lines);
      gelth probe(lines);

      CHECK(probe.GEONO == 1);
      CHECK(probe.TH == 2.99999993e-02);
      CHECK(probe.NINT == 0);
   }
}

TEST_CASE("FEM GELTH types output.", "[fem_gelth,out]" ) {

   std::ostringstream test;

   SECTION("empty") {
      gelth probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("simple") {
      gelth probe(1, 2., 3);
      test << probe;
      CHECK(test.str() ==
            "GELTH   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n");
   }

   SECTION("simple NINT default") {
      gelth probe(1, 2.);
      test << probe;
      CHECK(test.str() ==
            "GELTH   +1.000000000e+00+2.000000000e+00\n");
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
