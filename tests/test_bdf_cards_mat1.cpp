/**
   \file tests/test_bdf_cards_mat1.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `MAT1` cards classes.

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

TEST_CASE("BDF MAT1 definitions. (Free Field Format) first",
          "[bdf_mat1]") {

    std::list<std::string> data({
            "MAT1,1,2.,3.,.4,5.,6.,7.,8.,9.,10.,11.,12\n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    mat1 probe(lines);

    SECTION("first mat1") {
        CHECK((long)probe.MID == 1);
        CHECK((double)probe.E == 2.);
        CHECK((double)probe.G == 3.);
        CHECK((double)probe.NU == .4);
        CHECK((double)probe.RHO == 5.);
        CHECK((double)probe.A == 6.);
        CHECK((double)probe.TREF == 7.);
        CHECK((double)probe.GE == 8.);
        CHECK((double)probe.ST == 9.);
        CHECK((double)probe.SC == 10.);
        CHECK((double)probe.SS == 11.);
        CHECK((long)probe.MCSID == 12);
    }
}

TEST_CASE("BDF MAT1 definitions. (Free Field Format) mat1 with missing entries",
          "[bdf_mat2]") {

    std::list<std::string> data({
            "MAT1,1,2.070+5,80000.0,0.3,7.850-6\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    mat1 probe(lines);

    SECTION("mat1 with missing entries") {
        CHECK((long)probe.MID == 1);
        CHECK((double)probe.E == 2.070e5);
        CHECK((double)probe.G == 8e4);
        CHECK((double)probe.NU == .3);
        CHECK((double)probe.RHO == 7.85e-6);
        CHECK_FALSE(probe.A);
        CHECK_FALSE(probe.TREF);
        CHECK_FALSE(probe.GE);
        CHECK_FALSE(probe.ST);
        CHECK_FALSE(probe.SC);
        CHECK_FALSE(probe.SS);
        CHECK_FALSE(probe.MCSID);
    }
}

TEST_CASE("BDF MAT1 definitions. (Free Field Format) mat1 default values 1",
          "[bdf_mat3]") {

    std::list<std::string> data({"MAT1,1,2.070+5\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    mat1 probe(lines);

    SECTION("mat1 default values 1") {
        CHECK((long)probe.MID == 1);
        CHECK((double)probe.E == 2.070e5);
        CHECK((double)probe.G == 0.);
        CHECK((double)probe.NU == 0.);
        CHECK_FALSE(probe.RHO);
        CHECK_FALSE(probe.A);
        CHECK_FALSE(probe.TREF);
        CHECK_FALSE(probe.GE);
        CHECK_FALSE(probe.ST);
        CHECK_FALSE(probe.SC);
        CHECK_FALSE(probe.SS);
        CHECK_FALSE(probe.MCSID);
    }
}

TEST_CASE("BDF MAT1 definitions.  mat1 default values 2",
          "[bdf_mat5]") {

    std::list<std::string> data({"MAT1    1       2.070+5 80000.0\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    mat1 probe(lines);

    SECTION("mat1 default values 2") {
        CHECK((long)probe.MID == 1);
        CHECK((double)probe.E == 2.070e5);
        CHECK((double)probe.G == 8e4);
        CHECK((double)probe.NU == Approx(0.29375));
        CHECK_FALSE(probe.RHO);
        CHECK_FALSE(probe.A);
        CHECK_FALSE(probe.TREF);
        CHECK_FALSE(probe.GE);
        CHECK_FALSE(probe.ST);
        CHECK_FALSE(probe.SC);
        CHECK_FALSE(probe.SS);
        CHECK_FALSE(probe.MCSID);
    }

}

TEST_CASE("BDF MAT1 definitions. mat1 default values 3",
          "[bdf_mat4]") {

    std::list<std::string> data({"MAT1,1,2.070+5,,.3\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    mat1 probe(lines);

    SECTION("mat1 default values 3") {
        CHECK((long)probe.MID == 1);
        CHECK((double)probe.E == 2.070e5);
        CHECK((double)probe.G == Approx(79615.));
        CHECK((double)probe.NU == 0.3);
        CHECK_FALSE(probe.RHO);
        CHECK_FALSE(probe.A);
        CHECK_FALSE(probe.TREF);
        CHECK_FALSE(probe.GE);
        CHECK_FALSE(probe.ST);
        CHECK_FALSE(probe.SC);
        CHECK_FALSE(probe.SS);
        CHECK_FALSE(probe.MCSID);
    }
}

TEST_CASE("BDF MAT1 definitions. (Free Field Format) first (reuse)",
          "[bdf_mat1_reuse]") {

    std::list<std::string> data({
            "MAT1,1,2.,3.,.4,5.,6.,7.,8.,9.,10.,11.,12\n"});

    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    mat1 probe;
    probe(lines);

    SECTION("first mat1") {
        CHECK((long)probe.MID == 1);
        CHECK((double)probe.E == 2.);
        CHECK((double)probe.G == 3.);
        CHECK((double)probe.NU == .4);
        CHECK((double)probe.RHO == 5.);
        CHECK((double)probe.A == 6.);
        CHECK((double)probe.TREF == 7.);
        CHECK((double)probe.GE == 8.);
        CHECK((double)probe.ST == 9.);
        CHECK((double)probe.SC == 10.);
        CHECK((double)probe.SS == 11.);
        CHECK((long)probe.MCSID == 12);
    }
}

TEST_CASE("BDF MAT1 definitions. (Free Field Format) mat1 with missing entries (reuse)",
          "[bdf_mat2_reuse]") {

    std::list<std::string> data({
            "MAT1,1,2.070+5,80000.0,0.3,7.850-6\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    mat1 probe;
    probe(lines);

    SECTION("mat1 with missing entries") {
        CHECK((long)probe.MID == 1);
        CHECK((double)probe.E == 2.070e5);
        CHECK((double)probe.G == 8e4);
        CHECK((double)probe.NU == .3);
        CHECK((double)probe.RHO == 7.85e-6);
        CHECK_FALSE(probe.A);
        CHECK_FALSE(probe.TREF);
        CHECK_FALSE(probe.GE);
        CHECK_FALSE(probe.ST);
        CHECK_FALSE(probe.SC);
        CHECK_FALSE(probe.SS);
        CHECK_FALSE(probe.MCSID);
    }
}

TEST_CASE("BDF MAT1 roundtrio test.", "[bdf_mat1_roundtrip_1_reuse]") {


    std::ostringstream test;
    long MID{1}, MCSID{2};
    double E{2.}, G{3.}, NU{.3}, RHO{5.}, A{6}, TREF{7.}, GE{8.};
    double ST{9.}, SC{10.}, SS{11.};

    mat1 probe;
    test << probe;
    test << probe(&MID, &E, &G, &NU, &RHO, &A, &TREF, &GE,
                  &ST, &SC, &SS, &MCSID);

    SECTION("check output") {
        CHECK(test.str() ==
              "MAT1           12.000+003.000+003.000-015.000+006.000+007.000+008.000+00\n"
              "        9.000+001.000+011.100+01       2\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        mat1 probe_l;
        probe_l(lines);

        CHECK(probe_l.MID.value == 1);
        CHECK(probe_l.MCSID.value == 2);
        CHECK(probe_l.E.value == 2.);
        CHECK(probe_l.G.value == 3.);
        CHECK(probe_l.NU.value == .3);
        CHECK(probe_l.RHO.value == 5.);
        CHECK(probe_l.A.value == 6);
        CHECK(probe_l.TREF.value == 7.);
        CHECK(probe_l.GE.value == 8.);
        CHECK(probe_l.ST.value == 9.);
        CHECK(probe_l.SC.value == 10.);
        CHECK(probe_l.SS.value == 11.);
    }
}

TEST_CASE("BDF MAT1 roundtrio test (min data).", "[bdf_mat1_roundtrip_2_reuse]") {

    std::ostringstream test;

    long MID{17};
    double E{3e7}, RHO{4.28}, A{6.5e-6}, GE{.23};

    mat1 probe;
    test << probe;
    test << probe(&MID, &E, nullptr, nullptr, &RHO, &A, nullptr, &GE);

    SECTION("check output") {
        CHECK(test.str() ==
              "MAT1          173.000+07                4.280+006.500-06        2.300-01\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        mat1 probe_l;
        probe_l(lines);

        CHECK(probe_l.MID.value == 17);
        CHECK_FALSE(probe_l.MCSID);
        CHECK(probe_l.E.value == 30000000.);
        CHECK(probe_l.G.value == 0.);
        CHECK(probe_l.NU.value == 0.);
        CHECK(probe_l.RHO.value == 4.28);
        CHECK(probe_l.A.value == 6.5e-6);
        CHECK_FALSE(probe_l.TREF);
        CHECK(probe_l.GE.value == .23);
        CHECK_FALSE(probe_l.ST);
        CHECK_FALSE(probe_l.SC);
        CHECK_FALSE(probe_l.SS);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
