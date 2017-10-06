/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GBARM` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_gbarm[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM GBARM definitions.", "[fem_gbarm]" ) {

    vector<std::string> lines;
    __base::geoprop::reset_geono();
    size_t len;

    SECTION("GBARM (1)") {
        vector<std::string> data(
            {"GBARM    2.00000000e+000 2.50000000e+002 3.20000000e+001 3.20000000e+001\n",
             "         1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbarm probe(lines, len);

        CHECK(probe.GEONO == 2);
        CHECK(probe.HZ == 250.);
        CHECK(probe.BT == 32.);
        CHECK(probe.BB == 32.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GBARM (2)") {
        vector<std::string> data(
            {"GBARM    2.000000000e+00 2.50000000e+02  3.200000000e+01 3.200000000e+01\n",
             "         1.000000000e+00 1.000000000e+00 0.000000000e+00 0.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbarm probe(lines, len);

        CHECK(probe.GEONO == 2);
        CHECK(probe.HZ == 250.);
        CHECK(probe.BT == 32.);
        CHECK(probe.BB == 32.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEMIO-37: Failing to import GBARM record from SESAM GeniE FEM file", "[fem_gbarm]") {

    vector<std::string> lines;
    __base::geoprop::reset_geono();

    SECTION("Failing card") {
        vector<std::string> data({
                "GBARM     2.80000000E+01  1.50000006E-01  1.20000001E-02  1.20000001E-02\n",
                    "          1.00000000E+00  1.00000000E+00\n"});
        size_t len{__base::card::card_split(data, data.size(), lines)};
        gbarm probe(lines, len);

        CHECK(probe.GEONO == 28);
        CHECK(probe.HZ == .150000006);
        CHECK(probe.BT == .0120000001);
        CHECK(probe.BB == .0120000001);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GBARM types output.", "[fem_gbarm,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        gbarm probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gbarm probe(1, 2., 3., 4., 5., 6., 7, 8);
        test << probe;
        CHECK(test.str() ==
              "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }

    SECTION("simple (default N*)") {
        gbarm probe(1, 2., 3., 4., 5., 6.);
        test << probe;
        CHECK(test.str() ==
              "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("simple (default SF* and N*)") {
        gbarm probe(1, 2., 3., 4.);
        test << probe;
        CHECK(test.str() ==
              "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +1.000000000e+00+1.000000000e+00\n");
    }

    SECTION("simple (call)") {
        gbarm probe;
        test << probe(1, 2., 3., 4., 5., 6., 7, 8);
        CHECK(test.str() ==
              "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }

    SECTION("simple (default N*) (call)") {
        gbarm probe;
        test << probe(1, 2., 3., 4., 5., 6.);
        CHECK(test.str() ==
              "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("simple (default SF* and N*) (call)") {
        gbarm probe;
        test << probe(1, 2., 3., 4.);
        CHECK(test.str() ==
              "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +1.000000000e+00+1.000000000e+00\n");
    }
}

TEST_CASE("FEM GBARM conversion from own output.", "[fem_gbarm,in/out]") {

    vector<std::string> lines;
    __base::geoprop::reset_geono();
    size_t len;

    SECTION("GBARM (1)") {
        vector<std::string> data({
                "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbarm probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.BT == 3.);
        CHECK(probe.BB == 4.);
        CHECK(probe.SFY == 5.);
        CHECK(probe.SFZ == 6.);
        CHECK(probe.NLOBY == 7);
        CHECK(probe.NLOBZ == 8);
    }

    SECTION("GBARM (2)") {
        vector<std::string> data({
                "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbarm probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.BT == 3.);
        CHECK(probe.BB == 4.);
        CHECK(probe.SFY == 5.);
        CHECK(probe.SFZ == 6.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GBARM (3)") {
        gbeamg _EXTFEMIO_UNUSED(dummy)(1, 100.);
        vector<std::string> data({
                "GBARM   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                    "        +5.000000000e+00+6.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbarm probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.BT == 3.);
        CHECK(probe.BB == 4.);
        CHECK(probe.SFY == 5.);
        CHECK(probe.SFZ == 6.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
