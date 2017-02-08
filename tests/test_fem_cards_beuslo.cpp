 /**
   \file tests/test_fem_cards_beuslo.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `BEUSLO` class.

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
#include "fem/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM BEUSLO definitions. (Small Field Format)", "[fem_beuslo]" ) {

    size_t len;

    SECTION("first") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BEUSLO   1.000000000e+00 1.000000000e+00 0.000000000e+00 0.00000000E+00 \n",
                    "         1.000000000e+00 4.000000000e+00 0.000000000e+00 2.00000000E+00 \n",
                    "         1.66046816E+04  3.86669189E+03  3.86368091E+03  1.62054932E+04 \n"});
        vector<std::string> lines;
        len = __base::card::card_split(data, data.size(), lines);
        beuslo probe(lines, len);

        REQUIRE(probe.LLC == 1);
        REQUIRE(probe.LOTYP == 1);
        REQUIRE(probe.COMPLX == false);
        REQUIRE(probe.LAYER == 0);
        REQUIRE(probe.ELNO == 1);
        REQUIRE(probe.NDOF == 4);
        REQUIRE(probe.INTNO == 0);
        REQUIRE(probe.SIDE == 2);
        REQUIRE(probe.RLOADi == std::vector<double>({
                    1.66046816e+4, 3.86669189e+3, 3.86368091e+3, 1.62054932e+4}));
        REQUIRE(probe.ILOADi == std::vector<double>({}));
    }
}

TEST_CASE("FEM BEUSLO types output.", "[fem_beuslo,out]" ) {
    std::ostringstream test;

    long LLC(1);
    long LOTYP(2);
    bool COMPLX(false);
    long LAYER(3);
    long ELNO(4);
    long NDOF(5);
    long INTNO(6);
    long SIDE(2);
    std::vector<double> RLOADi({7., 8., 9., 10., 11.});
    std::vector<double> ILOADi({12., 13., 14., 15., 16.});

    std::string ref_r(
        "BEUSLO  +1.000000000e+00+2.000000000e+00           +0.00+3.000000000e+00\n"
        "        +4.000000000e+00+5.000000000e+00+6.000000000e+00+2.000000000e+00\n"
        "        +7.000000000e+00+8.000000000e+00+9.000000000e+00+1.000000000e+01\n"
        "        +1.100000000e+01\n");
    std::string ref_c(
        "BEUSLO  +1.000000000e+00+2.000000000e+00           +1.00+3.000000000e+00\n"
        "        +4.000000000e+00+5.000000000e+00+6.000000000e+00+2.000000000e+00\n"
        "        +7.000000000e+00+8.000000000e+00+9.000000000e+00+1.000000000e+01\n"
        "        +1.100000000e+01+1.200000000e+01+1.300000000e+01+1.400000000e+01\n"
        "        +1.500000000e+01+1.600000000e+01\n");

    SECTION("write (empty)") {
        beuslo probe;

        test << probe;
        REQUIRE(test.str() == "");
    }

    SECTION("write (fixed, verbose)") {
        beuslo probe(1,  2, false, 3, 4, 5, 6, 2, {7., 8., 9., 10., 11.});

        test << probe;
        REQUIRE(test.str() == ref_r);
    }

    SECTION("write (real, verbose)") {
        beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi);

        test << probe;
        REQUIRE(test.str() == ref_r);
    }

    SECTION("write (real, verbose, fail 1)") {
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                         SIDE, RLOADi));
    }

    SECTION("write (real, verbose, fail 2)") {
        COMPLX = true;
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi));
    }

    SECTION("write (real, impl. COMPLX)") {
        beuslo probe(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi);
        test << probe;
        REQUIRE(test.str() == ref_r);
    }

    SECTION("write (real, impl. COMPLX, fail)") {
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, NDOF+1, INTNO,
                   SIDE, RLOADi));
    }

    SECTION("write (real, impl. NDOF)") {
        beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                     SIDE, RLOADi);
        test << probe;
        REQUIRE(test.str() == ref_r);
    }

    SECTION("write (real, impl. NDOF, fails)") {
        COMPLX = true;
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi));
    }

    SECTION("write (real, impl. NDOF, COMPLX)") {
        beuslo probe(LLC,  LOTYP, LAYER, ELNO, INTNO,
                     SIDE, RLOADi);
        test << probe;
        REQUIRE(test.str() == ref_r);
    }

    SECTION("write (complex, verbose)") {
        COMPLX = true;
        beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi, ILOADi);
        test << probe;
        REQUIRE(test.str() == ref_c);
    }

    SECTION("write (complex, verbose, fails 1)") {
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, verbose, fails 2)") {
        COMPLX = true;
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, verbose, fails 3)") {
        COMPLX = true;
        std::vector<double> ILOADi({12., 13., 14., 15., 16., 17.});
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, impl. COMPLX)") {
        beuslo probe(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi, ILOADi);
        test << probe;
        REQUIRE(test.str() == ref_c);
    }

    SECTION("write (complex, impl. COMPLX, fails 1)") {
        std::vector<double> RLOADi({12., 13., 14., 15., 16., 17.});
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, impl. COMPLX, fails 2)") {
        std::vector<double> ILOADi({12., 13., 14., 15., 16., 17.});
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, impl. NDOF)") {
        COMPLX = true;
        beuslo probe(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                     SIDE, RLOADi, ILOADi);

        test << probe;
        REQUIRE(test.str() == ref_c);
    }

    SECTION("write (complex, impl. NDOF, fails 1)") {
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, impl. NDOF, fails 1)") {
        COMPLX = true;
        std::vector<double> ILOADi({12., 13., 14., 15., 16., 17.});
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, impl. NDOF, COMPLX)") {
        beuslo probe(LLC,  LOTYP, LAYER, ELNO, INTNO,
                     SIDE, RLOADi, ILOADi);
        test << probe;
        REQUIRE(test.str() == ref_c);
    }

    SECTION("write (complex, impl. NDOF, COMPLX, fails)") {
        std::vector<double> ILOADi({12., 13., 14., 15., 16., 17.});
        REQUIRE_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi));
    }
}

TEST_CASE("FEM BEUSLO conversion from own output.", "[fem_beuslo,in/out]") {

    size_t len;

    SECTION("BEUSLO (own output, only r)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BEUSLO  +1.000000000e+00+2.000000000e+00           +0.00+3.000000000e+00\n",
                    "        +4.000000000e+00+5.000000000e+00+6.000000000e+00+2.000000000e+00\n",
                    "        +7.000000000e+00+8.000000000e+00+9.000000000e+00+1.000000000e+01\n",
                    "        +1.100000000e+01\n"});
        vector<std::string> lines;
        len = __base::card::card_split(data, data.size(), lines);
        beuslo probe(lines, len);

        REQUIRE(probe.LLC == 1);
        REQUIRE(probe.LOTYP == 2);
        REQUIRE_FALSE(probe.COMPLX);
        REQUIRE(probe.LAYER == 3);
        REQUIRE(probe.ELNO == 4);
        REQUIRE(probe.NDOF == 5);
        REQUIRE(probe.INTNO == 6);
        REQUIRE(probe.SIDE == 2);
        REQUIRE(probe.RLOADi.size() == 5);
        REQUIRE(probe.RLOADi == std::vector<double>({7., 8., 9., 10., 11.}));
        REQUIRE(probe.ILOADi.size() == 0);
    }

    SECTION("BEUSLO (own output, r + i)") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BEUSLO  +1.000000000e+00+2.000000000e+00           +1.00+3.000000000e+00\n",
                    "        +4.000000000e+00+5.000000000e+00+6.000000000e+00+2.000000000e+00\n",
                    "        +7.000000000e+00+8.000000000e+00+9.000000000e+00+1.000000000e+01\n",
                    "        +1.100000000e+01+1.200000000e+01+1.300000000e+01+1.400000000e+01\n",
                    "        +1.500000000e+01+1.600000000e+01\n"});
        vector<std::string> lines;
        len = __base::card::card_split(data, data.size(), lines);
        beuslo probe(lines, len);

        REQUIRE(probe.LLC == 1);
        REQUIRE(probe.LOTYP == 2);
        REQUIRE(probe.COMPLX);
        REQUIRE(probe.LAYER == 3);
        REQUIRE(probe.ELNO == 4);
        REQUIRE(probe.NDOF == 5);
        REQUIRE(probe.INTNO == 6);
        REQUIRE(probe.SIDE == 2);
        REQUIRE(probe.RLOADi.size() == 5);
        REQUIRE(probe.RLOADi == std::vector<double>({7., 8., 9., 10., 11.}));
        REQUIRE(probe.ILOADi.size() == 5);
        REQUIRE(probe.ILOADi == std::vector<double>({12., 13., 14., 15., 16.}));
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
