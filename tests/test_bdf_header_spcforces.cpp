/**
   \file tests/test_bdf_header_spcforces.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Test of BDF SPCFORCES case control entries.

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

TEST_CASE("BDF generate 'SPCFORCES' header entries", "[bdf_header,spcforces]") {

   std::ostringstream test;

   SECTION("default") {
      case_control::spcforces probe({});
      test << probe;
      CHECK(test.str() == "SPCFORCES = NONE\n");
   }

   SECTION("first") {
      case_control::spcforces probe({}, case_control::spcforces::ALL);
      test << probe;
      CHECK(test.str() == "SPCFORCES = ALL\n");
   }

   SECTION("NOZPRINT") {
      case_control::spcforces probe({
            new case_control::spcforces::print,
            new case_control::spcforces::nozprint
         }, case_control::spcforces::ALL);
      test << probe;
      CHECK(test.str() == "SPCFORCES(PRINT, NOZPRINT) = ALL\n");
   }

   SECTION("num") {
      case_control::spcforces probe({}, 5);
      test << probe;
      CHECK(test.str() == "SPCFORCES = 5\n");
   }

   SECTION("IMAG") {
      case_control::spcforces probe({
               new case_control::spcforces::sort2,
               new case_control::spcforces::punch,
               new case_control::spcforces::print,
               new case_control::spcforces::imag
         }, case_control::spcforces::ALL);
      test << probe;
      CHECK(test.str() == "SPCFORCES(SORT2, PUNCH, PRINT, IMAG) = ALL\n");
   }

   SECTION("PHASE") {
      case_control::spcforces probe({
            new case_control::spcforces::phase
         }, case_control::spcforces::NONE);
      test << probe;
      CHECK(test.str() == "SPCFORCES(PHASE) = NONE\n");
   }

   SECTION("SORT2") {
      case_control::spcforces probe({
               new case_control::spcforces::sort2,
               new case_control::spcforces::print,
               new case_control::spcforces::psdf,
               new case_control::spcforces::crms,
               new case_control::spcforces::rpunch
         }, 20);
      test << probe;
      CHECK(test.str() == "SPCFORCES(SORT2, PRINT, PSDF, CRMS, RPUNCH) = 20\n");
   }

   SECTION("PRINT") {
      case_control::spcforces probe({
               new case_control::spcforces::print,
               new case_control::spcforces::rall,
               new case_control::spcforces::norprint
         }, case_control::spcforces::ALL);
      test << probe;
      CHECK(test.str() == "SPCFORCES(PRINT, RALL, NORPRINT) = ALL\n");
   }

}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
