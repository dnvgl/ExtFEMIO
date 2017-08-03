/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing IO for Sesam FEM `GECC` cards.

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

TEST_CASE("FEM GECC definitions.", "[fem_gecc]") {

    __base::eccno::reset_eccno();

    vector<std::string> lines;
    size_t len;

    SECTION("GECC (1)") {
        vector<std::string> data({
                // 345678!234567890123456!234567890123456!234567890123456!234567890123456
                "GECC     1.00000000e+000 2.00000000e+000 1.00000000e+000 3.00000000e+000\n", 
                "         1.34000000e+002\n"});
        len = __base::card::card_split(data, data.size(), lines);
        CHECK(len == 9);
        gecc probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.IOPT == gecc::ecc_opt::XYZ);
        CHECK(probe.EX == 1.);
        CHECK(probe.EY == 3.);
        CHECK(probe.EZ == 134.);
    }

    SECTION("GECC (2)") {
        vector<std::string> data({
                "GECC     1.000000000e+00 2.000000000e+00 1.000000000e+00 3.000000000e+00\n", 
                "         1.34000000e+002\n"});
        len = __base::card::card_split(data, data.size(), lines);
        CHECK(len == 9);
        gecc probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.IOPT == gecc::ecc_opt::XYZ);
        CHECK(probe.EX == 1.);
        CHECK(probe.EY == 3.);
        CHECK(probe.EZ == 134.);
    }

    SECTION("GECC (3)") {
        vector<std::string> data({
                "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n", 
                "        +1.340000000e+02\n"});
        len = __base::card::card_split(data, data.size(), lines);
        CHECK(len == 9);
        gecc probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.IOPT == gecc::ecc_opt::XYZ);
        CHECK(probe.EX == 1.);
        CHECK(probe.EY == 3.);
        CHECK(probe.EZ == 134.);
    }

    SECTION("GECC (4)") {
        vector<std::string> data({
                "GECC     1.00000000e+000 1.00000000e+000 1.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        CHECK(len == 5);
        gecc probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.IOPT == gecc::ecc_opt::Z_ONLY);
        CHECK(probe.EX == 0.);
        CHECK(probe.EY == 0.);
        CHECK(probe.EZ == 1.);
    }

    SECTION("GECC check") {
        vector<std::string> data({
                "GECC    +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gecc probe(lines, len);

        CHECK_THROWS_AS(probe(lines, len), errors::usage_error);
    }
}

TEST_CASE("FEM GECC types output.", "[fem_gecc,out]") {

    __base::eccno::reset_eccno();
    std::ostringstream test;

    long ECCNO{1};
    double EX{1.}, EY{3.}, EZ{134.};

    SECTION("empty") {
        gecc probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("const") {
        gecc probe(1, 1., 3., 134.);
        test << probe;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n"
              "        +1.340000000e+02\n");
    }

    SECTION("simple") {
        gecc probe(ECCNO, gecc::ecc_opt::XYZ, EX, EY, EZ);
        test << probe;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n"
              "        +1.340000000e+02\n");
    }

    SECTION("vector") {
        gecc probe(ECCNO, std::vector<double>({EX, EY, EZ}));
        test << probe;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n"
              "        +1.340000000e+02\n");
    }

    SECTION("const (default eccno)") {
        gecc probe(1., 3., 134.);
        test << probe;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n"
              "        +1.340000000e+02\n");
    }

    SECTION("simple (default eccno)") {
        gecc probe(EX, EY, EZ);
        test << probe;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n"
              "        +1.340000000e+02\n");
    }

    SECTION("vector (default eccno)") {
        gecc probe(std::vector<double>({EX, EY, EZ}));
        test << probe;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n"
              "        +1.340000000e+02\n");
    }

    SECTION("simple (z_only)") {
        gecc probe(22, EZ);
        test << probe;
        CHECK(test.str() ==
              "GECC    +2.200000000e+01+1.000000000e+00+1.340000000e+02\n");
    }

    SECTION("simple (default eccno, z_only") {
        elements::__base::elem::reset();
        gecc probe(EZ);
        test << probe;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+1.000000000e+00+1.340000000e+02\n");
    }

    SECTION("multiple") {
        gecc probe1(std::vector<double>({1., 0., 0.}));
        gecc probe2(std::vector<double>({0., 1., 0.}));
        gecc probe3(std::vector<double>({0., 0., 1.}));
        gecc probe4(std::vector<double>({-1., 0., 0.}));
        gecc probe5(std::vector<double>({0., -1., 0.}));
        gecc probe6(std::vector<double>({0., 0., -1.}));
        gecc probe7(1.);
        test << probe1 << probe2 << probe3 << probe4 << probe5 << probe6 << probe7;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +2.000000000e+00+2.000000000e+00+0.000000000e+00+1.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +3.000000000e+00+2.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +1.000000000e+00\n"
              "GECC    +4.000000000e+00+2.000000000e+00-1.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +5.000000000e+00+2.000000000e+00+0.000000000e+00-1.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +6.000000000e+00+2.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        -1.000000000e+00\n"
              "GECC    +7.000000000e+00+1.000000000e+00+1.000000000e+00\n");
    }

    SECTION("multiple (2)") {
        gecc probe1(1., 0., 0.);
        gecc probe2(0., 1., 0.);
        gecc probe3(0., 0., 1.);
        gecc probe4(-1., 0., 0.);
        gecc probe5(0., -1., 0.);
        gecc probe6(0., 0., -1.);
        gecc probe7(1.);
        test << probe1 << probe2 << probe3 << probe4 << probe5 << probe6 << probe7;
        CHECK(test.str() ==
              "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +2.000000000e+00+2.000000000e+00+0.000000000e+00+1.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +3.000000000e+00+2.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        +1.000000000e+00\n"
              "GECC    +4.000000000e+00+2.000000000e+00-1.000000000e+00+0.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +5.000000000e+00+2.000000000e+00+0.000000000e+00-1.000000000e+00\n"
              "        +0.000000000e+00\n"
              "GECC    +6.000000000e+00+2.000000000e+00+0.000000000e+00+0.000000000e+00\n"
              "        -1.000000000e+00\n"
              "GECC    +7.000000000e+00+1.000000000e+00+1.000000000e+00\n");
    }
}

TEST_CASE("FEM GECC conversion from own output.", "[fem_gecc,in/out]") {

    vector<std::string> lines;

    SECTION("GECC") {
        vector<std::string> data({
                "GECC    +1.000000000e+00+2.000000000e+00+1.000000000e+00+3.000000000e+00\n", 
                "        +1.340000000e+02\n"});
        auto len = __base::card::card_split(data, data.size(), lines);
        gecc probe(lines, len);

        CHECK(probe.ECCNO == 1);
        CHECK(probe.IOPT == gecc::ecc_opt::XYZ);
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
