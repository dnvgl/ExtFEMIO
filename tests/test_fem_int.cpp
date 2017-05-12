/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for SEASAM FEM int types.

   Detailed description
*/
#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::types;
using namespace dnvgl::extfem::fem::type_bounds;

namespace {
    const long lc0 = 0;
    const long lc1 = 1;
    const long lc_1 = -1;
}

TEST_CASE("FEM int types parsing.", "[fem_types]") {

    entry_type<long> probe("dummy", bound<long>(nullptr, nullptr));

    //        12345678901e3456
    SECTION("' 0.00000000E+000'") {
        CHECK(probe(" 0.00000000E+000") == 0);
    }

    //        12345678901e3456
    SECTION("' 2.00000000E+000'") {
        entry_type<long> obj("dummy", bound<long>(&lc1));
        CHECK(obj(" 2.00000000E+000") == 2);
    }

    //        12345678901e3456
    SECTION("' 2.00000000E+00 '") {
        entry_type<long> obj("dummy", bound<long>(&lc1));
        CHECK(obj(" 2.00000000E+00 ") == 2);
    }

    //        12345678901e3456
    SECTION("'+2.00000000E+00 '") {
        entry_type<long> obj("dummy", bound<long>(&lc1));
        CHECK(obj("+2.00000000E+00 ") == 2);
    }

    //        12345678901e3456
    SECTION("'+2.00000000E+000'") {
        entry_type<long> obj("dummy", bound<long>(&lc1));
        CHECK(obj("+2.00000000E+000") == 2);
    }

    //        12345678901e3456
    SECTION("'-1.00000000E+00 '") {
        entry_type<long> obj("dummy", bound<long>(&lc_1, nullptr, &lc0));
        CHECK(obj("-1.00000000E+00 ") == -1);
    }

    //        12345678901e3456
    SECTION("'+1.23000000E+02 '") {
        entry_type<long> obj("dummy");
        CHECK(obj("+1.23000000E+02 ") == 123);
    }

    SECTION("Misc Num") {
        //           12345678901e3456
        CHECK(probe("+7.00000000e+00 ") == 7);
        CHECK(probe("+7.00000000E+00 ") == 7);
        CHECK(probe("-7.00000000e+00 ") == -7);
        CHECK(probe("-7.00000000E+00 ") == -7);
    }

    SECTION("own output") {
        //           12345678901e3456
        CHECK(probe("+1.000000000E+00") == 1);
    }

    SECTION("FEMIO-4") {
        //           12345678901e3456
        CHECK(probe("  1.00000000E+00") == 1);
    }
}

TEST_CASE("FEM int types output.", "[fem_types]") {

    entry_type<long> obj("dummy");

    long lval(1);

    SECTION("Output") {
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "+1.000000000e+00");
    }

    SECTION("Output (neg. val)") {
        long lval_l{-1};
        CHECK(obj.format(lval_l).size() == 16);
        CHECK(obj.format(lval_l) == "-1.000000000e+00");
    }

    SECTION("Output ()") {
        long lval_l{1};
        CHECK(obj.format(lval_l).size() == 16);
        CHECK(obj.format(lval_l) == "+1.000000000e+00");
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_int --use-colour no)"
// coding: utf-8
// End:
