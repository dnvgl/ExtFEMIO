/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for BDF str types.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#endif

#include <catch.hpp>

#include <set>

#ifdef __GNUC__
#include "config.h"
#endif

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

TEST_CASE("BDF str types parsing.", "[bdf_types]") {

    set<std::string> const allowed({"ONE", "TWO", "THREE"});
    auto const str_allowed = make_shared<type_bounds::bound<std::string>>(allowed);
    auto const one = make_shared<std::string>("ONE");
    auto const str_allowed_default = make_shared<type_bounds::bound<std::string>>(
        allowed, one);

    SECTION("'TEST    '") {
        entry_type<std::string> obj("dummy");
        CHECK(obj(entry_value<std::string>("TEST    ")) == std::string("TEST"));
    }

    SECTION("'ONE     '") {
        entry_type<std::string> obj("dummy", str_allowed);
        CHECK(obj("ONE     ") == "ONE");
    }

    SECTION("'FOUR        '") {
        entry_type<std::string> obj("dummy", str_allowed);
        CHECK_THROWS(obj("FOUR    "));
    }

    SECTION("'            '") {
        entry_type<std::string> obj("dummy", str_allowed);
        CHECK_THROWS(obj("        "));
    }

    SECTION("'            ', 1") {
        entry_type<std::string> obj("dummy", str_allowed_default);
        CHECK(obj("        ") == "ONE");
    }
}

TEST_CASE("BDF list of str types output.", "[bdf_types]") {

    entry_type<std::string> obj("dummy");

    entry_value<std::string> lval("abcd");

    SECTION("SHORT") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(lval).size() == 8);
        CHECK(obj.format(lval) == "abcd    ");
    }

    SECTION("SHORT (nullptr)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("SHORT ()") {
        std::string lval_l("abcd");
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(&lval_l).size() == 8);
        CHECK(obj.format(&lval_l) == "abcd    ");
    }

    SECTION("SHORT (nullptr, void)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("SHORT (too long)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        lval = entry_value<std::string>("abcdefghi");
        CHECK_THROWS(obj.format(lval));
    }

    SECTION("LONG") {
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        CHECK(obj.format(lval).size() == 16);
        CHECK(obj.format(lval) == "abcd            ");
    }

    SECTION("FREE") {
        bdf::types::base::out_form = bdf::types::out_form_type::FREE;
        CHECK(obj.format(lval) == "abcd");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_str --use-colour no)"
// End:
