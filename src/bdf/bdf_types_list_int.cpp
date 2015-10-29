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

#include <sstream>

#include "bdf/types.h"

using namespace std;

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

std::string entry_type<std::deque<int>>::format(const std::deque<int>& inp) const {
  std::ostringstream res1, res2;

  for (auto &p : inp) res1 << p;

  std::string inp_proc(res1.str());

  switch (out_form) {
  case LONG:
    res2.setf(ios_base::right, ios_base::adjustfield);
    res2.fill(' ');
    break;
  case SHORT:
    res2.setf(ios_base::right, ios_base::adjustfield);
    res2.fill(' ');
    break;
  case FREE:
    break;
  }

  res2.width(out_form);

  res2 << inp_proc;
  std::string out(res2.str());
  if (out.size() != out_form && out_form > 0) {
    std::ostringstream msg("output string for value ", std::ostringstream::ate);
    msg << inp_proc << " of incorrect size, got length of " << out.size()
        << " instead of allowed length of " << out_form << ".";
    throw bdf_output_error(name, msg.str());
  }
  return out;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
