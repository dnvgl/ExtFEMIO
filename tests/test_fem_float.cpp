// Copyright © 2015 by DNV GL SE

// Task      Tests for FEM float types.

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

#include "extfem_misc.h"
#include "fem/types.h"
#include "fem/errors.h"

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::types;
using namespace ::dnvgl::extfem::fem::type_bounds;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
  return Catch::toString( ex() );
}

TEST_CASE("FEM float types parsing.", "[fem_types]" ) {

  entry_type<double> probe("dummy", bound<double>(NULL, NULL, make_unique<double>(0.).get()));

  SECTION("'       1.       '") {
    CHECK(*probe("       1.       ") == 1.);
  }

  SECTION("'      .1        '") {
    CHECK(*probe("      .1        ") == .1);
  }

  SECTION("'      -1.       '") {
    CHECK(*probe("      -1.       ") == -1.);
  }

  SECTION("'      -.1       '") {
    CHECK(*probe("      -.1       ") == -.1);
  }

  SECTION("'      -1.       ', min 0.") {
    entry_type<double> probe("dummy", bound<double>(new double(0.), NULL, new double(0.)));
    CHECK_THROWS(*probe("      -1.       "));
  }

  SECTION("Quick Reference") {
    ::std::vector<::std::string> samples;
    CHECK(*probe("           7.0  ") == 7.);
    CHECK(*probe("           7.   ") == 7.);
    CHECK(*probe("           .7   ") == .7);
    CHECK(*probe("           .7E1 ") == 7.);
    CHECK(*probe("           .7e1 ") == 7.);
    CHECK(*probe("           7.E+0") == 7.);
    CHECK(*probe("           7.e+0") == 7.);
    CHECK(*probe("          -7.0  ") == -7.);
    CHECK(*probe("          -7.   ") == -7.);
    CHECK(*probe("          -.7   ") == -.7);
    CHECK(*probe("          -.7E1 ") == -7.);
    CHECK(*probe("          -.7e1 ") == -7.);
    CHECK(*probe("          -7.E+0") == -7.);
    CHECK(*probe("          -7.e+0") == -7.);
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

  SECTION("'                '") {
    CHECK(*probe("                ") == 0.);
  }

  SECTION("'                ', no default") {
    entry_type<double> probe("dummy", bound<double>(NULL, NULL, NULL));
    CHECK_THROWS(*probe("                "));
  }

  SECTION("'   123.  '") {
    CHECK(*probe("   123.  ") == 123.);
  }

  SECTION("'       .123      '") {
    CHECK(*probe("       .123      ") == .123);
  }

  SECTION("' .736831        '") {
    CHECK(*probe(" .736831        ") ==  0.736831);
  }

  SECTION("'        '") {
    entry_type<double> probe(
      "probe", bound<double>(nullptr, nullptr, nullptr, true));
    CHECK_FALSE(probe("        "));
  }
}

TEST_CASE("FEM double types output.", "[fem_types]" ) {

  entry_type<double> obj("dummy");

  std::unique_ptr<double> lval = std::make_unique<double>(1.);

  SECTION("Output") {
    std::string res(obj.format(lval));
    CHECK(obj.format(lval).size() == 16);
    CHECK(obj.format(lval) == "1.0000000000e+00");
  }

  SECTION("Outout (nullptr)") {
    CHECK(obj.format((unique_ptr<double>)nullptr).size() == 16);
    CHECK(obj.format((unique_ptr<double>)nullptr) == "                ");
  }

  SECTION("Output (void)") {
    double *lval = new double(1.);
    CHECK(*lval == 1.);
    CHECK(obj.format(lval).size() == 16);
    CHECK(obj.format(lval) == "1.0000000000e+00");
    delete lval;
  }

  SECTION("Output (nullptr, void)") {
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
