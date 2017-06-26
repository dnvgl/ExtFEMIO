/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for BDF float types.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char  cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <vector>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include <memory>

#include "bdf/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::types;
using namespace dnvgl::extfem::bdf::type_bounds;

namespace {
    auto const cd0_ = make_shared<double>(0.);
    auto const cd0 = cd0_.get();
}

TEST_CASE("BDF float types parsing.", "[bdf_types]") {

    auto const bound_dummy_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_dummy = bound_dummy_.get();
    entry_type<double> probe("dummy", bound_dummy);

    SECTION("'   1.   '") {
        CHECK(probe("   1.   ").value == 1.);
    }

    SECTION("'  .1    '") {
        CHECK(probe("  .1    ").value == .1);
    }

    SECTION("'  -1.   '") {
        CHECK(probe("  -1.   ").value == -1.);
    }

    SECTION("'  -.1   '") {
        CHECK(probe("  -.1   ").value == -.1);
    }

    SECTION("'  -1.   ', min 0.") {
        auto const bound_dummy_ = make_shared<bound<double>>(cd0, nullptr, cd0);
        auto const bound_dummy = bound_dummy_.get();
        entry_type<double> probe1("dummy", bound_dummy);
        CHECK_THROWS(probe1("  -1.   "));
    }

    SECTION("Quick Reference") {
        vector<std::string> samples;
        CHECK(probe("   7.0  ").value == 7.);
        CHECK(probe("   7.   ").value == 7.);
        CHECK(probe("   .7   ").value == .7);
        CHECK(probe("   .7E1 ").value == 7.);
        CHECK(probe("   .7e1 ").value == 7.);
        CHECK(probe("   0.7+1").value == 7.);
        CHECK(probe("   .70+1").value == 7.);
        CHECK(probe("   7.E+0").value == 7.);
        CHECK(probe("   7.e+0").value == 7.);
        CHECK(probe("   70.-1").value == 7.);
        CHECK(probe("  -7.0  ").value == -7.);
        CHECK(probe("  -7.   ").value == -7.);
        CHECK(probe("  -.7   ").value == -.7);
        CHECK(probe("  -.7E1 ").value == -7.);
        CHECK(probe("  -.7e1 ").value == -7.);
        CHECK(probe("  -0.7+1").value == -7.);
        CHECK(probe("  -.70+1").value == -7.);
        CHECK(probe("  -7.E+0").value == -7.);
        CHECK(probe("  -7.e+0").value == -7.);
        CHECK(probe("  -70.-1").value == -7.);
    }

    SECTION("Invalid values") {
        CHECK_THROWS(probe("   7    "));
        CHECK_THROWS(probe("   7E1  "));
        CHECK_THROWS(probe("   7e1  "));
        CHECK_THROWS(probe("   7E0  "));
        CHECK_THROWS(probe("   7e0  "));
        CHECK_THROWS(probe("   7E+0 "));
        CHECK_THROWS(probe("   7e+0 "));
        CHECK_THROWS(probe("   70-1 "));
    }

    SECTION("'        '") {
        CHECK(probe("        ").value == 0.);
    }

    SECTION("'        ', no default") {
        auto const bound_dummy = make_shared<bound<double>>(
            nullptr, nullptr, nullptr);
        entry_type<double> probel("dummy", bound_dummy.get());
        CHECK_THROWS(probel("        "));
    }

    SECTION("'   123.  '") {
        CHECK(probe("   123.  ").value == 123.);
    }

    SECTION("'   .123  '") {
        CHECK(probe("   .123  ").value == .123);
    }

    SECTION("'   .123+3  '") {
        CHECK(probe("   .123+3  ").value == 123.);
    }

    SECTION("'  123.+3        '") {
        CHECK(probe("  123.+3        ").value == 123000.);
    }

    SECTION("' +123.+3        '") {
        CHECK(probe(" +123.+3        ").value == 123000.);
    }

    SECTION("' -123.+3        '") {
        CHECK(probe(" -123.+3        ").value == -123000.);
    }

    SECTION("' +123.-3        '") {
        CHECK(probe(" +123.-3        ").value == 0.123);
    }

    SECTION("' -123.-3        '") {
        CHECK(probe(" -123.-3        ").value == -0.123);
    }

    SECTION("' .736831        '") {
        CHECK(probe(" .736831        ").value == 0.736831);
    }

    SECTION("'        '") {
        auto const bound_probe_l = make_shared<bound<double>>(
            nullptr, nullptr, nullptr, true);
        entry_type<double> probe_l("probe", bound_probe_l.get());
        CHECK_FALSE(probe_l("        ").value);
    }
}

