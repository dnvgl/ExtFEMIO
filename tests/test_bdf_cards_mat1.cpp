/**
   \file tests/test_bdf_cards_mat1.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `MAT1` cards classes.

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

#include "config.h"

#include "bdf/cards.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return Catch::toString( ex.what() );
}

TEST_CASE("BDF MAT1 definitions. (Free Field Format)",
          "[bdf_mat1]" ) {

   SECTION("first mat1") {
      std::list<std::string> data({
         "MAT1,1,2.,3.,.4,5.,6.,7.,8.,9.,10.,11.,12\n"});

      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      mat1 probe(lines);

      CHECK((long)probe.MID == 1);
      CHECK((double)probe.E == 2.);
      CHECK((double)probe.G == 3.);
      CHECK((double)probe.NU == .4);
      CHECK((double)probe.RHO == 5.);
      CHECK((double)probe.A == 6.);
      CHECK((double)probe.TREF == 7.);
      CHECK((double)probe.GE == 8.);
      CHECK((double)probe.ST == 9.);
      CHECK((double)probe.SC == 10.);
      CHECK((double)probe.SS == 11.);
      CHECK((long)probe.MCSID == 12);
   }

   SECTION("mat1 with missing entries") {
      std::list<std::string> data({
         "MAT1,1,2.070+5,80000.0,0.3,7.850-6\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      mat1 probe(lines);

      CHECK((long)probe.MID == 1);
      CHECK((double)probe.E == 2.070e5);
      CHECK((double)probe.G == 8e4);
      CHECK((double)probe.NU == .3);
      CHECK((double)probe.RHO == 7.85e-6);
      CHECK_FALSE(probe.A);
      CHECK_FALSE(probe.TREF);
      CHECK_FALSE(probe.GE);
      CHECK_FALSE(probe.ST);
      CHECK_FALSE(probe.SC);
      CHECK_FALSE(probe.SS);
      CHECK_FALSE(probe.MCSID);
   }

   SECTION("mat1 default values 1") {
      std::list<std::string> data({"MAT1,1,2.070+5\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      mat1 probe(lines);

      CHECK((long)probe.MID == 1);
      CHECK((double)probe.E == 2.070e5);
      CHECK((double)probe.G == 0.);
      CHECK((double)probe.NU == 0.);
      CHECK_FALSE(probe.RHO);
      CHECK_FALSE(probe.A);
      CHECK_FALSE(probe.TREF);
      CHECK_FALSE(probe.GE);
      CHECK_FALSE(probe.ST);
      CHECK_FALSE(probe.SC);
      CHECK_FALSE(probe.SS);
      CHECK_FALSE(probe.MCSID);
   }

   SECTION("mat1 default values 2") {
      std::list<std::string> data({"MAT1    1       2.070+5 80000.0\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      mat1 probe(lines);

      CHECK((long)probe.MID == 1);
      CHECK((double)probe.E == 2.070e5);
      CHECK((double)probe.G == 8e4);
      CHECK((double)probe.NU == Approx(0.29375));
      CHECK_FALSE(probe.RHO);
      CHECK_FALSE(probe.A);
      CHECK_FALSE(probe.TREF);
      CHECK_FALSE(probe.GE);
      CHECK_FALSE(probe.ST);
      CHECK_FALSE(probe.SC);
      CHECK_FALSE(probe.SS);
      CHECK_FALSE(probe.MCSID);
   }

   SECTION("mat1 default values 3") {
      std::list<std::string> data({"MAT1,1,2.070+5,,.3\n"});
      std::list<std::string> lines;
      __base::card::card_split(data, lines);
      mat1 probe(lines);

      CHECK((long)probe.MID == 1);
      CHECK((double)probe.E == 2.070e5);
      CHECK((double)probe.G == Approx(79615.));
      CHECK((double)probe.NU == 0.3);
      CHECK_FALSE(probe.RHO);
      CHECK_FALSE(probe.A);
      CHECK_FALSE(probe.TREF);
      CHECK_FALSE(probe.GE);
      CHECK_FALSE(probe.ST);
      CHECK_FALSE(probe.SC);
      CHECK_FALSE(probe.SS);
      CHECK_FALSE(probe.MCSID);
   }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
