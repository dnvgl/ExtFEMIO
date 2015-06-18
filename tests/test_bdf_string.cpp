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

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp fil
#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_string.h"

TEST_CASE("Checking extra string functions", "[bdf_string]") {

  SECTION("checking trim functionality") {
    CHECK(::bdf_string::string("   2    ").trim() == std::string("2"));
    CHECK(::bdf_string::string("        ").trim() == std::string(""));
    CHECK(::bdf_string::string(" \t      ").trim() == std::string(""));
    CHECK(::bdf_string::string(" \txxx\t ").trim() == std::string("xxx"));
    CHECK(::bdf_string::string(" \tXXX\t ").trim() == std::string("XXX"));
    CHECK(::bdf_string::string("ABCDabcd").trim() == std::string("ABCDabcd"));
  }

  SECTION("checking lower functionality") {
    CHECK(::bdf_string::string("   2     ").lower() == std::string("   2     "));
    CHECK(::bdf_string::string("         ").lower() == std::string("         "));
    CHECK(::bdf_string::string(" \t      ").lower() == std::string(" \t      "));
    CHECK(::bdf_string::string(" \txxx\t ").lower() == std::string(" \txxx\t "));
    CHECK(::bdf_string::string(" \tXXX\t ").lower() == std::string(" \txxx\t "));
    CHECK(::bdf_string::string("ABCDabcd ").lower() == std::string("abcdabcd "));
  }

    SECTION("checking upper functionality") {
    CHECK(::bdf_string::string("   2     ").upper() == std::string("   2     "));
    CHECK(::bdf_string::string("         ").upper() == std::string("         "));
    CHECK(::bdf_string::string(" \t      ").upper() == std::string(" \t      "));
    CHECK(::bdf_string::string(" \txxx\t ").upper() == std::string(" \tXXX\t "));
    CHECK(::bdf_string::string(" \tXXX\t ").upper() == std::string(" \tXXX\t "));
    CHECK(::bdf_string::string("ABCDabcd ").upper() == std::string("ABCDABCD "));
  }

}

/*
  Local Variables:
  mode: c++
  coding: utf-8
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check"
  End:
*/
