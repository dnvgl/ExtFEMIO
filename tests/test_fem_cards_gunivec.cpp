/**
   \file tests/test_fem_cards_gunivec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GUNIVEC` cards.

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

TEST_CASE("FEM GUNIVEC definitions.", "[fem_gunivec]" ) {

    double c_ref_rload[6] = {0., 0., 2.e6, 0., 0., 0.};
    std::list<double> ref_rload(c_ref_rload, c_ref_rload + 6);
    vector<std::string> lines;
    size_t len;

    SECTION("GUNIVEC (1)") {
        vector<std::string> data({
                "GUNIVEC  5.34000000e+002 0.00000000e+000 0.00000000e+000-1.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gunivec probe(lines, len);

        CHECK(probe.TRANSNO == 534);
        CHECK(probe.UNIX == 0.);
        CHECK(probe.UNIY == 0.);
        CHECK(probe.UNIZ == -1.);
    }

    SECTION("GUNIVEC (2)") {
        vector<std::string> data({
                "GUNIVEC  5.35000000e+02  0.00000000e+00  0.00000000e+00 -1.00000000e+00 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        gunivec probe(lines, len);

        CHECK(probe.TRANSNO == 535);
        CHECK(probe.UNIX == 0.);
        CHECK(probe.UNIY == 0.);
        CHECK(probe.UNIZ == -1.);
    }
}

TEST_CASE("FEM GUNIVEC types output.", "[fem_gunivec,out]" ) {

    std::ostringstream test;

    SECTION("empty") {
        gunivec probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        __base::transno::reset_transno();
        gunivec probe(1, 2., 3., 4.);
        test << probe;
        CHECK(test.str() ==
              "GUNIVEC +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n");
    }

    SECTION("simple (2)") {
        __base::transno::reset_transno();
        gunivec probe(1., 2., 3.);
        test << probe;
        CHECK(test.str() ==
              "GUNIVEC +1.000000000e+00+1.000000000e+00+2.000000000e+00+3.000000000e+00\n");
    }

    SECTION("simple (multiple)") {
        __base::transno::reset_transno();
        gunivec probe1(3, 2., 3., 4.);
        gunivec probe2(3., 3., 4.);
        gunivec probe3(4., 3., 4.);
        test << probe1;
        test << probe2;
        test << probe3;
        CHECK(test.str() ==
              "GUNIVEC +3.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "GUNIVEC +1.000000000e+00+3.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "GUNIVEC +2.000000000e+00+4.000000000e+00+3.000000000e+00+4.000000000e+00\n");
    }

    SECTION("reuse (1)") {
        __base::transno::reset_transno();
        gunivec probe;
        test << probe(1, 2., 3., 4.);
        test << probe(5., 6., 7.);
        CHECK(test.str() ==
              "GUNIVEC +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "GUNIVEC +2.000000000e+00+5.000000000e+00+6.000000000e+00+7.000000000e+00\n");
    }

    SECTION("reuse (2)") {
        __base::transno::reset_transno();
        gunivec probe;
        test << probe(2, 2., 3., 4.);
        test << probe(5., 6., 7.);
        CHECK(test.str() ==
              "GUNIVEC +2.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "GUNIVEC +1.000000000e+00+5.000000000e+00+6.000000000e+00+7.000000000e+00\n");
    }
}

TEST_CASE("FEM GUNIVEC conversion from own output.", "[fem_gunivec,in/out]") {

    vector<std::string> lines;

    SECTION("GUNIVEC (1)") {
        vector<std::string> data({
                "GUNIVEC +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"});
        size_t len{__base::card::card_split(data, data.size(), lines)};
        gunivec probe(lines, len);

        CHECK(probe.TRANSNO == 1);
        CHECK(probe.UNIX == 2.);
        CHECK(probe.UNIY == 3.);
        CHECK(probe.UNIZ == 4.);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../.cbuild/tests/test_fem_cards --use-colour no)"
// End:
