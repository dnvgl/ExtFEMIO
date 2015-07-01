// Copyright © 2015 by DNV GL SE

// Task      Testing the BDF GRID cards classes.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id: test_bdf_bounds.cpp 22 2015-04-28 16:06:04Z hoel $";
}

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>

#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_cards.h"

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF GRID definitions. (Small Field Format)", "[bdf_grid]" ) {

  ::std::vector<string> data;
  data.push_back("GRID           1      22111525. 18000.  21000.        11       6       2\n");

  grid probe(data);

  SECTION("first grid") {
    CHECK(probe.ID() == 1);
    CHECK(probe.CP() == 22);
    CHECK(probe.X1() == 111525.);
    CHECK(probe.X2() == 18000.);
    CHECK(probe.X3() == 21000.);
    CHECK(probe.CD() == 11);
    vector<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(probe.PS() == ps_ref);
    CHECK(probe.SEID() == 2);
  }
}

TEST_CASE("BDF GRID definitions. (Large Field Format)", "[bdf_grid]" ) {

  ::std::vector<string> data;
  data.push_back("GRID*                  1              22         111525.          18000.\n");
  data.push_back("                  21000.              11               6               2\n");

  grid probe(data);

  SECTION("first grid") {
    CHECK(probe.ID() == 1);
    CHECK(probe.CP() == 22);
    CHECK(probe.X1() == 111525.);
    CHECK(probe.X2() == 18000.);
    CHECK(probe.X3() == 21000.);
    CHECK(probe.CD() == 11);
    vector<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(probe.PS() == ps_ref);
    CHECK(probe.SEID() == 2);
  }
}

TEST_CASE("BDF GRID definitions. (Free Field Format)", "[bdf_grid]" ) {

  ::std::vector<string> data;
  data.push_back("GRID,1,22,111525.,18000.,21000.,11,6,2\n");

  SECTION("first grid") {
    CHECK_THROWS(grid probe(data));
    // CHECK(probe.ID() == 1);
    // CHECK(probe.CP() == 22);
    // CHECK(probe.X1() == 111525.);
    // CHECK(probe.X2() == 18000.);
    // CHECK(probe.X3() == 21000.);
    // CHECK(probe.CD() == 11);
    // vector<int> ps_ref;
    // ps_ref.push_back(6);
    // CHECK(probe.PS() == ps_ref);
    // CHECK(probe.SEID() == 2);
  }
}

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 7"
  coding: utf-8
  End:
*/
