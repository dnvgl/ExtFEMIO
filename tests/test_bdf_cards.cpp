/**
   \file tests/test_bdf_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF cards classes.

   Detailed description
*/

// ID:
namespace {
    char const cID_test_bdf_cards[]
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

#include "config.h"

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
    return Catch::toString( ex.what() );
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
        CHECK(current->card_type() == cards::types::MAT1);
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
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::MAT1);
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
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        // PBEAML  104010  4               L
        //           63.0   340.0    35.0    14.0
        CHECK(current->card_type() == cards::types::PBEAML);
        CHECK(static_cast<pbeaml*>(current.get())->PID.value == 104010);
        CHECK(static_cast<pbeaml*>(current.get())->MID.value == 4);
        CHECK(static_cast<pbeaml*>(current.get())->GROUP.value == "MSCBML0");
        CHECK(static_cast<pbeaml*>(current.get())->TYPE.value == "L");
        CHECK(static_cast<pbeaml*>(current.get())->DIM.size() == 1);
        CHECK(static_cast<pbeaml*>(current.get())->DIM[0] ==
              std::vector<double>({63., 340., 35., 14.}));
        CHECK(static_cast<pbeaml*>(current.get())->NSM.size() == 1);
        CHECK(static_cast<pbeaml*>(current.get())->NSM ==
              std::vector<double>({0.}));
        CHECK(static_cast<pbeaml*>(current.get())->SO.size() == 0);
        CHECK(static_cast<pbeaml*>(current.get())->X_XB.size() == 0);
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        // PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6
        CHECK(current->card_type() == cards::types::PBEAM);
        CHECK(static_cast<pbeam*>(current.get())->PID.value == 4000001);
        CHECK(static_cast<pbeam*>(current.get())->MID.value == 3);
        CHECK(static_cast<pbeam*>(current.get())->A ==
              std::vector<double>({10460.}));
        CHECK(static_cast<pbeam*>(current.get())->I1 ==
              std::vector<double>({93690000.}));
        CHECK(static_cast<pbeam*>(current.get())->I2 ==
              std::vector<double>({1694000.}));
        CHECK(static_cast<pbeam*>(current.get())->I12 ==
              std::vector<double>({6.856e6}));
        CHECK(static_cast<pbeam*>(current.get())->J ==
              std::vector<double>({1.316e6}));
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        // PROD    6000001 1       3000.00\n"
        CHECK(current->card_type() == cards::types::PROD);
        CHECK(static_cast<prod*>(current.get())->PID.value == 6000001);
        CHECK(static_cast<prod*>(current.get())->MID.value == 1);
        CHECK(static_cast<prod*>(current.get())->A.value == 3000);
        CHECK_FALSE(static_cast<prod*>(current.get())->J);
        CHECK(static_cast<prod*>(current.get())->C.value == 0.);
        CHECK_FALSE(static_cast<prod*>(current.get())->NSM);
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::PSHELL);
        // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
        //         PID     MID1    T       MID2    12I/T**3 MID3
        // PSHELL  1       4         23.00 4               4
        CHECK(static_cast<pshell*>(current.get())->PID.value == 1);
        CHECK(static_cast<pshell*>(current.get())->MID1.value == 4);
        CHECK(static_cast<pshell*>(current.get())->T.value == 23.);
        CHECK(static_cast<pshell*>(current.get())->MID2.value == 4);
        CHECK(static_cast<pshell*>(current.get())->x12I_T__3.value == 1.);
        CHECK(static_cast<pshell*>(current.get())->MID3.value == 4);
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::GRID);
        CHECK(static_cast<grid*>(current.get())->ID.value == 1);
        CHECK(static_cast<grid*>(current.get())->X1.value == 111525.);
        CHECK(static_cast<grid*>(current.get())->X2.value == 18000.);
        CHECK(static_cast<grid*>(current.get())->X3.value == 21000.);
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::GRID);
        CHECK(static_cast<grid*>(current.get())->ID.value == 76);
        CHECK(static_cast<grid*>(current.get())->X1.value == 111522.);
        CHECK(static_cast<grid*>(current.get())->X2.value == 18002.);
        CHECK(static_cast<grid*>(current.get())->X3.value == 21002.);
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::GRID);
        CHECK(static_cast<grid*>(current.get())->ID.value == 153);
        CHECK(static_cast<grid*>(current.get())->X1.value == 111522.);
        CHECK(static_cast<grid*>(current.get())->X2.value == 18001.);
        CHECK(static_cast<grid*>(current.get())->X3.value == 21002.);
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::CQUAD4);
        // "CQUAD4  1       1       16      200     141     17\n"
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::CQUAD4);
        //  45678|234567890123456|234567890123456|234567890123456|234567890123456|2
        // "CQUAD4* 2               1               16              200             "
        // "+\n"
        // "+       140             15\n"
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::CTRIA3);
        // "CTRIA3  2606    1       1066    1065    1133\n"
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::CBEAM);
        // "CBEAM   7869    104010  76      153     0.0     66.5206 997.785\n"
        // "                        0.0     -22.617 -339.25 0.0     -22.617 -339.25\n"
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::CROD);
        // "CROD    11316   6000001 1028    2139\n"
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::CBEAM);
        //"CBEAM    465144 104010  76      153     1.       0.      0.\n"
        current.reset();

        probe.get(l);
        CAPTURE( l.front() );
        __base::card::card_split(l, data);
        cards::dispatch(data, current);
        CHECK(current->card_type() == cards::types::ENDDATA);
    }
}

TEST_CASE("Test partial supported element cards.", "[elem cards]") {

    std::unique_ptr<cards::__base::card> probe;

    SECTION("CAABSF") {
        std::list<std::string> data({ "CAABSF,44,38,1,10,20" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 44);
    }

    SECTION("CAERO1") {
        std::list<std::string> data({
                "CAERO1,1000,1,,3,,,2,1,0.,0.,0.,1.,.2,1.,0.,.8" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1000);
    }

    SECTION("CAERO2") {
        std::list<std::string> data({
                "CAERO2,1500,2,100,,4,99,,1,-1.,100.,-30.,175." });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1500);
    }

    SECTION("CAERO3") {
        std::list<std::string> data({
                "CAERO3,2000,2001,0,22,33,,,,1.,0.,0.,100.,17.130,0.,100." });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2000);
    }

    SECTION("CAERO4") {
        std::list<std::string> data({
                "CAERO4,6000,6001,100,,315,,,,0.0,0.0,0.0,1.0,0.2,1.0,0.0,0.8" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 6000);
    }

    SECTION("CAERO5") {
        std::list<std::string> data({
                "CAERO5,6000,6001,100,,315,0,0,,0.0,0.0,0.0,1.0,0.2,1.0,0.,0.8" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 6000);
    }

    SECTION("CAXIF2") {
        std::list<std::string> data({
                "CAXIF2,11,23,25,,,0.25E-3" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 11);
    }

    SECTION("CAXIF3") {
        std::list<std::string> data({
                "CAXIF3,105,31,32,33,,6.47E-3" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 105);
    }

    SECTION("CAXIF4") {
        std::list<std::string> data({
                "CAXIF4,524,421,425,424,422,0.5E-3,2.5+3" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 524);
    }

    SECTION("CBEND") {
        std::list<std::string> data({
                "CBEND,32,39,17,19,6.2,5.1,-1.2" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 32);
    }

    SECTION("CBEND (alt)") {
        std::list<std::string> data({
                "CBEND,32,39,17,19,106" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 32);
    }

    SECTION("CBUSH (1)") {
        std::list<std::string> data({
                "CBUSH,39,6,1,100,75" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
    }

    SECTION("CBUSH (2)") {
        std::list<std::string> data({
                "CBUSH,39,6,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
    }

    SECTION("CBUSH (3)") {
        std::list<std::string> data({
                "CBUSH,39,6,1,100" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
    }

    SECTION("CBUSH (4)") {
        std::list<std::string> data({
                "CBUSH,39,6,1,600,0.25,10,0.,10.,10." });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
    }

    SECTION("CBUSH1D") {
        std::list<std::string> data({
                "CBUSH1D,35,102,108,112" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 35);
    }

    SECTION("CBUTT") {
        std::list<std::string> data({
                "CBUTT,1002,11,5,0,0,3,1,,0.005,.07,,2.5,4.0,2.0,1.5" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
    }

    SECTION("CCONEAX") {
        std::list<std::string> data({
                "CCONEAX,1,2,3,4" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1);
    }

    SECTION("CCRSFIL") {
        std::list<std::string> data({
                "CCRSFIL,1002,11,5,0,0,2,1,,0.005,,40000.,2.5,4.,3.,2.,"
                    "25.0,101,201,11,,,,,,0.006,,45000.,2.6,4.5,3.2,2.2,"
                    "22.0,103,203,15" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
    }

    SECTION("CDAMP1") {
        std::list<std::string> data({
                "CDAMP1,19,6,0,,23,2" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 19);
    }

    SECTION("CDAMP1D") {
        std::list<std::string> data({
                "CDAMP1D,1001,101,55,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
    }

    SECTION("CDAMP2") {
        std::list<std::string> data({
                "CDAMP2,16,2.98,32,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 16);
    }

    SECTION("CDAMP2D") {
        std::list<std::string> data({
                "CDAMP2D,1001,101,55,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
    }

    SECTION("CDAMP3") {
        std::list<std::string> data({
                "CDAMP3,16,978,24,36" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 16);
    }

    SECTION("CDAMP4") {
        std::list<std::string> data({
                "CDAMP4,16,-2.6,4,9" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 16);
    }

    SECTION("CDAMP5") {
        std::list<std::string> data({
                "CDAMP5,1,4,10,20" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1);
    }

    SECTION("CDUM1") {
        std::list<std::string> data({
                "CDUM1,114,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 114);
    }

    SECTION("CDUM2") {
        std::list<std::string> data({
                "CDUM2,124,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 124);
    }

    SECTION("CDUM3") {
        std::list<std::string> data({
                "CDUM3,134,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 134);
    }

    SECTION("CDUM4") {
        std::list<std::string> data({
                "CDUM4,144,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 144);
    }

    SECTION("CDUM5") {
        std::list<std::string> data({
                "CDUM5,154,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 154);
    }

    SECTION("CDUM6") {
        std::list<std::string> data({
                "CDUM6,164,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 164);
    }

    SECTION("CDUM7") {
        std::list<std::string> data({
                "CDUM7,174,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 174);
    }

    SECTION("CDUM8") {
        std::list<std::string> data({
                "CDUM8,184,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 184);
    }

    SECTION("CDUM9") {
        std::list<std::string> data({
                "CDUM9,194,108,2,5,6,8,11,,2.4,,3.E4,2,,50" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 194);
    }

    SECTION("CELAS1") {
        std::list<std::string> data({
                "CELAS1,2,6,,,8,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
    }

    SECTION("CELAS1D") {
        std::list<std::string> data({
                "CELAS1D,1001,101,55,1,8,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
    }

    SECTION("CELAS2") {
        std::list<std::string> data({
                "CELAS2,28,6.2+3,32,,19,4" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 28);
    }

    SECTION("CELAS2D") {
        std::list<std::string> data({
                "CELAS2D,1001,101,55,1,8,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
    }

    SECTION("CELAS3") {
        std::list<std::string> data({
                "CELAS3,19,2,14,15" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 19);
    }

    SECTION("CELAS4") {
        std::list<std::string> data({
                "CELAS4,42,6.2-3,2" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 42);
    }

    SECTION("CFILLET") {
        std::list<std::string> data({
                "CFILLET,1002,11,5,0,0,3,1,,0.005,.07,,2.5,4.0,3.0,2.0,25.0" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
    }

    SECTION("CFLUID2") {
        std::list<std::string> data({
                "CFLUID2,100,11,14,,,.025,0.0" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 100);
    }

    SECTION("CFLUID3") {
        std::list<std::string> data({
                "CFLUID3,110,15,13,12,,1.2" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 110);
    }

    SECTION("CFLUID4") {
        std::list<std::string> data({
                "CFLUID4,120,11,15,12,6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 120);
    }

    SECTION("CGAP (1)") {
        std::list<std::string> data({
                "CGAP,17,2,110,112,5.2,0.3,-6.1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 17);
    }

    SECTION("CGAP (2)") {
        std::list<std::string> data({
                "CGAP,17,2,110,112,13" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 17);
    }

    SECTION("CHACAB") {
        std::list<std::string> data({
                "CHACAB,95,12,1,2,5,7,8,9,24,23" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 95);
    }

    SECTION("CHACBR") {
        std::list<std::string> data({
                "CHACBR,95,12,1,2,5,7,8,9,24,23" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 95);
    }

    SECTION("CHBDYE") {
        std::list<std::string> data({
                "CHBDYE,2,10,1,3,3,2,2" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
    }

    SECTION("CHBDYG") {
        std::list<std::string> data({
                "CHBDYG,2,,AREA4,3,3,2,2,,100,103,102,101" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
    }

    SECTION("CHBDYP") {
        std::list<std::string> data({
                "CHBDYP,2,5,POINT,2,2,101,,500,3,3,,,0.0,0.0,1.0" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
    }

    SECTION("CHEXA") {
        std::list<std::string> data({
                "CHEXA,71,4,3,4,5,6,7,8,9,10,0,0,30,31,53,54,55,56,57,58,59,60" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 71);
    }

    SECTION("CMASS1") {
        std::list<std::string> data({
                "CMASS1,32,6,2,1" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 32);
    }

    SECTION("CMASS3") {
        std::list<std::string> data({
                "CMASS3,13,42,62" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 13);
    }

    SECTION("COMBWLD") {
        std::list<std::string> data({
                "COMBWLD,1002,11,,0,0,12,1,,,,"
                    "44000.,2.5,4.0,3.0,2.0,22.5,,,,"
                    "42000.,2.5,2.0,1.25,0.75,-22.5,"
                    "101,201,1,1,,,,28.6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
    }

    SECTION("CONM1") {
        std::list<std::string> data({
                "CONM1,2,22,2,2.9,6.3,,,,4.8,28.6,,,,,,,,28.6,,,,,,28.6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
    }

    SECTION("CONM2") {
        std::list<std::string> data({
                "CONM2,2,15,6,49.7,,,,,16.2,,16.2,,,7.8" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
    }

    SECTION("CONROD") {
        std::list<std::string> data({
                "CONROD,2,16,17,4,2.69" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
    }

    SECTION("CPENTA") {
        std::list<std::string> data({
                "CPENTA,112,2,3,15,14,4,103,115,5,16,8,,,,120,125,130" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 112);
    }

    SECTION("CQUAD") {
        std::list<std::string> data({
                "CQUAD,111,203,31,74,75,32" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
    }

    SECTION("CQUAD8") {
        std::list<std::string> data({
                "CQUAD8,207,3,31,33,73,71,32,51,53,72,0.125,0.025,0.030,"
                    ".025,30.,.03" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 207);
    }

    SECTION("CQUADR") {
        std::list<std::string> data({
                "CQUADR,82,203,31,74,75,32,2.6,,,1.77,2.04,2.09,1.80" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 82);
    }

    SECTION("CQUADX") {
        std::list<std::string> data({
                "CQUADX,111,203,31,74,75,32" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
    }

    SECTION("CRAC2D") {
        std::list<std::string> data({
                "CRAC2D,114,108,2,5,6,8,7,11,12,14,16,17,,20,22" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 114);
    }

    SECTION("CRAC3D") {
        std::list<std::string> data({
                "CRAC3D,113,101,2,5,7,8,4,10,11,14,15,17,,3,6,9,12,,16,,"
                    "102,105,107,108,115,117,,103,104,110,111,114,115,117,,"
                    "103,106,109,112,,116,,202,205,207,208,204,210,211,"
                    "214,215,217,225,226" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 113);
    }

    SECTION("CSHEAR") {
        std::list<std::string> data({
                "CSHEAR,3,6,1,5,3,7" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 3);
    }

    SECTION("CSLOT3") {
        std::list<std::string> data({
                "CSLOT3,100,1,3,2,,3.0-3,,6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 100);
    }

    SECTION("CSLOT4") {
        std::list<std::string> data({
                "CSLOT4,101,1,3,2,4,,6.2+4,3" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 101);
    }

    SECTION("CSPOT") {
        std::list<std::string> data({
                "CSPOT,1001,,11,5,0,0,,1,,0.005,.07" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
    }

    SECTION("CTETRA") {
        std::list<std::string> data({
                "CTETRA,112,2,3,15,14,4,103,115,5,16,8,27" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 112);
    }

    SECTION("CTRIA6") {
        std::list<std::string> data({
                "CTRIA6,302,3,31,33,71,32,51,52,45,.03,.020,.025,.025" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 302);
    }

    SECTION("CTRIAR") {
        std::list<std::string> data({
                "CTRIAR,111,203,31,74,75,3.0,,,,,1.77,2.04,2.09" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
    }

    SECTION("CTRIAX") {
        std::list<std::string> data({
                "CTRIAX,111,203,31,74,75" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
    }

    SECTION("CTRIAX6") {
        std::list<std::string> data({
                "CTRIAX6,22,999,10,11,12,21,22,32,9.0" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 22);
    }

    SECTION("CTUBE") {
        std::list<std::string> data({
                "CTUBE,12,13,21,23" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 12);
    }

    SECTION("CVISC") {
        std::list<std::string> data({
                "CVISC,21,6327,29,31" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 21);
    }

    SECTION("GENEL") {
        std::list<std::string> data({
                "GENEL,629,,1,1,13,4,42,0,"
                    "24,2,,,,,,,"
                    "UD,,6,2,33,0,,,"
                    "Z,1.0,2.0,3.0,4.0,5.0,6.0,7.0,"
                    "8.0,9.0,10.0,,,,,,,"
                    "S,1.5,2.5,3.5,4.5,5.5,6.5,7.5,"
                    "8.5" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 629);
    }

    SECTION("GMINTC") {
        std::list<std::string> data({
                "GMINTC,1001,1,1,2" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
    }

    SECTION("GMINTS") {
        std::list<std::string> data({
                "GMINTS,1001,1,1,2" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001 );
    }

    SECTION("PLOTEL") {
        std::list<std::string> data({
                "PLOTEL,29,35,16" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 29);
    }

    SECTION("RBAR") {
        std::list<std::string> data({
                "RBAR,5,1,2,123456,,,,6.5-6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
    }

    SECTION("RBAR1") {
        std::list<std::string> data({
                "RBAR1,5,1,2,123,6.5-6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
    }

    SECTION("RBE1") {
        std::list<std::string> data({
                "RBE1,59,59,123456,,,,,,"
                    "UM,61,246,6.5-6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 59);
    }

    SECTION("RBE2") {
        std::list<std::string> data({
                "RBE2,9,8,12,10,12,14,15,16,"
                    "20,6.5-6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 9);
    }

    SECTION("RBE3") {
        std::list<std::string> data({
                "RBE3,14,,100,1234,1.0,123,1,3,"
                    "5,4.7,1,2,4,6,5.2,2,"
                    "7,8,9,5.1,1,15,16,,"
                    "UM,100,14,5,3,7,2,,"
                    "ALPHA,6.5-6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 14);
    }

    SECTION("RBE3D (1)") {
        std::list<std::string> data({
                "RBE3D,51,11,123,,,,,,"
                    "101,123,0.5,0.5,0.5,,,,"
                    "102,123,0.5,0.5,0.5" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 51);
    }

    SECTION("RBE3D (2)") {
        std::list<std::string> data({
                "RBE3D,51,11,123,4,8,,,LOCAL1,"
                    "101,123,0.5,0.5,0.5,,,,"
                    "102,123,0.5,0.5,0.5" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 51);
    }

    SECTION("RBE3D") {
        std::list<std::string> data({
                "RBE3D,51,11,123,4,,,,LOCAL2,"
                    "8,,,,,,,,"
                    "101,123,0.5,0.5,0.5,,,,"
                    "25,,,,,,,,"
                    "102,123,0.5,0.5,0.5" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 51);
    }

    SECTION("RJOINT") {
        std::list<std::string> data({
                "RJOINT,5,1,2,12345" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
    }

    SECTION("RROD") {
        std::list<std::string> data({
                "RROD,14,1,2,2,,6.5-6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 14);
    }

    SECTION("RSPLINE") {
        std::list<std::string> data({
                "RSPLINE,73,.05,27,28,123456,29,,30,"
                    "123,75,123,71" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 73);
    }

    SECTION("RSSCON (1)") {
        std::list<std::string> data({
                "RSSCON,110,GRID,11,12,13,14,15,16" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 110);
    }

    SECTION("RSSCON (2)") {
        std::list<std::string> data({
                "RSSCON,111,GRID,31,74,75" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
    }

    SECTION("RSSCON (3)") {
        std::list<std::string> data({
                "RSSCON,115,ELEM,311,741" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 115);
    }

    SECTION("RTRPLT") {
        std::list<std::string> data({
                "RTRPLT,7,1,2,3,1236,3,3" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 7);
    }

    SECTION("RTRPLT1") {
        std::list<std::string> data({
                "RTRPLT1,7,1,2,3,1236,3,6.0-6" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 7);
    }

    SECTION("SPLINE1") {
        std::list<std::string> data({
                "SPLINE1,3,111,115,122,14,0." });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 3);
    }

    SECTION("SPLINE2") {
        std::list<std::string> data({
                "SPLINE2,5,8,12,24,60,0.,1.0,3,"
                    "1." });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
    }

    SECTION("SPLINE3") {
        std::list<std::string> data({
                "SPLINE3,7000,107,109,6,5,3,1.0,,"
                    "43,5,-1.0" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 7000);
    }

    SECTION("SPLINE4") {
        std::list<std::string> data({
                "SPLINE4,3,111,115,,14,0.,IPS" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 3);
    }

    SECTION("SPLINE5") {
        std::list<std::string> data({
                "SPLINE5,5,8,12,,60,,,3,1.,,,BOTH" });
        std::list<std::string> l;
        __base::card::card_split(data, l);
        cards::dispatch(l, probe);

        CHECK(probe->card_type() == cards::types::ELEMENT);
        CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// coding: utf-8
// End:
