/**
   \file test_fem_cards_bnbcd.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `BNBCD` cards.

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

using namespace ::std;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("FEM BNBCD definitions.", "[fem_bnbcd]" ) {

   long ref_fix[6] = {1, 1, 1, 1, 0, 1};
   ::std::deque<string> lines;

   SECTION("BNBCD (1)") {
      ::std::deque<string> data;

      data.push_back(
         "BNBCD    8.31700000e+003 6.00000000e+000 1.00000000e+000 1.00000000e+000\n");
      data.push_back(
         "         1.00000000e+000 1.00000000e+000 0.00000000e+000 1.00000000e+000\n");
      card::card_split(data, lines);
      bnbcd probe(lines);

      CHECK(probe.NODENO == 8317);
      CHECK(probe.NDOF == 6);
      CHECK(probe.FIX == ::std::deque<long>(ref_fix, ref_fix + 6));
   }

   SECTION("BNBCD (2)") {
      ::std::deque<string> data;

      data.push_back(
         "BNBCD    8.31700000e+03  6.00000000e+00  1.00000000e+00  1.00000000e+00 \n");
      data.push_back(
         "         1.00000000e+00  1.00000000e+00  0.00000000e+00  1.00000000e+00 \n");
      card::card_split(data, lines);
      bnbcd probe(lines);

      CHECK(probe.NODENO == 8317);
      CHECK(probe.NDOF == 6);
      CHECK(probe.FIX == ::std::deque<long>(ref_fix, ref_fix + 6));
   }
}

TEST_CASE("FEM BNBCD types output.", "[fem_bnbcd,out]" ) {

   std::ostringstream test;

   long inp_fix[6] = {1, 2, 3, 4, 5, 6};

   SECTION("simple") {
      bnbcd probe(1, 6, ::std::deque<long>(inp_fix, inp_fix + 6));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("simple (2)") {
      bnbcd probe(1, 3, ::std::deque<long>(inp_fix, inp_fix + 3));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.00000000e+00 +3.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("calc ndof") {
      bnbcd probe(1, ::std::deque<long>(inp_fix, inp_fix + 6));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("calc ndof (2)") {
      bnbcd probe(1, ::std::deque<long>(inp_fix, inp_fix + 3));
      test << probe;
      CHECK(test.str() ==
            "BNBCD   +1.00000000e+00 +3.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
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
