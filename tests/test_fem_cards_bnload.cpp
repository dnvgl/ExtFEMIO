/**
   \file test_fem_cards_bnload.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `BNLOAD` cards.

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

TEST_CASE("FEM BNLOAD definitions.", "[fem_bnload]" ) {

   double c_ref_rload[6] = {0., 0., 2.e6, 0., 0., 0.};
   std::deque<double> ref_rload(c_ref_rload, c_ref_rload + 6);
   std::deque<std::string> lines;

   SECTION("BNLOAD (1)") {
      std::deque<std::string> data({
         "BNLOAD   1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         1.52470000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         2.00000000e+006 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
      card::card_split(data, lines);
      bnload probe(lines);

      CHECK(probe.LLC == 1);
      CHECK(probe.LOTYP == 0);
      CHECK_FALSE(probe.COMPLX);
      CHECK(probe.NODENO == 15247);
      CHECK(probe.NDOF == 6);
      CHECK(probe.RLOAD == ref_rload);
      CHECK(probe.ILOAD.size() == 0);
   }

   SECTION("BNLOAD (2)") {
      std::deque<std::string> data({
         "BNLOAD   1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         1.52470000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000\n",
         "         2.00000000e+006 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
      card::card_split(data, lines);
      bnload probe(lines);

      CHECK(probe.LLC == 1);
      CHECK(probe.LOTYP == 0);
      CHECK_FALSE(probe.COMPLX);
      CHECK(probe.NODENO == 15247);
      CHECK(probe.NDOF == 6);
      CHECK(probe.RLOAD == ref_rload);
      CHECK(probe.ILOAD.size() == 0);
   }
}

TEST_CASE("FEM BNLOAD types output.", "[fem_bnload,out]" ) {

   std::ostringstream test;

   double inp_rload[6] = {1., 2., 3., 4., 5., 6.};
   double inp_iload[6] = {1., 2., 3., 4., 5., 6.};

   SECTION("empty") {
      bnload probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("fixed") {
      bnload probe(1, 1, false, 4, 6,
                    std::deque<double>(inp_rload, inp_rload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("simple") {
      bnload probe(1, 1, false, 4, 6,
                    std::deque<double>(inp_rload, inp_rload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("simple (with ILOAD)") {
      bnload probe(1, 1, true, 4, 6,
                    std::deque<double>(inp_rload, inp_rload + 6),
                    std::deque<double>(inp_iload, inp_iload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  1.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n"
            "        +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("simple (calc COMPLX)") {
      bnload probe(1, 1, (long)4, 6,
                    std::deque<double>(inp_rload, inp_rload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("simple (with ILOAD, calc COMPLX)") {
      bnload probe(1, 1, (long)4, 6,
                    std::deque<double>(inp_rload, inp_rload + 6),
                    std::deque<double>(inp_iload, inp_iload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  1.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n"
            "        +1.00000000e+00 +2.00000000e+00 +3.00000000e+00 +4.00000000e+00 \n"
            "        +5.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("calc ndof") {
      bnload probe(1, 1, false, 4,
                    std::deque<double>(inp_rload, inp_rload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }
   SECTION("calc NDOF (calc COMPLX)") {
      bnload probe(1, 1, 4,
                    std::deque<double>(inp_rload, inp_rload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"
            "        +4.00000000e+00 +6.00000000e+00 +1.00000000e+00 +2.00000000e+00 \n"
            "        +3.00000000e+00 +4.00000000e+00 +5.00000000e+00 +6.00000000e+00 \n");
   }

   SECTION("calc NDOF (with ILOAD, calc COMPLX)") {
      bnload probe(1, 1, 4,
                    std::deque<double>(inp_rload, inp_rload + 6),
                    std::deque<double>(inp_iload, inp_iload + 6));
      test << probe;
      CHECK(test.str() ==
            "BNLOAD  +1.00000000e+00 +1.00000000e+00  1.00000000e+00  0.00000000e+00 \n"
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
