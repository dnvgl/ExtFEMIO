/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Process BDF files.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_bdf_file[]) =
        "@(#) $Id$";
}

#include "bdf/file.h"
#include "extfem_string.h"

#include <list>

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::bdf::input;

const set<char> bdf_file::cont_chars({'+', '*', ' '});

bdf_file::bdf_file(istream &inp) :
        cur_line(""), data(inp) {}

// Return all input file lines belonging to next BDF card.
void bdf_file::get(list<std::string> &res) {
    if (!res.empty()) res.clear();
    do {}
    while (cur_line.length() == 0 &&
           getline(data, cur_line));

    if (cur_line[0] == '$') {
        do {
            res.push_back(string::string(cur_line).trim("\n"));
        } while (getline(this->data, this->cur_line) &&
                 cur_line.size() != 0 && cur_line[0] == '$');
        return;
    }
    do {
        // if line not empty and not comment line add line to result std::set.
        if (cur_line.length() > 0) {
            if (cur_line[0] != '$')
                res.push_back(cur_line);
            // If line is comment save content to special member
            else
                cerr << "comment during processing recored; ignored"
                     << endl;
        }
        // if not EOF, read next line
        // loop while no next card starts and file has still content.
    } while (getline(this->data, this->cur_line) &&
             (res.size() == 0 ||
              cont_chars.find(cur_line[0]) != cont_chars.end()));
}

bool bdf_file::eof() const {
    return data.eof();
}

// Return size of input BDF file.
streampos bdf_file::size() const {
    // save current position in file
    auto const cur_pos = data.tellg();

    // jump to end of file
    data.seekg(0, ios::end);
    // determine position if file as file size
    auto const fileSize = data.tellg();

    // jump back to original position if file
    data.seekg(cur_pos);

    return fileSize;
}

// Return position in input BDF file.
streampos bdf_file::pos() const {
    return data.tellg();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//  (make -C ../../cbuild test ;
//   ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
