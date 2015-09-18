// Copyright © 2015 by DNV GL SE

// Purpose: Process BDF files.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "stdafx.h"

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "bdf_file.h"

#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>

using namespace std;
using namespace bdf::input;

namespace {
  const char initVals[3] = { '+', '*', ' ' };
}
const set<char> bdf_file::cont_chars(initVals, initVals + 3);

bdf_file::bdf_file(istream &inp) : data(inp) {
  data.imbue(locale(locale("C"), new line_reader()));
  data >> cur_line;
}

deque<std::string>& bdf_file::get() {
  deque<std::string> *res = new(deque<std::string>);
  do {
    if (cur_line.length() > 0 && cur_line[0] != '$') res->push_back(cur_line);
    data >> cur_line;
  } while(!data.eof() && (res->size() == 0 || cont_chars.find(cur_line[0]) != cont_chars.end()));
  return *res;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C .. check -j 8"
// End:
