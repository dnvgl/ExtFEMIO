/**
   \file tests/test_bdf_cards_pbeam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBEAM` card class.

   Detailed description
*/

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif

#include "bdf/cards.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("BDF PBEAM definitions.", "[bdf_PBEAM]") {

   SECTION("Small Field Format") {

      ::std::deque<string> data;
      data.push_back(
         //       PID     MID     A       I1      I2      I12     J
         // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
         "PBEAM    4000001       3 1.046+4 9.369+7 1.694+6 6.856+6 1.316+6        \n");
      ::std::deque<string> lines;
      card::card_split(data, lines);
      pbeam probe(lines);

      CAPTURE(data[0]);

      CHECK((long)probe.PID == 4000001);
      CHECK((long)probe.MID == 3);
      CHECK(probe.A.size() == 1);
      CHECK(probe.A[0] == 10460.);
      CHECK(probe.I1.size() == 1);
      CHECK(probe.I1[0] == 93690000.);
      CHECK(probe.I2.size() == 1);
      CHECK(probe.I2[0] == 1694000.);
      CHECK(probe.I12.size() == 1);
      CHECK(probe.I12[0] == 6.856e6);
      CHECK(probe.J.size() == 1);
      CHECK(probe.J[0] == 1.316e6);
   }

   SECTION("Small Field Format2") {

      ::std::deque<string> data;
      data.push_back(
         //       PID     MID     A       I1      I2      I12     J
         // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I
         "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n");
      ::std::deque<string> lines;
      card::card_split(data, lines);
      pbeam probe(lines);

      CAPTURE(data[0]);

      CHECK((long)probe.PID == 4000001);
      CHECK((long)probe.MID == 3);
      CHECK(probe.A.size() == 1);
      CHECK(probe.A[0] == 10460.);
      CHECK(probe.I1.size() == 1);
      CHECK(probe.I1[0] == 93690000.);
      CHECK(probe.I2.size() == 1);
      CHECK(probe.I2[0] == 1694000.);
      CHECK(probe.I12.size() == 1);
      CHECK(probe.I12[0] == 6.856e6);
      CHECK(probe.J.size() == 1);
      CHECK(probe.J[0] == 1.316e6);
   }

   SECTION("Free Field Format 1") {

      ::std::deque<string> data;
      data.push_back(
         "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.\n");
      ::std::deque<string> lines;
      card::card_split(data, lines);
      pbeam probe(lines);

      CAPTURE(data[0]);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID == 2);
      CHECK(probe.A.size() == 1);
      CHECK(probe.A[0] == 3.);
      CHECK(probe.I1.size() == 1);
      CHECK(probe.I1[0] == 4.);
      CHECK(probe.I2.size() == 1);
      CHECK(probe.I2[0] == 5.);
      CHECK(probe.I12.size() == 1);
      CHECK(probe.I12[0] == 6.);
      CHECK(probe.J.size() == 1);
      CHECK(probe.J[0] == 7.);
      CHECK(probe.NSM.size() == 1);
      CHECK(probe.NSM[0] == 8.);
      CHECK(probe.C1.size() == 1);
      CHECK(probe.C1[0] ==  9.);
      CHECK(probe.C2.size() == 1);
      CHECK(probe.C2[0] == 10.);
      CHECK(probe.D1.size() == 1);
      CHECK(probe.D1[0] == 11.);
      CHECK(probe.D2.size() == 1);
      CHECK(probe.D2[0] == 12.);
      CHECK(probe.E1.size() == 1);
      CHECK(probe.E1[0] == 13.);
      CHECK(probe.E2.size() == 1);
      CHECK(probe.E2[0] == 14.);
      CHECK(probe.F1.size() == 1);
      CHECK(probe.F1[0] == 15.);
      CHECK(probe.F2.size() == 1);
      CHECK(probe.F2[0] == 16.);
   }

   SECTION("Free Field Format 2") {

      ::std::deque<string> data;
      data.push_back(
         "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,\n");
      data.push_back(
         ",YES,18.,19.,20.,21.,22.,23.,24.,25.,26.,27.,28.,29.,30.,31.,32.,\n");
      data.push_back(
         ",NO,34.,35.,36.,37.,38.,39.,40.,41.,42.,43.,44.,45.,46.,47.,48.,\n");
      data.push_back(
         ",49.,50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.,61.,62.,63.,64.\n");
      ::std::deque<string> lines;
      card::card_split(data, lines);

      CHECK(lines.size() == 65);
      pbeam probe(lines);

      CAPTURE(data[0]);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID == 2);
      CHECK(probe.SO.size() == 2);
      CHECK(probe.SO[0] == "YES");
      CHECK(probe.SO[1] == "NO");
      CHECK(probe.X_XB.size() == 2);
      CHECK(probe.X_XB[0] == 18.);
      CHECK(probe.X_XB[1] == 34.);
      CHECK(probe.A.size() == 3);
      CHECK(probe.A[0] == 3.);
      CHECK(probe.A[1] == 19.);
      CHECK(probe.A[2] == 35.);
      CHECK(probe.I1.size() == 3);
      CHECK(probe.I1[0] == 4.);
      CHECK(probe.I1[1] == 20.);
      CHECK(probe.I1[2] == 36.);
      CHECK(probe.I2.size() == 3);
      CHECK(probe.I2[0] == 5.);
      CHECK(probe.I2[1] == 21.);
      CHECK(probe.I2[2] == 37.);
      CHECK(probe.I12.size() == 3);
      CHECK(probe.I12[0] == 6.);
      CHECK(probe.I12[1] == 22.);
      CHECK(probe.I12[2] == 38.);
      CHECK(probe.J.size() == 3);
      CHECK(probe.J[0] == 7.);
      CHECK(probe.J[1] == 23.);
      CHECK(probe.J[2] == 39.);
      CHECK(probe.NSM.size() == 3);
      CHECK(probe.NSM[0] == 8.);
      CHECK(probe.NSM[1] == 24.);
      CHECK(probe.NSM[2] == 40.);
      CHECK(probe.C1.size() == 3);
      CHECK(probe.C1[0] == 9.);
      CHECK(probe.C1[1] == 25.);
      CHECK(probe.C1[2] == 41.);
      CHECK(probe.C2.size() == 3);
      CHECK(probe.C2[0] == 10.);
      CHECK(probe.C2[1] == 26.);
      CHECK(probe.C2[2] == 42.);
      CHECK(probe.D1.size() == 3);
      CHECK(probe.D1[0] == 11.);
      CHECK(probe.D1[1] == 27.);
      CHECK(probe.D1[2] == 43.);
      CHECK(probe.D2.size() == 3);
      CHECK(probe.D2[0] == 12.);
      CHECK(probe.D2[1] == 28.);
      CHECK(probe.D2[2] == 44.);
      CHECK(probe.E1.size() == 3);
      CHECK(probe.E1[0] == 13.);
      CHECK(probe.E1[1] == 29.);
      CHECK(probe.E1[2] == 45.);
      CHECK(probe.E2.size() == 3);
      CHECK(probe.E2[0] == 14.);
      CHECK(probe.E2[1] == 30.);
      CHECK(probe.E2[2] == 46.);
      CHECK(probe.F1.size() == 3);
      CHECK(probe.F1[0] == 15.);
      CHECK(probe.F1[1] == 31.);
      CHECK(probe.F1[2] == 47.);
      CHECK(probe.F2.size() == 3);
      CHECK(probe.F2[0] == 16.);
      CHECK(probe.F2[1] == 32.);
      CHECK(probe.F2[2] == 48.);

      CHECK((double)probe.K1 == 49);
      CHECK((double)probe.K2 == 50);
      CHECK((double)probe.S1 == 51);
      CHECK((double)probe.S2 == 52);
      CHECK((double)probe.NSI_A == 53);
      CHECK((double)probe.NSI_B == 54);
      CHECK((double)probe.CW_A == 55);
      CHECK((double)probe.CW_B == 56);
      CHECK((double)probe.M1_A == 57);
      CHECK((double)probe.M2_A == 58);
      CHECK((double)probe.M1_B == 59);
      CHECK((double)probe.M2_B == 60);
      CHECK((double)probe.N1_A == 61);
      CHECK((double)probe.N2_A == 62);
      CHECK((double)probe.N1_B == 63);
      CHECK((double)probe.N2_B == 64);
   }

   SECTION("Free Field Format 3") {

      ::std::deque<string> data;
      data.push_back(
         "PBEAM,1,2,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,"
         "YES,18.,19.,20.,21.,22.,23.,24.,25.,26.,27.,28.,29.,30.,31.,32.,"
         "NO,34.,35.,36.,37.,38.,39.,40.,41.,42.,43.,44.,45.,46.,47.,48.,"
         "49.,50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.,61.,62.,63.,64."
         ",65.\n");
      ::std::deque<string> lines;
      card::card_split(data, lines);

      CAPTURE(data[0]);

      CHECK(lines.size() == 66);

      CHECK_THROWS(pbeam probe(lines));

   }

   SECTION("Tapered Beam") {

      ::std::deque<string> data;
      data.push_back(
         // 34567A1234567B1234567C1234567D1234567E1234567F
         "PBEAM         39       6     2.9     3.5    5.97"
         // 34567G1234567H1234567I
         "                        \n");
      data.push_back(
         // 34567A1234567B1234567C1234567D1234567E1234567F
         "                             2.0    -4.0         "
         // 34567G1234567H1234567I
         "                        \n");
      data.push_back(
         // 34567A1234567B1234567C1234567D1234567E1234567F
         "             YES     1.0     5.3    56.2    78.6"
         // 34567G1234567H1234567I
         "                        \n");
      data.push_back(
         // 34567A1234567B1234567C1234567D1234567E1234567F
         "                             2.5    -5.0        "
         // 34567G1234567H1234567I
         "                        \n");
      data.push_back(
         // 34567A1234567B1234567C1234567D1234567E1234567F
         "                             1.1             2.1"
         // 34567G1234567H1234567I
         "            0.21        \n");
      data.push_back(
         // 34567A1234567B1234567C1234567D1234567E1234567F
         "                                             0.5"
         // 34567G1234567H1234567I
         "             0.0        \n");
      ::std::deque<string> lines;
      card::card_split(data, lines);
      pbeam probe(lines);

      CAPTURE(data[0]);

      CHECK((long)probe.PID == 39);
      CHECK((long)probe.MID == 6);
      CHECK(probe.A.size() == 2);
      CHECK(probe.A[0] == 2.9);
      CHECK(probe.A[1] == 5.3);
      CHECK(probe.I1.size() == 2);
      CHECK(probe.I1[0] == 3.5);
      CHECK(probe.I1[1] == 56.2);
      CHECK(probe.I2.size() == 2);
      CHECK(probe.I2[0] == 5.97);
      CHECK(probe.I2[1] == 78.6);
      CHECK(probe.I12.size() == 2);
      CHECK_FALSE(probe.I12[0]);
      CHECK_FALSE(probe.I12[1]);
      CHECK(probe.J.size() == 2);
      CHECK_FALSE(probe.J[0]);
      CHECK_FALSE(probe.J[1]);
      CHECK(probe.NSM.size() == 2);
      CHECK_FALSE(probe.NSM[0]);
      CHECK_FALSE(probe.NSM[1]);
      CHECK(probe.C1.size() == 2);
      CHECK(probe.C1[0] == 0.);
      CHECK(probe.C1[1] == 0.);
      CHECK(probe.C2.size() == 2);
      CHECK(probe.C2[0] == 0.);
      CHECK(probe.C2[1] == 0.);
      CHECK(probe.D1.size() == 2);
      CHECK(probe.D1[0] == 2.);
      CHECK(probe.D1[1] == 2.5);
      CHECK(probe.D2.size() == 2);
      CHECK(probe.D2[0] == -4.);
      CHECK(probe.D2[1] == -5.);
      CHECK(probe.E1.size() == 2);
      CHECK(probe.E1[0] == 0.);
      CHECK(probe.E1[1] == 0.);
      CHECK(probe.E2.size() == 2);
      CHECK(probe.E2[0] == 0.);
      CHECK(probe.E2[1] == 0.);
      CHECK(probe.F1.size() == 2);
      CHECK(probe.F1[0] == 0.);
      CHECK(probe.F1[1] == 0.);
      CHECK(probe.F2.size() == 2);
      CHECK(probe.F2[0] == 0.);
      CHECK(probe.F2[1] == 0.);
      CHECK(probe.SO.size() == 1);
      CHECK(probe.SO[0] == "YES");
      CHECK(probe.X_XB.size() == 1);
      CHECK(probe.X_XB[0] == 1.);

      CHECK((double)probe.K1 == 1.);
      CHECK((double)probe.K2 == 1.);
      CHECK((double)probe.S1 == 1.1);
      CHECK((double)probe.S2 == 0.);
      CHECK((double)probe.NSI_A == 2.1);
      CHECK_FALSE(probe.NSI_B);
      CHECK((double)probe.CW_A == 0.21);
      CHECK_FALSE(probe.CW_B);
      CHECK((double)probe.M1_A == 0.);
      CHECK((double)probe.M2_A == 0.);
      CHECK_FALSE(probe.M1_B);
      CHECK_FALSE(probe.M2_B);
      CHECK((double)probe.N1_A == 0.5);
      CHECK((double)probe.N2_A == 0.);
      CHECK((double)probe.N1_B == 0.0);
      CHECK_FALSE(probe.N2_B);
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
