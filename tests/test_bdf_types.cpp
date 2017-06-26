/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing of definitions for Nastran Bulk data entry types.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX

#include <utility>
#include <memory>

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#endif 

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
using bdf::type_bounds::bound;

namespace {
    auto const cl1_ = make_shared<long>(1);
    auto const cl1 = cl1_.get();
    auto const cf1_ = make_shared<double>(1.);
    auto const cf1 = cf1_.get();
}

TEST_CASE("BDF types are compared: Checking 'entry_type<long>.type' against "
          "'Int'.", "[bdf_types]" ) {
    entry_type<long> obj_int("d_int");
    CHECK(entry_type<long>("dummy int").type() == bdf_types::Int);
}

TEST_CASE("BDF types are compared: Checking 'entry_type<long>->type' against "
          "'Int'.", "[bdf_types]" ) {
    entry_type<long> obj_int("d_int");
    CHECK(obj_int.type() == bdf_types::Int);
}

TEST_CASE("BDF types are compared: Checking 'entry_type<double>.type' against "
          "'Float'.", "[bdf_types]" ) {
    CHECK(entry_type<double>("dummy float").type() == bdf_types::Float);
}

TEST_CASE("BDF types are compared: Checking 'entry_type<double>->type' against "
          "'Float'.", "[bdf_types]" ) {
    entry_type<double> obj_float("d_float");
    CHECK(obj_float.type() == bdf_types::Float);
}

TEST_CASE("BDF types are compared: Checking 'bdf_list.type' against 'List'.",
          "[bdf_types]" ) {
    CHECK(entry_type<std::vector<int> >("dummy").type() == bdf_types::List);
}

TEST_CASE("BDF types are compared: Checking 'bdf_list->type' against 'List'.",
          "[bdf_types]" ) {
    entry_type<std::vector<int> > obj_list("d_dque");
    CHECK(obj_list.type() == bdf_types::List);
}

TEST_CASE("BDF types are compared: Checking 'bdf_complex->type' against "
          "'Complex'.", "[bdf_types]" ) {
    entry_type<std::complex<double> > obj_cplx("d_cplx");
    CHECK(obj_cplx.type() == bdf_types::Complex);
}

TEST_CASE("BDF types are compared: Comparing 'entry_type<long>' with "
          "'entry_type<double>'.", "[bdf_types]" ) {
    CHECK(
        entry_type<long>("dummy int") < entry_type<double>("dummy float"));
    CHECK(
        (entry_type<double>("dummy float") > entry_type<long>("dummy int")));
    CHECK(
        (entry_type<long>("dummy int") != entry_type<double>("dummy float")));
}

TEST_CASE("BDF types are compared: Comparing '*entry_type<long>' with "
          "'*entry_type<double>'.", "[bdf_types]" ) {
    entry_type<long> obj_int("d_int");
    entry_type<double> obj_float("d_float");
    CHECK(obj_int < obj_float);
}

TEST_CASE("Testing bdf entry values: Simple integer value.", "[bdf_types]" ) {
    entry_type<long> obj_int("dummy1");
    entry_value<long> val_int;
    obj_int.set_value(val_int, "3");
    CHECK((long)val_int == 3);
}

TEST_CASE("Testing bdf entry values: Simple integer value with default.",
          "[bdf_types]" ) {
    shared_ptr<bound<long>> b = make_shared<bound<long>>(nullptr, nullptr, cl1);
    entry_type<long> obj_int_l( "dummy1", b.get());
    entry_value<long> val_int;
    obj_int_l.set_value(val_int, "");
    CHECK((long)val_int == 1);
}

TEST_CASE("Testing bdf entry values: Simple float value.", "[bdf_types]" ) {
    entry_type<double> obj_float("dummy2");
    entry_value<double> val_float;
    obj_float.set_value(val_float, "3.");
    CHECK((double)val_float == 3.);
}

TEST_CASE("Testing bdf entry values: Simple float value with default.",
          "[bdf_types]" ) {
    auto const bound_dummy2 = make_shared<bound<double>>(nullptr, nullptr, cf1);
    entry_type<double> obj_float_l("dummy2", bound_dummy2.get());
    entry_value<double> val_float;
    obj_float_l.set_value(val_float, "");
    CHECK((double)val_float == 1.);
}

TEST_CASE("Testing bdf entry values: Simple int list value.", "[bdf_types]" ) {
    entry_type<std::vector<int> > obj_list("dummy 3");
    entry_value<std::vector<int> > val_list;
    obj_list.set_value(val_list, "123");
    CHECK(val_list == vector<int>({1, 2, 3}));
    // TODO: CHECK(vector<int>({1, 2, 3}) == val_list);
}


// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8 &&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_types --use-colour no)"
// coding: utf-8
// End:
