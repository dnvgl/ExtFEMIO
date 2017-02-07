/**
   \file tests/test_fem_cards_glsec.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GLSEC` cards.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
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

CATCH_TRANSLATE_EXCEPTION(exception &ex) {
    return ex.what();
}

CATCH_TRANSLATE_EXCEPTION(std::string const &ex) {
    return ex;
}

TEST_CASE("FEM GLSEC definitions.", "[fem_glsec]" ) {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GLSEC (1)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GLSEC    2.20000000e+001 7.00000000e+002 1.20000000e+001 1.50000000e+002\n",
                    "         1.20000000e+001 1.00000000e+000 1.00000000e+000 1.00000000e+000\n",
                    "         0.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        len = __base::card::card_split(data, data.size(), lines);
        glsec probe(lines, len);

        CHECK(probe.GEONO == 22);
        CHECK(probe.HZ == 700.);
        CHECK(probe.TY == 12);
        CHECK(probe.BY == 150);
        CHECK(probe.TZ == 12.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GLSEC (2)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GLSEC    2.200000000e+01 7.00000000e+02  1.200000000e+01 1.50000000e+02 \n",
                    "         1.200000000e+01 1.000000000e+00 1.000000000e+00 1.000000000e+00\n",
                    "         0.000000000e+00 0.000000000e+00 0.000000000e+00 0.000000000e+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        glsec probe(lines, len);

        CHECK(probe.GEONO == 22);
        CHECK(probe.HZ == 700.);
        CHECK(probe.TY == 12);
        CHECK(probe.BY == 150);
        CHECK(probe.TZ == 12.);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GLSEC (2)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GLSEC     1.60000000E+02  1.50000006E-01  9.00000054E-03  9.00000036E-02\n",
                    "          9.00000054E-03 1.000000000e+00 1.000000000e+00 1.00000000E+00 \n"});
        len = __base::card::card_split(data, data.size(), lines);
        glsec probe(lines, len);

        CHECK(probe.GEONO == 160);
        CHECK(probe.HZ == .150000006);
        CHECK(probe.TY == .00900000054);
        CHECK(probe.BY == .0900000036);
        CHECK(probe.TZ == .00900000054);
        CHECK(probe.SFY == 1.);
        CHECK(probe.SFZ == 1.);
        CHECK(probe.K);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

TEST_CASE("FEM GLSEC types output.", "[fem_glsec,out]" ) {

    std::ostringstream test;

    __base::geoprop::reset_geono();

    SECTION("empty") {
        glsec probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple") {
        glsec probe(1, 2., 3., 4., 5., 6., 7., true, 9, 10);
        test << probe;
        CHECK(test.str() ==
              "GLSEC   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00           +1.00\n"
              "        +9.000000000e+00+1.000000000e+01\n");
    }

    SECTION("NLOB? default") {
        glsec probe(1, 2., 3., 4., 5., 6., 7., true);
        test << probe;
        CHECK(test.str() ==
              "GLSEC   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
              "        +5.000000000e+00+6.000000000e+00+7.000000000e+00           +1.00\n");
    }
}

TEST_CASE("FEM GLSEC conversion from own output.", "[fem_glsec,in/out]") {

    vector<std::string> lines;
    size_t len;
    __base::geoprop::reset_geono();

    SECTION("GLSEC (1)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GLSEC   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                    "        +5.000000000e+00+6.000000000e+00+7.000000000e+00           +1.00\n",
                    "        +9.000000000e+00+1.000000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        glsec probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4.);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K);
        CHECK(probe.NLOBY == 9);
        CHECK(probe.NLOBZ == 10);
    }

    SECTION("GLSEC (2)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GLSEC   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                    "        +5.000000000e+00+6.000000000e+00+7.000000000e+00           +1.00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        glsec probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4.);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }

    SECTION("GLSEC (2)") {
        gbeamg _EXTFEMIO_UNUSED dummy(1, 100.);
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "GLSEC   +1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                    "        +5.000000000e+00+6.000000000e+00+7.000000000e+00           +1.00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        glsec probe(lines, len);

        CHECK(probe.GEONO == 1);
        CHECK(probe.HZ == 2.);
        CHECK(probe.TY == 3.);
        CHECK(probe.BY == 4.);
        CHECK(probe.TZ == 5.);
        CHECK(probe.SFY == 6.);
        CHECK(probe.SFZ == 7.);
        CHECK(probe.K);
        CHECK(probe.NLOBY == 0);
        CHECK(probe.NLOBZ == 0);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
