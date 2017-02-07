/**
   \file tests/test_fem_cards_gelmnt2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `GELMNT2` class.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

#include <catch.hpp>

#include "config.h"

#include "fem/cards.h"
#include "fem/errors.h"

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

TEST_CASE("FEM GELMNT2 definitions. (Small Field Format)", "[fem_gelmnt2]" ) {

    vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "GELMNT2   1.00000000E+00  1.00000000E+00  1.00000000E+00  0.00000000E+00\n",
                "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
                "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
                "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
                "          1.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
    vector<std::string> lines;
    size_t len{__base::card::card_split(data, data.size(), lines)};
    gelmnt2 probe(lines, len);

    SECTION("first moment") {
        REQUIRE(probe.SUBNO == 1);
        REQUIRE(probe.SLEVEL == 1);
        REQUIRE(probe.STYPE == 1);
        REQUIRE(probe.ADDNO == 0);
        REQUIRE(probe.T[0][0] == 1.);
        REQUIRE(probe.T[1][0] == 0.);
        REQUIRE(probe.T[2][0] == 0.);
        REQUIRE(probe.T[3][0] == 0.);
        REQUIRE(probe.T[0][1] == 0.);
        REQUIRE(probe.T[1][1] == 1.);
        REQUIRE(probe.T[2][1] == 0.);
        REQUIRE(probe.T[3][1] == 0.);
        REQUIRE(probe.T[0][2] == 0.);
        REQUIRE(probe.T[1][2] == 0.);
        REQUIRE(probe.T[2][2] == 1.);
        REQUIRE(probe.T[3][2] == 0.);
        REQUIRE(probe.T[0][3] == 0.);
        REQUIRE(probe.T[1][3] == 0.);
        REQUIRE(probe.T[2][3] == 0.);
        REQUIRE(probe.T[3][3] == 1.);
        REQUIRE(probe.NNOD == 1);
        REQUIRE(probe.NOD.size() == 1);
        REQUIRE(probe.NOD[0] == 1);
    }
}

TEST_CASE("FEM GELMNT2 types output.", "[fem_gelmnt2,out]" ) {

    std::ostringstream test;

    long SUBNO(1);
    long SLEVEL(2);
    long STYPE(3);
    long ADDNO(4);
    double T11(11.);
    double T21(21.);
    double T31(31.);
    double T12(12.);
    double T22(22.);
    double T32(32.);
    double T13(13.);
    double T23(23.);
    double T33(33.);
    double T14(14.);
    double T24(24.);
    double T34(34.);

    double T[][4] = {{T11, T12, T13, T14},
                     {T21, T22, T23, T24},
                     {T31, T32, T33, T34},
                     { 0.,  0.,  0.,  1.}};
    long NNOD(5);
    std::vector<long> NOD({6, 7, 8, 9, 10});

    std::string ref(
        // 345678|234567890123456|234567890123456|234567890123456|234567890123456
        "GELMNT2 +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
        "        +1.100000000e+01+2.100000000e+01+3.100000000e+01+1.200000000e+01\n"
        "        +2.200000000e+01+3.200000000e+01+1.300000000e+01+2.300000000e+01\n"
        "        +3.300000000e+01+1.400000000e+01+2.400000000e+01+3.400000000e+01\n"
        "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
        "        +9.000000000e+00+1.000000000e+01\n");

    SECTION("write (empty)") {
        gelmnt2 probe;
        test << probe;
        REQUIRE(test.str() == "");
    }

    SECTION("write (const)") {
        gelmnt2 probe(1, 2, 3, 4, T, 5, {6, 7, 8, 9, 10});
        test << probe;
        REQUIRE(test.str() == ref);
    }

    SECTION("write (1)") {
        gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO, T, NNOD, NOD);
        test << probe;
        REQUIRE(test.str() == ref);
    }

    SECTION("write (1a)") {
        REQUIRE_THROWS(gelmnt2(SUBNO, SLEVEL, STYPE, ADDNO, T, NNOD+1, NOD));
    }

    SECTION("write (2)") {
        gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO, T, NOD);
        test << probe;
        REQUIRE(test.str() == ref);
    }

    SECTION("write (3)") {
        gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO,
                      T11, T21, T31, T12, T22, T32, T13, T23, T33,
                      T14, T24, T34, NNOD, NOD);
        test << probe;
        REQUIRE(test.str() == ref);
    }

    SECTION("write (4)") {
        gelmnt2 probe(SUBNO, SLEVEL, STYPE, ADDNO,
                      T11, T21, T31, T12, T22, T32, T13, T23, T33,
                      T14, T24, T34, NOD);
        test << probe;
        REQUIRE(test.str() == ref);
    }
}

TEST_CASE("FEM GELMNT2 conversion from own output.", "[fem_gelmnt2,in/out]") {

    SECTION("GELMNT2") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GELMNT2 +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                    "        +1.100000000e+01+2.100000000e+01+3.100000000e+01+1.200000000e+01\n",
                    "        +2.200000000e+01+3.200000000e+01+1.300000000e+01+2.300000000e+01\n",
                    "        +3.300000000e+01+1.400000000e+01+2.400000000e+01+3.400000000e+01\n",
                    "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                    "        +9.000000000e+00+1.000000000e+01\n"});
        vector<std::string> lines;
        size_t len{__base::card::card_split(data, data.size(), lines)};
        gelmnt2 probe(lines, len);

        REQUIRE(probe.SUBNO == 1);
        REQUIRE(probe.SLEVEL == 2);
        REQUIRE(probe.STYPE == 3);
        REQUIRE(probe.ADDNO == 4);
        REQUIRE(probe.T[0][0] == 11.);
        REQUIRE(probe.T[1][0] == 12.);
        REQUIRE(probe.T[2][0] == 13.);
        REQUIRE(probe.T[3][0] == 14.);
        REQUIRE(probe.T[0][1] == 21.);
        REQUIRE(probe.T[1][1] == 22.);
        REQUIRE(probe.T[2][1] == 23.);
        REQUIRE(probe.T[3][1] == 24.);
        REQUIRE(probe.T[0][2] == 31.);
        REQUIRE(probe.T[1][2] == 32.);
        REQUIRE(probe.T[2][2] == 33.);
        REQUIRE(probe.T[3][2] == 34.);
        REQUIRE(probe.T[0][3] == 0.);
        REQUIRE(probe.T[1][3] == 0.);
        REQUIRE(probe.T[2][3] == 0.);
        REQUIRE(probe.T[3][3] == 1.);
        REQUIRE(probe.NNOD == 5);
        REQUIRE(probe.NOD.size() == 5);
        REQUIRE(probe.NOD == std::vector<long>({6, 7, 8, 9, 10}));
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
