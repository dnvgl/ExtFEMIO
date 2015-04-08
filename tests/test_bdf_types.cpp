// Copyright © 2015 by DNV GL SE

// Testing of definitions for Nastran Bulk data entry types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include <iostream>
#include <climits>

#include <assert.h>

#include "bdf_types.h"

int main(const int argc, char * argv[]) {

  {
    ::std::cerr << "::bdf_types::bdf_int("").type  : " << ::bdf_types::bdf_int("").get_type()   << "\n";
    ::std::cerr << "::bdf_types::bdf_float("").type: " << ::bdf_types::bdf_float("").get_type() << "\n";
    assert(::bdf_types::bdf_int("") < ::bdf_types::bdf_float(""));
  }

  // {
  //   ::bdf_types::bdf_type_base* obj_int = new ::bdf_types::bdf_int("");
  //   ::bdf_types::bdf_type_base* obj_float = new ::bdf_types::bdf_float("");
  //   assert(*obj_int < *obj_float);
  // }

  {
    ::bdf_types::bdf_int obj("dummy", 1, 100000000 - 1);
    obj("   2    ");
    assert(obj.value == 2);
  }

  {
    ::bdf_types::bdf_int obj("dummy", 1, 100000000 - 1);
    obj("   2    ");
    assert(obj.value == 2);
  }

  {
    ::bdf_types::bdf_int obj("dummy", 0, LONG_MAX);
    obj("       2");
    assert(obj.value == 2);
  }

  // def test_Int3(self):
  //     obj = bdf_types.Int('dummy', minval=0, default=0)
  //     assert obj("2       ") == 2

    // def test_Int4(self):
    //     obj = bdf_types.Int('dummy', minval=-1, default=None)
    //     assert obj("    -1  ") == -1

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

    // class TestChoose1(object):

    //     @pytest.fixture(scope='class')
    //     def probe(self):
    //         return bdf_types.Choose(bdf_types.Float('doggy'),
    //                                 bdf_types.Int('dummy'))

    //     def test_int(self, probe):
    //         assert probe("1236") == 1236

    //     def test_float1(self, probe):
    //         assert probe("1236.") == 1236.

    //     def test_float2(self, probe):
    //         assert probe("1.236+3") == 1236.

    // class Test_Choose2(object):

    //     @pytest.fixture(scope='class')
    //     def probe(self):
    //         return bdf_types.Choose(bdf_types.Float('BIT'),
    //                                 bdf_types.Str('OFFT',
    //                                               allowed=('GGG', 'BGG', 'GGO',
    //                                                        'BGO', 'GOG', 'BOG',
    //                                                        'GOO', 'BOO', ''),
    //                                               default='GGG'))

    //     def test_float(self, probe):
    //         assert probe("1.") == 1.

    //     def test_str_1(self, probe):
    //         assert probe("BGO") == 'BGO'

    //     def test_str_2(self, probe):
    //         assert probe("GGO     ") == 'GGO'

    //     def test_str_3(self, probe):
    //         assert probe("") == 'GGG'

    //     def test_str_4(self, probe):
    //         assert probe("        ") == 'GGG'

    //     def test_raise(self, probe):
    //         with pytest.raises(ValueError):
    //             probe("XXX     ")

    // def test_Str1(self):
    //     obj = bdf_types.Str('dummy')
    //     assert obj('GOO   ') == 'GOO'

    // def test_Str2(self):
    //     obj = bdf_types.Str('dummy', default=False)
    //     with pytest.raises(ValueError):
    //         obj('')

    // def test_Cross(self):
    //     obj = bdf_types.Cross('dummy')
    //     with pytest.raises(ValueError):
    //         obj("")

}

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. test"
  coding: utf-8
  End:
*/
