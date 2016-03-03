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

using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GBEAMG definitions.", "[fem_gbeamg]" ) {

   std::deque<std::string> lines;

   SECTION("GBEAMG (1)") {
      std::deque<std::string> data;
      data.push_back(
         "GBEAMG   1.68500000e+003 0.00000000e+000 1.11500000e+004 1.00000000e-008\n");
      data.push_back(
         "         5.93000000e+008 1.57380000e+007 0.00000000e+000 1.00000000e-008\n");
      data.push_back(
         "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n");
      data.push_back(
         "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n");
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
      std::deque<std::string> data;
      data.push_back(
         "GBEAMG   1.68500000e+03  0.00000000e+00  1.11500000e+04  1.00000000e-08 \n");
      data.push_back(
         "         5.93000000e+08  1.57380000e+07  0.00000000e+00  1.00000000e-08 \n");
      data.push_back(
         "         1.00000000e-08  1.00000000e-08  1.00000000e-08  1.00000000e-08 \n");
      data.push_back(
         "         1.00000000e-08  1.00000000e-08  1.00000000e-08  1.00000000e-08 \n");
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
}

TEST_CASE("FEM GBEAMG types output.", "[fem_gbeamg,out]" ) {

   std::ostringstream test;

   long NODEX(1), NODENO(222), NDOF(3);
   std::deque<int> ODOF;
   ODOF.push_back(2);
   ODOF.push_back(6);
   ODOF.push_back(3);

   SECTION("simple") {
      gbeamg probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15.);
      test << probe;
      CHECK(test.str() ==
            "GBEAMG  +1.00000000e+00  0.00000000e+00 +2.00000000e+00 +3.00000000e+00 \n"
            "        +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 +7.00000000e+00 \n"
            "        +8.00000000e+00 +9.00000000e+00 +1.00000000e+01 +1.10000000e+01 \n"
            "        +1.20000000e+01 +1.30000000e+01 +1.40000000e+01 +1.50000000e+01 \n");
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
