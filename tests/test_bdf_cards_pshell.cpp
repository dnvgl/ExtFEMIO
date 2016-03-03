/**
   \file tests/test_bdf_cards_pshell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PSHELL` card class.

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

TEST_CASE("BDF PSHELL definitions.",
          "[bdf_PSHELL]") {

   SECTION("Small Field Format") {

      std::deque<std::string> data;
      data.push_back(
         "PSHELL  1       4         23.00 4               4\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pshell probe(lines);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID1 == 4);
      CHECK((double)probe.T == 23.);
      CHECK((long)probe.MID2 == 4);
      CHECK((double)probe.x12I_T__3 == 1.);
      CHECK((long)probe.MID3 == 4);
   }

   SECTION("Large Field Format") {

      std::deque<std::string> data;
      data.push_back(
         "PSHELL* 1               4                 23.00         4  "
         "             \n");
      data.push_back(
         "*                       4  \n");

      std::deque<std::string> lines;
      card::card_split(data, lines);
      pshell probe(lines);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID1 == 4);
      CHECK((double)probe.T == 23.);
      CHECK((long)probe.MID2 == 4);
      CHECK((double)probe.x12I_T__3 == 1.);
      CHECK((long)probe.MID3 == 4);
   }

   SECTION("Comma Field Format") {

      std::deque<std::string> data;
      data.push_back("PSHELL,1,4,23.00,4,,4\n");
      std::deque<std::string> lines;
      card::card_split(data, lines);
      pshell probe(lines);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID1 == 4);
      CHECK((double)probe.T == 23.);
      CHECK((long)probe.MID2 == 4);
      CHECK((double)probe.x12I_T__3 == 1.);
      CHECK((long)probe.MID3 == 4);
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
