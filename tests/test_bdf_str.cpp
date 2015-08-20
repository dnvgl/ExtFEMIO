// Copyright © 2015 by DNV GL SE

// Purpose: Tests for BDF str types.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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

#include <set>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

using namespace bdf;
using namespace bdf::types;

TEST_CASE("BDF str types parsing.", "[bdf_types]" ) {

  const char* _allowed[3] = { "ONE", "TWO", "THREE" };
  const ::std::set<::std::string> allowed(_allowed, _allowed+3);
  str str_allowed(allowed);
  str str_allowed_default(allowed, "ONE");

  SECTION("'TEST    '") {
    bdf_str obj("dummy");
    CHECK(*obj("TEST    ") == ::std::string("TEST"));
  }

  SECTION("'ONE     '") {
    bdf_str obj("dummy", str_allowed);
    CHECK(*obj("ONE     ") == "ONE");
  }

  SECTION("'FOUR        '") {
    bdf_str obj("dummy", str_allowed);
    CHECK_THROWS(*obj("FOUR    "));
  }

  SECTION("'            '") {
    bdf_str obj("dummy", str_allowed);
    CHECK_THROWS(*obj("        "));
  }

  SECTION("'            ', 1") {
    bdf_str obj("dummy", str_allowed_default);
    CHECK(*obj("        ") == "ONE");
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
