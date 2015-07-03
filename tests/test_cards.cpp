// Copyright © 2015 by DNV GL SE

// Task      Testing the BDF cards classes.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp fil
#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <iostream>
#include <locale>
#include <sstream>
#include <vector>

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_cards.h"
#include "bdf_file.h"

using namespace std;
using namespace bdf::cards;
using namespace bdf::input;

struct line_reader: std::ctype<char> {
  line_reader(): std::ctype<char>(get_table()) {}
  static ctype_base::mask const* get_table() {
    static vector<std::ctype_base::mask> rc(table_size, std::ctype_base::mask());

    rc['\n'] = std::ctype_base::space; // probably still want \n as a separator?
    return &rc[0];
  }
};


TEST_CASE("BDF file reader.", "[bdf_cards]" ) {

  ::std::string s(
    //  45678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
    "$Only a comment\n"
    "MAT1    1       2.305+6 80000.0 0.3     7.850-6\n"
    "MAT1    4       2.305+6 80000.0 0.3     7.850-6\n"
    "PBEAML  104010  4               L     \n"
    "           63.0   340.0    35.0    14.0\n"
    "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n");
  istringstream ist(s);
  ist.imbue(locale(locale(), new line_reader())); // Added this

  bdf_file probe(ist);
  vector<::std::string> l;
  vector<::std::string> ref;

  ref.push_back("MAT1    1       2.305+6 80000.0 0.3     7.850-6");
  l = probe.get();
  CHECK(l == ref);

  ref.clear();
  ref.push_back("MAT1    4       2.305+6 80000.0 0.3     7.850-6");
  l = probe.get();
  CHECK(l == ref);

  ref.clear();
  ref.push_back("PBEAML  104010  4               L     ");
  ref.push_back("           63.0   340.0    35.0    14.0");
  l = probe.get();
  CHECK(l == ref);

  ref.clear();
  ref.push_back("PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6");
  l = probe.get();
  CHECK(l == ref);
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "gl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 7"
// coding: utf-8
// End:
