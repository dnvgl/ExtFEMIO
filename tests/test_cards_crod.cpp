// Copyright © 2015 by DNV GL SE

// Purpose: Testing the BDF CROD card class.

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

CATCH_TRANSLATE_EXCEPTION( bdf_error& ex ) {
  return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
  return ex;
}

using namespace std;
using namespace bdf::cards;

TEST_CASE("BDF CROD definitions. (Small Field Format)", "[bdf_crod]" ) {

  ::std::deque<string> data;
  data.push_back("CROD,222,13,14,15\n");
  ::std::deque<string> lines = card::card_split(data);
  crod probe(lines);

   SECTION("first crod") {


     CHECK(*probe.EID == 222);
     CHECK(*probe.PID == 13);
     CHECK(*probe.G1 == 14);
     CHECK(*probe.G2 == 15);

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
