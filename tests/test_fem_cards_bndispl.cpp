/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `BNDISPL` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_bndispl[]) =
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

TEST_CASE("FEM BNDISPL definitions.", "[fem_bndispl]") {

    vector<double> ref_rdisp({0., 0., 0., 0., 0., 0.});
    vector<std::string> lines;
    size_t len;

    SECTION("BNDISPL (1)") {
        vector<std::string> data({
            "BNDISPL  1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n",
            "         2.30470000e+004 6.00000000e+000 0.00000000e+000 0.00000000e+000\n",
            "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bndispl probe(lines, len);

        CHECK(probe.LLC == 1);
        CHECK(probe.DTYPE == 1);
        CHECK_FALSE(probe.COMPLX);
        CHECK(probe.NODENO == 23047);
        CHECK(probe.NDOF == 6);
        CHECK(probe.RDISP == ref_rdisp);
        CHECK(probe.IDISP == vector<double>({}));
    }

    SECTION("BNDISPL (2)") {
        vector<std::string> data({
            "BNDISPL  1.000000000e+00 1.000000000e+00 0.000000000e+00 0.000000000e+00\n",
            "         2.30470000e+04  6.000000000e+00 0.000000000e+00 0.000000000e+00\n",
            "         0.000000000e+00 0.000000000e+00 0.000000000e+00 0.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bndispl probe(lines, len);

        CHECK(probe.LLC == 1);
        CHECK(probe.DTYPE == 1);
        CHECK_FALSE(probe.COMPLX);
        CHECK(probe.NODENO == 23047);
        CHECK(probe.NDOF == 6);
        CHECK(probe.RDISP == ref_rdisp);
        CHECK(probe.IDISP == vector<double>({}));
    }
}

TEST_CASE("FEM BNDISPL types output.", "[fem_bndispl,out]") {

    std::ostringstream test;

    SECTION("empty") {
        bndispl probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        bndispl probe(1, 1, false, 4, 6, {1., 2., 3., 4., 5., 6.});
        test << probe;
        CHECK(test.str() ==
              "BNDISPL +1.000000000e+00+1.000000000e+00           +0.00            0.00\n"
              "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("simple (with IDISP)") {
        bndispl probe(1, 1, true, 4, 6,
        {1., 2., 3., 4., 5., 6.}, {1., 2., 3., 4., 5., 6.});
        test << probe;
        CHECK(test.str() ==
              "BNDISPL +1.000000000e+00+1.000000000e+00           +1.00            0.00\n"
              "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n"
              "        +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("simple (calc COMPLX)") {
        bndispl probe(1, 1, long(4), 6,
        {1., 2., 3., 4., 5., 6.});
        test << probe;
        CHECK(test.str() ==
              "BNDISPL +1.000000000e+00+1.000000000e+00           +0.00            0.00\n"
              "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("simple (with IDISP, calc COMPLX)") {
        bndispl probe(1, 1, long(4), 6,
        {1., 2., 3., 4., 5., 6.}, {1., 2., 3., 4., 5., 6.});
        test << probe;
        CHECK(test.str() ==
              "BNDISPL +1.000000000e+00+1.000000000e+00           +1.00            0.00\n"
              "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n"
              "        +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("calc ndof") {
        bndispl probe(1, 1, false, 4, {1., 2., 3., 4., 5., 6.});
        test << probe;
        CHECK(test.str() ==
              "BNDISPL +1.000000000e+00+1.000000000e+00           +0.00            0.00\n"
              "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n");
    }
    SECTION("calc NDOF (calc COMPLX)") {
        bndispl probe(1, 1, 4, {1., 2., 3., 4., 5., 6.});
        test << probe;
        CHECK(test.str() ==
              "BNDISPL +1.000000000e+00+1.000000000e+00           +0.00            0.00\n"
              "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("calc NDOF (with IDISP, calc COMPLX)") {
        bndispl probe(1, 1, 4,
        {1., 2., 3., 4., 5., 6.}, {1., 2., 3., 4., 5., 6.});
        test << probe;
        CHECK(test.str() ==
              "BNDISPL +1.000000000e+00+1.000000000e+00           +1.00            0.00\n"
              "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n"
              "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n"
              "        +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }
}


TEST_CASE("FEM BNDISPL conversion from own output.", "[fem_bndispl,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("BNDISPL (own output) (1)") {
        vector<std::string> data({
            "BNDISPL +1.000000000e+00+1.000000000e+00           +1.00            0.00\n",
            "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n",
            "        +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
            "        +5.000000000e+00+6.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bndispl probe(lines, len);

        CHECK(probe.LLC == 1);
        CHECK(probe.DTYPE == 1);
        CHECK(probe.COMPLX);
        CHECK(probe.NODENO == 4);
        CHECK(probe.NDOF == 6);
        CHECK(probe.RDISP == vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(probe.IDISP == vector<double>({1., 2., 3., 4., 5., 6.}));
    }

    SECTION("BNDISPL (own output) (2)") {
        vector<std::string> data({
            "BNDISPL +1.000000000e+00+1.000000000e+00           +0.00            0.00\n",
            "        +4.000000000e+00+6.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+6.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bndispl probe(lines, len);

        CHECK(probe.LLC == 1);
        CHECK(probe.DTYPE == 1);
        CHECK_FALSE(probe.COMPLX);
        CHECK(probe.NODENO == 4);
        CHECK(probe.NDOF == 6);
        CHECK(probe.RDISP == vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(probe.IDISP == vector<double>({}));
    }

    SECTION("BNDISPL (own output) (3)") {
        vector<std::string> data({
            "BNDISPL +1.000000000e+00+1.000000000e+00           +1.00            0.00\n",
            "        +4.000000000e+00+5.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00+1.000000000e+00\n",
            "        +2.000000000e+00+3.000000000e+00+4.000000000e+00+5.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bndispl probe(lines, len);

        CHECK(probe.LLC == 1);
        CHECK(probe.DTYPE == 1);
        CHECK(probe.COMPLX);
        CHECK(probe.NODENO == 4);
        CHECK(probe.NDOF == 5);
        CHECK(probe.RDISP == vector<double>({1., 2., 3., 4., 5.}));
        CHECK(probe.IDISP == vector<double>({1., 2., 3., 4., 5.}));
    }

    SECTION("BNDISPL (own output) (4)") {
        vector<std::string> data({
            "BNDISPL +1.000000000e+00+1.000000000e+00           +0.00            0.00\n",
            "        +4.000000000e+00+5.000000000e+00+1.000000000e+00+2.000000000e+00\n",
            "        +3.000000000e+00+4.000000000e+00+5.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        bndispl probe(lines, len);

        CHECK(probe.LLC == 1);
        CHECK(probe.DTYPE == 1);
        CHECK_FALSE(probe.COMPLX);
        CHECK(probe.NODENO == 4);
        CHECK(probe.NDOF == 5);
        CHECK(probe.RDISP == vector<double>({1., 2., 3., 4., 5.}));
        CHECK(probe.IDISP == vector<double>({}));
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
