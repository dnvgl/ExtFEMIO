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

using namespace dnvgl::extfem;
using namespace bdf;
using namespace bdf::cards;
using namespace bdf::cards::__base;

using bdf::types::entry_type;
using bdf::types::entry_value;

TEST_CASE("BDF PBEAML definitions: Small Field Format (BAR).", "[bdf_pbeaml]") {

    list<std::string> data({
            // 34567A1234567B1234567C1234567D1234567E1234567F
            "PBEAML  104018  4               BAR\n",
            "           25.0   600.0\n"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104018);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM[0].size() == 2);
    for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
        CHECK(double(probe.DIM[0][i]) == vector<double>({25., 600.})[i]);
    }
    CHECK(probe.NSM.size() == 1);
    CHECK(double(probe.NSM[0]) == 0.);
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (BAR 2).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML       134       8            BAR\n",
            "            55.0   500.0\n"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 134);
    CHECK((long)probe.MID == 8);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM[0].size() == 2);
    for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
        CHECK(double(probe.DIM[0][i]) == vector<double>({55., 500.})[i]);
    }
    CHECK(probe.NSM.size() == 1);
    CHECK(double(probe.NSM[0]) == 0.);
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (L).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  104010  4               L\n",
            "           63.0   340.0    35.0    14.0\n"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104010);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "L");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM[0].size() == 4);
    for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
        CHECK(double(probe.DIM[0][i]) == vector<double>(
                  {63., 340., 35., 14.})[i]);
    }
    CHECK(double(probe.NSM[0]) == 0.);
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (T).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  101031  1               T\n",
            "          150.0   400.0    12.0    10.0\n"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 101031);
    CHECK((long)probe.MID == 1);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "T");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM[0].size() == 4);
    for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
        CHECK(double(probe.DIM[0][i]) == vector<double>(
                  {150., 400., 12., 10.})[i]);
    }
    CHECK(double(probe.NSM[0]) == 0.);
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (I).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  104018  4               I\n",
            "           600.0   200.0   200.0    12.0    10.0    10.0\n"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104018);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "I");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM[0].size() == 6);
    for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
        CHECK(double(probe.DIM[0][i]) == vector<double>(
                  {600., 200., 200., 12., 10., 10.})[i]);
    }
    CHECK(double(probe.NSM[0]) == 0.);
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (TUBE).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML  104019  5               TUBE\n",
            "           600.0   500.0"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104019);
    CHECK((long)probe.MID == 5);
    CHECK(probe.TYPE == "TUBE");
    CHECK(probe.DIM.size() == 1);
    CHECK(probe.DIM[0].size() == 2);
    for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
        CHECK(double(probe.DIM[0][i]) == vector<double>(
                  {600., 500.})[i]);
    }
    CHECK(double(probe.NSM[0]) == 0.);
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
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 99);
    CHECK((long)probe.MID == 21);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "T");
    CHECK(probe.DIM.size() == 3);
    for (size_t i = 0; i<probe.DIM.size(); i++ ) {
        CHECK(probe.DIM[i].size() == 4);
        for (size_t j = 0; i<probe.DIM[i].size(); i++ ) {
            CHECK(double(probe.DIM[i][j]) == vector<vector<double>>(
                      {{12., 14.8, 2.5, 2.6},
                       {6., 7., 1.2, 2.6},
                       {6., 7.8, 5.6, 2.3}})[i][j]);
        }
    }
    CHECK(probe.NSM.size() == 3);
    for (size_t i = 0; i<probe.NSM.size(); i++ ) {
        CHECK(double(probe.NSM[i]) == vector<double>({0., 0., 0.})[i]);
    }
    CHECK(probe.SO.size() == 2);
    for (size_t i = 0; i<probe.SO.size(); i++ ) {
        CHECK(std::string(probe.SO[i]) == vector<std::string>({
                    "NO", "YES"})[i]);
    }
    CHECK(probe.X_XB.size() == 2);
    for (size_t i = 0; i<probe.X_XB.size(); i++ ) {
        CHECK(double(probe.X_XB[i]) == vector<double>({.4, .6})[i]);
    }
}

TEST_CASE("BDF PBEAML invalid dim test", "[bdf_pbeaml]") {
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6., 7.}};
    vector<double> NSM{77.};
    vector<std::string> SO{"NO"};
    vector<double> X_XB{};

    CHECK_THROWS_AS(pbeaml(&PID, &MID, &GROUP, &TYPE,
                           &DIM, &NSM, &SO, &X_XB), errors::form_error);
}

TEST_CASE("BDF PBEAML roundtrip test", "[bdf_pbeaml]") {
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.}};
    vector<double> NSM{77.};
    vector<std::string> SO{"NO"};
    vector<double> X_XB{};

    pbeaml probe(&PID, &MID, &GROUP, &TYPE,
                 &DIM, &NSM, &SO, &X_XB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01NO      \n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbeaml probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(probe.DIM.size() == 1);
        CHECK(probe.DIM[0].size() == 6);
        for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
            CHECK(double(probe.DIM[0][i]) == vector<double>({1., 2., 3., 4., 5., 6.})[i]);
        }
        CHECK(probe.NSM.size() == 1);
        CHECK(double(probe.NSM[0]) == 77.);
        CHECK(probe.SO.size() == 1);
        CHECK(std::string(probe.SO[0]) == "NO");
        CHECK(probe.X_XB.size() == 0);
    }
}

TEST_CASE("BDF PBEAML roundtrip test (reuse)", "[bdf_pbeaml]") {
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.}};
    vector<double> NSM{77.};
    vector<std::string> SO{"NO"};
    vector<double> X_XB{};

    pbeaml probe;
    test << probe;
    test << probe(&PID, &MID, &GROUP, &TYPE,
                 &DIM, &NSM, &SO, &X_XB);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01NO      \n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbeaml probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(probe.DIM.size() == 1);
        CHECK(probe.DIM[0].size() == 6);
        for (size_t i = 0; i<probe.DIM[0].size(); i++ ) {
            CHECK(double(probe.DIM[0][i]) == vector<double>({1., 2., 3., 4., 5., 6.})[i]);
        }
        CHECK(probe.NSM.size() == 1);
        CHECK(double(probe.NSM[0]) == 77.);
        CHECK(probe.SO.size() == 1);
        CHECK(std::string(probe.SO[0]) == "NO");
        CHECK(probe.X_XB.size() == 0);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test ;
//    ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
