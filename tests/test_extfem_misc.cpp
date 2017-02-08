/**
   \file tests/test_extfem_misc.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for genaral helper functions.

   Detailed description
   */

#include "extfem_misc.h"

// ID:
namespace {
    const char cID[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <catch.hpp>

#include "config.h"

#include "extfem_misc.h"

#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl;

TEST_CASE("Checking misc functions", "[extfem::misc]") {

    SECTION("version number") {
        CHECK(extfem::version() == "ExtFEMIO, Ver. " ExtFEMIO_VERSION);
    }
    SECTION("build data number") {
        CAPTURE(extfem::build_data());
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_extfem_string --use-colour no)"
// End:
