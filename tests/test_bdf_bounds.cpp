/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF boundary classes.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

// To avoid problems with "numeric_limits".
#define NOMINMAX

#include <limits>

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp
// file.
#define CATCH_CONFIG_MAIN
#endif

#include <memory>
#include <utility>

#include <catch.hpp>

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

using namespace dnvgl::extfem::bdf;
using types::entry_value;
using types::entry_type;

using type_bounds::bound;
using type_bounds::bound_unique;

namespace {
    auto const l0_ = make_shared<long>(0);
    auto const l1_ = make_shared<long>(1);
    auto const l6_ = make_shared<long>(6);
    auto const l12_ = make_shared<long>(12);
    auto const l_12_ = make_shared<long>(-12);
    auto const d1_ = make_shared<double>(1.);

    auto const l0 = l0_.get();
    auto const l1 = l1_.get();
    auto const l6 = l6_.get();
    auto const l12 = l12_.get();
    auto const l_12 = l_12_.get();
    auto const d1 = d1_.get();
}

TEST_CASE("BDF boundary definitions (long).", "[bdf_bounds]") {

    bound<long> probe;
    bound<long> probe_min(l_12, nullptr, nullptr);
    bound<long> probe_max(nullptr, l12, nullptr);
    bound<long> probe_mm(l_12, l12, nullptr);
    bound<long> probe_mmd(l_12, l12, l6);
    bound<long> probe_def(nullptr, nullptr, l1);

    SECTION("<nothing>") {
        CHECK_FALSE(probe.has_default());
        entry_value<long> val(numeric_limits<long>::min());
        CHECK(probe.in_bounds(val.value));
        val = entry_value<long>(long(0));
        CHECK(probe.in_bounds(val));
        val = entry_value<long>(numeric_limits<long>::max());
        CHECK(probe.in_bounds(val));
    }

    SECTION("min") {
        const long lmin = numeric_limits<long>::min();
        CHECK_FALSE(probe_min.has_default());
        entry_value<long> val(lmin);
        CHECK_FALSE(probe_min.in_bounds(val));
        entry_value<long> val_a(numeric_limits<long>::min());
        CHECK_FALSE(probe_min.in_bounds(val_a));
        val = entry_value<long>(-12);
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(numeric_limits<long>::max());
        CHECK(probe_min.in_bounds(val));
    }

    SECTION("min class") {
        CHECK_FALSE(probe_min.has_default());
        entry_value<long> val(numeric_limits<long>::min());
        CHECK_FALSE(probe_min.in_bounds(val));
        val = entry_value<long>(-12);
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(numeric_limits<long>::max());
        CHECK(probe_min.in_bounds(val));
    }

    SECTION("max") {
        CHECK_FALSE(probe_max.has_default());
        entry_value<long> val(numeric_limits<long>::max());
        CHECK_FALSE(probe_max.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(numeric_limits<long>::min());
        CHECK(probe_max.in_bounds(val));
    }

    SECTION("max class") {
        CHECK_FALSE(probe_max.has_default());
        entry_value<long> val(numeric_limits<long>::max());
        CHECK_FALSE(probe_max.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(numeric_limits<long>::min());
        CHECK(probe_max.in_bounds(val));
    }

    SECTION("min_max 1") {
        CHECK_FALSE(probe_mm.has_default());
        entry_value<long> val = entry_value<long>(
            numeric_limits<long>::min());
        CHECK_FALSE(probe_mm.in_bounds(val));
        val = entry_value<long>(-12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(numeric_limits<long>::max());
        CHECK_FALSE(probe_mm.in_bounds(val));
    }

    SECTION("min_max 2") {
        CHECK(probe_mmd.has_default());
        CHECK(probe_mmd.get_default() == 6);
        entry_value<long> val(numeric_limits<long>::min());
        CHECK_FALSE(probe_mmd.in_bounds(val));
        val = entry_value<long>(-12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_mmd.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(numeric_limits<long>::max());
        CHECK_FALSE(probe_mmd.in_bounds(val));
    }

    SECTION("<nothing> (with default)") {
        CHECK(probe_def.has_default());
        CHECK(probe_def.get_default() == 1);
    }
}

TEST_CASE("BDF boundary definitions (double).", "[bdf_bounds]") {

    bound<double> probe;
    bound<double> probe_def(nullptr, nullptr, d1);

    SECTION("<nothing>") {
        CHECK_FALSE(probe.has_default());
    }

    SECTION("<nothing> (with default)") {
        CHECK(probe_def.has_default());
        CHECK(probe_def.get_default() == 1.);
    }
}

TEST_CASE("string allowed values", "[bdf_bounds]") {
    set<std::string> const allowed({"A", "B", "C", "D"});
    std::string const std_val("A");
    auto const bound_tst_ = make_shared<bound<std::string>>(allowed, std_val);
    auto const bound_tst = bound_tst_.get();
    entry_type<std::string> form_tst("tst", bound_tst);

    SECTION("set default") {
        entry_value<std::string> val;

        form_tst.set_value(val, "");
        CHECK(std::string(val) == "A");
    }

    SECTION("check for valid value") {
        entry_value<std::string> val("E");
        CHECK_THROWS_AS(form_tst.check(val), errors::str_error);
    }

    SECTION("unexpected fail in cbar") {
        entry_value<std::string> val("EEG");
        set<std::string> allowed({"GGG", "BGG", "GGO", "BGO", "GOG",
                    "BOG", "GOO", "BOO"});
        auto const bound_OFFT_ = make_shared<bound<std::string>>(allowed,
            "GGG");
        auto const bound_OFFT = bound_OFFT_.get();
        entry_type<std::string> form_OFFT("OFFT", bound_OFFT);
        CHECK_THROWS_AS(form_OFFT.check(val), errors::str_error);
    }
}

TEST_CASE("Test unique ids", "[bdf_unique_id]") {
    shared_ptr<bound_unique<long>> b = make_shared<bound_unique<long>>(
        l1, l6, nullptr, false);
    entry_type<long> form_val("val", b.get());
    entry_value<long> val1;
    entry_value<long> val2;
    val1 = form_val.check(val1);
    val2 = form_val.check(val2);
    CHECK(long(val1) == 1);
    CHECK(long(val2) == 2);
    val1 = form_val.check(val1);
    val2 = form_val.check(val2);
    CHECK(long(val1) == 3);
    CHECK(long(val2) == 4);
    val1 = form_val.check(0);
    val2 = form_val.check(0);
    CHECK(long(val1) == 5);
    CHECK(long(val2) == 6);
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_bdf_bounds --use-colour no)"
// coding: utf-8
// End:
