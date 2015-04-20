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

#include <limits>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

TEST_CASE("BDF boundary definitions (long).", "[bdf_bounds]" ) {

  ::bdf_type_bounds::bdf_num_bounds<long> *probe = new ::bdf_type_bounds::bdf_num_bounds<long>();
  ::bdf_type_bounds::bdf_num_bounds<long> *probe_m = new ::bdf_type_bounds::bdf_num_bounds<long>(-12);
  ::bdf_type_bounds::bdf_num_bounds<long> *probe_mm = new ::bdf_type_bounds::bdf_num_bounds<long>(-12, 12);
  ::bdf_type_bounds::bdf_num_bounds<long> *probe_mmd = new ::bdf_type_bounds::bdf_num_bounds<long>(-12, 12, 6);
  ::bdf_type_bounds::bdf_num_default<long> *probe_def = new ::bdf_type_bounds::bdf_num_default<long>(1);
  ::bdf_type_bounds::bdf_num_bounds<long> *probe_min = new ::bdf_type_bounds::bdf_num_bounds_min<long>(-12);

  SECTION("<nothing>") {
    CHECK_FALSE(probe->has_default());
    CHECK(probe->in_bounds(std::numeric_limits<long>::min()));
    CHECK(probe->in_bounds(0));
    CHECK(probe->in_bounds(std::numeric_limits<long>::max()));
  }

  SECTION("min") {
    CHECK_FALSE(probe_m->has_default());
    CHECK_FALSE(probe_m->in_bounds(std::numeric_limits<long>::min()));
    CHECK(probe_m->in_bounds(-12));
    CHECK(probe_m->in_bounds(0));
    CHECK(probe_m->in_bounds(std::numeric_limits<long>::max()));
  }

  SECTION("min class") {
    CHECK_FALSE(probe_min->has_default());
    CHECK_FALSE(probe_min->in_bounds(std::numeric_limits<long>::min()));
    CHECK(probe_m->in_bounds(-12));
    CHECK(probe_m->in_bounds(0));
    CHECK(probe_m->in_bounds(std::numeric_limits<long>::max()));
  }

  SECTION("min_max") {
    CHECK_FALSE(probe_mm->has_default());
    CHECK_FALSE(probe_mm->in_bounds(std::numeric_limits<long>::min()));
    CHECK(probe_mm->in_bounds(-12));
    CHECK(probe_mm->in_bounds(0));
    CHECK(probe_mm->in_bounds(12));
    CHECK_FALSE(probe_mm->in_bounds(std::numeric_limits<long>::max()));
  }

  SECTION("min_max") {
    CHECK(probe_mmd->has_default());
        CHECK(probe_mmd->get_default() == 6);
    CHECK_FALSE(probe_mmd->in_bounds(std::numeric_limits<long>::min()));
    CHECK(probe_mm->in_bounds(-12));
    CHECK(probe_mmd->in_bounds(0));
    CHECK(probe_mm->in_bounds(12));
    CHECK_FALSE(probe_mmd->in_bounds(std::numeric_limits<long>::max()));
  }

  SECTION("<nothing> (with default)") {
    CHECK(probe_def->has_default());
    CHECK(probe_def->get_default() == 1);
  }
}

TEST_CASE("BDF boundary definitions (double).", "[bdf_bounds]" ) {

  ::bdf_type_bounds::bdf_num_bounds<double> *probe = new ::bdf_type_bounds::bdf_num_bounds<double>();
  ::bdf_type_bounds::bdf_num_default<double> *probe_def = new ::bdf_type_bounds::bdf_num_default<double>(1.);

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
  compile-command: "make -C .. check"
  coding: utf-8
  End:
*/
