/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `CBAR` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(test_bdf_cards_cbar_cID[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace cards;

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
        CHECK_FALSE(bool(probe.G0));
        CHECK(probe.choose_dir_code == cbar::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(probe.OFFT == "GGG");
        std::vector<int> p_ref;
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

TEST_CASE("CBAR Roundtrip test 1 (dir code).", "[bdf_cbar_roundtrip_1]") {
    cbar::reset();

    std::stringstream test;

    long EID(1), PID(2), GA(3), GB(4), G0(5);

    cbar probe(&EID, &PID, &GA, &GB, &G0);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBAR           1       2       3       4       5\n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbar probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.G0.value == 5);
    }
}

TEST_CASE("CBAR Roundtrip test 1 (dir code) (reuse).", "[bdf_cbar_roundtrip_1_reuse]") {

    cbar::reset();

    std::stringstream test;

    long EID(1), PID(2), GA(3), GB(4), G0(5);

    cbar probe;
    probe(&EID, &PID, &GA, &GB, &G0);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBAR           1       2       3       4       5\n");
    }

    SECTION("check reading") {
        cbar::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());
        cbar probe_l;

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.G0.value == 5);
    }
}

TEST_CASE("CBAR Roundtrip test (QRG sample 1)", "[bdf_cbar_roundtrip_2]"){
    cbar::reset();

    ostringstream test;

    long EID(2), PID(39), GA(7), GB(3);
    double X1(.6), X2(18), X3(26);
    std::string OFFT("GGO");

    cbar probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT);
    probe.PB.is_value = true;
    probe.PB.value.assign({5, 1, 3});
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBAR           2      39       7       36.000-011.800+012.600+01GGO     \n"
              "                     513\n");
    }

    SECTION("check reading") {
        cbar::reset();
        list<std::string> data;
        list<std::string> lines;
        std::string tmp;
        istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbar probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 26);
        CHECK(probe_l.OFFT.value == "GGO");
    }
}

TEST_CASE("CBAR Roundtrip test (QRG sample 1) (reuse)", "[bdf_cbar_roundtrip_2_reuse]"){
    cbar::reset();

    std::ostringstream test;

    long EID(2), PID(39), GA(7), GB(3);
    double X1(.6), X2(18), X3(26);
    std::string OFFT("GGO");

    cbar probe;
    probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT);
    probe.PB.is_value = true;
    probe.PB.value.assign({5, 1, 3});
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBAR           2      39       7       36.000-011.800+012.600+01GGO     \n"
              "                     513\n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());
        cbar probe_l;

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 26);
        CHECK(probe_l.OFFT.value == "GGO");
    }
}

TEST_CASE("CBAR Roundtrip test (QRG sample 1 (long))", "[bdf_cbar_roundtrip_3]") {
    cbar::reset();

    std::ostringstream test;

    long EID(2), PID(39), GA(7), GB(3);
    double X1(.6), X2(18), X3(1234.5);
    std::string OFFT("GGO");
    vector<int> PB{5, 1, 3};

    cbar probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT, nullptr, &PB);

    test << probe;

    SECTION("check output") {
            CHECK(test.str() ==
              "CBAR*                  2              39               7               3\n"
              "*       6.00000000000-011.80000000000+011.23450000000+03GGO             \n"
              "*                                    513\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbar probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 1234.5);
        CHECK(probe_l.OFFT.value == "GGO");
        CHECK(probe_l.PB == vector<int>({5, 1, 3}));
    }
}

TEST_CASE("CBAR Roundtrip test (QRG sample 1 (long)) (reuse)",
          "[bdf_cbar_roundtrip_3_reuse]") {
        cbar::reset();

    std::ostringstream test;

    long EID(2), PID(39), GA(7), GB(3);
    double X1(.6), X2(18), X3(1234.5);
    std::string OFFT("GGO");
    vector<int> PB{5, 1, 3};

    cbar probe;
    probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT, nullptr, &PB);

    test << probe;

    SECTION("check output") {
            CHECK(test.str() ==
              "CBAR*                  2              39               7               3\n"
              "*       6.00000000000-011.80000000000+011.23450000000+03GGO             \n"
              "*                                    513\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());
        cbar probe_l;

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        probe_l(lines);

        CHECK(probe_l.EID.value == 2);
        CHECK(probe_l.PID.value == 39);
        CHECK(probe_l.GA.value == 7);
        CHECK(probe_l.GB.value == 3);
        CHECK(probe_l.X1.value == .6);
        CHECK(probe_l.X2.value == 18);
        CHECK(probe_l.X3.value == 1234.5);
        CHECK(probe_l.OFFT.value == "GGO");
        CHECK(probe_l.PB == vector<int>({5, 1, 3}));
    }
}

TEST_CASE("CBAR Roundtrip test (dir code all elements)", "[bdf_cbar_roundtrip_4]") {
    cbar::reset();

    std::ostringstream test;

    long EID(1), PID(2), GA(3), GB(4), G0(5);
    double W3B{2.};

    cbar probe(&EID, &PID, &GA, &GB, &G0,
               nullptr, nullptr, nullptr, nullptr,
               nullptr, nullptr, nullptr, nullptr,
                &W3B);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBAR           1       2       3       4       5                        \n"
              "                                                                2.000+00\n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbar probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.G0.value == 5);
        CHECK(probe_l.W3B.value == 2.);
    }
}

