/**
   \file tests/test_bdf_cards_ctria3.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `CTRIA3` cards classes.

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
   return Catch::toString( ex() );
}

TEST_CASE("BDF CTRIA3 definitions. (Small Field Format)",
          "[bdf_ctria3]" ) {

   std::list<std::string> data({
      // 34567|1234567|1234567|1234567|1234567|1234567|
      "CTRIA3  1       1       16      200     141\n"});
   std::list<std::string> lines;
   __base::card::card_split(data, lines);
   ctria3 probe(lines);

   SECTION("first ctria3") {
      CHECK((long)probe.EID == 1);
      CHECK((long)probe.PID == 1);
      CHECK((long)probe.G1 == 16);
      CHECK((long)probe.G2 == 200);
      CHECK((long)probe.G3 == 141);
      CHECK(probe.choose_mcid_theta == ctria3::CHOOSE_MCID_THETA::has_THETA);
      CHECK_FALSE(probe.MCID);
      CHECK((double)probe.THETA == 0.0);
   }
}


TEST_CASE("BDF CTRIA3 definitions. (Large Field Format)",
          "[bdf_ctria3]" ) {

   std::list<std::string> data({
      // 34567|123456781234567|123456781234567|123456781234567|123456781234567|
      "CTRIA3* 2               1               16              200             *\n",
      "*       141\n"});
   std::list<std::string> lines;
   __base::card::card_split(data, lines);
   ctria3 probe(lines);

   SECTION("first ctria3") {
      CHECK((long)probe.EID == 2);
      CHECK((long)probe.PID == 1);
      CHECK((long)probe.G1 == 16);
      CHECK((long)probe.G2 == 200);
      CHECK((long)probe.G3 == 141);
      CHECK_FALSE(probe.MCID);
      CHECK((double)probe.THETA == 0.0);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
