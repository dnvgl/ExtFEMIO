/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the BDF `GRAV` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_test_bdf_cards_grav[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"

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

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF GRAV definitions. (Small Field Format)", "[bdf_grav]" ) {

    std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "GRAV    1       3       32.2    0.0     0.0     -1.0    0                 \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    grav probe(lines);

    SECTION("first grav") {
        CHECK((long)probe.SID == 1);
        CHECK((long)probe.CID == 3);
        CHECK((double)probe.A == 32.2);
        CHECK((double)probe.N1 == 0.);
        CHECK((double)probe.N2 == 0.);
        CHECK((double)probe.N3 == -1.);
        CHECK((long)probe.MB == 0);
    }
}

TEST_CASE("BDF GRAV types output.", "[bdf_grav,out]" ) {

    std::ostringstream test;

    SECTION("reverse") {
        long const SID(2), CID(6), MB(1);
        double const A(2.9), N1(0.), N2(1.9), N3(0.);
        grav const probe(&SID, &CID, &A, &N1, &N2, &N3, &MB);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "GRAV           2       62.900+00 0.00+001.900+00 0.00+00       1\n");
    }

    SECTION("reverse part") {
        long const SID(2), CID(6);
        double const A(2.9);
        std::vector<double> const N({0., 1.8, 0.});
        grav probe(&SID, &CID, &A, &N);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "GRAV           2       62.900+00 0.00+001.800+00 0.00+00\n");
    }

    SECTION("failed part") {
        long const SID(2), CID(6);
        double const A(2.9);
        std::vector<double> N({0., 1.8, 0., 4.});
        CHECK_THROWS(grav(&SID, &CID, &A, &N));
    }

    SECTION("reuse") {
        long SID(1), CID(2), MB(7);
        double A(3.), N1(4.), N2(5), N3(6.);
        std::vector<double> N({8., 9., 10.});
        grav probe;
        test << probe;
        test << probe(&SID, &CID, &A, &N1, &N2, &N3, &MB);
        SID++;
        CID++;
        A += 4.;
        test << probe(&SID, &CID, &A, &N1, &N2, &N3, &MB);
        SID++;
        test << probe(&SID, &CID, &A, &N1, &N2, &N3);
        SID++;
        test << probe(&SID, &CID, &A, &N);
        SID++;
        test << probe(&SID, &CID, &A, &N, &MB);
        test << probe;
        CHECK(test.str() ==
                "GRAV           1       23.000+004.000+005.000+006.000+00       7\n"
                "GRAV           2       37.000+004.000+005.000+006.000+00       7\n"
                "GRAV           3       37.000+004.000+005.000+006.000+00\n"
                "GRAV           4       37.000+008.000+009.000+001.000+01\n"
                "GRAV           5       37.000+008.000+009.000+001.000+01       7\n"
                "GRAV           5       37.000+008.000+009.000+001.000+01       7\n");
    }

    SECTION("sequential set") {
        grav probe;
        test << probe;
        probe.SID.value = 22;
        probe.A = 10.;
        probe.setN1(1.);
        probe.setN2(1.);
        probe.setN3(1.);
        test << probe;
        CHECK(test.str() ==
                "GRAV          22       01.000+011.000+001.000+001.000+00\n");
        probe.setN1(1.);
        CHECK_THROWS(probe.setN1(2.));
        CHECK_THROWS(probe.setN2(2.));
        CHECK_THROWS(probe.setN3(2.));
    }

}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
