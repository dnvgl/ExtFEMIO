// Copyright © 2015 by DNV GL SE

// Task      Testing the FEM cards classes.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id: test_fem_cards.cpp 155 2015-11-04 14:46:34Z berhol $";
}

#define NOMINMAX // To avoid problems with "numdric_limits"

#include <limits>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include <iostream>
#include <deque>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif

#include "fem/cards.h"
#include "fem/file.h"
#include "fem/errors.h"

using namespace ::std;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;
using namespace ::dnvgl::extfem::fem::input;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
  return Catch::toString( ex() );
}


TEST_CASE("FEM_Dispatch", "[cards]") {

  ::std::string s(
    //  45678|234567890123456|234567890123456|234567890123456|234567890123456
    //       SLEVEL          SELTYP          SELMOD
    "IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000\n"
    "TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001\n"
    "        CONVERSION DETAILS:\n"
    "        Msc Nastran File Format -> Sesam Interface File.\n"
    "        Input  : \test_01.bdf\n"
    "        Log    : \test_01.txt\n"
    "DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001\n"
    "        DATE TIME:  11/03/2015 09:46:08\n"
    "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013\n"
    "        COMPUTER: HAML130185\n"
    "        USER: berhol\n"
    "TDLOAD   4.00000000e+000 1.00000000e+000 1.07000000e+002 0.00000000e+000\n"
    "        SubCase\n"
    "GNODE    1.00000000e+000 1.00000000e+000 6.00000000e+000 1.23456000e+005\n"
    "GCOORD   1.00000000e+000 1.11525000e+005 1.80000000e+004 2.10000000e+004\n"
    "IEND     0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n");

  istringstream ist(s);
  fem_file probe(ist);
  deque<::std::string> l;
  deque<::std::string> ref;

  std::unique_ptr<cards::card> current;

  SECTION("Processing several cards.") {
    l = probe.get();
    CAPTURE( l[0] );
    INFO( "The line is " << l[0] );
    current = cards::dispatch(card::card_split(l));
    CHECK(current->card_type() == cards::IDENT);
    // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
    // IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000
    CHECK(*static_cast<ident*>(current.get())->SLEVEL == 1);
    CHECK(*static_cast<ident*>(current.get())->SELTYP == 1);
    CHECK(*static_cast<ident*>(current.get())->SELMOD == 3);

    l = probe.get();
    CAPTURE( l[0] );
    current = cards::dispatch(card::card_split(l));
    // CHECK(current->card_type() == cards::TEXT);
    // 12345678|234567890123456|234567890123456|234567890123456|234567890123456|2
    // TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001
    //         CONVERSION DETAILS:
    //         Msc Nastran File Format -> Sesam Interface File.
    //         Input  : \test_01.bdt
    //         Log    : \test_01.txt

    l = probe.get();
    CAPTURE( l[0] );
    current = cards::dispatch(card::card_split(l));
    // CHECK(current->card_type() == cards::DATE);
    // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
    // DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001
    //         DATE TIME:  11/03/2015 09:46:08
    //         PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013
    //         COMPUTER: HAML130185
    //         USER: berhol

    l = probe.get();
    CAPTURE( l[0] );
    current = cards::dispatch(card::card_split(l));
    // CHECK(current->card_type() == cards::TDLOAD);
    // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
    // TDLOAD   4.00000000e+000 1.00000000e+000 1.07000000e+002 0.00000000e+000
    //         SubCase

    l = probe.get();
    CAPTURE( l[0] );
    current = cards::dispatch(card::card_split(l));
    // CHECK(current->card_type() == cards::GNODE);
    // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
    // GNODE    1.00000000e+000 1.00000000e+000 6.00000000e+000 1.23456000e+005

    l = probe.get();
    CAPTURE( l[0] );
    current = cards::dispatch(card::card_split(l));
    // CHECK(current->card_type() == cards::GCOORD);
    // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
    // GCOORD   1.00000000e+000 1.11525000e+005 1.80000000e+004 2.10000000e+004

    l = probe.get();
    CAPTURE( l[0] );
    current = cards::dispatch(card::card_split(l));
    // CHECK(current->card_type() == cards::IEND);
    // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
    // IEND     0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000

  }
}

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 8"
  coding: utf-8
  End:
*/
