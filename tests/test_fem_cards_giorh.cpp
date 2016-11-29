/**
   \file tests/test_fem_cards_giorh.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GIORH` cards.

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

TEST_CASE("FEM GIORH definitions.", "[fem_giorh]" ) {

   std::list<std::string> lines;

    __base::geoprop::reset_geono();

   SECTION("GIORH (1)") {
      std::list<std::string> data(
          // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
          {"GIORH    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
                  "         1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000\n",
                  "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
      __base::card::card_split(data, lines);
      giorh probe(lines);

      CHECK(probe.GEONO == 5);
      CHECK(probe.HZ == 466.);
      CHECK(probe.TY == 14.5);
      CHECK(probe.BT == 125);
      CHECK(probe.TT == 16.);
      CHECK(probe.BB == 14.5);
      CHECK(probe.TB == 16.);
      CHECK(probe.SFY == 1.);
      CHECK(probe.SFZ == 1.);
      CHECK(probe.NLOBYT == 0);
      CHECK(probe.NLOBYB == 0);
      CHECK(probe.NLOBZ == 0);
   }

   SECTION("GIORH (2)") {
       std::list<std::string> data(
           // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
           {"GIORH    5.000000000e+00 4.66000000e+02  1.450000000e+01 1.25000000e+02 \n",
                   "         1.600000000e+01 1.450000000e+01 1.600000000e+01 1.000000000e+00\n",
                   "         1.000000000e+00 0.000000000e+00 0.000000000e+00 0.000000000e+00\n"});
       __base::card::card_split(data, lines);
       giorh probe(lines);

       CHECK(probe.GEONO == 5);
       CHECK(probe.HZ == 466.);
       CHECK(probe.TY == 14.5);
       CHECK(probe.BT == 125);
       CHECK(probe.TT == 16.);
       CHECK(probe.BB == 14.5);
       CHECK(probe.TB == 16.);
       CHECK(probe.SFY == 1.);
       CHECK(probe.SFZ == 1.);
       CHECK(probe.NLOBYT == 0);
       CHECK(probe.NLOBYB == 0);
       CHECK(probe.NLOBZ == 0);
   }

   SECTION("GIORH (3)") {
       std::list<std::string> data({
               // 345678|234567890123456|234567890123456|234567890123456|234567890123456
               "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                   "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                   "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"});
       __base::card::card_split(data, lines);
       giorh probe(lines);

       CHECK(probe.GEONO == 1);
       CHECK(probe.HZ == 2.);
       CHECK(probe.TY == 3.);
       CHECK(probe.BT == 4);
       CHECK(probe.TT == 5.);
       CHECK(probe.BB == 6.);
       CHECK(probe.TB == 7.);
       CHECK(probe.SFY == 8.);
       CHECK(probe.SFZ == 9.);
       CHECK(probe.NLOBYT == 10);
       CHECK(probe.NLOBYB == 11);
       CHECK(probe.NLOBZ == 12);
   }
}

TEST_CASE("FEMIO-25: Failing to import GIORH card from SESAM GeniE FEM file") {

    std::list<std::string> lines;

    SECTION("Failing card") {
        std::list<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GIORH     6.00000000E+00  7.14999974E-01  9.99999978E-03  1.09999999E-02\n",
                    "          1.00000005E-03  1.50000006E-01  1.49999997E-02  1.00000000E+00\n",
                    "          1.00000000E+00\n"});
        __base::card::card_split(data, lines);
        giorh probe(lines);

        CHECK(probe.GEONO == 6);
        CHECK(probe.HZ == 7.14999974e-1);
        CHECK(probe.TY == 9.99999978e-3);
        CHECK(probe.BT == 1.09999999e-2);
        CHECK(probe.TT == 1.00000005e-3);
        CHECK(probe.BB == 1.50000006e-1);
        CHECK(probe.TB == 1.49999997e-2);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GIORH types output.", "[fem_giorh,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        giorh probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        giorh probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10, 11, 12);
        test << probe;
        CHECK(test.str() ==
              "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n");
    }

    SECTION("default NLOB*") {
        giorh probe(1, 2., 3., 4., 5., 6., 7., 8., 9.);
        test << probe;
        CHECK(test.str() ==
              "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00\n");
    }
}

TEST_CASE("FEM GIORH conversion from own output.", "[fem_giorh,in/out]") {

    std::list<std::string> lines;

    __base::geoprop::reset_geono();

    SECTION("GIORH (1)") {
        std::list<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
             "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"});
        __base::card::card_split(data, lines);
        giorh probe(lines);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BT == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BB == 6.);
        CHECK(probe.TB == 7.);
        CHECK(probe.SFY == 8.);
        CHECK(probe.SFZ == 9.);
        CHECK(probe.NLOBYT == 10);
        CHECK(probe.NLOBYB == 11);
        CHECK(probe.NLOBZ == 12);
    }

    SECTION("GIORH (2)") {
        std::list<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
             "        +9.000000000e+00\n"});
        __base::card::card_split(data, lines);
        giorh probe(lines);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BT == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BB == 6.);
        CHECK(probe.TB == 7.);
        CHECK(probe.SFY == 8.);
        CHECK(probe.SFZ == 9.);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
