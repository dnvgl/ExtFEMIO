/**
   \file tests/test_bdf_cards_pbeaml.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBEAML` card class.

   Detailed description
   */

#include "extfem_misc.h"

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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF PBEAML definitions: Small Field Format (BAR).", "[bdf_pbeaml]") {

    list<std::string> data({
            // 34567A1234567B1234567C1234567D1234567E1234567F
            "PBEAML  104018  4               BAR\n",
            "           25.0   600.0\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104018);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM.front() == vector<double>({25., 600.}));
    CHECK(probe.NSM == vector<double>({0.}));
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (BAR 2).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML       134       8            BAR\n",
            "            55.0   500.0\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 134);
    CHECK((long)probe.MID == 8);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM.front() == vector<double>({55., 500.}));
    CHECK(probe.NSM == vector<double>({0.}));
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (L).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  104010  4               L\n",
            "           63.0   340.0    35.0    14.0\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104010);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "L");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM.front() == vector<double>({63., 340., 35., 14.}));
    CHECK(probe.NSM == vector<double>({0.}));
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (T).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  101031  1               T\n",
            "          150.0   400.0    12.0    10.0\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 101031);
    CHECK((long)probe.MID == 1);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "T");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM.front() == vector<double>({150., 400., 12., 10.}));
    CHECK(probe.NSM == vector<double>({0.}));
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (I).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  104018  4               I\n",
            "           600.0   200.0   200.0    12.0    10.0    10.0\n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104018);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "I");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM.front() == vector<double>({
                600., 200., 200., 12., 10., 10.}));
    CHECK(probe.NSM == vector<double>({0.}));
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (TUBE).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  104019  5               TUBE\n",
            "           600.0   500.0"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104019);
    CHECK((long)probe.MID == 5);
    CHECK(probe.TYPE == "TUBE");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM.front() == vector<double>({600., 500.}));
    CHECK(probe.NSM == vector<double>({0.}));
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (T, tapered).", "[bdf_pbeaml]") {

    list<std::string> data({
            // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I1234567J
            "PBEAML        99      21               T                                        \n",
            "             12.    14.8     2.5     2.6              NO     0.4      6.        \n",
            "              7.     1.2     2.6             YES     0.6      6.     7.8        \n",
            "             5.6     2.3             YES                                        \n"});
    list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 99);
    CHECK((long)probe.MID == 21);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "T");
    CHECK(probe.DIM.size() == 3);
    auto pos = probe.DIM.begin();
    CHECK(*pos == vector<double>({12., 14.8, 2.5, 2.6}));
    pos++;
    CHECK(*pos == vector<double>({6., 7., 1.2, 2.6}));
    pos++;
    CHECK(*pos == vector<double>({6., 7.8, 5.6, 2.3}));
    CHECK(probe.NSM == vector<double>({0., 0., 0.}));
    CHECK(probe.SO == vector<std::string>({"NO", "YES"}));
    CHECK(probe.X_XB == vector<double>({.4, .6}));
}

// TEST_CASE("BDF PBEAML roundtrip test", "[bdf_pbeaml]") {
//     ostringstream test;

//     long PID{7869}, MID{104010};
//     std::string GROUP("MSCBML0");
//     std::string TYPE("I");
//     vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.}};
//     vector<double> NSM{77.};
//     vector<std::string> SO{"NO"};
//     vector<double> X_XB{};

//     pbeaml probe(&PID, &MID, &GROUP, &TYPE,
//                  &DIM, &NSM, &SO, &X_XB);
//     test << probe;

//     SECTION("check output") {
//         CHECK(test.str() ==
//               "PBEAML       7869  1040101.000+002.000+003.000+004.000+005.000+006.000+00\n"
//               "        7.000+008.000+009.000+001.000+011.100+011.200+011.300+011.400+01\n"
//               "        YESA    1.600+012.000+003.000+004.000+005.000+006.000+007.000+00\n"
//               "        8.000+009.000+001.000+011.100+011.200+011.300+011.400+011.500+01\n"
//               "        1.700+011.800+011.900+012.000+012.100+012.200+012.300+012.400+01\n"
//               "        2.500+012.600+012.700+012.800+012.900+013.000+013.100+013.200+01\n");
//     }

//     SECTION("check reading") {
//         list<std::string> data;
//         list<std::string> lines;
//         std::string tmp;
//         istringstream raw(test.str());

//         while (getline(raw, tmp))
//             data.push_back(tmp);
//         __base::card::card_split(data, lines);
//         pbeaml probe_l(lines);

//         CHECK(long(probe_l.PID) == 7869);
//         CHECK(long(probe_l.MID) == 104010);
//         CHECK(probe.A == vector<double>({1., 2.}));
//         CHECK(probe.I1 == vector<double>({2., 3.}));
//         CHECK(probe.I2 == vector<double>({3., 4.}));
//         CHECK(probe.I12 == vector<double>({4., 5.}));
//         CHECK(probe.J == vector<double>({5., 6.}));
//         CHECK(probe.NSM == vector<double>({6., 7.}));
//         CHECK(probe.C1 == vector<double>({7., 8.}));
//         CHECK(probe.C2 == vector<double>({8., 9.}));
//         CHECK(probe.D1 == vector<double>({9., 10.}));
//         CHECK(probe.D2 == vector<double>({10., 11.}));
//         CHECK(probe.E1 == vector<double>({11., 12.}));
//         CHECK(probe.E2 == vector<double>({12., 13.}));
//         CHECK(probe.F1 == vector<double>({13., 14.}));
//         CHECK(probe.F2 == vector<double>({14., 15.}));
//         for (auto pos : probe.SO)
//             CHECK(pos.value == "YESA");
//         CHECK(probe.X_XB == vector<double> {16.});
//         CHECK(double(probe.K1) == 17.);
//         CHECK(double(probe.K2) == 18.);
//         CHECK(double(probe.S1) == 19.);
//         CHECK(double(probe.S2) == 20.);
//         CHECK(double(probe.NSI_A) == 21.);
//         CHECK(double(probe.NSI_B) == 22.);
//         CHECK(double(probe.CW_A) == 23.);
//         CHECK(double(probe.CW_B) == 24.);
//         CHECK(double(probe.M1_A) == 25.);
//         CHECK(double(probe.M2_A) == 26.);
//         CHECK(double(probe.M1_B) == 27.);
//         CHECK(double(probe.M2_B) == 28.);
//         CHECK(double(probe.N1_A) == 29.);
//         CHECK(double(probe.N2_A) == 30.);
//         CHECK(double(probe.N1_B) == 31.);
//         CHECK(double(probe.N2_B) == 32.);
//     }
// }

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test ;
//    ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
