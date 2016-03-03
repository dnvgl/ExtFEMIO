/**
   \file tests/test_bdf_cards_pbarl.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBARL` card class.

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

using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("BDF PBARL definitions.", "[bdf_PBARL]") {

   SECTION("Small Field Format (BAR)") {

      std::deque<std::string> data;
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBARL   104018  4               BAR\n");
      data.push_back(
         "           25.0   600.0\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pbarl probe(lines);

      CHECK((long)probe.PID == 104018);
      CHECK((long)probe.MID == 4);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "BAR");
      CHECK(probe.DIM.size() == 2);
      CHECK(probe.DIM[0] == 25.);
      CHECK(probe.DIM[1] == 600.);
      CHECK((double)probe.NSM == 0.);
   }


   SECTION("Small Field Format (BAR) (alt.)") {

      std::deque<std::string> data;
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBARL        134       8            BAR\n");
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "            55.0   500.0");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pbarl probe(lines);

      CHECK((long)probe.PID == 134);
      CHECK((long)probe.MID == 8);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "BAR");
      CHECK(probe.DIM.size() == 2);
      CHECK(probe.DIM[0] == 55.);
      CHECK(probe.DIM[1] == 500.);
      CHECK((double)probe.NSM == 0.);
   }

   SECTION("Small Field Format (L)") {

      std::deque<std::string> data;
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBARL   104010  4               L\n");
      data.push_back(
         "           63.0   340.0    35.0    14.0\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pbarl probe(lines);

      CHECK((long)probe.PID == 104010);
      CHECK((long)probe.MID == 4);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "L");
      CHECK(probe.DIM.size() == 4);
      CHECK(probe.DIM[0] == 63.);
      CHECK(probe.DIM[1] == 340.);
      CHECK((double)probe.DIM[2] == 35.);
      CHECK((double)probe.DIM[3] == 14.);
      CHECK((double)probe.NSM == 0.);
   }

   SECTION("Small Field Format (T)") {

      std::deque<std::string> data;
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBARL   101031  1               T\n");
      data.push_back(
         "          150.0   400.0    12.0    10.0\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pbarl probe(lines);

      CHECK((long)probe.PID == 101031);
      CHECK((long)probe.MID == 1);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "T");
      CHECK(probe.DIM.size() == 4);
      CHECK(probe.DIM[0] == 150.);
      CHECK(probe.DIM[1] == 400.);
      CHECK(probe.DIM[2] == 12.);
      CHECK(probe.DIM[3] == 10.);
      CHECK((double)probe.NSM == 0.);
   }

   SECTION("Small Field Format (I)") {

      std::deque<std::string> data;
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBARL   104018  4               I\n");
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "           600.0   200.0   200.0    12.0    10.0    10.0\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pbarl probe(lines);

      CHECK((long)probe.PID == 104018);
      CHECK((long)probe.MID == 4);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "I");
      CHECK(probe.DIM.size() == 6);
      CHECK(probe.DIM[0] == 600.);
      CHECK(probe.DIM[1] == 200.);
      CHECK(probe.DIM[2] == 200.);
      CHECK(probe.DIM[3] == 12.);
      CHECK(probe.DIM[4] == 10.);
      CHECK(probe.DIM[5] == 10.);
      CHECK((double)probe.NSM == 0.);
   }

   SECTION("Small Field Format (I) (alt)") {

      std::deque<std::string> data;
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBARL         39       6               I\n");
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "             14.      6.      .5      .5      .5      .5\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pbarl probe(lines);

      CHECK((long)probe.PID == 39);
      CHECK((long)probe.MID == 6);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "I");
      CHECK(probe.DIM.size() == 6);
      CHECK(probe.DIM[0] == 14.);
      CHECK(probe.DIM[1] == 6.);
      CHECK(probe.DIM[2] == .5);
      CHECK(probe.DIM[3] == .5);
      CHECK(probe.DIM[4] == .5);
      CHECK(probe.DIM[5] == .5);
      CHECK((double)probe.NSM == 0.);
   }

   SECTION("Small Field Format (TUBE)") {

      std::deque<std::string> data;
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBARL   104019  5               TUBE\n");
      data.push_back(
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "           600.0   500.0\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pbarl probe(lines);

      CHECK((long)probe.PID == 104019);
      CHECK((long)probe.MID == 5);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "TUBE");
      CHECK(probe.DIM.size() == 2);
      CHECK(probe.DIM[0] == 600.);
      CHECK(probe.DIM[1] == 500.);
      CHECK((double)probe.NSM == 0.);
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
