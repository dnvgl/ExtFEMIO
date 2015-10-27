// Copyright © 2015 by DNV GL SE

// Task      Testing the BDF boundary classes.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/types.h"

#include <memory>

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

using namespace std;
using namespace bdf::type_bounds;

TEST_CASE("BDF boundary definitions (long).", "[bdf_bounds]" ) {

  ::std::unique_ptr< ::bdf::type_bounds::bound< long > > probe =
    make_unique<::bdf::type_bounds::bound<long> >();
  ::std::unique_ptr< ::bdf::type_bounds::bound< long > > probe_min =
      make_unique<::bdf::type_bounds::bound<long> >(make_unique<long>(-12).get(), (long*)NULL, (long*)NULL);
  ::std::unique_ptr< ::bdf::type_bounds::bound< long > > probe_max =
      make_unique<::bdf::type_bounds::bound<long>>((long*)NULL, make_unique<long>(12).get(), (long*)NULL);
  ::std::unique_ptr< ::bdf::type_bounds::bound< long > > probe_mm =
      make_unique<::bdf::type_bounds::bound<long> >(make_unique<long>(-12).get(),
                              make_unique<long>(12).get(), (long*)NULL);
  ::std::unique_ptr< ::bdf::type_bounds::bound< long > > probe_mmd =
      make_unique<::bdf::type_bounds::bound<long> >(make_unique<long>(-12).get(),
                              make_unique<long>(12).get(),
                              make_unique<long>(6).get());
  ::std::unique_ptr< ::bdf::type_bounds::bound< long > > probe_def =
      make_unique<::bdf::type_bounds::bound<long> >((long*)NULL, (long*)NULL,
                              make_unique<long>(1).get());

  SECTION("<nothing>") {
    CHECK_FALSE(probe->has_default());
    unique_ptr< long > val(new long(numeric_limits<long>::min()));
    CHECK(probe->in_bounds(val.get()));
    val = make_unique<long>(0);
    CHECK(probe->in_bounds(val.get()));
    val = make_unique<long>(numeric_limits<long>::max());
    CHECK(probe->in_bounds(val.get()));
  }

  SECTION("min") {
    CHECK_FALSE(probe_min->has_default());
    unique_ptr<long> val(new long(numeric_limits<long>::min()));
    CHECK_FALSE(probe_min->in_bounds(val.get()));
    val = make_unique<long>(-12);
    CHECK(probe_min->in_bounds(val.get()));
    val = make_unique<long>(0);
    CHECK(probe_min->in_bounds(val.get()));
    val = make_unique<long>(numeric_limits<long>::max());
    CHECK(probe_min->in_bounds(val.get()));
  }

  SECTION("min class") {
    CHECK_FALSE(probe_min->has_default());
    unique_ptr<long> val(new long(numeric_limits<long>::min()));
    CHECK_FALSE(probe_min->in_bounds(val.get()));
    val = make_unique<long>(-12);
    CHECK(probe_min->in_bounds(val.get()));
    val = make_unique<long>(0);
    CHECK(probe_min->in_bounds(val.get()));
    val = make_unique<long>(numeric_limits<long>::max());
    CHECK(probe_min->in_bounds(val.get()));
  }

  SECTION("max") {
    CHECK_FALSE(probe_max->has_default());
    unique_ptr<long> val(new long(numeric_limits<long>::max()));
    CHECK_FALSE(probe_max->in_bounds(val.get()));
    val = make_unique<long>(12);
    CHECK(probe_max->in_bounds(val.get()));
    val = make_unique<long>(0);
    CHECK(probe_max->in_bounds(val.get()));
    val = make_unique<long>(numeric_limits<long>::min());
    CHECK(probe_max->in_bounds(val.get()));
  }

  SECTION("max class") {
    CHECK_FALSE(probe_max->has_default());
    unique_ptr<long> val(new long(numeric_limits<long>::max()));
    CHECK_FALSE(probe_max->in_bounds(val.get()));
    val = make_unique<long>(12);
    CHECK(probe_max->in_bounds(val.get()));
    val = make_unique<long>(0);
    CHECK(probe_max->in_bounds(val.get()));
    val = make_unique<long>(numeric_limits<long>::min());
    CHECK(probe_max->in_bounds(val.get()));
  }

  SECTION("min_max 1") {
    CHECK_FALSE(probe_mm->has_default());
    unique_ptr<long> val = make_unique<long>(
      numeric_limits<long>::min());
    CHECK_FALSE(probe_mm->in_bounds(val.get()));
    val = make_unique<long>(-12);
    CHECK(probe_mm->in_bounds(val.get()));
    val = make_unique<long>(0);
    CHECK(probe_mm->in_bounds(val.get()));
    val = make_unique<long>(12);
    CHECK(probe_mm->in_bounds(val.get()));
    val = make_unique<long>(numeric_limits<long>::max());
    CHECK_FALSE(probe_mm->in_bounds(val.get()));
  }

  SECTION("min_max 2") {
    CHECK(probe_mmd->has_default());
    CHECK(probe_mmd->get_default() == 6);
    unique_ptr<long> val(new long(numeric_limits<long>::min()));
    CHECK_FALSE(probe_mmd->in_bounds(val.get()));
    val = make_unique<long>(-12);
    CHECK(probe_mm->in_bounds(val.get()));
    val = make_unique<long>(0);
    CHECK(probe_mmd->in_bounds(val.get()));
    val = make_unique<long>(12);
    CHECK(probe_mm->in_bounds(val.get()));
    val = make_unique<long>(numeric_limits<long>::max());
    CHECK_FALSE(probe_mmd->in_bounds(val.get()));
  }

  SECTION("<nothing> (with default)") {
    CHECK(probe_def->has_default());
    CHECK(probe_def->get_default() == 1);
  }
}

TEST_CASE("BDF boundary definitions (double).", "[bdf_bounds]" ) {

  ::bdf::type_bounds::bound<double> *probe = new ::bdf::type_bounds::bound<double>();
  ::bdf::type_bounds::bound<double> *probe_def = new ::bdf::type_bounds::bound<double>(nullptr, nullptr, new double(1.));

  SECTION("<nothing>") {
    CHECK_FALSE(probe->has_default());
  }

  SECTION("<nothing> (with default)") {
    CHECK(probe_def->has_default());
    CHECK(probe_def->get_default() == 1.);
  }
}

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 8"
  coding: utf-8
  End:
*/
