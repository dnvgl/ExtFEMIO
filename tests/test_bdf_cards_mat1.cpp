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

TEST_CASE("BDF MAT1 definitions. (Free Field Format)",
          "[bdf_mat1]") {

    SECTION("first mat1") {
        std::list<std::string> data({
            "MAT1,1,2.,3.,.4,5.,6.,7.,8.,9.,10.,11.,12\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        mat1 probe(lines);

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

    SECTION("mat1 with missing entries") {
        std::list<std::string> data({
            "MAT1,1,2.070+5,80000.0,0.3,7.850-6\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        mat1 probe(lines);

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

    SECTION("mat1 default values 1") {
        std::list<std::string> data({"MAT1,1,2.070+5\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        mat1 probe(lines);

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

    SECTION("mat1 default values 2") {
        std::list<std::string> data({"MAT1    1       2.070+5 80000.0\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        mat1 probe(lines);

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

    SECTION("mat1 default values 3") {
        std::list<std::string> data({"MAT1,1,2.070+5,,.3\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        mat1 probe(lines);

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

TEST_CASE("BDF MAT1 types output.", "[bdf_mat1,out]") {

    std::ostringstream test;

    SECTION("test 1") {
        long MID{1}, MCSID{2};
        double E{2.}, G{3.}, NU{4.}, RHO{5.}, A{6}, TREF{7.}, GE{8.},
            ST{9.}, SC{10.}, SS{11.};

        mat1 probe(&MID, &E, &G, &NU, &RHO, &A, &TREF, &GE,
                   &ST, &SC, &SS, &MCSID);
        test << probe;
        CHECK(test.str() ==
              "MAT1           12.000+003.000+004.000+005.000+006.000+007.000+008.000+00\n"
              "        9.000+001.000+011.100+01       2\n");
    }

    SECTION("test 2") {
        long MID{17}, MCSID{1003};
        double E{3e7}, NU{.33}, RHO{4.28}, A{6.5e-6}, TREF{5.37e2},
               GE{.23}, ST{20e4}, SC{15e4}, SS{12e4};

        mat1 probe(&MID, &E, nullptr, &NU, &RHO, &A, &TREF, &GE,
                   &ST, &SC, &SS, &MCSID);
        test << probe;
        CHECK(test.str() ==
              "MAT1          173.000+07        3.300-014.280+006.500-065.370+022.300-01\n"
              "        2.000+051.500+051.200+05    1003\n");
    }

    SECTION("test min data") {
        long MID{17};
        double E{3e7}, RHO{4.28}, A{6.5e-6}, GE{.23};

        mat1 probe(&MID, &E, nullptr, nullptr, &RHO, &A, nullptr, &GE);
        test << probe;
        CHECK(test.str() ==
              "MAT1          173.000+07                4.280+006.500-06        2.300-01\n");
    }
}

TEST_CASE("BDF MAT1 reuse instance for output.", "[bdf_mat1,out]") {

    std::ostringstream test;

    SECTION("test reuse 1") {
        long MID{1}, MCSID{2};
        double E{2.}, G{3.}, NU{4.}, RHO{5.}, A{6}, TREF{7.}, GE{8.},
            ST{9.}, SC{10.}, SS{11.};

        mat1 probe;
        test << probe(&MID, &E, &G, &NU, &RHO, &A, &TREF, &GE,
                      &ST, &SC, &SS, &MCSID);
        CHECK(test.str() ==
              "MAT1           12.000+003.000+004.000+005.000+006.000+007.000+008.000+00\n"
              "        9.000+001.000+011.100+01       2\n");
    }

    SECTION("test reuse min data") {
        long MID{17};
        double E{3e7}, RHO{4.28}, A{6.5e-6}, GE{.23};

        mat1 probe;
        test << probe(&MID, &E, nullptr, nullptr, &RHO, &A, nullptr, &GE);
        CHECK(test.str() ==
              "MAT1          173.000+07                4.280+006.500-06        2.300-01\n");
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
