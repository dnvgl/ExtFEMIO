/**
   \file tests/test_bdf_cards_moment.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `MOMENT` card class.

   Detailed description
   */

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    char const cID_test_bdf_cards_moment[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF MOMENT definitions. (Small Field Format)", "[bdf_moment]") {

    std::list<std::string> data({
        // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
        "MOMENT  2       5       6       2.9     0.0     1.9     0.0               \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    moment probe(lines);

    SECTION("first moment") {
        CHECK((long)probe.SID == 2);
        CHECK((long)probe.G == 5);
        CHECK((long)probe.CID == 6);
        CHECK((double)probe.F == 2.9);
        CHECK((double)probe.N1 == 0.);
        CHECK((double)probe.N2 == 1.9);
        CHECK((double)probe.N3 == 0.);
    }
}

TEST_CASE("BDF MOMENT types output.", "[bdf_moment,out]") {

    std::ostringstream test;

    SECTION("reverse") {
        long SID(2), G(5), CID(6);
        double F(2.9), N1(0.), N2(1.9), N3(0.);
        moment probe(&SID, &G, &CID, &F, &N1, &N2, &N3);
        test << probe;
        CHECK(test.str() ==
              "MOMENT         2       5       62.900+00 0.00+001.900+00 0.00+00\n");
    }

    SECTION("reverse part") {
        long SID(2), G(5), CID(6);
        double F(2.9), N1(0.), N2(1.9);
        moment probe(&SID, &G, &CID, &F, &N1, &N2);
        test << probe;
        CHECK(test.str() ==
              "MOMENT         2       5       62.900+00 0.00+001.900+00\n");
    }

    SECTION("reverse part (2)") {
        long SID(2), G(5), CID(6);
        double F(2.9), N1(1.9);
        moment probe(&SID, &G, &CID, &F, &N1);
        test << probe;
        CHECK(test.str() ==
              "MOMENT         2       5       62.900+001.900+00\n");
    }

    SECTION("reuse") {
        long SID(2), G(5), CID(6);
        double F(2.9), N1(0.), N2(1.9), N3(0.);
        moment probe;
        test << probe;
        test << probe(&SID, &G, &CID, &F, &N1, &N2, &N3);
        SID++;
        G++;
        CID++;
        F += 4.;
        test << probe(&SID, &G, &CID, &F, &N1, &N2, &N3);
        SID++;
        test << probe(&SID, &G, &CID, &F, &N1, &N2);
        SID++;
        test << probe(&SID, &G, &CID, &F, &N1);
        test << probe;
        CHECK(test.str() ==
              "MOMENT         2       5       62.900+00 0.00+001.900+00 0.00+00\n"
              "MOMENT         3       6       76.900+00 0.00+001.900+00 0.00+00\n"
              "MOMENT         4       6       76.900+00 0.00+001.900+00\n"
              "MOMENT         5       6       76.900+00 0.00+00\n"
              "MOMENT         5       6       76.900+00 0.00+00\n");
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
