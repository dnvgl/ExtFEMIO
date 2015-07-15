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
#include "bdf_errors.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;
using namespace bdf::string;
#ifdef __GNUC__
using namespace boost;
#endif

bdf_float::bdf_float(::std::string name) :
  bdf_type_base(name), bounds(num<double>()) {};

bdf_float::bdf_float(::std::string name, num<double> _bounds) :
  bdf_type_base(name), bounds(_bounds) {};

const regex bdf_float::float_exp_re(
  "([\\+-]?[.[:digit:]]+)([+-][[:digit:]]+)");

const regex bdf_float::float_re(
  "([\\+-]?((0|([1-9][[:digit:]]*))?[.][[:digit:]]*)|"
  "[.][[:digit:]]+)(((E[+-]?)|[+-])[[:digit:]]+)?",
  regex_constants::ECMAScript);

const regex bdf_float::float_lead_dot(
  "^[\\+-]?[.][[:digit:]]+", regex_constants::ECMAScript);

// Convert string to float
double *bdf_float::operator() (std::string inp) {
  double *value = new double();
  std::string sval = ::bdf::string::string(inp).trim().upper();

  if (sval.length() == 0) {
    *value = this->bounds.get_default();
  } else {
    if (! regex_match(sval, float_re)) {
      std::string msg("illegal input, no float");
      throw bdf_float_error(msg + "; !" + sval + "!\n");
    }

    smatch m;

    if (regex_search(sval, m, float_exp_re))
      sval = m[1].str() + "E" + m[2].str();

    if (regex_match(sval, float_lead_dot)) {
        size_t pos = sval.find('.');
        sval.insert(pos, 1, '0');
    }

    *value = ::std::stod(sval);
  }
  if (!this->bounds.in_bounds(value))
    throw  "** BDF INP ERROR **: boundary condition violated";
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
