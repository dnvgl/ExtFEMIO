/**
   \file tests/test_fem_cards_beuslo.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `BEUSLO` class.

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

TEST_CASE("FEM BEUSLO definitions. (Small Field Format)", "[fem_beuslo]" ) {
   std::deque<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "BEUSLO    1.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n",
         "          1.00000000E+00  4.00000000E+00  0.00000000E+00  2.00000000E+00\n",
         "          1.66046816E+04  3.86669189E+03  3.86368091E+03  1.62054932E+04\n"});
   std::deque<std::string> lines;
   card::card_split(data, lines);
   beuslo probe(lines);

   SECTION("first") {

      CHECK(probe.LLC == 1);
      CHECK(probe.LOTYP == 1);
      CHECK(probe.COMPLX == false);
      CHECK(probe.LAYER == 0);
      CHECK(probe.ELNO == 1);
      CHECK(probe.NDOF == 4);
      CHECK(probe.INTNO == 0);
      CHECK(probe.SIDE == 2);
      CHECK(probe.RLOADi.size() == 4);
      CHECK(probe.RLOADi[0] == 1.66046816e+4);
      CHECK(probe.RLOADi[1] == 3.86669189e+3);
      CHECK(probe.RLOADi[2] == 3.86368091e+3);
      CHECK(probe.RLOADi[3] == 1.62054932e+4);
   }
}

TEST_CASE("FEM BEUSLO types output.", "[fem_beuslo,out]" ) {
   std::ostringstream test;

   long LLC(1);
   long LOTYP(2);
   bool COMPLX(false);
   long LAYER(3);
   long ELNO(4);
   long NDOF(5);
   long INTNO(6);
   long SIDE(2);
   std::deque<double> RLOADi({7., 8., 9., 10., 11.});
   std::deque<double> ILOADi({12., 13., 14., 15., 16.});

   std::string ref_r(
      "BEUSLO  +1.00000000e+00 +2.00000000e+00  0.00000000e+00 +3.00000000e+00 \n"
      "        +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 +2.00000000e+00 \n"
      "        +7.00000000e+00 +8.00000000e+00 +9.00000000e+00 +1.00000000e+01 \n"
      "        +1.10000000e+01  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
   std::string ref_c(
      "BEUSLO  +1.00000000e+00 +2.00000000e+00  1.00000000e+00 +3.00000000e+00 \n"
      "        +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 +2.00000000e+00 \n"
      "        +7.00000000e+00 +8.00000000e+00 +9.00000000e+00 +1.00000000e+01 \n"
      "        +1.10000000e+01 +1.20000000e+01 +1.30000000e+01 +1.40000000e+01 \n"
      "        +1.50000000e+01 +1.60000000e+01  0.00000000e+00  0.00000000e+00 \n");

   SECTION("write (empty)") {
      beuslo probe;

      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("write (fixed, verbose)") {
      beuslo probe(1,  2, false, 3, 4, 5, 6, 2, {7., 8., 9., 10., 11.});

      test << probe;
      CHECK(test.str() == ref_r);
   }

   SECTION("write (real, verbose)") {
      beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi);

      test << probe;
      CHECK(test.str() == ref_r);
   }

   SECTION("write (real, verbose, fail 1)") {
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                      SIDE, RLOADi));
   }

   SECTION("write (real, verbose, fail 2)") {
      COMPLX = true;
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                      SIDE, RLOADi));
   }

   SECTION("write (real, impl. COMPLX)") {
      beuslo probe(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi);
      test << probe;
      CHECK(test.str() == ref_r);
   }

   SECTION("write (real, impl. COMPLX, fail)") {
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, LAYER, ELNO, NDOF+1, INTNO,
                      SIDE, RLOADi));
   }

   SECTION("write (real, impl. NDOF)") {
      beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi);
      test << probe;
      CHECK(test.str() == ref_r);
   }

   SECTION("write (real, impl. NDOF, fails)") {
      COMPLX = true;
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                      SIDE, RLOADi));
   }

   SECTION("write (real, impl. NDOF, COMPLX)") {
      beuslo probe(LLC,  LOTYP, LAYER, ELNO, INTNO,
                   SIDE, RLOADi);
      test << probe;
      CHECK(test.str() == ref_r);
   }

   SECTION("write (complex, verbose)") {
      COMPLX = true;
      beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi, ILOADi);
      test << probe;
      CHECK(test.str() == ref_c);
   }

   SECTION("write (complex, verbose, fails 1)") {
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                      SIDE, RLOADi, ILOADi));
   }

   SECTION("write (complex, verbose, fails 2)") {
      COMPLX = true;
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                      SIDE, RLOADi, ILOADi));
   }

   SECTION("write (complex, verbose, fails 3)") {
      COMPLX = true;
      std::deque<double> ILOADi({12., 13., 14., 15., 16., 17.});
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                      SIDE, RLOADi, ILOADi));
   }

   SECTION("write (complex, impl. COMPLX)") {
      beuslo probe(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi, ILOADi);
      test << probe;
      CHECK(test.str() == ref_c);
   }

   SECTION("write (complex, impl. COMPLX, fails 1)") {
      std::deque<double> RLOADi({12., 13., 14., 15., 16., 17.});
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                      SIDE, RLOADi, ILOADi));
   }

   SECTION("write (complex, impl. COMPLX, fails 2)") {
      std::deque<double> ILOADi({12., 13., 14., 15., 16., 17.});
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                      SIDE, RLOADi, ILOADi));
   }

   SECTION("write (complex, impl. NDOF)") {
      COMPLX = true;
      beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi);

      test << probe;
      CHECK(test.str() == ref_c);
   }

   SECTION("write (complex, impl. NDOF, fails 1)") {
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                      SIDE, RLOADi, ILOADi));
   }

   SECTION("write (complex, impl. NDOF, fails 1)") {
      COMPLX = true;
      std::deque<double> ILOADi({12., 13., 14., 15., 16., 17.});
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                      SIDE, RLOADi, ILOADi));
   }

   SECTION("write (complex, impl. NDOF, COMPLX)") {
      beuslo probe(LLC,  LOTYP, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi);
      test << probe;
      CHECK(test.str() == ref_c);
   }

   SECTION("write (complex, impl. NDOF, COMPLX, fails)") {
      std::deque<double> ILOADi({12., 13., 14., 15., 16., 17.});
      CHECK_THROWS(
         beuslo probe(LLC,  LOTYP, LAYER, ELNO, INTNO,
                      SIDE, RLOADi, ILOADi));
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
