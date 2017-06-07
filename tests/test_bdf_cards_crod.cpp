/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Testing the BDF `CROD` card class.

   Detailed description
*/
#include "extfem_misc.h"
#include "bdf/cards_elements.h"

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

TEST_CASE("BDF CROD default EID.", "[bdf_crod]") {
    crod::reset();
    long G1{1}, G2{2};
    crod probe(nullptr, nullptr, &G1, &G2);
    CHECK(long(probe.EID) == 1);
    CHECK(long(probe.PID) == 1);
    crod probe2(nullptr, nullptr, &G1, &G2);
    CHECK(long(probe2.EID) == 2);
    CHECK(long(probe2.PID) == 2);
}

TEST_CASE("BDF CROD definitions. (Free Field Format)", "[bdf_crod]") {

    std::list<std::string> data({"CROD,222,13,14,15\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    crod probe(lines);

    SECTION("check value") {
        CHECK(probe.EID.value == 222);
        CHECK(probe.PID.value == 13);
        CHECK(probe.G1.value == 14);
        CHECK(probe.G2.value == 15);
    }
}

TEST_CASE("BDF CROD definitions. (Free Field Format) (default PID)",
          "[bdf_crod]") {

    std::list<std::string> data({"CROD,222,,14,15\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    crod probe(lines);

    SECTION("check value") {
        CHECK(probe.EID.value == 222);
        CHECK(probe.PID.value == 222);
        CHECK(probe.G1.value == 14);
        CHECK(probe.G2.value == 15);
    }
}

TEST_CASE("BDF CROD definitions. (Small Field Format)", "[bdf_crod]") {

    std::list<std::string> data({
            "CROD        7869     234      76     153\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    crod probe(lines);

    SECTION("check value") {
        CHECK(probe.EID.value == 7869);
        CHECK(probe.PID.value == 234);
        CHECK(probe.G1.value == 76);
        CHECK(probe.G2.value == 153);
    }
}

TEST_CASE("BDF CROD definitions. (Small Field Format) (default PID)",
          "[bdf_crod]") {

    std::list<std::string> data({
            "CROD        7869              76     153\n"});
    std::list<std::string> lines;
    __base::card::card_split(data, lines);
    crod probe(lines);

    SECTION("check value") {
        CHECK(probe.EID.value == 7869);
        CHECK(probe.PID.value == 7869);
        CHECK(probe.G1.value == 76);
        CHECK(probe.G2.value == 153);
    }
}

TEST_CASE("BDF CROD roundtrip test.", "[bdf_crod]") {
    crod::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, G1{76}, G2{153};

    crod probe(&EID, &PID, &G1, &G2);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CROD        7869  104010      76     153\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        crod probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.G1) == 76);
        CHECK(long(probe_l.G2) == 153);
    }
}

TEST_CASE("BDF CROD roundtrip test (reuse).", "[bdf_crod]") {
    crod::reset();
    std::ostringstream test;

    long EID{7869}, PID{104010}, G1{76}, G2{153};

    crod probe;
    test << probe;
    test << probe(&EID, &PID, &G1, &G2);

    SECTION("check output") {
        CHECK(test.str() ==
              "CROD        7869  104010      76     153\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        crod probe_l;
        probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 104010);
        CHECK(long(probe_l.G1) == 76);
        CHECK(long(probe_l.G2) == 153);
    }
}

TEST_CASE("BDF CROD roundtrip test. (default PID)", "[bdf_crod]") {
    crod::reset();
    std::ostringstream test;

    long EID{7869}, G1{76}, G2{153};

    crod probe(&EID, nullptr, &G1, &G2);
    test << probe;

    SECTION("check output") {
        CHECK(test.str() ==
              "CROD        7869    7869      76     153\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        crod probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.G1) == 76);
        CHECK(long(probe_l.G2) == 153);
    }
}

TEST_CASE("BDF CROD roundtrip test (reuse) (default PID).", "[bdf_crod]") {
    crod::reset();
    std::ostringstream test;

    long EID{7869}, G1{76}, G2{153};

    crod probe;
    test << probe;
    test << probe(&EID, nullptr, &G1, &G2);

    SECTION("check output") {
        CHECK(test.str() ==
              "CROD        7869    7869      76     153\n");
    }

    SECTION("check reading") {
        std::list<std::string> data;
        std::list<std::string> lines;
        std::string tmp;
        std::istringstream raw(test.str());

        while (getline(raw, tmp))
            data.push_back(tmp);
        __base::card::card_split(data, lines);
        crod probe_l;
        probe_l(lines);

        CHECK(long(probe_l.EID) == 7869);
        CHECK(long(probe_l.PID) == 7869);
        CHECK(long(probe_l.G1) == 76);
        CHECK(long(probe_l.G2) == 153);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test ;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
