/**
   \file tests/test_fem_cards_iend.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `IEND` cards.

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

TEST_CASE("FEM IEND definitions.", "[fem_iend]" ) {

   vector<std::string> lines;
   size_t len;

   SECTION("IEND (1)") {
      vector<std::string> data({
         "IEND     1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
      len = __base::card::card_split(data, data.size(), lines);
      iend probe(lines, len);

      CHECK(probe.CONT == 1);
   }

   SECTION("IEND (2)") {
      vector<std::string> data({
         "IEND    +1.00000000e+000+0.00000000e+000+0.00000000e+000+0.00000000e+000\n"});
      len = __base::card::card_split(data, data.size(), lines);
      iend probe(lines, len);

      CHECK(probe.CONT == 1);
   }

   SECTION("IEND (3)") {
      vector<std::string> data({
         "IEND     1.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n"});
      len = __base::card::card_split(data, data.size(), lines);
      iend probe(lines, len);

      CHECK(probe.CONT == 1);
   }

   SECTION("IEND (4)") {
      vector<std::string> data({
         "IEND                0.00            0.00            0.00            0.00\n"});
      len = __base::card::card_split(data, data.size(), lines);
      iend probe(lines, len);

      CHECK(probe.CONT == 0);
   }
}

TEST_CASE("FEM IEND types output.", "[fem_iend,out]" ) {

   std::ostringstream test;

   SECTION("emtpy") {
      iend probe;
      test << probe;
      CHECK(test.str() == "");
   }
   SECTION("simple") {
      iend probe(3);
      test << probe;
      CHECK(test.str() ==
            "IEND    +3.000000000e+00            0.00            0.00            0.00\n");
   }
}

TEST_CASE("FEM IEND conversion from own output.", "[fem_iend,in/out]") {

   vector<std::string> lines;
   size_t len;

   SECTION("IEND (1)") {
      vector<std::string> data({
            "IEND    +3.000000000e+00            0.00            0.00            0.00\n"});
      len = __base::card::card_split(data, data.size(), lines);
      iend probe(lines, len);

      CHECK(probe.CONT == 3);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
