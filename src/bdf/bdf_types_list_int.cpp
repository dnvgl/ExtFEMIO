// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran Bulk data entry types.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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
#include <boost/regex.hpp>
#else
#include <regex>
#endif

#include "bdf/types.h"

#ifdef __GNUC__
using boost::regex;
#else
using std::regex;
#endif
using bdf::types::entry_type;

const regex entry_type<std::deque<int>>::int_re("[[:digit:]]*");

std::deque<int>*
entry_type<std::deque<int>>::operator() (const std::string &inp) const {
  auto *value =  new std::deque<int>();
  auto sval = bdf::string::string(inp).trim();
  if (! regex_match(sval, int_re)) {
    std::string msg(name + ":illegal input (""");
    throw bdf_types_error(msg + sval + """), no integer in list");
  }
  for (auto pos = sval.begin();
       pos != sval.end(); ++pos)
    value->push_back(*pos - '0');
  return value;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
