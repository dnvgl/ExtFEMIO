/**
   \file test_fem_cards_giorhr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing IO for Sesam FEM `GIRORHR` cards.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_fem_cards_giorhr[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
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

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM GIORHR definitions.", "[fem_giorhr]" ) {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GIORHR (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GIORHR   5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 1.00000000e+000\n",
             "         5.00000000e+000 5.00000000e-003 6.00000000e-003\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorhr probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.TB == 1.);
        CHECK(probe.TT == 16.);
        CHECK(probe.BB == 14.5);
        CHECK(probe.TB == 1.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 5.);
        CHECK(probe.RT == .005);
        CHECK(probe.RB == .006);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GIORHR (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GIORHR   5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 1.00000000e+000\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 1.00000000e+000\n",
             "         1.60000000e+001 1.40000000e+001\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorhr probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BT == 125.);
        CHECK(probe.TT == 16.);
        CHECK(probe.BB == 14.5);
        CHECK(probe.TB == 1.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 16);
        CHECK(probe.RT == 14.5);
        CHECK(probe.RB == 1.);
        CHECK(probe.NLOBYT == 1);
        CHECK(probe.NLOBYB == 16);
        CHECK(probe.NLOBZ == 14);
    }

    SECTION("GIORHR (3)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n",
                "        +1.300000000e+01+1.400000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorhr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BT == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BB == 6.);
        CHECK(probe.TB == 7.);
        CHECK(probe.SFY == 8.);
        CHECK(probe.SFZ == 9.);
        CHECK(probe.RT == 10.);
        CHECK(probe.RB == 11.);
        CHECK(probe.NLOBYT == 12);
        CHECK(probe.NLOBYB == 13);
        CHECK(probe.NLOBZ == 14);
    }

    SECTION("GIORHR (4)") {
        gbeamg _EXTFEMIO_UNUSED dummy;
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01+1.100000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorhr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BT == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BB == 6.);
        CHECK(probe.TB == 7.);
        CHECK(probe.SFY == 8.);
        CHECK(probe.SFZ == 9.);
        CHECK(probe.RT == 10.);
        CHECK(probe.RB == 11.);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GIORHR (5)") {
        gbeamg _EXTFEMIO_UNUSED dummy;
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GIORHR    1.00000000E+00  1.00000001E-01  9.99999978E-03  9.99999978E-03\n",
                "          9.99999978E-03  1.00000001E-01  1.00000000E+00  1.00000000E+00\n",
                "          9.99999978E-03  1.00000001E-01  1.00000000E+00\n" });
        len = __base::card::card_split(data, data.size(), lines);
        giorhr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == .100000001);
        CHECK(probe.TY == .00999999978);
        CHECK(probe.BT == .00999999978);
        CHECK(probe.TT == .00999999978);
        CHECK(probe.BB == .100000001);
        CHECK(probe.TB == 1.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == .00999999978);
        CHECK(probe.RT == .100000001);
        CHECK(probe.RB == 1.);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GIORHR types output.", "[fem_giorhr,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        giorhr probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        giorhr probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12, 13, 14);
        test << probe;
        CHECK(test.str() ==
              "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01\n");
    }

    SECTION("default NLOB*") {
        giorhr probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10., 11.);
        test << probe;
        CHECK(test.str() ==
              "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01\n");
    }

    SECTION("default SF*, NLOB*") {
        giorhr probe(1, 2., 3., 4., 5., 6., 7., 8., 9.);
        test << probe;
        CHECK(test.str() ==
              "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+1.000000000e+00\n"
              "        +1.000000000e+00+8.000000000e+00+9.000000000e+00\n");
    }

    SECTION("simple (call)") {
        giorhr probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12, 13, 14);
        CHECK(test.str() ==
              "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01\n");
    }

    SECTION("default NLOB* (call)") {
        giorhr probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10., 11.);
        CHECK(test.str() ==
              "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01\n");
    }

    SECTION("default SF*, NLOB* (call)") {
        giorhr probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8., 9.);
        CHECK(test.str() ==
              "GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+1.000000000e+00\n"
              "        +1.000000000e+00+8.000000000e+00+9.000000000e+00\n");
    }
}

TEST_CASE("FEM GIORHR conversion from own output.", "[fem_giorhr,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GIORHR (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
             "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n",
             "        +1.300000000e+01+1.400000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorhr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BT == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BB == 6.);
        CHECK(probe.TB == 7.);
        CHECK(probe.SFY == 8.);
        CHECK(probe.SFZ == 9.);
        CHECK(probe.RT == 10.);
        CHECK(probe.RB == 11.);
        CHECK(probe.NLOBYT == 12);
        CHECK(probe.NLOBYB == 13);
        CHECK(probe.NLOBZ == 14);
    }

    SECTION("GIORHR (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GIORHR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
             "        +9.000000000e+00+1.000000000e+01+1.100000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        giorhr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BT == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BB == 6.);
        CHECK(probe.TB == 7.);
        CHECK(probe.SFY == 8.);
        CHECK(probe.SFZ == 9.);
        CHECK(probe.RT == 10.);
        CHECK(probe.RB == 11.);
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
