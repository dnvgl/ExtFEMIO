/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Generate bulk param entries.

   Detailed description
*/
#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED = 
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <complex>

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

TEST_CASE("BDF PARAM definitions. (Small Field Format)",
          "[bdf_PARAM]") {

    SECTION("param read int") {
        std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   IRES     1                                                      \n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        param probe(lines);
        CHECK(probe.N == "IRES");
        CHECK(probe.IVAL.value == 1);
        CHECK_FALSE(bool(probe.RVAL));
        CHECK_FALSE(bool(probe.CVAL));
        CHECK_FALSE(bool(probe.CPLXVAL));
    }

    SECTION("param read real") {
        std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   ADPCON   1.                                                     \n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        param probe(lines);
        CHECK(probe.N == "ADPCON");
        CHECK_FALSE(bool(probe.IVAL));
        CHECK(probe.RVAL.value == 1.);
        CHECK_FALSE(bool(probe.CVAL));
        CHECK_FALSE(bool(probe.CPLXVAL));
    }

    SECTION("param read char") {
        std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   ACOUT    PEAK                                                   \n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        param probe(lines);
        CHECK(probe.N == "ACOUT");
        CHECK_FALSE(bool(probe.IVAL));
        CHECK_FALSE(bool(probe.RVAL));
        CHECK(probe.CVAL.value == "PEAK");
        CHECK_FALSE(bool(probe.CPLXVAL));
    }

    SECTION("param read complex") {
        std::list<std::string> data({
            // 345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2345678|2
            "PARAM   CP1      2.      3.                                             \n"});

        std::list<std::string> lines;
        __base::card::card_split(data, lines);
        param probe(lines);
        CHECK(probe.N == "CP1");
        CHECK_FALSE(bool(probe.IVAL));
        CHECK_FALSE(bool(probe.RVAL));
        CHECK_FALSE(bool(probe.CVAL));
        CHECK(probe.CPLXVAL.value == std::complex<double>(2., 3.));
    }
}

TEST_CASE("BDF PARAM types output.", "[bdf_param,out]") {

    std::ostringstream test;

    SECTION("output int") {
        std::string name{"int"};
        long val{123};
        param probe(name, val);
        test << probe;
        CHECK(test.str() == "PARAM   INT          123\n");
    }

    SECTION("output char") {
        std::string name{"chr"}, val{"123"};
        param probe(name, val);
        test << probe;
        CHECK(test.str() == "PARAM   CHR     123     \n");
    }

    SECTION("output double") {
        std::string name{"dble"};
        double val{123e1};
        param probe(name, val);
        test << probe;
        CHECK(test.str() == "PARAM   DBLE    1.230+03\n");
    }

    SECTION("output complex 1") {
        std::string name{"cmplx"};
        double val1{1e1}, val2{1e1};
        param probe(name, val1, val2);
        test << probe;
        CHECK(test.str() == "PARAM   CMPLX   1.000+011.000+01\n");
    }

    SECTION("output complex 2") {
        std::string name{"cmplx"};
        std::complex<double> val(1e1, 1e1);
        param probe(name, val);
        test << probe;
        CHECK(test.str() == "PARAM   CMPLX   1.000+011.000+01\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
