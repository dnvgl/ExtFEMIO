/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing IO for Sesam FEM `GELMNT1` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_gelmnt1[]) =
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

TEST_CASE("FEM GELMNT1 definitions.", "[fem_gelmnt1]") {

    vector<std::string> lines;
    size_t len;

    SECTION("GELMNT1 (BEAS)") {
        vector<std::string> data({
            "GELMNT1  1.13160000e+004 1.00000000e+000 1.50000000e+001 0.00000000e+000\n",
            "         1.00000000e+001 1.10000000e+001 0.00000000e+000 0.00000000e+000\n"});


        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 11316);
        CHECK(probe.ELNO == 1);
        CHECK(probe.ELTYP == elements::el_types::BEAS);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({10, 11}));
    }

    SECTION("GELMNT1 (FQUS)") {
        vector<std::string> data({
            "GELMNT1  1.00000000e+000 6.00000000e+000 2.40000000e+001 0.00000000e+000\n",
            "         1.00000000e+000 6.00000000e+000 4.00000000e+000 2.00000000e+000\n"});

        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 1);
        CHECK(probe.ELNO == 6);
        CHECK(probe.ELTYP == elements::el_types::FQUS_FFQ);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({1, 6, 4, 2}));
    }

    SECTION("GELMNT1 (BEAS)") {
        vector<std::string> data({
            "GELMNT1   1.00000000E+00  1.00000000E+00  1.50000000E+01  0.00000000E+00\n",
            "          1.00000000E+00  2.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 1);
        CHECK(probe.ELNO == 1);
        CHECK(probe.ELTYP == elements::el_types::BEAS);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({1, 2}));
    }

    SECTION("GELMNT1 (BEAS) (empty fields)") {
        vector<std::string> data({
            "GELMNT1   1.00000000E+00  1.00000000E+00  1.50000000E+01  0.00000000E+00\n",
            "          1.00000000E+00  2.00000000E+00\n"});
        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 1);
        CHECK(probe.ELNO == 1);
        CHECK(probe.ELTYP == elements::el_types::BEAS);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({1, 2}));
    }
}

TEST_CASE("FEM GELMNT1 types output.", "[fem_gelmnt1,out]") {

    std::ostringstream test;

    SECTION("GELMNT1 OUT (empty)") {
        gelmnt1 probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("GELMNT1 OUT (FQUS, const)") {
        gelmnt1 probe(1, 6, elements::el_types::FQUS_FFQ, 0, {1, 6, 4, 2});
        test << probe;
        CHECK(test.str() ==
              "GELMNT1 +1.000000000e+00+6.000000000e+00+2.400000000e+01+0.000000000e+00\n"
              "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n");
    }

    SECTION("GELMNT1 OUT (FQUS)") {
        long ELNOX(1), ELNO(6);
        elements::el_types ELTYP(elements::el_types::FQUS_FFQ);
        long ELTYAD(0);
        std::vector<long> NODIN({1, 6, 4, 2});

        gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
        test << probe;
        CHECK(test.str() ==
              "GELMNT1 +1.000000000e+00+6.000000000e+00+2.400000000e+01+0.000000000e+00\n"
              "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n");
    }

    SECTION("GELMNT1 OUT (FTRS)") {
        long ELNOX(1), ELNO(6);
        elements::el_types ELTYP(elements::el_types::FTRS_FFTR);
        long ELTYAD(0);
        std::vector<long> NODIN({1, 6, 4});

        gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
        test << probe;
        CHECK(test.str() ==
              "GELMNT1 +1.000000000e+00+6.000000000e+00+2.500000000e+01+0.000000000e+00\n"
              "        +1.000000000e+00+6.000000000e+00+4.000000000e+00\n");
    }

    SECTION("GELMNT1 OUT (ILST)") {
        long ELNOX(12), ELNO(36);
        elements::el_types ELTYP(elements::el_types::ILST);
        long ELTYAD(0);
        std::vector<long> NODIN({1, 6, 4, 2, 13, 22});

        gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
        test << probe;
        CHECK(test.str() ==
              "GELMNT1 +1.200000000e+01+3.600000000e+01+6.000000000e+00+0.000000000e+00\n"
              "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n"
              "        +1.300000000e+01+2.200000000e+01\n");
    }

    SECTION("GELMNT1 OUT (BEAS)") {
        long ELNOX(12), ELNO(36);
        elements::el_types ELTYP(elements::el_types::BEAS);
        long ELTYAD(0);
        std::vector<long> NODIN({1, 6});

        gelmnt1 probe(ELNOX, ELNO, ELTYP, ELTYAD, NODIN);
        test << probe;
        CHECK(test.str() ==
              "GELMNT1 +1.200000000e+01+3.600000000e+01+1.500000000e+01+0.000000000e+00\n"
              "        +1.000000000e+00+6.000000000e+00\n");
    }

    SECTION("GELMNT1 OUT (BEAS) (ELTYAD default)") {
        long ELNOX(12), ELNO(36);
        elements::el_types ELTYP(elements::el_types::BEAS);
        std::vector<long> NODIN({1, 6});

        gelmnt1 probe(ELNOX, ELNO, ELTYP, NODIN);
        test << probe;
        CHECK(test.str() ==
              "GELMNT1 +1.200000000e+01+3.600000000e+01+1.500000000e+01+0.000000000e+00\n"
              "        +1.000000000e+00+6.000000000e+00\n");
    }
}

TEST_CASE("FEM GELMNT1 conversion from own output.", "[fem_gelmnt1,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("GELMNT1 (FQUS)") {
        vector<std::string> data({
            "GELMNT1 +1.000000000e+00+6.000000000e+00+2.400000000e+01+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n"});

        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 1);
        CHECK(probe.ELNO == 6);
        CHECK(probe.ELTYP == elements::el_types::FQUS_FFQ);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({1, 6, 4, 2}));
    }

    SECTION("GELMNT1 (FTRS)") {
        vector<std::string> data({
            "GELMNT1 +1.000000000e+00+6.000000000e+00+2.500000000e+01+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00\n"});

        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 1);
        CHECK(probe.ELNO == 6);
        CHECK(probe.ELTYP == elements::el_types::FTRS_FFTR);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({1, 6, 4}));
    }

    SECTION("GELMNT1 (ILST)") {
        vector<std::string> data({
            "GELMNT1 +1.200000000e+01+3.600000000e+01+6.000000000e+00+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00+4.000000000e+00+2.000000000e+00\n",
            "        +1.300000000e+01+2.200000000e+01\n"});

        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 12);
        CHECK(probe.ELNO == 36);
        CHECK(probe.ELTYP == elements::el_types::ILST);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({1, 6, 4, 2, 13, 22}));
    }

    SECTION("GELMNT1 (BEAS)") {
        vector<std::string> data({
            "GELMNT1 +1.200000000e+01+3.600000000e+01+1.500000000e+01+0.000000000e+00\n",
            "        +1.000000000e+00+6.000000000e+00\n"});

        len = __base::card::card_split(data, data.size(), lines);
        gelmnt1 probe(lines, len);

        CHECK(probe.ELNOX == 12);
        CHECK(probe.ELNO == 36);
        CHECK(probe.ELTYP == elements::el_types::BEAS);
        CHECK(probe.ELTYAD == 0);
        CHECK(probe.NODIN == std::vector<long>({1, 6}));
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//   (make -C ../cbuild test;
//    ../cbuild/tests/test_fem_cards --use-colour no)"
// End:
