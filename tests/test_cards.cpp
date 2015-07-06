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
#include <deque>

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
    static deque<std::ctype_base::mask> rc(table_size, std::ctype_base::mask());

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
  deque<::std::string> l;
  deque<::std::string> ref;

  ref.push_back("MAT1    1       2.305+6 80000.0 0.3     7.850-6");
  l = probe.get();
  CHECK(l == ref);

  ref.clear();
  ref.push_back("MAT1    4       2.305+6 80000.0 0.3     7.850-6");
  l = probe.get();
  cerr << "ref: " << ref[0] << "\n"
       << "val: " << l[0] << "\n";
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

TEST_CASE("Split Cards", "[bdf_cards]") {

  // Test data as found in the BDF documentation.

  ::std::deque<string> data;

  SECTION("Free Field Format 1") {
    data.empty();
    data.push_back(::std::string("GRID,2,1.0,-2.0,3.0,,136"));
    deque<::std::string> probe = bdf_card::card_split(data);
    deque<::std::string> ref;
    ref.push_back("GRID");
    ref.push_back("2");
    ref.push_back("1.0");
    ref.push_back("-2.0");
    ref.push_back("3.0");
    ref.push_back("");
    ref.push_back("136");
    CHECK(probe == ref);
  }

  SECTION("Free Field Format 2") {
    data.empty();
    data.push_back(::std::string("MATT9,1101,2 ,3 ,4 ,,,,8 ,+P101\n"));
    data.push_back(::std::string("+P101,9 ,,,,13\n"));
    deque<::std::string> probe = bdf_card::card_split(data);
    deque<::std::string> ref;
    ref.push_back("MATT9");
    ref.push_back("1101");
    ref.push_back("2 ");
    ref.push_back("3 ");
    ref.push_back("4 ");
    ref.push_back("");
    ref.push_back("");
    ref.push_back("");
    ref.push_back("8 ");
    ref.push_back("9 ");
    ref.push_back("");
    ref.push_back("");
    ref.push_back("");
    ref.push_back("13");
    CHECK(probe.size() == ref.size());
    CHECK(probe == ref);
  }
}

TEST_CASE("BDF_Dispatch", "[bdf_cards]") {

  ::std::string s(
    //  45678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
    "MAT1    1       2.305+6 80000.0 0.3     7.850-6\n"
    "MAT1    4       2.305+6 80000.0 0.3     7.850-6\n"
    "PBEAML  104010  4               L     \n"
    "           63.0   340.0    35.0    14.0\n"
    "PBEAM   4000001 3       1.046+4 9.369+7 1.694+6 6.856+6 1.316+6\n"
    "PROD    6000001 1       3000.00\n"
    "PSHELL  1       4         23.00 4               4\n"
    "GRID           1        111525. 18000.  21000.\n"
    "GRID          76        111522. 18002.  21002.\n"
    "GRID         153        111522. 18001.  21002.\n"
    "CQUAD4  1       1       16      200     141     17\n"
    //  45678|234567890123456|234567890123456|234567890123456|234567890123456|2
    "CQUAD4* 2               1               16              200             "
    "+\n"
    "+       140             15\n"
    "CTRIA3  2606    1       1066    1065    1133\n"
    "CBEAM   7869    104010  76      153     0.0     66.5206 997.785\n"
    "                        0.0     -22.617 -339.25 0.0     -22.617 -339.25\n"
    "CROD    11316   6000001 1028    2139\n"
    "CBEAM    465144 104010  76      153     1.       0.      0.\n"
    "$ Elements and Element Properties for region : pbeaml.59\n"
    "ENDDATA\n");

  istringstream ist(s);
  ist.imbue(locale(locale(), new line_reader())); // Added this

  bdf_file probe(ist);
  deque<::std::string> l;
  deque<::std::string> ref;

  bdf_card *current;

  l = probe.get();
  cerr << "probe: " << l[0] << "\n";
  current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  CHECK(current->card() == ::bdf::cards::UNKNOWN);

  l = probe.get();
  cerr << "probe: " << l[0] << "\n";
  current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  CHECK(current->card() == ::bdf::cards::UNKNOWN);

  l = probe.get();
  cerr << "probe: " << l[0] << "\n";
  current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  CHECK(current->card() == ::bdf::cards::UNKNOWN);

  l = probe.get();
  cerr << "probe: " << l[0] << "\n";
  current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  CHECK(current->card() == ::bdf::cards::UNKNOWN);

  l = probe.get();
  cerr << "probe: " << l[0] << "\n";
  current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  CHECK(current->card() == ::bdf::cards::UNKNOWN);

  l = probe.get();
  cerr << "probe: " << l[0] << "\n";
  current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  CHECK(current->card() == ::bdf::cards::UNKNOWN);

  l = probe.get();
  cerr << "probe: " << l[0] << "\n";
  current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  CHECK(current->card() == ::bdf::cards::GRID);

  // l = probe.get();
  // cerr << "probe: " << l[0] << "\n";
  // current = ::bdf::cards::dispatch(bdf_card::card_split(l));
  // CHECK(current->card() == ::bdf::cards::GRID);
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// c-file-style: "gl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 7"
// coding: utf-8
// End:
