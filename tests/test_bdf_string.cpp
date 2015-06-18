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
    CHECK(::bdf_string::string::trim("   2    ") == std::string("2"));
    CHECK(::bdf_string::string::trim("        ") == std::string(""));
    CHECK(::bdf_string::string::trim(" \t      ") == std::string(""));
    CHECK(::bdf_string::string::trim(" \txxx\t ") == std::string("xxx"));
    CHECK(::bdf_string::string::trim(" \tXXX\t ") == std::string("XXX"));
    CHECK(::bdf_string::string::trim("ABCDabcd") == std::string("ABCDabcd"));
  }

  SECTION("checking lower functionality") {
    CHECK(::bdf_string::string::lower("   2     ") == std::string("   2     "));
    CHECK(::bdf_string::string::lower("         ") == std::string("         "));
    CHECK(::bdf_string::string::lower(" \t      ") == std::string(" \t      "));
    CHECK(::bdf_string::string::lower(" \txxx\t ") == std::string(" \txxx\t "));
    CHECK(::bdf_string::string::lower(" \tXXX\t ") == std::string(" \txxx\t "));
    CHECK(::bdf_string::string::lower("ABCDabcd ") == std::string("abcdabcd "));
  }

    SECTION("checking upper functionality") {
    CHECK(::bdf_string::string::upper("   2     ") == std::string("   2     "));
    CHECK(::bdf_string::string::upper("         ") == std::string("         "));
    CHECK(::bdf_string::string::upper(" \t      ") == std::string(" \t      "));
    CHECK(::bdf_string::string::upper(" \txxx\t ") == std::string(" \tXXX\t "));
    CHECK(::bdf_string::string::upper(" \tXXX\t ") == std::string(" \tXXX\t "));
    CHECK(::bdf_string::string::upper("ABCDabcd ") == std::string("ABCDABCD "));
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
