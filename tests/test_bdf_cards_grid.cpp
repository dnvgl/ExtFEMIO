/**
   \file tests/test_bdf_cards_grid.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `GRID` cards classes.

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

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF GRID definitions. (Small Field Format)",
          "[bdf_grid]") {

    std::list<std::string> data({
        "GRID           1      22111525. 18000.  21000.        11       6       2\n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);

    SECTION("first grid") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        std::list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Large Field Format)",
          "[bdf_grid]") {

    std::list<std::string> data({
        "GRID*                  1              22         111525.          18000.\n",
        "                  21000.              11               6               2\n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);

    SECTION("first grid") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        std::list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Free Field Format)",
          "[bdf_grid]") {

    SECTION("first grid") {
        std::list<std::string> data({
            "GRID,1,22,111525.,18000.,21000.,11,6,2\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        std::list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }

    SECTION("first grid (cont)") {
        std::list<std::string> data({
            "GRID,1,22,111525.,\n",
            ",18000.,21000.,11,6,2\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        std::list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }

    SECTION("first grid (cont+)") {
        std::list<std::string> data({
            "GRID,1,22,111525.,+",
            "+,18000.,21000.,11,6,2\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        std::list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }

    SECTION("first grid (cont named +)") {
        std::list<std::string> data({
            "GRID,1,22,111525.,+G001\n",
            "+G001,18000.,21000.,11,6,2\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        std::list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("FEMIO-43: BDF import failed") {

    SECTION("report") {
        std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "GRID    1       0       -9550.  0.      5700.   0\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 0);
        CHECK((double)probe.X1 == -9550.);
        CHECK((double)probe.X2 == 0.);
        CHECK((double)probe.X3 == 5700.);
        CHECK((long)probe.CD == 0);
        std::list<int> ps_ref({});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 0);
    }

    SECTION("default CP") {
        std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "GRID    1               -9550.  0.      5700.   0\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK_FALSE(probe.CP);
        CHECK((double)probe.X1 == -9550.);
        CHECK((double)probe.X2 == 0.);
        CHECK((double)probe.X3 == 5700.);
        CHECK((long)probe.CD == 0);
        std::list<int> ps_ref({});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 0);
    }
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// coding: utf-8
// End:
