/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `TDLOAD` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_test_fem_cards_tdload[]) =
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

TEST_CASE("FEM TDLOAD definitions.", "[fem_tdload]") {

    vector<std::string> lines;
    size_t len;

    SECTION("TDLOAD (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD   4.00000000e+000 1.80000000e+002 1.21000000e+002 0.00000000e+000\n",
            "        PLAN_No6_STR(5445A/B)\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT.empty());
    }

    SECTION("TDLOAD (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD   4.000000000e+00 1.80000000e+02  1.21000000e+02  0.000000000e+00\n",
            "        PLAN_No6_STR(5445A/B)\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT.empty());
    }

    SECTION("TDLOAD (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD   4.000000000e+00 1.80000000e+02  1.21000000e+02  2.64000000e+02 \n",
            "        PLAN_No6_STR(5445A/B)\n",
            "        Meaningles comment.\n",
            "        abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+\n"});

        len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 180);
        CHECK(probe.CODNAM == 121);
        CHECK(probe.CODTXT == 264);
        CHECK(probe.SET_NAME == "PLAN_No6_STR(5445A/B)");
        CHECK(probe.CONT.size() == 2);
        CHECK(probe.CONT[0] == "Meaningles comment.                                             ");
        //                      1234567891123456789212345678931234567894123456789512345678961234
        CHECK(probe.CONT[1] == "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNUPQRSTUVWXYZ1234567890#+");
    }


    SECTION("TDLOAD (empty)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD  +4.000000000e+00+1.000000000e+00+1.120000000e+02+0.000000000e+00",
            "                    "
        });

        len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 1);
        CHECK(probe.CODNAM == 112);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "            ");
        CHECK(probe.CONT.empty());
    }
}

TEST_CASE("FEMIO-32: Import failed when reading TDLOAD entry", "[fem_tdload]") {

    vector<std::string> lines;

    SECTION("Failing card") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD   4.00000000e+000 1.00000000e+000 1.00000000e+002 0.00000000e+000\n",
            "         "});
        auto len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 1);
        CHECK(probe.CODNAM == 100);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "");
        CHECK(probe.CONT.empty());
    }
}

TEST_CASE("FEM TDLOAD types output.", "[fem_tdload,out]") {

    std::ostringstream test;

    SECTION("empty") {
        tdload probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        tdload probe(4, 123, 122, "1234567890123456789012");
        test << probe;
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("calc internal values") {
        tdload probe(123, "1234567890123456789012");
        test << probe;
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("with comment") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdload probe(4, 123, 122, 233, "1234567890123456789012", comments);
        test << probe;
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }

    SECTION("with comment (calc internal values)") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdload probe(123, "1234567890123456789012", comments);
        test << probe;
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }

    SECTION("empty comment (calc internal values)") {
        tdload probe(123, "");
        test << probe;
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.000000000e+02+0.000000000e+00\n"
              "        \n");
    }

    SECTION("call (simple)") {
        tdload probe;
        test << probe(4, 123, 122, "1234567890123456789012");
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("call (calc internal values)") {
        tdload probe;
        test << probe(123, "1234567890123456789012");
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n");
    }

    SECTION("call (with comment)") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdload probe;
        test << probe(4, 123, 122, 233, "1234567890123456789012", comments);
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }

    SECTION("call (with comment (calc internal values))") {
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        tdload probe;
        test << probe(123, "1234567890123456789012", comments);
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n");
    }

    SECTION("call (empty comment (calc internal values))") {
        tdload probe;
        test << probe(123, "");
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.000000000e+02+0.000000000e+00\n"
              "        \n");
    }

    SECTION("call (combined)") {
        tdload probe;
        test << probe;
        test << probe(4, 123, 122, "1234567890123456789012");
        test << probe(123, "1234567890123456789012");
        std::vector<std::string> comments(2);
        comments[0] = "test";
        comments[1] = "123456789112345678921234567893123";
        test << probe(4, 123, 122, 233, "1234567890123456789012", comments);
        test << probe(123, "1234567890123456789012", comments);
        test << probe(123, "");
        test << probe;
        CHECK(test.str() ==
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n"
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n"
              "        1234567890123456789012\n"
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n"
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n"
              "        1234567890123456789012\n"
              "        test                             \n"
              "        123456789112345678921234567893123\n"
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.000000000e+02+0.000000000e+00\n"
              "        \n"
              "TDLOAD  +4.000000000e+00+1.230000000e+02+1.000000000e+02+0.000000000e+00\n"
              "        \n");
    }
}

TEST_CASE("FEM TDLOAD conversion from own output.", "[fem_tdload,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("TDLOAD (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+0.000000000e+00\n",
            "        1234567890123456789012\n"});
        len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 123);
        CHECK(probe.CODNAM == 122);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "1234567890123456789012");
        CHECK(probe.CONT == std::vector<std::string>(0));
    }

    SECTION("TDLOAD (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD  +4.000000000e+00+1.230000000e+02+1.220000000e+02+2.330000000e+02\n",
            "        1234567890123456789012\n",
            "        test                             \n",
            "        123456789112345678921234567893123\n"});
        len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 123);
        CHECK(probe.CODNAM == 122);
        CHECK(probe.CODTXT == 233);
        CHECK(probe.SET_NAME == "1234567890123456789012");
        CHECK(probe.CONT == std::vector<std::string>({
            "test                             ",
            "123456789112345678921234567893123"}));
    }

    SECTION("TDLOAD (3)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TDLOAD  +4.000000000e+00+1.230000000e+02+1.000000000e+02+0.000000000e+00\n",
            "        \n"});
        len = __base::card::card_split(data, data.size(), lines);
        tdload probe(lines, len);

        CHECK(probe.NFIELD == 4);
        CHECK(probe.ILREF == 123);
        CHECK(probe.CODNAM == 100);
        CHECK(probe.CODTXT == 0);
        CHECK(probe.SET_NAME == "");
        CHECK(probe.CONT == std::vector<std::string>(0));
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
