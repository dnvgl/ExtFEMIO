/**
   \file support_grouping_csv.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Read FE grouping information from NAPA Provided CSV file.

   Detailed description
*/

// ID:
namespace {
   char const cID_support_grouping_csv[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include <vector>
#include <iostream>

#include "support/grouping.h"
#include "support/errors.h"

using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

void CSV::process_line(std::string const &line,
                       dnvgl::extfem::support::GroupInfo::elem_info *data) {
    std::istringstream inp(line);
    std::istringstream proc;
    std::string segment;

    if (std::getline(inp, segment, ';')) {
        proc.str(segment);
        proc >> data->id;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (std::getline(inp, segment, ';')) {
        proc.str(segment);
        proc.seekg(0) >> data->nnodes;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (std::getline(inp, segment, ';')) {
        proc.str(segment);
        proc.seekg(0) >> data->napa_obj;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (std::getline(inp, segment, ';')) {
        proc.str(segment);
        proc.seekg(0) >> data->func_name;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (std::getline(inp, segment, ';')) {
        proc.str(segment);
        proc.seekg(0) >> data->grade;
    }
    if (std::getline(inp, segment, ';')) {
        proc.str(segment);
        proc.seekg(0) >> data->yield;
    }
}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
