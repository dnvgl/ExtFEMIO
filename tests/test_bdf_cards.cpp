/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF cards classes.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_test_bdf_cards[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <list>

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"
#include "bdf/file.h"
#include "bdf/cards_elements.h"

#include "catch_list_helper.h"
#include "catch_vector_helper.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace bdf::cards;
using namespace bdf::cards::__base;
using namespace input;

using bdf::types::entry_type;
using bdf::types::entry_value;

TEST_CASE("BDF test card enum output", "[bdf_cards]") {

    std::ostringstream test;

    SECTION("multiple entries"){
        test << cards::types::CCRSFIL << " " << cards::types::MAT1;
        CHECK(test.str() == "CCRSFIL MAT1");
    }

    SECTION("output GRID") {
        test << cards::types::GRID;
        CHECK(test.str() == "GRID");
    }

    SECTION("output CBAR") {
        test << cards::types::CBAR;
        CHECK(test.str() == "CBAR");
    }

    SECTION("output CBEAM") {
        test << cards::types::CBEAM;
        CHECK(test.str() == "CBEAM");
    }

    SECTION("output CBEND") {
        test << cards::types::CBEND;
        CHECK(test.str() == "CBEND");
    }

    SECTION("output CONROD") {
        test << cards::types::CONROD;
        CHECK(test.str() == "CONROD");
    }

    SECTION("output CROD") {
        test << cards::types::CROD;
        CHECK(test.str() == "CROD");
    }

    SECTION("output CTUBE") {
        test << cards::types::CTUBE;
        CHECK(test.str() == "CTUBE");
    }

    SECTION("output PBAR") {
        test << cards::types::PBAR;
        CHECK(test.str() == "PBAR");
    }

    SECTION("output PBARL") {
        test << cards::types::PBARL;
        CHECK(test.str() == "PBARL");
    }

    SECTION("output PBEAM") {
        test << cards::types::PBEAM;
        CHECK(test.str() == "PBEAM");
    }

    SECTION("output PBEAML") {
        test << cards::types::PBEAML;
        CHECK(test.str() == "PBEAML");
    }

    SECTION("output PROD") {
        test << cards::types::PROD;
        CHECK(test.str() == "PROD");
    }

    SECTION("output CQUAD") {
        test << cards::types::CQUAD;
        CHECK(test.str() == "CQUAD");
    }

    SECTION("output CQUAD4") {
        test << cards::types::CQUAD4;
        CHECK(test.str() == "CQUAD4");
    }

    SECTION("output CQUAD8") {
        test << cards::types::CQUAD8;
        CHECK(test.str() == "CQUAD8");
    }

    SECTION("output CQUADR") {
        test << cards::types::CQUADR;
        CHECK(test.str() == "CQUADR");
    }

    SECTION("output CSHEAR") {
        test << cards::types::CSHEAR;
        CHECK(test.str() == "CSHEAR");
    }

    SECTION("output CTRIA3") {
        test << cards::types::CTRIA3;
        CHECK(test.str() == "CTRIA3");
    }

    SECTION("output CTRIA6") {
        test << cards::types::CTRIA6;
        CHECK(test.str() == "CTRIA6");
    }

    SECTION("output CTRIAR") {
        test << cards::types::CTRIAR;
        CHECK(test.str() == "CTRIAR");
    }

    SECTION("output PSHELL") {
        test << cards::types::PSHELL;
        CHECK(test.str() == "PSHELL");
    }

    SECTION("output CHEXA") {
        test << cards::types::CHEXA;
        CHECK(test.str() == "CHEXA");
    }

    SECTION("output CPENTA") {
        test << cards::types::CPENTA;
        CHECK(test.str() == "CPENTA");
    }

    SECTION("output CTETRA") {
        test << cards::types::CTETRA;
        CHECK(test.str() == "CTETRA");
    }

    SECTION("output CBUSH") {
        test << cards::types::CBUSH;
        CHECK(test.str() == "CBUSH");
    }

    SECTION("output CBUSH1D") {
        test << cards::types::CBUSH1D;
        CHECK(test.str() == "CBUSH1D");
    }

    SECTION("output CELAS1") {
        test << cards::types::CELAS1;
        CHECK(test.str() == "CELAS1");
    }

    SECTION("output CELAS2") {
        test << cards::types::CELAS2;
        CHECK(test.str() == "CELAS2");
    }

    SECTION("output CELAS3") {
        test << cards::types::CELAS3;
        CHECK(test.str() == "CELAS3");
    }

    SECTION("output CELAS4") {
        test << cards::types::CELAS4;
        CHECK(test.str() == "CELAS4");
    }

    SECTION("output GENEL") {
        test << cards::types::GENEL;
        CHECK(test.str() == "GENEL");
    }

    SECTION("output GMINTC") {
        test << cards::types::GMINTC;
        CHECK(test.str() == "GMINTC");
    }

    SECTION("output GMINTS") {
        test << cards::types::GMINTS;
        CHECK(test.str() == "GMINTS");
    }

    SECTION("output CCONEAX") {
        test << cards::types::CCONEAX;
        CHECK(test.str() == "CCONEAX");
    }

    SECTION("output CQUADX") {
        test << cards::types::CQUADX;
        CHECK(test.str() == "CQUADX");
    }

    SECTION("output CTRIAX") {
        test << cards::types::CTRIAX;
        CHECK(test.str() == "CTRIAX");
    }

    SECTION("output CTRIAX6") {
        test << cards::types::CTRIAX6;
        CHECK(test.str() == "CTRIAX6");
    }

    SECTION("output RBAR") {
        test << cards::types::RBAR;
        CHECK(test.str() == "RBAR");
    }

    SECTION("output RBAR1") {
        test << cards::types::RBAR1;
        CHECK(test.str() == "RBAR1");
    }

    SECTION("output RBE1") {
        test << cards::types::RBE1;
        CHECK(test.str() == "RBE1");
    }

    SECTION("output RBE2") {
        test << cards::types::RBE2;
        CHECK(test.str() == "RBE2");
    }

    SECTION("output RBE3") {
        test << cards::types::RBE3;
        CHECK(test.str() == "RBE3");
    }

    SECTION("output RJOINT") {
        test << cards::types::RJOINT;
        CHECK(test.str() == "RJOINT");
    }

    SECTION("output RROD") {
        test << cards::types::RROD;
        CHECK(test.str() == "RROD");
    }

    SECTION("output RSPLINE") {
        test << cards::types::RSPLINE;
        CHECK(test.str() == "RSPLINE");
    }

    SECTION("output RSSCON") {
        test << cards::types::RSSCON;
        CHECK(test.str() == "RSSCON");
    }

    SECTION("output RTRPLT") {
        test << cards::types::RTRPLT;
        CHECK(test.str() == "RTRPLT");
    }

    SECTION("output RTRPLT1") {
        test << cards::types::RTRPLT1;
        CHECK(test.str() == "RTRPLT1");
    }

    SECTION("output CMASS1") {
        test << cards::types::CMASS1;
        CHECK(test.str() == "CMASS1");
    }

    SECTION("output CMASS2") {
        test << cards::types::CMASS2;
        CHECK(test.str() == "CMASS2");
    }

    SECTION("output CMASS3") {
        test << cards::types::CMASS3;
        CHECK(test.str() == "CMASS3");
    }

    SECTION("output CMASS4") {
        test << cards::types::CMASS4;
        CHECK(test.str() == "CMASS4");
    }

    SECTION("output CONM1") {
        test << cards::types::CONM1;
        CHECK(test.str() == "CONM1");
    }

    SECTION("output CONM2") {
        test << cards::types::CONM2;
        CHECK(test.str() == "CONM2");
    }

    SECTION("output CDAMP1") {
        test << cards::types::CDAMP1;
        CHECK(test.str() == "CDAMP1");
    }

    SECTION("output CDAMP2") {
        test << cards::types::CDAMP2;
        CHECK(test.str() == "CDAMP2");
    }

    SECTION("output CDAMP3") {
        test << cards::types::CDAMP3;
        CHECK(test.str() == "CDAMP3");
    }

    SECTION("output CDAMP4") {
        test << cards::types::CDAMP4;
        CHECK(test.str() == "CDAMP4");
    }

    SECTION("output CDAMP5") {
        test << cards::types::CDAMP5;
        CHECK(test.str() == "CDAMP5");
    }

    SECTION("output CVISC") {
        test << cards::types::CVISC;
        CHECK(test.str() == "CVISC");
    }

    SECTION("output CAABSF") {
        test << cards::types::CAABSF;
        CHECK(test.str() == "CAABSF");
    }

    SECTION("output CAXIF2") {
        test << cards::types::CAXIF2;
        CHECK(test.str() == "CAXIF2");
    }

    SECTION("output CAXIF3") {
        test << cards::types::CAXIF3;
        CHECK(test.str() == "CAXIF3");
    }

    SECTION("output CAXIF4") {
        test << cards::types::CAXIF4;
        CHECK(test.str() == "CAXIF4");
    }

    SECTION("output CFLUID2") {
        test << cards::types::CFLUID2;
        CHECK(test.str() == "CFLUID2");
    }

    SECTION("output CFLUID3") {
        test << cards::types::CFLUID3;
        CHECK(test.str() == "CFLUID3");
    }

    SECTION("output CFLUID4") {
        test << cards::types::CFLUID4;
        CHECK(test.str() == "CFLUID4");
    }

    SECTION("output CHACAB") {
        test << cards::types::CHACAB;
        CHECK(test.str() == "CHACAB");
    }

    SECTION("output CHACBR") {
        test << cards::types::CHACBR;
        CHECK(test.str() == "CHACBR");
    }

    SECTION("output CSLOT3") {
        test << cards::types::CSLOT3;
        CHECK(test.str() == "CSLOT3");
    }

    SECTION("output CSLOT4") {
        test << cards::types::CSLOT4;
        CHECK(test.str() == "CSLOT4");
    }

    SECTION("output CHBDYE") {
        test << cards::types::CHBDYE;
        CHECK(test.str() == "CHBDYE");
    }

    SECTION("output CHBDYG") {
        test << cards::types::CHBDYG;
        CHECK(test.str() == "CHBDYG");
    }

    SECTION("output CHBDYP") {
        test << cards::types::CHBDYP;
        CHECK(test.str() == "CHBDYP");
    }

    SECTION("output CDUM1") {
        test << cards::types::CDUM1;
        CHECK(test.str() == "CDUM1");
    }

    SECTION("output CDUM2") {
        test << cards::types::CDUM2;
        CHECK(test.str() == "CDUM2");
    }

    SECTION("output CDUM3") {
        test << cards::types::CDUM3;
        CHECK(test.str() == "CDUM3");
    }

    SECTION("output CDUM4") {
        test << cards::types::CDUM4;
        CHECK(test.str() == "CDUM4");
    }

    SECTION("output CDUM5") {
        test << cards::types::CDUM5;
        CHECK(test.str() == "CDUM5");
    }

    SECTION("output CDUM6") {
        test << cards::types::CDUM6;
        CHECK(test.str() == "CDUM6");
    }

    SECTION("output CDUM7") {
        test << cards::types::CDUM7;
        CHECK(test.str() == "CDUM7");
    }

    SECTION("output CDUM8") {
        test << cards::types::CDUM8;
        CHECK(test.str() == "CDUM8");
    }

    SECTION("output CDUM9") {
        test << cards::types::CDUM9;
        CHECK(test.str() == "CDUM9");
    }

    SECTION("output PLOTEL") {
        test << cards::types::PLOTEL;
        CHECK(test.str() == "PLOTEL");
    }

    SECTION("output CGAP") {
        test << cards::types::CGAP;
        CHECK(test.str() == "CGAP");
    }

    SECTION("output CRAC2D") {
        test << cards::types::CRAC2D;
        CHECK(test.str() == "CRAC2D");
    }

    SECTION("output CRAC3D") {
        test << cards::types::CRAC3D;
        CHECK(test.str() == "CRAC3D");
    }

    SECTION("output CAERO1") {
        test << cards::types::CAERO1;
        CHECK(test.str() == "CAERO1");
    }

    SECTION("output CAERO2") {
        test << cards::types::CAERO2;
        CHECK(test.str() == "CAERO2");
    }

    SECTION("output CAERO3") {
        test << cards::types::CAERO3;
        CHECK(test.str() == "CAERO3");
    }

    SECTION("output CAERO4") {
        test << cards::types::CAERO4;
        CHECK(test.str() == "CAERO4");
    }

    SECTION("output CAERO5") {
        test << cards::types::CAERO5;
        CHECK(test.str() == "CAERO5");
    }

    SECTION("output SPLINE1") {
        test << cards::types::SPLINE1;
        CHECK(test.str() == "SPLINE1");
    }

    SECTION("output SPLINE2") {
        test << cards::types::SPLINE2;
        CHECK(test.str() == "SPLINE2");
    }

    SECTION("output SPLINE3") {
        test << cards::types::SPLINE3;
        CHECK(test.str() == "SPLINE3");
    }

    SECTION("output SPLINE4") {
        test << cards::types::SPLINE4;
        CHECK(test.str() == "SPLINE4");
    }

    SECTION("output SPLINE5") {
        test << cards::types::SPLINE5;
        CHECK(test.str() == "SPLINE5");
    }

    SECTION("output MAT1") {
        test << cards::types::MAT1;
        CHECK(test.str() == "MAT1");
    }

    SECTION("output MAT2") {
        test << cards::types::MAT2;
        CHECK(test.str() == "MAT2");
    }

    SECTION("output GRAV") {
        test << cards::types::GRAV;
        CHECK(test.str() == "GRAV");
    }

    SECTION("output FORCE") {
        test << cards::types::FORCE;
        CHECK(test.str() == "FORCE");
    }

    SECTION("output LOAD") {
        test << cards::types::LOAD;
        CHECK(test.str() == "LOAD");
    }

    SECTION("output MOMENT") {
        test << cards::types::MOMENT;
        CHECK(test.str() == "MOMENT");
    }

    SECTION("output ENDDATA") {
        test << cards::types::ENDDATA;
        CHECK(test.str() == "ENDDATA");
    }

    SECTION("output CDAMP1D") {
        test << cards::types::CDAMP1D;
        CHECK(test.str() == "CDAMP1D");
    }

    SECTION("output CDAMP2D") {
        test << cards::types::CDAMP2D;
        CHECK(test.str() == "CDAMP2D");
    }

    SECTION("output CELAS1D") {
        test << cards::types::CELAS1D;
        CHECK(test.str() == "CELAS1D");
    }

    SECTION("output CELAS2D") {
        test << cards::types::CELAS2D;
        CHECK(test.str() == "CELAS2D");
    }

    SECTION("output CBUTT") {
        test << cards::types::CBUTT;
        CHECK(test.str() == "CBUTT");
    }

    SECTION("output COMBWLD") {
        test << cards::types::COMBWLD;
        CHECK(test.str() == "COMBWLD");
    }

    SECTION("output CCRSFIL") {
        test << cards::types::CCRSFIL;
        CHECK(test.str() == "CCRSFIL");
    }

    SECTION("output CFILLET") {
        test << cards::types::CFILLET;
        CHECK(test.str() == "CFILLET");
    }

    SECTION("output CSPOT") {
        test << cards::types::CSPOT;
        CHECK(test.str() == "CSPOT");
    }

    SECTION("output RBE3D") {
        test << cards::types::RBE3D;
        CHECK(test.str() == "RBE3D");
    }

    SECTION("output PARAM") {
        test << cards::types::PARAM;
        CHECK(test.str() == "PARAM");
    }

    SECTION("output ELEMENT") {
        test << cards::types::ELEMENT;
        CHECK(test.str() == "ELEMENT");
    }

    SECTION("output BEAM_BASE") {
        test << cards::types::BEAM_BASE;
        CHECK(test.str() == "BEAM_BASE");
    }

    SECTION("output BAR_PROP") {
        test << cards::types::BAR_PROP;
        CHECK(test.str() == "BAR_PROP");
    }

    SECTION("output BEAM_PROP") {
        test << cards::types::BEAM_PROP;
        CHECK(test.str() == "BEAM_PROP");
    }

    SECTION("output CAXIFi") {
        test << cards::types::CAXIFi;
        CHECK(test.str() == "CAXIFi");
    }

    SECTION("output COMMENT") {
        test << cards::types::COMMENT;
        CHECK(test.str() == "COMMENT");
    }

    SECTION("output UNKNOWN") {
        test << cards::types::UNKNOWN;
        CHECK(test.str() == "UNKNOWN");
    }

}

TEST_CASE("BDF file reader.", "[bdf_cards]" ) {

    std::string s(
        // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
        "$Only a comment\n"
        "MAT1    1       2.305+6 80000.0 0.3     7.850-6\n"
        "MAT1    4       2.305+6 80000.0 0.3     7.850-6\n"
        "PBEAML  104010  4               L     \n"
        "           63.0   340.0    35.0    14.0\n"
        "$ Another comment\n"
        "$ Comment continued\n"
        "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n");
    std::istringstream ist(s);
    bdf_file probe(ist);
    std::list<std::string> l;

    std::list<std::string> ref;


    {
        std::list<std::string> ref1({"$Only a comment"});
        probe.get(l);
        CAPTURE(l.front());
        CHECK(l == ref1);
    }

    {
        std::list<std::string> ref1({
                "MAT1    1       2.305+6 80000.0 0.3     7.850-6"});
        probe.get(l);
        CAPTURE(l.front());
        CHECK(l == ref1);
    }

    {
        std::list<std::string> ref1({
                "MAT1    4       2.305+6 80000.0 0.3     7.850-6"});
        probe.get(l);
        CAPTURE(l.front());
        CHECK(l == ref1);
    }

    {
        std::list<std::string> ref1({
                "PBEAML  104010  4               L     ",
                "           63.0   340.0    35.0    14.0"});
        probe.get(l);
        CAPTURE(l.front());
        CHECK(l == ref1);
    }

    {
        std::list<std::string> ref1({
                "$ Another comment",
                "$ Comment continued"});
        probe.get(l);
        CAPTURE(l.front());
        CHECK(l == ref1);
    }

    {
        std::list<std::string> ref1({
                "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6"});
        probe.get(l);
        CAPTURE(l.front());
        CHECK(l == ref1);
    }
}

// Test data as found in the BDF documentation.
TEST_CASE("Split Free Field Cards, Sample 1", "[bdf_cards]") {
    std::list<std::string> data({ "GRID,2,1.0,-2.0,3.0,,136"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({ "GRID", "2", "1.0", "-2.0", "3.0", "", "136"});
    CHECK(probe.size() == ref.size());
    CHECK(probe == ref);
}

TEST_CASE("Split Free Field Cards, Sample 2", "[bdf_cards]") {
    std::list<std::string> data({
            "MATT9,1101,2 ,3 ,4 ,,,,8 ,+P101\n",
            "+P101,9 ,,,,13\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "MATT9", "1101", "2", "3", "4", "", "", "", "8", "9", "",
            "", "", "13"});
    CHECK(probe.size() == ref.size());
    CHECK(probe == ref);
}

TEST_CASE("Split Free Field Cards, Sample 3", "[bdf_cards]") {
    std::list<std::string> data({
            "GRID,100,,1.0,0.0,0.0,,456\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "GRID", "100", "", "1.0", "0.0", "0.0", "", "456"});
    CHECK(probe.size() == ref.size());
    CHECK(probe == ref);
}

TEST_CASE("Split Free Field Cards, Sample 4", "[bdf_cards]") {
    std::list<std::string> data({
            "SPC1,100,12456,1,2,3,4,5,6,+SPC-A+SPC-A,7,8,9,10\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "SPC1", "100", "12456", "1", "2", "3", "4", "5", "6", "7",
            "8", "9", "10"});
    // TODO: possible allow the above line syntax.
    CHECK_FALSE(probe.size() == ref.size());
    // for (size_t i=0; i<probe.size(); ++i) {
    //   CAPTURE( i << ": !" << probe[i] << "!" << ref[i] << "!" );
    //   CHECK(probe[i] == ref[i]);
    // }
}

TEST_CASE("Split Free Field Cards, Sample 5", "[bdf_cards]") {
    std::list<std::string> data({
            "SPC1,100,12456,1,2,3,4,5,6,7,8,9,10\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "SPC1", "100", "12456", "1", "2", "3", "4", "5", "6", "7",
            "8", "9", "10"});
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("Split Free Field Cards, Sample 6", "[bdf_cards]") {
    std::list<std::string> data({
            "MATT9,1151,2 ,3 ,4 ,,,,8 \n",
            ",9 ,,,,13\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "MATT9", "1151", "2", "3", "4", "", "", "", "8", "9", "",
            "", "", "13"});
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("Split Free Field Cards, Sample 7", "[bdf_cards]") {
    std::list<std::string> data({
            "MATT9,1151,2 ,3 ,4 ,,,,8 ,+\n",
            "+,9 ,,,,13\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "MATT9", "1151", "2", "3", "4", "", "", "", "8", "9", "",
            "", "", "13"});
    CHECK(probe.size() == ref.size());
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("Split Free Field Cards, Sample 8", "[bdf_cards]") {
    std::list<std::string> data({
            "MATT9*,1302,2 ,,4 ,+\n",
            "+,,,,,,13\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "MATT9", "1302", "2", "", "4", "", "", "", "", "", "13"});
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("Split Free Field Cards, Sample 9", "[bdf_cards]") {
    std::list<std::string> data({
            "MATT9,1303,2 ,3 ,4 ,,,,8 ,+\n",
            "*,9 ,,,,\n",
            "*,13\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "MATT9", "1303", "2", "3", "4", "", "", "", "8", "9", "",
            "", "", "13"});
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("Split Free Field Cards, Sample 10", "[bdf_cards]") {
    std::list<std::string> data({
            "MATT9,1355,2 ,3 ,,5 ,,,8 ,+\n",
            "*,,10,,,\n",
            "*,17\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "MATT9", "1355", "2", "3", "", "5", "", "", "8", "", "10",
            "", "", "17"});
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("Split Free Field Cards, Sample 11", "[bdf_cards]") {
    std::list<std::string> data({
            "CHEXA,200,200,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "CHEXA", "200", "200", "1", "2", "3", "4", "5", "6", "7",
            "8", "9", "10", "11", "12", "13", "14", "15", "16",
            "17", "18", "19", "20"});
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("Split Free Field Cards, Sample 12", "[bdf_cards]") {
    std::list<std::string> data({
            "PBEAM,1,2,3.,4.,.5,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,\n",
            ",NO,1.\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "PBEAM", "1", "2", "3.", "4.", ".5", "6.", "7.",
            "8.", "9.", "10.", "11.", "12.", "13.", "14.", "15.", "16.",
            "NO", "1."});
    CHECK_THAT(probe, IsEqual(ref));
}

// Test data as found in the BDF documentation.
TEST_CASE("Split Small Field Cards", "[cards]") {
    std::list<std::string> data;
    data.assign({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678
            "GRID           2             1.0    -2.0     3.0             136\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "GRID", "2", "", "1.0", "-2.0", "3.0", "", "136", ""});
    CHECK_THAT(probe, IsEqual(ref));
}

// Test data as found in the BDF documentation.
TEST_CASE("Split Large Field Cards", "[cards]") {
    std::list<std::string> data;
    data.assign({
            // 345678|234567812345678|234567812345678|234567812345678|234567812345678|2345678
            "GRID*                  2                             1.0            -2.0 *GRID10\n",
            "*GRID10              3.0                             136\n"});
    std::list<std::string> probe;
    card::card_split(data, probe);
    std::list<std::string> ref({
            "GRID", "2", "", "1.0", "-2.0", "3.0", "", "136", ""});
    CHECK_THAT(probe, IsEqual(ref));
}

TEST_CASE("BDF_Dispatch", "[cards]") {

    std::string s(
        // 35678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
        "$ YIELD: 235\n"
        "MAT1    1       2.305+6 80000.0 0.3     7.850-6\n"
        "$ YIELD: 355\n"
        "MAT1    4       2.305+6 80000.0 0.3     7.850-6\n"
        "PBEAML  104010  4               L     \n"
        "           63.0   340.0    35.0    14.0         YESA    1.+0\n"
        "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n"
        "                                                               \n"
        "        NO      1.+0\n"
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

    std::list<std::string> data;

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    CAPTURE(data.size());
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::COMMENT);

    probe.get(l);
    CAPTURE(l.front());
    INFO( "The line is " << l.front() );
    card::card_split(l, data);
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
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->A));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->TREF));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->GE));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->ST));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->SC));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->SS));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->MCSID));
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::COMMENT);

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
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
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->A));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->TREF));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->GE));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->ST));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->SC));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->SS));
    CHECK_FALSE(bool(static_cast<mat1*>(current.get())->MCSID));
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
    // PBEAML  104010  4               L
    //           63.0   340.0    35.0    14.0  YESA    1.
    {
        CHECK(current->card_type() == cards::types::PBEAML);
        auto probe = *static_cast<pbeaml*>(current.get());
        CHECK(probe.PID.value == 104010);
        CHECK(probe.MID.value == 4);
        CHECK(probe.GROUP.value == "MSCBML0");
        CHECK(probe.TYPE.value == "L");
        auto DIM = probe.DIM;
        CHECK(DIM.size() == 2);
        for (size_t i{0}; i < DIM.size(); i++)
            CHECK_THAT(std::vector<double>(
                           probe.DIM[i].begin(), probe.DIM[i].end()),
                       IsEqual(vector<double>({63., 340., 35., 14.})));
        CHECK_THAT(std::vector<double>(probe.NSM.begin(), probe.NSM.end()),
                       IsEqual(std::vector<double>(2, 0.)));
        CHECK_THAT(std::vector<std::string>(probe.SO.begin(), probe.SO.end()),
                   IsEqual(std::vector<std::string>(1, "YESA")));
        CHECK_THAT(std::vector<double>(probe.X_XB.begin(), probe.X_XB.end()),
                       IsEqual(std::vector<double>(1, 1.)));
        CHECK_THAT(std::vector<double>(probe.NSM.begin(), probe.NSM.end()),
                      IsEqual(std::vector<double>(2, 0.)));
        current.reset();
    }

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    // PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6
    CHECK(current->card_type() == cards::types::PBEAM);
    {
        auto probe = static_cast<pbeam*>(current.get());
        CHECK(probe->PID.value == 4000001);
        CHECK(probe->MID.value == 3);
        CHECK_THAT(vector<double>(probe->A.begin(), probe->A.end()),
                   IsEqual(vector<double>(2, 10460.)));
        CHECK_THAT(vector<double>(probe->I1.begin(), probe->I1.end()),
                   IsEqual(vector<double>(2, 93690000.)));
        CHECK_THAT(vector<double>(probe->I2.begin(), probe->I2.end()),
                   IsEqual(vector<double>(2, 1694000.)));
        CHECK_THAT(vector<double>(probe->I12.begin(), probe->I12.end()),
                   IsEqual(vector<double>(2, 6.856e6)));
        CHECK_THAT(vector<double>(probe->J.begin(), probe->J.end()),
                   IsEqual(vector<double>(2, 1.316e6)));
        current.reset();
    }
    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    // PROD    6000001 1       3000.00\n"
    CHECK(current->card_type() == cards::types::PROD);
    CHECK(static_cast<prod*>(current.get())->PID.value == 6000001);
    CHECK(static_cast<prod*>(current.get())->MID.value == 1);
    CHECK(static_cast<prod*>(current.get())->A.value == 3000);
    CHECK_FALSE(bool(static_cast<prod*>(current.get())->J));
    CHECK(static_cast<prod*>(current.get())->C.value == 0.);
    CHECK_FALSE(bool(static_cast<prod*>(current.get())->NSM));
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::PSHELL);
    // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
    //         PID     MID1    T       MID2    12I/T**3 MID3
    // PSHELL  1       4         23.00 4               4
    CHECK(static_cast<pshell*>(current.get())->PID.value == 1);
    CHECK(static_cast<pshell*>(current.get())->MID1.value == 4);
    CHECK(static_cast<pshell*>(current.get())->T.value == 23.);
    CHECK(static_cast<pshell*>(current.get())->MID2.value == 4);
    CHECK_FALSE(bool(static_cast<pshell*>(current.get())->x12I_T__3));
    CHECK(static_cast<pshell*>(current.get())->MID3.value == 4);
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::GRID);
    CHECK(static_cast<grid*>(current.get())->ID.value == 1);
    CHECK(static_cast<grid*>(current.get())->X1.value == 111525.);
    CHECK(static_cast<grid*>(current.get())->X2.value == 18000.);
    CHECK(static_cast<grid*>(current.get())->X3.value == 21000.);
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::GRID);
    CHECK(static_cast<grid*>(current.get())->ID.value == 76);
    CHECK(static_cast<grid*>(current.get())->X1.value == 111522.);
    CHECK(static_cast<grid*>(current.get())->X2.value == 18002.);
    CHECK(static_cast<grid*>(current.get())->X3.value == 21002.);
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::GRID);
    CHECK(static_cast<grid*>(current.get())->ID.value == 153);
    CHECK(static_cast<grid*>(current.get())->X1.value == 111522.);
    CHECK(static_cast<grid*>(current.get())->X2.value == 18001.);
    CHECK(static_cast<grid*>(current.get())->X3.value == 21002.);
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::CQUAD4);
    // "CQUAD4  1       1       16      200     141     17\n"
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::CQUAD4);
    //  45678|234567890123456|234567890123456|234567890123456|234567890123456|2
    // "CQUAD4* 2               1               16              200             "
    // "+\n"
    // "+       140             15\n"
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::CTRIA3);
    // "CTRIA3  2606    1       1066    1065    1133\n"
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::CBEAM);
    // "CBEAM   7869    104010  76      153     0.0     66.5206 997.785\n"
    // "                        0.0     -22.617 -339.25 0.0     -22.617 -339.25\n"
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::CROD);
    // "CROD    11316   6000001 1028    2139\n"
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::CBEAM);
    // "CBEAM    465144 104010  76      153     1.       0.      0.\n"
    current.reset();

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::COMMENT);

    probe.get(l);
    CAPTURE(l.front());
    card::card_split(l, data);
    cards::dispatch(data, current);
    CHECK(current->card_type() == cards::types::ENDDATA);
}

