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

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp fil
#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;

TEST_CASE("BDF float types parsing.", "[bdf_types]" ) {

  bdf_float probe(num<double>(NULL, NULL, new double(0.)));

  SECTION("'   1.   '") {
    probe.parse("   1.   ");
    CHECK(probe() == 1.);
  }

  SECTION("'  .1    '") {
    probe.parse("  .1    ");
    CHECK(probe() == .1);
  }

  SECTION("'  -1.   '") {
    probe.parse("  -1.   ");
    CHECK(probe() == -1.);
  }

  SECTION("'  -.1   '") {
    probe.parse("  -.1   ");
    CHECK(probe() == -.1);
  }

  SECTION("'  -1.   ', min 0.") {
    bdf_float probe(num<double>(new double(0.), NULL, new double(0.)));
    CHECK_THROWS(probe.parse("  -1.   "));
  }

  SECTION("Quick Reference") {
    ::std::vector<string> samples;
    probe.parse("   7.0  ");    CHECK(probe() == 7.);
    probe.parse("   7.   ");    CHECK(probe() == 7.);
    probe.parse("   .7"   );    CHECK(probe() == .7);
    probe.parse("   .7E1 ");    CHECK(probe() == 7.);
    probe.parse("   .7e1 ");    CHECK(probe() == 7.);
    probe.parse("   0.7+1");    CHECK(probe() == 7.);
    probe.parse("   .70+1");    CHECK(probe() == 7.);
    probe.parse("   7.E+0");    CHECK(probe() == 7.);
    probe.parse("   7.e+0");    CHECK(probe() == 7.);
    probe.parse("   70.-1");    CHECK(probe() == 7.);
    probe.parse("  -7.0  ");    CHECK(probe() == -7.);
    probe.parse("  -7.   ");    CHECK(probe() == -7.);
    probe.parse("  -.7"   );    CHECK(probe() == -.7);
    probe.parse("  -.7E1 ");    CHECK(probe() == -7.);
    probe.parse("  -.7e1 ");    CHECK(probe() == -7.);
    probe.parse("  -0.7+1");    CHECK(probe() == -7.);
    probe.parse("  -.70+1");    CHECK(probe() == -7.);
    probe.parse("  -7.E+0");    CHECK(probe() == -7.);
    probe.parse("  -7.e+0");    CHECK(probe() == -7.);
    probe.parse("  -70.-1");    CHECK(probe() == -7.);
  }

  SECTION("Invalid values") {
    CHECK_THROWS(probe.parse("   7    "));
    CHECK_THROWS(probe.parse("   7E1  "));
    CHECK_THROWS(probe.parse("   7e1  "));
    CHECK_THROWS(probe.parse("   7E0  "));
    CHECK_THROWS(probe.parse("   7e0  "));
    CHECK_THROWS(probe.parse("   7E+0 "));
    CHECK_THROWS(probe.parse("   7e+0 "));
    CHECK_THROWS(probe.parse("   70-1 "));
  }

  SECTION("'        '") {
    probe.parse("        ");
    CHECK(probe() == 0.);
  }

  SECTION("'        ', no default") {
    bdf_float probe(num<double>(NULL, NULL, NULL));
    CHECK_THROWS(probe.parse("        "));
  }

  SECTION("'   123.  '") {
    probe.parse("   123.  ");
    CHECK(probe() == 123.);
  }

  SECTION("'   .123  '") {
    probe.parse("   .123  ");
    CHECK(probe() == .123);
  }

  SECTION("'   .123+3  '") {
    probe.parse("   .123+3  ");
    CHECK(probe() == 123.);
  }

  SECTION("'  123.+3        '") {
    probe.parse("  123.+3        ");
    CHECK(probe() == 123000.);
  }

  SECTION("' +123.+3        '") {
    probe.parse(" +123.+3        ");
    CHECK(probe() == 123000.);
  }

  SECTION("' -123.+3        '") {
    probe.parse(" -123.+3        ");
    CHECK(probe() == -123000.);
  }

  SECTION("' +123.-3        '") {
    probe.parse(" +123.-3        ");
    CHECK(probe() == .123);
  }

  SECTION("' -123.-3        '") {
    probe.parse(" -123.-3        ");
    CHECK(probe() == -.123);
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
