/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBARL` card class.

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

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace bdf::cards;
using namespace bdf::cards::__base;

using bdf::types::entry_type;
using bdf::types::entry_value;

TEST_CASE("BDF PBARL definitions; Small Field Format (BAR).", "[bdf_pbarl]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104018  4               BAR\n",
                "           25.0   600.0\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    pbarl probe(lines);

    CHECK((long)probe.PID == 104018);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(probe.DIM.size() == 2);
    CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
          vector<double>({25., 600.}));
    CHECK((double)probe.NSM == 0.);
}


TEST_CASE("BDF PBARL definitions; Small Field Format (BAR) (alt.).", "[bdf_pbarl]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL        134       8            BAR\n",
                "            55.0   500.0"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    pbarl probe(lines);

    CHECK((long)probe.PID == 134);
    CHECK((long)probe.MID == 8);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "BAR");
    CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
          vector<double>({55., 500.}));
    CHECK((double)probe.NSM == 0.);
}

TEST_CASE("BDF PBARL definitions; Small Field Format (L).", "[bdf_pbarl]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104010  4               L\n",
                "           63.0   340.0    35.0    14.0\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    pbarl probe(lines);

    CHECK((long)probe.PID == 104010);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "L");
    CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
          vector<double>({63., 340., 35., 14.}));
    CHECK((double)probe.NSM == 0.);
}

TEST_CASE("BDF PBARL definitions; Small Field Format (T).", "[bdf_pbarl]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   101031  1               T\n",
                "          150.0   400.0    12.0    10.0\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    pbarl probe(lines);

    CHECK((long)probe.PID == 101031);
    CHECK((long)probe.MID == 1);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "T");
    CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
          vector<double>({150., 400., 12., 10.}));
    CHECK((double)probe.NSM == 0.);
}

TEST_CASE("BDF PBARL definitions; Small Field Format (I).", "[bdf_pbarl]") {
    pbarl::resetIds();

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104018  4               I\n",
                "           600.0   200.0   200.0    12.0    10.0    10.0\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    pbarl probe(lines);

    CHECK((long)probe.PID == 104018);
    CHECK((long)probe.MID == 4);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "I");
    CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
          vector<double>({
                  600., 200., 200., 12., 10., 10.}));
    CHECK((double)probe.NSM == 0.);
}

TEST_CASE("BDF PBARL definitions; Small Field Format (I) (alt).", "[bdf_pbarl]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL         39       6               I\n",
                "             14.      6.      .5      .5      .5      .5\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    pbarl probe(lines);

    CHECK((long)probe.PID == 39);
    CHECK((long)probe.MID == 6);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "I");
    CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
          vector<double>({14., 6., .5, .5, .5, .5}));
    CHECK((double)probe.NSM == 0.);
}

TEST_CASE("BDF PBARL definitions; Small Field Format (TUBE).", "[bdf_pbarl]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104019  5               TUBE\n",
                "           600.0   500.0\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);
    pbarl probe(lines);

    CHECK((long)probe.PID == 104019);
    CHECK((long)probe.MID == 5);
    CHECK(probe.GROUP == "MSCBML0");
    CHECK(probe.TYPE == "TUBE");
    CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
          vector<double>({600., 500.}));
    CHECK((double)probe.NSM == 0.);
}

TEST_CASE("BDF PBARL roundtrip test", "[bdf_pbarl]") {
    property::resetIds();

    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<double> DIM{1., 2., 3., 4., 5., 6.};
    double NSM{77.};

    pbarl probe(&PID, &MID, &GROUP, &TYPE,
                &DIM, &NSM);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBARL       7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01\n");
    }

    SECTION("check reading") {
        pbarl::resetIds();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbarl probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(probe.DIM.size() == 6);
        CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
              vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(double(probe.NSM) == 77.);
    }
}

TEST_CASE("BDF PBARL roundtrip test (reuse)", "[bdf_pbarl]") {
    property::resetIds();

    ostringstream test;

    long PID{7869}, MID{104010};
    std::string GROUP("MSCBML0");
    std::string TYPE("I");
    vector<double> DIM{1., 2., 3., 4., 5., 6.};
    double NSM{77.};

    pbarl probe;
    test << probe;
    test << probe(&PID, &MID, &GROUP, &TYPE,
                  &DIM, &NSM);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBARL       7869  104010MSCBML0 I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+007.700+01\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbarl probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(probe.DIM.size() == 6);
        CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
              vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(double(probe.NSM) == 77.);
    }
}

TEST_CASE("BDF PBARL roundtrip test (use default)", "[bdf_pbarl]") {
    pbarl::resetIds();
    ostringstream test;

    long PID{7869}, MID{104010};
    std::string TYPE("I");
    vector<double> DIM{1., 2., 3., 4., 5., 6.};

    pbarl probe(&PID, &MID, nullptr, &TYPE, &DIM);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBARL       7869  104010        I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+00\n");
    }

    SECTION("check reading") {
        pbarl::resetIds();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbarl probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(probe.DIM.size() == 6);
        CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
              vector<double>({1., 2., 3., 4., 5., 6.}));

        CHECK_FALSE(probe.NSM);
    }
}

TEST_CASE("BDF PBARL roundtrip test (use default) (reuse)", "[bdf_pbarl]") {
    pbarl::resetIds();

    ostringstream test;

    long PID{7869}, MID{104010};
    std::string TYPE("I");
    vector<double> DIM{1., 2., 3., 4., 5., 6.};

    pbarl probe;
    test << probe;
    test << probe(&PID, &MID, nullptr, &TYPE, &DIM);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBARL       7869  104010        I                                       \n"
              "        1.000+002.000+003.000+004.000+005.000+006.000+00\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbarl probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(probe.DIM.size() == 6);
        CHECK(vector<double>(probe.DIM.begin(), probe.DIM.end()) ==
              vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK_FALSE(probe.NSM);
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
