/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `CQUAD4` cards classes.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

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

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace cards;

TEST_CASE("BDF CQUAD4 definitions. (Small Field Format)", "[bdf_cquad4]") {

    std::list<std::string> data({
        "CQUAD4  1       1       16      200     141     17\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cquad4 probe(lines);

    SECTION("first cquad4") {
        CHECK((long)probe.EID.value == 1);
        CHECK((long)probe.PID.value == 1);
        CHECK((long)probe.G1.value == 16);
        CHECK((long)probe.G2.value == 200);
        CHECK((long)probe.G3.value == 141);
        CHECK((long)probe.G4.value == 17);
        CHECK(probe.choose_mcid_theta == cquad4::CHOOSE_MCID_THETA::has_THETA);
        CHECK_FALSE(bool(probe.MCID));
        CHECK((double)probe.THETA == 0.0);
    }
}


TEST_CASE("BDF CQUAD4 definitions. (Large Field Format)", "[bdf_cquad4]") {

    std::list<std::string> data({
        "CQUAD4* 2               1               16              200             *\n",
        "*       141             17\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cquad4 probe(lines);

    SECTION("first cquad4") {
        CHECK((long)probe.EID == 2);
        CHECK((long)probe.PID == 1);
        CHECK((long)probe.G1 == 16);
        CHECK((long)probe.G2 == 200);
        CHECK((long)probe.G3 == 141);
        CHECK((long)probe.G4 == 17);
        CHECK_FALSE(bool(probe.MCID));
        CHECK((double)probe.THETA == 0.0);
    }
}

TEST_CASE("BDF CQUAD4 types output.", "[bdf_cquad4,out]") {
    cquad4::reset();

    ostringstream test;

    SECTION("test 1") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long G4{6};
        double THETA{7.};
        double ZOFFS{8.};
        long TFLAG{1};
        double T1{10.}, T2{11.}, T3{12}, T4{13};

        cquad4 probe(&EID, &PID, &G1, &G2, &G3, &G4, &THETA, &ZOFFS, &TFLAG,
                     &T1, &T2, &T3, &T4);
        test << probe;

        CHECK(test.str() ==
              "CQUAD4         1       2       3       4       5       57.000+008.000+00\n"
              "                       11.000+011.100+011.200+011.300+01\n");
    }

    SECTION("test 2") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long G4{6};
        long MCID{7};
        double ZOFFS{8.};
        long TFLAG{1};
        double T1{910.}, T2{11.}, T3{12.}, T4{13.};

        cquad4 probe(&EID, &PID, &G1, &G2, &G3, &G4, &MCID, &ZOFFS, &TFLAG,
                      &T1, &T2, &T3, &T4);
        test << probe;

        CHECK(test.str() ==
              "CQUAD4         1       2       3       4       5       6       78.000+00\n"
              "                       19.100+021.100+011.200+011.300+01\n");
    }

    SECTION("test 3") {
        long EID{111};
        long PID{203};
        long G1{31};
        long G2{74};
        long G3{75};
        long G4{32};
        long MCID{3};
        double ZOFFS{.3};
        double T1{1.77}, T2{2.04}, T3{2.09}, T4{1.8};

        cquad4 probe(&EID, &PID, &G1, &G2, &G3, &G4, &MCID, &ZOFFS, nullptr,
                     &T1, &T2, &T3, &T4);
        test << probe;

        CHECK(test.str() ==
              "CQUAD4       111     203      31      74      75      32       33.000-01\n"
              "                        1.770+002.040+002.090+001.800+00\n");
    }

    SECTION("test 4") {
        long EID{111};
        long PID{203};
        long G1{31};
        long G2{74};
        long G3{75};
        long G4{32};
        double THETA{2.6};
        double ZOFFS{.98};
        double T1{1.77}, T2{2.04}, T3{2.09}, T4{1.8};

        cquad4 probe(&EID, &PID, &G1, &G2, &G3, &G4, &THETA, &ZOFFS, nullptr,
                     &T1, &T2, &T3, &T4);
        test << probe;

        CHECK(test.str() ==
              "CQUAD4       111     203      31      74      75      752.600+009.800-01\n"
              "                        1.770+002.040+002.090+001.800+00\n");
    }

    SECTION("test 5") {
        long EID{111};
        long PID{203};
        long G1{31};
        long G2{74};
        long G3{75};
        long G4{32};
        double THETA{2.6};
        double ZOFFS{.98};

        cquad4 probe(&EID, &PID, &G1, &G2, &G3, &G4, &THETA, &ZOFFS);
        test << probe;

        CHECK(test.str() ==
              "CQUAD4       111     203      31      74      75      752.600+009.800-01\n");
    }
}

TEST_CASE("BDF CQUAD4 types output (reuse).", "[bdf_cquad4,out,reuse]") {
    cquad4::reset();

    ostringstream test;

    SECTION("test 1") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long G4{6};
        double THETA{7.};
        double ZOFFS{8.};
        long TFLAG{1};
        double T1{10.}, T2{11.}, T3{12.}, T4{13.};

        cquad4 probe;

        test << probe;
        test << probe(&EID, &PID, &G1, &G2, &G3, &G4, &THETA, &ZOFFS, &TFLAG,
                      &T1, &T2, &T3, &T4);

        CHECK(test.str() ==
              "CQUAD4         1       2       3       4       5       67.000+008.000+00\n"
              "                       11.000+011.100+011.200+011.300+01\n");
    }

    SECTION("test 2") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long G4{6};
        long MCID{7};
        double ZOFFS{8.};
        long TFLAG{0};
        double T1{10.}, T2{101.}, T3{12.}, T4{13.};

        cquad4 probe;
        test << probe(&EID, &PID, &G1, &G2, &G3, &G4, &MCID, &ZOFFS, &TFLAG,
                      &T1, &T2, &T3, &T4);

        CHECK(test.str() ==
              "CQUAD4         1       2       3       4       5       6       78.000+00\n"
              "                       01.000+011.010+021.200+011.300+01\n");
    }

    SECTION("test 3") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long G4{6};
        long MCID{7};
        double ZOFFS{8.};

        cquad4 probe;
        test << probe(&EID, &PID, &G1, &G2, &G3, &G4, &MCID, &ZOFFS);

        CHECK(test.str() ==
              "CQUAD4         1       2       3       4       5       6       78.000+00\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
