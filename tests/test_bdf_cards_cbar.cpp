// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF CBAR card class.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf/cards.h"

using namespace ::std;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
  return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
  return ex;
}

TEST_CASE("BDF CBAR definitions. (Small Field Format)", "[bdf_cbar]" ) {

  ::std::deque<string> data;
  data.push_back("CBAR    7869    104010  76      153     0.0     66.5206 997.785 \n");
  data.push_back("                        0.0     -22.617 -339.25 0.0     -22.617 \n");
  ::std::deque<string> lines = card::card_split(data);
  cbar probe(lines);

  SECTION("first cbar") {
    CHECK(*probe.EID == 7869);
    CHECK(*probe.PID == 104010);
    CHECK(*probe.GA == 76);
    CHECK(*probe.GB == 153);
    CHECK(*probe.X1 == 0.);
    CHECK(*probe.X2 == 66.5206);
    CHECK(*probe.X3 == 997.785);
    CHECK_FALSE(probe.G0);
    CHECK(probe.choose_dir_code == cbar::has_DVEC);
    CHECK(*probe.OFFT == "GGG");
    deque<int> p_ref;
    CHECK(*probe.PA == p_ref);
    CHECK(*probe.PB == p_ref);
    CHECK(*probe.W1A == 0.);
    CHECK(*probe.W2A == -22.617);
    CHECK(*probe.W3A == -339.25);
    CHECK(*probe.W1B == 0.);
    CHECK(*probe.W2B == -22.617);
    CHECK(*probe.W3B == 0.);
  }
}

TEST_CASE("BDF CBAR definitions. (Small Field Format), dircode",
          "[bdf_cbar,dcode]" ) {

  ::std::deque<string> data;
  data.push_back("CBAR    7869    104010  76      153      13      "
                 "               GOO     \n");
  data.push_back("                        0.0     -22.617 -339.25 "
                 "0.0     -22.617 ");
  ::std::deque<string> lines = card::card_split(data);
  cbar probe(lines);

  SECTION("dir code cbar") {
    CHECK(*probe.EID == 7869);
    CHECK(*probe.PID == 104010);
    CHECK(*probe.GA == 76);
    CHECK(*probe.GB == 153);
    CHECK(*probe.G0 == 13);
    CHECK_FALSE(probe.X1);
    CHECK_FALSE(probe.X2);
    CHECK_FALSE(probe.X3);
    CHECK(probe.choose_dir_code == cbar::has_DCODE);
    CHECK(*probe.OFFT == "GOO");
    deque<int> p_ref;
    CHECK(*probe.PA == p_ref);
    CHECK(*probe.PB == p_ref);
    CHECK(*probe.W1A == 0.);
    CHECK(*probe.W2A == -22.617);
    CHECK(*probe.W3A == -339.25);
    CHECK(*probe.W1B == 0.);
    CHECK(*probe.W2B == -22.617);
    CHECK(*probe.W3B == 0.);
  }
}

TEST_CASE("BDF CBAR types output.", "[bdf_cbar,out]" ) {

  std::ostringstream test;

  SECTION("dir code") {
    long EID(1), PID(2), GA(3), GB(4), G0(5);

    cbar probe(&EID, &PID, &GA, &GB, &G0);
    test << probe;
    CHECK(test.str() == "CBAR           1       2       3       4       5\n");
  }

  SECTION("QRG sample 1") {
    long EID(2), PID(39), GA(7), GB(3);
    double X1(.6), X2(18), X3(26);
    std::string OFFT("EEG");

    cbar probe(&EID, &PID, &GA, &GB, &X1, &X2, &X3, &OFFT);
    std::deque<int> PB;
    PB.push_back(5);
    PB.push_back(1);
    PB.push_back(3);
    probe.PB = std::make_unique<std::deque<int>>(PB);
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
    std::deque<int> PB;
    PB.push_back(5);
    PB.push_back(1);
    PB.push_back(3);
    probe.PB = std::make_unique<std::deque<int>>(PB);
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
    probe.W3B = std::make_unique<double>(2.);
    test << probe;
    CHECK(test.str() ==
          "CBAR           1       2       3       4       5                        \n"
          "                                                                2.000+00\n");
  }

  SECTION("dir code all large") {
    long EID(123456789), PID(2), GA(3), GB(4), G0(5);

    cbar probe(&EID, &PID, &GA, &GB, &G0);
    probe.W3B = std::make_unique<double>(2.);
    test << probe;
    CHECK(test.str() ==
          //234567!123456789012345!123456789012345!123456789012345!123456789012345!
          "CBAR*          123456789               2               3               4\n"
          "*                      5                                                \n"
          "*                                                                       \n"
          "*                                                       2.00000000000+00\n");
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