TEST_CASE("Test partial supported element cards, CAABSF.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({ "CAABSF,44,38,1,10,20"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 44);
}

TEST_CASE("Test partial supported element cards, CAERO1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAERO1,1000,1,,3,,,2,1,0.,0.,0.,1.,.2,1.,0.,.8"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1000);
}

TEST_CASE("Test partial supported element cards, CAERO2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAERO2,1500,2,100,,4,99,,1,-1.,100.,-30.,175."});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1500);
}

TEST_CASE("Test partial supported element cards, CAERO3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAERO3,2000,2001,0,22,33,,,,1.,0.,0.,100.,17.130,0.,100."});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2000);
}

TEST_CASE("Test partial supported element cards, CAERO4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAERO4,6000,6001,100,,315,,,,0.0,0.0,0.0,1.0,0.2,1.0,0.0,0.8"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 6000);
}

TEST_CASE("Test partial supported element cards, CAERO5.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAERO5,6000,6001,100,,315,0,0,,0.0,0.0,0.0,1.0,0.2,1.0,0.,0.8"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 6000);
}

TEST_CASE("Test partial supported element cards, CAXIF2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAXIF2,11,23,25,,,0.25E-3"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 11);
}

TEST_CASE("Test partial supported element cards, CAXIF3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAXIF3,105,31,32,33,,6.47E-3"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 105);
}

