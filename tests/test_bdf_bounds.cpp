/**
   \file tests/test_bdf_bounds.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF boundary classes.

   Detailed description
   */

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

// To avoid problems with "numeric_limits".
#define NOMINMAX

#include <limits>

// This tells Catch to provide a main() - only do this in one cpp
// file.
#define CATCH_CONFIG_MAIN

#include <memory>

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

using namespace dnvgl::extfem::bdf;
using types::entry_value;
using types::entry_type;

TEST_CASE("BDF boundary definitions (long).", "[bdf_bounds]") {

    const long twelve = 12, ntwelve = -12, six = 6, one = 1;
    type_bounds::bound<long> probe;
    type_bounds::bound<long> probe_min(&ntwelve, nullptr, nullptr);
    type_bounds::bound<long> probe_max(nullptr, &twelve, nullptr);
    type_bounds::bound<long> probe_mm(&ntwelve, &twelve, nullptr);
    type_bounds::bound<long> probe_mmd(&ntwelve, &twelve, &six);
    type_bounds::bound<long> probe_def(nullptr, nullptr, &one);

    SECTION("<nothing>") {
        CHECK_FALSE(probe.has_default());
        entry_value<long> val(std::numeric_limits<long>::min());
        CHECK(probe.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe.in_bounds(val));
        val = entry_value<long>(std::numeric_limits<long>::max());
        CHECK(probe.in_bounds(val));
    }

    SECTION("min") {
        const long lmin = std::numeric_limits<long>::min();
        CHECK_FALSE(probe_min.has_default());
        entry_value<long> val(&lmin);
        CHECK_FALSE(probe_min.in_bounds(val));
        entry_value<long> val_a(std::numeric_limits<long>::min());
        CHECK_FALSE(probe_min.in_bounds(val_a));
        val = entry_value<long>(-12);
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(std::numeric_limits<long>::max());
        CHECK(probe_min.in_bounds(val));
    }

    SECTION("min class") {
        CHECK_FALSE(probe_min.has_default());
        entry_value<long> val(std::numeric_limits<long>::min());
        CHECK_FALSE(probe_min.in_bounds(val));
        val = entry_value<long>(-12);
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_min.in_bounds(val));
        val = entry_value<long>(std::numeric_limits<long>::max());
        CHECK(probe_min.in_bounds(val));
    }

    SECTION("max") {
        CHECK_FALSE(probe_max.has_default());
        entry_value<long> val(std::numeric_limits<long>::max());
        CHECK_FALSE(probe_max.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(std::numeric_limits<long>::min());
        CHECK(probe_max.in_bounds(val));
    }

    SECTION("max class") {
        CHECK_FALSE(probe_max.has_default());
        entry_value<long> val(std::numeric_limits<long>::max());
        CHECK_FALSE(probe_max.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_max.in_bounds(val));
        val = entry_value<long>(std::numeric_limits<long>::min());
        CHECK(probe_max.in_bounds(val));
    }

    SECTION("min_max 1") {
        CHECK_FALSE(probe_mm.has_default());
        entry_value<long> val = entry_value<long>(
            std::numeric_limits<long>::min());
        CHECK_FALSE(probe_mm.in_bounds(val));
        val = entry_value<long>(-12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(std::numeric_limits<long>::max());
        CHECK_FALSE(probe_mm.in_bounds(val));
    }

    SECTION("min_max 2") {
        CHECK(probe_mmd.has_default());
        CHECK(probe_mmd.get_default() == 6);
        entry_value<long> val(std::numeric_limits<long>::min());
        CHECK_FALSE(probe_mmd.in_bounds(val));
        val = entry_value<long>(-12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(long(0));
        CHECK(probe_mmd.in_bounds(val));
        val = entry_value<long>(12);
        CHECK(probe_mm.in_bounds(val));
        val = entry_value<long>(std::numeric_limits<long>::max());
        CHECK_FALSE(probe_mmd.in_bounds(val));
    }

    SECTION("<nothing> (with default)") {
        CHECK(probe_def.has_default());
        CHECK(probe_def.get_default() == 1);
    }
}

TEST_CASE("BDF boundary definitions (double).", "[bdf_bounds]") {

    const double one = 1.;
    type_bounds::bound<double> probe;
    type_bounds::bound<double> probe_def(nullptr, nullptr, &one);

    SECTION("<nothing>") {
        CHECK_FALSE(probe.has_default());
    }

    SECTION("<nothing> (with default)") {
        CHECK(probe_def.has_default());
        CHECK(probe_def.get_default() == 1.);
    }
}

TEST_CASE("string allowed values", "[bdf_bounds]") {
    entry_type<std::string> const form_tst(
        "tst", type_bounds::bound<std::string>({
                "A", "B", "C", "D"}, "A"));

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
        entry_type<std::string> const form_OFFT(
            "OFFT", type_bounds::bound<std::string>({
                    "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO"},
                "GGG"));
        CHECK_THROWS_AS(form_OFFT.check(val), errors::str_error);
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_bdf_bounds --use-colour no)"
// coding: utf-8
// End:
