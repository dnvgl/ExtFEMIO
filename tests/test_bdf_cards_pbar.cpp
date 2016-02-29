/**
   \file tests/test_bdf_cards_pbar.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBAR` card class.

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

using namespace ::std;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("BDF PBAR definitions.", "[bdf_PBAR]") {

   SECTION("Free Field Format (generic)") {

      ::std::deque<string> data;
      data.push_back(
         "PBAR,1,2,3.,4.,5.,6.,7.,,9.,10.,11.,12.,13.,14.,15.,16.,17.,"
         "18.,19.\n");
      ::std::deque<string> lines;
      card::card_split(data, lines);
      pbar probe(lines);

      CHECK((long)probe.PID ==  1);
      CHECK((long)probe.MID ==  2);
      CHECK((double)probe.A ==   3.);
      CHECK((double)probe.I1 ==  4.);
      CHECK((double)probe.I2 ==  5.);
      CHECK((double)probe.J ==   6.);
      CHECK((double)probe.NSM == 7.);
      CHECK((double)probe.C1 ==  9.);
      CHECK((double)probe.C2 == 10.);
      CHECK((double)probe.D1 == 11.);
      CHECK((double)probe.D2 == 12.);
      CHECK((double)probe.E1 == 13.);
      CHECK((double)probe.E2 == 14.);
      CHECK((double)probe.F1 == 15.);
      CHECK((double)probe.F2 == 16.);
      CHECK((double)probe.K1 == 17.);
      CHECK((double)probe.K2 == 18.);
      CHECK((double)probe.I12 == 19.);
   }

   SECTION("Small Field Format 1") {

      ::std::deque<string> data;
      data.push_back(
         "PBAR    4000001 3       1.046+4 9.369+7 1.694+6 1.316+6\n");
      data.push_back(
         "                        6.856+6\n");
      ::std::deque<string> lines;
      card::card_split(data, lines);
      pbar probe(lines);

      CHECK((long)probe.PID == 4000001);
      CHECK((long)probe.MID == 3);
      CHECK((double)probe.A == 10460.);
      CHECK((double)probe.I1 == 93690000.);
      CHECK((double)probe.I2 == 1694000.);
      CHECK((double)probe.J == 1316000.);
      CHECK((double)probe.NSM == 0.);
      CHECK((double)probe.C1 == 0.);
      CHECK((double)probe.C2 == 0.);
      CHECK((double)probe.D1 == 6.856e6);
      CHECK((double)probe.D2 == 0.);
      CHECK((double)probe.E1 == 0.);
      CHECK((double)probe.E2 == 0.);
      CHECK((double)probe.F1 == 0.);
      CHECK((double)probe.F2 == 0.);
      CHECK_FALSE(probe.K1);
      CHECK_FALSE(probe.K2);
      CHECK((double)probe.I12 == 0.);
   }

   SECTION("Small Field Format 2") {

      ::std::deque<string> data;
      data.push_back(
//     1234567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PBAR          29       6     2.9            5.97                                \n");
      data.push_back(
         "                             2.0     4.0                                        \n");
      ::std::deque<string> lines;
      card::card_split(data, lines);
      pbar probe(lines);

      CHECK((long)probe.PID == 29);
      CHECK((long)probe.MID == 6);
      CHECK((double)probe.A == 2.9);
      CHECK((double)probe.I1 == 0.);
      CHECK((double)probe.I2 == 5.97);
      CHECK((double)probe.J == 0.);
      CHECK((double)probe.NSM == 0.);
      CHECK((double)probe.C1 == 0.);
      CHECK((double)probe.C2 == 0.);
      CHECK((double)probe.D1 == 2.);
      CHECK((double)probe.D2 == 4.);
      CHECK((double)probe.E1 == 0.);
      CHECK((double)probe.E2 == 0.);
      CHECK((double)probe.F1 == 0.);
      CHECK((double)probe.F2 == 0.);
      CHECK_FALSE(probe.K1);
      CHECK_FALSE(probe.K2);
      CHECK((double)probe.I12 == 0.);
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
