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

  //        12345678901e3456
  SECTION("' 0.00000000E+000'") {
    CHECK(probe(" 0.00000000E+000") == 0.);
  }

  //        12345678901e3456
  SECTION("' 1.00000000E+01 '") {
    //            12345678901e3456
    CHECK(probe(" 1.00000000E+00 ") == 1.);
  }

  //        12345678901e3456
  SECTION("' 1.00000000e+01 '") {
    //            12345678901e3456
    CHECK(probe(" 1.00000000e+00 ") == 1.);
  }

  //        12345678901e3456
  SECTION("'+1.00000000E+00 '") {
    //            12345678901e3456
    CHECK(probe("+1.00000000E+00 ") == 1.);
  }

  //        12345678901e3456
  SECTION("'+1.00000000e+00'") {
    //            12345678901e3456
    CHECK(probe("+1.00000000e+00 ") == 1.);
  }

  //        12345678901e3456
  SECTION("' 1.00000000e+00 '") {
    //            12345678901e3456
    CHECK(probe("+1.00000000e+00 ") == 1.);
  }

  //        12345678901e3456
  SECTION("' 1.00000000e-01 '") {
    //            12345678901e3456
    CHECK(probe("+1.00000000e-01 ") == .1);
  }

  //        12345678901e3456
  SECTION("'-1.00000000e+00 '") {
    //            12345678901e3456
    CHECK(probe("-1.00000000e+00 ") == -1.);
  }

  //        12345678901e3456
  SECTION("'-1.00000000e-01 '") {
    //            12345678901e3456
    CHECK(probe("-1.00000000e-01 ") == -.1);
  }

  SECTION("'-1.00000000e-01 ', min 0.") {
    entry_type<double> probe("dummy", bound<double>(new double(0.), NULL, new double(0.)));
    CHECK_THROWS(probe(" -1.00000000e-01 "));
  }

  SECTION("Quick Reference") {
    ::std::vector<::std::string> samples;
    //            12345678901e3456
    CHECK(probe(" 7.00000000e+00 ") == 7.);
    CHECK(probe(" 7.00000000E+00 ") == 7.);
    CHECK(probe(" 7.00000000E-01 ") == .7);
    CHECK(probe("-7.00000000E-01 ") == -.7);
    CHECK(probe(" 7.00000000E+01 ") == 70.);
  }

  SECTION("'                '") {
    CHECK_THROWS(probe("                "));
  }

  SECTION("'                ', no default") {
    entry_type<double> probe("dummy", bound<double>(NULL, NULL, NULL));
    CHECK_THROWS(probe("                "));
  }

  //        12345678901e3456
  SECTION("' 1.23000000e+02 '") {
    CHECK(probe(" 1.23000000e+02 ") == 123.);
  }

  //        12345678901e3456
  SECTION("' 1.23000000e-01 '") {
    CHECK(probe(" 1.23000000e-01 ") == .123);
  }

  //        12345678901e3456
  SECTION("' 7.36831000E-01 '") {
    CHECK(probe(" 7.36831000E-01 ") ==  0.736831);
  }

  //        12345678901e3456
  SECTION("' 1.23000000e-001'") {
    CHECK(probe(" 1.23000000e-001") == .123);
  }

  //        12345678901e3456
  SECTION("' 7.36831000E-001'") {
    CHECK(probe(" 7.36831000E-001") == 0.736831);
  }

  SECTION("'        '") {
    entry_type<double> probe(
      "probe", bound<double>(nullptr, nullptr, nullptr, true));
    CHECK_THROWS(probe("        "));
  }
}

TEST_CASE("FEM double types output.", "[fem_types]" ) {

  entry_type<double> obj("dummy");

  double lval(1.);

  SECTION("Output") {
    std::string res(obj.format(lval));
    CHECK(obj.format(lval).size() == 16);
    //                         12345678901e3456
    CHECK(obj.format(lval) == "+1.00000000e+00 ");
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
