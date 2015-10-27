// Copyright © 2015 by DNV GL SE

// Task      Testing the BDF GRID cards classes.

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

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/cards.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return Catch::toString( ex() );
}

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF GRID definitions. (Small Field Format)",
          "[bdf_grid]" ) {

  ::std::deque<string> data;
  data.push_back(
    "GRID           1      22111525. 18000.  21000.        11       6       2\n");

  ::std::deque<string> lines = card::card_split(data);
  grid probe(lines);

  SECTION("first grid") {
    CHECK(*probe.ID == 1);
    CHECK(*probe.CP == 22);
    CHECK(*probe.X1 == 111525.);
    CHECK(*probe.X2 == 18000.);
    CHECK(*probe.X3 == 21000.);
    CHECK(*probe.CD == 11);
    deque<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(*probe.PS == ps_ref);
    CHECK(*probe.SEID == 2);
  }
}

TEST_CASE("BDF GRID definitions. (Large Field Format)",
          "[bdf_grid]" ) {

  ::std::deque<string> data;
  data.push_back(
    "GRID*                  1              22         111525.          18000.\n");
  data.push_back(
    "                  21000.              11               6               2\n");

  ::std::deque<string> lines = card::card_split(data);
  grid probe(lines);

  SECTION("first grid") {
    CHECK(*probe.ID == 1);
    CHECK(*probe.CP == 22);
    CHECK(*probe.X1 == 111525.);
    CHECK(*probe.X2 == 18000.);
    CHECK(*probe.X3 == 21000.);
    CHECK(*probe.CD == 11);
    deque<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(*probe.PS == ps_ref);
    CHECK(*probe.SEID == 2);
  }
}

TEST_CASE("BDF GRID definitions. (Free Field Format)",
          "[bdf_grid]" ) {

  ::std::deque<string> data;
  SECTION("first grid") {
    data.empty();
    data.push_back("GRID,1,22,111525.,18000.,21000.,11,6,2\n");

    ::std::deque<string> lines = card::card_split(data);
    grid probe(lines);

    CHECK(*probe.ID == 1);
    CHECK(*probe.CP == 22);
    CHECK(*probe.X1 == 111525.);
    CHECK(*probe.X2 == 18000.);
    CHECK(*probe.X3 == 21000.);
    CHECK(*probe.CD == 11);
    deque<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(*probe.PS == ps_ref);
    CHECK(*probe.SEID == 2);
  }

  SECTION("first grid (cont)") {
    data.empty();
    data.push_back("GRID,1,22,111525.,\n");
    data.push_back(",18000.,21000.,11,6,2\n");

    ::std::deque<string> lines = card::card_split(data);
    grid probe(lines);

    CHECK(*probe.ID == 1);
    CHECK(*probe.CP == 22);
    CHECK(*probe.X1 == 111525.);
    CHECK(*probe.X2 == 18000.);
    CHECK(*probe.X3 == 21000.);
    CHECK(*probe.CD == 11);
    deque<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(*probe.PS == ps_ref);
    CHECK(*probe.SEID == 2);
  }

  SECTION("first grid (cont+)") {
    data.empty();
    data.push_back("GRID,1,22,111525.,+");
    data.push_back("+,18000.,21000.,11,6,2\n");

    ::std::deque<string> lines = card::card_split(data);
    grid probe(lines);

    CHECK(*probe.ID == 1);
    CHECK(*probe.CP == 22);
    CHECK(*probe.X1 == 111525.);
    CHECK(*probe.X2 == 18000.);
    CHECK(*probe.X3 == 21000.);
    CHECK(*probe.CD == 11);
    deque<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(*probe.PS == ps_ref);
    CHECK(*probe.SEID == 2);
  }

  SECTION("first grid (cont named +)") {
    data.empty();
    data.push_back("GRID,1,22,111525.,+G001\n");
    data.push_back("+G001,18000.,21000.,11,6,2\n");

    ::std::deque<string> lines = card::card_split(data);
    grid probe(lines);

    CHECK(*probe.ID == 1);
    CHECK(*probe.CP == 22);
    CHECK(*probe.X1 == 111525.);
    CHECK(*probe.X2 == 18000.);
    CHECK(*probe.X3 == 21000.);
    CHECK(*probe.CD == 11);
    deque<int> ps_ref;
    ps_ref.push_back(6);
    CHECK(*probe.PS == ps_ref);
    CHECK(*probe.SEID == 2);
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
