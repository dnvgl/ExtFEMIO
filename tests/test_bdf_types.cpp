/**
   \file tests/test_bdf_types.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing of definitions for Nastran Bulk data entry types.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX

#include <utility>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

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
using namespace std::rel_ops;

using namespace dnvgl::extfem;
using namespace bdf::types;

namespace {
    const long cl1 = 1;
    const double cf1 = 1;
}

TEST_CASE("BDF types are compared.", "[bdf_types]" ) {

    entry_type<long> obj_int("d_int");
    entry_type<double> obj_float("d_float");
    entry_type<std::list<int> > obj_list("d_dque");
    entry_type<std::complex<double> > obj_cplx("d_cplx");

    SECTION("Checking 'entry_type<long>.type' against 'Int'") {
        REQUIRE(entry_type<long>("dummy idiot").type() == bdf_types::Int);
    }

    SECTION("Checking 'entry_type<long>->type' against 'Int'") {
        REQUIRE(obj_int.type() == bdf_types::Int);
    }

    SECTION("Checking 'entry_type<double>.type' against 'Float'") {
        REQUIRE(entry_type<double>("dummy float").type() == bdf_types::Float);
    }

    SECTION("Checking 'entry_type<double>->type' against 'Float'") {
        REQUIRE(obj_float.type() == bdf_types::Float);
    }

    SECTION("Checking 'bdf_list.type' against 'List'") {
        REQUIRE(entry_type<std::list<int> >("dummy").type() == bdf_types::List);
    }

    SECTION("Checking 'bdf_list->type' against 'List'") {
        REQUIRE(obj_list.type() == bdf_types::List);
    }

    SECTION("Checking 'bdf_complex->type' against 'Complex'") {
        REQUIRE(obj_cplx.type() == bdf_types::Complex);
    }

    SECTION("Comparing 'entry_type<long>' with 'entry_type<double>'") {
        REQUIRE(
            entry_type<long>("dummy int") < entry_type<double>("dummy float"));
        REQUIRE(
            (entry_type<double>("dummy float") > entry_type<long>("dummy int")));
        REQUIRE(
            (entry_type<long>("dummy int") != entry_type<double>("dummy float")));
    }

    SECTION("Comparing '*entry_type<long>' with '*entry_type<double>'") {
        REQUIRE(obj_int < obj_float);
    }
}

TEST_CASE("Testing bdf entry values.", "[bdf_types]" ) {

    entry_type<long> obj_int("dummy1");
    entry_type<double> obj_float("dummy2");
    entry_type<std::list<int> > obj_list("dummy 3");

    entry_value<long> val_int;
    entry_value<double> val_float;
    entry_value<std::list<int> > val_list;

    SECTION("Simple integer value") {
        obj_int.set_value(val_int, "3");
        REQUIRE((long)val_int == 3);
    }

    SECTION("Simple integer value with default") {
        entry_type<long> obj_int_l(
            "dummy1",
            bdf::type_bounds::bound<long>(nullptr, nullptr, &cl1));
        obj_int_l.set_value(val_int, "");
        REQUIRE((long)val_int == 1);
    }

    SECTION("Simple float value") {
        obj_float.set_value(val_float, "3.");
        REQUIRE((double)val_float == 3.);
    }

    SECTION("Simple float value with default") {
        entry_type<double> obj_float_l(
            "dummy2",
            bdf::type_bounds::bound<double>(nullptr, nullptr, &cf1));
        obj_float_l.set_value(val_float, "");
        REQUIRE((double)val_float == 1.);
    }

    SECTION("Simple int list value") {
        obj_list.set_value(val_list, "123");
        REQUIRE(val_list.value == list<int>({1, 2, 3}));
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_types --use-colour no)"
// coding: utf-8
// End:
