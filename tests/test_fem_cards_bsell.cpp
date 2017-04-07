/**
   \file tests/test_fem_cards_bsell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `BSELL` class.

   Detailed description
   */

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_fem_cards_bsell[] _EXTFEMIO_UNUSED =
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

TEST_CASE("FEM BSELL definitions. (Small Field Format)", "[fem_bsell]") {

    SECTION("BSELL (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "BSELL    1.000000000e+00 1.000000000e+00 0.000000000e+00 0.00000000E+00\n",
            "         1.000000000e+00 1.000000000e+00 2.000000000e+00-1.00000000E+00\n"});
        vector<std::string> lines;
        size_t len{__base::card::card_split(data, data.size(), lines)};
        bsell probe(lines, len);

        CHECK((long)probe.LC == 1);
        CHECK((double)probe.SUBNO == 1);
        CHECK(probe.LLC == std::vector<long>({1, 2}));
        CHECK(probe.FACT == std::vector<double>({1., -1.}));
    }
}

TEST_CASE("FEM BSELL types output.", "[fem_bsell,out]") {

    std::ostringstream test;

    long LC(2);
    long SUBNO(29);
    std::vector<long> LLC({1, 2, 3, 4, 5, 6});
    std::vector<double> FACT({1., -2., 3., -4., 5., -6.});

    SECTION("empty") {
        bsell probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("write (const)") {
        bsell probe(2, 29, {1, 2, 3, 4, 5, 6},
        {1., -2., 3., -4., 5., -6.});
        test << probe;
        CHECK(test.str() ==
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00+6.000000000e+00-6.000000000e+00\n");
    }

    SECTION("write (1)") {
        bsell probe(LC, SUBNO, LLC, FACT);
        test << probe;
        CHECK(test.str() ==
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00+6.000000000e+00-6.000000000e+00\n");
    }

    SECTION("write (less)") {
        bsell probe(2, 29, {1, 2, 3, 4, 5},
        {1., -2., 3., -4., 5.});
        test << probe;
        CHECK(test.str() ==
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00\n");
    }

    SECTION("call (const)") {
        bsell probe;
        test << probe(2, 29, {1, 2, 3, 4, 5, 6},
        {1., -2., 3., -4., 5., -6.});
        CHECK(test.str() ==
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00+6.000000000e+00-6.000000000e+00\n");
    }

    SECTION("call (1)") {
        bsell probe;
        test << probe(LC, SUBNO, LLC, FACT);
        CHECK(test.str() ==
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00+6.000000000e+00-6.000000000e+00\n");
    }

    SECTION("write (less)") {
        bsell probe;
        test << probe(2, 29, {1, 2, 3, 4, 5},
        {1., -2., 3., -4., 5.});
        CHECK(test.str() ==
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00\n");
    }

    SECTION("call (multiple)") {
        bsell probe;
        test << probe;
        test << probe(2, 29, {1, 2, 3, 4, 5, 6},
        {1., -2., 3., -4., 5., -6.});
        test << probe(LC, SUBNO, LLC, FACT);
        test << probe(2, 29, {1, 2, 3, 4, 5},
        {1., -2., 3., -4., 5.});
        test << probe;
        CHECK(test.str() ==
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00+6.000000000e+00-6.000000000e+00\n"
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00+6.000000000e+00-6.000000000e+00\n"
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00\n"
              "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n"
              "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n"
              "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n"
              "        +5.000000000e+00+5.000000000e+00\n");
    }
}

TEST_CASE("FEM BSELL conversion from own output.", "[fem_bsell,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("BSELL (own output)") {

        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n",
            "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n",
            "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n",
            "        +5.000000000e+00+5.000000000e+00+6.000000000e+00-6.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bsell probe(lines, len);

        CHECK((long)probe.LC == 2);
        CHECK((double)probe.SUBNO == 29);
        CHECK(probe.LLC == std::vector<long>({1, 2, 3, 4, 5, 6}));
        CHECK(probe.FACT == std::vector<double>({1., -2., 3., -4., 5., -6.}));
    }

    SECTION("BSELL (less)") {

        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "BSELL   +2.000000000e+00+2.900000000e+01            0.00            0.00\n",
            "        +1.000000000e+00+1.000000000e+00+2.000000000e+00-2.000000000e+00\n",
            "        +3.000000000e+00+3.000000000e+00+4.000000000e+00-4.000000000e+00\n",
            "        +5.000000000e+00+5.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bsell probe(lines, len);

        CHECK((long)probe.LC == 2);
        CHECK((double)probe.SUBNO == 29);
        CHECK(probe.LLC == std::vector<long>({1, 2, 3, 4, 5}));
        CHECK(probe.FACT == std::vector<double>({1., -2., 3., -4., 5.}));
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
