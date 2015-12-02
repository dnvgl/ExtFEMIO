/**
   \file tests/test_fem_cards_gcoord.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM GCOORDS cards.

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
#include "fem/cards.h"

using namespace ::std;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GCOORD definitions.", "[fem_gcoord]" ) {

   SECTION("GCOORD (1)") {
      ::std::deque<string> data;
      data.push_back("GCOORD   1.00000000e+000 1.00000000e+000 3.00000000e+000 1.34000000e+002\n");
      ::std::deque<string> lines = card::card_split(data);
      gcoord probe(lines);

      CHECK(probe.NODENO == 1);
      CHECK(probe.XCOORD == 1.);
      CHECK(probe.YCOORD == 3.);
      CHECK(probe.ZCOORD == 134.);
   }

   SECTION("GCOORD (2)") {
      ::std::deque<string> data;
      data.push_back("GCOORD   1.00000000e+00  1.00000000e+00  3.00000000e+00  1.34000000e+02 \n");
      ::std::deque<string> lines = card::card_split(data);
      gcoord probe(lines);

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

   SECTION("simple") {
      gcoord probe(NODENO, XCOORD, YCOORD, ZCOORD);
      test << probe;
      CHECK(test.str() == "GCOORD  +1.00000000e+00 +1.00000000e+00 +3.00000000e+00 +1.34000000e+02 \n");
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
