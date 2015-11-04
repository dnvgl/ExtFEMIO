// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF PROD card class.

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
  return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
  return ex;
}

TEST_CASE("BDF PROD definitions.",
          "[bdf_PROD]") {

  SECTION("Free Field Format 1") {

    ::std::deque<string> data;
    data.push_back(
      "PROD,1,2,3.,4.,5.,6.\n");
    ::std::deque<string> lines = card::card_split(data);

    CAPTURE( data[0] );

    prod probe(lines);

    CHECK(*probe.PID == 1);
    CHECK(*probe.MID == 2);
    CHECK(*probe.A == 3.);
    CHECK(*probe.J == 4.);
    CHECK(*probe.C == 5.);
    CHECK(*probe.NSM == 6.);
  }

  SECTION("Free Field Format 2") {

    ::std::deque<string> data;
    data.push_back(
      "PROD,1,2,3.,4.,5.\n");
    ::std::deque<string> lines = card::card_split(data);

    CAPTURE( data[0] );

    prod probe(lines);

    CHECK(*probe.PID == 1);
    CHECK(*probe.MID == 2);
    CHECK(*probe.A == 3.);
    CHECK(*probe.J == 4.);
    CHECK(*probe.C == 5.);
    CHECK_FALSE(probe.NSM);
  }

  SECTION("Free Field Format 3") {

    ::std::deque<string> data;
    data.push_back(
      "PROD,1,2,3.,4.\n");
    ::std::deque<string> lines = card::card_split(data);

    CAPTURE( data[0] );

    prod probe(lines);

    CHECK(*probe.PID == 1);
    CHECK(*probe.MID == 2);
    CHECK(*probe.A == 3.);
    CHECK(*probe.J == 4.);
    CHECK(*probe.C == 0.);
    CHECK_FALSE(probe.NSM);
  }

  SECTION("Small Field Format") {

    ::std::deque<string> data;
    data.push_back(
//     1234567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
      "PROD          17      23    42.6   17.92  4.2356     0.5                        \n");
    ::std::deque<string> lines = card::card_split(data);

    CAPTURE( data[0] );

    prod probe(lines);

    CHECK(*probe.PID == 17);
    CHECK(*probe.MID == 23);
    CHECK(*probe.A == 42.6);
    CHECK(*probe.J == 17.92);
    CHECK(*probe.C == 4.2356);
    CHECK(*probe.NSM == 0.5);
  }

  SECTION("Small Field Format 2") {

    ::std::deque<string> data;
    data.push_back(
//     1234567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
      "PROD    6000001 1       3000.00\n");
    ::std::deque<string> lines = card::card_split(data);

    CAPTURE( data[0] );

    prod probe(lines);

    CHECK(*probe.PID == 6000001);
    CHECK(*probe.MID == 1);
    CHECK(*probe.A == 3000);
    CHECK_FALSE(probe.J);
    CHECK(*probe.C == 0.);
    CHECK_FALSE(probe.NSM);
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
