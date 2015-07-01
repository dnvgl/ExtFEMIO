// Copyright © 2015 by DNV GL SE

// Definitions for Nastran Bulk data entry types.

// Author    Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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

bdf_float::bdf_float() :
  bdf_type_base(), bounds(num<double>()) {};

bdf_float::bdf_float(num<double> _bounds) :
  bdf_type_base(), bounds(_bounds) {};

const regex bdf_float::float_exp_re("([\\+-]?[.[:digit:]]+)([+-][[:digit:]]+)");

const regex bdf_float::float_re(
  "([\\+-]?((0|([1-9][[:digit:]]*))?[.][[:digit:]]*)|[.][[:digit:]]+)(((E[+-]?)|[+-])[[:digit:]]+)?",
  regex_constants::ECMAScript);

// Convert string to float
void bdf_float::parse(std::string inp) {
  std::string sval = ::bdf::string::string(inp).trim().upper();

  if (sval.length() == 0) {
    value = this->bounds.get_default();
  } else {
    if (! regex_match(sval, float_re)) {
      std::string msg("illegal input, no float");
      throw msg + "; !" + sval + "!\n";
    }

    smatch m;

    if (regex_search (sval, m, float_exp_re))
      sval = m[1].str() + "E" + m[2].str();

    istringstream buffer(sval);
    buffer >> value;
  }
  if (!this->bounds.in_bounds(value))
    throw  "** BDF INP ERROR **: boundary condition violated";
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
