/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the BDF `CMASS4` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_test_bdf_cards_cmass4[]) =
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
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF CMASS4 definitions. (Small Field Format)", "[bdf_cmass4]" ) {

    std::list<std::string> const data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "CMASS4  1       3.      32      33 \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cmass4 probe(lines);

    SECTION("first cmass4") {
        CHECK((long)probe.EID == 1);
        CHECK((double)probe.M == 3.);
        CHECK((long)probe.S1 == 32);
        CHECK((long)probe.S2 == 33);
    }
}

TEST_CASE("BDF CMASS4 types output.", "[bdf_cmass4,out]" ) {
    cmass4::reset();

    std::ostringstream test;

    SECTION("empty") {
        cmass4 const probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("reverse") {
        long EID(2), S1(6), S2(1);
        double M(2.9);
        cmass4 const probe(&EID, &M, &S1, &S2);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS4         22.900+00       6       1\n");
    }

    SECTION("reverse part") {
        long EID(2), S1(6);
        double M(2.9);
        cmass4 const probe(&EID, &M, &S1);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS4         22.900+00       6\n");
    }

    SECTION("Auto generate ID") {
        cmass4::reset();
        long EID(0), S1(6);
        double M(2.9);
        cmass4 probe(&EID, &M, &S1);
        CHECK(long(probe.EID) == 1);
    }

    SECTION("multiple") {
        long EID(1), S1(2);
        double M(3.);
        cmass4 probe;
        test << probe;
        test << probe(&EID, &M, &S1);
        EID++;
        test << probe(&EID, &M, &S1);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS4         13.000+00       2\n"
                "CMASS4         23.000+00       2\n"
                "CMASS4         23.000+00       2\n");
    }

    SECTION("multiple (default ID)") {
        double M(3.);
        long S1(2);
        cmass4 probe;
        test << probe;
        test << probe(&M, &S1);
        test << probe(&M, &S1);
        test << probe(&M, &S1);
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS4         13.000+00       2\n"
                "CMASS4         23.000+00       2\n"
                "CMASS4         33.000+00       2\n");
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
