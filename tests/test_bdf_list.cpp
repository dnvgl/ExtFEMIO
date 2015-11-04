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

TEST_CASE("BDF list types parsing.", "[bdf_types]" ) {

  // def test_List1(self):
    //     obj = bdf_types.List('dummy', maxelem=6, minval=1, maxval=6, uniq=True)
    //     assert obj("1236") == (1, 2, 3, 6)
  entry_type<std::deque<int>> probe("dummy");

  SECTION("' 1234   '") {

    deque<int> ref;
    ref.push_back(1);
    ref.push_back(2);
    ref.push_back(3);
    ref.push_back(4);
    CHECK(*probe("  1234  ") == ref);
  }

  SECTION("' 1236   '") {
    deque<int> ref;
    ref.push_back(1);
    ref.push_back(2);
    ref.push_back(3);
    ref.push_back(6);
    CHECK(*probe(" 1236   ") == ref);
  }

  SECTION("' 1a3b   '") {
    CHECK_THROWS(probe(" 1a3b   "));
  }
}

TEST_CASE("BDF list of int types output.", "[bdf_types]" ) {

  entry_type<std::deque<int>> obj("dummy");

  unique_ptr<std::deque<int>> lval = std::make_unique<std::deque<int>>();
  lval->push_back(1);
  lval->push_back(2);
  lval->push_back(3);
  lval->push_back(4);

  std::ostringstream stream(std::ostringstream::ate);

  SECTION("SHORT") {
    bdf::types::base::out_form = bdf::types::SHORT;
    stream << obj.format(lval);
    CHECK(stream.str().size() == 8);
    CHECK(stream.str() == "    1234");
  }

  SECTION("SHORT (nullptr)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format((unique_ptr<std::deque<int>>)nullptr).size() == 8);
    CHECK(obj.format((unique_ptr<std::deque<int>>)nullptr) == "        ");
  }

  SECTION("SHORT (void)") {
    std::deque<int> *llval = new std::deque<int>(
      lval->begin(), lval->end());
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format(llval).size() == 8);
    CHECK(obj.format(llval) == "    1234");
    delete llval;
  }

  SECTION("SHORT (nullptr)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    CHECK(obj.format(nullptr).size() == 8);
    CHECK(obj.format(nullptr) == "        ");
  }

  SECTION("SHORT (too long)") {
    bdf::types::base::out_form = bdf::types::SHORT;
    lval->push_back(1);
    lval->push_back(2);
    lval->push_back(3);
    lval->push_back(4);
    lval->push_back(4);
    CHECK_THROWS(obj.format(lval));
  }

  SECTION("LONG") {
    bdf::types::base::out_form = bdf::types::LONG;
    stream << obj.format(lval);
    CHECK(stream.str().size() == 16);
    CHECK(stream.str() == "            1234");
  }

  SECTION("FREE") {
    bdf::types::base::out_form = bdf::types::FREE;
    stream << obj.format(lval);
    CHECK(stream.str() == "1234");
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
