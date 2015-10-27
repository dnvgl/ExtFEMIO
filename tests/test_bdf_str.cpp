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

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <set>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/types.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

using namespace bdf;
using namespace bdf::types;

TEST_CASE("BDF str types parsing.", "[bdf_types]" ) {

  const char* _allowed[3] = { "ONE", "TWO", "THREE" };
  const ::std::set<::std::string> allowed(_allowed, _allowed+3);
  ::bdf::type_bounds::bound<::std::string> str_allowed(allowed);
  ::bdf::type_bounds::bound<::std::string> str_allowed_default(allowed, "ONE");

  SECTION("'TEST    '") {
    entry_type<::std::string> obj("dummy");
    CHECK(*obj("TEST    ") == ::std::string("TEST"));
  }

  SECTION("'ONE     '") {
    entry_type<::std::string> obj("dummy", str_allowed);
    CHECK(*obj("ONE     ") == "ONE");
  }

  SECTION("'FOUR        '") {
    entry_type<::std::string> obj("dummy", str_allowed);
    CHECK_THROWS(*obj("FOUR    "));
  }

  SECTION("'            '") {
    entry_type<::std::string> obj("dummy", str_allowed);
    CHECK_THROWS(*obj("        "));
  }

  SECTION("'            ', 1") {
    entry_type<::std::string> obj("dummy", str_allowed_default);
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
