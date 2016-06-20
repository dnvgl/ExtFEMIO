/**
   \file tests/test_bdf_header.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for NASTRAN bulk data file headers.

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

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <iostream>
#include <deque>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif

#include "bdf/header.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::header;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return Catch::toString( ex() );
}

TEST_CASE("BDF generate 'SOL' header entries", "[bdf_header,sol]") {

   std::ostringstream test;

   SECTION("sol 101") {
      exec::sol probe(101);
      test << probe;
      CHECK(test.str() == "SOL 101\n");
   }

   SECTION("sol sol::SESTATIC") {
      exec::sol probe(exec::sol::SESTATIC);
      test << probe;
      CHECK(test.str() == "SOL 101\n");
   }
}

TEST_CASE("BDF generate 'CEND' header entries", "[bdf_header,cend]") {

   std::ostringstream test;

   SECTION("cend") {
      exec::cend probe;
      test << probe;
      CHECK(test.str() == "CEND\n");
   }
}

TEST_CASE("BDF generate 'TITLE' header entries", "[bdf_header,title]") {

   std::ostringstream test;

   SECTION("") {
      case_::title probe("text");
      test << probe;
      CHECK(test.str() == "TITLE=text\n");
   }
}

TEST_CASE("BDF generate 'ECHO' header entries", "[bdf_header,echo]") {

   std::ostringstream test;

   SECTION("default") {
      case_::echo probe;
      test << probe;
      CHECK(test.str() == "ECHO=NONE\n");
   }

   SECTION("NONE") {
      case_::echo probe("NONE");
      test << probe;
      CHECK(test.str() == "ECHO=NONE\n");
   }
   SECTION("BOTH") {
      case_::echo probe("BOTH");
      test << probe;
      CHECK(test.str() == "ECHO=BOTH\n");
   }
}

TEST_CASE("BDF generate 'SUBCASE' header entries", "[bdf_header,subcase]") {

   std::ostringstream test;

   SECTION("1") {
      case_::subcase probe(1);
      test << probe;
      CHECK(test.str() == "SUBCASE=1\n");
   }
}

// TEST_CASE("BDF generate '' header entries", "[bdf_header,]") {

//    std::ostringstream test;

//    SECTION("") {
//        probe();
//       test << probe;
//       CHECK(test.str() == "CEND\n");
//    }
// }

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
