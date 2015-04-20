// Copyright © 2015 by DNV GL SE

// Task      Tests for BDF float types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include <limits>

#include <catch.hpp>

#include "bdf_types.h"

TEST_CASE("BDF float types parsing.", "[bdf_types]" ) {

#if 0
  ::bdf_types::bdf_float probe("dummy", 0., std::numeric_limits<double>::max(), 0.);

  SECTION("'  -1    '") {
    probe("  -1    ");
    CHECK(probe.value == -1.);
  }
#endif

  //     def test_default(self, probe):
    //         assert probe("        ") == 0.

    // class TestFloat2(object):

    //     @pytest.fixture(scope='class')
    //     def probe(self):
    //         return bdf_types.Float('dummy')

    //     def test_dot(self, probe):
    //         assert probe('123.') == 123.

    //     def test_exp(self, probe):
    //         assert probe('123+3') == 123000.

    // def test_List1(self):
    //     obj = bdf_types.List('dummy', maxelem=6, minval=1, maxval=6, uniq=True)
    //     assert obj("1236") == (1, 2, 3, 6)

}


/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make test"
  coding: utf-8
  End:
*/
