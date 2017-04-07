/**
   \file test_support_grouping_csv.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing reading CSV files from NAPA BDF export.

   Detailed description
*/

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_test_support_grouping_csv[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <catch.hpp>

#include "support/grouping.h"

#include <iostream>

using namespace std;

using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

TEST_CASE("Process Grouping information from NAPA CSV.",
          "[support_grouping_csv]") {

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

TEST_CASE("processing input stream",
          "[support_grouping_csv]" ) {

    istringstream ist("Test format for Poseidon grouping information\n"
                      "1;4;BOTTOM;G1;A;  235.0\n"
                      "2601;4;SIDES;G3;A;  235.0\n"
                      "4132;3;SIDEP;G4;A;  240.0\n");
    CSV probe(ist);

    SECTION("first entry") {
        CHECK(probe[1].id == 1);
        CHECK(probe[1].nnodes == 4);
        CHECK(probe[1].napa_obj == "BOTTOM");
        CHECK(probe[1].func_name == "G1");
        CHECK(probe[1].grade == "A");
        CHECK(probe[1].yield == 235.);
        CHECK(probe.yield(1) == 235.);
    }

    SECTION("second entry") {
        CHECK(probe[2601].id == 2601);
        CHECK(probe[2601].nnodes == 4);
        CHECK(probe[2601].napa_obj == "SIDES");
        CHECK(probe[2601].func_name == "G3");
        CHECK(probe[2601].grade == "A");
        CHECK(probe[2601].yield == 235.);
        CHECK(probe.yield(2601) == 235.);
    }

    SECTION("third entry") {
        CHECK(probe[4132].id == 4132);
        CHECK(probe[4132].nnodes == 3);
        CHECK(probe[4132].napa_obj == "SIDEP");
        CHECK(probe[4132].func_name == "G4");
        CHECK(probe[4132].grade == "A");
        CHECK(probe[4132].yield == 240.);
        CHECK(probe.yield(4132) == 240.);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_support_grouping --use-colour no)"
// End:
