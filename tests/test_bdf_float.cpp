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

#include "bdf/types.h"
#include "bdf/errors.h"

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::types;
using namespace ::dnvgl::extfem::bdf::type_bounds;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
  return Catch::toString( ex() );
}

TEST_CASE("BDF float types parsing.", "[bdf_types]" ) {

  entry_type<double> probe("dummy", bound<double>(NULL, NULL, make_unique<double>(0.).get()));

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
    entry_type<double> probe("dummy", bound<double>(new double(0.), NULL, new double(0.)));
    CHECK_THROWS(*probe("  -1.   "));
  }

  SECTION("Quick Reference") {
    ::std::vector<::std::string> samples;
    CHECK(*probe("   7.0  ") == 7.);
    CHECK(*probe("   7.   ") == 7.);
    CHECK(*probe("   .7   ") == .7);
    CHECK(*probe("   .7E1 ") == 7.);
    CHECK(*probe("   .7e1 ") == 7.);
    CHECK(*probe("   0.7+1") == 7.);
    CHECK(*probe("   .70+1") == 7.);
    CHECK(*probe("   7.E+0") == 7.);
    CHECK(*probe("   7.e+0") == 7.);
    CHECK(*probe("   70.-1") == 7.);
    CHECK(*probe("  -7.0  ") == -7.);
    CHECK(*probe("  -7.   ") == -7.);
    CHECK(*probe("  -.7   ") == -.7);
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
    entry_type<double> probe("dummy", bound<double>(NULL, NULL, NULL));
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
      "probe", bound<double>(nullptr, nullptr, nullptr, true));
    CHECK_FALSE(probe("        "));
  }
}

TEST_CASE("BDF double types output.", "[bdf_types]" ) {

  entry_type<double> obj("dummy");

  std::unique_ptr<double> lval = std::make_unique<double>(1.);

  SECTION("SHORT") {
    bdf::types::base::out_form = bdf::types::SHORT;
    std::string res(obj.format(lval));
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "1.000+00");
  }

  SECTION("SHORT (nullptr)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format((unique_ptr<double>)nullptr).size() == 8);
    CHECK(obj.format((unique_ptr<double>)nullptr) == "        ");
  }

  SECTION("SHORT (void)") {
    double *lval = new double(1.);
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(*lval == 1.);
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "1.000+00");
    *lval = 2.9;
    CHECK(obj.format(lval) == "2.900+00");
    *lval = 1.9;
    CHECK(obj.format(lval) == "1.900+00");
    *lval = 0.;
    CHECK(obj.format(lval) == "0.000+00");
    delete lval;
  }

  SECTION("SHORT (nullptr, void)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format(nullptr).size() == 8);
    CHECK(obj.format(nullptr) == "        ");
  }

  SECTION("SHORT (inexact)") {
    double* lval = new double(1234.5);
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.05;
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.005;
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.0005;
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.00005;
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.000005;
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "1.234+03");
    *lval = 1234.01;
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.001;
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.0001;
    CHECK_THROWS(obj.format(lval));
    *lval = 1234.00001;
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "1.234+03");
    *lval = 1233.9;
    CHECK_THROWS(obj.format(lval));
    *lval = 1233.99;
    CHECK_THROWS(obj.format(lval));
    *lval = 1233.999;
    CHECK_THROWS(obj.format(lval));
    *lval = 1233.9999;
    CHECK_THROWS(obj.format(lval));
    *lval = 1233.99999;
    CHECK(obj.format(lval).size() == 8);
    CHECK(obj.format(lval) == "1.234+03");
    delete lval;
  }

  SECTION("LONG") {
    bdf::types::base::out_form = bdf::types::LONG;
    CHECK(obj.format(lval).size() == 16);
    CHECK(obj.format(lval) == "1.00000000000+00");
  }

  SECTION("FREE") {
    bdf::types::base::out_form = bdf::types::FREE;
    CHECK(obj.format(lval) == "1.000000+00");
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