TEST_CASE("BDF double types output.", "[bdf_types]") {

    entry_type<double> obj("dummy");

    entry_value<double> lval(1.), mlval(-1.);

    SECTION("SHORT") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        std::string res(obj.format(lval));
        CHECK(obj.format(lval).size() == 8);
        CHECK(obj.format(lval) == "1.000+00");
        CHECK(obj.format(mlval).size() == 8);
        CHECK(obj.format(mlval) == "-1.00+00");
    }

    SECTION("SHORT (nullptr)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("SHORT ()") {
        auto p_lval = new double(1.);
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(*p_lval == 1.);
        CHECK(obj.format(p_lval).size() == 8);
        CHECK(obj.format(p_lval) == "1.000+00");
        *p_lval = 2.9;
        CHECK(obj.format(p_lval) == "2.900+00");
        *p_lval = 1.9;
        CHECK(obj.format(p_lval) == "1.900+00");
        *p_lval = 0.;
        CHECK(obj.format(p_lval) == " 0.00+00");
        *p_lval = -0.;
        CHECK(obj.format(p_lval) == "-0.00+00");
        delete p_lval;
    }

    SECTION("SHORT (nullptr, void)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("SHORT (inexact)") {
        double *p_lval = new double(1234.5);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.05;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.005;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.0005;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.00005;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.000005;
        CHECK(obj.format(p_lval).size() == 8);
        CHECK(obj.format(p_lval) == "1.234+03");
        *p_lval = 1234.01;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.001;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.0001;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1234.00001;
        CHECK(obj.format(p_lval).size() == 8);
        CHECK(obj.format(p_lval) == "1.234+03");
        *p_lval = 1233.9;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1233.99;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1233.999;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1233.9999;
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = 1233.99999;
        CHECK(obj.format(p_lval).size() == 8);
        CHECK(obj.format(p_lval) == "1.234+03");
        delete p_lval;
    }

    SECTION("LONG") {
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "1.00000000000+00");
    }

    SECTION("FREE") {
        bdf::types::base::out_form = bdf::types::out_form_type::FREE;
        CHECK(obj.format(lval) == "1.000000+00");
    }

    SECTION("FREE 2") {
        bdf::types::base::out_form = bdf::types::out_form_type::FREE;
        CHECK(obj.format(33) == "3.300000+01");
    }
}

TEST_CASE("Exception, mkoe 2015-12-17", "[bdf_types]") {

    entry_type<double> obj("dummy");

    SECTION("SHORT") {
        const double lval(-11.1);
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(lval).size() == 8);
        CHECK(obj.format(lval) == "-1.11+01");
    }

    SECTION("LONG") {
        const double lval(-11.104650284500055);
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "-1.1104650285+01");
    }
}

TEST_CASE("Negative zero", "[bdf_types]") {

    entry_type<double> obj("dummy");

    SECTION("SHORT") {
        const double lval(-0.);
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(lval).size() == 8);
        CHECK(obj.format(lval) == "-0.00+00");
    }

    SECTION("LONG") {
        const double lval(-0.);
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "-0.0000000000+00");
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_float --use-colour no)"
// coding: utf-8
// End:
