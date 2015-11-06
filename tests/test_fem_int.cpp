// Copyright © 2015 by DNV GL SE

// Task      Tests for SEASAM FEM int types.

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

#include "fem/types.h"
#include "fem/errors.h"

using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::types;
using namespace ::dnvgl::extfem::fem::type_bounds;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
  return Catch::toString( ex() );
}

TEST_CASE("FEM int types parsing.", "[fem_types]" ) {

  entry_type<long> probe("dummy", bound<long>(NULL, NULL, new long(0)));

  SECTION("'   2    '") {
    entry_type<long> obj("dummy", bound<long>(new long(1)));
    CHECK(*obj("   2    ") == 2);
  }

  SECTION("'       2'") {
    entry_type<long> obj("dummy", bound<long>(new long(0)));
    CHECK(*obj("       2") == 2);
  }

  SECTION("'2       '") {
    entry_type<long> obj("dummy", bound<long>(new long(0), NULL, new long(0)));
    CHECK(*obj("2       ") == 2);
  }

  SECTION("'    -1  '") {
    entry_type<long> obj("dummy", bound<long>(new long(-1), NULL, new long(0)));
    CHECK(*obj("    -1  ") == -1);
  }

  SECTION("default 1") {
    entry_type<long> obj("dummy", bound<long>(new long(-1), NULL, new long(0)));
    CHECK(*obj("        ") == 0);
  }

  SECTION("default 2") {
    entry_type<long> obj("dummy", bound<long>(new long(-1), NULL, new long(100)));
    CHECK(*obj("        ") == 100);
  }

  SECTION("123") {
    entry_type<long> obj("dummy");
    CHECK(*obj("123") == 123);
  }

  SECTION("123.") {
    entry_type<long> obj("dummy");
    CHECK(*obj("123.") == 123);
  }

  SECTION("Quick Reference") {
    ::std::vector<::std::string> samples;
    CHECK(*probe("           7.0  ") == 7);
    CHECK(*probe("           7.   ") == 7);
    CHECK(*probe("           .7E1 ") == 7);
    CHECK(*probe("           .7e1 ") == 7);
    CHECK(*probe("           7.E+0") == 7);
    CHECK(*probe("           7.e+0") == 7);
    CHECK(*probe("          -7.0  ") == -7);
    CHECK(*probe("          -7.   ") == -7);
    CHECK(*probe("          -.7E1 ") == -7);
    CHECK(*probe("          -.7e1 ") == -7);
    CHECK(*probe("          -7.E+0") == -7);
    CHECK(*probe("          -7.e+0") == -7);
    CHECK(*probe("           7    ") == 7);
    CHECK(*probe("           7E1  ") == 70);
    CHECK(*probe("           7e1  ") == 70);
    CHECK(*probe("           7E0  ") == 7);
    CHECK(*probe("           7e0  ") == 7);
    CHECK(*probe("           7E+0 ") == 7);
    CHECK(*probe("           7e+0 ") == 7);
  }
}

TEST_CASE("FEM int types output.", "[fem_types]" ) {

  entry_type<long> obj("dummy");

  std::unique_ptr<long> lval = std::make_unique<long>(1);

  SECTION("SHORT") {
    CHECK(obj.format(lval).size() == 16);
    CHECK(obj.format(lval) == "1.0000000000e+00");
  }

  SECTION("SHORT (nullptr)") {
    CHECK(obj.format((std::unique_ptr<long>)nullptr).size() == 16);
    CHECK(obj.format((std::unique_ptr<long>)nullptr) == "                ");
  }

  SECTION("SHORT (void)") {
    long *lval = new long(1);
    CHECK(*lval == 1);
    CHECK(obj.format(lval).size() == 16);
    CHECK(obj.format(lval) == "1.0000000000e+00");
    delete lval;
  }

  SECTION("SHORT (nullptr, void)") {
    CHECK(obj.format(nullptr).size() == 16);
    CHECK(obj.format(nullptr) == "                ");
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
