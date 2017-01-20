/**
   \file tests/test_fem_cards_gusyi.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing IO for Sesam FEM `GUSYI` cards.

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

#include "fem/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return ex.what();
}

CATCH_TRANSLATE_EXCEPTION( std::string& ex ) {
   return ex;
}

TEST_CASE("FEM GUSYI definitions.", "[fem_gusyi]" ) {

   vector<std::string> lines;
   size_t len;
    __base::geoprop::reset_geono();

    SECTION("GUSYI (1)") {
        vector<std::string> data(
            {"GUSYI    5.00000000e+000 4.66000000e+002 1.45000000e+001 1.25000000e+002\n",
             "         1.60000000e+001 1.45000000e+001 1.60000000e+001 1.00000000e+000\n",
             "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n",
             "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gusyi probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BT == 125.);
        CHECK(probe.B1 == 16.);
        CHECK(probe.TT == 14.5);
        CHECK(probe.BB == 16.);
        CHECK(probe.B2 == 1);
        CHECK(probe.TB == 1.);
        CHECK(probe.SFY == 0.);
        CHECK(probe.SFZ == 0.);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 1);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GUSYI (2)") {
        vector<std::string> data(
            {"GUSYI    5.00000000e+00  4.66000000e+02  1.45000000e+01  1.25000000e+02 \n",
             "         1.60000000e+01  1.45000000e+01  1.60000000e+01  1.00000000e+00 \n",
             "         1.00000000e+00  0.00000000e+00  0.00000000e+00  0.00000000e+00 \n",
             "         1.00000000e+00  0.00000000e+00 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        gusyi probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BT == 125.);
        CHECK(probe.B1 == 16.);
        CHECK(probe.TT == 14.5);
        CHECK(probe.BB == 16.);
        CHECK(probe.B2 == 1.);
        CHECK(probe.TB == 1.);
        CHECK(probe.SFY == 0.);
        CHECK(probe.SFZ == 0.);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 1);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GUSYI (3)") {
        vector<std::string> data(
            {"GUSYI    5.00000000e+00  4.66000000e+02  1.45000000e+01  1.25000000e+02 \n",
             "         1.60000000e+01  1.45000000e+01  1.60000000e+01  1.00000000e+00 \n",
             "         1.00000000e+00  0.00000000e+00  0.00000000e+00 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        gusyi probe(lines, len);

        CHECK(probe.GEONO == 5);
        CHECK(probe.HZ == 466.);
        CHECK(probe.TY == 14.5);
        CHECK(probe.BT == 125.);
        CHECK(probe.B1 == 16.);
        CHECK(probe.TT == 14.5);
        CHECK(probe.BB == 16.);
        CHECK(probe.B2 == 1.);
        CHECK(probe.TB == 1.);
        CHECK(probe.SFY == 0.);
        CHECK(probe.SFZ == 0.);
        CHECK(probe.NLOBYT == 0);
        CHECK(probe.NLOBYB == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GUSYI conversion from own output.", "[fem_gusyi,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        gusyi probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        gusyi probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10, 11, 12, 13, 14);
        test << probe;
        CHECK(test.str() ==
              "GUSYI   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
              "        +1.300000000e+01+1.400000000e+01\n");
    }

    SECTION("simple (default N*)") {
        gusyi probe(1, 2., 3., 4., 5., 6., 7., 8., 9., 10, 11);
        test << probe;
        CHECK(test.str() ==
              "GUSYI   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
              "        +9.000000000e+00+1.000000000e+01+1.100000000e+01\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
