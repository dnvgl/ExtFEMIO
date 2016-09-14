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

#include "config.h"

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

TEST_CASE("FEM GELMNT1 definitions.", "[fem_gelmnt1]" ) {

   std::list<std::string> lines;

   SECTION("GELMNT1 (BEAS)") {
      std::list<std::string> data({
         "GELMNT1  1.13160000e+004 1.00000000e+000 1.50000000e+001 0.00000000e+000\n",
         "         1.00000000e+001 1.10000000e+001 0.00000000e+000 0.00000000e+000\n"});


      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 11316);
      CHECK(probe.ELNO == 1);
      CHECK(probe.ELTYP == 15);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({10, 11}));
   }

   SECTION("GELMNT1 (FQUS)") {
      std::list<std::string> data({
         "GELMNT1  1.00000000e+000 6.00000000e+000 2.40000000e+001 0.00000000e+000\n",
         "         1.00000000e+000 6.00000000e+000 4.00000000e+000 2.00000000e+000\n"});

      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 1);
      CHECK(probe.ELNO == 6);
      CHECK(probe.ELTYP == 24);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({1, 6, 4, 2}));
   }

   SECTION("GELMNT1 (BEAS)") {
      std::list<std::string> data({
            "GELMNT1   1.00000000E+00  1.00000000E+00  1.50000000E+01  0.00000000E+00\n",
            "          1.00000000E+00  2.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 1);
      CHECK(probe.ELNO == 1);
      CHECK(probe.ELTYP == 15);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({1, 2}));
   }

   SECTION("GELMNT1 (BEAS) (empty fields)") {
      std::list<std::string> data({
            "GELMNT1   1.00000000E+00  1.00000000E+00  1.50000000E+01  0.00000000E+00\n",
            "          1.00000000E+00  2.00000000E+00\n"});
      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 1);
      CHECK(probe.ELNO == 1);
      CHECK(probe.ELTYP == 15);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({1, 2}));
   }
}

TEST_CASE("FEM GELMNT1 types output.", "[fem_gelmnt1,out]") {

   std::ostringstream test;

   SECTION("GELMNT1 OUT (empty)") {
      gelmnt1 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("GELMNT1 OUT (FQUS, const)") {
      long ELNOX(1), ELNO(6);
      elements::el_types ELTYP(elements::FQUS_FFQ);
      long ELTYAD(0);
      std::vector<long> NODIN({1, 6, 4, 2});

      gelmnt1 probe(1, 6, elements::FQUS_FFQ, 0, {1, 6, 4, 2});
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+6.000000000e+00+2.400000000e+01+0.000000000e+00\n"
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n");
   }

   SECTION("GELMNT1 OUT (FQUS)") {
      long ELNOX(1), ELNO(6);
      elements::el_types ELTYP(elements::FQUS_FFQ);
      long ELTYAD(0);
      std::vector<long> NODIN({1, 6, 4, 2});

      gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+6.000000000e+00+2.400000000e+01+0.000000000e+00\n"
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n");
   }

   SECTION("GELMNT1 OUT (FTRS)") {
      long ELNOX(1), ELNO(6);
      elements::el_types ELTYP(elements::FTRS_FFTR);
      long ELTYAD(0);
      std::vector<long> NODIN({1, 6, 4});

      gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.000000000e+00+6.000000000e+00+2.500000000e+01+0.000000000e+00\n"
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00\n");
   }

   SECTION("GELMNT1 OUT (ILST)") {
      long ELNOX(12), ELNO(36);
      elements::el_types ELTYP(elements::ILST);
      long ELTYAD(0);
      std::vector<long> NODIN({1, 6, 4, 2, 13, 22});

      gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.200000000e+01+3.600000000e+01+6.000000000e+00+0.000000000e+00\n"
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n"
            "        +1.300000000e+01+2.200000000e+01\n");
   }

   SECTION("GELMNT1 OUT (BEAS)") {
      long ELNOX(12), ELNO(36);
      elements::el_types ELTYP(elements::BEAS);
      long ELTYAD(0);
      std::vector<long> NODIN({1, 6});

      gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.200000000e+01+3.600000000e+01+1.500000000e+01+0.000000000e+00\n"
            "        +1.000000000e+00+6.000000000e+00\n");
   }

   SECTION("GELMNT1 OUT (BEAS) (ELTYAD default)") {
      long ELNOX(12), ELNO(36);
      elements::el_types ELTYP(elements::BEAS);
      std::vector<long> NODIN({1, 6});

      gelmnt1 probe(ELNOX, ELNO, ELTYP, NODIN);
      test << probe;
      CHECK(test.str() ==
            "GELMNT1 +1.200000000e+01+3.600000000e+01+1.500000000e+01+0.000000000e+00\n"
            "        +1.000000000e+00+6.000000000e+00\n");
   }
}

TEST_CASE("FEM GELMNT1 conversion from own output.", "[fem_gelmnt1,in/out]") {

   std::list<std::string> lines;

   SECTION("GELMNT1 (FQUS)") {
      std::list<std::string> data({
            "GELMNT1 +1.000000000e+00+6.000000000e+00+2.400000000e+01+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n"});

      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 1);
      CHECK(probe.ELNO == 6);
      CHECK(probe.ELTYP == elements::FQUS_FFQ);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({1, 6, 4, 2}));
   }

   SECTION("GELMNT1 (FTRS)") {
      std::list<std::string> data({
            "GELMNT1 +1.000000000e+00+6.000000000e+00+2.500000000e+01+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00\n"});

      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 1);
      CHECK(probe.ELNO == 6);
      CHECK(probe.ELTYP == elements::FTRS_FFTR);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({1, 6, 4}));
}

   SECTION("GELMNT1 (ILST)") {
      std::list<std::string> data({
            "GELMNT1 +1.200000000e+01+3.600000000e+01+6.000000000e+00+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n",
            "        +1.300000000e+01+2.200000000e+01\n"});

      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 12);
      CHECK(probe.ELNO == 36);
      CHECK(probe.ELTYP == elements::ILST);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({1, 6, 4, 2, 13, 22}));
   }

   SECTION("GELMNT1 (BEAS)") {
      std::list<std::string> data({
            "GELMNT1 +1.200000000e+01+3.600000000e+01+1.500000000e+01+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00\n"});

      __base::card::card_split(data, lines);
      gelmnt1 probe(lines);

      CHECK(probe.ELNOX == 12);
      CHECK(probe.ELNO == 36);
      CHECK(probe.ELTYP == elements::BEAS);
      CHECK(probe.ELTYAD == 0);
      CHECK(probe.NODIN == std::vector<long>({1, 6}));
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
