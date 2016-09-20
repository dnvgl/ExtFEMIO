/**
   \file tests/test_bdf_cards_grav.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the BDF `GRAV` card class.

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

TEST_CASE("BDF GRAV definitions. (Small Field Format)", "[bdf_grav]" ) {

   std::list<std::string> data({
      // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
      "GRAV    1       3       32.2    0.0     0.0     -1.0    0                 \n"});
   std::list<std::string> lines;
   __base::card::card_split(data, lines);
   grav probe(lines);

   SECTION("first grav") {
      CHECK((long)probe.SID == 1);
      CHECK((long)probe.CID == 3);
      CHECK((double)probe.A == 32.2);
      CHECK((double)probe.N1 == 0.);
      CHECK((double)probe.N2 == 0.);
      CHECK((double)probe.N3 == -1.);
      CHECK((long)probe.MB == 0);
   }
}

TEST_CASE("BDF GRAV types output.", "[bdf_grav,out]" ) {

   std::ostringstream test;

   SECTION("reverse") {
      long SID(2), CID(6), MB(1);
      double A(2.9), N1(0.), N2(1.9), N3(0.);
      grav probe(&SID, &CID, &A, &N1, &N2, &N3, &MB);
      test << probe;
      CHECK(test.str() ==
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "GRAV           2       62.900+00 0.00+001.900+00 0.00+00       1\n");
   }

   SECTION("reverse part") {
      long SID(2), CID(6);
      double A(2.9);
      std::vector<double> N({0., 1.8, 0.});
      grav probe(&SID, &CID, &A, &N);
      test << probe;
      CHECK(test.str() ==
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "GRAV           2       62.900+00 0.00+001.800+00 0.00+00\n");
   }

   SECTION("failed part") {
      long SID(2), CID(6);
      double A(2.9);
      std::vector<double> N({0., 1.8, 0., 4.});
      CHECK_THROWS(
         grav probe(&SID, &CID, &A, &N));
   }

   SECTION("reuse") {
      long SID(1), CID(2), MB(7);
      double A(3.), N1(4.), N2(5), N3(6.);
      std::vector<double> N({8., 9., 10.});
      grav probe;
      test << *probe(&SID, &CID, &A, &N1, &N2, &N3, &MB);
      SID++;
      CID++;
      A += 4.;
      test << *probe(&SID, &CID, &A, &N1, &N2, &N3, &MB);
      SID++;
      test << *probe(&SID, &CID, &A, &N1, &N2, &N3);
      SID++;
      test << *probe(&SID, &CID, &A, &N);
      SID++;
      test << *probe(&SID, &CID, &A, &N, &MB);
      CHECK(test.str() ==
            "GRAV           1       23.000+004.000+005.000+006.000+00       7\n"
            "GRAV           2       37.000+004.000+005.000+006.000+00       7\n"
            "GRAV           3       37.000+004.000+005.000+006.000+00\n"
            "GRAV           4       37.000+008.000+009.000+001.000+01\n"
            "GRAV           5       37.000+008.000+009.000+001.000+01       7\n");
   }

}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
