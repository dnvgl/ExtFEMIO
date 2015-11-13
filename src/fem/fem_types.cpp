// Copyright © 2015 by DNV GL SE

// Definitions for SESAM FEM data entry types.

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

#ifndef _MSC_VER
#include <config.h>
#endif
#include "fem/types.h"
#include "extfem_string.h"

using namespace ::dnvgl::extfem;

fem::types::base::base(const::std::string &name) : name(name) {};

::std::string fem::types::card::format() const {
  ::std::ostringstream res;
  res.setf(std::ios_base::left, ::std::ios_base::adjustfield);
  res.fill(' ');
  res.width(8);
  res << name;
  return res.str();
}

::std::string fem::types::empty::format() const {
  ::std::ostringstream res;
  res.fill(' ');
  res.width(16);
  res << "+0.00000000e+00 ";
  return res.str();
}


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
