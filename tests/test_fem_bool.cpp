/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for SEASAM FEM bool types.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_bool[]) =
        "@(#) $Id$";
}

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#endif

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::types;
using namespace dnvgl::extfem::fem::type_bounds;

TEST_CASE("FEM bool types parsing.", "[fem_types]") {

    entry_type<bool> probe("dummy");

    //        12345678901e3456
    SECTION("' 0.00000000E+000'") {
        CHECK_FALSE(probe(" 0.00000000E+000"));
    }

    //        12345678901e3456
    SECTION("' 0.00000000E+00 '") {
        CHECK_FALSE(probe(" 0.00000000E+00 "));
    }

    //        12345678901e3456
    SECTION("' 1.00000000E+000'") {
        CHECK(probe(" 1.00000000E+000"));
    }

    //        12345678901e3456
    SECTION("' 1.00000000E+00 '") {
        CHECK(probe(" 1.00000000E+00 "));
    }

    //        12345678901e3456
    SECTION("'+1.23000000E+02 '") {
        CHECK_THROWS(probe("+1.23000000E+02"));
    }

    //        12345678901e3456
    SECTION("' 0.000000000e+00'") {
        CHECK_FALSE(probe(" 0.000000000e+00"));
    }

    SECTION("Own output") {
        CHECK(probe("           +1.00 "));
        CHECK_FALSE(probe("           +0.00"));
    }

    SECTION("FEMIO-6") {
        CHECK_FALSE(probe("  0.00000000E+00"));
    }
}

TEST_CASE("FEM bool types output.", "[fem_types]") {

    entry_type<bool> obj("dummy");

    bool lval(true);

    SECTION("Output (true)") {
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "           +1.00");
    }

    SECTION("Output (false)") {
        bool lval_l(false);
        CHECK(obj.format(lval_l).size() == 16);
        CHECK(obj.format(lval_l) == "           +0.00");
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_bool --use-colour no)"
// coding: utf-8
// End:
