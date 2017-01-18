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
#include <vector>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "config.h"

#include "fem/types.h"
#include "fem/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::types;
using namespace dnvgl::extfem::fem::type_bounds;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
    return Catch::toString( ex.what() );
}

TEST_CASE("FEM list types parsing.", "[fem_types]" ) {

    entry_type<std::vector<int> > probe("dummy");
    std::vector<int> res;

    SECTION("' 1.34000000e+02 '") {
        probe(res, " 1.34000000e+02 ");
        CHECK(res == std::vector<int>({ 1, 3, 4 }));
    }

    SECTION("' 1.23600000e+03 '") {
        probe(res, " 1.23600000e+03 ");
        CHECK(res == std::vector<int>({ 1, 2, 3, 6 }));
    }

    SECTION("' 1.236000000e+03'") {
        probe(res, " 1.236000000e+03");
        CHECK(res == std::vector<int>({ 1, 2, 3, 6 }));
    }

    SECTION("' 1a3b   '") {
        CHECK_THROWS(probe(res, " 1a3b   "));
    }
}

TEST_CASE("FEM list of int types output.", "[fem_types]" ) {

    entry_type<std::vector<int> > obj("dummy");

    std::vector<int> lval({ 1, 2, 3, 4 });

    std::ostringstream stream(std::ostringstream::ate);

    SECTION("Output") {
        std::string res(obj.format(lval));
        CHECK(res.size() == 16);
        CHECK(res == " 1.234000000e+03");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
