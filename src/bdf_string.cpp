// Copyright © 2015 by DNV GL SE

// Purpose: String helper functions.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_string.h"

// http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
::std::string bdf_string::string::trim(const ::std::string &str,
                                              const ::std::string &whitespace) {
  const auto strBegin = str.find_first_not_of(whitespace);
  if (strBegin == ::std::string::npos)
    return ""; // no content

  const auto strEnd = str.find_last_not_of(whitespace);
  const auto strRange = strEnd - strBegin + 1;

  return str.substr(strBegin, strRange);
}

::std::string bdf_string::string::upper(const ::std::string &inp) {
  auto res(inp);
  transform(res.begin(), res.end(), res.begin(), ::toupper);
  return res;
}

::std::string bdf_string::string::lower(const ::std::string &inp) {
  auto res(inp);
  transform(res.begin(), res.end(), res.begin(), ::tolower);
  return res;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check"
// End:
