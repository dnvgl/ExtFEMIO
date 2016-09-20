/**
   \file tests/test_bdf_cards_cmass4.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the BDF `CMASS4` card class.

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

#include "config.h"

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

TEST_CASE("BDF CMASS4 definitions. (Small Field Format)", "[bdf_cmass4]" ) {

   std::list<std::string> data({
      // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      "CMASS4  1       3.      32      33 \n"});
   std::list<std::string> lines;
   __base::card::card_split(data, lines);
   cmass4 probe(lines);

   SECTION("first cmass4") {
      CHECK((long)probe.EID == 1);
      CHECK((double)probe.M == 3.);
      CHECK((long)probe.S1 == 32);
      CHECK((long)probe.S2 == 33);
   }
}

TEST_CASE("BDF CMASS4 types output.", "[bdf_cmass4,out]" ) {

   std::ostringstream test;

   SECTION("empty") {
      cmass4 probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("reverse") {
      long EID(2), S1(6), S2(1);
      double M(2.9);
      cmass4 probe(&EID, &M, &S1, &S2);
      test << probe;
      CHECK(test.str() ==
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "CMASS4         22.900+00       6       1\n");
   }

   SECTION("reverse part") {
      long EID(2), S1(6);
      double M(2.9);
      cmass4 probe(&EID, &M, &S1);
      test << probe;
      CHECK(test.str() ==
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "CMASS4         22.900+00       6\n");
   }

   SECTION("failed part") {
      long EID(0), S1(6);
      double M(2.9);
      CHECK_THROWS(
         cmass4 probe(&EID, &M, &S1));
   }

   SECTION("multiple") {
      long EID(1), S1(2);
      double M(3.);
      cmass4 probe;
      test << *probe(&EID, &M, &S1);
      EID++;
      test << *probe(&EID, &M, &S1);
      CHECK(test.str() ==
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "CMASS4         13.000+00       2\n"
            "CMASS4         23.000+00       2\n");
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
