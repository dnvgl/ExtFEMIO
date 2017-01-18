/**
   \file tests/test_bdf_cards_prod.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PROD` card class.

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

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex.what();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("BDF PROD definitions.",
          "[bdf_PROD]") {

   SECTION("Free Field Format 1") {

      std::list<std::string> data({
         "PROD,1,2,3.,4.,5.,6.\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);

      CAPTURE( data.front() );

      prod probe(lines);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID == 2);
      CHECK((double)probe.A == 3.);
      CHECK((double)probe.J == 4.);
      CHECK((double)probe.C == 5.);
      CHECK((double)probe.NSM == 6.);
   }

   SECTION("Free Field Format 2") {

      std::list<std::string> data({
         "PROD,1,2,3.,4.,5.\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);

      CAPTURE( data.front() );

      prod probe(lines);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID == 2);
      CHECK((double)probe.A == 3.);
      CHECK((double)probe.J == 4.);
      CHECK((double)probe.C == 5.);
      CHECK_FALSE(probe.NSM);
   }

   SECTION("Free Field Format 3") {

      std::list<std::string> data({
         "PROD,1,2,3.,4.\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);

      CAPTURE( data.front() );

      prod probe(lines);

      CHECK((long)probe.PID == 1);
      CHECK((long)probe.MID == 2);
      CHECK((double)probe.A == 3.);
      CHECK((double)probe.J == 4.);
      CHECK((double)probe.C == 0.);
      CHECK_FALSE(probe.NSM);
   }

   SECTION("Small Field Format") {

      std::list<std::string> data({
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PROD          17      23    42.6   17.92  4.2356     0.5                        \n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);

      CAPTURE( data.front() );

      prod probe(lines);

      CHECK((long)probe.PID == 17);
      CHECK((long)probe.MID == 23);
      CHECK((double)probe.A == 42.6);
      CHECK((double)probe.J == 17.92);
      CHECK((double)probe.C == 4.2356);
      CHECK((double)probe.NSM == 0.5);
   }

   SECTION("Small Field Format 2") {

      std::list<std::string> data({
         // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
         "PROD    6000001 1       3000.00\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);

      CAPTURE( data.front() );

      prod probe(lines);

      CHECK((long)probe.PID == 6000001);
      CHECK((long)probe.MID == 1);
      CHECK((double)probe.A == 3000);
      CHECK_FALSE(probe.J);
      CHECK((double)probe.C == 0.);
      CHECK_FALSE(probe.NSM);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
