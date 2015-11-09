// Copyright © 2015 by DNV GL SE

// Definitions for helper functions.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "StdAfx.h"

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#ifdef __GNUC__
#include "config.h"
#endif

#ifdef _MSC_VER

#include <cmath>

double ::std::round(double number) {
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}

#endif

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "dnvgl"
  indent-tabs-mode: nil
  compile-command: "make -C ../.. check -j 8"
  coding: utf-8
  End:
*/
