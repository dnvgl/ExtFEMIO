/**
   \file tests/test_fem_cards_iend.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `IEND` cards.

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

TEST_CASE("FEM IEND definitions.", "[fem_iend]" ) {

   std::deque<std::string> lines;

   SECTION("IEND (1)") {
      std::deque<std::string> data({
         "IEND     1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
      card::card_split(data, lines);
      iend probe(lines);

      CHECK(probe.CONT == 1);
   }

   SECTION("IEND (2)") {
      std::deque<std::string> data({
         "IEND    +1.00000000e+000+0.00000000e+000+0.00000000e+000+0.00000000e+000\n"});
      card::card_split(data, lines);
      iend probe(lines);

      CHECK(probe.CONT == 1);
   }

   SECTION("IEND (3)") {
      std::deque<std::string> data({
         "IEND     1.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n"});
      card::card_split(data, lines);
      iend probe(lines);

      CHECK(probe.CONT == 1);
   }
}

TEST_CASE("FEM IEND types output.", "[fem_iend,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      iend probe(3);
      test << probe;
      CHECK(test.str() == "IEND    +3.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
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
