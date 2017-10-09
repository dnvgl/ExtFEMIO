/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Test functionality used in all of BDF element classes.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_test_bdf_cards_elements[]) =
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

using namespace dnvgl::extfem;
using namespace bdf;
using namespace bdf::cards;
using namespace bdf::cards::__base;

using bdf::types::entry_type;
using bdf::types::entry_value;

TEST_CASE("Test id generation (elements).", "[bdf_elements]") {
    element::reset();

    cbar xCBar;
    crod xCRod;

    long EID{1};
    long PID{2};
    long GA{3};
    long GB{4};
    long G0{5};

    xCBar(&EID, &PID, &GA, &GB, &G0);
    EID = {2};
    long PID1{22};
    long G1{33};
    long G2{44};
    xCRod(&EID, &PID1, &G1, &G2);


    SECTION("Prevent re-usage of element id.") {
        EID = {3};
        PID = {2};
        G1 = {33};
        G2 = {44};
        crod xCRod2(&EID, &PID, &G1, &G2);
        CHECK(long(xCBar.EID) == 1);
        CHECK(long(xCRod.EID) == 2);
        CHECK(long(xCRod2.EID) == 3);
    }

    SECTION("New element id. (1)") {
        crod xCRod2(nullptr, &PID, &G1, &G2);
        CHECK(long(xCRod2.EID) == 3);
    }

    SECTION("New element id. (2)") {
        EID = {2};
        PID1 = {2};
        xCRod(&EID, &PID1, &G1, &G2);
        CHECK(long(xCRod.EID) == 3);
    }

    SECTION("New element id. (3)") {
        EID = {4};
        PID1 = {2};
        xCRod(&EID, &PID1, &G1, &G2);
        crod xCRod2(nullptr, &PID, &G1, &G2);
        CHECK(long(xCRod2.EID) == 3);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
