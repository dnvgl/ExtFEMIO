/**
   \file tests/test_fem_cards_gcoord.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GCOORDS` cards.

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

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex.what();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GCOORD definitions.", "[fem_gcoord]" ) {

   std::list<std::string> lines;

   SECTION("GCOORD (1)") {
      std::list<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GCOORD   1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n"});
      __base::card::card_split(data, lines);
      gcoord probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.XCOORD == 1.);
      CHECK(probe.YCOORD == 3.);
      CHECK(probe.ZCOORD == 134.);
   }

   SECTION("GCOORD (2)") {
      std::list<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GCOORD   1.000000000e+00 1.000000000e+00 3.000000000e+00 1.34000000e+02 \n"});
      __base::card::card_split(data, lines);
      gcoord probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.XCOORD == 1.);
      CHECK(probe.YCOORD == 3.);
      CHECK(probe.ZCOORD == 134.);
   }

   SECTION("GCOORD (own output)") {
      std::list<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
      __base::card::card_split(data, lines);
      gcoord probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.XCOORD == 1.);
      CHECK(probe.YCOORD == 3.);
      CHECK(probe.ZCOORD == 134.);
   }

   SECTION("reuse (GCOORD)") {
      std::list<std::string> data({
         // 345678|234567890123456|234567890123456|234567890123456|234567890123456
         "GCOORD   1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n"});
      __base::card::card_split(data, lines);
      gcoord probe;
      probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.XCOORD == 1.);
      CHECK(probe.YCOORD == 3.);
      CHECK(probe.ZCOORD == 134.);
   }

}

TEST_CASE("FEM GCOORD types output.", "[fem_gcoord,out]" ) {

   std::ostringstream test;

   long NODENO(1);
   double XCOORD(1.), YCOORD(3.), ZCOORD(134.);

   SECTION("empty") {
      gcoord probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("const") {
      gcoord probe(1, 1., 3., 134.);
      test << probe;
      CHECK(test.str() ==
            "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }

   SECTION("simple") {
      gcoord probe(NODENO, XCOORD, YCOORD, ZCOORD);
      test << probe;
      CHECK(test.str() ==
            "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }

   SECTION("reuse (const)") {
      gcoord probe;
      test << probe(1, 1., 3., 134.);
      CHECK(test.str() ==
            "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }

   SECTION("resue (simple)") {
      gcoord probe;
      test << probe(NODENO, XCOORD, YCOORD, ZCOORD);
      CHECK(test.str() ==
            "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }

   SECTION("reuse (multiple)") {
      gcoord probe;
      test << probe;
      test << probe(1, 1., 3., 134.);
      test << probe(NODENO, XCOORD, YCOORD, ZCOORD);
      NODENO++;
      XCOORD += 5.;
      test << probe(NODENO, XCOORD, YCOORD, ZCOORD);
      test << probe;
      CHECK(test.str() ==
            "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"
            "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"
            "GCOORD  +2.000000000e+00+6.000000000e+00+3.000000000e+00+1.340000000e+02\n"
            "GCOORD  +2.000000000e+00+6.000000000e+00+3.000000000e+00+1.340000000e+02\n");
   }
}

TEST_CASE("FEM GCOORD conversion from own output.", "[fem_gcoord,in/out]") {

   std::list<std::string> lines;

   SECTION("GCOORD") {
      std::list<std::string> data({
            "GCOORD  +1.000000000e+00+1.000000000e+00+3.000000000e+00+1.340000000e+02\n"});
      __base::card::card_split(data, lines);
      gcoord probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.XCOORD == 1.);
      CHECK(probe.YCOORD == 3.);
      CHECK(probe.ZCOORD == 134.);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
