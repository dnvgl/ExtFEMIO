/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the FEM `HIERARCH` class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_hierarch[]) =
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
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

TEST_CASE("FEM HIERARCH definitions. (Small Field Format)", "[fem_hierarch]" ) {
    vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "HIERARCH  9.00000000E+00  1.00000000E+00  2.00000000E+00  1.00000000E+00\n",
            "          2.00000000E+00  0.00000000E+00  0.00000000E+00  1.00000000E+00\n",
            "          2.00000000E+00  0.00000000E+00  0.00000000E+00  0.00000000E+00\n"});
    vector<std::string> lines;
    size_t len = __base::card::card_split(data, data.size(), lines);
    hierarch probe(lines, len);

    SECTION("first moment") {

        CHECK(probe.NFIELD == 9);
        CHECK(probe.IHREF == 1);
        CHECK(probe.ISELTY == 2);
        CHECK(probe.INDSEL == 1);
        CHECK(probe.ISLEVL == 2);
        CHECK(probe.ITREF == 0);
        CHECK(probe.IHPREF == 0);
        CHECK(probe.NSUB == 1);
        CHECK(probe.IHSREFi.size() == 1);
        CHECK(probe.IHSREFi[0] == 2);
    }
}

TEST_CASE("FEM HIERARCH types output.", "[fem_hierarch,out]" ) {
    std::ostringstream test;

    long NFIELD(1);
    long IHREF(2);
    long ISELTY(3);
    long INDSEL(4);
    long ISLEVL(5);
    long ITREF(6);
    long IHPREF(7);
    long NSUB(8);
    std::vector<long> IHSREFi({9, 10, 11, 12, 13, 14, 15, 16});

    std::string ref(
        "HIERARCH+1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
        "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n"
        "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
        "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n");

    SECTION("write (empty)") {
        hierarch probe;

        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("write (1)") {
        hierarch probe(NFIELD, IHREF, ISELTY, INDSEL, ISLEVL, ITREF,
                       IHPREF, NSUB, IHSREFi);

        test << probe;
        CHECK(test.str() == ref);
    }

    SECTION("write (1a)") {
        CHECK_THROWS(
            hierarch(NFIELD, IHREF, ISELTY, INDSEL, ISLEVL, ITREF,
                     IHPREF, NSUB+1, IHSREFi));
    }

    SECTION("write (2)") {
        hierarch probe(NFIELD, IHREF, ISELTY, INDSEL, ISLEVL, ITREF,
                       IHPREF, IHSREFi);

        test << probe;
        CHECK(test.str() == ref);
    }

    SECTION("write (3)") {
        hierarch probe(NFIELD, IHREF, ISELTY, INDSEL, ISLEVL, ITREF,
                       IHPREF, std::vector<long>({9, 10, 11, 12, 13, 14}));

        test << probe;
        CHECK(test.str() ==
                "HIERARCH+1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n"
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+6.000000000e+00\n"
                "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n"
                "        +1.300000000e+01+1.400000000e+01\n");
    }
}

TEST_CASE("FEM HIERARCH conversion from own output.", "[fem_hierarch,in/out]") {

    vector<std::string> lines;
    size_t len;

    SECTION("HIERARCH") {
        vector<std::string> data({
                "HIERARCH+1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+8.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n",
                "        +1.300000000e+01+1.400000000e+01+1.500000000e+01+1.600000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        hierarch probe(lines, len);

        CHECK(probe.NFIELD == 1);
        CHECK(probe.IHREF == 2);
        CHECK(probe.ISELTY == 3);
        CHECK(probe.INDSEL == 4);
        CHECK(probe.ISLEVL == 5);
        CHECK(probe.ITREF == 6);
        CHECK(probe.IHPREF == 7);
        CHECK(probe.NSUB == 8);
        CHECK(probe.IHSREFi == std::vector<long>({9, 10, 11, 12, 13, 14, 15, 16}));
    }

    SECTION("HIERARCH (2)") {
        vector<std::string> data({
                "HIERARCH+1.000000000e+00+2.000000000e+00+3.000000000e+00+4.000000000e+00\n",
                "        +5.000000000e+00+6.000000000e+00+7.000000000e+00+6.000000000e+00\n",
                "        +9.000000000e+00+1.000000000e+01+1.100000000e+01+1.200000000e+01\n",
                "        +1.300000000e+01+1.400000000e+01\n"});
        len = __base::card::card_split(data, data.size(), lines);
        hierarch probe(lines, len);

        CHECK(probe.NFIELD == 1);
        CHECK(probe.IHREF == 2);
        CHECK(probe.ISELTY == 3);
        CHECK(probe.INDSEL == 4);
        CHECK(probe.ISLEVL == 5);
        CHECK(probe.ITREF == 6);
        CHECK(probe.IHPREF == 7);
        CHECK(probe.NSUB == 6);
        CHECK(probe.IHSREFi == std::vector<long>({9, 10, 11, 12, 13, 14}));
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
