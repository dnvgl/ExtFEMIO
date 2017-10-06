/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `IDENT` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_ident[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM IDENT definitions.", "[fem_ident]") {

    vector<std::string> lines;
    size_t len;

    SECTION("IDENT (1)") {
        vector<std::string> data({
            "IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        ident probe(lines, len);

        CHECK(probe.SLEVEL == 1);
        CHECK(probe.SELTYP == 1);
        CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
    }

    SECTION("IDENT (2)") {
        vector<std::string> data({
            "IDENT   +1.00000000e+000+1.00000000e+000+3.00000000e+000+0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        ident probe(lines, len);

        CHECK(probe.SLEVEL == 1);
        CHECK(probe.SELTYP == 1);
        CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
    }

    SECTION("IDENT (3)") {
        vector<std::string> data({
            "IDENT    1.000000000e+00 1.000000000e+00 3.000000000e+00 0.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        ident probe(lines, len);

        CHECK(probe.SLEVEL == 1);
        CHECK(probe.SELTYP == 1);
        CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
    }

    SECTION("IDENT (4)") {
        vector<std::string> data({
            "IDENT    1.000000000e+00 1.000000000e+00 3.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        ident probe(lines, len);

        CHECK(probe.SLEVEL == 1);
        CHECK(probe.SELTYP == 1);
        CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
    }
}

TEST_CASE("FEM IDENT types output.", "[fem_ident,out]") {

    ostringstream test;

    SECTION("empty") {
        ident probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("const") {
        ident probe(1, 2, ident::mod_type::DIM_3D);
        test << probe;
        CHECK(test.str() ==
              "IDENT   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n");
    }

    SECTION("simple") {
        long SLEVEL{1}, SELTYP{2};
        ident::mod_type SELMOD{ident::mod_type::DIM_3D};
        ident probe(SLEVEL, SELTYP, SELMOD);
        test << probe;
        CHECK(test.str() ==
              "IDENT   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n");
    }
}

TEST_CASE("FEM IDENT conversion from own output.", "[fem_ident,in/out]") {

    vector<std::string> lines;

    SECTION("IDENT (1)") {
        vector<std::string> data({
            "IDENT   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n"});
        auto len = __base::card::card_split(data, data.size(), lines);
        ident probe(lines, len);

        CHECK(probe.SLEVEL == 1);
        CHECK(probe.SELTYP == 2);
        CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
