/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GIORH` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
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

TEST_CASE("FEM GIORH definitions.", "[fem_giorh]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GIORH (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
        {"GIORH    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
        "         1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000\n",
        "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorh probe(lines, len);

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
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
        {"GIORH    5.000000000e+00 4.66000000e+02  1.450000000e+01 1.25000000e+02 \n",
        "         1.600000000e+01 1.450000000e+01 1.600000000e+01 1.000000000e+00\n",
        "         1.000000000e+00 0.000000000e+00 0.000000000e+00 0.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorh probe(lines, len);

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
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
            "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorh probe(lines, len);

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

    SECTION("GIORH (4)") {
        gbeamg _EXTFEMIO_UNUSED dummy(1, 100.);
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
            "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
            "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorh probe(lines, len);

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

TEST_CASE("FEMIO-25: Failing to import GIORH card from SESAM GeniE FEM file", "[fem_giorh]") {

    vector<std::string> lines;
    SECTION("Failing card") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "GIORH     6.00000000E+00  7.14999974E-01  9.99999978E-03  1.09999999E-02\n",
            "          1.00000005E-03  1.50000006E-01  1.49999997E-02  1.00000000E+00\n",
            "          1.00000000E+00\n"});
        size_t len{__base::card::card_split(data, data.size(), lines)};
        giorh probe(lines, len);

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

TEST_CASE("FEM GIORH types output.", "[fem_giorh,out]") {

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

    SECTION("default SF*, NLOB*") {
        giorh probe(1, 2., 3., 4., 5., 6., 7.);
        test << probe;
        CHECK(test.str() ==
              "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+1.000000000e+00\n"
              "        +1.000000000e+00\n");
    }

    SECTION("simple (call)") {
        giorh probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10, 11, 12);
        CHECK(test.str() ==
              "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n");
    }

    SECTION("default NLOB* (call)") {
        giorh probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8., 9.);
        CHECK(test.str() ==
              "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00\n");
    }

    SECTION("default SF*, NLOB* (call)") {
        giorh probe;
        test << probe(1, 2., 3., 4., 5., 6., 7.);
        CHECK(test.str() ==
              "GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+1.000000000e+00\n"
              "        +1.000000000e+00\n");
    }
}

TEST_CASE("FEM GIORH conversion from own output.", "[fem_giorh,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GIORH (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
        {"GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
        "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
        "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorh probe(lines, len);

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
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
        {"GIORH   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
        "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
        "        +9.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorh probe(lines, len);

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
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
