/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Process Sesam FEM files.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include <stdexcept>

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_file[]) =
        "@(#) $Id$";
}

#include "fem/file.h"

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

using namespace dnvgl::extfem::fem::input;

fem_file::fem_file(istream &inp) :
   cur_line(""), data(inp), last_comment("") {
}

// Return all input file lines belonging to next FEM card.
size_t fem_file::get(vector<std::string> &res) {
    size_t i{0};
    while (cur_line.size() == 0)
        getline(data, cur_line);
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
    } while (getline(this->data, this->cur_line) &&
             (i == 0 || cur_line[0] == ' '));
    return i;
}

/**
 * \brief Return size of input FEM file.
 * \return size of current fem file
 */
streampos fem_file::size() const {
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

/**
 * \brief Return position in input FEM file.
 * \return current stream position
 */
streampos fem_file::pos() const {
    return data.tellg();
}

/**
 * \brief Check for EOF on data.
 * \return is eof of data reached?
 */
bool fem_file::eof() const {
    return data.eof();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
