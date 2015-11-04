// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF CTRIA3 cards classes.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>


#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif

#include "bdf/cards.h"
#include "bdf/errors.h"

using namespace ::std;
using namespace ::dnvgl::extfem::bdf;
using namespace ::dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
  return Catch::toString( ex() );
}

TEST_CASE("BDF CTRIA3 definitions. (Small Field Format)",
          "[bdf_ctria3]" ) {

  ::std::deque<string> data;
  //              1234567|1234567|1234567|1234567|1234567|1234567|
  data.push_back("CTRIA3  1       1       16      200     141\n");
  ::std::deque<string> lines = card::card_split(data);
  ctria3 probe(lines);

  SECTION("first ctria3") {
    CHECK(*probe.EID == 1);
    CHECK(*probe.PID == 1);
    CHECK(*probe.G1 == 16);
    CHECK(*probe.G2 == 200);
    CHECK(*probe.G3 == 141);
    CHECK(probe.choose_mcid_theta == ctria3::has_THETA);
    CHECK_FALSE(probe.MCID);
    CHECK(*probe.THETA == 0.0);
  }
}


TEST_CASE("BDF CTRIA3 definitions. (Large Field Format)",
          "[bdf_ctria3]" ) {

  ::std::deque<string> data;
  //              1234567|123456781234567|123456781234567|123456781234567|123456781234567|
  data.push_back("CTRIA3* 2               1               16              200             *\n");
  data.push_back("*       141\n");
  ::std::deque<string> lines = card::card_split(data);
  ctria3 probe(lines);

  SECTION("first ctria3") {
    CHECK(*probe.EID == 2);
    CHECK(*probe.PID == 1);
    CHECK(*probe.G1 == 16);
    CHECK(*probe.G2 == 200);
    CHECK(*probe.G3 == 141);
    CHECK_FALSE(probe.MCID);
    CHECK(*probe.THETA == 0.0);
  }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
