/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `BEUSLO` class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_beuslo[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "fem/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM BEUSLO definitions. (Small Field Format)", "[fem_beuslo]" ) {

    SECTION("first") {
        vector<std::string> data({
                // 345678|234567890123456|234567890123456|234567890123456|234567890123456
                "BEUSLO   1.000000000e+00 1.000000000e+00 0.000000000e+00 0.00000000E+00 \n",
                "         1.000000000e+00 4.000000000e+00 0.000000000e+00 2.00000000E+00 \n",
                "         1.66046816E+04  3.86669189E+03  3.86368091E+03  1.62054932E+04 \n"});
        vector<std::string> lines;
        size_t const len{__base::card::card_split(data, data.size(), lines)};
        beuslo probe(lines, len);

        CHECK(probe.LLC == 1);
        CHECK(probe.LOTYP == 1);
        CHECK(probe.COMPLX == false);
        CHECK(probe.LAYER == 0);
        CHECK(probe.ELNO == 1);
        CHECK(probe.NDOF == 4);
        CHECK(probe.INTNO == 0);
        CHECK(probe.SIDE == 2);
        CHECK(probe.RLOADi == std::vector<double>({
                    1.66046816e+4, 3.86669189e+3, 3.86368091e+3, 1.62054932e+4}));
        CHECK(probe.ILOADi == std::vector<double>({}));
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
        beuslo const probe;

        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("write (fixed, verbose)") {
        beuslo const probe(1, 2, false, 3, 4, 5, 6, 2, {7., 8., 9., 10., 11.});

        test << probe;
        CHECK(test.str() == ref_r);
    }

    SECTION("write (real, verbose)") {
        beuslo const probe(LLC, LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi);

        test << probe;
        CHECK(test.str() == ref_r);
    }

    SECTION("write (real, verbose, fail 1)") {
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                         SIDE, RLOADi));
    }

    SECTION("write (real, verbose, fail 2)") {
        COMPLX = true;
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi));
    }

    SECTION("write (real, impl. COMPLX)") {
        beuslo const probe(LLC, LOTYP, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi);
        test << probe;
        CHECK(test.str() == ref_r);
    }

    SECTION("write (real, impl. COMPLX, fail)") {
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, NDOF+1, INTNO,
                   SIDE, RLOADi));
    }

    SECTION("write (real, impl. NDOF)") {
        beuslo const probe(LLC, LOTYP, COMPLX, LAYER, ELNO, INTNO,
                     SIDE, RLOADi);
        test << probe;
        CHECK(test.str() == ref_r);
    }

    SECTION("write (real, impl. NDOF, fails)") {
        COMPLX = true;
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi));
    }

    SECTION("write (real, impl. NDOF, COMPLX)") {
        beuslo const probe(LLC, LOTYP, LAYER, ELNO, INTNO,
                     SIDE, RLOADi);
        test << probe;
        CHECK(test.str() == ref_r);
    }

    SECTION("write (complex, verbose)") {
        COMPLX = true;
        beuslo const probe(LLC, LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi, ILOADi);
        test << probe;
        CHECK(test.str() == ref_c);
    }

    SECTION("write (complex, verbose, fails 1)") {
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, verbose, fails 2)") {
        COMPLX = true;
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, verbose, fails 3)") {
        COMPLX = true;
        std::vector<double> ILOADi_l({12., 13., 14., 15., 16., 17.});
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, NDOF+1, INTNO,
                   SIDE, RLOADi, ILOADi_l));
    }

    SECTION("write (complex, impl. COMPLX)") {
        beuslo const probe(LLC, LOTYP, LAYER, ELNO, NDOF, INTNO,
                     SIDE, RLOADi, ILOADi);
        test << probe;
        CHECK(test.str() == ref_c);
    }

    SECTION("write (complex, impl. COMPLX, fails 1)") {
        std::vector<double> RLOADi_l({12., 13., 14., 15., 16., 17.});
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi_l, ILOADi));
    }

    SECTION("write (complex, impl. COMPLX, fails 2)") {
        std::vector<double> ILOADi_l({12., 13., 14., 15., 16., 17.});
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, NDOF, INTNO,
                   SIDE, RLOADi, ILOADi_l));
    }

    SECTION("write (complex, impl. NDOF)") {
        COMPLX = true;
        beuslo const probe(LLC, LOTYP, COMPLX, LAYER, ELNO, INTNO,
                     SIDE, RLOADi, ILOADi);

        test << probe;
        CHECK(test.str() == ref_c);
    }

    SECTION("write (complex, impl. NDOF, fails 1)") {
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi));
    }

    SECTION("write (complex, impl. NDOF, fails 1)") {
        COMPLX = true;
        std::vector<double> ILOADi_l({12., 13., 14., 15., 16., 17.});
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, COMPLX, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi_l));
    }

    SECTION("write (complex, impl. NDOF, COMPLX)") {
        beuslo const probe(LLC, LOTYP, LAYER, ELNO, INTNO,
                     SIDE, RLOADi, ILOADi);
        test << probe;
        CHECK(test.str() == ref_c);
    }

    SECTION("write (complex, impl. NDOF, COMPLX, fails)") {
        std::vector<double> ILOADi_l({12., 13., 14., 15., 16., 17.});
        CHECK_THROWS(
            beuslo(LLC,  LOTYP, LAYER, ELNO, INTNO,
                   SIDE, RLOADi, ILOADi_l));
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

        CHECK(probe.LLC == 1);
        CHECK(probe.LOTYP == 2);
        CHECK_FALSE(probe.COMPLX);
        CHECK(probe.LAYER == 3);
        CHECK(probe.ELNO == 4);
        CHECK(probe.NDOF == 5);
        CHECK(probe.INTNO == 6);
        CHECK(probe.SIDE == 2);
        CHECK(probe.RLOADi.size() == 5);
        CHECK(probe.RLOADi == std::vector<double>({7., 8., 9., 10., 11.}));
        CHECK(probe.ILOADi.size() == 0);
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

        CHECK(probe.LLC == 1);
        CHECK(probe.LOTYP == 2);
        CHECK(probe.COMPLX);
        CHECK(probe.LAYER == 3);
        CHECK(probe.ELNO == 4);
        CHECK(probe.NDOF == 5);
        CHECK(probe.INTNO == 6);
        CHECK(probe.SIDE == 2);
        CHECK(probe.RLOADi.size() == 5);
        CHECK(probe.RLOADi == std::vector<double>({7., 8., 9., 10., 11.}));
        CHECK(probe.ILOADi.size() == 5);
        CHECK(probe.ILOADi == std::vector<double>({12., 13., 14., 15., 16.}));
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
