// Copyright © 2015 by DNV GL SE

/*
  Purpose: Tests for string helper functions.

  Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
*/

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/string.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

TEST_CASE("Checking extra string functions", "[bdf_string]") {

  SECTION("checking trim functionality") {
    CHECK(::bdf::string::string("   2    ").trim() == "2");
    CHECK(::bdf::string::string("        ").trim() == "");
    CHECK(::bdf::string::string(" \t      ").trim() == "");
    CHECK(::bdf::string::string(" \txxx\t ").trim() == "xxx");
    CHECK(::bdf::string::string(" \tXXX\t ").trim() == "XXX");
    CHECK(::bdf::string::string("ABCDabcd").trim() == "ABCDabcd");
  }

  SECTION("checking lower functionality") {
    CHECK(::bdf::string::string("   2     ").lower() == "   2     ");
    CHECK(::bdf::string::string("         ").lower() == "         ");
    CHECK(::bdf::string::string(" \t      ").lower() == " \t      ");
    CHECK(::bdf::string::string(" \txxx\t ").lower() == " \txxx\t ");
    CHECK(::bdf::string::string(" \tXXX\t ").lower() == " \txxx\t ");
    CHECK(::bdf::string::string("ABCDabcd ").lower() == "abcdabcd ");
  }

  SECTION("checking upper functionality") {
    CHECK(::bdf::string::string("   2     ").upper() == "   2     ");
    CHECK(::bdf::string::string("         ").upper() == "         ");
    CHECK(::bdf::string::string(" \t      ").upper() == " \t      ");
    CHECK(::bdf::string::string(" \txxx\t ").upper() == " \tXXX\t ");
    CHECK(::bdf::string::string(" \tXXX\t ").upper() == " \tXXX\t ");
    CHECK(::bdf::string::string("ABCDabcd ").upper() == "ABCDABCD ");
  }

}

/*
  Local Variables:
  mode: c++
  coding: utf-8
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 8"
  End:
*/
