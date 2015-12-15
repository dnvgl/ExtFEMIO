/**
   \file test_fem_cards_bndispl.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `BNDISPL` cards.

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

TEST_CASE("FEM BNDISPL definitions.", "[fem_bndispl]" ) {

   double c_ref_rdisp[6] = {0., 0., 0., 0., 0., 0.};
   ::std::deque<double> ref_rdisp(c_ref_rdisp, c_ref_rdisp + 6);
   ::std::deque<::std::string> lines;

   SECTION("BNDISPL (1)") {
      ::std::deque<string> data;

      data.push_back(
         "BNDISPL  1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n");
      data.push_back(
         "         2.30470000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000\n");
      data.push_back(
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n");
      card::card_split(data, lines);
      bndispl probe(lines);

      CHECK(probe.LLC == 1);
      CHECK(probe.DTYPE == 1);
      CHECK_FALSE(probe.COMPLX);
      CHECK(probe.NODENO == 23047);
      CHECK(probe.NDOF == 6);
      CHECK(probe.RDISP == ref_rdisp);
      CHECK(probe.IDISP.size() == 0);
   }

   SECTION("BNDISPL (2)") {
      ::std::deque<string> data;

      data.push_back(
         "BNDISPL  1.00000000e+00  1.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
      data.push_back(
         "         2.30470000e+04  6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
      data.push_back(
         "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
      card::card_split(data, lines);
      bndispl probe(lines);

      CHECK(probe.LLC == 1);
      CHECK(probe.DTYPE == 1);
      CHECK_FALSE(probe.COMPLX);
      CHECK(probe.NODENO == 23047);
      CHECK(probe.NDOF == 6);
      CHECK(probe.RDISP == ref_rdisp);
      CHECK(probe.IDISP.size() == 0);
   }
}

TEST_CASE("FEM BNDISPL types output.", "[fem_bndispl,out]" ) {

   std::ostringstream test;

   double inp_rdisp[6] = {1., 2., 3., 4., 5., 6.};
   double inp_idisp[6] = {1., 2., 3., 4., 5., 6.};

   SECTION("simple") {
      bndispl probe(1, 1, false, 4, 6,
                    ::std::deque<double>(inp_rdisp, inp_rdisp + 6));
      test << probe;
      CHECK(test.str() ==
            "BNDISPL +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("simple (with IDISP)") {
      bndispl probe(1, 1, true, 4, 6,
                    ::std::deque<double>(inp_rdisp, inp_rdisp + 6),
                    ::std::deque<double>(inp_idisp, inp_idisp + 6));
      test << probe;
      CHECK(test.str() ==
            "BNDISPL +1.00000000e+00 +1.00000000e+00  1.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n"
            "        +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("simple (calc COMPLX)") {
      bndispl probe(1, 1, (long)4, 6,
                    ::std::deque<double>(inp_rdisp, inp_rdisp + 6));
      test << probe;
      CHECK(test.str() ==
            "BNDISPL +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("simple (with IDISP, calc COMPLX)") {
      bndispl probe(1, 1, (long)4, 6,
                    ::std::deque<double>(inp_rdisp, inp_rdisp + 6),
                    ::std::deque<double>(inp_idisp, inp_idisp + 6));
      test << probe;
      CHECK(test.str() ==
            "BNDISPL +1.00000000e+00 +1.00000000e+00  1.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n"
            "        +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("calc ndof") {
      bndispl probe(1, 1, false, 4,
                    ::std::deque<double>(inp_rdisp, inp_rdisp + 6));
      test << probe;
      CHECK(test.str() ==
            "BNDISPL +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }
   SECTION("calc NDOF (calc COMPLX)") {
      bndispl probe(1, 1, 4,
                    ::std::deque<double>(inp_rdisp, inp_rdisp + 6));
      test << probe;
      CHECK(test.str() ==
            "BNDISPL +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("calc NDOF (with IDISP, calc COMPLX)") {
      bndispl probe(1, 1, 4,
                    ::std::deque<double>(inp_rdisp, inp_rdisp + 6),
                    ::std::deque<double>(inp_idisp, inp_idisp + 6));
      test << probe;
      CHECK(test.str() ==
            "BNDISPL +1.00000000e+00 +1.00000000e+00  1.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n"
            "        +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
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
