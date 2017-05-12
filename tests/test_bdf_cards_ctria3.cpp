/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `CTRIA3` cards classes.

   Detailed description
*/
#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    const char  cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace cards;

TEST_CASE("BDF CTRIA3 definitions. (Small Field Format)",
          "[bdf_ctria3]") {

    list<std::string> data({
        // 34567|1234567|1234567|1234567|1234567|1234567|
        "CTRIA3  1       1       16      200     141\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    ctria3 probe(lines);

    SECTION("run test") {
        CHECK(long(probe.EID) == 1);
        CHECK(long(probe.PID) == 1);
        CHECK(long(probe.G1) == 16);
        CHECK(long(probe.G2) == 200);
        CHECK(long(probe.G3) == 141);
        CHECK(probe.choose_mcid_theta == ctria3::CHOOSE_MCID_THETA::has_THETA);
        CHECK_FALSE(probe.MCID);
        CHECK(double(probe.THETA) == 0.0);
    }
}

TEST_CASE("BDF CTRIA3 definitions. (Small Field Format, default values)",
          "[bdf_ctria3]") {

    list<std::string> data({
        // 34567|1234567|1234567|1234567|1234567|1234567|
        "CTRIA3  1               16      200     141\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    ctria3 probe(lines);

    SECTION("run test") {
        CHECK(long(probe.EID) == 1);
        CHECK(long(probe.PID) == 1);
        CHECK(long(probe.G1) == 16);
        CHECK(long(probe.G2) == 200);
        CHECK(long(probe.G3) == 141);
        CHECK(probe.choose_mcid_theta == ctria3::CHOOSE_MCID_THETA::has_THETA);
        CHECK_FALSE(probe.MCID);
        CHECK(double(probe.THETA) == 0.0);
        CHECK_FALSE(probe.ZOFFS);
        CHECK_FALSE(probe.TFLAG);
        CHECK_FALSE(probe.T1);
        CHECK_FALSE(probe.T2);
        CHECK_FALSE(probe.T3);
    }
}

TEST_CASE("BDF CTRIA3 definitions. (Small Field Format, default values 2)",
          "[bdf_ctria3]") {

    list<std::string> data({
        // 34567|1234567|1234567|1234567|1234567|1234567|1234567|1234567|1234567|1234567|
        "CTRIA3  1               16      200     141\n",
        "                1\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    ctria3 probe(lines);

    SECTION("run test") {
        CHECK(long(probe.EID) == 1);
        CHECK(long(probe.PID) == 1);
        CHECK(long(probe.G1) == 16);
        CHECK(long(probe.G2) == 200);
        CHECK(long(probe.G3) == 141);
        CHECK(probe.choose_mcid_theta == ctria3::CHOOSE_MCID_THETA::has_THETA);
        CHECK_FALSE(probe.MCID);
        CHECK(double(probe.THETA) == 0.0);
        CHECK_FALSE(probe.ZOFFS);
        CHECK(long(probe.TFLAG) == 1);
        CHECK(double(probe.T1) == 1.);
        CHECK(double(probe.T2) == 1.);
        CHECK(double(probe.T3) == 1.);
    }
}

TEST_CASE("BDF CTRIA3 definitions. (Large Field Format)",
          "[bdf_ctria3]") {

    list<std::string> data({
        // 34567|123456781234567|123456781234567|123456781234567|123456781234567|
        "CTRIA3* 2               1               16              200             *\n",
        "*       141\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    ctria3 probe(lines);

    SECTION("run test") {
        CHECK(long(probe.EID) == 2);
        CHECK(long(probe.PID) == 1);
        CHECK(long(probe.G1) == 16);
        CHECK(long(probe.G2) == 200);
        CHECK(long(probe.G3) == 141);
        CHECK_FALSE(probe.MCID);
        CHECK(double(probe.THETA) == 0.0);
    }
}

TEST_CASE("BDF CTRIA3 check limits.", "[bdf_ctria3]") {

    ostringstream test;

    long EID{1};
    long PID{2};
    long G1{3};
    long G2{4};
    long G3{5};
    double THETA{6.};
    double ZOFFS{7.};
    long TFLAG{8};
    double T1{9.}, T2{10.}, T3{11};

    SECTION("run test") {
        CHECK_THROWS_AS(
            ctria3(&EID, &PID, &G1, &G2, &G3, &THETA, &ZOFFS, &TFLAG,
                   &T1, &T2, &T3),
            errors::int_error);
    }
}

TEST_CASE("BDF CTRIA3 check limits reuse.", "[bdf_ctria3]") {

    ostringstream test;

    long EID{1};
    long PID{2};
    long G1{3};
    long G2{4};
    long G3{5};
    double THETA{6.};
    double ZOFFS{7.};
    long TFLAG{8};
    double T1{9.}, T2{10.}, T3{11};

    SECTION("run test") {
        ctria3 probe;
        CHECK_THROWS_AS(
            probe(&EID, &PID, &G1, &G2, &G3, &THETA, &ZOFFS, &TFLAG,
                  &T1, &T2, &T3),
            errors::int_error);
    }
}

TEST_CASE("BDF CTRIA3 roundtrip 1.", "[bdf_ctria3_roundtrip]") {

    ostringstream test;

    long EID{1};
    long PID{2};
    long G1{3};
    long G2{4};
    long G3{5};
    double THETA{6.};
    double ZOFFS{7.};
    long TFLAG{1};
    double T1{9.}, T2{10.}, T3{11};

    ctria3 probe(&EID, &PID, &G1, &G2, &G3, &THETA, &ZOFFS, &TFLAG,
                 &T1, &T2, &T3);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CTRIA3         1       2       3       4       56.000+007.000+00        \n"
              "                       19.000+001.000+011.100+01\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        ctria3 probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
    }

}

TEST_CASE("BDF CTRIA3 types output 2.", "[bdf_ctria3,out]") {

    ostringstream test;

    SECTION("check output") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long MCID{6};
        double ZOFFS{7.};
        long TFLAG{0};
        double T1{9.}, T2{10.}, T3{11};

        ctria3 probe(&EID, &PID, &G1, &G2, &G3, &MCID, &ZOFFS, &TFLAG,
                      &T1, &T2, &T3);
        test << probe;

        CHECK(test.str() ==
              "CTRIA3         1       2       3       4       5       67.000+00        \n"
              "                       09.000+001.000+011.100+01\n");
    }
}

TEST_CASE("BDF CTRIA3 types output 3.", "[bdf_ctria3,out]") {

    ostringstream test;

    SECTION("check output") {
        long EID{111};
        long PID{203};
        long G1{31};
        long G2{74};
        long G3{75};
        long MCID{3};
        double ZOFFS{.98};
        double T1{1.77}, T2{2.04}, T3{2.09};

        ctria3 probe(&EID, &PID, &G1, &G2, &G3, &MCID, &ZOFFS, nullptr,
                      &T1, &T2, &T3);
        test << probe;

        CHECK(test.str() ==
              "CTRIA3       111     203      31      74      75       39.800-01        \n"
              "                        1.770+002.040+002.090+00\n");
    }
}

TEST_CASE("BDF CTRIA3 types output 4.", "[bdf_ctria3,out]") {

    ostringstream test;

    SECTION("check output") {
        long EID{111};
        long PID{203};
        long G1{31};
        long G2{74};
        long G3{75};
        double THETA{3.};
        double ZOFFS{.98};
        double T1{1.77}, T2{2.04}, T3{2.09};

        ctria3 probe(&EID, &PID, &G1, &G2, &G3, &THETA, &ZOFFS, nullptr,
                      &T1, &T2, &T3);
        test << probe;

        CHECK(test.str() ==
              "CTRIA3       111     203      31      74      753.000+009.800-01        \n"
              "                        1.770+002.040+002.090+00\n");
    }
}

TEST_CASE("BDF CTRIA3 types output 5.", "[bdf_ctria3,out]") {

    ostringstream test;

    SECTION("check output") {
        long EID{111};
        long PID{203};
        long G1{31};
        long G2{74};
        long G3{75};
        double THETA{3.};
        double ZOFFS{.98};

        ctria3 probe(&EID, &PID, &G1, &G2, &G3, &THETA, &ZOFFS);
        test << probe;

        CHECK(test.str() ==
              "CTRIA3       111     203      31      74      753.000+009.800-01\n");
        }

}

TEST_CASE("BDF CTRIA types output (reuse).", "[bdf_ctria3,out,resue]") {

    ostringstream test;

    SECTION("test 1") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        double THETA{6.};
        double ZOFFS{7.};
        long TFLAG{1};
        double T1{9.}, T2{10.}, T3{11};

        ctria3 probe;

        test << probe;
        test << probe(&EID, &PID, &G1, &G2, &G3, &THETA, &ZOFFS, &TFLAG,
                      &T1, &T2, &T3);

        CHECK(test.str() ==
              "CTRIA3         1       2       3       4       56.000+007.000+00        \n"
              "                       19.000+001.000+011.100+01\n");
    }

    SECTION("test 2") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long MCID{6};
        double ZOFFS{7.};
        long TFLAG{1};
        double T1{9.}, T2{10.}, T3{11};

        ctria3 probe;
        test << probe(&EID, &PID, &G1, &G2, &G3, &MCID, &ZOFFS, &TFLAG,
                      &T1, &T2, &T3);

        CHECK(test.str() ==
              "CTRIA3         1       2       3       4       5       67.000+00        \n"
              "                       19.000+001.000+011.100+01\n");
    }

    SECTION("test 3") {
        long EID{1};
        long PID{2};
        long G1{3};
        long G2{4};
        long G3{5};
        long MCID{6};
        double ZOFFS{7.};

        ctria3 probe;
        test << probe(&EID, &PID, &G1, &G2, &G3, &MCID, &ZOFFS);

        CHECK(test.str() ==
              "CTRIA3         1       2       3       4       5       67.000+00\n");
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