TEST_CASE("Test partial supported element cards, CAXIF4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CAXIF4,524,421,425,424,422,0.5E-3,2.5+3"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 524);
}

TEST_CASE("Test partial supported element cards, CBEND.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBEND,32,39,17,19,6.2,5.1,-1.2"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 32);
}

TEST_CASE("Test partial supported element cards, CBEND (alt).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBEND,32,39,17,19,106"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 32);
}

TEST_CASE("Test partial supported element cards, CBUSH (1).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBUSH,39,6,1,100,75"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::CBUSH);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
}

TEST_CASE("Test partial supported element cards, CBUSH (2).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBUSH,39,6,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::CBUSH);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
}

TEST_CASE("Test partial supported element cards, CBUSH (3).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBUSH,39,6,1,100"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::CBUSH);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
}

TEST_CASE("Test partial supported element cards, CBUSH (4).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBUSH,39,6,1,600,,,,,0.25,10,0.,10.,10."});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::CBUSH);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 39);
}

TEST_CASE("Test partial supported element cards, CBUSH1D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBUSH1D,35,102,108,112"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 35);
}

TEST_CASE("Test partial supported element cards, CBUTT.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CBUTT,1002,11,5,0,0,3,1,,0.005,.07,,2.5,4.0,2.0,1.5"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
}

TEST_CASE("Test partial supported element cards, CCONEAX.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CCONEAX,1,2,3,4"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1);
}

TEST_CASE("Test partial supported element cards, CCRSFIL.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CCRSFIL,1002,11,5,0,0,2,1,,0.005,,40000.,2.5,4.,3.,2.,"
                "25.0,101,201,11,,,,,,0.006,,45000.,2.6,4.5,3.2,2.2,"
                "22.0,103,203,15"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
}

TEST_CASE("Test partial supported element cards, CDAMP1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDAMP1,19,6,0,,23,2"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 19);
}

TEST_CASE("Test partial supported element cards, CDAMP1D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDAMP1D,1001,101,55,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
}

TEST_CASE("Test partial supported element cards, CDAMP2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDAMP2,16,2.98,32,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 16);
}

TEST_CASE("Test partial supported element cards, CDAMP2D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDAMP2D,1001,101,55,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
}

TEST_CASE("Test partial supported element cards, CDAMP3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDAMP3,16,978,24,36"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 16);
}

TEST_CASE("Test partial supported element cards, CDAMP4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDAMP4,16,-2.6,4,9"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 16);
}

TEST_CASE("Test partial supported element cards, CDAMP5.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDAMP5,1,4,10,20"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1);
}

TEST_CASE("Test partial supported element cards, CDUM1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM1,114,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 114);
}

