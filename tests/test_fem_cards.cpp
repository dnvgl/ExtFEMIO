/**
   \file tests/test_fem_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the FEM cards classes.

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


TEST_CASE("FEM_Dispatch", "[cards, ident]") {

   ::std::string s(
      //  45678|234567890123456|234567890123456|234567890123456|234567890123456
      //       SLEVEL          SELTYP          SELMOD
      "IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000\n"
      "TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001\n"
      "        CONVERSION DETAILS:\n"
      "        Msc Nastran File Format -> Sesam Interface File.\n"
      "        Input  : \\test_01.fem\n"
      "        Log    : \\test_01.txt\n"
      "DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001\n"
      "        DATE TIME:  11/03/2015 09:46:08\n"
      "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013\n"
      "        COMPUTER: HAML130185\n"
      "        USER: berhol\n"
      "TDLOAD   4.00000000e+000 1.00000000e+000 1.07000000e+002 0.00000000e+000\n"
      "        SubCase\n"
      "GNODE    1.00000000e+000 1.00000000e+000 6.00000000e+000 1.23456000e+005\n"
      "GCOORD   1.00000000e+000 1.11525000e+005 1.80000000e+004 2.10000000e+004\n"
      "GELMNT1  3.39000000e+002 8.54000000e+002 2.40000000e+001 0.00000000e+000\n"
      "         6.08000000e+002 6.18000000e+002 5.71000000e+002 5.65000000e+002\n"
      "GELREF1  4.64000000e+002 3.00000000e+000 0.00000000e+000 0.00000000e+000\n"
      "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
      "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
      "GBARM    2.00000000e+000 2.50000000e+002 3.20000000e+001 3.20000000e+001\n"
      "         1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000\n"
      "GBEAMG   1.68500000e+003 0.00000000e+000 1.11500000e+004 1.00000000e-008\n"
      "         5.93000000e+008 1.57380000e+007 0.00000000e+000 1.00000000e-008\n"
      "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n"
      "         1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008\n"
      "GECCEN   1.37200000e+003 0.00000000e+000-2.48199365e+002-9.05288207e+000\n"
      "GELTH    6.54394000e+005 1.00000000e-001 0.00000000e+000 0.00000000e+000\n"
      "GIORH    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n"
      "         1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000\n"
      "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"
      "IEND     0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n");

   istringstream ist(s);
   fem_file probe(ist);
   deque<::std::string> l;
   deque<::std::string> ref;

   ::std::unique_ptr<cards::card> current;

   SECTION("Checking dispatch [ident].") {
      probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::IDENT);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // IDENT    1.00000000e+000 1.00000000e+000 3.00000000e+000 0.00000000e+000
      CHECK(static_cast<ident*>(current.get())->SLEVEL == 1);
      CHECK(static_cast<ident*>(current.get())->SELTYP == 1);
      CHECK(static_cast<ident*>(current.get())->SELMOD == 3);
   }

   SECTION("Checking dispatch [text].") {
      for (int i = 0; i < 2; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::TEXT);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456|2
      // TEXT     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001
      //         CONVERSION DETAILS:
      //         Msc Nastran File Format -> Sesam Interface File.
      //         Input  : \test_01.bdt
      //         Log    : \test_01.txt
      CHECK(static_cast<text*>(current.get())->TYPE == 0);
      CHECK(static_cast<text*>(current.get())->SUBTYPE == 0);
      CHECK(static_cast<text*>(current.get())->NRECS == 4);
      CHECK(static_cast<text*>(current.get())->NBYTE == 72);
      CHECK(static_cast<text*>(current.get())->CONT.size() == 4);
      CHECK(static_cast<text*>(current.get())->CONT[0] ==
            //        1         2         3         4         5         6
            //234567890123456789012345678901234567890123456789012345678901234
            "CONVERSION DETAILS:                                             ");
      CHECK(static_cast<text*>(current.get())->CONT[1] ==
            "Msc Nastran File Format -> Sesam Interface File.                ");
      CHECK(static_cast<text*>(current.get())->CONT[2] ==
            "Input  : \\test_01.fem                                           ");
      CHECK(static_cast<text*>(current.get())->CONT[3] ==
            "Log    : \\test_01.txt                                           ");
   }

   SECTION("Checking dispatch [date].") {
      for (int i = 0; i < 3; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::DATE);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001
      //         DATE TIME:  11/03/2015 09:46:08
      //         PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013
      //         COMPUTER: HAML130185
      //         USER: berhol
      CHECK(static_cast<date*>(current.get())->TYPE == 0);
      CHECK(static_cast<date*>(current.get())->SUBTYPE == 0);
      CHECK(static_cast<date*>(current.get())->NRECS == 4);
      CHECK(static_cast<date*>(current.get())->NBYTE == 72);
      CHECK(static_cast<date*>(current.get())->CONT[0] ==
            //        1         2         3         4         5         6
            //234567890123456789012345678901234567890123456789012345678901234
            "DATE TIME:  11/03/2015 09:46:08                                 ");
      CHECK(static_cast<date*>(current.get())->CONT[1] ==
            "PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013            ");
      CHECK(static_cast<date*>(current.get())->CONT[2] ==
            "COMPUTER: HAML130185                                            ");
      CHECK(static_cast<date*>(current.get())->CONT[3] ==
            "USER: berhol                                                    ");
   }

   SECTION("Checking dispatch [tdload].") {
      for (int i = 0; i < 4; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      // CHECK(current->card_type() == cards::TDLOAD);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // TDLOAD   4.00000000e+000 1.00000000e+000 1.07000000e+002 0.00000000e+000
      //         SubCase
   }

   SECTION("Checking dispatch [gnode].") {
      for (int i = 0; i < 5; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GNODE);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GNODE    1.00000000e+000 1.00000000e+000 6.00000000e+000 1.23456000e+005
      CHECK(static_cast<gnode*>(current.get())->NODEX == 1);
      CHECK(static_cast<gnode*>(current.get())->NODENO == 1);
      CHECK(static_cast<gnode*>(current.get())->NDOF == 6);
      CHECK(static_cast<gnode*>(current.get())->ODOF.size() == 6);
      CHECK(static_cast<gnode*>(current.get())->ODOF[0] == 1);
      CHECK(static_cast<gnode*>(current.get())->ODOF[1] == 2);
      CHECK(static_cast<gnode*>(current.get())->ODOF[2] == 3);
      CHECK(static_cast<gnode*>(current.get())->ODOF[3] == 4);
      CHECK(static_cast<gnode*>(current.get())->ODOF[4] == 5);
      CHECK(static_cast<gnode*>(current.get())->ODOF[5] == 6);
   }

   SECTION("Checking dispatch [gcoord].") {
      for (int i = 0; i < 6; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GCOORD);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GCOORD   1.00000000e+000 1.11525000e+005 1.80000000e+004 2.10000000e+004
      CHECK(static_cast<gcoord*>(current.get())->NODENO == 1);
      CHECK(static_cast<gcoord*>(current.get())->XCOORD == 111525.);
      CHECK(static_cast<gcoord*>(current.get())->YCOORD == 18000.);
      CHECK(static_cast<gcoord*>(current.get())->ZCOORD == 21000.);
   }

   SECTION("Checking dispatch [gelmnt1].") {
      for (int i = 0; i < 7; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GELMNT1);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GELMNT1  3.39000000e+002 8.54000000e+002 2.40000000e+001 0.00000000e+000
      //          6.08000000e+002 6.18000000e+002 5.71000000e+002 5.65000000e+002
      CHECK(static_cast<gelmnt1*>(current.get())->ELNOX == 339);
      CHECK(static_cast<gelmnt1*>(current.get())->ELNO == 854);
      CHECK(static_cast<gelmnt1*>(current.get())->ELTYP == 24);
      CHECK(static_cast<gelmnt1*>(current.get())->ELTYAD == 0);
      CHECK(static_cast<gelmnt1*>(current.get())->NODIN.size() == 4);
      CHECK(static_cast<gelmnt1*>(current.get())->NODIN[0] == 608);
      CHECK(static_cast<gelmnt1*>(current.get())->NODIN[1] == 618);
      CHECK(static_cast<gelmnt1*>(current.get())->NODIN[2] == 571);
      CHECK(static_cast<gelmnt1*>(current.get())->NODIN[3] == 565);
   }

   SECTION("Checking dispatch [gelref1].") {
      for (int i = 0; i < 8; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GELREF1);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GELREF1  4.64000000e+002 3.00000000e+000 0.00000000e+000 0.00000000e+000
      //          0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
      //          1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
      CHECK(static_cast<gelref1*>(current.get())->ELNO == 464);
      CHECK(static_cast<gelref1*>(current.get())->MATNO          == 3);
      CHECK(static_cast<gelref1*>(current.get())->ADDNO          == 0);
      CHECK(static_cast<gelref1*>(current.get())->INTNO          == 0);
      CHECK(static_cast<gelref1*>(current.get())->MINTNO         == 0);
      CHECK(static_cast<gelref1*>(current.get())->STRANO         == 0);
      CHECK(static_cast<gelref1*>(current.get())->STRENO         == 0);
      CHECK(static_cast<gelref1*>(current.get())->STREPONO       == 0);
      CHECK(static_cast<gelref1*>(current.get())->GEONO_OPT      == 1);
      CHECK(static_cast<gelref1*>(current.get())->FIXNO_OPT      == 0);
      CHECK(static_cast<gelref1*>(current.get())->ECCNO_OPT      == 0);
      CHECK(static_cast<gelref1*>(current.get())->TRANSNO_OPT    == 0);
      CHECK(static_cast<gelref1*>(current.get())->GEONO.size()   == 0);
      CHECK(static_cast<gelref1*>(current.get())->FIXNO.size()   == 0);
      CHECK(static_cast<gelref1*>(current.get())->ECCNO.size()   == 0);
      CHECK(static_cast<gelref1*>(current.get())->TRANSNO.size() == 0);
   }

   SECTION("Checking dispatch [gbarm].") {
      for (int i = 0; i < 9; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GBARM);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GBARM    2.00000000e+000 2.50000000e+002 3.20000000e+001 3.20000000e+001
      //          1.00000000e+000 1.00000000e+000 0.00000000e+000 0.00000000e+000
      CHECK(static_cast<gbarm*>(current.get())->GEONO == 2);
      CHECK(static_cast<gbarm*>(current.get())->HZ == 250.);
      CHECK(static_cast<gbarm*>(current.get())->BT == 32.);
      CHECK(static_cast<gbarm*>(current.get())->BB == 32.);
      CHECK(static_cast<gbarm*>(current.get())->SFY == 1.);
      CHECK(static_cast<gbarm*>(current.get())->SFZ == 1.);
      CHECK(static_cast<gbarm*>(current.get())->NLOBY == 0);
      CHECK(static_cast<gbarm*>(current.get())->NLOBZ == 0);
   }

   SECTION("Checking dispatch [gbeamg].") {
      for (int i = 0; i < 10; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GBEAMG);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GBEAMG   1.68500000e+003 0.00000000e+000 1.11500000e+004 1.00000000e-008
      //          5.93000000e+008 1.57380000e+007 0.00000000e+000 1.00000000e-008
      //          1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008
      //          1.00000000e-008 1.00000000e-008 1.00000000e-008 1.00000000e-008
      CHECK(static_cast<gbeamg*>(current.get())->GEONO == 1685);
      CHECK(static_cast<gbeamg*>(current.get())->AREA == 1.115e4);
      CHECK(static_cast<gbeamg*>(current.get())->IX == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->IY == 5.93e8);
      CHECK(static_cast<gbeamg*>(current.get())->IZ == 1.5738e7);
      CHECK(static_cast<gbeamg*>(current.get())->IYZ == 0.);
      CHECK(static_cast<gbeamg*>(current.get())->WXMIN == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->WYMIN == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->WZMIN == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->SHARY == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->SHARZ == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->SHCENY == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->SHCENZ == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->SY == 1e-8);
      CHECK(static_cast<gbeamg*>(current.get())->SZ == 1e-8);
   }

   SECTION("Checking dispatch [geccen].") {
      for (int i = 0; i < 11; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GECCEN);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GECCEN   1.37200000e+003 0.00000000e+000-2.48199365e+002-9.05288207e+000
      CHECK(static_cast<geccen*>(current.get())->ECCNO == 1372);
      CHECK(static_cast<geccen*>(current.get())->EX == 0.);
      CHECK(static_cast<geccen*>(current.get())->EY == -2.48199365e+002);
      CHECK(static_cast<geccen*>(current.get())->EZ == -9.05288207);
   }

   SECTION("Checking dispatch [gelth].") {
      for (int i = 0; i < 12; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GELTH);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // GELTH    6.54394000e+005 1.00000000e-001 0.00000000e+000 0.00000000e+000
      CHECK(static_cast<gelth*>(current.get())->GEONO == 654394);
      CHECK(static_cast<gelth*>(current.get())->TH == .1);
      CHECK(static_cast<gelth*>(current.get())->NINT == 0);
   }


   SECTION("Checking dispatch [giorh].") {
      for (int i = 0; i < 13; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::GIORH);
      // GIORH    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002
      //          1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000
      //          1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
      CHECK(static_cast<giorh*>(current.get())->GEONO == 5);
      // CHECK(static_cast<giorh*>(current.get())-> == );
   }

   SECTION("Checking dispatch [iend].") {
      for (int i = 0; i < 14; i++) probe.get(l);
      ::std::string msg;
      for (auto p : l) msg += p + "\n";
      CAPTURE(msg);
      cards::dispatch(card::card_split(l), current);
      CHECK(current->card_type() == cards::IEND);
      // 12345678|234567890123456|234567890123456|234567890123456|234567890123456
      // IEND     0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000
      CHECK(static_cast<iend*>(current.get())->CONT == 0);
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
