/**
   \file tests/test_fem_cards_gelmnt1.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GELMNT1` cards.

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

TEST_CASE("FEM GELMNT1 definitions.", "[fem_gelmnt1]" ) {

   std::deque<std::string> lines;

   SECTION("GELMNT1 (BEAS)") {
      std::deque<std::string> data;
      data.push_back("GELMNT1  1.13160000e+004 1.00000000e+000 1.50000000e+001 0.00000000e+000\n");
      data.push_back("         1.00000000e+001 1.10000000e+001 0.00000000e+000 0.00000000e+000\n");


      card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 11316);
      CHECK(probe.ELNO == 1);
      CHECK(probe.ELTYP == 15);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN.size() == 2);
      CHECK(probe.NODIN[0] == 10);
      CHECK(probe.NODIN[1] == 11);
   }

   SECTION("GELMNT1 (FQUS)") {
      std::deque<std::string> data;
      data.push_back("GELMNT1  1.00000000e+000 6.00000000e+000 2.40000000e+001 0.00000000e+000\n");
      data.push_back("         1.00000000e+000 6.00000000e+000 4.00000000e+000 2.00000000e+000\n");


      card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 1);
      CHECK(probe.ELNO == 6);
      CHECK(probe.ELTYP == 24);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN.size() == 4);
      CHECK(probe.NODIN[0] == 1);
      CHECK(probe.NODIN[1] == 6);
      CHECK(probe.NODIN[2] == 4);
      CHECK(probe.NODIN[3] == 2);
   }
}

TEST_CASE("FEM GELMNT1 types output.", "[fem_gelmnt1,out]" ) {

   std::ostringstream test;

   SECTION("GELMNT1 OUT (FQUS)") {
      long ELNOX(1), ELNO(6);
      elements::el_types ELTYP(elements::FQUS_FFQ);
      long ELTYAD(0);
      std::deque<long> NODIN;
      NODIN.push_back(1);
      NODIN.push_back(6);
      NODIN.push_back(4);
      NODIN.push_back(2);

      gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
      CHECK(probe.ELNOX == 1);
      CHECK(probe.ELNO == 6);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.ELTYP == elements::FQUS_FFQ);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.00000000e+00 +6.00000000e+00 +2.40000000e+01 +0.00000000e+00 \n"
            "        +1.00000000e+00 +6.00000000e+00 +4.00000000e+00 +2.00000000e+00 \n");
   }

   SECTION("GELMNT1 OUT (ILST)") {
      long ELNOX(12), ELNO(36);
      elements::el_types ELTYP(elements::ILST);
      long ELTYAD(0);
      std::deque<long> NODIN;
      NODIN.push_back(1);
      NODIN.push_back(6);
      NODIN.push_back(4);
      NODIN.push_back(2);
      NODIN.push_back(13);
      NODIN.push_back(22);

      gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.20000000e+01 +3.60000000e+01 +6.00000000e+00 +0.00000000e+00 \n"
            "        +1.00000000e+00 +6.00000000e+00 +4.00000000e+00 +2.00000000e+00 \n"
            "        +1.30000000e+01 +2.20000000e+01  0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("GELMNT1 OUT (BEAS)") {
      long ELNOX(12), ELNO(36);
      elements::el_types ELTYP(elements::BEAS);
      long ELTYAD(0);
      std::deque<long> NODIN;
      NODIN.push_back(1);
      NODIN.push_back(6);

      gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.20000000e+01 +3.60000000e+01 +1.50000000e+01 +0.00000000e+00 \n"
            "        +1.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
   }

   SECTION("GELMNT1 OUT (BEAS) (ELTYAD default)") {
      long ELNOX(12), ELNO(36);
      elements::el_types ELTYP(elements::BEAS);
      std::deque<long> NODIN;
      NODIN.push_back(1);
      NODIN.push_back(6);

      gelmnt1 probe(ELNOX, ELNO, ELTYP, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.20000000e+01 +3.60000000e+01 +1.50000000e+01 +0.00000000e+00 \n"
            "        +1.00000000e+00 +6.00000000e+00  0.00000000e+00  0.00000000e+00 \n");
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
