/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Test functionality used in all of BDF property classes.

   Detailed description
*/

// ID:
namespace {
   char const cID_test_bdf_cards_properties[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace bdf::cards;
using namespace bdf::cards::__base;

using bdf::types::entry_type;
using bdf::types::entry_value;

TEST_CASE("Test id generation (properties).", "[bdf_properties]") {
    property::reset();

    pbar xPbar;
    prod xPshell;

    long PID{1};
    long MID{2};
    double A{3.};
    double I1{4.};
    double I2{5.};

    xPbar(&PID, &MID, &A, &I1, &I2);
    PID = {2};
    long MID1{2};
    double T{3.};
    xPshell(&PID, &MID1, &T);


    SECTION("Prevent re-usage of property id.") {
        PID = {1};
        MID = {2};
        A = {3.};
        prod xProd(&PID, &MID, &A);
        long val{xProd.PID};
        CHECK(val == 3);
    }

    SECTION("New property id. (1)") {
        prod xProd(nullptr, &MID, &A);
        CHECK(long(xProd.PID) == 3);
    }

    SECTION("New property id. (2)") {
        PID = {2};
        MID1 = {2};
        T = {3.};
        xPshell(&PID, &MID1, &T);
        CHECK(long(xPshell.PID) == 3);
    }

    SECTION("New property id. (3)") {
        PID = {4};
        MID1 = {2};
        T = {3.};
        xPshell(&PID, &MID1, &T);
        prod xProd(nullptr, &MID, &A);
        CHECK(long(xProd.PID) == 3);
    }
// pelas

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
