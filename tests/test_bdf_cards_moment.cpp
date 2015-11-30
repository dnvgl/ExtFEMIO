/**
   \file tests/test_bdf_cards_moment.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF MOMENT card class.

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

#include "bdf/cards.h"

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif

#include "bdf/cards.h"
#include "bdf/errors.h"

using namespace ::std;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("BDF MOMENT definitions. (Small Field Format)", "[bdf_moment]" ) {

   ::std::deque<string> data;
   data.push_back(
      // 12345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      "MOMENT  2       5       6       2.9     0.0     1.9     0.0               \n");
   ::std::deque<string> lines;
   card::card_split(data, lines);
   moment probe(lines);

   SECTION("first moment") {
      CHECK((long)probe.SID == 2);
      CHECK((long)probe.G == 5);
      CHECK((long)probe.CID == 6);
      CHECK((double)probe.F == 2.9);
      CHECK((double)probe.N1 == 0.);
      CHECK((double)probe.N2 == 1.9);
      CHECK((double)probe.N3 == 0.);
   }
}

TEST_CASE("BDF MOMENT types output.", "[bdf_moment,out]" ) {

   std::ostringstream test;

   SECTION("reverse") {
      long SID(2), G(5), CID(6);
      double F(2.9), N1(0.), N2(1.9), N3(0.);
      moment probe(&SID, &G, &CID, &F, &N1, &N2, &N3);
      test << probe;
      CHECK(test.str() ==
            "MOMENT         2       5       62.900+000.000+001.900+000.000+00\n");
   }

   SECTION("reverse part") {
      long SID(2), G(5), CID(6);
      double F(2.9), N1(0.), N2(1.9);
      moment probe(&SID, &G, &CID, &F, &N1, &N2);
      test << probe;
      CHECK(test.str() ==
            "MOMENT         2       5       62.900+000.000+001.900+00\n");
   }

   SECTION("reverse part (2)") {
      long SID(2), G(5), CID(6);
      double F(2.9), N1(1.9);
      moment probe(&SID, &G, &CID, &F, &N1);
      test << probe;
      CHECK(test.str() ==
            "MOMENT         2       5       62.900+001.900+00\n");
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
