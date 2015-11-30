// Copyright © 2015 by DNV GL SE

// Testing of definitions for Nastran Bulk data entry types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#define NOMINMAX

#include <utility>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/types.h"

using namespace ::dnvgl::extfem;

CATCH_TRANSLATE_EXCEPTION( bdf::errors::error& ex ) {
   return Catch::toString( ex() );
}

using namespace bdf::types;

TEST_CASE("BDF types are compared.", "[bdf_types]" ) {

   bdf::types::base* obj_int = new entry_type<long>("dummy1");
   bdf::types::base* obj_float = new entry_type<double>("dummy2");
   bdf::types::base* obj_list = new entry_type<::std::deque<int>>("dummy 3");

   SECTION("Checking 'entry_type<long>.type' against 'Int'") {
      CHECK(entry_type<long>("dummy idiot").type() == Int);
   }

   SECTION("Checking 'entry_type<long>->type' against 'Int'") {
      CHECK(obj_int->type() == Int);
   }

   SECTION("Checking 'entry_type<double>.type' against 'Float'") {
      CHECK(entry_type<double>("dummy float").type() == Float);
   }

   SECTION("Checking 'entry_type<double>->type' against 'Float'") {
      CHECK(obj_float->type() == Float);
   }

   SECTION("Checking 'bdf_list.type' against 'List'") {
      CHECK(entry_type<::std::deque<int>>("dummy").type() == List);
   }

   SECTION("Checking 'bdf_list->type' against 'List'") {
      CHECK(obj_list->type() == List);
   }

   SECTION("Comparing 'entry_type<long>' with 'entry_type<double>'") {
      CHECK(entry_type<long>("dummy int") < entry_type<double>("dummy float"));
      CHECK(entry_type<double>("dummy float") > entry_type<long>("dummy int"));
      CHECK(entry_type<long>("dummy int") != entry_type<double>("dummy float"));
   }

   SECTION("Comparing '*entry_type<long>' with '*entry_type<double>'") {
      CHECK(*obj_int < *obj_float);
   }
}

TEST_CASE("Testing bdf entry values.", "[bdf_types]" ) {

   entry_type<long> obj_int("dummy1");
   entry_type<double> obj_float("dummy2");
   entry_type<::std::deque<int>> obj_list("dummy 3");

   entry_value<long> val_int;
   entry_value<double> val_float;
   entry_value<::std::deque<int>> val_list;

   SECTION("Simple integer value") {
      obj_int.set_value(val_int, "3");
      CHECK((long)val_int == 3);
   }


   SECTION("Simple integer value with default") {
      entry_type<long> obj_int(
         "dummy1",
         bdf::type_bounds::bound<long>(nullptr, nullptr, ::std::make_unique<long>(1).get()));
      obj_int.set_value(val_int, "");
      CHECK((long)val_int == 1);
   }


}
/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C ../ check -j 8"
  coding: utf-8
  End:
*/
