/**
   \file tests/test_extfem_string.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for string helper functions.

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

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "config.h"

#include "extfem_string.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl;

CATCH_TRANSLATE_EXCEPTION( extfem::bdf::errors::error& ex ) {
   return Catch::toString( ex.what() );
}

TEST_CASE("Checking extra string functions", "[extfem::string]") {

   SECTION("checking trim functionality") {
      CHECK(extfem::string::string("   2    ").trim() == "2");
      CHECK(extfem::string::string("        ").trim() == "");
      CHECK(extfem::string::string(" \t      ").trim() == "");
      CHECK(extfem::string::string(" \txxx\t ").trim() == "xxx");
      CHECK(extfem::string::string(" \tXXX\t ").trim() == "XXX");
      CHECK(extfem::string::string("ABCDabcd").trim() == "ABCDabcd");
   }

   SECTION("checking lower functionality") {
      CHECK(extfem::string::string("   2     ").lower() == "   2     ");
      CHECK(extfem::string::string("         ").lower() == "         ");
      CHECK(extfem::string::string(" \t      ").lower() == " \t      ");
      CHECK(extfem::string::string(" \txxx\t ").lower() == " \txxx\t ");
      CHECK(extfem::string::string(" \tXXX\t ").lower() == " \txxx\t ");
      CHECK(extfem::string::string("ABCDabcd ").lower() == "abcdabcd ");
   }

   SECTION("checking upper functionality") {
      CHECK(extfem::string::string("   2     ").upper() == "   2     ");
      CHECK(extfem::string::string("         ").upper() == "         ");
      CHECK(extfem::string::string(" \t      ").upper() == " \t      ");
      CHECK(extfem::string::string(" \txxx\t ").upper() == " \tXXX\t ");
      CHECK(extfem::string::string(" \tXXX\t ").upper() == " \tXXX\t ");
      CHECK(extfem::string::string("ABCDabcd ").upper() == "ABCDABCD ");
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
