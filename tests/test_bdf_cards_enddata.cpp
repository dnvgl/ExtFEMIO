/**
   \file tests/test_bdf_cards_enddata.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `ENDDATA` card class.

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
   return Catch::toString( ex() );
}

TEST_CASE("BDF ENDDATA definitions. (Small Field Format)",
          "[bdf_ENDDATA]" ) {

   SECTION("enddata read") {
      std::list<std::string> data({
         "ENDDAT                                                                  \n"});

      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      enddata probe(lines);
   }
}

TEST_CASE("BDF ENDDATA types output.", "[bdf_enddata,out]" ) {

   std::ostringstream test;
   // enddata probe();
   // test << probe;
   test << enddata();

   SECTION("output") {
      CHECK(test.str() == "ENDDATA \n");
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. doxyfile.stamp check -j 8"
// End:
