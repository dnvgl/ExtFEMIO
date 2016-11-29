/**
   \file tests/test_fem_cards_gpipe.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GPIPE` cards.

   Detailed description
*/

// ID:
namespace {
    const char cID[]
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

TEST_CASE("FEM GPIPE definitions.", "[fem_gpipe]" ) {

    std::list<std::string> lines;

    __base::geoprop::reset_geono();

    SECTION("GPIPE (1)") {
        std::list<std::string> data(
            {"GPIPE    6.54357000e+005 0.00000000e+000 5.90218891e-002 2.95109446e-002\n",
             "         1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        __base::card::card_split(data, lines);
        gpipe probe(lines);

        CHECK(probe.GEONO == 654357);
        CHECK(probe.DI == 0.);
        CHECK(probe.DY == 5.90218891e-2);
        CHECK(probe.T == 2.95109446e-2);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NCIR == 0);
        CHECK(probe.NRAD == 0);
    }

    SECTION("GPIPE (2)") {
        std::list<std::string> data(
            {"GPIPE    6.54357000e+05  0.000000000e+00 5.90218891e-02  2.95109446e-02 \n",
             "         1.000000000e+00 1.000000000e+00 0.000000000e+00 0.000000000e+00\n"});
        __base::card::card_split(data, lines);
        gpipe probe(lines);

        CHECK(probe.GEONO == 654357);
        CHECK(probe.DI == 0.);
        CHECK(probe.DY == 5.90218891e-2);
        CHECK(probe.T == 2.95109446e-2);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NCIR == 0);
        CHECK(probe.NRAD == 0);
    }
}

TEST_CASE("FEMIO-26: Failing to import GPIPE card from SESAM GeniE FEM file") {

    std::list<std::string> lines;

    __base::geoprop::reset_geono();

    SECTION("Failing card") {
        std::list<std::string> data(
            {"GPIPE     1.80000000E+01  1.49100006E-01  2.19100013E-01  3.50000001E-02\n",
             "          1.00000000E+00  1.00000000E+00\n"});
        __base::card::card_split(data, lines);
        gpipe probe(lines);

        CHECK(probe.GEONO == 18);
        CHECK(probe.DI == 1.49100006e-1);
        CHECK(probe.DY == 2.19100013e-1);
        CHECK(probe.T == 3.50000001e-2);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NCIR == 0);
        CHECK(probe.NRAD == 0);
    }
}

TEST_CASE("FEM GPIPE types output.", "[fem_gpipe,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("emtpy") {
        gpipe probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gpipe probe(1, 2., 3., 4., 5., 6., 7, 8);
        test << probe;
        CHECK(test.str() ==
              "GPIPE   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }

    SECTION("NC* default") {
        gpipe probe(1, 2., 3., 4., 5., 6.);
        test << probe;
        CHECK(test.str() ==
              "GPIPE   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }
}

TEST_CASE("FEM GPIPE conversion from own output.", "[fem_gpipe,in/out]") {

    std::list<std::string> lines;

    __base::geoprop::reset_geono();

    SECTION("GPIPE (1)") {
        std::list<std::string> data(
            {"GPIPE   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"});
        __base::card::card_split(data, lines);
        gpipe probe(lines);

        CHECK(probe.GEONO == 1);
        CHECK(probe.DI == 2.);
        CHECK(probe.DY == 3.);
        CHECK(probe.T == 4.);
        CHECK(probe.SFY == 5.);
        CHECK(probe.SFZ == 6.);
        CHECK(probe.NCIR == 7);
        CHECK(probe.NRAD == 8);
    }

    SECTION("GPIPE (2)") {
        std::list<std::string> data(
            {"GPIPE   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00\n"});
        __base::card::card_split(data, lines);
        gpipe probe(lines);

        CHECK(probe.GEONO == 1);
        CHECK(probe.DI == 2.);
        CHECK(probe.DY == 3.);
        CHECK(probe.T == 4.);
        CHECK(probe.SFY == 5.);
        CHECK(probe.SFZ == 6.);
        CHECK(probe.NCIR == 0);
        CHECK(probe.NRAD == 0);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
