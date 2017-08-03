/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `MISOSEL` cards.

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

TEST_CASE("FEM MISOSEL definitions.", "[fem_misosel]" ) {

    double c_ref_rload[6] = {0., 0., 2.e6, 0., 0., 0.};
    std::list<double> ref_rload(c_ref_rload, c_ref_rload + 6);
    vector<std::string> lines;
    size_t len;

    SECTION("MISOSEL (1)") {
        vector<std::string> data({
                "MISOSEL  4.10000000e+001 2.06000000e+008 3.00032000e-001 7.80000000e+000\n",
                    "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        misosel probe(lines, len);

        CHECK(probe.MATNO == 41);
        CHECK(probe.YOUNG == 2.06e8);
        CHECK(probe.POISS == 3.00032e-1);
        CHECK(probe.RHO == 7.8);
        CHECK(probe.DAMP == 0.);
        CHECK(probe.ALPHA == 0.);
        CHECK(probe.DUMMY == 0.);
        CHECK(probe.YIELD == 0.);
    }

    SECTION("MISOSEL (2)") {
        vector<std::string> data({
                "MISOSEL  4.10000000e+01  2.06000000e+08  3.00032000e-01  7.80000000e+00 \n",
                    "         0.00000000e+00  0.00000000e+00  1.00000000e+00  2.34000000e+02 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        misosel probe(lines, len);

        CHECK(probe.MATNO == 41);
        CHECK(probe.YOUNG == 2.06e8);
        CHECK(probe.POISS == 3.00032e-1);
        CHECK(probe.RHO == 7.8);
        CHECK(probe.DAMP == 0.);
        CHECK(probe.ALPHA == 0.);
        CHECK(probe.DUMMY == 1.);
        CHECK(probe.YIELD == 234.);
    }
}

TEST_CASE("FEMIO-27: Failing to import MISOEL card from SESAM GeniE FEM file", "[fem_misosel]") {

    vector<std::string> lines;

    SECTION("Failing card") {
        vector<std::string> data({
                "MISOSEL  1.00000000e+000 2.06000000e+008 3.00000012e-001 7.84999990e+000\n",
                    "         0.00000000e+000 0.00000000e+000\n"});
        size_t len{__base::card::card_split(data, data.size(), lines)};
        misosel probe(lines, len);

        CHECK(probe.MATNO == 1);
        CHECK(probe.YOUNG == 2.06e8);
        CHECK(probe.POISS == 3.00000012e-1);
        CHECK(probe.RHO == 7.84999990);
        CHECK(probe.DAMP == 0.);
        CHECK(probe.ALPHA == 0.);
        CHECK(probe.DUMMY == 0.);
        CHECK(probe.YIELD == 0.);
    }
}

TEST_CASE("FEM MISOSEL types output.", "[fem_misosel,out]" ) {

    std::ostringstream test;

    SECTION("empty") {
        misosel probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        misosel probe(1, 2., 3., 4., 5., 6., 7., 8.);
        test << probe;
        CHECK(test.str() ==
              "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }

    SECTION("default YIELD") {
        misosel probe;
        test << probe(1, 2., 3., 4., 5., 6.);
        CHECK(test.str() ==
              "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("call simple") {
        misosel probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8.);
        CHECK(test.str() ==
              "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n");
    }

    SECTION("call default YIELD") {
        misosel probe;
        test << probe(1, 2., 3., 4., 5., 6.);
        CHECK(test.str() ==
              "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }

    SECTION("call multiple") {
        misosel probe;
        test << probe(1, 2., 3., 4., 5., 6., 7., 8.);
        test << probe(1, 2., 3., 4., 5., 6.);
        CHECK(test.str() ==
              "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00\n");
    }
}

TEST_CASE("FEM MISOSEL conversion from own output.", "[fem_misosel,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("MISOEL (1)") {
        vector<std::string> data({
                "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                    "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        misosel probe(lines, len);

        CHECK(probe.MATNO == 1);
        CHECK(probe.YOUNG == 2.);
        CHECK(probe.POISS == 3.);
        CHECK(probe.RHO == 4.);
        CHECK(probe.DAMP == 5.);
        CHECK(probe.ALPHA == 6.);
        CHECK(probe.DUMMY == 7.);
        CHECK(probe.YIELD == 8.);
    }

    SECTION("MISOEL (2)") {
        vector<std::string> data({
                "MISOSEL +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                    "        +5.000000000e+00+6.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        misosel probe(lines, len);

        CHECK(probe.MATNO == 1);
        CHECK(probe.YOUNG == 2.);
        CHECK(probe.POISS == 3.);
        CHECK(probe.RHO == 4.);
        CHECK(probe.DAMP == 5.);
        CHECK(probe.ALPHA == 6.);
        CHECK(probe.DUMMY == 0.);
        CHECK(probe.YIELD == 0.);
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
