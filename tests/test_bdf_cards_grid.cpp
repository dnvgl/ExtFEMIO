/**
   \file tests/test_bdf_cards_grid.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `GRID` cards classes.

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

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return Catch::toString( ex() );
}

TEST_CASE("BDF GRID definitions. (Small Field Format)",
          "[bdf_grid]" ) {

   std::deque<std::string> data;
   data.push_back(
      "GRID           1      22111525. 18000.  21000.        11       6       2\n");

   std::deque<std::string> lines;
   card::card_split(data, lines);
   grid probe(lines);

   SECTION("first grid") {
      CHECK((long)probe.ID == 1);
      CHECK((long)probe.CP == 22);
      CHECK((double)probe.X1 == 111525.);
      CHECK((double)probe.X2 == 18000.);
      CHECK((double)probe.X3 == 21000.);
      CHECK((long)probe.CD == 11);
      std::deque<int> ps_ref;
      ps_ref.push_back(6);
      CHECK(probe.PS == ps_ref);
      CHECK((long)probe.SEID == 2);
   }
}

TEST_CASE("BDF GRID definitions. (Large Field Format)",
          "[bdf_grid]" ) {

   std::deque<std::string> data;
   data.push_back(
      "GRID*                  1              22         111525.          18000.\n");
   data.push_back(
      "                  21000.              11               6               2\n");

   std::deque<std::string> lines;
   card::card_split(data, lines);
   grid probe(lines);

   SECTION("first grid") {
      CHECK((long)probe.ID == 1);
      CHECK((long)probe.CP == 22);
      CHECK((double)probe.X1 == 111525.);
      CHECK((double)probe.X2 == 18000.);
      CHECK((double)probe.X3 == 21000.);
      CHECK((long)probe.CD == 11);
      std::deque<int> ps_ref;
      ps_ref.push_back(6);
      CHECK(probe.PS == ps_ref);
      CHECK((long)probe.SEID == 2);
   }
}

TEST_CASE("BDF GRID definitions. (Free Field Format)",
          "[bdf_grid]" ) {

   std::deque<std::string> data;
   SECTION("first grid") {
      data.empty();
      data.push_back("GRID,1,22,111525.,18000.,21000.,11,6,2\n");

      std::deque<std::string> lines;
      card::card_split(data, lines);
      grid probe(lines);

      CHECK((long)probe.ID == 1);
      CHECK((long)probe.CP == 22);
      CHECK((double)probe.X1 == 111525.);
      CHECK((double)probe.X2 == 18000.);
      CHECK((double)probe.X3 == 21000.);
      CHECK((long)probe.CD == 11);
      std::deque<int> ps_ref;
      ps_ref.push_back(6);
      CHECK(probe.PS == ps_ref);
      CHECK((long)probe.SEID == 2);
   }

   SECTION("first grid (cont)") {
      data.empty();
      data.push_back("GRID,1,22,111525.,\n");
      data.push_back(",18000.,21000.,11,6,2\n");

      std::deque<std::string> lines;
      card::card_split(data, lines);
      grid probe(lines);

      CHECK((long)probe.ID == 1);
      CHECK((long)probe.CP == 22);
      CHECK((double)probe.X1 == 111525.);
      CHECK((double)probe.X2 == 18000.);
      CHECK((double)probe.X3 == 21000.);
      CHECK((long)probe.CD == 11);
      std::deque<int> ps_ref;
      ps_ref.push_back(6);
      CHECK(probe.PS == ps_ref);
      CHECK((long)probe.SEID == 2);
   }

   SECTION("first grid (cont+)") {
      data.empty();
      data.push_back("GRID,1,22,111525.,+");
      data.push_back("+,18000.,21000.,11,6,2\n");

      std::deque<std::string> lines;
      card::card_split(data, lines);
      grid probe(lines);

      CHECK((long)probe.ID == 1);
      CHECK((long)probe.CP == 22);
      CHECK((double)probe.X1 == 111525.);
      CHECK((double)probe.X2 == 18000.);
      CHECK((double)probe.X3 == 21000.);
      CHECK((long)probe.CD == 11);
      std::deque<int> ps_ref;
      ps_ref.push_back(6);
      CHECK(probe.PS == ps_ref);
      CHECK((long)probe.SEID == 2);
   }

   SECTION("first grid (cont named +)") {
      data.empty();
      data.push_back("GRID,1,22,111525.,+G001\n");
      data.push_back("+G001,18000.,21000.,11,6,2\n");

      std::deque<std::string> lines;
      card::card_split(data, lines);
      grid probe(lines);

      CHECK((long)probe.ID == 1);
      CHECK((long)probe.CP == 22);
      CHECK((double)probe.X1 == 111525.);
      CHECK((double)probe.X2 == 18000.);
      CHECK((double)probe.X3 == 21000.);
      CHECK((long)probe.CD == 11);
      std::deque<int> ps_ref;
      ps_ref.push_back(6);
      CHECK(probe.PS == ps_ref);
      CHECK((long)probe.SEID == 2);
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// coding: utf-8
// End:
