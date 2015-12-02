/**
   \file fem/fem_file.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Process Sesam FEM files.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "fem/file.h"

#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>

using namespace ::std;
using namespace ::dnvgl::extfem::fem::input;

fem_file::fem_file(istream &inp) :
   data(inp), last_comment(""), eof(false) {
   data.imbue(locale(locale("C"), new line_reader()));
   data >> cur_line;
}

// Return all input file lines belonging to next FEM card.
void fem_file::get(deque<std::string> &res) {
   res.clear();
   do {
      // if line not empty and not comment line add line to result set.
      if (cur_line.length() > 0)
         res.push_back(cur_line);
      // if not EOF, read next line
      if (!data.eof()) data >> cur_line;
      else eof = true;
      // loop while no next card starts and file has still content.
   } while (!data.eof() &&
            (res.size() == 0 || cur_line[0] == ' '));
}

// Return size of input FEM file.
std::streampos fem_file::size(void) {
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

// Return position in input FEM file.
streampos fem_file::pos(void) {
   return data.tellg();
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
