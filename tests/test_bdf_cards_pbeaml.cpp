/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBEAML` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_bdf_cards_pbeaml[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"


#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"
#include "bdf/file.h"

#include "catch_vector_helper.h"

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
            "           25.0   600.0         YESA    1.\n"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 104018);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(probe.DIM.size() == 2);
    for (size_t i{0}; i < 2; i++)
        CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                   IsEqual(vector<double>({25., 600.})));
    CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<std::string>(1, "YESA")));
    CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
               IsEqual(vector<double>(1, 1.)));
    CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
               IsEqual(vector<double>(2, 0.)));
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (BAR 2).", "[bdf_pbeaml]") {

    list<std::string> data({
            "PBEAML       134       8            BAR\n",
            "            55.0   500.0        YESA    1.\n"});
    list<std::string> lines;
    card::card_split(data, lines);
    pbeaml probe(lines);

    CHECK((long)probe.PID == 134);
    CHECK((long)probe.MID == 8);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(probe.DIM.size() == 2);
    for (size_t i{0}; i < 2; i++)
        CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                   IsEqual(vector<double>({55., 500.})));
    CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
               IsEqual(vector<double>(2, 0.)));
    CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<std::string>(1, "YESA")));
    CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
               IsEqual(vector<double>(1, 1.)));
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
    CHECK(probe.DIM.size() == 2);
    CHECK(probe.DIM[0].size() == 4);
    for (size_t i{0}; i < 2; i++)
        CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                   IsEqual(vector<double>({63., 340., 35., 14.})));
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
    CHECK(probe.DIM.size() == 2);
    for (size_t i{0}; i < 2; i++)
        CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                   IsEqual(vector<double>({150., 400., 12., 10.})));
    CHECK(double(probe.NSM[0]) == 0.);
    CHECK(probe.SO.size() == 0);
    CHECK(probe.X_XB.size() == 0);
}

TEST_CASE("BDF PBEAML definitions: Small Field Format (I).", "[bdf_pbeaml]") {
    pbeaml::reset();

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
    CHECK(probe.DIM.size() == 2);
    for (size_t i{0}; i < 2; i++)
        CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                   IsEqual(vector<double>({600., 200., 200., 12., 10., 10.})));
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
    CHECK(probe.DIM.size() == 2);
    for (size_t i{0}; i < 2; i++)
        CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                   IsEqual(vector<double>({600., 500.})));
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
    CHECK(probe.DIM.size() == 4);
    for (size_t i = 0; i<probe.DIM.size(); i++ ) {
        CHECK(probe.DIM[i].size() == 4);
        CHECK(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()) ==
          vector<vector<double>>(
              {{12., 14.8, 2.5, 2.6},
                  {6., 7., 1.2, 2.6},
                  {6., 7.8, 5.6, 2.3},
                  {12., 14.8, 2.5, 2.6}})[i]);
    }
    CHECK(probe.NSM.size() == 3);
    CHECK(vector<double>(probe.NSM.begin(), probe.NSM.end()) ==
          vector<double>({0., 0., 0.}));
    CHECK(vector<std::string>(probe.SO.begin(), probe.SO.end()) ==
          vector<std::string>({"NO", "YES", "YES"}));
    CHECK(vector<double>(probe.X_XB.begin(), probe.X_XB.end()) ==
          vector<double>({.4, .6, 1.}));
}

TEST_CASE("BDF PBEAML invalid dim test", "[bdf_pbeaml]") {
    pbeaml::reset();
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6., 7.}};
    vector<double> NSM{77.};
    vector<std::string> SO(1, "NO");
    vector<double> X_XB(1, 1.);

    CHECK_THROWS_AS(pbeaml(&PID, &MID, &GROUP, &TYPE,
                           &DIM, &NSM, &SO, &X_XB), errors::form_error);
}

TEST_CASE("BDF PBEAML roundtrip test", "[bdf_pbeaml]") {
    pbeaml::reset();
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.}};
    vector<double> NSM{77.};
    vector<std::string> SO(1, "NO");
    vector<double> X_XB(1, 1.);

    pbeaml probe(&PID, &MID, &GROUP, &TYPE,
                 &DIM, &NSM, &SO, &X_XB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01NO      \n"
              "        1.000+00\n");
    }

    SECTION("check reading") {
        pbeaml::reset();
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
        CHECK(probe_l.DIM.size() == 2);
        for (size_t i{0}; i < 2; i++)
            CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                       IsEqual(vector<double>({1., 2., 3., 4., 5., 6.})));
        CHECK(vector<double>(probe_l.NSM.begin(), probe_l.NSM.end()) ==
              vector<double>({77., 77.}));
        CHECK(vector<std::string>(probe_l.SO.begin(), probe_l.SO.end()) ==
              vector<std::string>(1, "NO"));
        CHECK(vector<double>(probe_l.X_XB.begin(), probe_l.X_XB.end()) ==
              vector<double>(1, 1.));
    }
}

TEST_CASE("BDF PBEAML roundtrip test (reuse)", "[bdf_pbeaml]") {
    pbarl::reset();

    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.},
            {1., 2., 3., 4., 5., 6.}};
    vector<double> NSM{77., 77.};
    vector<std::string> SO(1, "NO");
    vector<double> X_XB(1, 1.);

    pbeaml probe;
    test << probe;
    test << probe(&PID, &MID, &GROUP, &TYPE,
                 &DIM, &NSM, &SO, &X_XB);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01NO      \n"
              "        1.000+00\n");
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
        CHECK(probe_l.DIM.size() == 2);
        for (size_t i{0}; i < 2; i++)
            CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                       IsEqual(vector<double>({1., 2., 3., 4., 5., 6.})));
        CHECK(vector<double>(probe_l.NSM.begin(), probe_l.NSM.end()) ==
              vector<double>({77., 77.}));
        CHECK(vector<std::string>(probe_l.SO.begin(), probe_l.SO.end()) ==
              vector<std::string>(1, "NO"));
        CHECK(vector<double>(probe_l.X_XB.begin(), probe_l.X_XB.end()) ==
              vector<double>(1, 1.));
    }
}

TEST_CASE("BDF PBEAML roundtrip test (SO, X/XB: default)", "[bdf_pbeaml]") {
    pbeaml::reset();
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.}};

    pbeaml probe(&PID, &MID, &GROUP, &TYPE,
                 &DIM);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+00        YESA    \n"
              "        1.000+00\n");
    }

    SECTION("check reading") {
        pbeaml::reset();
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
        CHECK(probe_l.DIM.size() == 2);
        for (size_t i{0}; i < 2; i++)
            CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                       IsEqual(vector<double>({1., 2., 3., 4., 5., 6.})));
        CHECK(vector<double>(probe_l.NSM.begin(), probe_l.NSM.end()) ==
            vector<double>({0., 0.}));
        CHECK(vector<std::string>(probe_l.SO.begin(), probe_l.SO.end()) ==
              vector<std::string>(1, "YESA"));
        CHECK(vector<double>(probe_l.X_XB.begin(), probe_l.X_XB.end()) ==
              vector<double>(1, 1.));
    }
}

TEST_CASE("BDF PBEAML roundtrip test (reuse) (SO, X/XB: default)",
          "[bdf_pbeaml]") {
    pbarl::reset();

    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.}};

    pbeaml probe;
    test << probe;
    test << probe(&PID, &MID, &GROUP, &TYPE,
                  &DIM);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+00        YESA    \n"
              "        1.000+00\n");
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
        CHECK(probe_l.DIM.size() == 2);
        for (size_t i{0}; i < 2; i++)
            CHECK_THAT(vector<double>(probe.DIM[i].begin(), probe.DIM[i].end()),
                       IsEqual(vector<double>({1., 2., 3., 4., 5., 6.})));
        CHECK(vector<double>(probe_l.NSM.begin(), probe_l.NSM.end()) ==
              vector<double>({0., 0.}));
        CHECK(vector<std::string>(probe_l.SO.begin(), probe_l.SO.end()) ==
              vector<std::string>(1, "YESA"));
        CHECK(vector<double>(probe_l.X_XB.begin(), probe_l.X_XB.end()) ==
              vector<double>(1, 1.));
    }
}

TEST_CASE("BDF PBEAML roundtrip test, multiple stations", "[bdf_pbeaml]") {
    pbeaml::reset();
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.},
        {7., 8., 9., 10., 11, 12.}};
    vector<double> NSM{77., 88.};
    vector<std::string> SO{"NO"};
    vector<double> X_XB{1.};

    pbeaml probe(&PID, &MID, &GROUP, &TYPE,
                 &DIM, &NSM, &SO, &X_XB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01NO      \n"
              "        1.000+007.000+008.000+009.000+001.000+011.100+011.200+018.800+01\n");
    }

    SECTION("check reading") {
        pbeaml::reset();
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
        CHECK(probe_l.DIM.size() == 2);
        CHECK(probe_l.DIM[0].size() == 6);
        CHECK(vector<double>(probe_l.DIM[0].begin(), probe_l.DIM[0].end()) ==
        vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(probe_l.DIM[1].size() == 6);
        CHECK(vector<double>(probe_l.DIM[1].begin(), probe_l.DIM[1].end()) ==
        vector<double>({7., 8., 9., 10., 11, 12.}));
        CHECK(vector<double>(probe_l.NSM.begin(), probe_l.NSM.end())
        == vector<double>({77., 88.}));
        CHECK(probe_l.SO.size() == 1);
        CHECK(std::string(probe_l.SO[0]) == "NO");
        CHECK(probe_l.X_XB.size() == 1);
        CHECK(double(probe_l.X_XB[0]) == 1.);
   }
}

TEST_CASE("BDF PBEAML roundtrip test, multiple stations (reuse)", "[bdf_pbeaml]") {
    pbarl::reset();

    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<vector<double>> DIM{{1., 2., 3., 4., 5., 6.},
        {7., 8., 9., 10., 11, 12.}};
    vector<double> NSM{77., 88.};
    vector<std::string> SO{"NO"};
    vector<double> X_XB{1.};

    pbeaml probe;
    test << probe;
    test << probe(&PID, &MID, &GROUP, &TYPE,
                  &DIM, &NSM, &SO, &X_XB);

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
              "PBEAML      7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01NO      \n"
              "        1.000+007.000+008.000+009.000+001.000+011.100+011.200+018.800+01\n");
    }

    SECTION("check reading") {
        list<std::string> lines;
        list<std::string> l;
        std::string tmp;

        istringstream raw(test.str());

        input::bdf_file data(raw);

        data.get(l);
        card::card_split(l, lines);
        pbeaml probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(probe_l.DIM.size() == 2);
        CHECK(probe_l.DIM[0].size() == 6);
        CHECK(vector<double>(probe_l.DIM[0].begin(), probe_l.DIM[0].end()) ==
              vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(probe_l.DIM[1].size() == 6);
        CHECK(vector<double>(probe_l.DIM[1].begin(), probe_l.DIM[1].end()) ==
              vector<double>({7., 8., 9., 10., 11, 12.}));
        CHECK(vector<double>(probe_l.NSM.begin(), probe_l.NSM.end())
              == vector<double>({77., 88.}));
        CHECK(probe_l.SO.size() == 1);
        CHECK(std::string(probe_l.SO[0]) == "NO");
        CHECK(probe_l.X_XB.size() == 1);
        CHECK(double(probe_l.X_XB[0]) == 1.);
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
