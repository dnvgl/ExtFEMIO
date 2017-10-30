/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing the BDF `CONM1` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    char const  _EXTFEMIO_UNUSED(cID_test_bdf_cards_conm1[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"

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

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF CONM1 definitions. (Small Field Format)", "[bdf_conm1]" ) {

    SECTION("first conm1") {
        conm1::reset();
        std::list<std::string> data({
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CONM1    2       22       2      2.9     6.3                            \n",
                "         4.8     28.6                                                   \n",
                "                 28.6                                            28.6   \n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        conm1 probe(lines);

        CHECK(long(probe.EID) == 2);
        CHECK(long(probe.G) == 22);
        CHECK(long(probe.CID) == 2);
        CHECK(double(probe.M11) == 2.9);
        CHECK(double(probe.M21) == 6.3);
        CHECK_FALSE(bool(probe.M22));
        CHECK_FALSE(bool(probe.M31));
        CHECK_FALSE(bool(probe.M32));
        CHECK(double(probe.M33) == 4.8);
        CHECK(double(probe.M41) == 28.6);
        CHECK_FALSE(bool(probe.M42));
        CHECK_FALSE(bool(probe.M43));
        CHECK_FALSE(bool(probe.M44));
        CHECK_FALSE(bool(probe.M51));
        CHECK_FALSE(bool(probe.M52));
        CHECK_FALSE(bool(probe.M53));
        CHECK_FALSE(bool(probe.M54));
        CHECK(double(probe.M55) == 28.6);
        CHECK_FALSE(bool(probe.M61));
        CHECK_FALSE(bool(probe.M62));
        CHECK_FALSE(bool(probe.M63));
        CHECK_FALSE(bool(probe.M64));
        CHECK_FALSE(bool(probe.M65));
        CHECK(double(probe.M66) == 28.6);
    }

    SECTION("full conm1") {
        conm1::reset();
        std::list<std::string> data({
                // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
                "CONM1   1       2       3       11.     21.     22.     31.     32.     \n",
                "        33.     41.     42.     43.     44.     51.     52.     53.     \n",
                "        54.     55.     61.     62.     63.     64.     65.     66.     \n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        conm1 probe(lines);

        CHECK(long(probe.EID) == 1);
        CHECK(long(probe.G) == 2);
        CHECK(long(probe.CID) == 3);
        CHECK(double(probe.M11) == 11.);
        CHECK(double(probe.M21) == 21.);
        CHECK(double(probe.M22) == 22.);
        CHECK(double(probe.M31) == 31.);
        CHECK(double(probe.M32) == 32.);
        CHECK(double(probe.M33) == 33.);
        CHECK(double(probe.M41) == 41.);
        CHECK(double(probe.M42) == 42.);
        CHECK(double(probe.M43) == 43.);
        CHECK(double(probe.M44) == 44.);
        CHECK(double(probe.M51) == 51.);
        CHECK(double(probe.M52) == 52.);
        CHECK(double(probe.M53) == 53.);
        CHECK(double(probe.M54) == 54.);
        CHECK(double(probe.M55) == 55.);
        CHECK(double(probe.M61) == 61.);
        CHECK(double(probe.M62) == 62.);
        CHECK(double(probe.M63) == 63.);
        CHECK(double(probe.M64) == 64.);
        CHECK(double(probe.M65) == 65.);
        CHECK(double(probe.M66) == 66.);
    }
}

TEST_CASE("BDF CONM1 types output.", "[bdf_conm1,out]" ) {
    conm1::reset();

    std::ostringstream test;

    SECTION("empty") {
        conm1 probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("reverse") {
        long EID{2}, G{22}, CID{2};
        double M11{2.9}, M21{6.3}, M33{4.8}, M41{28.6}, M55{28.6}, M66{28.6};
        conm1 probe(&EID, &G, &CID, &M11, &M21, nullptr, nullptr, nullptr,
                    &M33, &M41, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                    nullptr, &M55, nullptr, nullptr, nullptr, nullptr, nullptr, &M66);
        test << probe;
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          2      22       22.900+006.300+00                        \n"
              "        4.800+002.860+01                                                \n"
              "                2.860+01                                        2.860+01\n");
    }

    SECTION("reverse part") {
        long EID{2}, G{22}, CID{2};
        double M11{2.9}, M21{6.3}, M33{4.8}, M41{28.6}, M55{28.6}, M66{28.6};
        conm1 probe(&EID, &G, &CID, &M11, &M21, nullptr, nullptr, nullptr,
                    &M33, &M41);
        test << probe;
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          2      22       22.900+006.300+00                        \n"
              "        4.800+002.860+01                                                \n"
              "                                                                        \n");
    }

    SECTION("auto number EID") {
        conm1::reset();
        long EID{0}, G{22}, CID{2};
        double M11{2.9};
        conm1 probe(&EID, &G, &CID, &M11);
        CHECK(long(probe.EID) == 1);
    }

    SECTION("auto number EID (2)") {
        conm1::reset();
        long G{22}, CID{2};
        double M11{2.9};
        conm1 probe(&G, &CID, &M11);
        CHECK(long(probe.EID) == 1);
    }

    SECTION("multiple") {
        conm1::reset();
        long EID{2}, G{6}, CID{3};
        double M11{2.9};
        conm1 probe;
        test << probe;
        test << probe(&EID, &G, &CID, &M11);
        EID++;
        test << probe(&EID, &G, &CID, &M11);
        test << probe;
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678\n"
              "CONM1          2       6       32.900+00                                \n"
              "                                                                        \n"
              "                                                                        \n"
              "CONM1          3       6       32.900+00                                \n"
              "                                                                        \n"
              "                                                                        \n"
              "CONM1          3       6       32.900+00                                \n"
              "                                                                        \n"
              "                                                                        \n");
    }

    SECTION("diag M value") {
        conm1::reset();
        long EID{2}, G{6}, CID{3};
        vector<double> Mij({2.9});
        conm1 probe;
        test << probe;
        test << probe(&EID, &G, &CID, &Mij);
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          2       6       32.900+00                                \n"
              "                                                                        \n"
              "                                                                        \n");
    }

    SECTION("diag M values") {
        conm1::reset();
        long EID{2}, G{6}, CID{3};
        vector<double> Mij({1., 2., 3., 4., 5., 6.});
        conm1 probe;
        test << probe;
        test << probe(&EID, &G, &CID, &Mij);
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          2       6       31.000+00        2.000+00                \n"
              "        3.000+00                        4.000+00                        \n"
              "                5.000+00                                        6.000+00\n");
    }

    SECTION("diag M values (auto EID)") {
        conm1::reset();
        long G{6}, CID{3};
        vector<double> Mij({1., 2., 3., 4., 5., 6.});
        conm1 probe(&G, &CID, &Mij);
        test << probe;
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          1       6       31.000+00        2.000+00                \n"
              "        3.000+00                        4.000+00                        \n"
              "                5.000+00                                        6.000+00\n");
    }

    SECTION("diag M values (auto EID) called") {
        conm1::reset();
        long G{6}, CID{3};
        vector<double> Mij({1., 2., 3., 4., 5., 6.});
        conm1 probe;
        test << probe;
        test << probe(&G, &CID, &Mij);
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          1       6       31.000+00        2.000+00                \n"
              "        3.000+00                        4.000+00                        \n"
              "                5.000+00                                        6.000+00\n");
    }

    SECTION("diag M values (auto EID) call") {
        conm1::reset();
        long G{6}, CID{3};
        vector<double> Mij({1., 2., 3., 4., 5., 6.});
        conm1 probe;
        test << probe;
        test << probe(&G, &CID, &Mij);
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          1       6       31.000+00        2.000+00                \n"
              "        3.000+00                        4.000+00                        \n"
              "                5.000+00                                        6.000+00\n");
    }

    SECTION("diag M values (auto EID) call, null values") {
        conm1::reset();
        long G{6}, CID{3};
        vector<double> Mij({1., 0., 0., 0., 0., 0.});
        conm1 probe;
        test << probe;
        test << probe(&G, &CID, &Mij);
        CHECK(test.str() ==
              // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
              "CONM1          1       6       31.000+00                                \n"
              "                                                                        \n"
              "                                                                        \n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_bdf_cards --invisibles --use-colour no)"
// End:
