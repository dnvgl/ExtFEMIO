/**
   \file test_fem_cards_gbox.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing IO for Sesam FEM `GBOX` cards.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_fem_cards_gbox[] _EXTFEMIO_UNUSED =
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

CATCH_TRANSLATE_EXCEPTION(exception &ex) {
    return ex.what();
}

CATCH_TRANSLATE_EXCEPTION(std::string const &ex) {
    return ex;
}

TEST_CASE("FEM GBOX definitions.", "[fem_gbox]" ) {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GBOX (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GBOX     5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 1.00000000e+000\n",
             "         5.00000000e+000 5.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.TB == 125);
        CHECK(probe.TT == 16.);
        CHECK(probe.BY == 14.5);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 5);
        CHECK(probe.NLOBZ == 5);
    }

    SECTION("GBOX (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GBOX     5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 1.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.TB == 125);
        CHECK(probe.TT == 16.);
        CHECK(probe.BY == 14.5);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GBOX (3)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GBOX    +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.TB == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BY == 6.);
        CHECK(probe.SFY == 7.);
        CHECK(probe.SFZ == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GBOX (4)") {
        gbeamg _EXTFEMIO_UNUSED dummy;
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GBOX    +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.TB == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BY == 6.);
        CHECK(probe.SFY == 7.);
        CHECK(probe.SFZ == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GBOX (5)") {
        gbeamg _EXTFEMIO_UNUSED dummy;
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GBOX      1.00000000E+00  1.00000001E-01  9.99999978E-03  9.99999978E-03\n",
                "          9.99999978E-03  1.00000001E-01  1.00000000E+00  1.00000000E+00\n" });
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == .100000001);
        CHECK(probe.TY == .00999999978);
        CHECK(probe.TB == .00999999978);
        CHECK(probe.TT == .00999999978);
        CHECK(probe.BY == .100000001);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEMIO-25: Failing to import GBOX card from SESAM GeniE FEM file") {

    vector<std::string> lines;
    size_t len;
    SECTION("Failing card") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GBOX      6.00000000E+00  7.14999974E-01  9.99999978E-03  1.09999999E-02\n",
                "          1.00000005E-03  1.49999997E-02  1.00000000E+00  1.00000000E+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 6);
        CHECK(probe.HZ == 7.14999974e-1);
        CHECK(probe.TY == 9.99999978e-3);
        CHECK(probe.TB == 1.09999999e-2);
        CHECK(probe.TT == 1.00000005e-3);
        CHECK(probe.BY == 1.49999997e-2);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GBOX types output.", "[fem_gbox,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        gbox probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gbox probe(1, 2., 3., 4., 5., 6., 7., 8., 9, 10);
        test << probe;
        CHECK(test.str() ==
              "GBOX    +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01\n");
    }

    SECTION("default NLOB*") {
        gbox probe(1, 2., 3., 4., 5., 6., 7., 8.);
        test << probe;
        CHECK(test.str() ==
              "GBOX    +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }
}

TEST_CASE("FEM GBOX conversion from own output.", "[fem_gbox,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GBOX (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GBOX    +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
             "        +9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.TB == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BY == 6.);
        CHECK(probe.SFY == 7.);
        CHECK(probe.SFZ == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GBOX (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GBOX    +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gbox probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.TB == 4);
        CHECK(probe.TT == 5.);
        CHECK(probe.BY == 6.);
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
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