TEST_CASE("Test partial supported element cards, CDUM2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM2,124,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 124);
}

TEST_CASE("Test partial supported element cards, CDUM3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM3,134,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 134);
}

TEST_CASE("Test partial supported element cards, CDUM4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM4,144,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 144);
}

TEST_CASE("Test partial supported element cards, CDUM5.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM5,154,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 154);
}

TEST_CASE("Test partial supported element cards, CDUM6.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM6,164,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 164);
}

TEST_CASE("Test partial supported element cards, CDUM7.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM7,174,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 174);
}

TEST_CASE("Test partial supported element cards, CDUM8.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM8,184,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 184);
}

TEST_CASE("Test partial supported element cards, CDUM9.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CDUM9,194,108,2,5,6,8,11,,2.4,,3.E4,2,,50"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 194);
}

TEST_CASE("Test partial supported element cards, CELAS1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CELAS1,2,6,,,8,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
}

TEST_CASE("Test partial supported element cards, CELAS1D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CELAS1D,1001,101,55,1,8,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
}

TEST_CASE("Test partial supported element cards, CELAS2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CELAS2,28,6.2+3,32,,19,4"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 28);
}

TEST_CASE("Test partial supported element cards, CELAS2D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CELAS2D,1001,101,55,1,8,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
}

TEST_CASE("Test partial supported element cards, CELAS3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CELAS3,19,2,14,15"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 19);
}

TEST_CASE("Test partial supported element cards, CELAS4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CELAS4,42,6.2-3,2"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 42);
}

TEST_CASE("Test partial supported element cards, CFILLET.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CFILLET,1002,11,5,0,0,3,1,,0.005,.07,,2.5,4.0,3.0,2.0,25.0"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
}

TEST_CASE("Test partial supported element cards, CFLUID2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CFLUID2,100,11,14,,,.025,0.0"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 100);
}

TEST_CASE("Test partial supported element cards, CFLUID3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CFLUID3,110,15,13,12,,1.2"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 110);
}

TEST_CASE("Test partial supported element cards, CFLUID4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CFLUID4,120,11,15,12,6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 120);
}

TEST_CASE("Test partial supported element cards, CGAP (1).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CGAP,17,2,110,112,5.2,0.3,-6.1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 17);
}

TEST_CASE("Test partial supported element cards, CGAP (2).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CGAP,17,2,110,112,13"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 17);
}

TEST_CASE("Test partial supported element cards, CHACAB.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CHACAB,95,12,1,2,5,7,8,9,24,23"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 95);
}

TEST_CASE("Test partial supported element cards, CHACBR.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CHACBR,95,12,1,2,5,7,8,9,24,23"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 95);
}

TEST_CASE("Test partial supported element cards, CHBDYE.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CHBDYE,2,10,1,3,3,2,2"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
}

TEST_CASE("Test partial supported element cards, CHBDYG.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CHBDYG,2,,AREA4,3,3,2,2,,100,103,102,101"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
}

TEST_CASE("Test partial supported element cards, CHBDYP.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CHBDYP,2,5,POINT,2,2,101,,500,3,3,,,0.0,0.0,1.0"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
}

TEST_CASE("Test partial supported element cards, CHEXA.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CHEXA,71,4,3,4,5,6,7,8,9,10,0,0,30,31,53,54,55,56,57,58,59,60"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 71);
}

TEST_CASE("Test partial supported element cards, CMASS1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CMASS1,32,6,2,1"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 32);
}

TEST_CASE("Test partial supported element cards, CMASS3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CMASS3,13,42,62"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 13);
}

TEST_CASE("Test partial supported element cards, COMBWLD.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "COMBWLD,1002,11,,0,0,12,1,,,,"
                "44000.,2.5,4.0,3.0,2.0,22.5,,,,"
                "42000.,2.5,2.0,1.25,0.75,-22.5,"
                "101,201,1,1,,,,28.6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1002);
}

TEST_CASE("Test partial supported element cards, CONM1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CONM1,2,22,2,2.9,6.3,,,,4.8,28.6,,,,,,,,28.6,,,,,,28.6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
}

TEST_CASE("Test partial supported element cards, CONM2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CONM2,2,15,6,49.7,,,,,16.2,,16.2,,,7.8"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
}

TEST_CASE("Test partial supported element cards, CONROD.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CONROD,2,16,17,4,2.69"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 2);
}

TEST_CASE("Test partial supported element cards, CPENTA.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CPENTA,112,2,3,15,14,4,103,115,5,16,8,,,,120,125,130"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 112);
}

TEST_CASE("Test partial supported element cards, CQUAD.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CQUAD,111,203,31,74,75,32"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
}

TEST_CASE("Test partial supported element cards, CQUAD8.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CQUAD8,207,3,31,33,73,71,32,51,53,72,0.125,0.025,0.030,"
                ".025,30.,.03"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 207);
}

TEST_CASE("Test partial supported element cards, CQUADR.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CQUADR,82,203,31,74,75,32,2.6,,,1.77,2.04,2.09,1.80"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 82);
}

TEST_CASE("Test partial supported element cards, CQUADX.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CQUADX,111,203,31,74,75,32"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
}

TEST_CASE("Test partial supported element cards, CRAC2D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CRAC2D,114,108,2,5,6,8,7,11,12,14,16,17,,20,22"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 114);
}

TEST_CASE("Test partial supported element cards, CRAC3D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CRAC3D,113,101,2,5,7,8,4,10,11,14,15,17,,3,6,9,12,,16,,"
                "102,105,107,108,115,117,,103,104,110,111,114,115,117,,"
                "103,106,109,112,,116,,202,205,207,208,204,210,211,"
                "214,215,217,225,226"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 113);
}

TEST_CASE("Test partial supported element cards, CSHEAR.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CSHEAR,3,6,1,5,3,7"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 3);
}

TEST_CASE("Test partial supported element cards, CSLOT3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CSLOT3,100,1,3,2,,3.0-3,,6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 100);
}

TEST_CASE("Test partial supported element cards, CSLOT4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CSLOT4,101,1,3,2,4,,6.2+4,3"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 101);
}

TEST_CASE("Test partial supported element cards, CSPOT.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CSPOT,1001,,11,5,0,0,,1,,0.005,.07"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
}

TEST_CASE("Test partial supported element cards, CTETRA.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CTETRA,112,2,3,15,14,4,103,115,5,16,8,27"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 112);
}

TEST_CASE("Test partial supported element cards, CTRIA6.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CTRIA6,302,3,31,33,71,32,51,52,45,.03,.020,.025,.025"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 302);
}

TEST_CASE("Test partial supported element cards, CTRIAR.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CTRIAR,111,203,31,74,75,3.0,,,,,1.77,2.04,2.09"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
}

TEST_CASE("Test partial supported element cards, CTRIAX.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CTRIAX,111,203,31,74,75"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
}

TEST_CASE("Test partial supported element cards, CTRIAX6.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CTRIAX6,22,999,10,11,12,21,22,32,9.0"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 22);
}

TEST_CASE("Test partial supported element cards, CTUBE.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CTUBE,12,13,21,23"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 12);
}

TEST_CASE("Test partial supported element cards, CVISC.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "CVISC,21,6327,29,31"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 21);
}

TEST_CASE("Test partial supported element cards, GENEL.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "GENEL,629,,1,1,13,4,42,0,"
                "24,2,,,,,,,"
                "UD,,6,2,33,0,,,"
                "Z,1.0,2.0,3.0,4.0,5.0,6.0,7.0,"
                "8.0,9.0,10.0,,,,,,,"
                "S,1.5,2.5,3.5,4.5,5.5,6.5,7.5,"
                "8.5"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 629);
}

TEST_CASE("Test partial supported element cards, GMINTC.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "GMINTC,1001,1,1,2"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001);
}

TEST_CASE("Test partial supported element cards, GMINTS.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "GMINTS,1001,1,1,2"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 1001 );
}

TEST_CASE("Test partial supported element cards, PLOTEL.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "PLOTEL,29,35,16"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 29);
}

TEST_CASE("Test partial supported element cards, RBAR.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBAR,5,1,2,123456,,,,6.5-6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
}

TEST_CASE("Test partial supported element cards, RBAR1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBAR1,5,1,2,123,6.5-6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
}

TEST_CASE("Test partial supported element cards, RBE1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBE1,59,59,123456,,,,,,"
                "UM,61,246,6.5-6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 59);
}

TEST_CASE("Test partial supported element cards, RBE2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBE2,9,8,12,10,12,14,15,16,"
                "20,6.5-6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 9);
}

TEST_CASE("Test partial supported element cards, RBE3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBE3,14,,100,1234,1.0,123,1,3,"
                "5,4.7,1,2,4,6,5.2,2,"
                "7,8,9,5.1,1,15,16,,"
                "UM,100,14,5,3,7,2,,"
                "ALPHA,6.5-6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 14);
}

TEST_CASE("Test partial supported element cards, RBE3D (1).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBE3D,51,11,123,,,,,,"
                "101,123,0.5,0.5,0.5,,,,"
                "102,123,0.5,0.5,0.5"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 51);
}

TEST_CASE("Test partial supported element cards, RBE3D (2).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBE3D,51,11,123,4,8,,,LOCAL1,"
                "101,123,0.5,0.5,0.5,,,,"
                "102,123,0.5,0.5,0.5"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 51);
}

TEST_CASE("Test partial supported element cards, RBE3D.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RBE3D,51,11,123,4,,,,LOCAL2,"
                "8,,,,,,,,"
                "101,123,0.5,0.5,0.5,,,,"
                "25,,,,,,,,"
                "102,123,0.5,0.5,0.5"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 51);
}

TEST_CASE("Test partial supported element cards, RJOINT.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RJOINT,5,1,2,12345"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
}

TEST_CASE("Test partial supported element cards, RROD.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RROD,14,1,2,2,,6.5-6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 14);
}

TEST_CASE("Test partial supported element cards, RSPLINE.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RSPLINE,73,.05,27,28,123456,29,,30,"
                "123,75,123,71"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 73);
}

TEST_CASE("Test partial supported element cards, RSSCON (1).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RSSCON,110,GRID,11,12,13,14,15,16"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 110);
}

TEST_CASE("Test partial supported element cards, RSSCON (2).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RSSCON,111,GRID,31,74,75"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 111);
}

TEST_CASE("Test partial supported element cards, RSSCON (3).", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RSSCON,115,ELEM,311,741"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 115);
}

TEST_CASE("Test partial supported element cards, RTRPLT.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RTRPLT,7,1,2,3,1236,3,3"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 7);
}

TEST_CASE("Test partial supported element cards, RTRPLT1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "RTRPLT1,7,1,2,3,1236,3,6.0-6"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 7);
}

TEST_CASE("Test partial supported element cards, SPLINE1.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "SPLINE1,3,111,115,122,14,0."});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 3);
}

TEST_CASE("Test partial supported element cards, SPLINE2.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "SPLINE2,5,8,12,24,60,0.,1.0,3,"
                "1."});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
}

TEST_CASE("Test partial supported element cards, SPLINE3.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "SPLINE3,7000,107,109,6,5,3,1.0,,"
                "43,5,-1.0"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 7000);
}

TEST_CASE("Test partial supported element cards, SPLINE4.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "SPLINE4,3,111,115,,14,0.,IPS"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 3);
}

TEST_CASE("Test partial supported element cards, SPLINE5.", "[bdf_cards]") {

    std::unique_ptr<cards::__base::card> probe;

    std::list<std::string> data({
            "SPLINE5,5,8,12,,60,,,3,1.,,,BOTH"});
    std::list<std::string> l;
    card::card_split(data, l);
    cards::dispatch(l, probe);

    CHECK(probe->card_type() == cards::types::ELEMENT);
    CHECK(dynamic_cast<cards::__base::element*>(probe.get())->EID.value == 5);
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test ;
//    ../cbuild/tests/test_bdf_cards --use-colour no)"
// coding: utf-8
// End:
