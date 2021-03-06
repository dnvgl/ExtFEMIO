/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `IEND` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_iend[]) =
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
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM IEND definitions.", "[fem_iend]") {

    vector<std::string> lines;
    size_t len;

    SECTION("IEND (1)") {
        vector<std::string> data({
            "IEND     1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        iend probe(lines, len);

        CHECK(probe.CONT == 1);
    }

    SECTION("IEND (2)") {
        vector<std::string> data({
            "IEND    +1.00000000e+000+0.00000000e+000+0.00000000e+000+0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        iend probe(lines, len);

        CHECK(probe.CONT == 1);
    }

    SECTION("IEND (3)") {
        vector<std::string> data({
            "IEND     1.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        iend probe(lines, len);

        CHECK(probe.CONT == 1);
    }

    SECTION("IEND (4)") {
        vector<std::string> data({
            "IEND                0.00            0.00            0.00            0.00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        iend probe(lines, len);

        CHECK(probe.CONT == 0);
    }
}

TEST_CASE("FEM IEND types output.", "[fem_iend,out]") {

    std::ostringstream test;

    SECTION("emtpy") {
        iend probe;
        test << probe;
        CHECK(test.str() == "");
    }
    SECTION("simple") {
        iend probe(3);
        test << probe;
        CHECK(test.str() ==
              "IEND    +3.000000000e+00            0.00            0.00            0.00\n");
    }
}

TEST_CASE("FEM IEND conversion from own output.", "[fem_iend,in/out]") {

    vector<std::string> lines;

    SECTION("IEND (1)") {
        vector<std::string> data({
            "IEND    +3.000000000e+00            0.00            0.00            0.00\n"});
        auto len = __base::card::card_split(data, data.size(), lines);
        iend probe(lines, len);

        CHECK(probe.CONT == 3);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_support_grouping --use-colour no)"
// End:
