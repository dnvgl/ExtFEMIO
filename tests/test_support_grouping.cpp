/**
   \file test_support_grouping.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing grouping.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_support_grouping[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "support/grouping.h"
#include "support/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

CATCH_TRANSLATE_EXCEPTION(exception &ex) {
   return Catch::toString( ex.what() );
}

TEST_CASE("Process Grouping information.", "[support_grouping]") {

    SECTION("simple") {
        elem_info probe(1, 2, "AA", "TEST", "HIGH", {230});

        CHECK(probe.id == 1);
        CHECK(probe.nnodes == 2);
        CHECK(probe.napa_obj == "AA");
        CHECK(probe.func_name == "TEST");
        CHECK(probe.grade == "HIGH");
        CHECK(probe.yield == 230.);
    }
}

TEST_CASE("Testing element comparison", "[support_grouping]") {
    elem_info probe_1(1, 2, "AA", "TEST", "HIGH", {230});
    elem_info probe_2(2, 2, "AA", "TEST", "HIGH", {230});
    elem_info probe_3(1, 2, "AA", "TEST", "HIGH", {230});

    SECTION("eq") {
        CHECK(probe_1 == probe_3);
    }

    SECTION("ne") {
        CHECK(probe_1 != probe_2);
    }

    SECTION("lt") {
        CHECK(probe_1 < probe_2);
        CHECK(probe_1 <= probe_3);
    }

    SECTION("gt") {
        CHECK(probe_2 > probe_1);
        CHECK(probe_1 >= probe_3);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
