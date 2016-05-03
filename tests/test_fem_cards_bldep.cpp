/**
   \file test_fem_cards_bldep.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `BLDEP` cards.

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

TEST_CASE("FEM BLDEP definitions.", "[fem_bldep]" ) {

    std::deque<std::string> lines; 

   SECTION("BLDEP (1)") {
      std::deque<std::string> data({
         "BLDEP    1.10720000e+004 2.30470000e+004 6.00000000e+000 9.00000000e+000\n",
         "         1.00000000e+000 1.00000000e+000 1.00000000e+000 0.00000000e+000\n",
         "         1.00000000e+000 6.00000000e+000 6.43000000e+003 0.00000000e+000\n",
         "         1.00000000e+000 5.00000000e+000-1.06500000e+003 0.00000000e+000\n",
         "         2.00000000e+000 2.00000000e+000 1.00000000e+000 0.00000000e+000\n",
         "         2.00000000e+000 4.00000000e+000 1.06500000e+003 0.00000000e+000\n",
         "         2.00000000e+000 6.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         3.00000000e+000 3.00000000e+000 1.00000000e+000 0.00000000e+000\n",
         "         3.00000000e+000 5.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         3.00000000e+000 4.00000000e+000-6.43000000e+003 0.00000000e+000\n"});
      card::card_split(data, lines);
      bldep probe(lines);

      CHECK(probe.NODENO == 11072);
      CHECK(probe.CNOD == 23047);
      CHECK(probe.NDDOF == 6);
      CHECK(probe.NDEP == 9);
      CHECK(probe.DEPDOF == std::deque<long>({1, 1, 1, 2, 2, 2, 3, 3, 3}));
      CHECK(probe.INDEPDOF == std::deque<long>({1, 6, 5, 2, 4, 6, 3, 5, 4}));
      CHECK(probe.b == std::deque<double>({ 1.000e+0,  6.430e+3, -1.065e+3,
                  1.000e+0,  1.065e+3,  0.000e+0,
                  1.000e+0,  0.000e+0, -6.430e+3}));
   }

   SECTION("BLDEP (2)") {
      std::deque<std::string> data({
         "BLDEP    1.10720000e+004 2.30470000e+004 6.00000000e+000 9.00000000e+000\n",
         "         1.00000000e+000 1.00000000e+000 1.00000000e+000 0.00000000e+000\n",
         "         1.00000000e+000 6.00000000e+000 6.43000000e+003 0.00000000e+000\n",
         "         1.00000000e+000 5.00000000e+000-1.06500000e+003 0.00000000e+000\n",
         "         2.000000000e+00 2.000000000e+00 1.000000000e+00 0.000000000e+00\n",
         "         2.000000000e+00 4.000000000e+00 1.06500000e+03  0.000000000e+00\n",
         "         2.000000000e+00 6.000000000e+00 0.000000000e+00 0.000000000e+00\n",
         "         3.000000000e+00 3.000000000e+00 1.000000000e+00 0.000000000e+00\n",
         "         3.000000000e+00 5.000000000e+00 0.000000000e+00 0.000000000e+00\n",
         "         3.000000000e+00 4.000000000e+00-6.43000000e+03  0.000000000e+00\n"});
      card::card_split(data, lines);
      bldep probe(lines);

      CHECK(probe.NODENO == 11072);
      CHECK(probe.CNOD == 23047);
      CHECK(probe.NDDOF == 6);
      CHECK(probe.NDEP == 9);
      CHECK(probe.DEPDOF == std::deque<long>({1, 1, 1, 2, 2, 2, 3, 3, 3}));
      CHECK(probe.INDEPDOF == std::deque<long>({1, 6, 5, 2, 4, 6, 3, 5, 4}));
      CHECK(probe.b == std::deque<double>({ 1.000e+0,  6.430e+3, -1.065e+3,
                  1.000e+0,  1.065e+3,  0.000e+0,
                  1.000e+0,  0.000e+0, -6.430e+3}));
   }

   SECTION("BLDEP (3)") {
      std::deque<std::string> data({
         "BLDEP   +1.000000000e+00+2.000000000e+00+6.000000000e+00+6.000000000e+00\n",
         "        +1.000000000e+00+3.000000000e+00+1.000000000e+00            0.00\n",
         "        +1.000000000e+00+2.000000000e+00+2.000000000e+00            0.00\n",
         "        +1.000000000e+00+1.000000000e+00+3.000000000e+00            0.00\n",
         "        +2.000000000e+00+3.000000000e+00+4.000000000e+00            0.00\n",
         "        +2.000000000e+00+2.000000000e+00+5.000000000e+00            0.00\n",
         "        +2.000000000e+00+1.000000000e+00+6.000000000e+00            0.00\n"});
      card::card_split(data, lines);
      bldep probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.CNOD == 2);
      CHECK(probe.NDDOF == 6);
      CHECK(probe.NDEP == 6);
      CHECK(probe.DEPDOF == std::deque<long>({1, 1, 1, 2, 2, 2}));
      CHECK(probe.INDEPDOF == std::deque<long>({3, 2, 1, 3, 2, 1}));
      CHECK(probe.b == std::deque<double>({1.,  2., 3., 4., 5., 6.}));
   }
}

TEST_CASE("FEM BLDEP types output.", "[fem_bldep,out]" ) {

   std::ostringstream test;

   SECTION("empty") {
      bldep probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("simple") {
      long inp_depdof[9] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
      long inp_indepdof[9] = {3, 2, 1, 3, 2, 1, 3, 2, 1};
      double inp_b[9] = { 1., 2., 3., 4., 5., 6., 7., 8., 9.};
      bldep probe(1, 2, 6, 6,
                  std::deque<long>(inp_depdof, inp_depdof + 9),
                  std::deque<long>(inp_indepdof, inp_indepdof + 9),
                  std::deque<double>(inp_b, inp_b + 9));
      test << probe;
      CHECK(test.str() ==
            "BLDEP   +1.000000000e+00+2.000000000e+00+6.000000000e+00+6.000000000e+00\n"
            "        +1.000000000e+00+3.000000000e+00+1.000000000e+00            0.00\n"
            "        +1.000000000e+00+2.000000000e+00+2.000000000e+00            0.00\n"
            "        +1.000000000e+00+1.000000000e+00+3.000000000e+00            0.00\n"
            "        +2.000000000e+00+3.000000000e+00+4.000000000e+00            0.00\n"
            "        +2.000000000e+00+2.000000000e+00+5.000000000e+00            0.00\n"
            "        +2.000000000e+00+1.000000000e+00+6.000000000e+00            0.00\n");
   }

   SECTION("simple (fixed)") {
      bldep probe(1, 2, 6, 6,
                  {1, 1, 1, 2, 2, 2, 3, 3, 3},
                  {3, 2, 1, 3, 2, 1, 3, 2, 1},
                  { 1., 2., 3., 4., 5., 6., 7., 8., 9.});
      test << probe;
      CHECK(test.str() ==
            "BLDEP   +1.000000000e+00+2.000000000e+00+6.000000000e+00+6.000000000e+00\n"
            "        +1.000000000e+00+3.000000000e+00+1.000000000e+00            0.00\n"
            "        +1.000000000e+00+2.000000000e+00+2.000000000e+00            0.00\n"
            "        +1.000000000e+00+1.000000000e+00+3.000000000e+00            0.00\n"
            "        +2.000000000e+00+3.000000000e+00+4.000000000e+00            0.00\n"
            "        +2.000000000e+00+2.000000000e+00+5.000000000e+00            0.00\n"
            "        +2.000000000e+00+1.000000000e+00+6.000000000e+00            0.00\n");
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