TEST_CASE("CBAR Roundtrip test (dir code all elements) (reuse)",
          "[bdf_cbar_roundtrip_4_reuse]") {
    cbar::reset();

    std::ostringstream test;

    long EID(1), PID(2), GA(3), GB(4), G0(5);
    double W3B{2.};

    cbar probe(&EID, &PID, &GA, &GB, &G0,
               nullptr, nullptr, nullptr, nullptr,
               nullptr, nullptr, nullptr, nullptr,
               &W3B);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBAR           1       2       3       4       5                        \n"
              "                                                                2.000+00\n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbar probe_l(lines);

        CHECK(probe_l.EID.value == 1);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.G0.value == 5);
        CHECK(probe_l.W3B.value == 2.);
    }
}

TEST_CASE("CBAR Roundtrip test (dir code all elements) (large)",
          "[bdf_cbar_roundtrip_5]") {
    cbar::reset();

    std::ostringstream test;
    long EID(123456789), PID(2), GA(3), GB(4), G0(5);
    double W3B{2.};

    cbar probe(&EID, &PID, &GA, &GB, &G0,
               nullptr, nullptr, nullptr, nullptr,
               nullptr, nullptr, nullptr, nullptr,
               &W3B);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBAR*          123456789               2               3               4\n"
              "*                      5                                                \n"
              "*                                                                       \n"
              "*                                                       2.00000000000+00\n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbar probe_l(lines);

        CHECK(probe_l.EID.value == 123456789);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.G0.value == 5);
        CHECK(probe_l.W3B.value == 2.);

    }
}

TEST_CASE("CBAR Roundtrip test (dir code all elements) (large) (reuse)",
          "[bdf_cbar_roundtrip_5_reuse]") {
    cbar::reset();

    std::ostringstream test;
    long EID(123456789), PID(2), GA(3), GB(4), G0(5);
    double W3B{2.};

    cbar probe;
    test << probe;
    test << probe(&EID, &PID, &GA, &GB, &G0,
                  nullptr, nullptr, nullptr, nullptr,
                  nullptr, nullptr, nullptr, nullptr,
                  &W3B);

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBAR*          123456789               2               3               4\n"
              "*                      5                                                \n"
              "*                                                                       \n"
              "*                                                       2.00000000000+00\n");
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbar probe_l;
        probe_l(lines);

        CHECK(probe_l.EID.value == 123456789);
        CHECK(probe_l.PID.value == 2);
        CHECK(probe_l.GA.value == 3);
        CHECK(probe_l.GB.value == 4);
        CHECK(probe_l.G0.value == 5);
        CHECK(probe_l.W3B.value == 2.);

    }
}

TEST_CASE("CBAR Roundtrip test dir code all large (ptr)", "[bdf_cbar_roundtrip_6]") {
    cbar::reset();

    std::ostringstream test;

    long EID(123456789), PID(2), GA(3), GB(4), G0(5);
    double W3B{2.};

    __base::card *probe = new cbar(
        &EID, &PID, &GA, &GB, &G0,
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr,
        &W3B);
    test << *probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBAR*          123456789               2               3               4\n"
              "*                      5                                                \n"
              "*                                                                       \n"
              "*                                                       2.00000000000+00\n");
        delete probe;
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        __base::card *probe_l = new cbar(lines);

        CHECK(static_cast<cbar*>(probe_l)->EID.value == 123456789);
        CHECK(static_cast<cbar*>(probe_l)->PID.value == 2);
        CHECK(static_cast<cbar*>(probe_l)->GA.value == 3);
        CHECK(static_cast<cbar*>(probe_l)->GB.value == 4);
        CHECK(static_cast<cbar*>(probe_l)->G0.value == 5);
        CHECK(static_cast<cbar*>(probe_l)->W3B.value == 2.);

        delete probe_l;
    }
}

TEST_CASE("CBAR Roundtrip test dir code all large (ptr) (reuse)",
          "[bdf_cbar_roundtrip_6_reuse]") {
    cbar::reset();

    std::ostringstream test;

    long EID(123456789), PID(2), GA(3), GB(4), G0(5);
    double W3B{2.};

    __base::card *probe = new cbar;
    test << *probe;
    (*static_cast<cbar*>(probe))(&EID, &PID, &GA, &GB, &G0,
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr,
        &W3B);
    test << *probe;

    SECTION("check output") {
        CHECK(test.str() ==
              // 34567!123456789012345!123456789012345!123456789012345!123456789012345!
              "CBAR*          123456789               2               3               4\n"
              "*                      5                                                \n"
              "*                                                                       \n"
              "*                                                       2.00000000000+00\n");
        delete probe;
    }

    SECTION("check reading") {
        cbar::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        __base::card *probe_l = new cbar;
        (*static_cast<cbar*>(probe_l))(lines);

        CHECK(static_cast<cbar*>(probe_l)->EID.value == 123456789);
        CHECK(static_cast<cbar*>(probe_l)->PID.value == 2);
        CHECK(static_cast<cbar*>(probe_l)->GA.value == 3);
        CHECK(static_cast<cbar*>(probe_l)->GB.value == 4);
        CHECK(static_cast<cbar*>(probe_l)->G0.value == 5);
        CHECK(static_cast<cbar*>(probe_l)->W3B.value == 2.);

        delete probe_l;
    }
}

TEST_CASE("Error conditions (Wrong OFFT error)", "[bdf_cbar_error_1]") {

    long EID(2), PID(39), GA(7), GB(3);
    double X1(.6), X2(18), X3(26);
    std::string OFFT("EEG");

    SECTION("create instance") {
        CHECK_THROWS_AS(cbar(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT),
                        errors::str_error);
    }

    SECTION("reuse instance") {
        cbar probe;
        CHECK_THROWS_AS(probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT),
                        errors::str_error);
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
