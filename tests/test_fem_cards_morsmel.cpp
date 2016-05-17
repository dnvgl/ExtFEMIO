/**
   \file test_fem_cards_morsmel.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing IO for Sesam FEM `MORSMEL` cards.

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

TEST_CASE("FEM MORSMEL definitions.", "[fem_morsmel]" ) {

   double c_ref_rload[6] = {0., 0., 2.e6, 0., 0., 0.};
   std::deque<double> ref_rload(c_ref_rload, c_ref_rload + 6);
   std::deque<std::string> lines;

   SECTION("MORSMEL (1)") {
      std::deque<std::string> data({
            "MORSMEL   8.00000000E+00  0.00000000E+00  0.00000000E+00  1.00000000E+00\n",
            "          0.00000000E+00  1.07820425E+11  3.14079724E+10  1.41541114E+11\n",
            "          0.00000000E+00  0.00000000E+00  3.26140006E+10  2.21900001E-01\n",
            "          2.91298896E-01  2.99999993E-02  2.99999993E-02  1.20000004E-05\n",
            "          1.20000004E-05\n"});
      card::card_split(data, lines);
      morsmel probe(lines);

      CHECK(probe.MATNO == 8);
      CHECK(probe.Q1 == 0.);
      CHECK(probe.Q2 == 0.);
      CHECK(probe.Q3 == 1.);
      CHECK(probe.RHO == 0.);
      CHECK(probe.D11 == 1.07820425e+11);
      CHECK(probe.D21 == 3.14079724e+10);
      CHECK(probe.D22 == 1.41541114e+11);
      CHECK(probe.D31 == 0.);
      CHECK(probe.D32 == 0.);
      CHECK(probe.D33 == 3.26140006e+10);
      CHECK(probe.PS1 == 2.21900001e-1);
      CHECK(probe.PS2 == 2.91298896e-1);
      CHECK(probe.DAMP1 == 2.99999993e-2);
      CHECK(probe.DAMP2 == 2.99999993e-2);
      CHECK(probe.ALPHA1 == 1.20000004e-5);
      CHECK(probe.ALPHA2 == 1.20000004e-5);
   }

   SECTION("MORSMEL (2)") {
      std::deque<std::string> data({
            "MORSMEL   1.30000000E+01  0.00000000E+00  1.00000000E+00  0.00000000E+00\n",
            "          0.00000000E+00  5.21928417E+10  7.03282944E+09  6.01096520E+10\n",
            "          0.00000000E+00  0.00000000E+00  2.18899994E+09  1.16999999E-01\n",
            "          1.34747013E-01  2.99999993E-02  2.99999993E-02  1.20000004E-05\n",
            "          1.20000004E-05  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
      card::card_split(data, lines);
      morsmel probe(lines);

      CHECK(probe.MATNO == 13);
      CHECK(probe.Q1 == 0.);
      CHECK(probe.Q2 == 1.);
      CHECK(probe.Q3 == 0.);
      CHECK(probe.RHO == 0.);
      CHECK(probe.D11 == 5.21928417e+10);
      CHECK(probe.D21 == 7.03282944e+09);
      CHECK(probe.D22 == 6.01096520e+10);
      CHECK(probe.D31 == 0.);
      CHECK(probe.D32 == 0.);
      CHECK(probe.D33 == 2.18899994e+9);
      CHECK(probe.PS1 == 1.16999999e-1);
      CHECK(probe.PS2 == 1.34747013e-1);
      CHECK(probe.DAMP1 == 2.99999993e-2);
      CHECK(probe.DAMP2 == 2.99999993e-2);
      CHECK(probe.ALPHA1 == 1.20000004e-5);
      CHECK(probe.ALPHA2 == 1.20000004e-5);
   }
}

TEST_CASE("FEM MORSMEL types output.", "[fem_morsmel,out]" ) {

   std::ostringstream test;

   SECTION("empty") {
      morsmel probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("simple") {
      morsmel probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10, 11., 12.,
                    13., 14., 15., 16., 17.);
      test << probe;
      CHECK(test.str() ==
            "MORSMEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
            "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n"
            "        +1.700000000e+01\n");
   }
}

TEST_CASE("FEM MORSMEL conversion from own output.", "[fem_morsmel,in/out]") {

   std::deque<std::string> lines;

   SECTION("MORSMEL (1)") {
      std::deque<std::string> data({
            "MORSMEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
            "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n",
            "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n",
            "        +1.700000000e+01\n"});
      card::card_split(data, lines);
      morsmel probe(lines);

      CHECK(probe.MATNO == 1);
      CHECK(probe.Q1 == 2.);
      CHECK(probe.Q2 == 3.);
      CHECK(probe.Q3 == 4.);
      CHECK(probe.RHO == 5.);
      CHECK(probe.D11 == 6.);
      CHECK(probe.D21 == 7.);
      CHECK(probe.D22 == 8.);
      CHECK(probe.D31 == 9.);
      CHECK(probe.D32 == 10.);
      CHECK(probe.D33 == 11.);
      CHECK(probe.PS1 == 12.);
      CHECK(probe.PS2 == 13.);
      CHECK(probe.DAMP1 == 14.);
      CHECK(probe.DAMP2 == 15.);
      CHECK(probe.ALPHA1 == 16.);
      CHECK(probe.ALPHA2 == 17.);
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
