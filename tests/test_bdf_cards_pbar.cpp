/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBAR` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_test_bdf_cards_pbar[]) =
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
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF PBAR definitions: Free Field Format (generic).", "[bdf_pbar]") {
    pbar::reset();

    std::list<std::string> const data({
            "PBAR,1,2,3.,4.,5.,6.,7.,,9.,10.,11.,12.,13.,14.,15.,16.,17.,18.,19.\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbar probe(lines);

    CHECK((long)probe.PID == 1);
    CHECK((long)probe.MID == 2);
    CHECK((double)probe.A == 3.);
    CHECK((double)probe.I1 == 4.);
    CHECK((double)probe.I2 == 5.);
    CHECK((double)probe.J == 6.);
    CHECK((double)probe.NSM == 7.);
    CHECK((double)probe.C1 == 9.);
    CHECK((double)probe.C2 == 10.);
    CHECK((double)probe.D1 == 11.);
    CHECK((double)probe.D2 == 12.);
    CHECK((double)probe.E1 == 13.);
    CHECK((double)probe.E2 == 14.);
    CHECK((double)probe.F1 == 15.);
    CHECK((double)probe.F2 == 16.);
    CHECK((double)probe.K1 == 17.);
    CHECK((double)probe.K2 == 18.);
    CHECK((double)probe.I12 == 19.);
}


TEST_CASE("BDF PBAR definitions: Small Field Format 1.", "[bdf_pbar]") {

    std::list<std::string> const data({
            "PBAR    4000001 3       1.046+4 9.369+7 1.694+6 1.316+6\n",
            "                        6.856+6\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbar probe(lines);

    CHECK((long)probe.PID == 4000001);
    CHECK((long)probe.MID == 3);
    CHECK((double)probe.A == 10460.);
    CHECK((double)probe.I1 == 93690000.);
    CHECK((double)probe.I2 == 1694000.);
    CHECK((double)probe.J == 1316000.);
    CHECK((double)probe.NSM == 0.);
    CHECK((double)probe.C1 == 0.);
    CHECK((double)probe.C2 == 0.);
    CHECK((double)probe.D1 == 6.856e6);
    CHECK((double)probe.D2 == 0.);
    CHECK((double)probe.E1 == 0.);
    CHECK((double)probe.E2 == 0.);
    CHECK((double)probe.F1 == 0.);
    CHECK((double)probe.F2 == 0.);
    CHECK_FALSE(bool(probe.K1));
    CHECK_FALSE(bool(probe.K2));
    CHECK((double)probe.I12 == 0.);
}

TEST_CASE("BDF PBAR definitions: Small Field Format 2.", "[bdf_pbar]") {

    pbar::reset();

    std::list<std::string> const data({
            // 234567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567
            "PBAR          29       6     2.9            5.97                                \n",
                "                             2.0     4.0                                        \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbar probe(lines);

    CHECK((long)probe.PID == 29);
    CHECK((long)probe.MID == 6);
    CHECK((double)probe.A == 2.9);
    CHECK((double)probe.I1 == 0.);
    CHECK((double)probe.I2 == 5.97);
    CHECK((double)probe.J == 0.);
    CHECK((double)probe.NSM == 0.);
    CHECK((double)probe.C1 == 0.);
    CHECK((double)probe.C2 == 0.);
    CHECK((double)probe.D1 == 2.);
    CHECK((double)probe.D2 == 4.);
    CHECK((double)probe.E1 == 0.);
    CHECK((double)probe.E2 == 0.);
    CHECK((double)probe.F1 == 0.);
    CHECK((double)probe.F2 == 0.);
    CHECK_FALSE(bool(probe.K1));
    CHECK_FALSE(bool(probe.K2));
    CHECK((double)probe.I12 == 0.);
}

TEST_CASE("BDF PBAR roundtrip test", "[bdf_pbar]") {
    pbar::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    double A{1.};
    double I1{2.};
    double I2{3.};
    double J{5.};
    double NSM{6.};
    double C1{7.};
    double C2{8.};
    double D1{9.};
    double D2{10.};
    double E1{11.};
    double E2{12.};
    double F1{13.};
    double F2{14.};
    double K1{17.};
    double K2{18.};
    double I12{4.};

    pbar probe(&PID, &MID, &A, &I1, &I2, &J, &NSM,
               &C1, &C2, &D1, &D2, &E1, &E2, &F1, &F2,
               &K1, &K2, &I12);
    test << probe;

    SECTION("check output") {
        pbar::reset();
        CHECK(test.str() ==
              "PBAR        7869  1040101.000+002.000+003.000+005.000+006.000+007.000+00\n"
              "        8.000+009.000+001.000+011.100+011.200+011.300+011.400+011.700+01\n"
              "        1.800+014.000+00\n");
    }

    SECTION("check reading") {
        pbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbar probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(double(probe.A) == 1.);
        CHECK(double(probe.I1) == 2.);
        CHECK(double(probe.I2) == 3.);
        CHECK(double(probe.J) == 5.);
        CHECK(double(probe.NSM) == 6.);
        CHECK(double(probe.C1) == 7.);
        CHECK(double(probe.C2) == 8.);
        CHECK(double(probe.D1) == 9.);
        CHECK(double(probe.D2) == 10.);
        CHECK(double(probe.E1) == 11.);
        CHECK(double(probe.E2) == 12.);
        CHECK(double(probe.F1) == 13.);
        CHECK(double(probe.F2) == 14.);
        CHECK(double(probe.K1) == 17.);
        CHECK(double(probe.K2) == 18.);
        CHECK(double(probe.I12) == 4.);
    }
}

TEST_CASE("BDF PBAR roundtrip test (reuse)", "[bdf_pbar]") {
    pbar::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    double A{1.};
    double I1{2.};
    double I2{3.};
    double J{5.};
    double NSM{6.};
    double C1{7.};
    double C2{8.};
    double D1{9.};
    double D2{10.};
    double E1{11.};
    double E2{12.};
    double F1{13.};
    double F2{14.};
    double K1{17.};
    double K2{18.};
    double I12{4.};

    pbar probe;
    test << probe;
    test << probe(&PID, &MID, &A, &I1, &I2, &J, &NSM,
                  &C1, &C2, &D1, &D2, &E1, &E2, &F1, &F2,
                  &K1, &K2, &I12);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBAR        7869  1040101.000+002.000+003.000+005.000+006.000+007.000+00\n"
              "        8.000+009.000+001.000+011.100+011.200+011.300+011.400+011.700+01\n"
              "        1.800+014.000+00\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbar probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(double(probe.A) == 1.);
        CHECK(double(probe.I1) == 2.);
        CHECK(double(probe.I2) == 3.);
        CHECK(double(probe.J) == 5.);
        CHECK(double(probe.NSM) == 6.);
        CHECK(double(probe.C1) == 7.);
        CHECK(double(probe.C2) == 8.);
        CHECK(double(probe.D1) == 9.);
        CHECK(double(probe.D2) == 10.);
        CHECK(double(probe.E1) == 11.);
        CHECK(double(probe.E2) == 12.);
        CHECK(double(probe.F1) == 13.);
        CHECK(double(probe.F2) == 14.);
        CHECK(double(probe.K1) == 17.);
        CHECK(double(probe.K2) == 18.);
        CHECK(double(probe.I12) == 4.);
    }
}

TEST_CASE("BDF PBAR roundtrip test minimal", "[bdf_pbar]") {
    pbar::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    double A{1.};
    double I1{2.};
    double I2{3.};

    pbar probe(&PID, &MID, &A, &I1, &I2);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBAR        7869  1040101.000+002.000+003.000+00\n");
    }

    SECTION("check reading") {
        pbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbar probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(double(probe.A) == 1.);
        CHECK(double(probe.I1) == 2.);
        CHECK(double(probe.I2) == 3.);
        CHECK_FALSE(bool(probe.J));
        CHECK_FALSE(bool(probe.NSM));
        CHECK_FALSE(bool(probe.C1));
        CHECK_FALSE(bool(probe.C2));
        CHECK_FALSE(bool(probe.D1));
        CHECK_FALSE(bool(probe.D2));
        CHECK_FALSE(bool(probe.E1));
        CHECK_FALSE(bool(probe.E2));
        CHECK_FALSE(bool(probe.F1));
        CHECK_FALSE(bool(probe.F2));
        CHECK_FALSE(bool(probe.K1));
        CHECK_FALSE(bool(probe.K2));
        CHECK_FALSE(bool(probe.I12));
    }
}

TEST_CASE("BDF PBAR roundtrip test minimal (reuse)", "[bdf_pbar]") {
    pbar::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    double A{1.};
    double I1{2.};
    double I2{3.};

    pbar probe;
    test << probe;
    test << probe(&PID, &MID, &A, &I1, &I2);

    SECTION("check output") {
        pbar::reset();
        CHECK(test.str() ==
              "PBAR        7869  1040101.000+002.000+003.000+00\n");
    }

    SECTION("check reading") {
        pbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbar probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK(double(probe.A) == 1.);
        CHECK(double(probe.I1) == 2.);
        CHECK(double(probe.I2) == 3.);
        CHECK_FALSE(bool(probe.J));
        CHECK_FALSE(bool(probe.NSM));
        CHECK_FALSE(bool(probe.C1));
        CHECK_FALSE(bool(probe.C2));
        CHECK_FALSE(bool(probe.D1));
        CHECK_FALSE(bool(probe.D2));
        CHECK_FALSE(bool(probe.E1));
        CHECK_FALSE(bool(probe.E2));
        CHECK_FALSE(bool(probe.F1));
        CHECK_FALSE(bool(probe.F2));
        CHECK_FALSE(bool(probe.K1));
        CHECK_FALSE(bool(probe.K2));
        CHECK_FALSE(bool(probe.I12));
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
