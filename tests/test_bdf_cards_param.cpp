/**
   \file tests/test_bdf_cards_param.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Generate bulk param entries.

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
#include <complex>

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
   return Catch::toString( ex() );
}

TEST_CASE("BDF PARAM definitions. (Small Field Format)",
          "[bdf_PARAM]" ) {

   SECTION("param read int") {
      std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   IRES     1                                                      \n"});

      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      param probe(lines);
      CHECK(probe.N == "IRES");
      CHECK(probe.IVAL.value == 1);
      CHECK_FALSE(probe.RVAL);
      CHECK_FALSE(probe.CVAL);
      CHECK_FALSE(probe.CPLXVAL);
   }

   SECTION("param read real") {
      std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   ADPCON   1.                                                     \n"});

      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      param probe(lines);
      CHECK(probe.N == "ADPCON");
      CHECK_FALSE(probe.IVAL);
      CHECK(probe.RVAL.value == 1.);
      CHECK_FALSE(probe.CVAL);
      CHECK_FALSE(probe.CPLXVAL);
   }

   SECTION("param read char") {
      std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   ACOUT    PEAK                                                   \n"});

      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      param probe(lines);
      CHECK(probe.N == "ACOUT");
      CHECK_FALSE(probe.IVAL);
      CHECK_FALSE(probe.RVAL);
      CHECK(probe.CVAL.value == "PEAK");
      CHECK_FALSE(probe.CPLXVAL);
   }

   SECTION("param read complex") {
      std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   CP1      2.      3.                                             \n"});

      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      param probe(lines);
      CHECK(probe.N == "CP1");
      CHECK_FALSE(probe.IVAL);
      CHECK_FALSE(probe.RVAL);
      CHECK_FALSE(probe.CVAL);
      CHECK(probe.CPLXVAL.value == std::complex<double>(2., 3.));
   }
}

TEST_CASE("BDF PARAM types output.", "[bdf_param,out]" ) {

   std::ostringstream test;

   SECTION("output int") {
      param probe("int", (long)123);
      test << probe;
      CHECK(test.str() == "PARAM   INT          123\n");
   }

   SECTION("output char") {
      param probe("chr", "123");
      test << probe;
      CHECK(test.str() == "PARAM   CHR     123     \n");
   }

   SECTION("output double") {
      param probe("dble", 123e1);
      test << probe;
      CHECK(test.str() == "PARAM   DBLE    1.230+03\n");
   }

   SECTION("output complex 1") {
      param probe("cmplx", 1e1, 1e1);
      test << probe;
      CHECK(test.str() == "PARAM   CMPLX   1.000+011.000+01\n");
   }

   SECTION("output complex 2") {
      param probe("cmplx", std::complex<double>(1e1, 1e1));
      test << probe;
      CHECK(test.str() == "PARAM   CMPLX   1.000+011.000+01\n");
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
