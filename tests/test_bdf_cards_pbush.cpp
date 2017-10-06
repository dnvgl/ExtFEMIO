/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Testing the BDF `PBUSH` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_test_bdf_cards_pbush[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"

#include "catch_vector_helper.h"

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

TEST_CASE ("BDF PBUSH definitons.", "[bdf_pbush]") {

    SECTION("QR Guide, Example 1") {
        list<std::string> data({
                // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i
                "PBUSH     35     K       4.35    2.4                              3.1\n",
                "                 GE     .06\n",
                "                 RCV    7.3      3.3\n"});
        list<std::string> lines;
        card::card_split(data, lines);
        pbush probe(lines);

        CHECK((long)probe.PID == 35);
        CHECK_THAT(vector<double>(probe.K.begin(), probe.K.end()),
                   IsEqual(vector<double>({4.35, 2.4, 0., 0., 0., 3.1})));
        CHECK(probe.B.size() == 0);
        CHECK_THAT(vector<double>(probe.GE.begin(), probe.GE.end()),
                   IsEqual(vector<double>({.06, 0., 0., 0., 0., 0.})));
        CHECK(probe.RCV);
        CHECK(double(probe.SA) == 7.3);
        CHECK(double(probe.ST) == 3.3);
        CHECK(double(probe.EA) == 1.);
        CHECK(double(probe.ET) == 1.);
    }

    SECTION("QR Guide, Example 1") {
        list<std::string> data({
                // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i
                "PBUSH     35     B       2.3\n"});
        list<std::string> lines;
        card::card_split(data, lines);
        pbush probe(lines);

        CHECK((long)probe.PID == 35);
        CHECK(probe.K.size() == 0);
        CHECK_THAT(vector<double>(probe.B.begin(), probe.B.end()),
                   IsEqual(vector<double>({2.3, 0., 0., 0., 0., 0.})));
        CHECK(probe.GE.size() == 0);
        CHECK_FALSE(probe.RCV);
    }
}

TEST_CASE("BDF PBUSH roundtrip test", "[bdf_pbush]") {
    pbush::reset();
    ostringstream test;

    long PID{7869};
    vector<double> K{{1., 2., 3., 4., 5., 6.}};
    vector<double> B{{11., 12., 13., 14., 15., 16.}};
    vector<double> GE{{21., 22., 23., 24., 25., 26.}};

    pbush probe(&PID, &K, &B, &GE);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
              "PBUSH       7869K       1.000+002.000+003.000+004.000+005.000+006.000+00\n"
              "                B       1.100+011.200+011.300+011.400+011.500+011.600+01\n"
              "                GE      2.100+012.200+012.300+012.400+012.500+012.600+01\n");
    }

    SECTION("check reading") {
        pbush::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;

        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbush probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(vector<double>(probe_l.K.begin(), probe_l.K.end()) ==
              vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(vector<double>(probe_l.B.begin(), probe_l.B.end()) ==
              vector<double>({11., 12., 13., 14., 15., 16.}));
        CHECK(vector<double>(probe_l.GE.begin(), probe_l.GE.end()) ==
              vector<double>({21., 22., 23., 24., 25., 26.}));
        CHECK(double(probe_l.SA) == 1.);
        CHECK(double(probe_l.ST) == 1.);
        CHECK(double(probe_l.EA) == 1.);
        CHECK(double(probe_l.ET) == 1.);
    }
}

TEST_CASE("BDF PBUSH roundtrip test 2", "[bdf_pbush]") {
    pbush::reset();
    ostringstream test;

    long PID{7869};
    vector<double> K{{1., 2., 3., 4., 5., 6.}};
    double SA{11.};
    double ST{12.};
    double EA{13.};
    double ET{14.};

    pbush probe(&PID, &K, nullptr, nullptr,
                &SA, &ST, &EA, &ET);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
              "PBUSH       7869K       1.000+002.000+003.000+004.000+005.000+006.000+00\n"
              "                RCV     1.100+011.200+011.300+011.400+01\n");
    }

    SECTION("check reading") {
        pbush::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;

        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        pbush probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(vector<double>(probe_l.K.begin(), probe_l.K.end()) ==
              vector<double>({1., 2., 3., 4., 5., 6.}));
        CHECK(probe_l.B.size() == 0);
        CHECK(probe_l.GE.size() == 0);
        CHECK(probe_l.RCV);
        CHECK(double(probe_l.SA) == 11.);
        CHECK(double(probe_l.ST) == 12.);
        CHECK(double(probe_l.EA) == 13.);
        CHECK(double(probe_l.ET) == 14.);
    }
}



// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
