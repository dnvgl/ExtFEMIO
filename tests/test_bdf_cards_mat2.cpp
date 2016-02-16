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

namespace {
   std::string err_msg;

   const void _warn_res(const std::string &msg) {
      err_msg = msg;
   }
}

EXTFEMIO_API const void(*dnvgl::extfem::bdf::cards::warn_report)(const std::string&) = &_warn_res;


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

   SECTION("FFEMIO-3") {
      data.empty();
      data.push_back("MAT2*    10              7.01670932+10   "
                     "2.78474977+10   0.");
      data.push_back("*        1.35642948+11   0.              "
                     "1.26610002+10   0.");
      data.push_back("*        .000012         .000012         "
                     ".000012         0.");
      data.push_back("*        2.99999993-2    0.              "
                     "0.              0.");
      data.push_back("*");

      ::std::deque<string> lines;
      card::card_split(data, lines);
      mat2 probe(lines);

      CHECK((long)probe.MID == 10);
      CHECK((double)probe.G11 == 7.01670932e+10);
      CHECK((double)probe.G12 == 2.78474977e+10);
      CHECK((double)probe.G13 == 0.);
      CHECK((double)probe.G22 == 1.35642948e+11);
      CHECK((double)probe.G23 == 0.);
      CHECK((double)probe.G33 == 1.26610002e+10);
      CHECK((double)probe.RHO == 0.);
      CHECK((double)probe.A1 == 12.e-6);
      CHECK((double)probe.A2 == 12.e-6);
      CHECK((double)probe.A3 == 12.e-6);
      CHECK((double)probe.TREF == 0.);
      CHECK((double)probe.GE == 2.99999993e-2);
      CHECK((double)probe.ST == 0.);
      CHECK((double)probe.SC == 0.);
      CHECK((double)probe.SS == 0.);
      CHECK((long)probe.MCSID == 0);
      CHECK(err_msg ==
            "Long Field Format: Missing continuation line for record:\n"
            "--> MAT2*    10              7.01670932+10   2.78474977+10   0.\n"
            "--> *        1.35642948+11   0.              1.26610002+10   0.\n"
            "--> *        .000012         .000012         .000012         0.\n"
            "--> *        2.99999993-2    0.              0.              0.\n"
            "--> *\n");
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
