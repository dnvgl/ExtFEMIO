/**
   \file
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

TEST_CASE("BDF GRID definitions. (default values)",
          "[bdf_grid]") {

    list<std::string> data({
        "GRID           1                                                        \n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);
    vector<int> ps_ref({});

    SECTION("first grid") {
        CHECK(long(probe.ID) == 1);
        CHECK_FALSE(bool(probe.CP));
        CHECK(double(probe.X1) == 0.);
        CHECK(double(probe.X2) == 0.);
        CHECK(double(probe.X3) == 0.);
        CHECK_FALSE(bool(probe.CD));
        CHECK(probe.PS.value == ps_ref);
        CHECK(long(probe.SEID) == 0);
    }
}

TEST_CASE("BDF GRID definitions. (default values 2)",
          "[bdf_grid]") {

    list<std::string> data({
        "GRID           1\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);
    vector<int> ps_ref({});

    SECTION("first grid") {
        CHECK(long(probe.ID) == 1);
        CHECK_FALSE(bool(probe.CP));
        CHECK(double(probe.X1) == 0.);
        CHECK(double(probe.X2) == 0.);
        CHECK(double(probe.X3) == 0.);
        CHECK_FALSE(bool(probe.CD));
        CHECK(probe.PS == ps_ref);
        CHECK(long(probe.SEID) == 0);
    }
}

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
        vector<int> ps_ref({6});
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
        vector<int> ps_ref({6});
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
        vector<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Free Field Format)",
          "[bdf_grid]") {

    list<std::string> data({
            "GRID,1,22,111525.,18000.,21000.,11,6,2\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);
    vector<int> ps_ref({6});

    SECTION("run test") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Free Field Format, continuation line)",
          "[bdf_grid]") {

    list<std::string> data({
            "GRID,1,22,111525.,\n",
            ",18000.,21000.,11,6,2\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);
    vector<int> ps_ref({6});

    SECTION("runtest") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Free Field Format, continuation line with +)",
          "[bdf_grid]") {

    list<std::string> data({
            "GRID,1,22,111525.,+",
            "+,18000.,21000.,11,6,2\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);

    SECTION("run test") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        vector<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("BDF GRID definitions. (Free Field Format, continuation line named)",
          "[bdf_grid]") {

    list<std::string> data({
            "GRID,1,22,111525.,+G001\n",
                "+G001,18000.,21000.,11,6,2\n"});

    list<std::string> lines;
    __base::card::card_split(data, lines);
    grid probe(lines);

    SECTION("run test") {
        CHECK((long)probe.ID == 1);
        CHECK((long)probe.CP == 22);
        CHECK((double)probe.X1 == 111525.);
        CHECK((double)probe.X2 == 18000.);
        CHECK((double)probe.X3 == 21000.);
        CHECK((long)probe.CD == 11);
        vector<int> ps_ref({6});
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 2);
    }
}

TEST_CASE("FEMIO-43: BDF import failed") {

    vector<int> ps_ref({});

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
        CHECK_FALSE(bool(probe.CP));
        CHECK((double)probe.X1 == -9550.);
        CHECK((double)probe.X2 == 0.);
        CHECK((double)probe.X3 == 5700.);
        CHECK((long)probe.CD == 0);
        CHECK(probe.PS == ps_ref);
        CHECK((long)probe.SEID == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test.", "[bdf_grid]") {

    ostringstream test;

    long ID{1};
    long CP{2};
    double X1{3.}, X2{4.}, X3{5.};
    long CD{-1};
    vector<int> PS{4, 5, 6};
    long SEID{1};

    grid probe(&ID, &CP, &X1, &X2, &X3, &CD, &PS, &SEID);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() == ("GRID           1       23.000+004.000+005.000+00"
                             "      -1     456       1\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l(lines);

        CHECK(probe_l.ID.value == 1);
        CHECK(probe_l.CP.value == 2);
        CHECK(probe_l.X1.value == 3.);
        CHECK(probe_l.X2.value == 4.);
        CHECK(probe_l.X3.value == 5.);
        CHECK(probe_l.CD.value == -1);
        CHECK(probe_l.PS.value == vector<int>({4, 5, 6}));
        CHECK(probe_l.SEID.value == 1);
    }
}

TEST_CASE("BDF GRID types roundtrip test (reuse).", "[bdf_grid_reuse]") {

    ostringstream test;

    long ID{1};
    long CP{2};
    double X1{3.}, X2{4.}, X3{5.};
    long CD{-1};
    vector<int> PS{4, 5, 6};
    long SEID{1};

    grid probe;
    test << probe;
    probe(&ID, &CP, &X1, &X2, &X3, &CD, &PS, &SEID);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() == ("GRID           1       23.000+004.000+005.000+00"
                             "      -1     456       1\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l;
        probe_l(lines);

        CHECK(probe_l.ID.value == 1);
        CHECK(probe_l.CP.value == 2);
        CHECK(probe_l.X1.value == 3.);
        CHECK(probe_l.X2.value == 4.);
        CHECK(probe_l.X3.value == 5.);
        CHECK(probe_l.CD.value == -1);
        CHECK(probe_l.PS.value == vector<int>({4, 5, 6}));
        CHECK(probe_l.SEID.value == 1);
    }
}

TEST_CASE("BDF GRID types roundtrip test 2.", "[bdf_grid]") {

    ostringstream test;

    long ID{2};
    long CP{3};
    double X1{1.}, X2{ -2.}, X3{3.};
    vector<int> PS{3, 1, 6};

    grid probe(&ID, &CP, &X1, &X2, &X3, nullptr, &PS, nullptr);
    test << probe;

    SECTION("check output") {
       CHECK(test.str() == ("GRID           2       31.000+00-2.00+003.000+00"
                             "             316\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l(lines);

        CHECK(probe_l.ID.value == 2);
        CHECK(probe_l.CP.value == 3);
        CHECK(probe_l.X1.value == 1.);
        CHECK(probe_l.X2.value == -2.);
        CHECK(probe_l.X3.value == 3.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({3, 1, 6}));
        CHECK(probe_l.SEID.value == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test 2 (reuse).", "[bdf_grid]") {

    ostringstream test;

    long ID{2};
    long CP{3};
    double X1{1.}, X2{ -2.}, X3{3.};
    vector<int> PS{3, 1, 6};

    grid probe;
    test << probe;
    test << probe(&ID, &CP, &X1, &X2, &X3, nullptr, &PS, nullptr);

    SECTION("check output") {
       CHECK(test.str() == ("GRID           2       31.000+00-2.00+003.000+00"
                             "             316\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l;
        probe_l(lines);

        CHECK(probe_l.ID.value == 2);
        CHECK(probe_l.CP.value == 3);
        CHECK(probe_l.X1.value == 1.);
        CHECK(probe_l.X2.value == -2.);
        CHECK(probe_l.X3.value == 3.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({3, 1, 6}));
        CHECK(probe_l.SEID.value == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test 3.", "[bdf_grid]") {

    ostringstream test;

    grid probe(1, 2, 3., 4., 5.);
    test << probe;

    SECTION("check reading") {
        CHECK(test.str() ==
              "GRID           1       23.000+004.000+005.000+00\n");
    }
    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l(lines);

        CHECK(probe_l.ID.value == 1);
        CHECK(probe_l.CP.value == 2);
        CHECK(probe_l.X1.value == 3.);
        CHECK(probe_l.X2.value == 4.);
        CHECK(probe_l.X3.value == 5.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({}));
        CHECK(probe_l.SEID.value == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test 3 (reuse).", "[bdf_grid_reuse]") {

    ostringstream test;

    grid probe;
    test << probe;
    test << probe(1, 2, 3., 4., 5.);

    SECTION("check reading") {
        CHECK(test.str() ==
              "GRID           1       23.000+004.000+005.000+00\n");
    }
    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l;
        probe_l(lines);

        CHECK(probe_l.ID.value == 1);
        CHECK(probe_l.CP.value == 2);
        CHECK(probe_l.X1.value == 3.);
        CHECK(probe_l.X2.value == 4.);
        CHECK(probe_l.X3.value == 5.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({}));
        CHECK(probe_l.SEID.value == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test 4.", "[bdf_grid]") {

    ostringstream test;

    long ID{2};
    double X1{1.}, X2{ -2.}, X3{3.};
    vector<int> PS{3, 1, 6};

    grid probe(&ID, nullptr, &X1, &X2, &X3, nullptr, &PS, nullptr);
    test << probe;

    SECTION("check reading") {
        CHECK(test.str() == ("GRID           2        1.000+00-2.00+003.000+00"
                             "             316\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l(lines);

        CHECK(probe_l.ID.value == 2);
        CHECK(probe_l.CP.value == 0);
        CHECK(probe_l.X1.value == 1.);
        CHECK(probe_l.X2.value == -2.);
        CHECK(probe_l.X3.value == 3.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({3, 1, 6}));
        CHECK(probe_l.SEID.value == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test 4 (reuse).", "[bdf_grid]") {

    ostringstream test;

    long ID{2};
    double X1{1.}, X2{ -2.}, X3{3.};
    vector<int> PS{3, 1, 6};

    grid probe;
    test << probe;
    test << probe(&ID, nullptr, &X1, &X2, &X3, nullptr, &PS, nullptr);

    SECTION("check reading") {
        CHECK(test.str() == ("GRID           2        1.000+00-2.00+003.000+00"
                             "             316\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l;
        probe_l(lines);

        CHECK(probe_l.ID.value == 2);
        CHECK(probe_l.CP.value == 0);
        CHECK(probe_l.X1.value == 1.);
        CHECK(probe_l.X2.value == -2.);
        CHECK(probe_l.X3.value == 3.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({3, 1, 6}));
        CHECK(probe_l.SEID.value == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test (minimum args).", "[bdf_grid]") {

    ostringstream test;

    long ID{2};
    double X1{1.}, X2{-2.}, X3{3.};

    grid probe(&ID, nullptr, &X1, &X2, &X3);
    test << probe;

    SECTION("check reading") {
        CHECK(test.str() == (
                  "GRID           2        1.000+00-2.00+003.000+00\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l(lines);

        CHECK(probe_l.ID.value == 2);
        CHECK(probe_l.CP.value == 0);
        CHECK(probe_l.X1.value == 1.);
        CHECK(probe_l.X2.value == -2.);
        CHECK(probe_l.X3.value == 3.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({}));
        CHECK(probe_l.SEID.value == 0);
    }
}

TEST_CASE("BDF GRID types roundtrip test (minimum args) (reuse).",
          "[bdf_grid]") {

    ostringstream test;

    long ID{2};
    double X1{1.}, X2{-2.}, X3{3.};

    grid probe;
    test << probe;
    test << probe(&ID, nullptr, &X1, &X2, &X3);

    SECTION("check reading") {
        CHECK(test.str() == (
                  "GRID           2        1.000+00-2.00+003.000+00\n"));
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        grid probe_l;
        probe_l(lines);

        CHECK(probe_l.ID.value == 2);
        CHECK(probe_l.CP.value == 0);
        CHECK(probe_l.X1.value == 1.);
        CHECK(probe_l.X2.value == -2.);
        CHECK(probe_l.X3.value == 3.);
        CHECK_FALSE(bool(probe_l.CD));
        CHECK(probe_l.PS.value == vector<int>({}));
        CHECK(probe_l.SEID.value == 0);
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
