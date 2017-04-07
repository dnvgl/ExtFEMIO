/**
   \file tests/test_fem_cards_gelth.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GELTH` cards.

   Detailed description
*/

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

TEST_CASE("FEM GELTH definitions.", "[fem_gelth]" ) {

    vector<std::string> lines;
    size_t len;

    __base::geoprop::reset_geono();

    SECTION("GELTH (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GELTH    6.54394000e+005 1.00000000e-001 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gelth probe(lines, len);

        CHECK(probe.GEONO == 654394);
        CHECK(probe.TH == .1);
        CHECK(probe.NINT == 0);
    }

    SECTION("GELTH (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GELTH    6.54394000e+05  1.00000000e-01  0.000000000e+00 0.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gelth probe(lines, len);

        CHECK(probe.GEONO == 654394);
        CHECK(probe.TH == .1);
        CHECK(probe.NINT == 0);
    }
}

TEST_CASE("FEMIO-24: Failing to import line from SESAM GeniE FEM file") {

    vector<std::string> lines;
    __base::geoprop::reset_geono();

    SECTION("Failing card") {
        vector<std::string> data(
            {"GELTH     1.00000000E+00  2.99999993E-02\n"});
        size_t len{__base::card::card_split(data, data.size(), lines)};
        gelth probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.TH == 2.99999993e-02);
        CHECK(probe.NINT == 0);
    }
}

TEST_CASE("FEM GELTH types output.", "[fem_gelth,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        gelth probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gelth probe(1, 2., 3);
        test << probe;
        CHECK(test.str() ==
              "GELTH   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n");
    }

    SECTION("simple NINT default") {
        gelth probe(1, 2.);
        test << probe;
        CHECK(test.str() ==
              "GELTH   +1.000000000e+00+2.000000000e+00\n");
    }

    SECTION("simple NINT default (2)") {
        gelth probe(1, 2., 0);
        test << probe;
        CHECK(test.str() ==
              "GELTH   +1.000000000e+00+2.000000000e+00\n");
    }

    SECTION("simple GEONO default (1)") {
        gelth probe;
        test << probe(2.);
        test << probe(3.);
        CHECK(test.str() ==
              "GELTH   +1.000000000e+00+2.000000000e+00\n"
              "GELTH   +2.000000000e+00+3.000000000e+00\n");
    }

    SECTION("simple GEONO default (2)") {
        gelth probe;
        test << probe(2.);
        test << probe(3.);

        CHECK(test.str() ==
              "GELTH   +1.000000000e+00+2.000000000e+00\n"
              "GELTH   +2.000000000e+00+3.000000000e+00\n");
    }

    SECTION("simple GEONO default (3)") {
        gelth probe;
        test << probe(3, 2.);
        test << probe(4, 3.);
        test << probe(5.);
        test << probe(6.);
        CHECK(test.str() ==
              "GELTH   +3.000000000e+00+2.000000000e+00\n"
              "GELTH   +4.000000000e+00+3.000000000e+00\n"
              "GELTH   +1.000000000e+00+5.000000000e+00\n"
              "GELTH   +2.000000000e+00+6.000000000e+00\n");
    }
}

TEST_CASE("FEM GELTH conversion from own output.", "[fem_gelth,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GELTH (1)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GELTH   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gelth probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.TH == 2.);
        CHECK(probe.NINT == 3);
    }

    SECTION("GELTH (2)") {
        vector<std::string> data(
            // 2345678|234567890123456|234567890123456|234567890123456|234567890123456
            {"GELTH   +1.000000000e+00+2.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gelth probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.TH == 2.);
        CHECK(probe.NINT == 0);
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
