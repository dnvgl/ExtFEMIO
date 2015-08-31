// Copyright © 2015 by DNV GL SE

// Task      Tests for BDF float types.

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
#include <string>
#include <vector>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;

TEST_CASE("BDF float types parsing.", "[bdf_types]" ) {

  entry_type<double> probe("dummy", ::bdf::type_bounds::bound<double>(NULL, NULL, make_unique<double>(0.).get()));

  SECTION("'   1.   '") {
    CHECK(*probe("   1.   ") == 1.);
  }

  SECTION("'  .1    '") {
    CHECK(*probe("  .1    ") == .1);
  }

  SECTION("'  -1.   '") {
    CHECK(*probe("  -1.   ") == -1.);
  }

  SECTION("'  -.1   '") {
    CHECK(*probe("  -.1   ") == -.1);
  }

  SECTION("'  -1.   ', min 0.") {
    entry_type<double> probe("dummy", ::bdf::type_bounds::bound<double>(new double(0.), NULL, new double(0.)));
    CHECK_THROWS(*probe("  -1.   "));
  }

  SECTION("Quick Reference") {
    ::std::vector<string> samples;
    CHECK(*probe("   7.0  ") == 7.);
    CHECK(*probe("   7.   ") == 7.);
    CHECK(*probe("   .7"   ) == .7);
    CHECK(*probe("   .7E1 ") == 7.);
    CHECK(*probe("   .7e1 ") == 7.);
    CHECK(*probe("   0.7+1") == 7.);
    CHECK(*probe("   .70+1") == 7.);
    CHECK(*probe("   7.E+0") == 7.);
    CHECK(*probe("   7.e+0") == 7.);
    CHECK(*probe("   70.-1") == 7.);
    CHECK(*probe("  -7.0  ") == -7.);
    CHECK(*probe("  -7.   ") == -7.);
    CHECK(*probe("  -.7"   ) == -.7);
    CHECK(*probe("  -.7E1 ") == -7.);
    CHECK(*probe("  -.7e1 ") == -7.);
    CHECK(*probe("  -0.7+1") == -7.);
    CHECK(*probe("  -.70+1") == -7.);
    CHECK(*probe("  -7.E+0") == -7.);
    CHECK(*probe("  -7.e+0") == -7.);
    CHECK(*probe("  -70.-1") == -7.);
  }

  SECTION("Invalid values") {
    CHECK_THROWS(*probe("   7    "));
    CHECK_THROWS(*probe("   7E1  "));
    CHECK_THROWS(*probe("   7e1  "));
    CHECK_THROWS(*probe("   7E0  "));
    CHECK_THROWS(*probe("   7e0  "));
    CHECK_THROWS(*probe("   7E+0 "));
    CHECK_THROWS(*probe("   7e+0 "));
    CHECK_THROWS(*probe("   70-1 "));
  }

  SECTION("'        '") {
    CHECK(*probe("        ") == 0.);
  }

  SECTION("'        ', no default") {
    entry_type<double> probe("dummy", ::bdf::type_bounds::bound<double>(NULL, NULL, NULL));
    CHECK_THROWS(*probe("        "));
  }

  SECTION("'   123.  '") {
    CHECK(*probe("   123.  ") == 123.);
  }

  SECTION("'   .123  '") {
    CHECK(*probe("   .123  ") == .123);
  }

  SECTION("'   .123+3  '") {
    CHECK(*probe("   .123+3  ") == 123.);
  }

  SECTION("'  123.+3        '") {
    CHECK(*probe("  123.+3        ") == 123000.);
  }

  SECTION("' +123.+3        '") {
    CHECK(*probe(" +123.+3        ") == 123000.);
  }

  SECTION("' -123.+3        '") {
    CHECK(*probe(" -123.+3        ") == -123000.);
  }

  SECTION("' +123.-3        '") {
    CHECK(*probe(" +123.-3        ") == 0.123);
  }

  SECTION("' -123.-3        '") {
    CHECK(*probe(" -123.-3        ") == -0.123);
  }

  SECTION("' .736831        '") {
    CHECK(*probe(" .736831        ") ==  0.736831);
  }

  SECTION("'        '") {
    entry_type<double> probe(
      "probe", ::bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
    CHECK_FALSE(probe("        "));
  }
}


/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 8"
  coding: utf-8
  End:
*/
