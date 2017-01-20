/**
   \file tests/test_fem_cards_geccen.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GECCEN` cards.

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

#include "fem/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex.what();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GECCEN definitions.", "[fem_geccen]" ) {

   vector<std::string> lines;
   size_t len;

   SECTION("GECCEN (1)") {
      vector<std::string> data({
         "GECCEN   1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n"});
      len = __base::card::card_split(data, data.size(), lines);
      geccen probe(lines, len);

      CHECK(probe.ECCNO == 1);
      CHECK(probe.EX == 1.);
      CHECK(probe.EY == 3.);
      CHECK(probe.EZ == 134.);
   }

   SECTION("GECCEN (2)") {
      vector<std::string> data({
         "GECCEN   1.000000000e+00 1.000000000e+00 3.000000000e+00 1.34000000e+02 \n"});
      len = __base::card::card_split(data, data.size(), lines);
      geccen probe(lines, len);

      CHECK(probe.ECCNO == 1);
      CHECK(probe.EX == 1.);
      CHECK(probe.EY == 3.);
      CHECK(probe.EZ == 134.);
   }

   SECTION("GECCEN (3)") {
      vector<std::string> data({
         "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
      len = __base::card::card_split(data, data.size(), lines);
      geccen probe(lines, len);

      CHECK(probe.ECCNO == 1);
      CHECK(probe.EX == 1.);
      CHECK(probe.EY == 3.);
      CHECK(probe.EZ == 134.);
   }
}

TEST_CASE("FEM GECCEN types output.", "[fem_geccen,out]" ) {

   std::ostringstream test;

   long ECCNO(1);
   double EX(1.), EY(3.), EZ(134.);

   SECTION("empty") {
      geccen probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("const") {
      geccen probe(1, 1., 3., 134.);
      test << probe;
      CHECK(test.str() ==
            "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }

   SECTION("simple") {
      geccen probe(ECCNO, EX, EY, EZ);
      test << probe;
      CHECK(test.str() ==
            "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }

   SECTION("vector") {
      geccen probe(ECCNO, std::vector<double>({EX, EY, EZ}));
      test << probe;
      CHECK(test.str() ==
            "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }
}

TEST_CASE("FEM GECCEN conversion from own output.", "[fem_geccen,in/out]") {

   vector<std::string> lines;
   size_t len;

   SECTION("GECCEN") {
      vector<std::string> data({
            "GECCEN  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
      len = __base::card::card_split(data, data.size(), lines);
      geccen probe(lines, len);

      CHECK(probe.ECCNO == 1);
      CHECK(probe.EX == 1.);
      CHECK(probe.EY == 3.);
      CHECK(probe.EZ == 134.);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
