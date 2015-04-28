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

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp fil
#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

using namespace bdf::types;
using namespace bdf::type_bounds;

TEST_CASE("BDF float types parsing.", "[bdf_types]" ) {

  bdf_float probe("dummy", bdf_num_bounds<double>(NULL, NULL, new double(0.)));

  SECTION("'  -1.   '") {
    probe("  -1.   ");
    CHECK(probe.value == -1.);
  }

  SECTION("'  -1.   ', min 0.") {
    bdf_float probe("dummy", bdf_num_bounds<double>(new double(0.), NULL, new double(0.)));
    CHECK_THROWS(probe("  -1.   "));
  }

  SECTION("'        '") {
    probe("        ");
    CHECK(probe.value == 0.);
  }


  SECTION("'   123.  '") {
    probe("   123.  ");
    CHECK(probe.value == 123.);
  }

  // SECTION("'  123+3  '") {
  //   probe("  123+3        ");
  //   CHECK(probe.value == 123000.);
  // }

    // def test_List1(self):
    //     obj = bdf_types.List('dummy', maxelem=6, minval=1, maxval=6, uniq=True)
    //     assert obj("1236") == (1, 2, 3, 6)

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
