/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `CBEAM` card class.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

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

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF CBEAM definitions. (Small Field Format)", "[bdf_cbeam]") {

    std::list<std::string> data({
        "CBEAM   7869    104010  76      153     0.0     66.5206 997.785  2.\n",
        "                        0.0     -22.617 -339.25 0.0     -22.617 \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cbeam probe(lines);
    SECTION("first cbeam") {
        CHECK(probe.EID.value == 7869);
        CHECK(probe.PID.value == 104010);
        CHECK(probe.GA.value == 76);
        CHECK(probe.GB.value == 153);
        CHECK(double(probe.X1) == 0.);
        CHECK(double(probe.X2) == 66.5206);
        CHECK(double(probe.X3) == 997.785);
        CHECK_FALSE(bool(probe.G0));
        CHECK(probe.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(double(probe.BIT) == 2.);
        CHECK_FALSE(bool(probe.OFFT));
        CHECK(probe.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_BIT);
        std::vector<int> p_ref;
        CHECK(probe.PA.value == p_ref);
        CHECK(probe.PB.value == p_ref);
        CHECK(double(probe.W1A) == 0.);
        CHECK(double(probe.W2A) == -22.617);
        CHECK(double(probe.W3A) == -339.25);
        CHECK(double(probe.W1B) == 0.);
        CHECK(double(probe.W2B) == -22.617);
        CHECK(double(probe.W3B) == 0.);
        CHECK_FALSE(bool(probe.SA));
        CHECK_FALSE(bool(probe.SB));
    }
}

TEST_CASE("BDF CBEAM definitions (OFFT default). (Small Field Format)", "[bdf_cbeam]") {

    std::list<std::string> data({
        "CBEAM   36      103023  7       9       0.0     1000.00 0.0\n",
        "                        0.0     -240.00 0.0     0.0     -240.00 0.0\n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cbeam probe(lines);

    SECTION("OFFT default") {
        // CBEAM   36      103023  7       9       0.0     1000.00 0.0
        //                         0.0     -240.00 0.0     0.0     -240.00 0.0
        CHECK(long(probe.EID) == 36);
        CHECK(long(probe.PID) == 103023);
        CHECK(long(probe.GA) == 7);
        CHECK(long(probe.GB) == 9);
        CHECK_FALSE(bool(probe.G0));
        CHECK(double(probe.X1) == 0.);
        CHECK(double(probe.X2) == 1000.);
        CHECK(double(probe.X3) == 0.);
        CHECK(probe.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(std::string(probe.OFFT) == "GGG");
        CHECK_FALSE(bool(probe.BIT));
        CHECK(probe.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_OFFT);
        std::vector<int> p_ref;
        CHECK(probe.PA == p_ref);
        CHECK(probe.PB == p_ref);
        CHECK(double(probe.W1A) == 0.);
        CHECK(double(probe.W2A) == -240);
        CHECK(double(probe.W3A) == 0.);
        CHECK(double(probe.W1B) == 0.);
        CHECK(double(probe.W2B) == -240.);
        CHECK(double(probe.W3B) == 0.);
        CHECK_FALSE(bool(probe.SA));
        CHECK_FALSE(bool(probe.SB));
    }
}

TEST_CASE("BDF CBEAM definitions. (Small Field Format), dircode",
          "[bdf_cbeam,dcode]") {
    std::list<std::string> data({
        "CBEAM   7869    104010  76      153      13                     GOO     \n",
        "                        0.0     -22.617 -339.25 0.0     22.617 "});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cbeam probe(lines);

    SECTION("dir code cbeam") {
        CHECK(long(probe.EID) == 7869);
        CHECK(long(probe.PID) == 104010);
        CHECK(long(probe.GA) == 76);
        CHECK(long(probe.GB) == 153);
        CHECK(long(probe.G0) == 13);
        CHECK_FALSE(bool(probe.X1));
        CHECK_FALSE(bool(probe.X2));
        CHECK_FALSE(bool(probe.X3));
        CHECK(probe.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DCODE);
        CHECK(std::string(probe.OFFT) == "GOO");
        CHECK_FALSE(bool(probe.BIT));
        CHECK(probe.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_OFFT);
        std::vector<int> p_ref;
        CHECK(probe.PA == p_ref);
        CHECK(probe.PB == p_ref);
        CHECK(double(probe.W1A) == 0.);
        CHECK(double(probe.W2A) == -22.617);
        CHECK(double(probe.W3A) == -339.25);
        CHECK(double(probe.W1B) == 0.);
        CHECK(double(probe.W2B) == 22.617);
        CHECK(double(probe.W3B) == 0.);
        CHECK_FALSE(bool(probe.SA));
        CHECK_FALSE(bool(probe.SB));
    }
}

TEST_CASE("BDF CBEAM definitions (OFFT default). (Small Field Format), dircode",
          "[bdf_cbeam,dcode]") {
    std::list<std::string> data({
        "CBEAM   7869    104010  76      153      13\n",
        "                        0.0     -22.617 -339.25 0.0     22.617 "});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    cbeam probe(lines);
    SECTION("OFFT default") {
        // CBEAM   7869    104010  76      153      13
        //                         0.0     -22.617 -339.25 0.0     22.617
        CHECK(long(probe.EID) == 7869);
        CHECK(long(probe.PID) == 104010);
        CHECK(long(probe.GA) == 76);
        CHECK(long(probe.GB) == 153);
        CHECK(long(probe.G0) == 13);
        CHECK_FALSE(bool(probe.X1));
        CHECK_FALSE(bool(probe.X2));
        CHECK_FALSE(bool(probe.X3));
        CHECK(probe.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DCODE);
        CHECK(std::string(probe.OFFT) == "GGG");
        CHECK_FALSE(bool(probe.BIT) );
        CHECK(probe.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_OFFT);
        std::vector<int> p_ref;
        CHECK(probe.PA == p_ref);
        CHECK(probe.PB == p_ref);
        CHECK(double(probe.W1A) == 0.);
        CHECK(double(probe.W2A) == -22.617);
        CHECK(double(probe.W3A) == -339.25);
        CHECK(double(probe.W1B) == 0.);
        CHECK(double(probe.W2B) == 22.617);
        CHECK(double(probe.W3B) == 0.);
        CHECK_FALSE(bool(probe.SA));
        CHECK_FALSE(bool(probe.SB));
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DCODE, OFFT)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153}, G0{13};
    std::string OFFT("GGG");
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe(&EID, &PID, &GA, &GB, &G0, &OFFT, &PA, &PB,
                &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*                     13                                GGG             \n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK(long(probe_l.G0) == 13);
        CHECK_FALSE(bool(probe_l.X1));
        CHECK_FALSE(bool(probe_l.X2));
        CHECK_FALSE(bool(probe_l.X3));
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DCODE);
        CHECK(std::string(probe_l.OFFT) == "GGG");
        CHECK_FALSE(bool(probe_l.BIT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_OFFT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DCODE, OFFT) (reuse)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153}, G0{13};
    std::string OFFT("GGG");
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe;
    test << probe;
    test << probe(&EID, &PID, &GA, &GB, &G0, &OFFT, &PA, &PB,
                  &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*                     13                                GGG             \n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK(long(probe_l.G0) == 13);
        CHECK_FALSE(bool(probe_l.X1));
        CHECK_FALSE(bool(probe_l.X2));
        CHECK_FALSE(bool(probe_l.X3));
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DCODE);
        CHECK(std::string(probe_l.OFFT) == "GGG");
        CHECK_FALSE(bool(probe_l.BIT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_OFFT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DCODE, BIT)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153}, G0{13};
    double BIT{.72};
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe(&EID, &PID, &GA, &GB, &G0, &BIT, &PA, &PB,
                &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*                     13                                7.20000000000-01\n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK(long(probe_l.G0) == 13);
        CHECK_FALSE(bool(probe_l.X1));
        CHECK_FALSE(bool(probe_l.X2));
        CHECK_FALSE(bool(probe_l.X3));
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DCODE);
        CHECK(double(probe_l.BIT) == .72);
        CHECK_FALSE(bool(probe_l.OFFT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_BIT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DCODE, BIT) (reuse)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153}, G0{13};
    double BIT(.72);
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe;
    test << probe;
    test << probe(&EID, &PID, &GA, &GB, &G0, &BIT, &PA, &PB,
                  &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*                     13                                7.20000000000-01\n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK(long(probe_l.G0) == 13);
        CHECK_FALSE(bool(probe_l.X1));
        CHECK_FALSE(bool(probe_l.X2));
        CHECK_FALSE(bool(probe_l.X3));
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DCODE);
        CHECK(double(probe_l.BIT) == .72);
        CHECK_FALSE(bool(probe_l.OFFT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_BIT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DVEC, OFFT)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153};
    double X1{111.}, X2{222.}, X3{333};

    std::string OFFT("GGG");
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT, &PA, &PB,
                &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*       1.11000000000+022.22000000000+023.33000000000+02GGG             \n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK_FALSE(bool(probe_l.G0));
        CHECK(double(probe_l.X1) == 111.);
        CHECK(double(probe_l.X2) == 222.);
        CHECK(double(probe_l.X3) == 333.);
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(std::string(probe_l.OFFT) == "GGG");
        CHECK_FALSE(bool(probe_l.BIT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_OFFT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DVEC, OFFT) (reuse)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153};
    double X1{111.}, X2{222.}, X3{333};
    std::string OFFT("GGG");
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe;
    test << probe;
    test << probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT, &PA, &PB,
                  &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*       1.11000000000+022.22000000000+023.33000000000+02GGG             \n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK_FALSE(bool(probe_l.G0));
        CHECK(double(probe_l.X1) == 111.);
        CHECK(double(probe_l.X2) == 222.);
        CHECK(double(probe_l.X3) == 333.);
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(std::string(probe_l.OFFT) == "GGG");
        CHECK_FALSE(bool(probe_l.BIT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_OFFT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DVEC, BIT)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153};
    double X1{111.}, X2{222.}, X3{333};
    double BIT{.72};
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &BIT, &PA, &PB,
                &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*       1.11000000000+022.22000000000+023.33000000000+027.20000000000-01\n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK_FALSE(bool(probe_l.G0));
        CHECK(double(probe_l.X1) == 111.);
        CHECK(double(probe_l.X2) == 222.);
        CHECK(double(probe_l.X3) == 333.);
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(double(probe_l.BIT) == .72);
        CHECK_FALSE(bool(probe_l.OFFT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_BIT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

TEST_CASE("BDF CBEAM roundtrip test (DVEC, BIT) (reuse)", "[bdf_cbeam]") {
    cbeam::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, GA{76}, GB{153};
    double X1{111.}, X2{222.}, X3{333};
    double BIT(.72);
    std::vector<int> PA{1, 2};
    std::vector<int> PB{3, 4};
    double W1A{0.}, W2A{-22.617}, W3A{-339.25}, W1B{0.}, W2B{22.617}, W3B{0.};
    long SA{11}, SB{12};

    cbeam probe;
    test << probe;
    test << probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &BIT, &PA, &PB,
                  &W1A, &W2A, &W3A, &W1B, &W2B, &W3B, &SA, &SB);

    SECTION("check output") {
        CHECK(test.str() ==
              "CBEAM*              7869          104010              76             153\n"
              "*       1.11000000000+022.22000000000+023.33000000000+027.20000000000-01\n"
              "*                     12              34 0.0000000000+00-2.2617000000+01\n"
              "*       -3.3925000000+02 0.0000000000+002.26170000000+01 0.0000000000+00\n"
              "*                     11              12\n"
              "*       \n");
    }

    SECTION("check reading") {
        cbeam::reset();
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        cbeam probe_l;
        probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.GA) == 76);
        CHECK(long(probe_l.GB) == 153);
        CHECK_FALSE(bool(probe_l.G0));
        CHECK(double(probe_l.X1) == 111.);
        CHECK(double(probe_l.X2) == 222.);
        CHECK(double(probe_l.X3) == 333.);
        CHECK(probe_l.choose_dir_code == cbeam::CHOOSE_DIR_CODE::has_DVEC);
        CHECK(double(probe_l.BIT) == .72);
        CHECK_FALSE(bool(probe_l.OFFT));
        CHECK(probe_l.choose_offt_bit == cbeam::CHOOSE_OFFT_BIT::has_BIT);
        std::vector<int> p_refA{1, 2};
        CHECK(probe_l.PA == p_refA);
        std::vector<int> p_refB{3, 4};
        CHECK(probe_l.PB == p_refB);
        CHECK(double(probe_l.W1A) == 0.);
        CHECK(double(probe_l.W2A) == -22.617);
        CHECK(double(probe_l.W3A) == -339.25);
        CHECK(double(probe_l.W1B) == 0.);
        CHECK(double(probe_l.W2B) == 22.617);
        CHECK(double(probe_l.W3B) == 0.);
        CHECK(long(probe_l.SA) == 11);
        CHECK(long(probe_l.SB) == 12);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
