/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the BDF `CMASS2` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_test_bdf_cards_cmass2[]) =
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

TEST_CASE("BDF CMASS2 definitions. (Small Field Format)", "[bdf_cmass2]" ) {

    SECTION("first cmass2") {
        std::list<std::string> const data({
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS2  1       3.      32      8\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        cmass2 probe(lines);

        CHECK((long)probe.EID == 1);
        CHECK((double)probe.M == 3.);
        CHECK((long)probe.G1 == 32);
        CHECK(probe.C1 == std::vector<int>(1, 8));
        CHECK_FALSE(bool(probe.G2));
        CHECK(probe.C2 == std::vector<int>());
    }

    SECTION("full cmass2") {
        std::list<std::string> const data({
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS2  1       3.      32      8       43      2\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        cmass2 probe(lines);

        CHECK((long)probe.EID == 1);
        CHECK((double)probe.M == 3.);
        CHECK((long)probe.G1 == 32);
        CHECK(probe.C1 == std::vector<int>(1, 8));
        CHECK((long)probe.G2 == 43);
        CHECK(probe.C2 == std::vector<int>(1, 2));
    }

    SECTION("only second vals cmass2") {
        std::list<std::string> const data({
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS2  1       3.                      32      12\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        cmass2 probe(lines);

        CHECK((long)probe.EID == 1);
        CHECK((double)probe.M == 3.);
        CHECK_FALSE(bool(probe.G1));
        CHECK(probe.C1 == std::vector<int>());
        CHECK((long)probe.G2 == 32);
        CHECK(probe.C2 == std::vector<int>({1, 2}));
    }
}

TEST_CASE("BDF CMASS2 types output.", "[bdf_cmass2,out]" ) {
    cmass2::reset();

    std::ostringstream test;

    SECTION("empty") {
        cmass2 const probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("reverse") {
        long EID(2), S1(6), S2(1);
        std::vector<int> C1({1, 2, 3}), C2({4, 5, 6});
        double M(2.9);
        cmass2 const probe(&EID, &M, &S1, &C1, &S2, &C2);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS2         22.900+00       6     123       1     456\n");
    }

    SECTION("reverse part") {
        long EID(2), S1(6);
        double M(2.9);
        std::vector<int> C1({1, 2, 3});
        cmass2 const probe(&EID, &M, &S1, &C1);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS2         22.900+00       6     123\n");
    }

    SECTION("auto number EID") {
        cmass2::reset();
        long EID(0), S1(6);
        double M(2.9);
        std::vector<int> C1({1, 2, 3});
        cmass2 probe(&EID, &M, &S1, &C1);
        CHECK(long(probe.EID) == 1);
    }

    SECTION("multiple") {
        long EID(2), S1(6);
        double M(2.9);
        std::vector<int> C1({1, 2, 3});
        cmass2 probe;
        test << probe;
        test << probe(&EID, &M, &S1, &C1);
        EID++;
        test << probe(&EID, &M, &S1, &C1);
        test << probe;
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS2         22.900+00       6     123\n"
                "CMASS2         32.900+00       6     123\n"
                "CMASS2         32.900+00       6     123\n");
    }

    SECTION("multiple (default ID)") {
        long S1(6);
        double M(2.9);
        std::vector<int> C1({1, 2, 3});
        cmass2 probe;
        test << probe;
        test << probe(&M, &S1, &C1);
        test << probe(&M, &S1, &C1);
        test << probe(&M, &S1, &C1);
        CHECK(test.str() ==
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CMASS2         12.900+00       6     123\n"
                "CMASS2         22.900+00       6     123\n"
                "CMASS2         32.900+00       6     123\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
