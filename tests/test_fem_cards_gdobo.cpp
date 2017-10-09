/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing IO for Sesam FEM `GDOBO` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_test_fem_cards_gdobo[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM GDOBO definitions.", "[fem_gdobo]" ) {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GDOBO (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GDOBO    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e-002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 1.00000000e+000\n",
             "         5.00000000e+000 5.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gdobo probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BY == .0125);
        CHECK(probe.TT == 16.);
        CHECK(probe.TB == 14.5);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 5);
        CHECK(probe.NLOBZ == 5);
    }

    SECTION("GDOBO (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GDOBO    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 1.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gdobo probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BY == 125);
        CHECK(probe.TT == 16.);
        CHECK(probe.TB == 14.5);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GDOBO (3)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gdobo probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.TB == 6.);
        CHECK(probe.SFY == 7.);
        CHECK(probe.SFZ == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GDOBO (4)") {
        gbeamg _EXTFEMIO_UNUSED(dummy);
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gdobo probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.TB == 6.);
        CHECK(probe.SFY == 7.);
        CHECK(probe.SFZ == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GDOBO (5)") {
        gbeamg _EXTFEMIO_UNUSED(dummy);
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GDOBO     1.00000000E+00  1.00000001E-01  9.99999978E-03  9.99999978E-03\n",
                "          9.99999978E-03  1.00000001E-01  1.00000000E+00  1.00000000E+00\n" });
        len = __base::card::card_split(data, data.size(), lines);
        gdobo probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == .100000001);
        CHECK(probe.TY == .00999999978);
        CHECK(probe.BY == .00999999978);
        CHECK(probe.TT == .00999999978);
        CHECK(probe.TB == .100000001);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GDOBO types output.", "[fem_gdobo,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        gdobo probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gdobo probe(1, 2., 3., 4., 5., 6., 7., 8., 9, 10);
        test << probe;
        CHECK(test.str() ==
              "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01\n");
    }

    SECTION("default NLOB*") {
        gdobo probe(1, 2., 3., 4., 5., 6., 7., 8.);
        test << probe;
        CHECK(test.str() ==
              "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }

    SECTION("default SF*, NLOB*") {
        gdobo probe(1, 2., 3., 4., 5., 6.);
        test << probe;
        CHECK(test.str() ==
              "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+1.000000000e+00+1.000000000e+00\n");
    }

    SECTION("simple (call)") {
        gdobo probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8., 9, 10);
        CHECK(test.str() ==
              "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01\n");
    }

    SECTION("default NLOB* (call)") {
        gdobo probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8.);
        CHECK(test.str() ==
              "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }

    SECTION("default SF*, NLOB* (call)") {
        gdobo probe;
        test << probe(1, 2., 3., 4., 5., 6.);
        CHECK(test.str() ==
              "GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+1.000000000e+00+1.000000000e+00\n");
    }
}

TEST_CASE("FEM GDOBO conversion from own output.", "[fem_gdobo,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GDOBO (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
             "        +9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gdobo probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.TB == 6.);
        CHECK(probe.SFY == 7.);
        CHECK(probe.SFZ == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GDOBO (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GDOBO   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gdobo probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.TB == 6.);
        CHECK(probe.SFY == 7.);
        CHECK(probe.SFZ == 8.);
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
