/**
   \file tests/test_bdf_header_displacement.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing of DISPLACEMENT class for case control.

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

TEST_CASE("BDF generate 'DISPLACEMENT' header entries", "[bdf_header,displacement]") {

   std::ostringstream test;

   SECTION("first") {
      case_control::displacement probe({}, case_control::displacement::ALL);
      test << probe;
      CHECK(test.str() == "DISPLACEMENT = ALL\n");
   }

   SECTION("bdf sample") {
      case_control::displacement probe({
            new case_control::displacement::print,
            new case_control::displacement::punch,
            new case_control::displacement::real},
         case_control::displacement::ALL);
      test << probe;
      CHECK(test.str() == "DISPLACEMENT(PRINT, PUNCH, REAL) = ALL\n");
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
