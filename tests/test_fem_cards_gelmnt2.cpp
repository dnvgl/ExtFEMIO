/**
   \file tests/test_fem_cards_gelmnt2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `GELMNT2` class.

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

TEST_CASE("FEM GELMNT2 definitions. (Small Field Format)", "[fem_gelmnt2]" ) {

   std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GELMNT2   1.00000000E+00  1.00000000E+00  1.00000000E+00  0.00000000E+00\n",
         "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
         "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
         "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
         "          1.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
   std::deque<std::string> lines;
   card::card_split(data, lines);
   gelmnt2 probe(lines);

   SECTION("first moment") {
      CHECK(probe.SUBNO == 1);
      CHECK(probe.SLEVEL == 1);
      CHECK(probe.STYPE == 1);
      CHECK(probe.ADDNO == 0);
      CHECK(probe.T[0][0] == 1.);
      CHECK(probe.T[1][0] == 0.);
      CHECK(probe.T[2][0] == 0.);
      CHECK(probe.T[3][0] == 0.);
      CHECK(probe.T[0][1] == 0.);
      CHECK(probe.T[1][1] == 1.);
      CHECK(probe.T[2][1] == 0.);
      CHECK(probe.T[3][1] == 0.);
      CHECK(probe.T[0][2] == 0.);
      CHECK(probe.T[1][2] == 0.);
      CHECK(probe.T[2][2] == 1.);
      CHECK(probe.T[3][2] == 0.);
      CHECK(probe.T[0][3] == 0.);
      CHECK(probe.T[1][3] == 0.);
      CHECK(probe.T[2][3] == 0.);
      CHECK(probe.T[3][3] == 1.);
      CHECK(probe.NNOD == 1);
      CHECK(probe.NOD.size() == 1);
      CHECK(probe.NOD[0] == 1);
   }
}

TEST_CASE("FEM GELMNT2 types output.", "[fem_gelmnt2,out]" ) {

   std::ostringstream test;

   long SUBNO(1);
   long SLEVEL(2);
   long STYPE(3);
   long ADDNO(4);
   double T11(11.);
   double T21(21.);
   double T31(31.);
   double T12(12.);
   double T22(22.);
   double T32(32.);
   double T13(13.);
   double T23(23.);
   double T33(33.);
   double T14(14.);
   double T24(24.);
   double T34(34.);

   double T[][4] = {{T11, T12, T13, T14},
                    {T21, T22, T23, T24},
                    {T31, T32, T33, T34},
                    { 0.,  0.,  0.,  1.}};
   long NNOD(5);
   std::deque<long> NOD({6, 7, 8, 9, 10});

   std::string ref(
      "GELMNT2 +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
      "        +1.10000000e+01 +2.10000000e+01 +3.10000000e+01 +1.20000000e+01 \n"
      "        +2.20000000e+01 +3.20000000e+01 +1.30000000e+01 +2.30000000e+01 \n"
      "        +3.30000000e+01 +1.40000000e+01 +2.40000000e+01 +3.40000000e+01 \n"
      "        +5.00000000e+00 +6.00000000e+00 +7.00000000e+00 +8.00000000e+00 \n"
      "        +9.00000000e+00 +1.00000000e+01  0.00000000e+00  0.00000000e+00 \n");

   SECTION("write (empty)") {
      gelmnt2 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("write (const)") {
      gelmnt2 probe(1, 2, 3, 4, T, 5, {6, 7, 8, 9, 10});
      test << probe;
      CHECK(test.str() == ref);
   }

   SECTION("write (1)") {
      gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO, T, NNOD, NOD);
      test << probe;
      CHECK(test.str() == ref);
   }

   SECTION("write (1a)") {
      CHECK_THROWS(gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO, T, NNOD+1, NOD));
   }

   SECTION("write (2)") {
      gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO, T, NOD);
      test << probe;
      CHECK(test.str() == ref);
   }

   SECTION("write (3)") {
      gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO,
                    T11, T21, T31, T12, T22, T32, T13, T23, T33,
                    T14, T24, T34, NNOD, NOD);
      test << probe;
      CHECK(test.str() == ref);
   }

   SECTION("write (4)") {
      gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO,
                    T11, T21, T31, T12, T22, T32, T13, T23, T33,
                    T14, T24, T34, NOD);
      test << probe;
      CHECK(test.str() == ref);
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
