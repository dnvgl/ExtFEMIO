/**
   \file tests/test_fem_cards_hsuptran.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `HSUPTRAN` class.

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

TEST_CASE("FEM HSUPTRAN definitions. (Small Field Format)", "[fem_hsuptran]") {
    vector<std::string> data({
        // 345678|234567890123456|234567890123456|234567890123456|234567890123456
        "HSUPTRAN  1.80000000E+01  2.00000000E+00  1.00000000E+00  0.00000000E+00\n",
        "          0.00000000E+00  0.00000000E+00  0.00000000E+00  1.00000000E+00\n",
        "          0.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
        "          1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
        "          0.00000000E+00  1.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
    vector<std::string> lines;
    size_t len = __base::card::card_split(data, data.size(), lines);
    hsuptran probe(lines, len);

    SECTION("first moment") {

        CHECK(probe.NFIELD == 18);
        CHECK(probe.ITREF == 2);
        CHECK(probe.T[0][0] == 1.);
        CHECK(probe.T[1][0] == 0.);
        CHECK(probe.T[2][0] == 0.);
        CHECK(probe.T[3][0] == 0.);
        CHECK(probe.T[0][1] == 0.);
        CHECK(probe.T[1][1] == 1.);
        CHECK(probe.T[2][1] == 0.);
        CHECK(probe.T[3][1] == 0.);
        CHECK(probe.T[0][2] == 0.);
        CHECK(probe.T[1][2] == 0.);
        CHECK(probe.T[2][2] == 1.);
        CHECK(probe.T[3][2] == 0.);
        CHECK(probe.T[0][3] == 0.);
        CHECK(probe.T[1][3] == 0.);
        CHECK(probe.T[2][3] == 0.);
        CHECK(probe.T[3][3] == 1.);
    }
}

TEST_CASE("FEM HSUPTRAN types output.", "[fem_hsuptran,out]") {
    std::ostringstream test;

    long NFIELD(1);
    long ITREF(2);
    double T11(11.);
    double T21(21.);
    double T31(31.);
    double T41(0.);
    double T12(12.);
    double T22(22.);
    double T32(32.);
    double T42(0.);
    double T13(13.);
    double T23(33.);
    double T33(33.);
    double T43(0.);
    double T14(14.);
    double T24(24.);
    double T34(34.);
    double T44(1.);

    std::string ref(
        "HSUPTRAN+1.000000000e+00+2.000000000e+00+1.100000000e+01+2.100000000e+01\n"
        "        +3.100000000e+01+0.000000000e+00+1.200000000e+01+2.200000000e+01\n"
        "        +3.200000000e+01+0.000000000e+00+1.300000000e+01+3.300000000e+01\n"
        "        +3.300000000e+01+0.000000000e+00+1.400000000e+01+2.400000000e+01\n"
        "        +3.400000000e+01+1.000000000e+00\n");

    SECTION("write (empty)") {
        hsuptran probe;

        test << probe;
        CHECK(test.str() == "");
    }


    SECTION("write (const)") {
        hsuptran probe(1, 2,
                       11., 21., 31., 0.,
                       12., 22., 32., 0.,
                       13., 33., 33., 0.,
                       14., 24., 34., 1.);

        test << probe;
        CHECK(test.str() == ref);
    }

    SECTION("write (1)") {
        hsuptran probe(NFIELD, ITREF,
                       T11, T21, T31, T41,
                       T12, T22, T32, T42,
                       T13, T23, T33, T43,
                       T14, T24, T34, T44);

        test << probe;
        CHECK(test.str() == ref);
    }

    SECTION("write (2)") {
        double T[][4] = {{T11, T21, T31, T41},
        {T12, T22, T32, T42},
        {T13, T23, T33, T43},
        {T14, T24, T34, T44}};
        hsuptran probe(NFIELD, ITREF, T);

        test << probe;
        CHECK(test.str() == ref);
    }
}

TEST_CASE("FEM HSUPTRAN conversion from own output.", "[fem_hsuptran,in/out]") {

    vector<std::string> lines;

    SECTION("HSUPTRAN") {

        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "HSUPTRAN+1.000000000e+00+2.000000000e+00+1.100000000e+01+2.100000000e+01\n",
            "        +3.100000000e+01+0.000000000e+00+1.200000000e+01+2.200000000e+01\n",
            "        +3.200000000e+01+0.000000000e+00+1.300000000e+01+3.300000000e+01\n",
            "        +3.300000000e+01+0.000000000e+00+1.400000000e+01+2.400000000e+01\n",
            "        +3.400000000e+01+1.000000000e+00\n"});
        size_t len{__base::card::card_split(data, data.size(), lines)};
        hsuptran probe(lines, len);

        CHECK(probe.NFIELD == 1);
        CHECK(probe.ITREF == 2);
        CHECK(probe.T[0][0] == 11.);
        CHECK(probe.T[1][0] == 12.);
        CHECK(probe.T[2][0] == 13.);
        CHECK(probe.T[3][0] == 14.);
        CHECK(probe.T[0][1] == 21.);
        CHECK(probe.T[1][1] == 22.);
        CHECK(probe.T[2][1] == 33.);
        CHECK(probe.T[3][1] == 24.);
        CHECK(probe.T[0][2] == 31.);
        CHECK(probe.T[1][2] == 32.);
        CHECK(probe.T[2][2] == 33.);
        CHECK(probe.T[3][2] == 34.);
        CHECK(probe.T[0][3] == 0.);
        CHECK(probe.T[1][3] == 0.);
        CHECK(probe.T[2][3] == 0.);
        CHECK(probe.T[3][3] == 1.);
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
