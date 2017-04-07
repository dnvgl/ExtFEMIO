/**
   \file tests/test_fem_float.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for FEM float types.

   Detailed description
   */

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <vector>

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
    const double dc0 = 0.;
}

TEST_CASE("FEM float types parsing.", "[fem_types]") {

    entry_type<double> probe(
        "dummy", bound<double>(nullptr, nullptr, &dc0));

    //        12345678901e3456
    SECTION("' 0.00000000E+000'") {
        CHECK(probe(" 0.00000000E+000") == 0.);
    }

    SECTION("'-0.00000000E+000'") {
        CHECK(probe("-0.00000000E+000") == 0.);
    }

    //        12345678901e3456
    SECTION("' 1.00000000E+01 '") {
        //            12345678901e3456
        CHECK(probe(" 1.00000000E+00 ") == 1.);
    }

    //        12345678901e3456
    SECTION("' 1.00000000e+01 '") {
        //            12345678901e3456
        CHECK(probe(" 1.00000000e+00 ") == 1.);
    }

    //        12345678901e3456
    SECTION("'+1.00000000E+00 '") {
        //            12345678901e3456
        CHECK(probe("+1.00000000E+00 ") == 1.);
    }

    //        12345678901e3456
    SECTION("'+1.00000000e+00'") {
        //            12345678901e3456
        CHECK(probe("+1.00000000e+00 ") == 1.);
    }

    //        12345678901e3456
    SECTION("' 1.00000000e+00 '") {
        //           12345678901e3456
        CHECK(probe("+1.00000000e+00 ") == 1.);
    }

    //        12345678901e3456
    SECTION("' 1.00000000e-01 '") {
        //           12345678901e3456
        CHECK(probe("+1.00000000e-01 ") == .1);
    }

    //        12345678901e3456
    SECTION("'-1.00000000e+00 '") {
        //           12345678901e3456
        CHECK(probe("-1.00000000e+00 ") == -1.);
    }

    //        12345678901e3456
    SECTION("' 0.000000000e+00'") {
        //           12345678901e3456
        CHECK(probe(" 0.000000000e+00") == 0);
    }

    //        12345678901e3456
    SECTION("'-1.00000000e-01 '") {
        //           12345678901e3456
        CHECK(probe("-1.00000000e-01 ") == -.1);
    }

    SECTION("'-1.00000000e-01 ', min 0.") {
        entry_type<double> probe_l("dummy",
                                 bound<double>(&dc0, nullptr, &dc0));
        CHECK_THROWS(probe_l(" -1.00000000e-01 "));
    }

    SECTION("Quick Reference") {
        std::vector<std::string> samples;
        //            12345678901e3456
        CHECK(probe(" 7.00000000e+00 ") == 7.);
        CHECK(probe(" 7.00000000E+00 ") == 7.);
        CHECK(probe(" 7.00000000E-01 ") == .7);
        CHECK(probe("-7.00000000E-01 ") == -.7);
        CHECK(probe(" 7.00000000E+01 ") == 70.);
    }

    SECTION("'                '") {
        CHECK_THROWS(probe("                "));
    }

    SECTION("'                ', no default") {
        entry_type<double> probe_l(
            "dummy", bound<double>(nullptr, nullptr, nullptr));
        CHECK_THROWS(probe_l("                "));
    }

    //        12345678901e3456
    SECTION("' 1.23000000e+02 '") {
        CHECK(probe(" 1.23000000e+02 ") == 123.);
    }

    //        12345678901e3456
    SECTION("' 1.23000000e-01 '") {
        CHECK(probe(" 1.23000000e-01 ") == .123);
    }

    //        12345678901e3456
    SECTION("' 7.36831000E-01 '") {
        CHECK(probe(" 7.36831000E-01 ") == 0.736831);
    }

    //        12345678901e3456
    SECTION("' 1.23000000e-001'") {
        CHECK(probe(" 1.23000000e-001") == .123);
    }

    //        12345678901e3456
    SECTION("' 7.36831000E-001'") {
        CHECK(probe(" 7.36831000E-001") == 0.736831);
    }

    SECTION("'        '") {
        entry_type<double> probe_l(
            "probe", bound<double>(nullptr, nullptr, nullptr, true));
        CHECK_THROWS(probe_l("        "));
    }

    SECTION("Own output") {
        CHECK(probe("+1.000000000e+00") == 1.);
    }

    SECTION("FEMIO-5") {
        CHECK(probe("  1.00000000E+00") == 1.);
    }
}

TEST_CASE("FEM double types output.", "[fem_types]") {

    entry_type<double> obj("dummy");

    double lval(1.);

    SECTION("Output") {
        std::string res(obj.format(lval));
        CHECK(obj.format(lval).size() == 16);
        //                         12345678901e3456
        CHECK(obj.format(lval) == "+1.000000000e+00");
    }

    SECTION("-0.") {
        lval = -0.;
        std::string res(obj.format(lval));
        CHECK(obj.format(lval).size() == 16);
        //                         12345678901e3456
        CHECK(obj.format(lval) == "-0.000000000e+00");
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_float --use-colour no)"
// coding: utf-8
// End:
