/**
   \file tests/test_bdf_cards_mat2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the BDF `MAT2` cards classes.

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

TEST_CASE("BDF MAT2 definitions. (Free Field Format)",
          "[bdf_mat2]" ) {

   ::std::deque<string> data;

   SECTION("first mat2") {
      data.empty();
      data.push_back("MAT2,1,2.,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,"
                     "13.,14.,15.,16.,17\n");

      ::std::deque<string> lines;
      card::card_split(data, lines);
      mat2 probe(lines);

      CHECK((long)probe.MID == 1);
      CHECK((double)probe.G11 == 2.);
      CHECK((double)probe.G12 == 3.);
      CHECK((double)probe.G13 == 4.);
      CHECK((double)probe.G22 == 5.);
      CHECK((double)probe.G23 == 6.);
      CHECK((double)probe.G33 == 7.);
      CHECK((double)probe.RHO == 8.);
      CHECK((double)probe.A1 == 9.);
      CHECK((double)probe.A2 == 10.);
      CHECK((double)probe.A3 == 11.);
      CHECK((double)probe.TREF == 12.);
      CHECK((double)probe.GE == 13.);
      CHECK((double)probe.ST == 14.);
      CHECK((double)probe.SC == 15.);
      CHECK((double)probe.SS == 16.);
      CHECK((long)probe.MCSID == 17);
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
