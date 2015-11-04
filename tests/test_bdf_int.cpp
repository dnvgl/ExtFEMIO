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
#include "bdf/errors.h"

using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::types;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
  return Catch::toString( ex() );
}

TEST_CASE("BDF int types parsing.", "[bdf_types]" ) {

  SECTION("'   2    '") {
    entry_type<long> obj("dummy", type_bounds::bound<long>(new long(1)));
    CHECK(*obj("   2    ") == 2);
  }

  SECTION("'       2'") {
    entry_type<long> obj("dummy", type_bounds::bound<long>(new long(0)));
    CHECK(*obj("       2") == 2);
  }

  SECTION("'2       '") {
    entry_type<long> obj("dummy", type_bounds::bound<long>(new long(0), NULL, new long(0)));
    CHECK(*obj("2       ") == 2);
  }

  SECTION("'    -1  '") {
    entry_type<long> obj("dummy", type_bounds::bound<long>(new long(-1), NULL, new long(0)));
    CHECK(*obj("    -1  ") == -1);
  }

  SECTION("default 1") {
    entry_type<long> obj("dummy", type_bounds::bound<long>(new long(-1), NULL, new long(0)));
    CHECK(*obj("        ") == 0);
  }

  SECTION("default 2") {
    entry_type<long> obj("dummy", type_bounds::bound<long>(new long(-1), NULL, new long(100)));
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

  std::unique_ptr<long> lval = std::make_unique<long>(1);

  SECTION("SHORT") {
      bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "       1");
  }

  SECTION("SHORT (too long)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    lval = std::make_unique<long>(123456789);
    CHECK_THROWS(obj.format(lval));
  }

  SECTION("SHORT (nullptr)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format((std::unique_ptr<long>)nullptr).size() == 8);
    CHECK(obj.format((std::unique_ptr<long>)nullptr) == "        ");
  }

  SECTION("SHORT (void)") {
    long *lval = new long(1);
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(*lval == 1);
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "       1");
    delete lval;
  }

  SECTION("SHORT (nullptr, void)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format(nullptr).size() == 8);
    CHECK(obj.format(nullptr) == "        ");
  }

  SECTION("LONG") {
    bdf::types::base::out_form = bdf::types::LONG;
    std::string res(obj.format(lval));
    CHECK(obj.format(lval).size() == 16);
    CHECK(obj.format(lval) == "               1");
  }

  SECTION("FREE") {
    bdf::types::base::out_form = bdf::types::FREE;
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
