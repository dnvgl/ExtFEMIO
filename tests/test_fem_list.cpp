/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the FEM list class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_list[]) =
        "@(#) $Id$";
}

#include <vector>

#ifndef EXTFEM_POS_TEST
// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#endif

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::types;
using namespace dnvgl::extfem::fem::type_bounds;

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
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_list --use-colour no)"
// End:
