/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing BDF header ECHO entry

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_test_bdf_header_echo[]) =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif


#include "bdf/header.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::header;

TEST_CASE("Testing cdni_entry", "[bdf_header,echo,cdni_entry]") {

    SECTION("first") {
        case_control::echo::sort::cdni_entry probe("ABC");
        CHECK(probe.str() == "ABC");
    }

    SECTION("pointer") {
        shared_ptr<case_control::echo::sort::cdni_entry> probe;
        probe = make_shared<case_control::echo::sort::cdni_entry>("ABC");
        CHECK(probe->str() == "ABC");
    }

    SECTION("except") {
        case_control::echo::sort::cdni_entry probe("ABC", true);
        CHECK(probe.str() == "EXCEPT ABC");
    }
}

TEST_CASE("BDF generate more 'ECHO' header entries", "[bdf_header,echo]") {

    ostringstream test;

    SECTION("ECHO = NONE") {
        case_control::echo probe({make_shared<case_control::echo::none>()});
        test << probe;
        CHECK(test.str() == "ECHO = NONE\n");
    }

    SECTION("ECHO=NOSORT") {
        case_control::echo probe({make_shared<case_control::echo::unsort>()});
        test << probe;
        CHECK(test.str() == "ECHO = UNSORT\n");
    }

    SECTION("ECHO=BOTH") {
        case_control::echo probe({make_shared<case_control::echo::both>()});
        test << probe;
        CHECK(test.str() == "ECHO = BOTH\n");
    }

    SECTION("ECHO = PUNCH, SORT (MAT1, PARAM)") {
        case_control::echo probe(
            {make_shared<case_control::echo::punch>(),
             make_shared<case_control::echo::sort>(
                 vector<shared_ptr<case_control::echo::sort::cdni_entry>>(
                     {make_shared<case_control::echo::sort::cdni_entry>("MAT1"),
                      make_shared<case_control::echo::sort::cdni_entry>("PARAM")}))});
        test << probe;
        CHECK(test.str() == "ECHO = PUNCH, SORT(MAT1, PARAM)\n");
    }

    SECTION("ECHO = SORT (EXCEPT DMI, DMIG)") {
        case_control::echo probe(
            {make_shared<case_control::echo::sort>(
                 vector<shared_ptr<case_control::echo::sort::cdni_entry>>(
                     {make_shared<case_control::echo::sort::cdni_entry>("DMI", true),
                      make_shared<case_control::echo::sort::cdni_entry>("DMIG")}))});
        test << probe;
        CHECK(test.str() == "ECHO = SORT(EXCEPT DMI, DMIG)\n");
    }

    SECTION("ECHO=BOTH,PUNCH,FILE") {
        case_control::echo probe(
            {make_shared<case_control::echo::both>(),
             make_shared<case_control::echo::punch>(),
             make_shared<case_control::echo::file>()});
        test << probe;
        CHECK(test.str() == "ECHO = BOTH, PUNCH, FILE\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
