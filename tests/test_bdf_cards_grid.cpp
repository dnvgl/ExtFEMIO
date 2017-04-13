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

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::cards;

TEST_CASE("BDF GRID definitions. (Small Field Format)",
          "[bdf_grid]") {

    list<std::string> data({
        "GRID           1      22111525. 18000.  21000.        11       6       2\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);

    SECTION("first grid") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Small Field Format) (reuse instance)",
          "[bdf_grid,in,reuse]") {

    list<std::string> data({
        "GRID           1      22111525. 18000.  21000.        11       6       2\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe;
    probe(lines);

    SECTION("first grid") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Large Field Format)",
          "[bdf_grid]") {

    list<std::string> data({
        "GRID*                  1              22         111525.          18000.\n",
        "                  21000.              11               6               2\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);

    SECTION("first grid") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Free Field Format)",
          "[bdf_grid]") {

    SECTION("first grid") {
        list<std::string> data({
            "GRID,1,22,111525.,18000.,21000.,11,6,2\n"});

        list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }

    SECTION("first grid (cont)") {
        list<std::string> data({
            "GRID,1,22,111525.,\n",
            ",18000.,21000.,11,6,2\n"});

        list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }

    SECTION("first grid (cont+)") {
        list<std::string> data({
            "GRID,1,22,111525.,+",
            "+,18000.,21000.,11,6,2\n"});

        list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }

    SECTION("first grid (cont named +)") {
        list<std::string> data({
            "GRID,1,22,111525.,+G001\n",
            "+G001,18000.,21000.,11,6,2\n"});

        list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        list<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("FEMIO-43: BDF import failed") {

    SECTION("report") {
        list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "GRID    1       0       -9550.  0.      5700.   0\n"});

        list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 0);
        CHECK((double)probe.X1 == -9550.);
        CHECK((double)probe.X2 == 0.);
        CHECK((double)probe.X3 == 5700.);
        CHECK((long)probe.CD == 0);
        list<int> ps_ref({});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 0);
    }

    SECTION("default CP") {
        list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "GRID    1               -9550.  0.      5700.   0\n"});

        list<std::string> lines;
        __base::card::card_split(data, lines);
        grid probe(lines);

        CHECK((long)probe.ID == 1);
        CHECK_FALSE(probe.CP);
        CHECK((double)probe.X1 == -9550.);
        CHECK((double)probe.X2 == 0.);
        CHECK((double)probe.X3 == 5700.);
        CHECK((long)probe.CD == 0);
        list<int> ps_ref({});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 0);
    }
}

TEST_CASE("BDF GRID types output.", "[bdf_grid,out]") {

    ostringstream test;

    SECTION("test 1") {
        long ID{1};
        long CP{2};
        double X1{3.}, X2{4.}, X3{5.};
        long CD{-1};
        list<int> PS{4, 5, 6};
        long SEID{1};

        grid probe(&ID, &CP, &X1, &X2, &X3, &CD, &PS, &SEID);

        test << probe;
        CHECK(test.str() == ("GRID           1       23.000+004.000+005.000+00"
                             "      -1     456       1\n"));
    }

    SECTION("test 2") {
        long ID{2};
        long CP{3};
        double X1{1.}, X2{ -2.}, X3{3.};
        list<int> PS{3, 1, 6};

        grid probe(&ID, &CP, &X1, &X2, &X3, nullptr, &PS, nullptr);

        test << probe;
        CHECK(test.str() == ("GRID           2       31.000+00-2.00+003.000+00"
                             "             316\n"));
    }

    SECTION("test 3") {
        grid probe(1, 2, 3., 4., 5.);

        test << probe;
        CHECK(test.str() ==
              "GRID           1       23.000+004.000+005.000+00\n");
    }

    SECTION("test 4") {
        long ID{2};
        double X1{1.}, X2{ -2.}, X3{3.};
        list<int> PS{3, 1, 6};

        grid probe(&ID, nullptr, &X1, &X2, &X3, nullptr, &PS, nullptr);

        test << probe;
        CHECK(test.str() == ("GRID           2        1.000+00-2.00+003.000+00"
                             "             316\n"));
    }
}

TEST_CASE("BDF GRID types output (reuse instance).", "[bdf_grid,out.reuse]") {

    ostringstream test;

    SECTION("test 1") {
        long ID{1};
        long CP{2};
        double X1{3.}, X2{4.}, X3{5.};
        long CD{-1};
        list<int> PS{4, 5, 6};
        long SEID{1};

        grid probe;

        test << probe;
        test << probe(&ID, &CP, &X1, &X2, &X3, &CD, &PS, &SEID);
        CHECK(test.str() == ("GRID           1       23.000+004.000+005.000+00"
                             "      -1     456       1\n"));
    }

    SECTION("test 2") {
        long ID{2};
        long CP{3};
        double X1{1.}, X2{ -2.}, X3{3.};
        list<int> PS{3, 1, 6};

        grid probe;

        test << probe(&ID, &CP, &X1, &X2, &X3, nullptr, &PS, nullptr);
        CHECK(test.str() == ("GRID           2       31.000+00-2.00+003.000+00"
                             "             316\n"));
    }

    SECTION("test 3") {
        grid probe;

        test << probe(1, 2, 3., 4., 5.);
        CHECK(test.str() ==
              "GRID           1       23.000+004.000+005.000+00\n");
    }

    SECTION("test 4") {
        long ID{2};
        double X1{1.}, X2{ -2.}, X3{3.};
        list<int> PS{3, 1, 6};

        grid probe;

        test << probe(&ID, nullptr, &X1, &X2, &X3, nullptr, &PS, nullptr);
        CHECK(test.str() == ("GRID           2        1.000+00-2.00+003.000+00"
                             "             316\n"));
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
