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

#include "test_bdf_float.h"

void test_bdf_float () {

    // class TestFloat1(object):

    //     @pytest.fixture(scope='class')
    //     def probe(self):
    //         return bdf_types.Float('dummy', default=0.0)

    //     def test_neg(self, probe):
    //         assert probe("  -1    ") == -1.

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
