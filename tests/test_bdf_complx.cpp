/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for BDF complx types.

   Detailed description
*/
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

#ifdef  __GNUC__
#include "config.h"
#endif

#include "bdf/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::types;
using namespace dnvgl::extfem::bdf::type_bounds;

TEST_CASE("BDF complx types parsing.", "[bdf_types]") {

    entry_type<std::complex<double> > probe("dummy");

    SECTION("'   1.      1.   '") {
        CHECK(probe("   1.   ", "   1.   ").value == std::complex<double>(1., 1));
    }

    SECTION("'  .1      .1    '") {
        CHECK(probe("  .1    ", "  .1    ").value == std::complex<double>(.1, .1));
    }

    SECTION("'  -1.     -1.   '") {
        CHECK(probe("  -1.   ", "  -1.   ").value == std::complex<double>(-1., -1));
    }
    SECTION("Quick Reference") {
        std::vector<std::string> samples;
        CHECK(probe("   7.0  ").value == std::complex<double>(7., 0));
        CHECK(probe("   7.   ").value == std::complex<double>(7., 0));
        CHECK(probe("   .7   ").value == std::complex<double>(.7, 0));
        CHECK(probe("   .7E1 ").value == std::complex<double>(7., 0));
        CHECK(probe("   .7e1 ").value == std::complex<double>(7., 0));
        CHECK(probe("   0.7+1").value == std::complex<double>(7., 0));
        CHECK(probe("   .70+1").value == std::complex<double>(7., 0));
        CHECK(probe("   7.E+0").value == std::complex<double>(7., 0));
        CHECK(probe("   7.e+0").value == std::complex<double>(7., 0));
        CHECK(probe("   70.-1").value == std::complex<double>(7., 0));
        CHECK(probe("  -7.0  ").value == std::complex<double>(-7., 0));
        CHECK(probe("  -7.   ").value == std::complex<double>(-7., 0));
        CHECK(probe("  -.7   ").value == std::complex<double>(-.7, 0));
        CHECK(probe("  -.7E1 ").value == std::complex<double>(-7., 0));
        CHECK(probe("  -.7e1 ").value == std::complex<double>(-7., 0));
        CHECK(probe("  -0.7+1").value == std::complex<double>(-7., 0));
        CHECK(probe("  -.70+1").value == std::complex<double>(-7., 0));
        CHECK(probe("  -7.E+0").value == std::complex<double>(-7., 0));
        CHECK(probe("  -7.e+0").value == std::complex<double>(-7., 0));
        CHECK(probe("  -70.-1").value == std::complex<double>(-7., 0));
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
        CHECK_THROWS(probe("        "));
    }
}

TEST_CASE("BDF std::complex<double> types output.", "[bdf_types]") {

    entry_type<std::complex<double> > obj("dummy");

    entry_value<std::complex<double> > lval(std::complex<double>(1., 1.));
    entry_value<std::complex<double> > mlval(std::complex<double>(-1., -1.));

    SECTION("Preq") {
        CHECK(lval.value == std::complex<double>(1., 1.));
        CHECK(mlval.value == std::complex<double>(-1., -1.));
    }

    SECTION("SHORT") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        std::string res(obj.format(lval));
        CHECK(res == "1.000+001.000+00");
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "1.000+001.000+00");
        CHECK(obj.format(mlval).size() == 16);
        CHECK(obj.format(mlval) == "-1.00+00-1.00+00");
    }

    SECTION("SHORT (nullptr)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 16);
        CHECK(obj.format(nullptr) == "                ");
    }

    SECTION("SHORT ()") {
        auto p_lval = new std::complex<double>(1.);
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(*p_lval == 1.);
        CHECK(obj.format(p_lval).size() == 16);
        CHECK(obj.format(p_lval) == "1.000+000.000+00");
        *p_lval = std::complex<double>(2.9, -2.9);
        CHECK(obj.format(p_lval) == "2.900+00-2.90+00");
        *p_lval = std::complex<double>(1.9, -1.9);
        CHECK(obj.format(p_lval) == "1.900+00-1.90+00");
        *p_lval = std::complex<double>(0.);
        CHECK(obj.format(p_lval) == "0.000+000.000+00");
        delete p_lval;
    }

    SECTION("SHORT (inexact)") {
        auto p_lval = new std::complex<double>(1234.5);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.05);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.005);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.0005);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.00005);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.000005);
        CHECK(obj.format(p_lval).size() == 16);
        CHECK(obj.format(p_lval) == "1.234+030.000+00");
        *p_lval = std::complex<double>(1234.01);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.001);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.0001);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1234.00001);
        CHECK(obj.format(p_lval).size() == 16);
        CHECK(obj.format(p_lval) == "1.234+030.000+00");
        *p_lval = std::complex<double>(1233.9);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1233.99);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1233.999);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1233.9999);
        CHECK_THROWS(obj.format(p_lval));
        *p_lval = std::complex<double>(1233.99999);
        CHECK(obj.format(p_lval).size() == 16);
        CHECK(obj.format(p_lval) == "1.234+030.000+00");
        delete p_lval;
    }

    SECTION("LONG") {
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        CHECK(obj.format(lval).size() == 32);
        CHECK(obj.format(lval) == "1.00000000000+001.00000000000+00");
    }

    SECTION("FREE") {
        bdf::types::base::out_form = bdf::types::out_form_type::FREE;
        CHECK(obj.format(lval) == "1.000000+00,1.000000+00");
    }

    SECTION("FREE 2") {
        bdf::types::base::out_form = bdf::types::out_form_type::FREE;
        CHECK(obj.format(33) == "3.300000+01,0.000000+00");
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_header --use-colour no)"
// coding: utf-8
// End:
