/**
   \file test_fem_cards_gbeamg.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GBEAMG` cards.

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

TEST_CASE("FEM GBEAMG definitions.", "[fem_gbeamg]" ) {

   std::deque<std::string> lines;

   SECTION("GBEAMG (1)") {
      std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GBEAMG   1.68500000e+003 0.00000000e+000 1.11500000e+004 1.00000000e-008\n",
         "         5.93000000e+008 1.57380000e+007 0.00000000e+000 1.00000000e-008\n",
         "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n",
         "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n"});
      card::card_split(data, lines);
      gbeamg probe(lines);

      CHECK(probe.GEONO == 1685);
      CHECK(probe.AREA == 1.115e4);
      CHECK(probe.IX == 1e-8);
      CHECK(probe.IY == 5.93e8);
      CHECK(probe.IZ == 1.5738e7);
      CHECK(probe.IYZ == 0.);
      CHECK(probe.WXMIN == 1e-8);
      CHECK(probe.WYMIN == 1e-8);
      CHECK(probe.WZMIN == 1e-8);
      CHECK(probe.SHARY == 1e-8);
      CHECK(probe.SHARZ == 1e-8);
      CHECK(probe.SHCENY == 1e-8);
      CHECK(probe.SHCENZ == 1e-8);
      CHECK(probe.SY == 1e-8);
      CHECK(probe.SZ == 1e-8);
   }

   SECTION("GBEAMG (2)") {
      std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GBEAMG   1.68500000e+03  0.000000000e+00 1.11500000e+04  1.00000000e-08 \n",
         "         5.93000000e+08  1.57380000e+07  0.000000000e+00 1.00000000e-08 \n",
         "         1.00000000e-08  1.00000000e-08  1.00000000e-08  1.00000000e-08 \n",
         "         1.00000000e-08  1.00000000e-08  1.00000000e-08  1.00000000e-08 \n"});
      card::card_split(data, lines);
      gbeamg probe(lines);

      CHECK(probe.GEONO == 1685);
      CHECK(probe.AREA == 1.115e4);
      CHECK(probe.IX == 1e-8);
      CHECK(probe.IY == 5.93e8);
      CHECK(probe.IZ == 1.5738e7);
      CHECK(probe.IYZ == 0.);
      CHECK(probe.WXMIN == 1e-8);
      CHECK(probe.WYMIN == 1e-8);
      CHECK(probe.WZMIN == 1e-8);
      CHECK(probe.SHARY == 1e-8);
      CHECK(probe.SHARZ == 1e-8);
      CHECK(probe.SHCENY == 1e-8);
      CHECK(probe.SHCENZ == 1e-8);
      CHECK(probe.SY == 1e-8);
      CHECK(probe.SZ == 1e-8);
   }

   SECTION("GBEAMG (own output)") {
      std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GBEAMG  +1.000000000e+00            0.00+2.000000000e+00+3.000000000e+00\n",
         "        +4.000000000e+00+5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
         "        +8.000000000e+00+9.000000000e+00+1.000000000e+01+1.100000000e+01\n",
         "        +1.200000000e+01+1.300000000e+01+1.400000000e+01+1.500000000e+01\n"});
      card::card_split(data, lines);
      gbeamg probe(lines);

      CHECK(probe.GEONO == 1);
      CHECK(probe.AREA == 2.);
      CHECK(probe.IX == 3.);
      CHECK(probe.IY == 4.);
      CHECK(probe.IZ == 5.);
      CHECK(probe.IYZ == 6.);
      CHECK(probe.WXMIN == 7.);
      CHECK(probe.WYMIN == 8.);
      CHECK(probe.WZMIN == 9.);
      CHECK(probe.SHARY == 10.);
      CHECK(probe.SHARZ == 11.);
      CHECK(probe.SHCENY == 12.);
      CHECK(probe.SHCENZ == 13.);
      CHECK(probe.SY == 14.);
      CHECK(probe.SZ == 15.);
   }
}

TEST_CASE("FEM GBEAMG types output.", "[fem_gbeamg,out]" ) {

   std::ostringstream test;

   long NODEX(1), NODENO(222), NDOF(3);
   std::deque<int> ODOF({2, 6, 3});

   SECTION("empty") {
      gbeamg probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("simple") {
      gbeamg probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15.);
      test << probe;
      CHECK(test.str() ==
            "GBEAMG  +1.000000000e+00            0.00+2.000000000e+00+3.000000000e+00\n"
            "        +4.000000000e+00+5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
            "        +8.000000000e+00+9.000000000e+00+1.000000000e+01+1.100000000e+01\n"
            "        +1.200000000e+01+1.300000000e+01+1.400000000e+01+1.500000000e+01\n");
   }
}

TEST_CASE("FEM GBEAMG conversion from own output.", "[fem_gbeamg,in/out]") {

   std::deque<std::string> lines;

   SECTION("GBEAMG (1)") {
      std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "GBEAMG  +1.000000000e+00            0.00+2.000000000e+00+3.000000000e+00\n",
            "        +4.000000000e+00+5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
            "        +8.000000000e+00+9.000000000e+00+1.000000000e+01+1.100000000e+01\n",
            "        +1.200000000e+01+1.300000000e+01+1.400000000e+01+1.500000000e+01\n"});
      card::card_split(data, lines);
      gbeamg probe(lines);

      CHECK(probe.GEONO == 1);
      CHECK(probe.AREA == 2.);
      CHECK(probe.IX == 3.);
      CHECK(probe.IY == 4.);
      CHECK(probe.IZ == 5.);
      CHECK(probe.IYZ == 6.);
      CHECK(probe.WXMIN == 7.);
      CHECK(probe.WYMIN == 8.);
      CHECK(probe.WZMIN == 9);
      CHECK(probe.SHARY == 10.);
      CHECK(probe.SHARZ == 11.);
      CHECK(probe.SHCENY == 12.);
      CHECK(probe.SHCENZ == 13.);
      CHECK(probe.SY == 14.);
      CHECK(probe.SZ == 15.);
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
