/**
   \file tests/test_bdf_cards_pbeaml.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBEAML` card class.

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
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("BDF PBEAML definitions.", "[bdf_PBEAML]") {

   SECTION("Small Field Format (BAR)") {

      std::list<std::string> data({
         // 34567A1234567B1234567C1234567D1234567E1234567F
         "PBEAML  104018  4               BAR\n",
         "           25.0   600.0\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      pbeaml probe(lines);

      CHECK((long)probe.PID == 104018);
      CHECK((long)probe.MID == 4);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "BAR");
      CHECK(probe.DIM.size() == 1);
      CHECK(probe.DIM[0] == std::list<double>({25., 600.}));
      CHECK(probe.NSM == std::list<double>({0.}));
      CHECK(probe.SO.size() == 0);
      CHECK(probe.X_XB.size() == 0);
   }

   SECTION("Small Field Format (BAR 2)") {

      std::list<std::string> data({
         "PBEAML       134       8            BAR\n",
         "            55.0   500.0\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      pbeaml probe(lines);

      CHECK((long)probe.PID == 134);
      CHECK((long)probe.MID == 8);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "BAR");
      CHECK(probe.DIM.size() == 1);
      CHECK(probe.DIM[0] == std::list<double>({55., 500.}));
      CHECK(probe.NSM == std::list<double>({0.}));
      CHECK(probe.SO.size() == 0);
      CHECK(probe.X_XB.size() == 0);
   }

   SECTION("Small Field Format (L)") {

      std::list<std::string> data({
         "PBEAML  104010  4               L\n",
         "           63.0   340.0    35.0    14.0\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      pbeaml probe(lines);

      CHECK((long)probe.PID == 104010);
      CHECK((long)probe.MID == 4);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "L");
      CHECK(probe.DIM.size() == 1);
      CHECK(probe.DIM[0] == std::list<double>({63., 340., 35., 14.}));
      CHECK(probe.NSM == std::list<double>({0.}));
      CHECK(probe.SO.size() == 0);
      CHECK(probe.X_XB.size() == 0);
   }

   SECTION("Small Field Format (T)") {

      std::list<std::string> data({
         "PBEAML  101031  1               T\n",
         "          150.0   400.0    12.0    10.0\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      pbeaml probe(lines);

      CHECK((long)probe.PID == 101031);
      CHECK((long)probe.MID == 1);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "T");
      CHECK(probe.DIM.size() == 1);
      CHECK(probe.DIM[0] == std::list<double>({150., 400., 12., 10.}));
      CHECK(probe.NSM == std::list<double>({0.}));
      CHECK(probe.SO.size() == 0);
      CHECK(probe.X_XB.size() == 0);
   }

   SECTION("Small Field Format (I)") {

      std::list<std::string> data({
         "PBEAML  104018  4               I\n",
         "           600.0   200.0   200.0    12.0    10.0    10.0\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      pbeaml probe(lines);

      CHECK((long)probe.PID == 104018);
      CHECK((long)probe.MID == 4);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "I");
      CHECK(probe.DIM.size() == 1);
      CHECK(probe.DIM[0] == std::list<double>({
               600., 200., 200., 12., 10., 10.}));
      CHECK(probe.NSM == std::list<double>({0.}));
      CHECK(probe.SO.size() == 0);
      CHECK(probe.X_XB.size() == 0);
   }

   SECTION("Small Field Format (TUBE)") {

      std::list<std::string> data({
         "PBEAML  104019  5               TUBE\n",
         "           600.0   500.0"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      pbeaml probe(lines);

      CHECK((long)probe.PID == 104019);
      CHECK((long)probe.MID == 5);
      CHECK(probe.TYPE == "TUBE");
      CHECK(probe.DIM.size() == 1);
      CHECK(probe.DIM[0] == std::list<double>({600., 500.}));
      CHECK(probe.NSM == std::list<double>({0.}));
      CHECK(probe.SO.size() == 0);
      CHECK(probe.X_XB.size() == 0);
   }

   SECTION("Small Field Format (T, tapered)") {

      std::list<std::string> data({
         // 34567A1234567B1234567C1234567D1234567E1234567F1234567G1234567H1234567I1234567J
         "PBEAML        99      21               T                                        \n",
         "             12.    14.8     2.5     2.6              NO     0.4      6.        \n",
         "              7.     1.2     2.6             YES     0.6      6.     7.8        \n",
         "             5.6     2.3             YES                                        \n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      pbeaml probe(lines);

      CHECK((long)probe.PID == 99);
      CHECK((long)probe.MID == 21);
      CHECK(probe.GROUP == "MSCBML0");
      CHECK(probe.TYPE == "T");
      CHECK(probe.DIM.size() == 3);
      CHECK(probe.DIM[0] == std::list<double>({12., 14.8, 2.5, 2.6}));
      CHECK(probe.DIM[1] == std::list<double>({6., 7., 1.2, 2.6}));
      CHECK(probe.DIM[2] == std::list<double>({6., 7.8, 5.6, 2.3}));
      CHECK(probe.NSM == std::list<double>({0., 0., 0.}));
      CHECK(probe.SO == std::list<std::string>({"NO", "YES"}));
      CHECK(probe.X_XB == std::list<double>({.4, .6}));
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
