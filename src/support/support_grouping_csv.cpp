/**
   \file support_grouping_csv.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Read FE grouping information from NAPA Provided CSV file.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_support_grouping_csv[] _EXTFEMIO_UNUSED = 
        "@(#) $Id$";
}

#include "support/grouping.h"
#include "support/errors.h"

using namespace std;
using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

CSV::CSV(std::istream &inp) {
    std::string line;
    elem_info info;

    while (getline(inp, line)) {
        try {
            process_line(line, &info);
            (*this)[info.id] = info;
        } catch (errors::unreadable_error) {
        }
    }
}

void CSV::process_line(std::string const &line,
                       dnvgl::extfem::support::GroupInfo::elem_info *data) {
    istringstream inp(line);
    istringstream proc;
    std::string segment;
    proc.imbue(std::locale::classic());

    if (getline(inp, segment, ';')) {
        // data->id = std::atol(segment.c_str());
        proc.str(segment);
        proc >> data->id;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        // data->nnodes = std::atol(segment.c_str());
        proc.str(segment);
        proc.seekg(0) >> data->nnodes;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        data->napa_obj = segment;
        // proc.str(segment);
        // proc.seekg(0) >> data->napa_obj;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        data->func_name = segment;
        // proc.str(segment);
        // proc.seekg(0) >> data->func_name;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        data->grade = segment;
        // proc.str(segment);
        // proc.seekg(0) >> data->grade;
    }
    if (getline(inp, segment, ';')) {
        //data->yield = std::atof(segment.c_str());
        proc.str(segment);
        proc.seekg(0) >> data->yield;
    }
}


// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_support_grouping --use-colour no)"
// End:
