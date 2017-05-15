/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing IO for Sesam FEM `GCHAN` cards.

   Detailed description
*/
#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_fem_cards_gchan[] _EXTFEMIO_UNUSED =
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

TEST_CASE("FEM GCHAN definitions.", "[fem_gchan]" ) {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GCHAN (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHAN    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.00000000e+000 1.00000000e+000\n",
             "         1.00000000e+000 5.00000000e+000 5.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchan probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BY == 125);
        CHECK(probe.TZ == 16.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K == 1);
        CHECK(probe.NLOBY == 5);
        CHECK(probe.NLOBZ == 5);
    }

    SECTION("GCHAN (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHAN    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.00000000e+000\n",
             "         1.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchan probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BY == 125);
        CHECK(probe.TZ == 16.);
        CHECK(probe.SFY == 14.5);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K == 1);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GCHAN (3)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
                "        +8.000000000e+00+9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchan probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4.);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GCHAN (4)") {
        gbeamg _EXTFEMIO_UNUSED dummy;
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
                "        +8.000000000e+00+9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchan probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GCHAN (5)") {
        gbeamg _EXTFEMIO_UNUSED dummy;
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GCHAN     1.00000000E+00  1.00000001E-01  9.99999978E-03  9.99999978E-03\n",
                "          9.99999978E-03  1.00000000E+00  1.00000000E+00\n",
                "          1.00000000E+00\n" });
        len = __base::card::card_split(data, data.size(), lines);
        gchan probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == .100000001);
        CHECK(probe.TY == .00999999978);
        CHECK(probe.BY == .00999999978);
        CHECK(probe.TZ == .00999999978);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K == 1);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GCHAN types output.", "[fem_gchan,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        gchan probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gchan probe(1, 2., 3., 4., 5., 6., 7., 8, 9, 10);
        test << probe;
        CHECK(test.str() ==
              "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00+9.000000000e+00+1.000000000e+01\n");
    }

    SECTION("default NLOB*") {
        gchan probe(1, 2., 3., 4., 5., 6., 7., 8);
        test << probe;
        CHECK(test.str() ==
              "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00\n");
    }

    SECTION("default SF*, NLOB*") {
        gchan probe(1, 2., 3., 4., 5., 6);
        test << probe;
        CHECK(test.str() ==
              "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+1.000000000e+00+1.000000000e+00\n"
              "        +6.000000000e+00\n");
    }

    SECTION("simple (instance)") {
        gchan probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8, 9, 10);
        CHECK(test.str() ==
              "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00+9.000000000e+00+1.000000000e+01\n");
    }

    SECTION("default NLOB* (instance)") {
        gchan probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8);
        CHECK(test.str() ==
              "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n"
              "        +8.000000000e+00\n");
    }

    SECTION("default SF*, NLOB* (instance)") {
        gchan probe;
        test << probe(1, 2., 3., 4., 5., 6);
        CHECK(test.str() ==
              "GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+1.000000000e+00+1.000000000e+00\n"
              "        +6.000000000e+00\n");
    }
}

TEST_CASE("FEM GCHAN conversion from own output.", "[fem_gchan,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GCHAN (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
             "        +8.000000000e+00+9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gchan probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8.);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GCHAN (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GCHAN   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
             "        +5.000000000e+00+6.000000000e+00+7.000000000e+00\n",
             "        +8.000000000e+00"});
        len = __base::card::card_split(data, data.size(), lines);
        gchan probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K == 8.);
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
