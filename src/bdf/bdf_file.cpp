// Copyright © 2015 by DNV GL SE

// Purpose: Process BDF files.

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

#include "bdf/file.h"

#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>

using namespace ::std;
using namespace ::dnvgl::extfem::bdf::input;

namespace {
  const char initVals[3] = { '+', '*', ' ' };
}
const set<char> bdf_file::cont_chars(initVals, initVals + 3);


bdf_file::bdf_file(istream &inp) :
  data(inp), last_comment(""), eof(false) {
  data.imbue(locale(locale("C"), new line_reader()));
  data >> cur_line;
}

// Return all input file lines belonging to next BDF card.
deque<std::string>& bdf_file::get() {
  deque<std::string> *res = new(deque<std::string>);
  do {
    // if line not empty and not comment line add line to result set.
    if (cur_line.length() > 0 && cur_line[0] != '$')
      res->push_back(cur_line);
    // If line is comment save content to special member
    else if (cur_line.length() > 0 && cur_line[0] == '$')
      last_comment = cur_line;
    // if not EOF, read next line
    if (!data.eof()) data >> cur_line;
    else eof = true;
  // loop while no next card starts and file has still content.
  } while (!data.eof() &&
           (res->size() == 0 ||
            cont_chars.find(cur_line[0]) != cont_chars.end()));
  return *res;
}

// Return size of input BDF file.
std::streampos bdf_file::size(void) {
  // save current position in file
  auto cur_pos = data.tellg();

  // jump to end of file
  data.seekg(0, ios::end);
  // determine position if file as file size
  auto fileSize = data.tellg();

  // jump back to original position if file
  data.seekg(cur_pos);

  return fileSize;
}

// Return position in input BDF file.
streampos bdf_file::pos(void) {
  return data.tellg();
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
