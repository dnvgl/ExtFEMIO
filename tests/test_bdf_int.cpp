/**
   \file tests/test_bdf_int.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for BDF int types.

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

#include "bdf/types.h"

#include <clocale>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::types;

namespace {
    const long cl1 = 1, cl100 = 100, cl_1 = -1, cl0 = 0;
}

TEST_CASE("BDF int types parsing.", "[bdf_types]") {

    SECTION("'   2    '") {
        entry_type<long> obj("dummy", type_bounds::bound<long>(&cl1));
        CHECK(obj("   2    ").value == 2);
    }

    SECTION("'       2'") {
        entry_type<long> obj("dummy", type_bounds::bound<long>(&cl0));
        CHECK(obj("       2").value == 2);
    }

    SECTION("'2       '") {
        entry_type<long> obj(
            "dummy", type_bounds::bound<long>(&cl0, nullptr, &cl0));
        CHECK(obj("2       ").value == 2);
    }

    SECTION("'    -1  '") {
        entry_type<long> obj(
            "dummy", type_bounds::bound<long>(&cl_1, nullptr, &cl0));
        CHECK(obj("    -1  ").value == -1);
    }

    SECTION("default 1") {
        entry_type<long> obj(
            "dummy", type_bounds::bound<long>(&cl_1, nullptr, &cl0));
        CHECK(obj("        ").value == 0);
    }

    SECTION("default 2") {
        entry_type<long> obj(
            "dummy", type_bounds::bound<long>(&cl_1, nullptr, &cl100));
        CHECK(obj("        ").value == 100);
    }

    SECTION("123") {
        entry_type<long> obj("dummy");
        CHECK(obj("123").value == 123);
    }

    SECTION("123.") {
        entry_type<long> obj("dummy");
        CHECK_THROWS(obj("123."));
    }
}

TEST_CASE("BDF int types output.", "[bdf_types]") {

    entry_type<long> obj("dummy");

    long lval(1);

    SECTION("SHORT") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(lval).size() == 8);
        CHECK(obj.format(lval) == "       1");
    }

    SECTION("SHORT (too long)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        lval = 123456789;
        CHECK_THROWS(obj.format(lval));
    }

    SECTION("SHORT (nullptr)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("SHORT ()") {
        lval = 1;
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(&lval).size() == 8);
        CHECK(obj.format(&lval) == "       1");
    }

    SECTION("SHORT (nullptr, void)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("LONG") {
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        std::string res(obj.format(lval));
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "               1");
    }

    SECTION("FREE") {
        bdf::types::base::out_form = bdf::types::out_form_type::FREE;
        std::string res(obj.format(lval));
        CHECK(obj.format(lval) == "1");
    }
}

TEST_CASE("Locale, mkoe 2016-01-07 [FEMIO-1]") {
    SECTION("SHORT (>=1e3)") {
        std::locale locsave(std::locale::global(std::locale("")));

        entry_type<long> obj("dummy");
        long lval(1234);

        std::locale::global(locsave);

        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(lval) == "    1234");
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_int --use-colour no)"
// coding: utf-8
// End:
