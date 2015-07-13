// Copyright © 2015 by DNV GL SE

// Purpose: Testing the bdf_list class.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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
#include <deque>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp fil
#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;

TEST_CASE("BDF list types parsing.", "[bdf_types]" ) {

  // def test_List1(self):
    //     obj = bdf_types.List('dummy', maxelem=6, minval=1, maxval=6, uniq=True)
    //     assert obj("1236") == (1, 2, 3, 6)
  bdf_list<int> probe("dummy");

  SECTION("' 1234   '") {

    deque<int> ref;
    ref.push_back(1);
    ref.push_back(2);
    ref.push_back(3);
    ref.push_back(4);
    CHECK(*probe.parse("  1234  ") == ref);
  }

  SECTION("' 1236   '") {
    deque<int> ref;
    ref.push_back(1);
    ref.push_back(2);
    ref.push_back(3);
    ref.push_back(6);
    CHECK(*probe.parse(" 1236   ") == ref);
  }

  SECTION("' 1a3b   '") {
    CHECK_THROWS(probe.parse(" 1a3b   "));
  }
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check"
// End:
