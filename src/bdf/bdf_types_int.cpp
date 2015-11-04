// Copyright © 2015 by DNV GL SE

// Definitions for Nastran Bulk data entry types.

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

#include <sstream>

#include "bdf/types.h"
#include "bdf/errors.h"

using namespace std;
using namespace ::dnvgl;
using namespace extfem;
using bdf::types::entry_type;

entry_type<long>::entry_type(std::string name) :
  bdf::types::base(name), bounds(*(std::make_unique< bdf::type_bounds::bound<long> >())) {};

entry_type<long>::entry_type(std::string name, bdf::type_bounds::bound<long> _bounds) :
  bdf::types::base(name), bounds(_bounds) {};

const
#if HAVE_BOOST_REGEX_HPP
boost::regex
#else
std::regex
#endif
entry_type<long>::int_re(
  "[[:space:]]*[\\+-]?[[:digit:]]+[[:space:]]*");

long *entry_type<long>::operator() (const std::string &inp) const {
  auto sval = extfem::string::string(inp).trim();
  auto *value = new long();
  if (sval.length() == 0) {
    if (this->bounds.does_allow_empty())
      return nullptr;
    if (!this->bounds.has_default())
      throw errors::int_error(name, "empty entry without default");
    *value = this->bounds.get_default();
    return value;
  } else {
    if (! regex_match(inp, int_re)) {
      std::string msg("illegal input (""");
      msg += inp;
      msg += """), no integer";
      throw errors::int_error(name, msg);
    }
    istringstream buffer(sval);
    buffer >> *value;
  }
  if (!this->bounds.in_bounds(value)) {
    std::string msg("boundary condition violated (");
    throw errors::int_error(name, msg + name + ")\n(""" + inp + """)");
  }
  return value;
}

std::string entry_type<long>::format(const std::unique_ptr<long> &inp) const {

  if (!inp)
    return bdf::types::empty().format(nullptr);

  std::ostringstream res;
  switch (out_form) {
  case LONG:
    res.setf(ios_base::right, ios_base::adjustfield);
    res.fill(' ');
    break;
  case SHORT:
    res.setf(ios_base::right, ios_base::adjustfield);
    res.fill(' ');
    break;
  case FREE:
    break;
  }
  res.width(out_form);

  res << *inp;
  std::string out(res.str());
  if (out.size() != static_cast<size_t>(out_form) && out_form > 0) {
    std::ostringstream msg("output string for value ", std::ostringstream::ate);
    msg << *inp << " of incorrect size, got length of " << out.size()
        << " instead of allowed length of " << out_form << ".";
    throw errors::int_error(name, msg.str());
  }
  return out;
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
