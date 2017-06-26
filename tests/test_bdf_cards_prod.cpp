/**
    \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PROD` card class.

   Detailed description
*/
#include "StdAfx.h"

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

TEST_CASE("BDF PROD definitions; Free Field Format 1.", "[bdf_prod]") {
    prod::reset();

    std::list<std::string> data({
            "PROD,1,2,3.,4.,5.,6.\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);

    CAPTURE(data.front());

    prod probe(lines);

    CHECK((long)probe.PID == 1);
    CHECK((long)probe.MID == 2);
    CHECK((double)probe.A == 3.);
    CHECK((double)probe.J == 4.);
    CHECK((double)probe.C == 5.);
    CHECK((double)probe.NSM == 6.);
}

TEST_CASE("BDF PROD definitions; Free Field Format 2.", "[bdf_prod]") {
    prod::reset();

    std::list<std::string> data({
            "PROD,1,2,3.,4.,5.\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);

    CAPTURE(data.front());

    prod probe(lines);

    CHECK((long)probe.PID == 1);
    CHECK((long)probe.MID == 2);
    CHECK((double)probe.A == 3.);
    CHECK((double)probe.J == 4.);
    CHECK((double)probe.C == 5.);
    CHECK_FALSE(bool(probe.NSM));
}

TEST_CASE("BDF PROD definitions; Free Field Format 3.", "[bdf_prod]") {
    prod::reset();

    std::list<std::string> data({
            "PROD,1,2,3.,4.\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);

    CAPTURE(data.front());

    prod probe(lines);

    CHECK((long)probe.PID == 1);
    CHECK((long)probe.MID == 2);
    CHECK((double)probe.A == 3.);
    CHECK((double)probe.J == 4.);
    CHECK((double)probe.C == 0.);
    CHECK_FALSE(bool(probe.NSM));
}

TEST_CASE("BDF PROD definitions; Small Field Format.", "[bdf_prod]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PROD          17      23    42.6   17.92  4.2356     0.5                        \n"});
    std::list<std::string> lines;
    card::card_split(data, lines);

    CAPTURE(data.front());

    prod probe(lines);

    CHECK((long)probe.PID == 17);
    CHECK((long)probe.MID == 23);
    CHECK((double)probe.A == 42.6);
    CHECK((double)probe.J == 17.92);
    CHECK((double)probe.C == 4.2356);
    CHECK((double)probe.NSM == 0.5);
}

TEST_CASE("BDF PROD definitions; Small Field Format 2.", "[bdf_prod]") {

    std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PROD    6000001 1       3000.00\n"});
    std::list<std::string> lines;
    card::card_split(data, lines);

    CAPTURE(data.front());

    prod probe(lines);

    CHECK((long)probe.PID == 6000001);
    CHECK((long)probe.MID == 1);
    CHECK((double)probe.A == 3000);
    CHECK_FALSE(bool(probe.J));
    CHECK((double)probe.C == 0.);
    CHECK_FALSE(bool(probe.NSM));
}

TEST_CASE("BDF PROD roundtrip test", "[bdf_prod]") {
    prod::reset();
    ostringstream test;

    long PID{17};
    long MID{23};
    double A{42.6};
    double J{17.92};
    double C{4.2356};
    double NSM{.5};

    prod probe(&PID, &MID, &A, &J, &C, &NSM);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PROD*                 17              234.26000000000+011.79200000000+01\n"
              "*       4.23560000000+005.00000000000-01\n");
    }

    SECTION("check reading") {
        prod::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        prod probe_l(lines);

        CHECK(long(probe_l.PID) == 17);
        CHECK(long(probe_l.MID) == 23);
        CHECK(double(probe_l.A) == 42.6);
        CHECK(double(probe_l.J) == 17.92);
        CHECK(double(probe_l.C) == 4.2356);
        CHECK(double(probe_l.NSM) == .5);
    }
}

TEST_CASE("BDF PROD roundtrip test (minimal)", "[bdf_prod]") {
    prod::reset();
    ostringstream test;

    long PID{17};
    long MID{23};
    double A{42.6};

    prod probe(&PID, &MID, &A);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
              "PROD          17      234.260+01\n");
    }

    SECTION("check reading") {
        prod::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        prod probe_l(lines);

        CHECK(long(probe_l.PID) == 17);
        CHECK(long(probe_l.MID) == 23);
        CHECK(double(probe_l.A) == 42.6);
        CHECK_FALSE(bool(probe_l.J));
        CHECK_FALSE(bool(probe_l.C));
        CHECK_FALSE(bool(probe_l.NSM));
    }
}

TEST_CASE("BDF PROD roundtrip test (reuse)", "[bdf_prod]") {
    pbarl::reset();

    ostringstream test;

    long PID{17};
    long MID{23};
    double A{42.6};
    double J{17.92};
    double C{4.235};
    double NSM{.5};

    prod probe;
    test << probe;
    test << probe(&PID, &MID, &A, &J, &C, &NSM);

    SECTION("check output") {
        CHECK(test.str() ==
              "PROD          17      234.260+011.792+014.235+005.000-01\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        prod probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 17);
        CHECK(long(probe_l.MID) == 23);
        CHECK(double(probe_l.A) == 42.6);
        CHECK(double(probe_l.J) == 17.92);
        CHECK(double(probe_l.C) == 4.235);
        CHECK(double(probe_l.NSM) == .5);
    }
}

TEST_CASE("BDF PROD roundtrip test (A only)", "[bdf_prod]") {
    prod::reset();
    ostringstream test;

    long PID{17};
    long MID{23};
    double A{42.6};

    prod probe(&PID, &MID, &A);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PROD          17      234.260+01\n");
    }

    SECTION("check reading") {
        prod::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        prod probe_l(lines);

        CHECK(long(probe_l.PID) == 17);
        CHECK(long(probe_l.MID) == 23);
        CHECK(double(probe_l.A) == 42.6);
        CHECK_FALSE(bool(probe_l.J));
        CHECK(double(probe_l.C) == 0.);
        CHECK_FALSE(bool(probe_l.NSM));
    }
}

TEST_CASE("BDF PROD roundtrip test (A only) (reuse)", "[bdf_prod]") {
    pbarl::reset();

    ostringstream test;

    long PID{17};
    long MID{23};
    double A{42.6};

    prod probe;
    test << probe;
    test << probe(&PID, &MID, &A);

    SECTION("check output") {
        CHECK(test.str() ==
              "PROD          17      234.260+01\n");
    }

    SECTION("check reading") {
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        card::card_split(data, lines);
        prod probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 17);
        CHECK(long(probe_l.MID) == 23);
        CHECK(double(probe_l.A) == 42.6);
        CHECK_FALSE(bool(probe_l.J));
        CHECK(double(probe_l.C) == 0.);
        CHECK_FALSE(bool(probe_l.NSM));
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
