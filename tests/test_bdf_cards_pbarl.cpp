/**
   \file tests/test_bdf_cards_pbarl.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PBARL` card class.

   Detailed description
   */

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

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

TEST_CASE("BDF PBARL definitions.", "[bdf_PBARL]") {

    SECTION("Small Field Format (BAR)") {

        std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104018  4               BAR\n",
            "           25.0   600.0\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbarl probe(lines);

        CHECK((long)probe.PID == 104018);
        CHECK((long)probe.MID == 4);
        CHECK(probe.GROUP == "MSCBML0");
        CHECK(probe.TYPE == "BAR");
        CHECK(probe.DIM.size() == 2);
        CHECK(probe.DIM == std::vector<double>({25., 600.}));
        CHECK((double)probe.NSM == 0.);
    }


    SECTION("Small Field Format (BAR) (alt.)") {

        std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL        134       8            BAR\n",
            "            55.0   500.0"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbarl probe(lines);

        CHECK((long)probe.PID == 134);
        CHECK((long)probe.MID == 8);
        CHECK(probe.GROUP == "MSCBML0");
        CHECK(probe.TYPE == "BAR");
        CHECK(probe.DIM == std::vector<double>({55., 500.}));
        CHECK((double)probe.NSM == 0.);
    }

    SECTION("Small Field Format (L)") {

        std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104010  4               L\n",
            "           63.0   340.0    35.0    14.0\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbarl probe(lines);

        CHECK((long)probe.PID == 104010);
        CHECK((long)probe.MID == 4);
        CHECK(probe.GROUP == "MSCBML0");
        CHECK(probe.TYPE == "L");
        CHECK(probe.DIM == std::vector<double>({63., 340., 35., 14.}));
        CHECK((double)probe.NSM == 0.);
    }

    SECTION("Small Field Format (T)") {

        std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   101031  1               T\n",
            "          150.0   400.0    12.0    10.0\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbarl probe(lines);

        CHECK((long)probe.PID == 101031);
        CHECK((long)probe.MID == 1);
        CHECK(probe.GROUP == "MSCBML0");
        CHECK(probe.TYPE == "T");
        CHECK(probe.DIM == std::vector<double>({150., 400., 12., 10.}));
        CHECK((double)probe.NSM == 0.);
    }

    SECTION("Small Field Format (I)") {

        std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104018  4               I\n",
            "           600.0   200.0   200.0    12.0    10.0    10.0\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbarl probe(lines);

        CHECK((long)probe.PID == 104018);
        CHECK((long)probe.MID == 4);
        CHECK(probe.GROUP == "MSCBML0");
        CHECK(probe.TYPE == "I");
        CHECK(probe.DIM == std::vector<double>({
            600., 200., 200., 12., 10., 10.}));
        CHECK((double)probe.NSM == 0.);
    }

    SECTION("Small Field Format (I) (alt)") {

        std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL         39       6               I\n",
            "             14.      6.      .5      .5      .5      .5\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbarl probe(lines);

        CHECK((long)probe.PID == 39);
        CHECK((long)probe.MID == 6);
        CHECK(probe.GROUP == "MSCBML0");
        CHECK(probe.TYPE == "I");
        CHECK(probe.DIM == std::vector<double>({
            14., 6., .5, .5, .5, .5}));
        CHECK((double)probe.NSM == 0.);
    }

    SECTION("Small Field Format (TUBE)") {

        std::list<std::string> data({
            // 34567a1234567b1234567c1234567d1234567e1234567f1234567g1234567h1234567i1234567j
            "PBARL   104019  5               TUBE\n",
            "           600.0   500.0\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pbarl probe(lines);

        CHECK((long)probe.PID == 104019);
        CHECK((long)probe.MID == 5);
        CHECK(probe.GROUP == "MSCBML0");
        CHECK(probe.TYPE == "TUBE");
        CHECK(probe.DIM == std::vector<double>({600., 500.}));
        CHECK((double)probe.NSM == 0.);
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
