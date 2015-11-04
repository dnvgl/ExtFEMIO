// Copyright © 2015 by DNV GL SE

// Purpose: String helper functions.

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

#include "extfem_string.h"

// http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
extfem::string::string extfem::string::string::trim(const std::string &whitespace) {
  const auto strBegin = this->find_first_not_of(whitespace);
  if (strBegin == std::string::npos)
    return extfem::string::string(""); // no content

  const auto strEnd = this->find_last_not_of(whitespace);
  const auto strRange = strEnd - strBegin + 1;

  return this->substr(strBegin, strRange);
}

extfem::string::string extfem::string::string::upper() {
  transform(this->begin(), this->end(), this->begin(), ::toupper);
  return *this;
}

extfem::string::string extfem::string::string::lower() {
  transform(this->begin(), this->end(), this->begin(), ::tolower);
  return *this;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
