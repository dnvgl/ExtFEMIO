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

#include <cassert>

#include "bdf_types.h"

#include "test_bdf_int.h"
#include "test_bdf_float.h"

int main(const int argc, char * argv[]) {

  {
    assert(::bdf_types::bdf_int("").type() == ::bdf_types::Int);
    assert(::bdf_types::bdf_float("").type() == ::bdf_types::Float);
    assert(::bdf_types::bdf_int("") < ::bdf_types::bdf_float(""));
  }

  {
    ::bdf_types::bdf_type_base* obj_int = new ::bdf_types::bdf_int("");
    ::bdf_types::bdf_type_base* obj_float = new ::bdf_types::bdf_float("");
    assert(obj_int->type() == ::bdf_types::Int);
    assert(obj_float->type() == ::bdf_types::Float);
    assert(*obj_int < *obj_float);
  }

  test_bdf_int();
  test_bdf_float();

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