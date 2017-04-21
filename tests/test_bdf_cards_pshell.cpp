/**
   \file tests/test_bdf_cards_pshell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PSHELL` card class.

   Detailed description
   */

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

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF PSHELL definitions (Small Field Format).", "[bdf_pshell]") {

    std::list<std::string> data({
            "PSHELL  1       4         23.00 4               4\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pshell probe(lines);

    SECTION("check data") {

        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }
}

TEST_CASE("BDF PSHELL definitions (reuse) (Small Field Format).", "[bdf_pshell]") {

    std::list<std::string> data({
            "PSHELL  1       4         23.00 4               4\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pshell probe;
    probe(lines);

    SECTION("check data") {
        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }
}

TEST_CASE("BDF PSHELL definitions (Large Field Format).", "[bdf_pshell]") {

    std::list<std::string> data({
            "PSHELL* 1               4                 23.00         4               \n",
            "*                       4  \n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pshell probe(lines);

    SECTION("check data") {
        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }
}

TEST_CASE("BDF PSHELL definitions (reuse) (Large Field Format).", "[bdf_pshell]") {

    std::list<std::string> data({
            "PSHELL* 1               4                 23.00         4               \n",
            "*                       4  \n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pshell probe;
    probe(lines);

    SECTION("check data") {
        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }
}

TEST_CASE("BDF PSHELL definitions (Free Field Format).", "[bdf_pshell]") {

    std::list<std::string> data({"PSHELL,1,4,23.00,4,,4\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pshell probe(lines);

    SECTION("check data") {
        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }
}

TEST_CASE("BDF PSHELL definitions (reuse) (Free Field Format).", "[bdf_pshell]") {

    std::list<std::string> data({"PSHELL,1,4,23.00,4,,4\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pshell probe;
    probe(lines);

    SECTION("check data") {
        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }
}

TEST_CASE("BDF PSHELL roundtrip test", "[bdf_pshell]") {
    std::ostringstream test;

    long PID{7869};
    long MID1{104010};
    double T{5.};
    long MID2{3};
    double _12_T_3{.73};
    long MID3{4};
    double TS_T{.8};
    double NSM{70.};
    double Z1{12.};
    double Z2{22.};
    long MID4{5};

    pshell probe(&PID, &MID1, &T, &MID2, &_12_T_3, &MID3, &TS_T, &NSM,
                 &Z1, &Z2, &MID4);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PSHELL      7869  1040105.000+00       37.300-01       48.000-017.000+01\n"
              "        1.200+012.200+01       5\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pshell probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID1) == 104010);
        CHECK(double(probe_l.T) == 5.);
        CHECK(long(probe_l.MID2) == 3);
        CHECK(double(probe_l.x12I_T__3) == .73);
        CHECK(double(probe_l.TS_T) == .8);
        CHECK(long(probe_l.MID3) == 4);
        CHECK(double(probe_l.NSM) == 70.);
        CHECK(double(probe_l.Z1) == 12.);
        CHECK(double(probe_l.Z2) == 22.);
        CHECK(long(probe_l.MID4) == 5);
    }
}

TEST_CASE("BDF PSHELL roundtrip test (reuse)", "[bdf_pshell]") {
    std::ostringstream test;

    long PID{7869};
    long MID1{104010};
    double T{5.};
    long MID2{3};
    double _12_T_3{.73};
    long MID3{4};
    double TS_T{.8};
    double NSM{70.};
    double Z1{12.};
    double Z2{22.};
    long MID4{5};

    pshell probe;
    test << probe;
    test << probe(&PID, &MID1, &T, &MID2, &_12_T_3, &MID3, &TS_T, &NSM,
                  &Z1, &Z2, &MID4);

    SECTION("check output") {
        CHECK(test.str() ==
              "PSHELL      7869  1040105.000+00       37.300-01       48.000-017.000+01\n"
              "        1.200+012.200+01       5\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pshell probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID1) == 104010);
        CHECK(double(probe_l.T) == 5.);
        CHECK(long(probe_l.MID2) == 3);
        CHECK(double(probe_l.x12I_T__3) == .73);
        CHECK(double(probe_l.TS_T) == .8);
        CHECK(long(probe_l.MID3) == 4);
        CHECK(double(probe_l.NSM) == 70.);
        CHECK(double(probe_l.Z1) == 12.);
        CHECK(double(probe_l.Z2) == 22.);
        CHECK(long(probe_l.MID4) == 5);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test ;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
