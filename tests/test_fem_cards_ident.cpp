/**
   \file tests/test_fem_cards_ident.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `IDENT` cards.

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
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM IDENT definitions.", "[fem_ident]" ) {

   std::list<std::string> lines;

   SECTION("IDENT (1)") {
      std::list<std::string> data({
         "IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000\n"});
      __base::card::card_split(data, lines);
      ident probe(lines);

      CHECK(probe.SLEVEL == 1);
      CHECK(probe.SELTYP == 1);
      CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
   }

   SECTION("IDENT (2)") {
      std::list<std::string> data({
         "IDENT   +1.00000000e+000+1.00000000e+000+3.00000000e+000+0.00000000e+000\n"});
      __base::card::card_split(data, lines);
      ident probe(lines);

      CHECK(probe.SLEVEL == 1);
      CHECK(probe.SELTYP == 1);
      CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
   }

   SECTION("IDENT (3)") {
      std::list<std::string> data({
         "IDENT    1.000000000e+00 1.000000000e+00 3.000000000e+00 0.000000000e+00\n"});
      __base::card::card_split(data, lines);
      ident probe(lines);

      CHECK(probe.SLEVEL == 1);
      CHECK(probe.SELTYP == 1);
      CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
   }

   SECTION("IDENT (4)") {
      std::list<std::string> data({
         "IDENT    1.000000000e+00 1.000000000e+00 3.000000000e+00\n"});
      __base::card::card_split(data, lines);
      ident probe(lines);

      CHECK(probe.SLEVEL == 1);
      CHECK(probe.SELTYP == 1);
      CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
   }
}

TEST_CASE("FEM IDENT types output.", "[fem_ident,out]" ) {

   std::ostringstream test;

   SECTION("empty") {
      ident probe;
      test << probe;
      CHECK(test.str() == "");
   }

   SECTION("const") {
      ident probe(1, 2, ident::mod_type::DIM_3D);
      test << probe;
      CHECK(test.str() ==
            "IDENT   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n");
   }

   SECTION("simple") {
      long SLEVEL(1), SELTYP(2);
      ident::mod_type SELMOD(ident::mod_type::DIM_3D);
      ident probe(SLEVEL, SELTYP, SELMOD);
      test << probe;
      CHECK(test.str() ==
            "IDENT   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n");
   }
}

TEST_CASE("FEM IDENT conversion from own output.", "[fem_ident,in/out]") {

   std::list<std::string> lines;

   SECTION("IDENT (1)") {
      std::list<std::string> data({
            "IDENT   +1.000000000e+00+2.000000000e+00+3.000000000e+00\n"});
      __base::card::card_split(data, lines);
      ident probe(lines);

      CHECK(probe.SLEVEL == 1);
      CHECK(probe.SELTYP == 2);
      CHECK(probe.SELMOD == ident::mod_type::DIM_3D);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
