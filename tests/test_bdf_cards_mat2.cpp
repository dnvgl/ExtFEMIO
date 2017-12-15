/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing the BDF `MAT2` cards classes.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_test_bdf_cards_mat2[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/cards.h"
#include "bdf/file.h"

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
using namespace cards;
using namespace input;

TEST_CASE("BDF MAT2 definitions. (Free Field Format) first",
          "[bdf_mat2]") {

    SECTION("first mat2") {
        std::list<std::string> const data({
            "MAT2,1,2.,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,"
            "13.,14.,15.,16.,17\n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        mat2 probe(lines);

        CHECK((long)probe.MID == 1);
        CHECK((double)probe.G11 == 2.);
        CHECK((double)probe.G12 == 3.);
        CHECK((double)probe.G13 == 4.);
        CHECK((double)probe.G22 == 5.);
        CHECK((double)probe.G23 == 6.);
        CHECK((double)probe.G33 == 7.);
        CHECK((double)probe.RHO == 8.);
        CHECK((double)probe.A1 == 9.);
        CHECK((double)probe.A2 == 10.);
        CHECK((double)probe.A3 == 11.);
        CHECK((double)probe.TREF == 12.);
        CHECK((double)probe.GE == 13.);
        CHECK((double)probe.ST == 14.);
        CHECK((double)probe.SC == 15.);
        CHECK((double)probe.SS == 16.);
        CHECK((long)probe.MCSID == 17);
    }
}

namespace {
    std::string err_msg;

    void _warn_res(const std::string &msg) {
        err_msg = msg;
    }
}

TEST_CASE("BDF MAT2 definitions. (FEMIO-3)",
          "[bdf_mat_FEMIO_3]") {

    warn_report = &_warn_res;

    SECTION("FEMIO-3") {
        std::list<std::string> const data({
            "MAT2*    10              7.01670932+10   2.78474977+10   0.",
            "*        1.35642948+11   0.              1.26610002+10   0.",
            "*        .000012         .000012         .000012         0.",
            "*        2.99999993-2    0.              0.              0.",
            "*"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        mat2 probe(lines);

        CHECK((long)probe.MID == 10);
        CHECK((double)probe.G11 == 7.01670932e+10);
        CHECK((double)probe.G12 == 2.78474977e+10);
        CHECK((double)probe.G13 == 0.);
        CHECK((double)probe.G22 == 1.35642948e+11);
        CHECK((double)probe.G23 == 0.);
        CHECK((double)probe.G33 == 1.26610002e+10);
        CHECK((double)probe.RHO == 0.);
        CHECK((double)probe.A1 == 12.e-6);
        CHECK((double)probe.A2 == 12.e-6);
        CHECK((double)probe.A3 == 12.e-6);
        CHECK((double)probe.TREF == 0.);
        CHECK((double)probe.GE == 2.99999993e-2);
        CHECK((double)probe.ST == 0.);
        CHECK((double)probe.SC == 0.);
        CHECK((double)probe.SS == 0.);
        CHECK((long)probe.MCSID == 0);
        CHECK(err_msg ==
              "Long Field Format: Missing continuation line for record:\n"
              "--> MAT2*    10              7.01670932+10   2.78474977+10   0.\n"
              "--> *        1.35642948+11   0.              1.26610002+10   0.\n"
              "--> *        .000012         .000012         .000012         0.\n"
              "--> *        2.99999993-2    0.              0.              0.\n"
              "--> *\n");
    }
}

TEST_CASE("BDF MAT2 roundtrio test 1.", "[bdf_mat2_roundtrip_1]") {

    std::ostringstream test;

    long MID{1};
    double G11{2.};
    double G12{3.};
    double G13{4.};
    double G22{5.};
    double G23{6.};
    double G33{7.};
    double RHO{8.};
    double A1{9.};
    double A2{10.};
    double A3{11.};
    double TREF{12.};
    double GE{13.};
    double ST{14.};
    double SC{15.};
    double SS{16.};
    long MCSID{17};

    mat2 const probe(&MID, &G11, &G12, &G13, &G22, &G23, &G33, &RHO,
               &A1, &A2, &A3, &TREF, &GE, &ST, &SC, &SS,
               &MCSID);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "MAT2           12.000+003.000+004.000+005.000+006.000+007.000+008.000+00\n"
              "        9.000+001.000+011.100+011.200+011.300+011.400+011.500+011.600+01\n"
              "              17\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        mat2 probe_l(lines);

        CHECK(probe_l.MID.value == 1);
        CHECK(probe_l.G11.value == 2.);
        CHECK(probe_l.G12.value == 3.);
        CHECK(probe_l.G13.value == 4.);
        CHECK(probe_l.G22.value == 5.);
        CHECK(probe_l.G23.value == 6.);
        CHECK(probe_l.G33.value == 7.);
        CHECK(probe_l.RHO.value == 8.);
        CHECK(probe_l.A1.value == 9.);
        CHECK(probe_l.A2.value == 10.);
        CHECK(probe_l.A3.value == 11.);
        CHECK(probe_l.TREF.value == 12.);
        CHECK(probe_l.GE.value == 13.);
        CHECK(probe_l.ST.value == 14.);
        CHECK(probe_l.SC.value == 15.);
        CHECK(probe_l.SS.value == 16.);
        CHECK(probe_l.MCSID.value == 17);
    }
}

TEST_CASE("BDF MAT2 roundtrio test reuse.", "[bdf_mat2_roundtrip_1_reuse]") {

    std::ostringstream test;

    long MID{1};
    double G11{2.};
    double G12{3.};
    double G13{4.};
    double G22{5.};
    double G23{6.};
    double G33{7.};
    double RHO{8.};
    double A1{9.};
    double A2{10.};
    double A3{11.};
    double TREF{12.};
    double GE{13.};
    double ST{14.};
    double SC{15.};
    double SS{16.};
    long MCSID{17};

    mat2 probe;
    test << probe;
    test << probe(&MID, &G11, &G12, &G13, &G22, &G23, &G33, &RHO,
          &A1, &A2, &A3, &TREF, &GE, &ST, &SC, &SS,
          &MCSID);


    SECTION("check output") {
        CHECK(test.str() ==
              "MAT2           12.000+003.000+004.000+005.000+006.000+007.000+008.000+00\n"
              "        9.000+001.000+011.100+011.200+011.300+011.400+011.500+011.600+01\n"
              "              17\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        mat2 probe_l;
        probe_l(lines);

        CHECK(probe_l.MID.value == 1);
        CHECK(probe_l.G11.value == 2.);
        CHECK(probe_l.G12.value == 3.);
        CHECK(probe_l.G13.value == 4.);
        CHECK(probe_l.G22.value == 5.);
        CHECK(probe_l.G23.value == 6.);
        CHECK(probe_l.G33.value == 7.);
        CHECK(probe_l.RHO.value == 8.);
        CHECK(probe_l.A1.value == 9.);
        CHECK(probe_l.A2.value == 10.);
        CHECK(probe_l.A3.value == 11.);
        CHECK(probe_l.TREF.value == 12.);
        CHECK(probe_l.GE.value == 13.);
        CHECK(probe_l.ST.value == 14.);
        CHECK(probe_l.SC.value == 15.);
        CHECK(probe_l.SS.value == 16.);
        CHECK(probe_l.MCSID.value == 17);
    }
}

TEST_CASE("BDF MAT2 testing yield stress handling.", "[bdf_mat2_yield]") {

    std::ostringstream test;

    std::string const s(
        // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
        "$svd.mat 1        ""Mild""\n"
        "$svd.yield 1        235.0 1.0\n"
        "$ Marterial Record : Mild\n"
        "$ Description of Material :\n"
        "MAT2*    1               7.01670932+10   2.78474977+10   0.\n"
        "*        1.35642948+11   0.              1.26610002+10   0.\n"
        "*        .000012         .000012         .000012         0.\n"
        "*        2.99999993-2    0.              0.              0.\n"
        "*\n"
        "*\n"
        "$       \n"
        "$svd.mat 2        ""HT32""\n"
        "$svd.yield 2        315.0 0.78\n"
        "$ Marterial Record : HT32\n"
        "$ Description of Material :\n"
        "MAT2*    2               7.01670932+10   2.78474977+10   0.\n"
        "*        1.35642948+11   0.              1.26610002+10   0.\n"
        "*        .000012         .000012         .000012         0.\n"
        "*        2.99999993-2    0.              0.              0.\n"
        "MAT2*    3               7.01670932+10   2.78474977+10   0.\n"
        "*        1.35642948+11   0.              1.26610002+10   0.\n"
        "*        .000012         .000012         .000012         0.\n"
        "*        2.99999993-2    0.              0.              0.\n");
    std::istringstream ist(s);
    bdf_file probe(ist);
    std::list<std::string> l;
    std::list<std::string> data;

    {
        probe.get(l);
        CAPTURE(l.front());
        __base::card::card_split(l, data);
        comment card(data);
        CHECK(*(card.yield) == 235.);
        CHECK(*(comment::yield) == 235.);
    }

    {
        probe.get(l);
        CAPTURE(l.front());
        __base::card::card_split(l, data);
        mat2 card(data);
        CHECK(long(card.MID) == 1);
        CHECK(double(card.G11) == 70167093200.);
        CHECK(double(card.G12) == 27847497700.);
        CHECK(double(card.G13) == 0.);
        CHECK(double(card.G22) == 135642948000.);
        CHECK(double(card.G23) == 0.);
        CHECK(double(card.G33) == 12661000200.);
        CHECK(double(card.RHO) == 0.);
        CHECK(double(card.A1) == .000012);
        CHECK(double(card.A2) == .000012);
        CHECK(double(card.A3) == .000012);
        CHECK(double(card.TREF) == 0.);
        CHECK(double(card.GE) == .0299999993);
        CHECK(double(card.ST) == 0.);
        CHECK(double(card.SC) == 0.);
        CHECK(double(card.SS) == 0.);
        CHECK(long(card.MCSID) == 0);
        CHECK(card.extra.yield != nullptr);
        CHECK(*(card.extra.yield) == 235.);
    }

    {
        probe.get(l);
        CAPTURE(l.front());
        __base::card::card_split(l, data);
        comment card(data);
        CHECK(*(card.yield) == 315.);
        CHECK(*(comment::yield) == 315.);
    }

    {
        probe.get(l);
        CAPTURE(l.front());
        __base::card::card_split(l, data);
        mat2 card(data);
        CHECK(long(card.MID) == 2);
        CHECK(double(card.G11) == 70167093200.);
        CHECK(double(card.G12) == 27847497700.);
        CHECK(double(card.G13) == 0.);
        CHECK(double(card.G22) == 135642948000.);
        CHECK(double(card.G23) == 0.);
        CHECK(double(card.G33) == 12661000200.);
        CHECK(double(card.RHO) == 0.);
        CHECK(double(card.A1) == .000012);
        CHECK(double(card.A2) == .000012);
        CHECK(double(card.A3) == .000012);
        CHECK(double(card.TREF) == 0.);
        CHECK(double(card.GE) == .0299999993);
        CHECK(double(card.ST) == 0.);
        CHECK(double(card.SC) == 0.);
        CHECK(double(card.SS) == 0.);
        CHECK(long(card.MCSID) == 0);
        CHECK(card.extra.yield != nullptr);
        CHECK(*(card.extra.yield) == 315.);
    }

    {
        probe.get(l);
        CAPTURE(l.front());
        __base::card::card_split(l, data);
        mat2 card(data);
        CHECK(long(card.MID) == 3);
        CHECK(double(card.G11) == 70167093200.);
        CHECK(double(card.G12) == 27847497700.);
        CHECK(double(card.G13) == 0.);
        CHECK(double(card.G22) == 135642948000.);
        CHECK(double(card.G23) == 0.);
        CHECK(double(card.G33) == 12661000200.);
        CHECK(double(card.RHO) == 0.);
        CHECK(double(card.A1) == .000012);
        CHECK(double(card.A2) == .000012);
        CHECK(double(card.A3) == .000012);
        CHECK(double(card.TREF) == 0.);
        CHECK(double(card.GE) == .0299999993);
        CHECK(double(card.ST) == 0.);
        CHECK(double(card.SC) == 0.);
        CHECK(double(card.SS) == 0.);
        CHECK(long(card.MCSID) == 0);
        CHECK(card.extra.yield == nullptr);
    }

}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
