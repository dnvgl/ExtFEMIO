/**
   \file tests/test_bdf_list.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF list class.

   Detailed description
*/

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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::types;
using namespace ::dnvgl::extfem::bdf::type_bounds;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return Catch::toString( ex() );
}

TEST_CASE("BDF list types parsing.", "[bdf_types]" ) {

   entry_type<std::deque<int>> probe("dummy");

   SECTION("' 1234   '") {
      deque<int> ref({ 1, 2, 3, 4 });
      CHECK(probe("  1234  ").value == ref);
   }

   SECTION("' 1236   '") {
      deque<int> ref({ 1, 2, 3, 6 });
      CHECK(probe(" 1236   ").value == ref);
   }

   SECTION("' 1a3b   '") {
      CHECK_THROWS(probe(" 1a3b   "));
   }
}

TEST_CASE("BDF list of int types output.", "[bdf_types]" ) {

   entry_type<std::deque<int>> obj("dummy");

   //std::deque<int> inp({ 1, 2, 3, 4 });
   entry_value<std::deque<int>> lval({ 1, 2, 3, 4 });

   std::ostringstream stream(std::ostringstream::ate);

   SECTION("SHORT") {
      bdf::types::base::out_form = bdf::types::SHORT;
      stream << obj.format(lval);
      CHECK(stream.str().size() == 8);
      CHECK(stream.str() == "    1234");
   }

   SECTION("SHORT (nullptr)") {
      bdf::types::base::out_form = bdf::types::SHORT;
      CHECK(obj.format(nullptr).size() == 8);
      CHECK(obj.format(nullptr) == "        ");
   }

   SECTION("SHORT (void)") {
      std::deque<int> llval(lval.value);
      bdf::types::base::out_form = bdf::types::SHORT;
      CHECK(obj.format(&llval).size() == 8);
      CHECK(obj.format(&llval) == "    1234");
   }

   SECTION("SHORT (nullptr)") {
      bdf::types::base::out_form = bdf::types::SHORT;
      CHECK(obj.format(nullptr).size() == 8);
      CHECK(obj.format(nullptr) == "        ");
   }

   SECTION("SHORT (too long)") {
      bdf::types::base::out_form = bdf::types::SHORT;
      lval.value.push_back(1);
      lval.value.push_back(2);
      lval.value.push_back(3);
      lval.value.push_back(4);
      lval.value.push_back(4);
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
