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
      executive_control::sol probe(101);
      test << probe;
      CHECK(test.str() == "SOL 101\n");
   }

   SECTION("sol sol::SESTATIC") {
      executive_control::sol probe(executive_control::sol::SESTATIC);
      test << probe;
      CHECK(test.str() == "SOL 101\n");
   }
}

TEST_CASE("BDF generate 'CEND' header entries", "[bdf_header,cend]") {

   std::ostringstream test;

   SECTION("cend") {
      executive_control::cend probe;
      test << probe;
      CHECK(test.str() == "CEND\n");
   }
}

TEST_CASE("BDF generate 'TITLE' header entries", "[bdf_header,title]") {

   std::ostringstream test;

   SECTION("") {
      case_control::title probe("text");
      test << probe;
      CHECK(test.str() == "TITLE = text\n");
   }
}

TEST_CASE("BDF generate 'ECHO' header entries", "[bdf_header,echo]") {

   std::ostringstream test;

   SECTION("default") {
      case_control::echo probe;
      test << probe;
      CHECK(test.str() == "ECHO = NONE\n");
   }

   SECTION("NONE") {
      case_control::echo probe({new case_control::echo::none});
      test << probe;
      CHECK(test.str() == "ECHO = NONE\n");
   }
   SECTION("BOTH") {
      case_control::echo probe({new case_control::echo::both});
      test << probe;
      CHECK(test.str() == "ECHO = BOTH\n");
   }
}

TEST_CASE("BDF generate 'BEGIN BULK' header entries", "[bdf_header,begin bulk]") {

   std::ostringstream test;

   SECTION("1") {
      case_control::begin_bulk probe;
      test << probe;
      CHECK(test.str() == ("BEGIN BULK\n"));
   }
}

TEST_CASE("BDF generate 'SUBCASE' header entries", "[bdf_header,subcase]") {

   std::ostringstream test;

   SECTION("1") {
      case_control::subcase probe(1);
      test << probe;
      CHECK(test.str() == ("SUBCASE = 1\n"));
   }

   SECTION("Title") {
      case_control::subcase probe;
      test << probe;
      CHECK(test.str() == ("SUBCASE = 2\n"));
   }
}

TEST_CASE("BDF generate 'SUBTITLE' header entries", "[bdf_header,subtitle]") {

   std::ostringstream test;

   SECTION("1") {
      case_control::subtitle probe("LC 1");
      test << probe;
      CHECK(test.str() == "SUBTITLE = LC 1\n");
   }
}

TEST_CASE("BDF generate 'LOAD' header entries", "[bdf_header,load]") {

   std::ostringstream test;

   SECTION("1") {
      case_control::load probe(1);
      test << probe;
      CHECK(test.str() == "LOAD = 1\n");
   }

   SECTION("15") {
      case_control::load probe(15);
      test << probe;
      CHECK(test.str() == "LOAD = 15\n");
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
