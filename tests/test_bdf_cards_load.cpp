/**
   \file tests/test_bdf_cards_load.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `LOAD` class.

   Detailed description
   */

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_bdf_cards_load[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"

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

CATCH_TRANSLATE_EXCEPTION(errors::error& ex) {
    return ex.what();
}

CATCH_TRANSLATE_EXCEPTION(std::string& ex) {
    return ex;
}

TEST_CASE("BDF LOAD definitions. (Small Field Format)", "[bdf_load]") {

    std::list<std::string> data({
        // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
        "LOAD    101     -0.5    1.0     3       6.2     4                         \n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    load probe(lines);

    SECTION("first moment") {
        CHECK((long)probe.SID == 101);
        CHECK((double)probe.S == -.5);
        CHECK(probe.Si == std::list<double>({1., 6.2}));
        CHECK(probe.Li == std::list<long>({3, 4}));
    }
}

TEST_CASE("BDF LOAD types output.", "[bdf_load,out]") {

    std::ostringstream test;

    long SID(2);
    double S(2.9);

    SECTION("write (empty)") {
        load probe;
        test << probe;
        CHECK(test.str() == "");
    }

    SECTION("write (1)") {
        std::list<double> Si({3., 1.7});
        std::list<long> Li({3, 4});
        load probe(&SID, &S, &Si, &Li);
        test << probe;
        CHECK(test.str() ==
              "LOAD           22.900+003.000+00       31.700+00       4\n");
    }

    SECTION("write (2)") {
        std::list<double> Si({3.});
        std::list<long> Li({3, 0});
        Li.resize(1);
        load probe(&SID, &S, &Si, &Li);
        test << probe;
        CHECK(test.str() ==
              "LOAD           22.900+003.000+00       3\n");
    }

    SECTION("write (3)") {
        std::list<double> Si({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        std::list<long> Li({4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
        load probe(&SID, &S, &Si, &Li);
        test << probe;
        CHECK(test.str() ==
              "LOAD           22.900+00 0.00+00       41.000+00       52.000+00       6\n"
              "        3.000+00       74.000+00       85.000+00       96.000+00      10\n"
              "        7.000+00      118.000+00      129.000+00      13\n");
    }

    SECTION("write (multiple)") {
        std::list<double> Si({3.});
        std::list<long> Li({3, 0});
        Li.resize(1);
        load probe;
        test << probe;
        test << probe(&SID, &S, &Si, &Li);
        SID++;
        test << probe(&SID, &S, &Si, &Li);
        test << probe;
        CHECK(test.str() ==
              "LOAD           22.900+003.000+00       3\n"
              "LOAD           32.900+003.000+00       3\n"
              "LOAD           32.900+003.000+00       3\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
