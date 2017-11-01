/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing input and output for Sesam FEM `DATE` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_fem_cards_date[]) =
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

TEST_CASE("FEM DATE definitions.", "[fem_date]") {

    vector<std::string> lines;

    SECTION("DATE (1)") {
        vector<std::string> data({
            // 345678|234567890123456|234567890123456|234567890123456|234567890123456
            "DATE     0.00000000e+000 0.00000000e+000 4.00000000e+000 7.20000000e+001",
            "        DATE TIME:  11/03/2015 09:46:08",
            "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013",
            "        COMPUTER: HAML130185",
            "        USER: berhol"});

        size_t len{__base::card::card_split(data, data.size(), lines)};
        date probe(lines, len);

        CHECK(probe.TYPE == 0);
        CHECK(probe.SUBTYPE == 0);
        CHECK(probe.NRECS == 4);
        CHECK(probe.NBYTE == 72);
        CHECK(probe.CONT == std::vector<std::string>({
            //        1         2         3         4         5         6         7
            // 3456789012345678901234567890123456789012345678901234567890123456789012
            "DATE TIME:  11/03/2015 09:46:08                                         ",
            "PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013                    ",
            "COMPUTER: HAML130185                                                    ",
            "USER: berhol                                                            "}));
    }
}

TEST_CASE("FEM DATE types output.", "[fem_date,out]") {

    std::ostringstream test;

    long TYPE(0), SUBTYPE(0), NRECS(4), NBYTE(72);
    std::vector<std::string> CONT({
        "DATE TIME:  11/03/2015 09:46:08",
        "PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013",
        "COMPUTER: HAML130185",
        "USER: berhol"});

    SECTION("empty") {
        date probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("simple (fixed)") {
        date probe(0, 0, 4, 72,
        {"DATE TIME:  11/03/2015 09:46:08",
        "PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013",
        "COMPUTER: HAML130185",
        "USER: berhol"});
        test << probe;
        CHECK(probe.NBYTE == 72);
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "DATE    +0.000000000e+00+0.000000000e+00+4.000000000e+00+7.200000000e+01\n"
              "        DATE TIME:  11/03/2015 09:46:08                                 \n"
              "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013            \n"
              "        COMPUTER: HAML130185                                            \n"
              "        USER: berhol                                                    \n");
    }

    SECTION("simple") {
        date probe(TYPE, SUBTYPE, NRECS, NBYTE, CONT);
        test << probe;
        CHECK(probe.NBYTE == 72);
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "DATE    +0.000000000e+00+0.000000000e+00+4.000000000e+00+7.200000000e+01\n"
              "        DATE TIME:  11/03/2015 09:46:08                                 \n"
              "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013            \n"
              "        COMPUTER: HAML130185                                            \n"
              "        USER: berhol                                                    \n");
    }

    SECTION("simple (auto dims)") {
        date probe(TYPE, SUBTYPE, CONT);
        test << probe;
        CHECK(probe.NBYTE == 60);
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "DATE    +0.000000000e+00+0.000000000e+00+4.000000000e+00+6.000000000e+01\n"
              "        DATE TIME:  11/03/2015 09:46:08                     \n"
              "        PROGRAM: Sesam Converters  VERSION: 2.0.5  Year 2013\n"
              "        COMPUTER: HAML130185                                \n"
              "        USER: berhol                                        \n");
    }
}

TEST_CASE("FEMio-7: Problems with test output.", "[fem_date,out]") {

    SECTION("Data set from issue.") {
        std::ostringstream test;
        std::vector<std::string> CONT({
            std::string("PROGRAM: GL_ShipLoad"),
            std::string("VERSION : 2.2.?")});
        date probe(1, 0, CONT);
        test << probe;
        CHECK(probe.NBYTE == 28);
        CHECK(test.str() ==
              //        1         2         3         4         5         6         7
              // 3456789012345678901234567890123456789012345678901234567890123456789012
              "DATE    +1.000000000e+00+0.000000000e+00+2.000000000e+00+2.800000000e+01\n"
              "        PROGRAM: GL_ShipLoad\n"
              "        VERSION : 2.2.?     \n");
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
