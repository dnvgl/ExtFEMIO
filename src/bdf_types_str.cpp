// Copyright © 2015 by DNV GL SE

// Purpose: Processing of string entries from Nastran BDF files.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_types.h"

using namespace std;
using namespace bdf::types;
using namespace bdf::type_bounds;
using namespace bdf::string;

bdf_str::bdf_str(::std::string name) :
  bdf_type_base(name), bounds(str()) {}

bdf_str::bdf_str(::std::string name, str bounds) :
  bdf_type_base(name), bounds(bounds) {}

::std::string *bdf_str::operator() (::std::string inp) {
  std::string sval = bdf::string::string(inp).trim();

  if (sval.length() == 0)
    sval = bounds.get_default();

  if (!bounds.is_allowed(sval))
    throw bdf_str_error(name, "Value not in list of allowed values.");

  return new ::std::string(sval);
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
