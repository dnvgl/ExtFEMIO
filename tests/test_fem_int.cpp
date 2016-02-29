/**
   \file tests/test_fem_int.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Tests for SEASAM FEM int types.

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

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <sstream>

#ifndef _MSC_VER
#include <config.h>
#endif

#include "fem/types.h"
#include "fem/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::dnvgl::extfem;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::types;
using namespace ::dnvgl::extfem::fem::type_bounds;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return Catch::toString( ex() );
}

namespace {
   static const long lc0 = 0;
   static const long lc1 = 1;
   static const long lc_1 = -1;
}

TEST_CASE("FEM int types parsing.", "[fem_types]" ) {

   entry_type<long> probe("dummy", bound<long>(nullptr, nullptr));

   //        12345678901e3456
   SECTION("' 0.00000000E+000'") {
      CHECK(probe(" 0.00000000E+000") == 0);
   }

   //        12345678901e3456
   SECTION("' 2.00000000E+000'") {
      entry_type<long> obj("dummy", bound<long>(&lc1));
      CHECK(obj(" 2.00000000E+000") == 2);
   }

   //        12345678901e3456
   SECTION("' 2.00000000E+00 '") {
      entry_type<long> obj("dummy", bound<long>(&lc1));
      CHECK(obj(" 2.00000000E+00 ") == 2);
   }

   //        12345678901e3456
   SECTION("'+2.00000000E+00 '") {
      entry_type<long> obj("dummy", bound<long>(&lc1));
      CHECK(obj("+2.00000000E+00 ") == 2);
   }

   //        12345678901e3456
   SECTION("'+2.00000000E+000'") {
      entry_type<long> obj("dummy", bound<long>(&lc1));
      CHECK(obj("+2.00000000E+000") == 2);
   }

   //        12345678901e3456
   SECTION("'-1.00000000E+00 '") {
      entry_type<long> obj("dummy", bound<long>(&lc_1, nullptr, &lc0));
      CHECK(obj("-1.00000000E+00 ") == -1);
   }

   //        12345678901e3456
   SECTION("'+1.23000000E+02 '") {
      entry_type<long> obj("dummy");
      CHECK(obj("+1.23000000E+02 ") == 123);
   }

   SECTION("Misc Num") {
      ::std::vector<::std::string> samples;
      //            12345678901e3456
      CHECK(probe("+7.00000000e+00 ") == 7);
      CHECK(probe("+7.00000000E+00 ") == 7);
      CHECK(probe("-7.00000000e+00 ") == -7);
      CHECK(probe("-7.00000000E+00 ") == -7);
   }
}

TEST_CASE("FEM int types output.", "[fem_types]" ) {

   entry_type<long> obj("dummy");

   long lval(1);

   SECTION("Output") {
      CHECK(obj.format(lval).size() == 16);
      CHECK(obj.format(lval) == "+1.00000000e+00 ");
   }

   SECTION("Output (neg. val)") {
      long lval(-1);
      CHECK(obj.format(lval).size() == 16);
      CHECK(obj.format(lval) == "-1.00000000e+00 ");
   }

   SECTION("Output (void)") {
      long lval(1);
      CHECK(lval == 1);
      CHECK(obj.format(lval).size() == 16);
      CHECK(obj.format(lval) == "+1.00000000e+00 ");
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
