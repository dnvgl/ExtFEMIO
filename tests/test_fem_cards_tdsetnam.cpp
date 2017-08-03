/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `TDSETNAM` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
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

TEST_CASE("FEM TDSETNAM definitions.", "[fem_tdsetnam]") {

    vector<std::string> lines;
    size_t len;

    SECTION("TDSETNAM (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSETNAM 4.00000000e+000 1.80000000e+002 1.21000000e+002 0.00000000e+000\n",
            "        PLAN_No6_STR(5445A/B)\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdsetnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ISREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT == std::vector<std::string>(0));
    }

    SECTION("TDSETNAM (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSETNAM 4.00000000e+00  1.80000000e+02  1.21000000e+02  0.00000000e+00 \n",
            "        PLAN_No6_STR(5445A/B)\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdsetnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ISREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT == std::vector<std::string>(0));
    }

    SECTION("TDSETNAM (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSETNAM 4.00000000e+00  1.80000000e+02  1.21000000e+02  2.64000000e+02 \n",
            "        PLAN_No6_STR(5445A/B)\n",
            "        Meaningles comment.\n",
            "        abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdsetnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ISREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 264);
        CHECK(probe.SET_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT == std::vector<std::string>({
            // 34567891123456789212345678931234567894123456789512345678961234
            "Meaningles comment.                                             ",
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+"}));
    }
}

TEST_CASE("FEM TDSETNAM types output.", "[fem_tdsetnam,out]") {

    std::ostringstream test;

    SECTION("empty") {
        tdsetnam probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        tdsetnam probe(4, 123, 122, "1234567890123456789012");
        test << probe;
        CHECK(test.str() ==
              "TDSETNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("calc internal values") {
        tdsetnam probe(123, "1234567890123456789012");
        test << probe;
        CHECK(test.str() ==
              "TDSETNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("with comment") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdsetnam probe(4, 123, 122, 233, "1234567890123456789012", comments);
        test << probe;
        CHECK(test.str() ==
              "TDSETNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }

    SECTION("with comment (calc internal values)") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdsetnam probe(123, "1234567890123456789012", comments);
        test << probe;
        CHECK(test.str() ==
              "TDSETNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }
}

TEST_CASE("FEM TDSETNAM conversion from own output.", "[fem_tdsetnam,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("TDSETNAM (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSETNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n",
            "        1234567890123456789012\n"});
        len = __base::card::card_split(data, data.size(), lines);
        tdsetnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ISREF == 123);
        CHECK(probe.CODNAM == 122);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "1234567890123456789012");
        CHECK(probe.CONT == std::vector<std::string>(0));
    }

    SECTION("TDSETNAM (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDSETNAM+4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n",
            "        1234567890123456789012\n",
            "        test                             \n",
            "        123456789112345678921234567893123\n"});
        len = __base::card::card_split(data, data.size(), lines);
        tdsetnam probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ISREF == 123);
        CHECK(probe.CODNAM == 122);
        CHECK(probe.CODTXT == 233);
        CHECK(probe.SET_NAME == "1234567890123456789012");
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
