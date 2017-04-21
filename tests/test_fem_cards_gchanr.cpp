/**
   \file test_fem_cards_gchanr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing IO for Sesam FEM `GCHANR` cards.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_fem_cards_gchanr[] _EXTFEMIO_UNUSED =
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

TEST_CASE("FEM GCHANR definitions.", "[fem_gchanr]" ) {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GCHANR (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHANR   1.16000000e+002 2.00000000e-001 8.50000000e-003 7.50000000e-002\n",
             "         1.15000000e-002 1.00000000e+000 1.00000000e+000 0.00000000e+000\n",
             "         1.00000000e+000 5.00000000e-004 5.00000000e+000 6.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchanr probe(lines, len);

        CHECK(probe.GEONO == 116);
        CHECK(probe.HZ == .2);
        CHECK(probe.TY == .0085);
        CHECK(probe.BY == .075);
        CHECK(probe.TZ == .0115);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K == 1);
        CHECK(probe.R == .0005);
        CHECK(probe.NLOBY == 5);
        CHECK(probe.NLOBZ == 6);
    }

    SECTION("GCHANR (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHANR   5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000 0.00000000e+000\n",
             "         1.00000000e+000 1.45000000e-003\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchanr probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BY == 125);
        CHECK(probe.TZ == 16.);
        CHECK(probe.SFY == 14.5);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K == 1);
        CHECK(probe.R == .00145);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GCHANR (3)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
                "        +8.000000000e+00+9.000000000e+00+1.000000000e+01+1.100000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchanr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8);
        CHECK(probe.R == 9.);
        CHECK(probe.NLOBY == 10);
        CHECK(probe.NLOBZ == 11);
    }

    SECTION("GCHANR (4)") {
        gbeamg _EXTFEMIO_UNUSED dummy(1, 100.);
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
                "        +8.000000000e+00+9.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchanr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8);
        CHECK(probe.R == 9);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GCHANR types output.", "[fem_gchanr,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        gchanr probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gchanr probe(1, 2., 3., 4., 5., 6., 7., 8, 9., 10, 11);
        test << probe;
        CHECK(test.str() ==
              "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00+9.000000000e+00+1.000000000e+01+1.100000000e+01\n");
    }

    SECTION("default NLOB*") {
        gchanr probe(1, 2., 3., 4., 5., 6., 7., 8, 9.);
        test << probe;
        CHECK(test.str() ==
              "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00+9.000000000e+00\n");
    }

    SECTION("default SF*, NLOB*") {
        gchanr probe(1, 2., 3., 4., 5., 6, 7.);
        test << probe;
        CHECK(test.str() ==
              "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+1.000000000e+00+1.000000000e+00\n"
              "        +6.000000000e+00+7.000000000e+00\n");
    }

    SECTION("simple (instance)") {
        gchanr probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8, 9., 10, 11);
        CHECK(test.str() ==
              "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00+9.000000000e+00+1.000000000e+01+1.100000000e+01\n");
    }

    SECTION("default NLOB* (instance)") {
        gchanr probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8, 9.);
        CHECK(test.str() ==
              "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00+9.000000000e+00\n");
    }

    SECTION("default SF*, NLOB* (instance)") {
        gchanr probe;
        test << probe(1, 2., 3., 4., 5., 6, 7.);
        CHECK(test.str() ==
              "GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+1.000000000e+00+1.000000000e+00\n"
              "        +6.000000000e+00+7.000000000e+00\n");
    }
}

TEST_CASE("FEM GCHANR conversion from own output.", "[fem_gchanr,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GCHANR (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
             "        +8.000000000e+00+9.000000000e+00+1.000000000e+01+1.100000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchanr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8);
        CHECK(probe.R == 9.);
        CHECK(probe.NLOBY == 10);
        CHECK(probe.NLOBZ == 11);
    }

    SECTION("GCHANR (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHANR  +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
             "        +8.000000000e+00+9.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchanr probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8);
        CHECK(probe.R == 9.);
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
