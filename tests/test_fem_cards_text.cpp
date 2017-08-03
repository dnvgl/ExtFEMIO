/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `TEXT` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_fem_cards_text[] _EXTFEMIO_UNUSED =
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

TEST_CASE("FEM TEXT definitions.", "[fem_text]" ) {

    vector<std::string> lines;
    size_t len;

    SECTION("TEXT (1)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001",
                "        CONVERSION DETAILS:",
                "        Msc Nastran File Format -> Sesam Interface File.",
                "        Input  : \\test_01.bdt",
                "        Log    : \\test_01.txt"});

        len = __base::card::card_split(data, data.size(), lines);
        text probe(lines, len);

        CHECK(probe.TYPE == 0);
        CHECK(probe.SUBTYPE == 0);
        CHECK(probe.NRECS == 4);
        CHECK(probe.NBYTE == 72);
        CHECK(probe.CONT == std::vector<std::string>({
                    //        1         2         3         4         5         6         7
                    // 3456789012345678901234567890123456789012345678901234567890123456789012
                    "CONVERSION DETAILS:                                                     ",
                    "Msc Nastran File Format -> Sesam Interface File.                        ",
                    "Input  : \\test_01.bdt                                                   ",
                    "Log    : \\test_01.txt                                                   "}));
    }

    SECTION("TEXT (2)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TEXT     0.000000000e+00 0.000000000e+00 4.000000000e+00 7.200000000e+01",
            "        CONVERSION DETAILS:",
            "        Msc Nastran File Format -> Sesam Interface File.",
            "        Input  : \\test_01.bdt",
            "        Log    : \\test_01.txt"});

        len = __base::card::card_split(data, data.size(), lines);
        text probe(lines, len);

        CHECK(probe.TYPE == 0);
        CHECK(probe.SUBTYPE == 0);
        CHECK(probe.NRECS == 4);
        CHECK(probe.NBYTE == 72);
        CHECK(probe.CONT == std::vector<std::string>({
            //        1         2         3         4         5         6         7
            // 3456789012345678901234567890123456789012345678901234567890123456789012
            "CONVERSION DETAILS:                                                     ",
            "Msc Nastran File Format -> Sesam Interface File.                        ",
            "Input  : \\test_01.bdt                                                   ",
            "Log    : \\test_01.txt                                                   "}));
    }

    SECTION("TEXT (empty)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "TEXT    +3.000000000e+00+1.000000000e+00+1.000000000e+00+2.000000000e+01",
            "                            "});

        len = __base::card::card_split(data, data.size(), lines);
        text probe(lines, len);

        CHECK(probe.TYPE == 3);
        CHECK(probe.SUBTYPE == 1);
        CHECK(probe.NRECS == 1);
        CHECK(probe.NBYTE == 20);
        CHECK(probe.CONT == std::vector<std::string>({
            //        1         2         3         4         5         6         7
            // 3456789012345678901234567890123456789012345678901234567890123456789012
            "                    "}));
    }
}

TEST_CASE("FEM TEXT types output.", "[fem_text,out]" ) {

    std::stringstream test;
    std::vector<std::string> CONT({
            "CONVERSION DETAILS:",
            "Msc Nastran File Format -> Sesam Interface File.",
            "Input  : \\test_01.bdt",
            "Log    : \\test_01.txt"});

    SECTION("simple (empty)") {
        text probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        text probe(0, 0, 4, 72, CONT);
        test << probe;
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+7.200000000e+01\n"
              "        CONVERSION DETAILS:                                             \n"
              "        Msc Nastran File Format -> Sesam Interface File.                \n"
              "        Input  : \\test_01.bdt                                           \n"
              "        Log    : \\test_01.txt                                           \n");
    }

    SECTION("simple (auto dim)") {
        text probe(0, 0, CONT);
        test << probe;
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n"
              "        CONVERSION DETAILS:                             \n"
              "        Msc Nastran File Format -> Sesam Interface File.\n"
              "        Input  : \\test_01.bdt                           \n"
              "        Log    : \\test_01.txt                           \n");
    }

    SECTION("call (simple)") {
        text probe;
        test << probe(0, 0, 4, 72, CONT);
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+7.200000000e+01\n"
              "        CONVERSION DETAILS:                                             \n"
              "        Msc Nastran File Format -> Sesam Interface File.                \n"
              "        Input  : \\test_01.bdt                                           \n"
              "        Log    : \\test_01.txt                                           \n");
    }

    SECTION("call (simple (auto dim))") {
        text probe;
        test << probe(0, 0, CONT);
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n"
              "        CONVERSION DETAILS:                             \n"
              "        Msc Nastran File Format -> Sesam Interface File.\n"
              "        Input  : \\test_01.bdt                           \n"
              "        Log    : \\test_01.txt                           \n");
    }

    SECTION("call (multiple)") {
        text probe;
        test << probe;
        test << probe(0, 0, 4, 72, CONT);
        test << probe(0, 0, CONT);
        test << probe;
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+7.200000000e+01\n"
              "        CONVERSION DETAILS:                                             \n"
              "        Msc Nastran File Format -> Sesam Interface File.                \n"
              "        Input  : \\test_01.bdt                                           \n"
              "        Log    : \\test_01.txt                                           \n"
              "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n"
              "        CONVERSION DETAILS:                             \n"
              "        Msc Nastran File Format -> Sesam Interface File.\n"
              "        Input  : \\test_01.bdt                           \n"
              "        Log    : \\test_01.txt                           \n"
              "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n"
              "        CONVERSION DETAILS:                             \n"
              "        Msc Nastran File Format -> Sesam Interface File.\n"
              "        Input  : \\test_01.bdt                           \n"
              "        Log    : \\test_01.txt                           \n");
    }
}

TEST_CASE("FEM TEXT conversion from own output.", "[fem_text,in/out]") {

    vector<std::string> lines;

    SECTION("TEXT (1)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "TEXT    +0.000000000e+00+0.000000000e+00+4.000000000e+00+5.600000000e+01\n",
                "        CONVERSION DETAILS:                             \n",
                "        Msc Nastran File Format -> Sesam Interface File.\n",
                "        Input  : \\test_01.bdt                           \n",
                "        Log    : \\test_01.txt                           \n"});
        auto len = __base::card::card_split(data, data.size(), lines);
        text probe(lines, len);

        CHECK(probe.TYPE == 0);
        CHECK(probe.SUBTYPE == 0);
        CHECK(probe.NRECS == 4);
        CHECK(probe.NBYTE == 56);
        CHECK(probe.CONT == std::vector<std::string>({
                    //        1         2         3         4         5         6         7
                    // 3456789012345678901234567890123456789012345678901234567890123456789012
                    "CONVERSION DETAILS:                                     ",
                    "Msc Nastran File Format -> Sesam Interface File.        ",
                    "Input  : \\test_01.bdt                                   ",
                    "Log    : \\test_01.txt                                   "}));
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
