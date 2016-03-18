/**
   \file tests/test_fem_cards_bsell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `BSELL` class.

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
#include "fem/errors.h"

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

TEST_CASE("FEM BSELL definitions. (Small Field Format)", "[fem_bsell]" ) {

   std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "BSELL     1.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n",
         "          1.00000000E+00  1.00000000E+00  2.00000000E+00 -1.00000000E+00\n"});
   std::deque<std::string> lines;
   card::card_split(data, lines);
   bsell probe(lines);

   SECTION("first moment") {
      CHECK((long)probe.LC == 1);
      CHECK((double)probe.SUBNO == 1);
      CHECK(probe.LLC.size() == 2);
      CHECK(probe.LLC[0] == 1);
      CHECK(probe.LLC[1] == 2);
      CHECK(probe.FACT.size() == 2);
      CHECK(probe.FACT[0] == 1.);
      CHECK(probe.FACT[1] == -1.);
   }
}

TEST_CASE("FEM BSELL types output.", "[fem_bsell,out]" ) {

   std::ostringstream test;

   long LC(2);
   double SUBNO(29);
   std::deque<long> LLC({1, 2, 3, 4, 5, 6});
   std::deque<double> FACT({1., -2., 3., -4., 5., -6.});

   SECTION("write (1)") {
      bsell probe(LC, SUBNO, LLC, FACT);
      test << probe;
      CHECK(test.str() ==
            "BSELL   +2.00000000e+00 +2.90000000e+01  0.00000000e+00  0.00000000e+00 \n"
            "        +1.00000000e+00 +1.00000000e+00 +2.00000000e+00 -2.00000000e+00 \n"
            "        +3.00000000e+00 +3.00000000e+00 +4.00000000e+00 -4.00000000e+00 \n"
            "        +5.00000000e+00 +5.00000000e+00 +6.00000000e+00 -6.00000000e+00 \n");
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
