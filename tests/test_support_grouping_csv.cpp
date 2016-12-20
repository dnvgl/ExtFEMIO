/**
   \file test_support_grouping_csv.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing reading CSV files from NAPA BDF export.

   Detailed description
*/

// ID:
namespace {
   char const cID_test_support_grouping_csv[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include <catch.hpp>

#include "support/grouping.h"
#include "support/errors.h"

using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

CATCH_TRANSLATE_EXCEPTION( errors::error& ex ) {
   return Catch::toString( ex() );
}

TEST_CASE("Process Grouping information from NAPA CSV.",
          "[support_grouping_csv]" ) {

    class testCSV : public CSV {
    public:
        using CSV::process_line;
    };

    SECTION("initial") {

        elem_info *probe = new elem_info;
        testCSV::process_line("1;4;BOTTOM;G1;A;  235.0", probe);

        CHECK(probe->id == 1);
        CHECK(probe->nnodes == 4);
        CHECK(probe->napa_obj == "BOTTOM");
        CHECK(probe->func_name == "G1");
        CHECK(probe->grade == "A");
        CHECK(probe->yield == 235.);

        delete probe;
    }

    SECTION("faulty") {

        elem_info *probe = new elem_info;
        CHECK_THROWS(
            testCSV::process_line(
                "Test format for Poseidon grouping information", probe));
        delete probe;
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
