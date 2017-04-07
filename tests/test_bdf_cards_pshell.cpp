/**
   \file tests/test_bdf_cards_pshell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `PSHELL` card class.

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

TEST_CASE("BDF PSHELL definitions.",
          "[bdf_PSHELL]") {

    SECTION("Small Field Format") {

        std::list<std::string> data({
            "PSHELL  1       4         23.00 4               4\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pshell probe(lines);

        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }

    SECTION("Large Field Format") {

        std::list<std::string> data({
            "PSHELL* 1               4                 23.00         4               \n",
            "*                       4  \n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pshell probe(lines);

        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
    }

    SECTION("Comma Field Format") {

        std::list<std::string> data({"PSHELL,1,4,23.00,4,,4\n"});
        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        pshell probe(lines);

        CHECK((long)probe.PID == 1);
        CHECK((long)probe.MID1 == 4);
        CHECK((double)probe.T == 23.);
        CHECK((long)probe.MID2 == 4);
        CHECK((double)probe.x12I_T__3 == 1.);
        CHECK((long)probe.MID3 == 4);
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
