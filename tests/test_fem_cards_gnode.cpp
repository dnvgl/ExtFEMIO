/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GNODE` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_gnode[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM GNODE definitions.", "[fem_gnode]") {

    vector<std::string> lines;
    size_t len;

    SECTION("GNODE (1)") {
        vector<std::string> data({
            "GNODE    1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gnode probe(lines, len);

        CHECK(probe.NODEX == 1);
        CHECK(probe.NODENO == 1);
        CHECK(probe.NDOF == 3);
        CHECK(probe.ODOF.size() == 3);
        CHECK(probe.ODOF[0] == 1);
        CHECK(probe.ODOF[1] == 3);
        CHECK(probe.ODOF[2] == 4);
    }

    SECTION("GNODE (2)") {
        vector<std::string> data({
            "GNODE    1.000000000e+00 1.000000000e+00 3.000000000e+00 1.34000000e+02 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        gnode probe(lines, len);

        CHECK(probe.NODEX == 1);
        CHECK(probe.NODENO == 1);
        CHECK(probe.NDOF == 3);
        CHECK(probe.ODOF.size() == 3);
        CHECK(probe.ODOF[0] == 1);
        CHECK(probe.ODOF[1] == 3);
        CHECK(probe.ODOF[2] == 4);
    }

    SECTION("GNODE (3)") {
        vector<std::string> data({
            "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gnode probe(lines, len);

        CHECK(probe.NODEX == 1);
        CHECK(probe.NODENO == 222);
        CHECK(probe.NDOF == 3);
        CHECK(probe.ODOF.size() == 3);
        CHECK(probe.ODOF[0] == 2);
        CHECK(probe.ODOF[1] == 3);
        CHECK(probe.ODOF[2] == 6);
    }

    SECTION("reuse (GNODE)") {
        vector<std::string> data({
            "GNODE    1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gnode probe;
        probe(lines, len);

        CHECK(probe.NODEX == 1);
        CHECK(probe.NODENO == 1);
        CHECK(probe.NDOF == 3);
        CHECK(probe.ODOF.size() == 3);
        CHECK(probe.ODOF[0] == 1);
        CHECK(probe.ODOF[1] == 3);
        CHECK(probe.ODOF[2] == 4);
    }
}

TEST_CASE("FEM GNODE types output.", "[fem_gnode,out]") {

    std::ostringstream test;

    long NODEX(1), NODENO(222), NDOF(3);
    std::vector<int> ODOF({2, 6, 3});

    SECTION("emtpy") {
        gnode probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("const") {
        gnode probe(1, 222, 3, {2, 6, 3});
        test << probe;
        CHECK(test.str() ==
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n");
    }

    SECTION("simple") {
        gnode probe(NODEX, NODENO, NDOF, ODOF);
        test << probe;
        CHECK(test.str() ==
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n");
    }

    SECTION("simple (2)") {
        gnode probe(NODEX, NODENO, ODOF);
        test << probe;
        CHECK(test.str() ==
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n");
    }

    SECTION("reuse (const)") {
        gnode probe;
        test << probe(1, 222, 3, {2, 6, 3});
        CHECK(test.str() ==
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n");
    }

    SECTION("reuse (simple)") {
        gnode probe;
        test << probe(NODEX, NODENO, NDOF, ODOF);
        CHECK(test.str() ==
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n");
    }

    SECTION("reuse (simple (2))") {
        gnode probe;
        test << probe(NODEX, NODENO, ODOF);
        CHECK(test.str() ==
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n");
    }

    SECTION("reuse (multiple)") {
        gnode probe;
        test << probe;
        test << probe(1, 222, 3, {2, 6, 3});
        test << probe(NODEX, NODENO, NDOF, ODOF);
        test << probe(NODEX, NODENO, ODOF);
        test << probe;
        CHECK(test.str() ==
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n"
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n"
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n"
              "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n");
    }
}

TEST_CASE("FEM GNODE conversion from own output.", "[fem_gnode,in/out]") {

    vector<std::string> lines;

    SECTION("GNODE (1)") {
        vector<std::string> data({
            "GNODE   +1.000000000e+00+2.220000000e+02+3.000000000e+00 2.360000000e+02\n"});
        size_t len{__base::card::card_split(data, data.size(), lines)};
        gnode probe(lines, len);

        CHECK(probe.NODEX == 1);
        CHECK(probe.NODENO == 222);
        CHECK(probe.NDOF == 3);
        CHECK(probe.ODOF == std::vector<int>({2, 3, 6}));
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
