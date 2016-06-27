/**
   \file tests/test_bdf_header_echo.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing BDF header ECHO entry

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

TEST_CASE("Testing cdni_entry", "bdf_header,echo,cdni_entry") {

   SECTION("first") {
      case_control::echo::sort::cdni_entry probe("ABC");
      CHECK(probe.str() == "ABC");
   }

   SECTION("pointer") {
      case_control::echo::sort::cdni_entry* probe;
      probe = new case_control::echo::sort::cdni_entry("ABC");
      CHECK(probe->str() == "ABC");
   }

   SECTION("except") {
      case_control::echo::sort::cdni_entry probe("ABC", true);
      CHECK(probe.str() == "EXCEPT ABC");
   }
}

TEST_CASE("BDF generate more 'ECHO' header entries", "[bdf_header,echo]") {

   std::ostringstream test;

   SECTION("ECHO = NONE") {
      case_control::echo probe({new case_control::echo::none()});
      test << probe;
      CHECK(test.str() == "ECHO = NONE\n");
   }

   SECTION("ECHO=NOSORT") {
      case_control::echo probe({new case_control::echo::unsort()});
      test << probe;
      CHECK(test.str() == "ECHO = UNSORT\n");
   }

   SECTION("ECHO=BOTH") {
      case_control::echo probe({new case_control::echo::both()});
      test << probe;
      CHECK(test.str() == "ECHO = BOTH\n");
   }

   SECTION("ECHO = PUNCH, SORT (MAT1, PARAM)") {
      case_control::echo probe(
         {new case_control::echo::punch(),
         new case_control::echo::sort(std::list<case_control::echo::sort::cdni_entry>(
             {case_control::echo::sort::cdni_entry("MAT1"),
              case_control::echo::sort::cdni_entry("PARAM")}))});
      test << probe;
      CHECK(test.str() == "ECHO = PUNCH, SORT(MAT1, PARAM)\n");
   }

   SECTION("ECHO = SORT (EXCEPT DMI, DMIG)") {
      case_control::echo probe(
      {new case_control::echo::sort(std::list<case_control::echo::sort::cdni_entry>(
             {case_control::echo::sort::cdni_entry("DMI", true),
              case_control::echo::sort::cdni_entry("DMIG")}))});
      test << probe;
      CHECK(test.str() == "ECHO = SORT(EXCEPT DMI, DMIG)\n");
   }

   SECTION("ECHO=BOTH,PUNCH,FILE") {
      case_control::echo probe(
         {new case_control::echo::both,
          new case_control::echo::punch,
          new case_control::echo::file});
      test << probe;
      CHECK(test.str() == "ECHO = BOTH, PUNCH, FILE\n");
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
