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

entry_type<long>::entry_type(::std::string name) :
  ::bdf::types::base(name), bounds(*(::std::make_unique< ::bdf::type_bounds::bound<long> >())) {};

entry_type<long>::entry_type(::std::string name, ::bdf::type_bounds::bound<long> _bounds) :
  ::bdf::types::base(name), bounds(_bounds) {};

const regex entry_type<long>::int_re(
  "[[:space:]]*[\\+-]?[[:digit:]]+[[:space:]]*");

long *entry_type<long>::operator() (const std::string &inp) const {
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
    throw bdf_int_error(name, msg + name + ")\n(""" + inp + """)");
  }
  return value;
}

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
