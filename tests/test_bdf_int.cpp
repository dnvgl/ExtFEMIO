// Copyright © 2015 by DNV GL SE

// Task      Tests for BDF int types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include <limits>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <sstream>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/types.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

using namespace bdf;
using namespace bdf::types;

TEST_CASE("BDF int types parsing.", "[bdf_types]" ) {

  SECTION("'   2    '") {
    entry_type<long> obj("dummy", ::bdf::type_bounds::bound<long>(new long(1)));
    CHECK(*obj("   2    ") == 2);
  }

  SECTION("'       2'") {
    entry_type<long> obj("dummy", ::bdf::type_bounds::bound<long>(new long(0)));
    CHECK(*obj("       2") == 2);
  }

  SECTION("'2       '") {
    entry_type<long> obj("dummy", ::bdf::type_bounds::bound<long>(new long(0), NULL, new long(0)));
    CHECK(*obj("2       ") == 2);
  }

  SECTION("'    -1  '") {
    entry_type<long> obj("dummy", ::bdf::type_bounds::bound<long>(new long(-1), NULL, new long(0)));
    CHECK(*obj("    -1  ") == -1);
  }

  SECTION("default 1") {
    entry_type<long> obj("dummy", ::bdf::type_bounds::bound<long>(new long(-1), NULL, new long(0)));
    CHECK(*obj("        ") == 0);
  }

  SECTION("default 2") {
    entry_type<long> obj("dummy", ::bdf::type_bounds::bound<long>(new long(-1), NULL, new long(100)));
    CHECK(*obj("        ") == 100);
  }

  SECTION("123") {
    entry_type<long> obj("dummy");
    CHECK(*obj("123") == 123);
  }

  SECTION("123.") {
    entry_type<long> obj("dummy");
    CHECK_THROWS(*obj("123."));
  }
}

TEST_CASE("BDF int types output.", "[bdf_types]" ) {

  entry_type<long> obj("dummy");

  long lval = 1;

  SECTION("SHORT") {
    bdf::types::base::out_form = SHORT;
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "       1");
  }

  SECTION("SHORT (too long)") {
    bdf::types::base::out_form = SHORT;
    lval = 123456789;
    CHECK_THROWS(obj.format(lval));
  }

  SECTION("LONG") {
    bdf::types::base::out_form = LONG;
    std::string res(obj.format(lval));
    CHECK(obj.format(lval).size() == 16);
    CHECK(obj.format(lval) == "               1");
  }

  SECTION("FREE") {
    bdf::types::base::out_form = FREE;
    std::string res(obj.format(lval));
    CHECK(obj.format(lval) == "1");
  }
}


/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 8"
  coding: utf-8
  End:
*/
