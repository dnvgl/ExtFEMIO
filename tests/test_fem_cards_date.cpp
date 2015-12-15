/**
   \file tests/test_fem_cards_date.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `DATE` cards.

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
#include "fem/cards.h"

using namespace ::std;
using namespace ::dnvgl::extfem::fem;
using namespace ::dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex();
}

CATCH_TRANSLATE_EXCEPTION( ::std::string& ex ) {
   return ex;
}

TEST_CASE("FEM DATE definitions.", "[fem_date]" ) {
    
   ::std::deque<string> lines;
    
   SECTION("DATE (1)") {
      ::std::deque<string> data;
      //              12345678|234567890123456|234567890123456|234567890123456|234567890123456
      data.push_back("DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001");
      data.push_back("        DATE TIME:  11/03/2015 09:46:08");
      data.push_back("        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013");
      data.push_back("        COMPUTER: HAML130185");
      data.push_back("        USER: berhol");

      card::card_split(data, lines);
      date probe(lines);

      CHECK(probe.TYPE == 0);
      CHECK(probe.SUBTYPE == 0);
      CHECK(probe.NRECS == 4);
      CHECK(probe.NBYTE == 72);
      CHECK(probe.CONT[0] ==
            //        1         2         3         4         5         6
            // 34567890123456789012345678901234567890123456789012345678901234
            "DATE TIME:  11/03/2015 09:46:08                                 ");
      CHECK(probe.CONT[1] ==
            "PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013            ");
      CHECK(probe.CONT[2] ==
            "COMPUTER: HAML130185                                            ");
      CHECK(probe.CONT[3] ==
            "USER: berhol                                                    ");
   }
}

TEST_CASE("FEM DATE types output.", "[fem_date,out]" ) {

   std::ostringstream test;

   SECTION("simple") {
      long TYPE(0), SUBTYPE(0), NRECS(4), NBYTE(72);
      deque<::std::string> CONT;
      CONT.push_back("DATE TIME:  11/03/2015 09:46:08");
      CONT.push_back("PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013");
      CONT.push_back("COMPUTER: HAML130185");
      CONT.push_back("USER: berhol");
      date probe(TYPE, SUBTYPE, NRECS, NBYTE, CONT);
      test << probe;
      CHECK(test.str() ==
            //        1         2         3         4         5         6         7
            // 3456789012345678901234567890123456789012345678901234567890123456789012
            "DATE    +0.00000000e+00 +0.00000000e+00 +4.00000000e+00 +7.20000000e+01 \n"
            "        DATE TIME:  11/03/2015 09:46:08                                 \n"
            "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013            \n"
            "        COMPUTER: HAML130185                                            \n"
            "        USER: berhol                                                    \n");
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j8"
// End:
