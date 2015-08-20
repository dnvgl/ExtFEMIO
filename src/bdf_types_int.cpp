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
#include <memory>
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

bdf_int::bdf_int(::std::string name) :
  bdf_type_base(name), bounds(*(::std::make_unique< num<long> >())) {};

bdf_int::bdf_int(::std::string name, num<long> _bounds) :
  bdf_type_base(name), bounds(_bounds) {};

const regex bdf_int::int_re(
  "[[:space:]]*[\\+-]?[[:digit:]]+[[:space:]]*");

long *bdf_int::operator() (const std::string inp) {
  std::string sval = bdf::string::string(inp).trim();
  long *value = new long();
  if (sval.length() == 0) {
    if (this->bounds.does_allow_empty())
      return nullptr;
    if (!this->bounds.has_default())
      throw bdf_int_error(name, "empty entry without default");
    *value = this->bounds.get_default();
    return value;
  } else {
    if (! regex_match(inp, int_re)) {
      std::string msg("illegal input (""");
      msg += inp;
      msg += """), no integer";
      throw bdf_int_error(name, msg);
    }
    istringstream buffer(sval);
    buffer >> *value;
  }
  if (!this->bounds.in_bounds(value)) {
    ::std::string msg("boundary condition violated (");
    msg += name;
    msg += ")\n(""";
    msg += inp;
    msg += """)";
    throw bdf_int_error(name, msg);
  }
  return value;
}

/*
  Local Variables:
  mode: c++
  ispell-local-dictionary: "english"
  c-file-style: "gl"
  indent-tabs-mode: nil
  compile-command: "make -C .. check"
  coding: utf-8
  End:
*/
