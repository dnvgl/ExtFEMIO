// Copyright © 2015 by DNV GL SE

// Purpose: Definitions for Nastran Bulk data entry types.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

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
#ifdef __GNUC__
using namespace boost;
#else
using namespace std;
#endif

#include "bdf_types.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;
using namespace bdf::string;
#ifdef __GNUC__
using namespace boost;
#endif

const regex entry_type<::std::deque<int>>::int_re("[[:digit:]]*");

::std::deque<int>*
entry_type<::std::deque<int>>::operator() (const std::string &inp) const {
  ::std::deque<int> *value =  new ::std::deque<int>();
  std::string sval = ::bdf::string::string(inp).trim();
  if (! regex_match(sval, int_re)) {
    std::string msg(name + ":illegal input (""");
    msg += sval;
    msg += """), no integer in list\n";
    throw bdf_types_error(msg);
  }
  for (::std::string::iterator pos = sval.begin();
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
// compile-command: "make -C .. check -j8"
// End:
