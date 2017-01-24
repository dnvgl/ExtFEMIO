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
   const char cID_fem_file[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "fem/file.h"

#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem::fem::input;

fem_file::fem_file(std::istream &inp) :
   cur_line(""), data(inp), last_comment("") {
}

// Return all input file lines belonging to next FEM card.
size_t fem_file::get(vector<std::string> &res) {
    size_t i{0};
    while (cur_line.size() == 0)
        std::getline(data, cur_line);
    do {
        // if line not empty and not comment line add line to result std::set.
        if (cur_line.length() > 0)
            try {
                res.at(i).assign(cur_line);
            } catch (out_of_range) {
                res.emplace_back(cur_line);
            }
        ++i;
        // if not EOF, read next line
        // loop while no next card starts and file has still content.
    } while (std::getline(this->data, this->cur_line) &&
             (i == 0 || cur_line[0] == ' '));
    return i;
}

// Return size of input FEM file.
std::streampos fem_file::size(void) {
    // save current position in file
    auto cur_pos = data.tellg();

    // jump to end of file
    data.seekg(0, std::ios::end);
    // determine position if file as file size
    auto fileSize = data.tellg();

    // jump back to original position if file
    data.seekg(cur_pos);

    return fileSize;
}

// Return position in input FEM file.
std::streampos fem_file::pos(void) {
    return data.tellg();
}

bool fem_file::eof(void) {
    return data.eof();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
