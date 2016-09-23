/**
   \file test_bdf_header_stress.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing of STRESS case control entry.

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

#include <iostream>
#include <deque>

#include <catch.hpp>

#include "config.h"

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

TEST_CASE("BDF generate 'STRESS' header entries", "[bdf_header,stress]") {

   std::ostringstream test;

   SECTION("default") {
      case_control::stress probe({});
      test << probe;
      CHECK(test.str() == "STRESS = NONE\n");
   }

   SECTION("first") {
      case_control::stress probe({}, case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS = ALL\n");
   }

   SECTION("5") {
      case_control::stress probe({}, 5);
      test << probe;
      CHECK(test.str() == "STRESS = 5\n");
   }

   SECTION("15") {
      case_control::stress probe({
            new case_control::stress::sort1,
            new case_control::stress::print,
            new case_control::stress::punch,
            new case_control::stress::phase}, 15);
      test << probe;
      CHECK(test.str() == "STRESS(SORT1, PRINT, PUNCH, PHASE) = 15\n");
   }

   SECTION("20") {
      case_control::stress probe({
            new case_control::stress::print,
            new case_control::stress::psdf,
            new case_control::stress::crms,
            new case_control::stress::rpunch},
         20);
      test << probe;
      CHECK(test.str() == "STRESS(PRINT, PSDF, CRMS, RPUNCH) = 20\n");
   }

   SECTION("RALL etc") {
      case_control::stress probe({
            new case_control::stress::print,
            new case_control::stress::rall,
            new case_control::stress::norprint},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(PRINT, RALL, NORPRINT) = ALL\n");
   }

   SECTION("SORT1") {
      case_control::stress probe({
            new case_control::stress::sort1},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(SORT1) = ALL\n");
   }

   SECTION("SORT2") {
      case_control::stress probe({
            new case_control::stress::sort2},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(SORT2) = ALL\n");
   }

   SECTION("PRINT") {
      case_control::stress probe({
            new case_control::stress::print},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(PRINT) = ALL\n");
   }

   SECTION("PUNCH") {
      case_control::stress probe({
            new case_control::stress::punch},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(PUNCH) = ALL\n");
   }

   SECTION("PLOT") {
      case_control::stress probe({
            new case_control::stress::plot},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(PLOT) = ALL\n");
   }

   SECTION("REAL") {
      case_control::stress probe({
            new case_control::stress::real},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(REAL) = ALL\n");
   }

   SECTION("IMAG") {
      case_control::stress probe({
            new case_control::stress::imag},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(IMAG) = ALL\n");
   }

   SECTION("PHASE") {
      case_control::stress probe({
            new case_control::stress::phase},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(PHASE) = ALL\n");
   }

   SECTION("PSDF") {
      case_control::stress probe({
            new case_control::stress::print,
               new case_control::stress::rall,
               new case_control::stress::norprint},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(PRINT, RALL, NORPRINT) = ALL\n");
   }

   SECTION("ATOC") {
      case_control::stress probe({
            new case_control::stress::atoc},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(ATOC) = ALL\n");
   }

   SECTION("CRMS") {
      case_control::stress probe({
            new case_control::stress::crms},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(CRMS) = ALL\n");
   }

   SECTION("RALL") {
      case_control::stress probe({
            new case_control::stress::rall},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(RALL) = ALL\n");
   }

   SECTION("VONMISES") {
      case_control::stress probe({
            new case_control::stress::vonmises},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(VONMISES) = ALL\n");
   }

   SECTION("MAXS") {
      case_control::stress probe({
            new case_control::stress::maxs},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(MAXS) = ALL\n");
   }

   SECTION("SHEAR") {
      case_control::stress probe({
            new case_control::stress::shear},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(SHEAR) = ALL\n");
   }

   SECTION("CENTER") {
      case_control::stress probe({
            new case_control::stress::center},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(CENTER) = ALL\n");
   }

   SECTION("CUBIC") {
      case_control::stress probe({
            new case_control::stress::cubic},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(CUBIC) = ALL\n");
   }

   SECTION("SGAGE") {
      case_control::stress probe({
            new case_control::stress::sgage},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(SGAGE) = ALL\n");
   }

   SECTION("CORNER") {
      case_control::stress probe({
            new case_control::stress::corner},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(CORNER) = ALL\n");
   }

   SECTION("BILIN") {
      case_control::stress probe({
            new case_control::stress::bilin},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(BILIN) = ALL\n");
   }

   SECTION("RPRINT") {
      case_control::stress probe({
            new case_control::stress::rprint},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(RPRINT) = ALL\n");
   }

   SECTION("NORPRINT") {
      case_control::stress probe({
            new case_control::stress::norprint},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(NORPRINT) = ALL\n");
   }

   SECTION("RPUNCH") {
      case_control::stress probe({
            new case_control::stress::rpunch},
         case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS(RPUNCH) = ALL\n");
   }

   SECTION("ALL") {
      case_control::stress probe({}, case_control::stress::restype::ALL);
      test << probe;
      CHECK(test.str() == "STRESS = ALL\n");
   }

   SECTION("n") {
      case_control::stress probe({}, 6);
      test << probe;
      CHECK(test.str() == "STRESS = 6\n");
   }

   SECTION("NONE") {
      case_control::stress probe({}, case_control::stress::restype::NONE);
      test << probe;
      CHECK(test.str() == "STRESS = NONE\n");
   }
}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
