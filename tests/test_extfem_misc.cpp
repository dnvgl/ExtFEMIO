/**
   \file tests/test_extfem_misc.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Tests for genaral helper functions.

   Detailed description
*/

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include <catch.hpp>

#include <config.h>
#include "extfem_misc.h"

#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl;

CATCH_TRANSLATE_EXCEPTION( extfem::bdf::errors::error& ex ) {
   return Catch::toString( ex() );
}

TEST_CASE("Checking misc functions", "[extfem::misc]") {

   SECTION("version number") {
      CHECK(extfem::version() == "ExtFEMIO, Ver. " ExtFEMIO_VERSION
            ", SVN. Rev. " ExtFEMIO_REVISION);
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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
