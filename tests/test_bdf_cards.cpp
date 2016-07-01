/**
   \file tests/test_bdf_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF cards classes.

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

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <iostream>
#include <list>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif

#include "bdf/cards.h"
#include "bdf/file.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;
using namespace dnvgl::extfem::bdf::input;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return Catch::toString( ex() );
}

TEST_CASE("BDF file reader.", "[bdf_cards]" ) {

   std::string s(
      // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      "$Only a comment\n"
      "MAT1    1       2.305+6 80000.0 0.3     7.850-6\n"
      "MAT1    4       2.305+6 80000.0 0.3     7.850-6\n"
      "PBEAML  104010  4               L     \n"
      "           63.0   340.0    35.0    14.0\n"
      "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n");
   std::istringstream ist(s);
   bdf_file probe(ist);
   std::list<std::string> l;

   std::list<std::string> ref;


   {
      std::list<std::string> ref({
         "MAT1    1       2.305+6 80000.0 0.3     7.850-6" });
      probe.get(l);
      CAPTURE( l.front() );
      CHECK(l == ref);
   }

   {
      std::list<std::string> ref({
         "MAT1    4       2.305+6 80000.0 0.3     7.850-6" });
      probe.get(l);
      CAPTURE( l.front() );
      CHECK(l == ref);
   }

   {
      std::list<std::string> ref({
         "PBEAML  104010  4               L     ",
         "           63.0   340.0    35.0    14.0" });
      probe.get(l);
      CAPTURE( l.front() );
      CHECK(l == ref);
   }

   {
      std::list<std::string> ref({
         "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6" });
      probe.get(l);
      CAPTURE( l.front() );
      CHECK(l == ref);
   }
}

TEST_CASE("Split Free Field Cards", "[bdf_cards]") {

   // Test data as found in the BDF documentation.

   SECTION("Sample 1") {
      std::list<std::string> data({ "GRID,2,1.0,-2.0,3.0,,136" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({ "GRID", "2", "1.0", "-2.0", "3.0", "", "136" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 2") {
      std::list<std::string> data({
         "MATT9,1101,2 ,3 ,4 ,,,,8 ,+P101\n",
         "+P101,9 ,,,,13\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
            "MATT9", "1101", "2", "3", "4", "", "", "", "8", "9", "",
               "", "", "13"});
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 3") {
      std::list<std::string> data({
         "GRID,100,,1.0,0.0,0.0,,456\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
            "GRID", "100", "", "1.0", "0.0", "0.0", "", "456"});
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 4") {
      std::list<std::string> data({
         "SPC1,100,12456,1,2,3,4,5,6,+SPC-A+SPC-A,7,8,9,10\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "SPC1", "100", "12456", "1", "2", "3", "4", "5", "6", "7",
         "8", "9", "10" });
      // TODO: possible allow the above line syntax.
      CHECK_FALSE(probe.size() == ref.size());
      // for (size_t i=0; i<probe.size(); ++i) {
      //   CAPTURE( i << ": !" << probe[i] << "!" << ref[i] << "!" );
      //   CHECK(probe[i] == ref[i]);
      // }
   }

   SECTION("Sample 5") {
      std::list<std::string> data({
         "SPC1,100,12456,1,2,3,4,5,6,7,8,9,10\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
            "SPC1", "100", "12456", "1", "2", "3", "4", "5", "6", "7",
               "8", "9", "10"});
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 6") {
      std::list<std::string> data({
         "MATT9,1151,2 ,3 ,4 ,,,,8 \n",
         ",9 ,,,,13\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "MATT9", "1151", "2", "3", "4", "", "", "", "8", "9", "",
         "", "", "13" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 7") {
      std::list<std::string> data({
         "MATT9,1151,2 ,3 ,4 ,,,,8 ,+\n",
         "+,9 ,,,,13\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "MATT9", "1151", "2", "3", "4", "", "", "", "8", "9", "",
         "", "", "13" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 8") {
      std::list<std::string> data({
         "MATT9*,1302,2 ,,4 ,+\n",
         "+,,,,,,13\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "MATT9", "1302", "2", "", "4", "", "", "", "", "", "13" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 9") {
      std::list<std::string> data({
         "MATT9,1303,2 ,3 ,4 ,,,,8 ,+\n",
         "*,9 ,,,,\n",
         "*,13\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "MATT9", "1303", "2", "3", "4", "", "", "", "8", "9", "",
         "", "", "13" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 10") {
      std::list<std::string> data({
         "MATT9,1355,2 ,3 ,,5 ,,,8 ,+\n",
         "*,,10,,,\n",
         "*,17\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "MATT9", "1355", "2", "3", "", "5", "", "", "8", "", "10",
         "", "", "17" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }

   SECTION("Sample 11") {
      std::list<std::string> data({
         "CHEXA,200,200,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "CHEXA", "200", "200", "1", "2", "3", "4", "5", "6", "7",
         "8", "9", "10", "11", "12", "13", "14", "15", "16",
         "17", "18", "19", "20" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }
}

TEST_CASE("Split Small Field Cards", "[cards]") {

   // Test data as found in the BDF documentation.

   std::list<std::string> data;

   SECTION("Sample 1") {
      data.assign({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678
            "GRID           2             1.0    -2.0     3.0             136\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
            "GRID", "2", "", "1.0", "-2.0", "3.0", "", "136", "" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }
}

TEST_CASE("Split Large Field Cards", "[cards]") {

   // Test data as found in the BDF documentation.

   std::list<std::string> data;

   SECTION("Sample 1") {
      data.assign({
         // 345678|234567812345678|234567812345678|234567812345678|234567812345678|2345678
         "GRID*                  2                             1.0            -2.0 *GRID10\n",
         "*GRID10              3.0                             136\n" });
      std::list<std::string> probe;
      __base::card::card_split(data, probe);
      std::list<std::string> ref({
         "GRID", "2", "", "1.0", "-2.0", "3.0", "", "136", "" });
      CHECK(probe.size() == ref.size());
      CHECK(probe == ref);
   }
}

TEST_CASE("BDF_Dispatch", "[cards]") {

   std::string s(
      // 35678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      "MAT1    1       2.305+6 80000.0 0.3     7.850-6\n"
      "MAT1    4       2.305+6 80000.0 0.3     7.850-6\n"
      "PBEAML  104010  4               L     \n"
      "           63.0   340.0    35.0    14.0\n"
      "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n"
      "PROD    6000001 1       3000.00\n"
      "PSHELL  1       4         23.00 4               4\n"
      "GRID           1        111525. 18000.  21000.\n"
      "GRID          76        111522. 18002.  21002.\n"
      "GRID         153        111522. 18001.  21002.\n"
      "CQUAD4  1       1       16      200     141     17\n"
      // 35678|234567890123456|234567890123456|234567890123456|234567890123456|2
      "CQUAD4* 2               1               16              200             "
      "+\n"
      "+       140             15\n"
      "CTRIA3  2606    1       1066    1065    1133\n"
      "CBEAM   7869    104010  76      153     0.0     66.5206 997.785\n"
      "                        0.0     -22.617 -339.25 0.0     -22.617 -339.25\n"
      "CROD    11316   6000001 1028    2139\n"
      "CBEAM    465144 104010  76      153     1.       0.      0.\n"
      "$ Elements and Element Properties for region : pbeaml.59\n"
      "ENDDATA\n");

   std::istringstream ist(s);
   bdf_file probe(ist);
   std::list<std::string> l;
   std::list<std::string> ref;

   std::unique_ptr<cards::__base::card> current;

   SECTION("Processing several cards.") {
      probe.get(l);
      CAPTURE( l.front() );
      INFO( "The line is " << l.front() );
      std::list<std::string> data;
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::MAT1);
      // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      //         MID     E       G       NU      RHO
      // MAT1    1       2.305+6 80000.0 0.3     7.850-6
      CHECK(static_cast<mat1*>(current.get())->MID.value == 1);
      CHECK(static_cast<mat1*>(current.get())->E.value == 2.305e6);
      CHECK(static_cast<mat1*>(current.get())->G.value == 8e4);
      CHECK(static_cast<mat1*>(current.get())->NU.value == .3);
      CHECK(static_cast<mat1*>(current.get())->RHO.value == 7.85e-6);
      CHECK_FALSE(static_cast<mat1*>(current.get())->A);
      CHECK_FALSE(static_cast<mat1*>(current.get())->TREF);
      CHECK_FALSE(static_cast<mat1*>(current.get())->GE);
      CHECK_FALSE(static_cast<mat1*>(current.get())->ST);
      CHECK_FALSE(static_cast<mat1*>(current.get())->SC);
      CHECK_FALSE(static_cast<mat1*>(current.get())->SS);
      CHECK_FALSE(static_cast<mat1*>(current.get())->MCSID);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::MAT1);
      // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      //         MID     E       G       NU      RHO
      // MAT1    4       2.305+6 80000.0 0.3     7.850-6
      CHECK(static_cast<mat1*>(current.get())->MID.value == 4);
      CHECK(static_cast<mat1*>(current.get())->E.value == 2.305e6);
      CHECK(static_cast<mat1*>(current.get())->G.value == 8e4);
      CHECK(static_cast<mat1*>(current.get())->NU.value == .3);
      CHECK(static_cast<mat1*>(current.get())->RHO.value == 7.85e-6);
      CHECK_FALSE(static_cast<mat1*>(current.get())->A);
      CHECK_FALSE(static_cast<mat1*>(current.get())->TREF);
      CHECK_FALSE(static_cast<mat1*>(current.get())->GE);
      CHECK_FALSE(static_cast<mat1*>(current.get())->ST);
      CHECK_FALSE(static_cast<mat1*>(current.get())->SC);
      CHECK_FALSE(static_cast<mat1*>(current.get())->SS);
      CHECK_FALSE(static_cast<mat1*>(current.get())->MCSID);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      // PBEAML  104010  4               L
      //           63.0   340.0    35.0    14.0
      CHECK(current->card_type() == cards::PBEAML);
      CHECK(static_cast<pbeaml*>(current.get())->PID.value == 104010);
      CHECK(static_cast<pbeaml*>(current.get())->MID.value == 4);
      CHECK(static_cast<pbeaml*>(current.get())->GROUP.value == "MSCBML0");
      CHECK(static_cast<pbeaml*>(current.get())->TYPE.value == "L");
      CHECK(static_cast<pbeaml*>(current.get())->DIM.size() == 1);
      CHECK(static_cast<pbeaml*>(current.get())->DIM[0] ==
            std::list<double>({63., 340., 35., 14.}));
      CHECK(static_cast<pbeaml*>(current.get())->NSM.size() == 1);
      CHECK(static_cast<pbeaml*>(current.get())->NSM ==
            std::list<double>({0.}));
      CHECK(static_cast<pbeaml*>(current.get())->SO.size() == 0);
      CHECK(static_cast<pbeaml*>(current.get())->X_XB.size() == 0);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      // PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6
      CHECK(current->card_type() == cards::PBEAM);
      CHECK(static_cast<pbeam*>(current.get())->PID.value == 4000001);
      CHECK(static_cast<pbeam*>(current.get())->MID.value == 3);
      CHECK(static_cast<pbeam*>(current.get())->A ==
            std::list<double>({10460.}));
      CHECK(static_cast<pbeam*>(current.get())->I1 ==
            std::list<double>({93690000.}));
      CHECK(static_cast<pbeam*>(current.get())->I2 ==
            std::list<double>({1694000.}));
      CHECK(static_cast<pbeam*>(current.get())->I12 ==
            std::list<double>({6.856e6}));
      CHECK(static_cast<pbeam*>(current.get())->J ==
            std::list<double>({1.316e6}));

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      // PROD    6000001 1       3000.00\n"
      CHECK(current->card_type() == cards::PROD);
      CHECK(static_cast<prod*>(current.get())->PID.value == 6000001);
      CHECK(static_cast<prod*>(current.get())->MID.value == 1);
      CHECK(static_cast<prod*>(current.get())->A.value == 3000);
      CHECK_FALSE(static_cast<prod*>(current.get())->J);
      CHECK(static_cast<prod*>(current.get())->C.value == 0.);
      CHECK_FALSE(static_cast<prod*>(current.get())->NSM);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::PSHELL);
      // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      //         PID     MID1    T       MID2    12I/T**3 MID3
      // PSHELL  1       4         23.00 4               4
      CHECK(static_cast<pshell*>(current.get())->PID.value == 1);
      CHECK(static_cast<pshell*>(current.get())->MID1.value == 4);
      CHECK(static_cast<pshell*>(current.get())->T.value == 23.);
      CHECK(static_cast<pshell*>(current.get())->MID2.value == 4);
      CHECK(static_cast<pshell*>(current.get())->x12I_T__3.value == 1.);
      CHECK(static_cast<pshell*>(current.get())->MID3.value == 4);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::GRID);
      CHECK(static_cast<grid*>(current.get())->ID.value == 1);
      CHECK(static_cast<grid*>(current.get())->X1.value == 111525.);
      CHECK(static_cast<grid*>(current.get())->X2.value == 18000.);
      CHECK(static_cast<grid*>(current.get())->X3.value == 21000.);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::GRID);
      CHECK(static_cast<grid*>(current.get())->ID.value == 76);
      CHECK(static_cast<grid*>(current.get())->X1.value == 111522.);
      CHECK(static_cast<grid*>(current.get())->X2.value == 18002.);
      CHECK(static_cast<grid*>(current.get())->X3.value == 21002.);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::GRID);
      CHECK(static_cast<grid*>(current.get())->ID.value == 153);
      CHECK(static_cast<grid*>(current.get())->X1.value == 111522.);
      CHECK(static_cast<grid*>(current.get())->X2.value == 18001.);
      CHECK(static_cast<grid*>(current.get())->X3.value == 21002.);

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::CQUAD4);
      // "CQUAD4  1       1       16      200     141     17\n"


      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::CQUAD4);
      //  45678|234567890123456|234567890123456|234567890123456|234567890123456|2
      // "CQUAD4* 2               1               16              200             "
      // "+\n"
      // "+       140             15\n"

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::CTRIA3);
      // "CTRIA3  2606    1       1066    1065    1133\n"

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::CBEAM);
      // "CBEAM   7869    104010  76      153     0.0     66.5206 997.785\n"
      // "                        0.0     -22.617 -339.25 0.0     -22.617 -339.25\n"

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::CROD);
      // "CROD    11316   6000001 1028    2139\n"

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::CBEAM);
      //"CBEAM    465144 104010  76      153     1.       0.      0.\n"

      probe.get(l);
      CAPTURE( l.front() );
      __base::card::card_split(l, data);
      cards::dispatch(data, current);
      CHECK(current->card_type() == cards::ENDDATA);
   }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// coding: utf-8
// End:
