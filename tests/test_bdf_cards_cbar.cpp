/**
   \file tests/test_bdf_cards_cbar.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `CBAR` card class.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    const char test_bdf_cards_cbar_cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <limits>

#include <catch.hpp>

#include "config.h"

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF CBAR definitions. (Small Field Format)", "[bdf_cbar]" ) {

    std::list<std::string> data({
            "CBAR    7869    104010  76      153     0.0     66.5206 997.785 \n",
                "                        0.0     -22.617 -339.25 0.0     -22.617 \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cbar probe(lines);

    SECTION("first cbar") {
        CHECK(probe.EID.value == 7869);
        CHECK(probe.PID.value == 104010);
        CHECK(probe.GA.value == 76);
        CHECK(probe.GB.value == 153);
        CHECK((double)probe.X1 == 0.);
        CHECK((double)probe.X2 == 66.5206);
        CHECK((double)probe.X3 == 997.785);
        CHECK_FALSE(probe.G0);
        CHECK(probe.choose_dir_code == cbar::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(probe.OFFT == "GGG");
        std::list<int> p_ref;
        CHECK(probe.PA == p_ref);
        CHECK(probe.PB == p_ref);
        CHECK((double)probe.W1A == 0.);
        CHECK((double)probe.W2A == -22.617);
        CHECK((double)probe.W3A == -339.25);
        CHECK((double)probe.W1B == 0.);
        CHECK((double)probe.W2B == -22.617);
        CHECK((double)probe.W3B == 0.);
    }
}

TEST_CASE("BDF CBAR definitions. (Small Field Format), dircode",
          "[bdf_cbar,dcode]" ) {

    std::list<std::string> data({
            "CBAR    7869    104010  76      153      13                     GOO     \n",
                "                        0.0     -22.617 -339.25 0.0     -22.617 "});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cbar probe(lines);

    SECTION("dir code cbar") {
        CHECK((long)probe.EID == 7869);
        CHECK((long)probe.PID == 104010);
        CHECK(probe.GA.value == 76);
        CHECK(probe.GB.value == 153);
        CHECK(probe.G0.value == 13);
        CHECK_FALSE(probe.X1);
        CHECK_FALSE(probe.X2);
        CHECK_FALSE(probe.X3);
        CHECK(probe.choose_dir_code == cbar::CHOOSE_DIR_CODE::has_DCODE);
        CHECK(probe.OFFT == "GOO");
        std::list<int> p_ref;
        CHECK(probe.PA.value == p_ref);
        CHECK(probe.PB.value == p_ref);
        CHECK(probe.W1A.value == 0.);
        CHECK(probe.W2A.value == -22.617);
        CHECK(probe.W3A.value == -339.25);
        CHECK(probe.W1B.value == 0.);
        CHECK(probe.W2B.value == -22.617);
        CHECK(probe.W3B.value == 0.);
    }
}

TEST_CASE("BDF CBAR types output.", "[bdf_cbar,out]" ) {

    std::ostringstream test;

    SECTION("dir code") {
        long EID(1), PID(2), GA(3), GB(4), G0(5);

        cbar probe(&EID, &PID, &GA, &GB, &G0);
        test << probe;
        CHECK(test.str() ==
              "CBAR           1       2       3       4       5\n");
    }

    SECTION("QRG sample 1") {
        long EID(2), PID(39), GA(7), GB(3);
        double X1(.6), X2(18), X3(26);
        std::string OFFT("EEG");

        cbar probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT);
        probe.PB.is_value = true;
        probe.PB.value.assign({5, 1, 3});
        test << probe;
        CHECK(test.str() ==
              "CBAR           2      39       7       36.000-011.800+012.600+01EEG     \n"
              "                     513\n");
    }

    SECTION("QRG sample 1 (long)") {
        long EID(2), PID(39), GA(7), GB(3);
        double X1(.6), X2(18), X3(1234.5);
        std::string OFFT("EEG");

        cbar probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT);
        probe.PB.is_value = true;
        probe.PB.value.assign({5, 1, 3});

        test << probe;
        CHECK(test.str() ==
              "CBAR*                  2              39               7               3\n"
              "*       6.00000000000-011.80000000000+011.23450000000+03EEG             \n"
              "*                                    513\n"
              "*       \n");
    }

    SECTION("dir code all elements") {
        long EID(1), PID(2), GA(3), GB(4), G0(5);

        cbar probe(&EID, &PID, &GA, &GB, &G0);
        probe.W3B = 2.;
        test << probe;
        CHECK(test.str() ==
              "CBAR           1       2       3       4       5                        \n"
              "                         0.00+00 0.00+00 0.00+00 0.00+00 0.00+002.000+00\n");
    }

    SECTION("dir code all large") {
        long EID(123456789), PID(2), GA(3), GB(4), G0(5);

        cbar probe(&EID, &PID, &GA, &GB, &G0);
        probe.W3B = 2.;
        test << probe;
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBAR*          123456789               2               3               4\n"
              "*                      5                                                \n"
              "*                                        0.0000000000+00 0.0000000000+00\n"
              "*        0.0000000000+00 0.0000000000+00 0.0000000000+002.00000000000+00\n");
    }

    SECTION("dir code all large (ptr)") {
        long EID(123456789), PID(2), GA(3), GB(4), G0(5);

        __base::card *probe = new cbar(&EID, &PID, &GA, &GB, &G0);
        static_cast<cbar*>(probe)->W3B = 2.;
        test << *probe;
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBAR*          123456789               2               3               4\n"
              "*                      5                                                \n"
              "*                                        0.0000000000+00 0.0000000000+00\n"
              "*        0.0000000000+00 0.0000000000+00 0.0000000000+002.00000000000+00\n");
        delete probe;
    }
}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
