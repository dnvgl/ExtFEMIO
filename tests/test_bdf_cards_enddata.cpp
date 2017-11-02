/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `ENDDATA` card class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_test_bdf_cards_enddata[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF ENDDATA definitions. (Small Field Format)",
          "[bdf_ENDDATA]") {

    SECTION("enddata read") {
        std::list<std::string> const data({
            "ENDDAT                                                                  \n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        enddata probe(lines);
    }
}

TEST_CASE("BDF ENDDATA types output.", "[bdf_enddata,out]") {

    std::ostringstream test;
    // enddata probe();
    // test << probe;
    test << enddata();

    SECTION("output") {
        CHECK(test.str() == "ENDDATA \n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
