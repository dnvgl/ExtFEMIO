/**
   \file test_fem_cards_mgsprng.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `MGSPRNG` cards.

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

TEST_CASE("FEM MGSPRNG definitions.", "[fem_mgsprng]" ) {

   double c_ref_K[6] = {0., 0., 0., 0., 0., 0.};
   std::deque<std::deque<double>> ref_K(6);
   for (int i = 0; i < 6; i++) {
      ref_K[i] = std::deque<double>(6);
      for (int j = 0; j < 6; j++)
         ref_K[i][j] = 0;
   }
   ref_K[1][1] = 1e8;

   std::deque<std::string> lines;

   SECTION("MGSPRNG (1)") {
      std::deque<std::string> data({
         "MGSPRNG  7.00000000e+001 6.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         1.00000000e+008 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
      card::card_split(data, lines);
      mgsprng probe(lines);

      CHECK(probe.MATNO == 70);
      CHECK(probe.NDOF == 6);
      CHECK(probe.K.size() == 6);
      for (int i = 0; i < 6; i++)
         CHECK(probe.K[i].size() == 6);
      CHECK(probe.K == ref_K);
   }

   SECTION("MGSPRNG (2)") {
      std::deque<std::string> data({
         "MGSPRNG  7.00000000e+01  6.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
         "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
         "         1.00000000e+08  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
         "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
         "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
         "         0.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n"});
      card::card_split(data, lines);
      mgsprng probe(lines);

      CHECK(probe.MATNO == 70);
      CHECK(probe.NDOF == 6);
      CHECK(probe.K.size() == 6);
      for (int i = 0; i < 6; i++)
         CHECK(probe.K[i].size() == 6);
      CHECK(probe.K == ref_K);
   }

   SECTION("MGSPRNG (3)") {

      std::deque<std::deque<double>> ref_K(6);
      ref_K[0] = std::deque<double>({1., 2., 3., 4., 5., 6.});
      ref_K[1] = std::deque<double>({2., 7., 8., 9., 10., 11.});
      ref_K[2] = std::deque<double>({3., 8., 12., 13., 14., 15.});
      ref_K[3] = std::deque<double>({4., 9., 13., 16., 17., 18.});
      ref_K[4] = std::deque<double>({5., 10., 14., 17., 19., 20.});
      ref_K[5] = std::deque<double>({6., 11., 15., 18., 20., 21.});

      std::deque<std::string> data({
         "MGSPRNG  7.00000000e+01  6.00000000e+00  1.00000000e+00  2.00000000e+00 \n",
         "         3.00000000e+00  4.00000000e+00  5.00000000e+00  6.00000000e+00 \n",
         "         7.00000000e+00  8.00000000e+00  9.00000000e+00  1.00000000e+01 \n",
         "         1.10000000e+01  1.20000000e+01  1.30000000e+01  1.40000000e+01 \n",
         "         1.50000000e+01  1.60000000e+01  1.70000000e+01  1.80000000e+01 \n",
         "         1.90000000e+01  2.00000000e+01  2.10000000e+01  0.00000000e+00 \n"});
      card::card_split(data, lines);
      mgsprng probe(lines);

      CHECK(probe.MATNO == 70);
      CHECK(probe.NDOF == 6);
      CHECK(probe.K.size() == 6);
      for (int i = 0; i < 6; i++)
         CHECK(probe.K[i].size() == 6);

      CHECK(probe.K == ref_K);
   }
}

TEST_CASE("FEM MGSPRNG types output.", "[fem_mgsprng,out]" ) {

   std::ostringstream test;

   double c_ref_K[6] = { 0.,  0.,  0.,  0.,  0.,  0.};
   std::deque<std::deque<double>> ref_K(6);
   for (int i = 0; i < 6; i++)
      ref_K[i] = std::deque<double>(c_ref_K, c_ref_K + 6);
   ref_K[1][1] = 999;

   SECTION("simple") {
      mgsprng probe(1, 6, ref_K);
      test << probe;
      CHECK(test.str() ==
            "MGSPRNG +1.00000000e+00 +6.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +9.99000000e+02 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("calc NDOF") {
      mgsprng probe(1, ref_K);
      test << probe;
      CHECK(test.str() ==
            "MGSPRNG +1.00000000e+00 +6.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +9.99000000e+02 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 +0.00000000e+00 \n"
            "        +0.00000000e+00 +0.00000000e+00 +0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("all vals std::set") {
      std::deque<std::deque<double>> ref_K(6);
      ref_K[0] = std::deque<double>({1., 2., 3., 4., 5., 6.});
      ref_K[1] = std::deque<double>({2., 7., 8., 9., 10., 11.});
      ref_K[2] = std::deque<double>({3., 8., 12., 13., 14., 15.});
      ref_K[3] = std::deque<double>({4., 9., 13., 16., 17., 18.});
      ref_K[4] = std::deque<double>({5., 10., 14., 17., 19., 20.});
      ref_K[5] = std::deque<double>({6., 11., 15., 18., 20., 21.});


      mgsprng probe(1, ref_K);
      test << probe;
      CHECK(test.str() ==
            "MGSPRNG +1.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n"
            "        +7.00000000e+00 +8.00000000e+00 +9.00000000e+00 +1.00000000e+01 \n"
            "        +1.10000000e+01 +1.20000000e+01 +1.30000000e+01 +1.40000000e+01 \n"
            "        +1.50000000e+01 +1.60000000e+01 +1.70000000e+01 +1.80000000e+01 \n"
            "        +1.90000000e+01 +2.00000000e+01 +2.10000000e+01  0.00000000e+00 \n");
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
