/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GECCEN` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_geccen[]) =
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

TEST_CASE("FEM GECCEN definitions.", "[fem_geccen]") {

    __base::eccno::reset_eccno();

    vector<std::string> lines;
    size_t len;

    SECTION("GECCEN (1)") {
        vector<std::string> data({
                "GECCEN   1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n"});
        len = __base::card::card_split(data, data.size(), lines);
        geccen probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.EX == 1.);
        CHECK(probe.EY == 3.);
        CHECK(probe.EZ == 134.);
    }

    SECTION("GECCEN (2)") {
        vector<std::string> data({
                "GECCEN   1.000000000e+00 1.000000000e+00 3.000000000e+00 1.34000000e+02 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        geccen probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.EX == 1.);
        CHECK(probe.EY == 3.);
        CHECK(probe.EZ == 134.);
    }

    SECTION("GECCEN (3)") {
        vector<std::string> data({
                "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
        len = __base::card::card_split(data, data.size(), lines);
        geccen probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.EX == 1.);
        CHECK(probe.EY == 3.);
        CHECK(probe.EZ == 134.);
    }

    SECTION("GECCEN check") {
        vector<std::string> data({
                "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
        len = __base::card::card_split(data, data.size(), lines);
        geccen probe(lines, len);

        CHECK_THROWS_AS(probe(lines, len), errors::usage_error);
    }
}

TEST_CASE("FEM GECCEN types output.", "[fem_geccen,out]") {

    __base::eccno::reset_eccno();
    ostringstream test;

    long ECCNO(1);
    double EX(1.), EY(3.), EZ(134.);

    SECTION("empty") {
        geccen probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("const") {
        geccen probe(1, 1., 3., 134.);
        test << probe;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
    }

    SECTION("simple") {
        geccen probe(ECCNO, EX, EY, EZ);
        test << probe;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
    }

    SECTION("vector") {
        geccen probe(ECCNO, vector<double>({EX, EY, EZ}));
        test << probe;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
    }

    SECTION("const (default eccno)") {
        geccen probe(1., 3., 134.);
        test << probe;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
    }

    SECTION("simple (default eccno)") {
        geccen probe(EX, EY, EZ);
        test << probe;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
    }

    SECTION("vector (default eccno)") {
        geccen probe(vector<double>({EX, EY, EZ}));
        test << probe;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
    }

    SECTION("multiple") {
        geccen probe1(vector<double>({1., 0., 0.}));
        geccen probe2(vector<double>({0., 1., 0.}));
        geccen probe3(vector<double>({0., 0., 1.}));
        geccen probe4(vector<double>({-1., 0., 0.}));
        geccen probe5(vector<double>({0., -1., 0.}));
        geccen probe6(vector<double>({0., 0., -1.}));
        test << probe1 << probe2 << probe3 << probe4 << probe5 << probe6;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "GECCEN  +2.000000000e+00+0.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "GECCEN  +3.000000000e+00+0.000000000e+00+0.000000000e+00+1.000000000e+00\n"
              "GECCEN  +4.000000000e+00-1.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "GECCEN  +5.000000000e+00+0.000000000e+00-1.000000000e+00+0.000000000e+00\n"
              "GECCEN  +6.000000000e+00+0.000000000e+00+0.000000000e+00-1.000000000e+00\n");
    }

    SECTION("multiple (2)") {
        geccen probe1(1., 0., 0.);
        geccen probe2(0., 1., 0.);
        geccen probe3(0., 0., 1.);
        geccen probe4(-1., 0., 0.);
        geccen probe5(0., -1., 0.);
        geccen probe6(0., 0., -1.);
        test << probe1 << probe2 << probe3 << probe4 << probe5 << probe6;
        CHECK(test.str() ==
              "GECCEN  +1.000000000e+00+1.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "GECCEN  +2.000000000e+00+0.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "GECCEN  +3.000000000e+00+0.000000000e+00+0.000000000e+00+1.000000000e+00\n"
              "GECCEN  +4.000000000e+00-1.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "GECCEN  +5.000000000e+00+0.000000000e+00-1.000000000e+00+0.000000000e+00\n"
              "GECCEN  +6.000000000e+00+0.000000000e+00+0.000000000e+00-1.000000000e+00\n");
    }
}

TEST_CASE("FEM GECCEN conversion from own output.", "[fem_geccen,in/out]") {

    vector<std::string> lines;

    SECTION("GECCEN") {
        vector<std::string> data({
                "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
        size_t len = __base::card::card_split(data, data.size(), lines);
        geccen probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.EX == 1.);
        CHECK(probe.EY == 3.);
        CHECK(probe.EZ == 134.);
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
