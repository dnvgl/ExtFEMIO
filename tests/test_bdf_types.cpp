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

#define NOMINMAX

#include <utility>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp fil
#define CATCH_CONFIG_COLOUR_NONE    // completely disables all text colouring

#include <catch.hpp>

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"

using namespace bdf::types;

TEST_CASE("BDF types are compared.", "[bdf_types]" ) {

  bdf_type_base* obj_int = new bdf_int();
  bdf_type_base* obj_float = new bdf_float();
  bdf_type_base* obj_list = new bdf_list<int>();

  SECTION("Checking 'bdf_int.type' against 'Int'") {
    CHECK(bdf_int().type() == Int);
  }

  SECTION("Checking 'bdf_int->type' against 'Int'") {
    CHECK(obj_int->type() == Int);
  }

  SECTION("Checking 'bdf_float.type' against 'Float'") {
    CHECK(bdf_float().type() == Float);
  }

  SECTION("Checking 'bdf_float->type' against 'Float'") {
    CHECK(obj_float->type() == Float);
  }

  SECTION("Checking 'bdf_list.type' against 'List'") {
    CHECK(bdf_list<int>().type() == List);
  }

  SECTION("Checking 'bdf_list->type' against 'List'") {
    CHECK(obj_list->type() == List);
  }

  SECTION("Comparing 'bdf_int' with 'bdf_float'") {
    CHECK(bdf_int() < bdf_float());
    CHECK(bdf_float() > bdf_int());
    CHECK(bdf_int() != bdf_float());
  }

  SECTION("Comparing '*bdf_int' with '*bdf_float'") {
    CHECK(*obj_int < *obj_float);
  }
}

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


/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C ../ check"
  coding: utf-8
  End:
*/
