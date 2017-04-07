/**
   \file tests/test_fem_cards_belfix.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `BELFIX` class.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM BELFIX definitions.", "[fem_belfix]" ) {

    size_t len;

    SECTION("first") {

        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BELFIX   2.30470000e+004 1.00000000e+000 0.00000000e+000 0.00000000e+000\n",
                    "         1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000\n",
                    "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        vector<std::string> lines;
        len = __base::card::card_split(data, 3, lines);
        belfix probe(lines, len);

        CHECK(probe.FIXNO == 23047);
        CHECK(probe.OPT == belfix::n_opt::FIXATION);
        CHECK(probe.TRANO == 0);
        CHECK(probe.A == std::vector<double>({1., 1., 1., 1., 1., 0.}));
    }

    SECTION("spring") {

        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BELFIX   2.30470000e+004 2.00000000e+000 0.00000000e+000 0.00000000e+000\n",
                    "         1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000\n",
                    "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        vector<std::string> lines;
        len = __base::card::card_split(data, 3, lines);
        belfix probe(lines, len);

        CHECK(probe.FIXNO == 23047);
        CHECK(probe.OPT == belfix::n_opt::SPRING);
        CHECK(probe.TRANO == 0);
        CHECK(probe.A == std::vector<double>({1., 1., 1., 1., 1., 0.}));
    }

    SECTION("fixation end") {

        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BELFIX   2.30470000e+004 3.00000000e+000 0.00000000e+000 0.00000000e+000\n",
                    "         1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000\n",
                    "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        vector<std::string> lines;
        len = __base::card::card_split(data, 3, lines);
        belfix probe(lines, len);

        CHECK(probe.FIXNO == 23047);
        CHECK(probe.OPT == belfix::n_opt::FIXATION_END);
        CHECK(probe.TRANO == 0);
        CHECK(probe.A == std::vector<double>({1., 1., 1., 1., 1., 0.}));
    }

    SECTION("spring end") {

        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BELFIX   2.30470000e+004 4.00000000e+000 0.00000000e+000 0.00000000e+000\n",
                    "         1.00000000e+000 1.00000000e+000 1.00000000e+000 1.00000000e+000\n",
                    "         1.00000000e+000 0.00000000e+000 0.00000000e+000 0.00000000e+000\n"});
        vector<std::string> lines;
        len = __base::card::card_split(data, 3, lines);
        belfix probe(lines, len);

        CHECK(probe.FIXNO == 23047);
        CHECK(probe.OPT == belfix::n_opt::SPRING_END);
        CHECK(probe.TRANO == 0);
        CHECK(probe.A == std::vector<double>({1., 1., 1., 1., 1., 0.}));
    }
}

TEST_CASE("FEM BELFIX types output.", "[fem_belfix,out]" ) {

    SECTION("write default") {
        std::ostringstream test;

        belfix probe;
        test << probe;

        CHECK(test.str() == "");
    }

    SECTION("write") {
        std::ostringstream test;

        long FIXNO(1);
        belfix::n_opt OPT(belfix::n_opt::FIXATION);
        long TRANO(1);
        std::vector<double> A({1., 0., .5, 1., 1., 1.});

        belfix probe(FIXNO, OPT, TRANO, A);
        test << probe;

        CHECK(test.str() ==
              "BELFIX  +1.000000000e+00+1.000000000e+00+1.000000000e+00            0.00\n"
              "        +1.000000000e+00+0.000000000e+00+5.000000000e-01+1.000000000e+00\n"
              "        +1.000000000e+00+1.000000000e+00\n");
    }

    SECTION("write (const)") {
        std::ostringstream test;

        belfix probe(1, belfix::n_opt::FIXATION, 1, {1., 0., .5, 1., 1., 1.});
        test << probe;

        CHECK(test.str() ==
              "BELFIX  +1.000000000e+00+1.000000000e+00+1.000000000e+00            0.00\n"
              "        +1.000000000e+00+0.000000000e+00+5.000000000e-01+1.000000000e+00\n"
              "        +1.000000000e+00+1.000000000e+00\n");
    }
}

TEST_CASE("FEM BELFIX conversion from own output.", "[fem_belfix,in/out]") {

    vector<std::string> lines;

    SECTION("BELFIX (own output)") {

        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BELFIX  +1.000000000e+00+1.000000000e+00+1.000000000e+00            0.00\n",
                    "        +1.000000000e+00+0.000000000e+00+5.000000000e-01+1.000000000e+00\n",
                    "        +1.000000000e+00+1.000000000e+00\n"});
        size_t len{__base::card::card_split(data, 3, lines)};
        belfix probe(lines, len);

        CHECK(probe.FIXNO == 1);
        CHECK(probe.OPT == belfix::n_opt::FIXATION);
        CHECK(probe.TRANO == 1);
        CHECK(probe.A == std::vector<double>({1., 0., .5, 1., 1., 1.}));
    }
}

TEST_CASE("FEM BELFIX conversion to Poseidon BEAM dofs.", "[fem_belfix,fixation]") {

    SECTION("first test") {
        belfix probe(1, belfix::n_opt::FIXATION, 1, {1., 0., 1., 0., 1., 0.});
        CHECK(probe.pos_string() == "101010");
    }

    SECTION("Invalid fixation values") {
        belfix probe(1, belfix::n_opt::FIXATION, 1, {1., 0., .5, 1., 1., 1.});
        CHECK_THROWS(probe.pos_string());
    }

    SECTION("Invalid spring values") {
        belfix probe(1, belfix::n_opt::SPRING, 1, {1., 0., 0., 1., 1., 1.});
        CHECK_THROWS(probe.pos_string());
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
