/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Testing of DISPLACEMENT class for case control.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char  cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#define NOMINMAX // To avoid problems with "numeric_limits"

#include <catch.hpp>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/header.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace dnvgl::extfem::bdf::header;

TEST_CASE("BDF generate 'DISPLACEMENT' header entries", "[bdf_header,displacement]") {

    std::ostringstream test;

    SECTION("first") {
        case_control::displacement probe({}, case_control::displacement::restype::ALL);
        test << probe;
        CHECK(test.str() == "DISPLACEMENT = ALL\n");
    }

    SECTION("bdf sample") {
        case_control::displacement probe({
            make_shared<case_control::displacement::print>(),
            make_shared<case_control::displacement::punch>(),
            make_shared<case_control::displacement::real>()},
            case_control::displacement::restype::ALL);
        test << probe;
        CHECK(test.str() == "DISPLACEMENT(PRINT, PUNCH, REAL) = ALL\n");
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j7 &&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_bdf_header --use-colour no)"
// End:
