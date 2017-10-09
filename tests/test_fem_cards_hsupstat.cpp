/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `HSUPSTAT` class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_hsupstat[]) =
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

TEST_CASE("FEM HSUPSTAT definitions. (Small Field Format)", "[fem_hsupstat]") {

    vector<std::string> data({
        // 345678|234567890123456|234567890123456|234567890123456|234567890123456
        "HSUPSTAT  9.00000000E+00  2.00000000E+00  6.00000000E+00  0.00000000E+00\n",
        "          5.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n",
        "         -1.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
    vector<std::string> lines;
    auto len = __base::card::card_split(data, data.size(), lines);
    hsupstat probe(lines, len);

    SECTION("first moment") {
        CHECK(probe.NFIELD == 9);
        CHECK(probe.ISELTY == 2);
        CHECK(probe.NIDOF == 6);
        CHECK(probe.NRDOF == 0);
        CHECK(probe.NBAND == 5);
        CHECK(probe.NELT == 0);
        CHECK(probe.LINDEP == 0);
        CHECK(probe.RELOADC == 0);
        CHECK(probe.COMPLC == -1);
    }
}

TEST_CASE("FEM HSUPSTAT types output.", "[fem_hsupstat,out]") {
    ostringstream test;

    long NFIELD(1);
    long ISELTY(2);
    long NIDOF(3);
    long NRDOF(4);
    long NBAND(5);
    long NELT(6);
    long LINDEP(7);
    long RELOADC(8);
    long COMPLC(9);

    SECTION("write (empty)") {
        hsupstat probe;

        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("write (const)") {
        hsupstat probe(1, 2, 3, 4, 5, 6, 7, 8, 9);

        test << probe;
        CHECK(test.str() ==
              "HSUPSTAT+1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00\n");
    }

    SECTION("write (1)") {
        hsupstat probe(NFIELD, ISELTY, NIDOF, NRDOF, NBAND, NELT,
                       LINDEP, RELOADC, COMPLC);

        test << probe;
        CHECK(test.str() ==
              "HSUPSTAT+1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00\n");
    }
}

TEST_CASE("FEM HSUPSTAT conversion from own output.", "[fem_hsupstat,in/out]") {

    vector<std::string> lines;

    SECTION("HSUPSTAT") {

        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "HSUPSTAT+1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
            "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
            "        +9.000000000e+00\n"});

        vector<std::string> lines_l;
        auto len = __base::card::card_split(data, data.size(), lines_l);
        hsupstat probe(lines_l, len);

        CHECK(probe.NFIELD == 1);
        CHECK(probe.ISELTY == 2);
        CHECK(probe.NIDOF == 3);
        CHECK(probe.NRDOF == 4);
        CHECK(probe.NBAND == 5);
        CHECK(probe.NELT == 6);
        CHECK(probe.LINDEP == 7);
        CHECK(probe.RELOADC == 8);
        CHECK(probe.COMPLC == 9);
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
