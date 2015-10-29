// Copyright © 2015 by DNV GL SE

// Purpose: Processing of string entries from Nastran BDF files.

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

#include <sstream>

#include "bdf/types.h"

using namespace std;
using bdf::types::entry_type;

entry_type<std::string>::entry_type(std::string name) :
  bdf::types::base(name), bounds(bdf::type_bounds::bound<std::string>()) {}

entry_type<std::string>::entry_type(std::string name, bdf::type_bounds::bound<std::string> bounds) :
  bdf::types::base(name), bounds(bounds) {}

std::string
*entry_type<std::string>::operator() (const std::string &inp) const {
  auto sval = bdf::string::string(inp).trim();

  if (sval.length() == 0)
    sval = bounds.get_default();

  if (!bounds.is_allowed(sval))
    throw bdf_str_error(name, "!" + sval + "! Value not in list of allowed values.");

  return new std::string(sval);
}

std::string entry_type<std::string>::format(const std::string &inp) const {
  std::ostringstream res;
  switch (out_form) {
  case LONG:
    res.setf(ios_base::left, ios_base::adjustfield);
    res.fill(' ');
    break;
  case SHORT:
    res.setf(ios_base::left, ios_base::adjustfield);
    res.fill(' ');
    break;
  case FREE:
    break;
  }
  res.width(out_form);

  res << inp;
  std::string out(res.str());
  if (out.size() != out_form && out_form > 0) {
    std::ostringstream msg("output string for value ", std::ostringstream::ate);
    msg << inp << " of incorrect size, got length of " << out.size()
        << " instead of allowed length of " << out_form << ".";
    throw bdf_int_error(name, msg.str());
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
