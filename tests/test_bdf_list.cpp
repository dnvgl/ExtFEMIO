/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF list class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_bdf_list[]) =
        "@(#) $Id$";
}

#include <string>
#include <deque>

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#endif

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::types;
using namespace dnvgl::extfem::bdf::type_bounds;

TEST_CASE("BDF list types parsing.", "[bdf_types]") {

    entry_type<std::vector<int> > probe("dummy");

    SECTION("' 1234   '") {
        std::vector<int> ref({1, 2, 3, 4});
        CHECK(probe("  1234  ").value == ref);
    }

    SECTION("' 1236   '") {
        std::vector<int> ref({1, 2, 3, 6});
        CHECK(probe(" 1236   ").value == ref);
    }

    SECTION("' 1a3b   '") {
        CHECK_THROWS(probe(" 1a3b   "));
    }
}

TEST_CASE("BDF list of int types output.", "[bdf_types]") {

    entry_type<std::vector<int> > obj("dummy");

    //std::vector<int> inp({ 1, 2, 3, 4 });
    entry_value<std::vector<int> > lval({1, 2, 3, 4});

    std::ostringstream stream(std::ostringstream::ate);

    SECTION("SHORT") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        stream << obj.format(lval);
        CHECK(stream.str().size() == 8);
        CHECK(stream.str() == "    1234");
    }

    SECTION("SHORT (nullptr)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("SHORT ()") {
        std::vector<int> llval(lval.value);
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(&llval).size() == 8);
        CHECK(obj.format(&llval) == "    1234");
    }

    SECTION("SHORT (nullptr)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        CHECK(obj.format(nullptr).size() == 8);
        CHECK(obj.format(nullptr) == "        ");
    }

    SECTION("SHORT (too long)") {
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
        lval.value.push_back(1);
        lval.value.push_back(2);
        lval.value.push_back(3);
        lval.value.push_back(4);
        lval.value.push_back(4);
        CHECK_THROWS(obj.format(lval));
    }

    SECTION("LONG") {
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        stream << obj.format(lval);
        CHECK(stream.str().size() == 16);
        CHECK(stream.str() == "            1234");
    }

    SECTION("FREE") {
        bdf::types::base::out_form = bdf::types::out_form_type::FREE;
        stream << obj.format(lval);
        CHECK(stream.str() == "1234");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_list --use-colour no)"
// End:
