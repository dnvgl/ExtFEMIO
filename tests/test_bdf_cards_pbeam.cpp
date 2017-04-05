/**
   \file tests/test_bdf_cards_pbeam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBEAM` card class.

   Detailed description
*/

#include "extfem_misc.h"
#include "fem/types.h"

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

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF PBEAM definitions.", "[bdf_PBEAM]") {

    SECTION("Small Field Format") {

        std::list<std::string> data({
                //       PID     MID     A       I1      I2      I12     J
                // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
                "PBEAM    4000001       3 1.046+4 9.369+7 1.694+6 6.856+6 1.316+6        \n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbeam probe(lines);

        CAPTURE( data.front() );

        REQUIRE((long)probe.PID == 4000001);
        REQUIRE((long)probe.MID == 3);
        REQUIRE(probe.A == std::vector<double>({10460.}));
        REQUIRE(probe.I1 == std::vector<double>({93690000.}));
        REQUIRE(probe.I2 == std::vector<double>({1694000.}));
        REQUIRE(probe.I12 == std::vector<double>({6.856e6}));
        REQUIRE(probe.J == std::vector<double>({1.316e6}));
    }

    SECTION("Small Field Format2") {

        std::list<std::string> data({
                //       PID     MID     A       I1      I2      I12     J
                // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
                "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbeam probe(lines);

        CAPTURE( data.front() );

        REQUIRE((long)probe.PID == 4000001);
        REQUIRE((long)probe.MID == 3);
        REQUIRE(probe.A == std::vector<double>({10460.}));
        REQUIRE(probe.I1 == std::vector<double>({93690000.}));
        REQUIRE(probe.I2 == std::vector<double>({1694000.}));
        REQUIRE(probe.I12 == std::vector<double>({6.856e6}));
        REQUIRE(probe.J == std::vector<double>({1.316e6}));
    }

    SECTION("Free Field Format 1") {

        std::list<std::string> data({
                "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbeam probe(lines);

        CAPTURE( data.front() );

        REQUIRE((long)probe.PID == 1);
        REQUIRE((long)probe.MID == 2);
        REQUIRE(probe.A == std::vector<double>({3.}));
        REQUIRE(probe.I1 == std::vector<double>({4.}));
        REQUIRE(probe.I2 == std::vector<double>({5.}));
        REQUIRE(probe.I12 == std::vector<double>({6.}));
        REQUIRE(probe.J == std::vector<double>({7.}));
        REQUIRE(probe.NSM == std::vector<double>({8.}));
        REQUIRE(probe.C1 == std::vector<double>({9.}));
        REQUIRE(probe.C2 == std::vector<double>({10.}));
        REQUIRE(probe.D1 == std::vector<double>({11.}));
        REQUIRE(probe.D2 == std::vector<double>({12.}));
        REQUIRE(probe.E1 == std::vector<double>({13.}));
        REQUIRE(probe.E2 == std::vector<double>({14.}));
        REQUIRE(probe.F1 == std::vector<double>({15.}));
        REQUIRE(probe.F2 == std::vector<double>({16.}));
    }

    SECTION("Free Field Format 2") {

        std::list<std::string> data({
                "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,\n",
                    ",YES,18.,19.,20.,21.,22.,23.,24.,25.,26.,27.,28.,29.,30.,31.,32.,\n",
                    ",NO,34.,35.,36.,37.,38.,39.,40.,41.,42.,43.,44.,45.,46.,47.,48.,\n",
                    ",49.,50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.,61.,62.,63.,64.\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);

        REQUIRE(lines.size() == 65);
        pbeam probe(lines);

        CAPTURE( data.front() );

        REQUIRE((long)probe.PID == 1);
        REQUIRE((long)probe.MID == 2);
        std::vector<std::string> ref({"YES", "NO"});
        for (auto p : probe.SO) {
            REQUIRE(p == ref.front());
            ref.erase(ref.begin());
        }
        REQUIRE(probe.X_XB == std::vector<double>({18., 34.}));
        REQUIRE(probe.A == std::vector<double>({3., 19., 35.}));
        REQUIRE(probe.I1 == std::vector<double>({4., 20., 36.}));
        REQUIRE(probe.I2 == std::vector<double>({5., 21., 37.}));
        REQUIRE(probe.I12 == std::vector<double>({6., 22., 38.}));
        REQUIRE(probe.J == std::vector<double>({7., 23., 39.}));
        REQUIRE(probe.NSM == std::vector<double>({8., 24., 40.}));
        REQUIRE(probe.C1 == std::vector<double>({9., 25., 41.}));
        REQUIRE(probe.C2 == std::vector<double>({10., 26., 42.}));
        REQUIRE(probe.D1 == std::vector<double>({11., 27., 43.}));
        REQUIRE(probe.D2 == std::vector<double>({12., 28., 44.}));
        REQUIRE(probe.E1 == std::vector<double>({13., 29., 45.}));
        REQUIRE(probe.E2 == std::vector<double>({14., 30., 46.}));
        REQUIRE(probe.F1 == std::vector<double>({15., 31., 47.}));
        REQUIRE(probe.F2 == std::vector<double>({16., 32., 48.}));

        REQUIRE((double)probe.K1 == 49);
        REQUIRE((double)probe.K2 == 50);
        REQUIRE((double)probe.S1 == 51);
        REQUIRE((double)probe.S2 == 52);
        REQUIRE((double)probe.NSI_A == 53);
        REQUIRE((double)probe.NSI_B == 54);
        REQUIRE((double)probe.CW_A == 55);
        REQUIRE((double)probe.CW_B == 56);
        REQUIRE((double)probe.M1_A == 57);
        REQUIRE((double)probe.M2_A == 58);
        REQUIRE((double)probe.M1_B == 59);
        REQUIRE((double)probe.M2_B == 60);
        REQUIRE((double)probe.N1_A == 61);
        REQUIRE((double)probe.N2_A == 62);
        REQUIRE((double)probe.N1_B == 63);
        REQUIRE((double)probe.N2_B == 64);
    }

    SECTION("Free Field Format 3") {

        std::list<std::string> data({
                "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,"
                    "YES,18.,19.,20.,21.,22.,23.,24.,25.,26.,27.,28.,29.,30.,31.,32.,"
                    "NO,34.,35.,36.,37.,38.,39.,40.,41.,42.,43.,44.,45.,46.,47.,48.,"
                    "49.,50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.,61.,62.,63.,64."
                    ",65.\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);

        CAPTURE( data.front() );

        REQUIRE(lines.size() == 66);

        REQUIRE_THROWS(pbeam(lines));

    }

    SECTION("Tapered Beam") {

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

        REQUIRE((long)probe.PID == 39);
        REQUIRE((long)probe.MID == 6);
        REQUIRE(probe.A == std::vector<double>({2.9, 5.3}));
        REQUIRE(probe.I1 == std::vector<double>({3.5, 56.2}));
        REQUIRE(probe.I2 == std::vector<double>({5.97, 78.6}));
        REQUIRE(probe.I12 == std::vector<double>({0., 0.}));
        REQUIRE(probe.J == std::vector<double>({0., 0.}));
        REQUIRE(probe.NSM == std::vector<double>({0., 0.}));
        REQUIRE(probe.C1 == std::vector<double>({0., 0.}));
        REQUIRE(probe.C2 == std::vector<double>({0., 0.}));
        REQUIRE(probe.D1 == std::vector<double>({2., 2.5}));
        REQUIRE(probe.D2 == std::vector<double>({-4., -5.}));
        REQUIRE(probe.E1 == std::vector<double>({0., 0.}));
        REQUIRE(probe.E2 == std::vector<double>({0., 0.}));
        REQUIRE(probe.F1 == std::vector<double>({0., 0.}));
        REQUIRE(probe.F2 == std::vector<double>({0., 0.}));
        std::vector<dnvgl::extfem::bdf::types::entry_value<std::string> > ref(1);
        dnvgl::extfem::bdf::types::entry_type<std::string> tmp("tmp");
        tmp.set_value(ref.front(), "YES");
        REQUIRE(probe.SO == ref);
        REQUIRE(probe.X_XB == std::vector<double>({1.}));

        REQUIRE((double)probe.K1 == 1.);
        REQUIRE((double)probe.K2 == 1.);
        REQUIRE((double)probe.S1 == 1.1);
        REQUIRE((double)probe.S2 == 0.);
        REQUIRE((double)probe.NSI_A == 2.1);
        REQUIRE_FALSE(probe.NSI_B);
        REQUIRE((double)probe.CW_A == 0.21);
        REQUIRE_FALSE(probe.CW_B);
        REQUIRE((double)probe.M1_A == 0.);
        REQUIRE((double)probe.M2_A == 0.);
        REQUIRE_FALSE(probe.M1_B);
        REQUIRE_FALSE(probe.M2_B);
        REQUIRE((double)probe.N1_A == 0.5);
        REQUIRE((double)probe.N2_A == 0.);
        REQUIRE((double)probe.N1_B == 0.0);
        REQUIRE_FALSE(probe.N2_B);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
