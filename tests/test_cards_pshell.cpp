// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF PSHELL card class.

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
#include "bdf_cards.h"

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
  return ex;
}

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF PSHELL definitions.",
          "[bdf_PSHELL]") {

  SECTION("Small Field Format") {

    ::std::deque<string> data;
    data.push_back(
      "PSHELL  1       4         23.00 4               4\n");
    ::std::deque<string> lines = card::card_split(data);
    pshell probe(lines);

    CHECK(*probe.PID == 1);
    CHECK(*probe.MID1 == 4);
    CHECK(*probe.T == 23.);
    CHECK(*probe.MID2 == 4);
    CHECK(*probe.x12I_T__3 == 1.);
    CHECK(*probe.MID3 == 4);
  }

  SECTION("Large Field Format") {

    ::std::deque<string> data;
    data.push_back(
      "PSHELL* 1               4                 23.00         4  "
      "             \n");
    data.push_back(
      "*                       4  \n");

    ::std::deque<string> lines = card::card_split(data);
    pshell probe(lines);

    CHECK(*probe.PID == 1);
    CHECK(*probe.MID1 == 4);
    CHECK(*probe.T == 23.);
    CHECK(*probe.MID2 == 4);
    CHECK(*probe.x12I_T__3 == 1.);
    CHECK(*probe.MID3 == 4);
  }

  SECTION("Comma Field Format") {

    ::std::deque<string> data;
    data.push_back("PSHELL,1,4,23.00,4,,4\n");
    ::std::deque<string> lines = card::card_split(data);
    pshell probe(lines);

    CHECK(*probe.PID == 1);
    CHECK(*probe.MID1 == 4);
    CHECK(*probe.T == 23.);
    CHECK(*probe.MID2 == 4);
    CHECK(*probe.x12I_T__3 == 1.);
    CHECK(*probe.MID3 == 4);
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
