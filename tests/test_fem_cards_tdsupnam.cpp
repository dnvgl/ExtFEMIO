/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing input and output for Sesam FEM `TDSUPNAM` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_tdsupnam[]) =
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

TEST_CASE("FEM TDSUPNAM definitions.", "[fem_tdsupnam]") {

    vector<std::string> lines;
    size_t len;

    SECTION("TDSUPNAM (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSUPNAM 4.00000000e+000 1.80000000e+002 1.21000000e+002 0.00000000e+000\n",
            "        PLAN_No6_STR(5445A/B)\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdsupnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.IHREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SUP_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT == std::vector<std::string>(0));
    }

    SECTION("TDSUPNAM (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSUPNAM 4.000000000e+00 1.80000000e+02  1.21000000e+02  0.000000000e+00\n",
            "        PLAN_No6_STR(5445A/B)\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdsupnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.IHREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SUP_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT == std::vector<std::string>(0));
    }

    SECTION("TDSUPNAM (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSUPNAM 4.000000000e+00 1.80000000e+02  1.21000000e+02  2.64000000e+02 \n",
            "        PLAN_No6_STR(5445A/B)\n",
            "        Meaningles comment.\n",
            "        abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdsupnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.IHREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 264);
        CHECK(probe.SUP_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT.size() == 2);
        CHECK(probe.CONT[0] == "Meaningles comment.                                             ");
        //                      1234567891123456789212345678931234567894123456789512345678961234
        CHECK(probe.CONT[1] == "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+");
    }
}

TEST_CASE("FEM TDSUPNAM types output.", "[fem_tdsupnam,out]") {

    std::ostringstream test;

    SECTION("empty") {
        tdsupnam probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        tdsupnam probe(4, 123, 122, "1234567890123456789012");
        test << probe;
        CHECK(test.str() ==
              "TDSUPNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("calc internal values") {
        tdsupnam probe(123, "1234567890123456789012");
        test << probe;
        CHECK(test.str() ==
              "TDSUPNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("with comment") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdsupnam probe(4, 123, 122, 233, "1234567890123456789012", comments);
        test << probe;
        CHECK(test.str() ==
              "TDSUPNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }

    SECTION("with comment (calc internal values)") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdsupnam probe(123, "1234567890123456789012", comments);
        test << probe;
        CHECK(test.str() ==
              "TDSUPNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }
}

TEST_CASE("FEM TDSUPNAM conversion from own output.", "[fem_tdsupnam,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("TDSUPNAM (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSUPNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n",
            "        1234567890123456789012\n"});
        len = __base::card::card_split(data, data.size(), lines);
        tdsupnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.IHREF == 123);
        CHECK(probe.CODNAM == 122);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SUP_NAME == "1234567890123456789012");
        CHECK(probe.CONT == std::vector<std::string>(0));
    }

    SECTION("TDSUPNAM (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSUPNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n",
            "        1234567890123456789012\n",
            "        test                             \n",
            "        123456789112345678921234567893123\n"});
        len = __base::card::card_split(data, data.size(), lines);
        tdsupnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.IHREF == 123);
        CHECK(probe.CODNAM == 122);
        CHECK(probe.CODTXT == 233);
        CHECK(probe.SUP_NAME == "1234567890123456789012");
        CHECK(probe.CONT == std::vector<std::string>({
            "test                             ",
            "123456789112345678921234567893123"}));
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
