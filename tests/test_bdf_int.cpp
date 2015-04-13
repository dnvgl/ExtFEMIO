// Copyright © 2015 by DNV GL SE

// Task      Tests for BDF int types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "test_bdf_int.h"

void test_bdf_int () {

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

  {
    ::bdf_types::bdf_int obj("dummy", 0, LONG_MAX, 0);
    obj("2       ");
    assert(obj.value == 2);
  }

  {
    ::bdf_types::bdf_int obj("dummy", -1, LONG_MAX, 0);
    obj("    -1  ");
    assert(obj.value == -1);
  }

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
