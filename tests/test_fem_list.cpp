/**
   \file tests/test_fem_list.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the FEM list class.

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

TEST_CASE("FEM list types parsing.", "[fem_types]" ) {

   entry_type<std::deque<int>> probe("dummy");

   SECTION("' 1.34000000e+02 '") {

      std::deque<int> ref({ 1, 3, 4 });
      CHECK(*probe(" 1.34000000e+02 ") == ref);
   }

   SECTION("' 1.23600000e+03 '") {
      std::deque<int> ref({ 1, 2, 3, 6 });
      CHECK(*probe(" 1.23600000e+03 ") == ref);
   }

   SECTION("' 1a3b   '") {
      CHECK_THROWS(probe(" 1a3b   "));
   }
}

TEST_CASE("FEM list of int types output.", "[fem_types]" ) {

   entry_type<std::deque<int>> obj("dummy");

   std::deque<int> lval({ 1, 2, 3, 4 });

   std::ostringstream stream(std::ostringstream::ate);

   SECTION("Output") {
      std::string res(obj.format(lval));
      CHECK(res.size() == 16);
      CHECK(res == " 1.23400000e+03 ");
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
