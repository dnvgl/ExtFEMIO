// Copyright © 2015 by DNV GL SE

// Definitions for Nastran Bulk data entry types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "stdafx.h"

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include <sstream>
#include <limits>
#include <algorithm>
#include <string>
#ifdef __GNUC__
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#ifndef _MSC_VER
#include <config.h>
#endif
#include "bdf_types.h"
#include "bdf_string.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;
using namespace bdf::string;
#ifdef __GNUC__
using namespace boost;
#endif

::bdf::types::base::base(::std::string name) : name(name) {};

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check -j 8"
  coding: utf-8
  End:
*/
