/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBEAM` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_test_bdf_cards_pbeam[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"

#include "catch_vector_helper.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF PBEAM definitions (Small Field Format).", "[bdf_pbeam]") {

    std::list<std::string> data({
            //       PID     MID     A       I1      I2      I12     J
            // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
            "PBEAM    4000001       3 1.046+4 9.369+7 1.694+6 6.856+6 1.316+6        \n",
            "         \n",
            "         NO       1.+0\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeam probe(lines);

    CAPTURE( data.front() );

    CHECK(long(probe.PID) == 4000001);
    CHECK(long(probe.MID) == 3);
    CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
               IsEqual(vector<double>({10460., 10460.})));
    CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
               IsEqual(vector<double>({93690000., 93690000.})));
    CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
               IsEqual(vector<double>({1694000., 1694000.})));
    CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
               IsEqual(vector<double>({6.856e6, 6.856e6})));
    CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
               IsEqual(vector<double>({1.316e6, 1.316e6})));
    CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<std::string>(1, "NO")));
    CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
               IsEqual(vector<double>({1.})));
}

TEST_CASE("BDF PBEAM definitions (Small Field Format 2).", "[bdf_pbeam]") {
    pbeam::reset();

    std::list<std::string> data({
            //       PID     MID     A       I1      I2      I12     J
            // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
            "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n",
            "         \n",
            "         NO       1.+0\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeam probe(lines);

    CAPTURE( data.front() );

    CHECK(long(probe.PID) == 4000001);
    CHECK(long(probe.MID) == 3);
    CHECK_THAT(vector<double>(probe.A.begin(),probe.A.end()),
               IsEqual(vector<double>({10460., 10460.})));
    CHECK_THAT(vector<double>(probe.I1.begin(),probe.I1.end()),
               IsEqual(vector<double>({93690000., 93690000.})));
    CHECK_THAT(vector<double>(probe.I2.begin(),probe.I2.end()),
               IsEqual(vector<double>({1694000., 1694000.})));
    CHECK_THAT(vector<double>(probe.I12.begin(),probe.I12.end()),
               IsEqual(vector<double>({6.856e6, 6.856e6})));
    CHECK_THAT(vector<double>(probe.J.begin(),probe.J.end()),
               IsEqual(vector<double>({1.316e6, 1.316e6})));
    CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "NO")));
    CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
               IsEqual(vector<double>({1.})));
}

TEST_CASE("BDF PBEAM definitions (Free Field Format 1).", "[bdf_pbeam]") {

    std::list<std::string> data({
            "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,\n",
            ",NO,1.\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeam probe(lines);

    CAPTURE( data.front() );

    CHECK(long(probe.PID) == 1);
    CHECK(long(probe.MID) == 2);
    CHECK_THAT(vector<double>(probe.A  .begin(), probe.A  .end()),
               IsEqual(vector<double>({3., 3.})));
    CHECK_THAT(vector<double>(probe.I1 .begin(), probe.I1 .end()),
               IsEqual(vector<double>({4., 4.})));
    CHECK_THAT(vector<double>(probe.I2 .begin(), probe.I2 .end()),
               IsEqual(vector<double>({5., 5.})));
    CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
               IsEqual(vector<double>({6., 6.})));
    CHECK_THAT(vector<double>(probe.J  .begin(), probe.J  .end()),
               IsEqual(vector<double>({7., 7.})));
    CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
               IsEqual(vector<double>({8., 8.})));
    CHECK_THAT(vector<double>(probe.C1 .begin(), probe.C1 .end()),
               IsEqual(vector<double>({9., 0.})));
    CHECK_THAT(vector<double>(probe.C2 .begin(), probe.C2 .end()),
               IsEqual(vector<double>({10., 0.})));
    CHECK_THAT(vector<double>(probe.D1 .begin(), probe.D1 .end()),
               IsEqual(vector<double>({11., 0.})));
    CHECK_THAT(vector<double>(probe.D2 .begin(), probe.D2 .end()),
               IsEqual(vector<double>({12., 0.})));
    CHECK_THAT(vector<double>(probe.E1 .begin(), probe.E1 .end()),
               IsEqual(vector<double>({13., 0.})));
    CHECK_THAT(vector<double>(probe.E2 .begin(), probe.E2 .end()),
               IsEqual(vector<double>({14., 0.})));
    CHECK_THAT(vector<double>(probe.F1 .begin(), probe.F1 .end()),
               IsEqual(vector<double>({15., 0.})));
    CHECK_THAT(vector<double>(probe.F2 .begin(), probe.F2 .end()),
               IsEqual(vector<double>({16., 0.})));
    CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "NO")));
    CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
               IsEqual(vector<double>({1.})));
}

TEST_CASE("BDF PBEAM definitions (Free Field Format 2).", "[bdf_pbeam]") {
    pbeam::reset();

    std::list<std::string> data({
            "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,\n",
            ",YES,.5,19.,20.,21.,22.,23.,24.,25.,26.,27.,28.,29.,30.,31.,32.,\n",
            ",NO,1.,35.,36.,37.,38.,39.,40.,41.,42.,43.,44.,45.,46.,47.,48.,\n",
            ",49.,50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.,61.,62.,63.,64.\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);

    CHECK(lines.size() == 65);
    pbeam probe(lines);

    CAPTURE( data.front() );

    CHECK(long(probe.PID) == 1);
    CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>({"YES", "NO"})));
    CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
               IsEqual(vector<double>({.5, 1.})));
    CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
               IsEqual(vector<double>({3., 19., 35.})));
    CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
               IsEqual(vector<double>({4., 20., 36.})));
    CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
               IsEqual(vector<double>({5., 21., 37.})));
    CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
               IsEqual(vector<double>({6., 22., 38.})));
    CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
               IsEqual(vector<double>({7., 23., 39.})));
    CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
               IsEqual(vector<double>({8., 24., 40.})));
    CHECK_THAT(vector<double>(probe.C1.begin(), probe.C1.end()),
               IsEqual(vector<double>({9., 25., 41.})));
    CHECK_THAT(vector<double>(probe.C2.begin(), probe.C2.end()),
               IsEqual(vector<double>({10., 26., 42.})));
    CHECK_THAT(vector<double>(probe.D1.begin(), probe.D1.end()),
               IsEqual(vector<double>({11., 27., 43.})));
    CHECK_THAT(vector<double>(probe.D2.begin(), probe.D2.end()),
               IsEqual(vector<double>({12., 28., 44.})));
    CHECK_THAT(vector<double>(probe.E1.begin(), probe.E1.end()),
               IsEqual(vector<double>({13., 29., 45.})));
    CHECK_THAT(vector<double>(probe.E2.begin(), probe.E2.end()),
               IsEqual(vector<double>({14., 30., 46.})));
    CHECK_THAT(vector<double>(probe.F1.begin(), probe.F1.end()),
               IsEqual(vector<double>({15., 31., 47.})));
    CHECK_THAT(vector<double>(probe.F2.begin(), probe.F2.end()),
               IsEqual(vector<double>({16., 32., 48.})));
    CHECK(double(probe.K1) == 49);
    CHECK(double(probe.K2) == 50);
    CHECK(double(probe.S1) == 51);
    CHECK(double(probe.S2) == 52);
    CHECK(double(probe.NSI_A) == 53);
    CHECK(double(probe.NSI_B) == 54);
    CHECK(double(probe.CW_A) == 55);
    CHECK(double(probe.CW_B) == 56);
    CHECK(double(probe.M1_A) == 57);
    CHECK(double(probe.M2_A) == 58);
    CHECK(double(probe.M1_B) == 59);
    CHECK(double(probe.M2_B) == 60);
    CHECK(double(probe.N1_A) == 61);
    CHECK(double(probe.N2_A) == 62);
    CHECK(double(probe.N1_B) == 63);
    CHECK(double(probe.N2_B) == 64);
}


TEST_CASE("BDF PBEAM definitions (Free Field Format 3).", "[bdf_pbeam]") {

    std::list<std::string> data({
            "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,"
            "YES,18.,19.,20.,21.,22.,23.,24.,25.,26.,27.,28.,29.,30.,31.,32.,"
            "NO,34.,35.,36.,37.,38.,39.,40.,41.,42.,43.,44.,45.,46.,47.,48.,"
            "49.,50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.,61.,62.,63.,64."
            ",65.\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);

    CAPTURE(data.front());
    CHECK(lines.size() == 66);
    CHECK_THROWS(pbeam(lines));
}

TEST_CASE("BDF PBEAM definitions (Tapered Beam).", "[bdf_pbeam]") {

    std::list<std::string> data({
            // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
            "PBEAM         39       6     2.9     3.5    5.97                        \n",
            "                             2.0    -4.0                                \n",
            "             YES     1.0     5.3    56.2    78.6                        \n",
            "                             2.5    -5.0                                \n",
            "                             1.1             2.1            0.21        \n",
            "                                             0.5             0.0        \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeam probe(lines);

    CAPTURE( data.front() );

    CHECK(long(probe.PID) == 39);
    CHECK(long(probe.MID) == 6);
    CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
               IsEqual(vector<double>({2.9, 5.3})));
    CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
               IsEqual(vector<double>({3.5, 56.2})));
    CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
               IsEqual(vector<double>({5.97, 78.6})));
    CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.C1.begin(), probe.C1.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.C2.begin(), probe.C2.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.D1.begin(), probe.D1.end()),
               IsEqual(vector<double>({2., 2.5})));
    CHECK_THAT(vector<double>(probe.D2.begin(), probe.D2.end()),
               IsEqual(vector<double>({-4., -5.})));
    CHECK_THAT(vector<double>(probe.E1.begin(), probe.E1.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.E2.begin(), probe.E2.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.F1.begin(), probe.F1.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<double>(probe.F2.begin(), probe.F2.end()),
               IsEqual(vector<double>({0., 0.})));
    CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "YES")));
    CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
               IsEqual(vector<double>({1.})));
    CHECK(double(probe.K1) == 1.);
    CHECK(double(probe.K2) == 1.);
    CHECK(double(probe.S1) == 1.1);
    CHECK(double(probe.S2) == 0.);
    CHECK(double(probe.NSI_A) == 2.1);
    CHECK_FALSE(bool(probe.NSI_B));
    CHECK(double(probe.CW_A) == 0.21);
    CHECK_FALSE(bool(probe.CW_B));
    CHECK(double(probe.M1_A) == 0.);
    CHECK(double(probe.M2_A) == 0.);
    CHECK_FALSE(bool(probe.M1_B));
    CHECK_FALSE(bool(probe.M2_B));
    CHECK(double(probe.N1_A) == 0.5);
    CHECK(double(probe.N2_A) == 0.);
    CHECK(double(probe.N1_B) == 0.0);
    CHECK_FALSE(bool(probe.N2_B));
}

TEST_CASE("BDF PBEAM definitions (Patran import error 20170925 1).", "[bdf_pbeam]") {

    std::list<std::string> data({
            // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
            "PBEAM  *              41               51.84282217136-051.25369392769+02 +003SS3\n",
            "*+003SS31.25369392769+021.25369392769+02                1.25369392769+01 +003SS4\n",
            "*+003SS41.25369392769+011.25369392769+011.25369392769+01                 +003SS5\n",
            "*+003SS5                                                                 +003SS6\n",
            "*+003SS5YESA            1.00000000000+00                                 +003SS6\n",
            "*+003SS5                                                                 +003SS6\n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeam probe(lines);

    CAPTURE( data.front() );

    CHECK(long(probe.PID) == 41);
    CHECK(long(probe.MID) == 5);
}

TEST_CASE("BDF PBEAM definitions (Patran import error 20170925 2).", "[bdf_pbeam]") {

    std::list<std::string> data({
            // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
            //                    PID             MID            A(A)           I1(A)
            "PBEAM  *              42               51.86736295278-051.27836735889+02 +003UPT\n",
            //                  I2(A)          I12(A)            J(A)          NSM(A)
            "*+003UPT1.27836735889+021.27836735889+02                1.27836735889+01 +003UPU\n",
            //                  C1(A)           C2(A)           D1(A)           D2(A)
            "*+003UPU1.27836735889+011.27836735889+011.27836735889+01                 +003UPV\n",
            //                  E1(A)           E2(A)           F1(A)           F2(A)
            "*+003UPV                                                                 +003UPW\n",
            //                     SO            X/XB
            "*+003SS5YESA            1.00000000000+00                                 +003SS6\n",
            "*+003SS5                                                                 +003SS6\n"});
   std::list<std::string> lines;
    __base::card::card_split(data, lines);
    pbeam probe(lines);

    CAPTURE( data.front() );

    CHECK(long(probe.PID) == 42);
    CHECK(long(probe.MID) == 5);
}

    TEST_CASE("BDF PBEAM roundtrip test", "[bdf_pbeam]") {
    pbeam::reset();
    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 2.};
    std::vector<double> I1{2., 3.};
    std::vector<double> I2{3., 4.};
    std::vector<double> I12{4., 5.};
    std::vector<double> J{5., 6.};
    std::vector<double> NSM{6., 7.};
    std::vector<double> C1{7., 8.};
    std::vector<double> C2{8., 9.};
    std::vector<double> D1{9., 10.};
    std::vector<double> D2{10., 11.};
    std::vector<double> E1{11., 12.};
    std::vector<double> E2{12., 13.};
    std::vector<double> F1{13., 14.};
    std::vector<double> F2{14., 15.};
    std::vector<std::string> SO{"YESA"};
    std::vector<double> X_XB{16.};
    double K1{17.};
    double K2{18.};
    double S1{19.};
    double S2{20.};
    double NSI_A{21.};
    double NSI_B{22.};
    double CW_A{23.};
    double CW_B{24.};
    double M1_A{25.};
    double M2_A{26.};
    double M1_B{27.};
    double M2_B{28.};
    double N1_A{29.};
    double N2_A{30.};
    double N1_B{31.};
    double N2_B{32.};

    pbeam probe(&PID, &MID, &A, &I1, &I2, &I12, &J, &NSM,
                &C1, &C2, &D1, &D2, &E1, &E2, &F1, &F2,
                &SO, &X_XB,
                &K1, &K2, &S1, &S2, &NSI_A, &NSI_B, &CW_A, &CW_B,
                &M1_A, &M2_A, &M1_B, &M2_B, &N1_A, &N2_A, &N1_B, &N2_B);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+004.000+005.000+006.000+00\n"
              "        7.000+008.000+009.000+001.000+011.100+011.200+011.300+011.400+01\n"
              "        YESA    1.600+012.000+003.000+004.000+005.000+006.000+007.000+00\n"
              "        8.000+009.000+001.000+011.100+011.200+011.300+011.400+011.500+01\n"
              "        1.700+011.800+011.900+012.000+012.100+012.200+012.300+012.400+01\n"
              "        2.500+012.600+012.700+012.800+012.900+013.000+013.100+013.200+01\n");
    }

    SECTION("check reading") {
        pbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
 IsEqual(std::vector<double>({1., 2.})));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
 IsEqual(std::vector<double>({2., 3.})));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
 IsEqual(std::vector<double>({3., 4.})));
        CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
 IsEqual(std::vector<double>({4., 5.})));
        CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
 IsEqual(std::vector<double>({5., 6.})));
        CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
 IsEqual(std::vector<double>({6., 7.})));
        CHECK_THAT(vector<double>(probe.C1.begin(), probe.C1.end()),
 IsEqual(std::vector<double>({7., 8.})));
        CHECK_THAT(vector<double>(probe.C2.begin(), probe.C2.end()),
 IsEqual(std::vector<double>({8., 9.})));
        CHECK_THAT(vector<double>(probe.D1.begin(), probe.D1.end()),
 IsEqual(std::vector<double>({9., 10.})));
        CHECK_THAT(vector<double>(probe.D2.begin(), probe.D2.end()),
 IsEqual(std::vector<double>({10., 11.})));
        CHECK_THAT(vector<double>(probe.E1.begin(), probe.E1.end()),
 IsEqual(std::vector<double>({11., 12.})));
        CHECK_THAT(vector<double>(probe.E2.begin(), probe.E2.end()),
 IsEqual(std::vector<double>({12., 13.})));
        CHECK_THAT(vector<double>(probe.F1.begin(), probe.F1.end()),
 IsEqual(std::vector<double>({13., 14.})));
        CHECK_THAT(vector<double>(probe.F2.begin(), probe.F2.end()),
 IsEqual(std::vector<double>({14., 15.})));
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
                   IsEqual(std::vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
 IsEqual(std::vector<double> {16.}));
        CHECK(double(probe.K1) == 17.);
        CHECK(double(probe.K2) == 18.);
        CHECK(double(probe.S1) == 19.);
        CHECK(double(probe.S2) == 20.);
        CHECK(double(probe.NSI_A) == 21.);
        CHECK(double(probe.NSI_B) == 22.);
        CHECK(double(probe.CW_A) == 23.);
        CHECK(double(probe.CW_B) == 24.);
        CHECK(double(probe.M1_A) == 25.);
        CHECK(double(probe.M2_A) == 26.);
        CHECK(double(probe.M1_B) == 27.);
        CHECK(double(probe.M2_B) == 28.);
        CHECK(double(probe.N1_A) == 29.);
        CHECK(double(probe.N2_A) == 30.);
        CHECK(double(probe.N1_B) == 31.);
        CHECK(double(probe.N2_B) == 32.);
    }
}

TEST_CASE("BDF PBEAM roundtrip test (reuse)", "[bdf_pbeam]") {
    pbarl::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 2.};
    std::vector<double> I1{2., 3.};
    std::vector<double> I2{3., 4.};
    std::vector<double> I12{4., 5.};
    std::vector<double> J{5., 6.};
    std::vector<double> NSM{6., 7.};
    std::vector<double> C1{7., 8.};
    std::vector<double> C2{8., 9.};
    std::vector<double> D1{9., 10.};
    std::vector<double> D2{10., 11.};
    std::vector<double> E1{11., 12.};
    std::vector<double> E2{12., 13.};
    std::vector<double> F1{13., 14.};
    std::vector<double> F2{14., 15.};
    std::vector<std::string> SO{"YESA"};
    std::vector<double> X_XB{1.};
    double K1{17.};
    double K2{18.};
    double S1{19.};
    double S2{20.};
    double NSI_A{21.};
    double NSI_B{22.};
    double CW_A{23.};
    double CW_B{24.};
    double M1_A{25.};
    double M2_A{26.};
    double M1_B{27.};
    double M2_B{28.};
    double N1_A{29.};
    double N2_A{30.};
    double N1_B{31.};
    double N2_B{32.};

    pbeam probe;
    test << probe;
    test << probe(&PID, &MID, &A, &I1, &I2, &I12, &J, &NSM,
                  &C1, &C2, &D1, &D2, &E1, &E2, &F1, &F2,
                  &SO, &X_XB,
                  &K1, &K2, &S1, &S2, &NSI_A, &NSI_B, &CW_A, &CW_B,
                  &M1_A, &M2_A, &M1_B, &M2_B, &N1_A, &N2_A, &N1_B, &N2_B);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+004.000+005.000+006.000+00\n"
              "        7.000+008.000+009.000+001.000+011.100+011.200+011.300+011.400+01\n"
              "        YESA    1.000+002.000+003.000+004.000+005.000+006.000+007.000+00\n"
              "        8.000+009.000+001.000+011.100+011.200+011.300+011.400+011.500+01\n"
              "        1.700+011.800+011.900+012.000+012.100+012.200+012.300+012.400+01\n"
              "        2.500+012.600+012.700+012.800+012.900+013.000+013.100+013.200+01\n");
    }

    SECTION("check reading") {
        pbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
 IsEqual(std::vector<double>({1., 2.})));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
 IsEqual(std::vector<double>({2., 3.})));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
 IsEqual(std::vector<double>({3., 4.})));
        CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
 IsEqual(std::vector<double>({4., 5.})));
        CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
 IsEqual(std::vector<double>({5., 6.})));
        CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
 IsEqual(std::vector<double>({6., 7.})));
        CHECK_THAT(vector<double>(probe.C1.begin(), probe.C1.end()),
 IsEqual(std::vector<double>({7., 8.})));
        CHECK_THAT(vector<double>(probe.C2.begin(), probe.C2.end()),
 IsEqual(std::vector<double>({8., 9.})));
        CHECK_THAT(vector<double>(probe.D1.begin(), probe.D1.end()),
 IsEqual(std::vector<double>({9., 10.})));
        CHECK_THAT(vector<double>(probe.D2.begin(), probe.D2.end()),
 IsEqual(std::vector<double>({10., 11.})));
        CHECK_THAT(vector<double>(probe.E1.begin(), probe.E1.end()),
 IsEqual(std::vector<double>({11., 12.})));
        CHECK_THAT(vector<double>(probe.E2.begin(), probe.E2.end()),
 IsEqual(std::vector<double>({12., 13.})));
        CHECK_THAT(vector<double>(probe.F1.begin(), probe.F1.end()),
 IsEqual(std::vector<double>({13., 14.})));
        CHECK_THAT(vector<double>(probe.F2.begin(), probe.F2.end()),
 IsEqual(std::vector<double>({14., 15.})));
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
 IsEqual(std::vector<double>(1, 1.)));
        CHECK(double(probe.K1) == 17.);
        CHECK(double(probe.K2) == 18.);
        CHECK(double(probe.S1) == 19.);
        CHECK(double(probe.S2) == 20.);
        CHECK(double(probe.NSI_A) == 21.);
        CHECK(double(probe.NSI_B) == 22.);
        CHECK(double(probe.CW_A) == 23.);
        CHECK(double(probe.CW_B) == 24.);
        CHECK(double(probe.M1_A) == 25.);
        CHECK(double(probe.M2_A) == 26.);
        CHECK(double(probe.M1_B) == 27.);
        CHECK(double(probe.M2_B) == 28.);
        CHECK(double(probe.N1_A) == 29.);
        CHECK(double(probe.N2_A) == 30.);
        CHECK(double(probe.N1_B) == 31.);
        CHECK(double(probe.N2_B) == 32.);
    }
}

TEST_CASE("BDF PBEAM roundtrip test (no taper)", "[bdf_pbeam]") {
    pbeam::reset();
    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 1.};
    std::vector<double> I1{2., 2.};
    std::vector<double> I2{3., 3.};
    std::vector<double> I12{4., 4.};
    std::vector<double> J{5., 5.};
    std::vector<double> NSM{6., 6.};
    std::vector<double> C1{7., 7.};
    std::vector<double> C2{8., 8.};
    std::vector<double> D1{9., 9.};
    std::vector<double> D2{10., 10.};
    std::vector<double> E1{11., 11.};
    std::vector<double> E2{12., 12.};
    std::vector<double> F1{13., 13.};
    std::vector<double> F2{14., 14.};
    std::vector<std::string> SO(1, "YESA");
    std::vector<double> X_XB(1, 1.);
    double K1{17.};
    double K2{18.};
    double S1{19.};
    double S2{20.};
    double NSI_A{21.};
    double NSI_B{22.};
    double CW_A{23.};
    double CW_B{24.};
    double M1_A{25.};
    double M2_A{26.};
    double M1_B{27.};
    double M2_B{28.};
    double N1_A{29.};
    double N2_A{30.};
    double N1_B{31.};
    double N2_B{32.};

    pbeam probe(&PID, &MID, &A, &I1, &I2, &I12, &J, &NSM,
                &C1, &C2, &D1, &D2, &E1, &E2, &F1, &F2,
                &SO, &X_XB,
                &K1, &K2, &S1, &S2, &NSI_A, &NSI_B, &CW_A, &CW_B,
                &M1_A, &M2_A, &M1_B, &M2_B, &N1_A, &N2_A, &N1_B, &N2_B);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+004.000+005.000+006.000+00\n"
              "        7.000+008.000+009.000+001.000+011.100+011.200+011.300+011.400+01\n"
              "        YESA    1.000+00                                                \n"
              "                                                                        \n"
              "        1.700+011.800+011.900+012.000+012.100+012.200+012.300+012.400+01\n"
              "        2.500+012.600+012.700+012.800+012.900+013.000+013.100+013.200+01\n");
    }

    SECTION("check reading") {
        pbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
 IsEqual(std::vector<double>({1., 1.})));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
 IsEqual(std::vector<double>({2., 2.})));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
 IsEqual(std::vector<double>({3., 3.})));
        CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
 IsEqual(std::vector<double>({4., 4.})));
        CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
 IsEqual(std::vector<double>({5., 5.})));
        CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
 IsEqual(std::vector<double>({6., 6.})));
        CHECK_THAT(vector<double>(probe.C1.begin(), probe.C1.end()),
 IsEqual(std::vector<double>({7., 7.})));
        CHECK_THAT(vector<double>(probe.C2.begin(), probe.C2.end()),
 IsEqual(std::vector<double>({8., 8.})));
        CHECK_THAT(vector<double>(probe.D1.begin(), probe.D1.end()),
 IsEqual(std::vector<double>({9., 9.})));
        CHECK_THAT(vector<double>(probe.D2.begin(), probe.D2.end()),
 IsEqual(std::vector<double>({10., 10})));
        CHECK_THAT(vector<double>(probe.E1.begin(), probe.E1.end()),
 IsEqual(std::vector<double>({11., 11})));
        CHECK_THAT(vector<double>(probe.E2.begin(), probe.E2.end()),
 IsEqual(std::vector<double>({12., 12})));
        CHECK_THAT(vector<double>(probe.F1.begin(), probe.F1.end()),
 IsEqual(std::vector<double>({13., 13})));
        CHECK_THAT(vector<double>(probe.F2.begin(), probe.F2.end()),
 IsEqual(std::vector<double>({14., 14})));
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
 IsEqual(std::vector<double>({1.})));
        CHECK(double(probe.K1) == 17.);
        CHECK(double(probe.K2) == 18.);
        CHECK(double(probe.S1) == 19.);
        CHECK(double(probe.S2) == 20.);
        CHECK(double(probe.NSI_A) == 21.);
        CHECK(double(probe.NSI_B) == 22.);
        CHECK(double(probe.CW_A) == 23.);
        CHECK(double(probe.CW_B) == 24.);
        CHECK(double(probe.M1_A) == 25.);
        CHECK(double(probe.M2_A) == 26.);
        CHECK(double(probe.M1_B) == 27.);
        CHECK(double(probe.M2_B) == 28.);
        CHECK(double(probe.N1_A) == 29.);
        CHECK(double(probe.N2_A) == 30.);
        CHECK(double(probe.N1_B) == 31.);
        CHECK(double(probe.N2_B) == 32.);
    }
}

TEST_CASE("BDF PBEAM roundtrip test (no taper) (reuse)", "[bdf_pbeam]") {
    pbarl::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 1.};
    std::vector<double> I1{2., 2.};
    std::vector<double> I2{3., 3.};
    std::vector<double> I12{4., 4.};
    std::vector<std::string> SO(1, "YESA");
    std::vector<double> X_XB{1.};
    std::vector<double> J{5., 5.};
    std::vector<double> NSM{6., 6.};
    std::vector<double> C1{7., 7.};
    std::vector<double> C2{8., 8.};
    std::vector<double> D1{9., 9.};
    std::vector<double> D2{10., 10.};
    std::vector<double> E1{11., 11.};
    std::vector<double> E2{12., 12.};
    std::vector<double> F1{13., 13.};
    std::vector<double> F2{14., 14.};
    double K1{17.};
    double K2{18.};
    double S1{19.};
    double S2{20.};
    double NSI_A{21.};
    double NSI_B{22.};
    double CW_A{23.};
    double CW_B{24.};
    double M1_A{25.};
    double M2_A{26.};
    double M1_B{27.};
    double M2_B{28.};
    double N1_A{29.};
    double N2_A{30.};
    double N1_B{31.};
    double N2_B{32.};

    pbeam probe;
    test << probe;
    test << probe(&PID, &MID, &A, &I1, &I2, &I12, &J, &NSM,
                  &C1, &C2, &D1, &D2, &E1, &E2, &F1, &F2,
                  &SO, &X_XB,
                  &K1, &K2, &S1, &S2, &NSI_A, &NSI_B, &CW_A, &CW_B,
                  &M1_A, &M2_A, &M1_B, &M2_B, &N1_A, &N2_A, &N1_B, &N2_B);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+004.000+005.000+006.000+00\n"
              "        7.000+008.000+009.000+001.000+011.100+011.200+011.300+011.400+01\n"
              "        YESA    1.000+00                                                \n"
              "                                                                        \n"
              "        1.700+011.800+011.900+012.000+012.100+012.200+012.300+012.400+01\n"
              "        2.500+012.600+012.700+012.800+012.900+013.000+013.100+013.200+01\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
 IsEqual(std::vector<double>(2, 1.)));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
 IsEqual(std::vector<double>(2, 2.)));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
 IsEqual(std::vector<double>(2, 3.)));
        CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
 IsEqual(std::vector<double>(2, 4.)));
        CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
 IsEqual(std::vector<double>(2, 5.)));
        CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
 IsEqual(std::vector<double>(2, 6.)));
        CHECK_THAT(vector<double>(probe.C1.begin(), probe.C1.end()),
 IsEqual(std::vector<double>(2, 7.)));
        CHECK_THAT(vector<double>(probe.C2.begin(), probe.C2.end()),
 IsEqual(std::vector<double>(2, 8.)));
        CHECK_THAT(vector<double>(probe.D1.begin(), probe.D1.end()),
 IsEqual(std::vector<double>(2, 9.)));
        CHECK_THAT(vector<double>(probe.D2.begin(), probe.D2.end()),
 IsEqual(std::vector<double>(2, 10.)));
        CHECK_THAT(vector<double>(probe.E1.begin(), probe.E1.end()),
 IsEqual(std::vector<double>(2, 11.)));
        CHECK_THAT(vector<double>(probe.E2.begin(), probe.E2.end()),
 IsEqual(std::vector<double>(2, 12.)));
        CHECK_THAT(vector<double>(probe.F1.begin(), probe.F1.end()),
 IsEqual(std::vector<double>(2, 13.)));
        CHECK_THAT(vector<double>(probe.F2.begin(), probe.F2.end()),
 IsEqual(std::vector<double>(2, 14.)));
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
 IsEqual(std::vector<double>(1, 1.)));
        CHECK(double(probe.K1) == 17.);
        CHECK(double(probe.K2) == 18.);
        CHECK(double(probe.S1) == 19.);
        CHECK(double(probe.S2) == 20.);
        CHECK(double(probe.NSI_A) == 21.);
        CHECK(double(probe.NSI_B) == 22.);
        CHECK(double(probe.CW_A) == 23.);
        CHECK(double(probe.CW_B) == 24.);
        CHECK(double(probe.M1_A) == 25.);
        CHECK(double(probe.M2_A) == 26.);
        CHECK(double(probe.M1_B) == 27.);
        CHECK(double(probe.M2_B) == 28.);
        CHECK(double(probe.N1_A) == 29.);
        CHECK(double(probe.N2_A) == 30.);
        CHECK(double(probe.N1_B) == 31.);
        CHECK(double(probe.N2_B) == 32.);
    }
}

TEST_CASE("BDF PBEAM roundtrip test (minimal)", "[bdf_pbeam]") {
    pbeam::reset();
    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 1.};
    std::vector<double> I1{2., 2.};
    std::vector<double> I2{3., 3.};
    std::vector<double> I12{4., 4.};
    std::vector<std::string> SO(1, "YESA");
    std::vector<double> X_XB(1, 1.);

    pbeam probe(&PID, &MID, &A, &I1, &I2, &SO, &X_XB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+00                        \n"
              "                                                                        \n"
              "        YESA    1.000+00\n");
    }

    SECTION("check reading") {
        pbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
 IsEqual(std::vector<double>({1., 1.})));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
 IsEqual(std::vector<double>({2., 2.})));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
 IsEqual(std::vector<double>({3., 3.})));
        CHECK(probe.I12.size() == 0);
        CHECK(probe.J.size() == 0);
        CHECK(probe.NSM.size() == 0);
        CHECK(probe.C1.size() == 0);
        CHECK(probe.C2.size() == 0);
        CHECK(probe.D1.size() == 0);
        CHECK(probe.D2.size() == 0);
        CHECK(probe.E1.size() == 0);
        CHECK(probe.E2.size() == 0);
        CHECK(probe.F1.size() == 0);
        CHECK(probe.F2.size() == 0);
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
                   IsEqual(std::vector<double>(1, 1.)));
        CHECK_FALSE(bool(probe.K1));
        CHECK_FALSE(bool(probe.K2));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.NSI_A));
        CHECK_FALSE(bool(probe.NSI_B));
        CHECK_FALSE(bool(probe.CW_A));
        CHECK_FALSE(bool(probe.CW_B));
        CHECK_FALSE(bool(probe.M1_A));
        CHECK_FALSE(bool(probe.M2_A));
        CHECK_FALSE(bool(probe.M1_B));
        CHECK_FALSE(bool(probe.M2_B));
        CHECK_FALSE(bool(probe.N1_A));
        CHECK_FALSE(bool(probe.N2_A));
        CHECK_FALSE(bool(probe.N1_B));
        CHECK_FALSE(bool(probe.N2_B));
    }
}

TEST_CASE("BDF PBEAM roundtrip test (minimal) (reuse)", "[bdf_pbeam]") {
    pbarl::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 1.};
    std::vector<double> I1{2., 2.};
    std::vector<double> I2{3., 3.};
    std::vector<std::string> SO(1, "YESA");
    std::vector<double> X_XB(1, 1.);

    pbeam probe;
    test << probe;
    test << probe(&PID, &MID, &A, &I1, &I2, &SO, &X_XB);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+00                        \n"
              "                                                                        \n"
              "        YESA    1.000+00\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
                   IsEqual(std::vector<double>(2, 1.)));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
                   IsEqual(std::vector<double>(2, 2.)));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
                   IsEqual(std::vector<double>(2, 3.)));
        CHECK(probe.I12.size() == 0);
        CHECK(probe.J.size() == 0);
        CHECK(probe.NSM.size() == 0);
        CHECK(probe.C1.size() == 0);
        CHECK(probe.C2.size() == 0);
        CHECK(probe.D1.size() == 0);
        CHECK(probe.D2.size() == 0);
        CHECK(probe.E1.size() == 0);
        CHECK(probe.E2.size() == 0);
        CHECK(probe.F1.size() == 0);
        CHECK(probe.F2.size() == 0);
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
                   IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
                   IsEqual(std::vector<double>(1, 1.)));
        CHECK_FALSE(bool(probe.K1));
        CHECK_FALSE(bool(probe.K2));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.NSI_A));
        CHECK_FALSE(bool(probe.NSI_B));
        CHECK_FALSE(bool(probe.CW_A));
        CHECK_FALSE(bool(probe.CW_B));
        CHECK_FALSE(bool(probe.M1_A));
        CHECK_FALSE(bool(probe.M2_A));
        CHECK_FALSE(bool(probe.M1_B));
        CHECK_FALSE(bool(probe.M2_B));
        CHECK_FALSE(bool(probe.N1_A));
        CHECK_FALSE(bool(probe.N2_A));
        CHECK_FALSE(bool(probe.N1_B));
        CHECK_FALSE(bool(probe.N2_B));
    }
}

TEST_CASE("BDF PBEAM roundtrip test (minimal) (SO, X/XB: default)", "[bdf_pbeam]") {
    pbeam::reset();
    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A({1.});
    std::vector<double> I1({2.});
    std::vector<double> I2({3.});
    std::vector<double> I12({4.});

    pbeam probe(&PID, &MID, &A, &I1, &I2);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+00                        \n"
              "                                                                        \n"
              "        YESA    1.000+00\n");
    }

    SECTION("check reading") {
        pbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
 IsEqual(std::vector<double>({1., 1.})));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
 IsEqual(std::vector<double>({2., 2.})));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
 IsEqual(std::vector<double>({3., 3.})));
        CHECK(probe.I12.size() == 0);
        CHECK(probe.J.size() == 0);
        CHECK(probe.NSM.size() == 0);
        CHECK(probe.C1.size() == 0);
        CHECK(probe.C2.size() == 0);
        CHECK(probe.D1.size() == 0);
        CHECK(probe.D2.size() == 0);
        CHECK(probe.E1.size() == 0);
        CHECK(probe.E2.size() == 0);
        CHECK(probe.F1.size() == 0);
        CHECK(probe.F2.size() == 0);
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
               IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
                   IsEqual(std::vector<double>(1, 1.)));
        CHECK_FALSE(bool(probe.K1));
        CHECK_FALSE(bool(probe.K2));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.NSI_A));
        CHECK_FALSE(bool(probe.NSI_B));
        CHECK_FALSE(bool(probe.CW_A));
        CHECK_FALSE(bool(probe.CW_B));
        CHECK_FALSE(bool(probe.M1_A));
        CHECK_FALSE(bool(probe.M2_A));
        CHECK_FALSE(bool(probe.M1_B));
        CHECK_FALSE(bool(probe.M2_B));
        CHECK_FALSE(bool(probe.N1_A));
        CHECK_FALSE(bool(probe.N2_A));
        CHECK_FALSE(bool(probe.N1_B));
        CHECK_FALSE(bool(probe.N2_B));
    }
}

TEST_CASE("BDF PBEAM roundtrip test (minimal) (SO, X/XB: default) (reuse)", "[bdf_pbeam]") {
    pbarl::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A({1.});
    std::vector<double> I1({2.});
    std::vector<double> I2({3.});

    pbeam probe;
    test << probe;
    test << probe(&PID, &MID, &A, &I1, &I2);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+00                        \n"
              "                                                                        \n"
              "        YESA    1.000+00\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
                   IsEqual(std::vector<double>(2, 1.)));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
                   IsEqual(std::vector<double>(2, 2.)));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
                   IsEqual(std::vector<double>(2, 3.)));
        CHECK(probe.I12.size() == 0);
        CHECK(probe.J.size() == 0);
        CHECK(probe.NSM.size() == 0);
        CHECK(probe.C1.size() == 0);
        CHECK(probe.C2.size() == 0);
        CHECK(probe.D1.size() == 0);
        CHECK(probe.D2.size() == 0);
        CHECK(probe.E1.size() == 0);
        CHECK(probe.E2.size() == 0);
        CHECK(probe.F1.size() == 0);
        CHECK(probe.F2.size() == 0);
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
                   IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
                   IsEqual(std::vector<double>(1, 1.)));
        CHECK_FALSE(bool(probe.K1));
        CHECK_FALSE(bool(probe.K2));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.NSI_A));
        CHECK_FALSE(bool(probe.NSI_B));
        CHECK_FALSE(bool(probe.CW_A));
        CHECK_FALSE(bool(probe.CW_B));
        CHECK_FALSE(bool(probe.M1_A));
        CHECK_FALSE(bool(probe.M2_A));
        CHECK_FALSE(bool(probe.M1_B));
        CHECK_FALSE(bool(probe.M2_B));
        CHECK_FALSE(bool(probe.N1_A));
        CHECK_FALSE(bool(probe.N2_A));
        CHECK_FALSE(bool(probe.N1_B));
        CHECK_FALSE(bool(probe.N2_B));
    }
}

TEST_CASE("BDF PBEAM roundtrip test (N2_B only)", "[bdf_pbeam]") {
    pbeam::reset();
    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 1.};
    std::vector<double> I1{2., 2.};
    std::vector<double> I2{3., 3.};
    std::vector<std::string> SO(1, "YESA");
    std::vector<double> X_XB(1, 1.);
    double N2_B{32.};

    pbeam probe(&PID, &MID, &A, &I1, &I2, nullptr, nullptr, nullptr,
                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                &SO, &X_XB,
                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &N2_B);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+00                        \n"
              "                                                                        \n"
              "        YESA    1.000+00                                                \n"
              "                                                                        \n"
              "                                                                        \n"
              "                                                                3.200+01\n");
    }

    SECTION("check reading") {
        pbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
                   IsEqual(std::vector<double>(2, 1.)));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
                   IsEqual(std::vector<double>(2, 2.)));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
                   IsEqual(std::vector<double>(2, 3.)));
        CHECK(probe.I12.size() == 0);
        CHECK(probe.J.size() == 0);
        CHECK(probe.NSM.size() == 0);
        CHECK(probe.C1.size() == 0);
        CHECK(probe.C2.size() == 0);
        CHECK(probe.D1.size() == 0);
        CHECK(probe.D2.size() == 0);
        CHECK(probe.E1.size() == 0);
        CHECK(probe.E2.size() == 0);
        CHECK(probe.F1.size() == 0);
        CHECK(probe.F2.size() == 0);
        CHECK_THAT(vector<std::string>(probe.SO.begin(), probe.SO.end()),
                   IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
                   IsEqual(std::vector<double>(1, 1.)));
        CHECK_FALSE(bool(probe.K1));
        CHECK_FALSE(bool(probe.K2));
        CHECK_FALSE(bool(probe.S1));
        CHECK_FALSE(bool(probe.S2));
        CHECK_FALSE(bool(probe.NSI_A));
        CHECK_FALSE(bool(probe.NSI_B));
        CHECK_FALSE(bool(probe.CW_A));
        CHECK_FALSE(bool(probe.CW_B));
        CHECK_FALSE(bool(probe.M1_A));
        CHECK_FALSE(bool(probe.M2_A));
        CHECK_FALSE(bool(probe.M1_B));
        CHECK_FALSE(bool(probe.M2_B));
        CHECK_FALSE(bool(probe.N1_A));
        CHECK_FALSE(bool(probe.N2_A));
        CHECK_FALSE(bool(probe.N1_B));
        CHECK(double(probe.N2_B) == 32.);
    }
}

TEST_CASE("BDF PBEAM roundtrip test (N2_B only) (reuse)", "[bdf_pbeam]") {
    pbarl::reset();

    std::ostringstream test;

    long PID{7869}, MID{104010};
    std::vector<double> A{1., 1.};
    std::vector<double> I1{2., 2.};
    std::vector<double> I2{3., 3.};
    std::vector<std::string> SO(1, "YESA");
    std::vector<double> X_XB(1, 1.);
    double N2_B{32.};

    pbeam probe;
    test << probe;
    test << probe(
        &PID, &MID, &A, &I1, &I2, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        &SO, &X_XB,
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &N2_B);

    SECTION("check output") {
        CHECK(test.str() ==
              "PBEAM       7869  1040101.000+002.000+003.000+00                        \n"
              "                                                                        \n"
              "        YESA    1.000+00                                                \n"
              "                                                                        \n"
              "                                                                        \n"
              "                                                                3.200+01\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        pbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.MID) == 104010);
        CHECK_THAT(vector<double>(probe_l.A.begin(), probe_l.A.end()),
                   IsEqual(std::vector<double>( {1., 1.})));
        CHECK_THAT(vector<double>(probe_l.I1.begin(), probe_l.I1.end()),
                   IsEqual(std::vector<double>({2., 2.})));
        CHECK_THAT(vector<double>(probe_l.I2.begin(), probe_l.I2.end()),
                   IsEqual(std::vector<double>({3., 3.})));
        CHECK_THAT(vector<double>(probe_l.I12.begin(), probe_l.I12.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.J.begin(), probe_l.J.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.NSM.begin(), probe_l.NSM.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.C1.begin(), probe_l.C1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.C2.begin(), probe_l.C2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.D1.begin(), probe_l.D1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.D2.begin(), probe_l.D2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.E1.begin(), probe_l.E1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.E2.begin(), probe_l.E2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.F1.begin(), probe_l.F1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe_l.F2.begin(), probe_l.F2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<std::string>(probe_l.SO.begin(), probe_l.SO.end()),
                   IsEqual(vector<string>(1, "YESA")));
        CHECK_THAT(vector<double>(probe_l.X_XB.begin(), probe_l.X_XB.end()),
                   IsEqual(std::vector<double>(1, 1.)));
        CHECK(double(probe_l.K1) == 1.);
        CHECK(double(probe_l.K2) == 1.);
        CHECK(double(probe_l.S1) == 0.);
        CHECK(double(probe_l.S2) == 0.);
        CHECK(double(probe_l.NSI_A) == 0.);
        CHECK(double(probe_l.NSI_B) == 0.);
        CHECK(double(probe_l.CW_A) == 0.);
        CHECK(double(probe_l.CW_B) == 0.);
        CHECK(double(probe_l.M1_A) == 0.);
        CHECK(double(probe_l.M2_A) == 0.);
        CHECK(double(probe_l.M1_B) == 0.);
        CHECK(double(probe_l.M2_B) == 0.);
        CHECK(double(probe_l.N1_A) == 0.);
        CHECK(double(probe_l.N2_A) == 0.);
        CHECK(double(probe_l.N1_B) == 0.);
        CHECK(double(probe_l.N2_B) == 32.);
    }
}

TEST_CASE("Error reports", "[bdf_bugs]") {

    SECTION("20180514") {

        std::list<std::string> data({
           // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567
           "PBEAM*   8               1              1241.44         2.40798+6      \n",
           "*       37601.           -148296.       34650.                         \n",
           "         0.      0.      0.      0.      0.      0.      0.      0.    \n",
           "*       .676711         .142035                                        \n",
           "*                                       1.89246+7       1.89246+7      \n",
           "                                        37.1607 2.55562 37.1607 2.55562\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbeam probe(lines);

        CAPTURE( data.front() );

        CHECK(long(probe.PID) == 8);
        CHECK(long(probe.MID) == 1);
        CHECK_THAT(vector<double>(probe.A.begin(), probe.A.end()),
                   IsEqual(std::vector<double>( {1241.44})));
        CHECK_THAT(vector<double>(probe.I1.begin(), probe.I1.end()),
                   IsEqual(std::vector<double>({2.40798e6})));
        CHECK_THAT(vector<double>(probe.I2.begin(), probe.I2.end()),
                   IsEqual(std::vector<double>({37601.})));
        CHECK_THAT(vector<double>(probe.I12.begin(), probe.I12.end()),
                   IsEqual(std::vector<double>({ -148296.})));
        CHECK_THAT(vector<double>(probe.J.begin(), probe.J.end()),
                   IsEqual(std::vector<double>({34650.})));
        CHECK_THAT(vector<double>(probe.NSM.begin(), probe.NSM.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.C1.begin(), probe.C1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.C2.begin(), probe.C2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.D1.begin(), probe.D1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.D2.begin(), probe.D2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.E1.begin(), probe.E1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.E2.begin(), probe.E2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.F1.begin(), probe.F1.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK_THAT(vector<double>(probe.F2.begin(), probe.F2.end()),
                   IsEqual(std::vector<double>({0., 0.})));
        CHECK(probe.SO.size() == 0);
        CHECK(probe.X_XB.size() == 0);
        CHECK(double(probe.K1) == 0.676711);
        CHECK(double(probe.K2) == 0.142035);
        CHECK(double(probe.S1) == 0.);
        CHECK(double(probe.S2) == 0.);
        CHECK(double(probe.NSI_A) == 0.);
        CHECK(double(probe.NSI_B) == 0.);
        CHECK(double(probe.CW_A) == 18924600.);
        CHECK(double(probe.CW_B) == 18924600.);
        CHECK(double(probe.M1_A) == 0.);
        CHECK(double(probe.M2_A) == 0.);
        CHECK(double(probe.M1_B) == 0.);
        CHECK(double(probe.M2_B) == 0.);
        CHECK(double(probe.N1_A) == 37.1607);
        CHECK(double(probe.N2_A) == 2.55562);
        CHECK(double(probe.N1_B) == 37.1607);
        CHECK(double(probe.N2_B) == 2.55562);
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
