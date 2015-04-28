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

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp fil
#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

using namespace bdf::types;
using namespace bdf::type_bounds;

TEST_CASE("BDF int types parsing.", "[bdf_types]" ) {

  SECTION("'   2    '") {
    bdf_int obj("dummy", bdf_num_bounds<long>(new long(1)));
    obj("   2    ");
    CHECK(obj.value == 2);
  }

  SECTION("'       2'") {
    bdf_int obj("dummy", bdf_num_bounds<long>(new long(0)));
    obj("       2");
    CHECK(obj.value == 2);
  }

  SECTION("'2       '") {
    bdf_int obj("dummy", bdf_num_bounds<long>(new long(0), NULL, new long(0)));
    obj("2       ");
    CHECK(obj.value == 2);
  }

  SECTION("'    -1  '") {
    bdf_int obj("dummy", bdf_num_bounds<long>(new long(-1), NULL, new long(0)));
    obj("    -1  ");
    CHECK(obj.value == -1);
  }

  SECTION("default 1") {
    bdf_int obj("dummy", bdf_num_bounds<long>(new long(-1), NULL, new long(0)));
    obj("        ");
    CHECK(obj.value == 0);
  }

  SECTION("default 2") {
    bdf_int obj("dummy", bdf_num_bounds<long>(new long(-1), NULL, new long(100)));
    obj("        ");
    CHECK(obj.value == 100);
  }
}

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check"
  coding: utf-8
  End:
*/
