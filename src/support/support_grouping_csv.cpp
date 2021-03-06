/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Read FE grouping information from NAPA Provided CSV file.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_support_grouping_csv[]) =
        "@(#) $Id$";
}

#include "support/grouping.h"
#include "support/errors.h"

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
using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

CSV::CSV(istream &inp) {
    std::string line;
    CElemInfo info;

    while (getline(inp, line)) {
        try {
            process_line(line, &info);
            (*this)[info.id] = info;
        } catch (errors::unreadable_error) {
        }
    }
}

void CSV::process_line(std::string const &line,
                       dnvgl::extfem::support::GroupInfo::CElemInfo *data) {
    istringstream inp(line);
    istringstream proc;
    std::string segment;
    proc.imbue(locale::classic());

    if (getline(inp, segment, ';')) {
        proc.str(segment);
        proc >> data->id;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        proc.str(segment);
        proc.seekg(0) >> data->nnodes;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        data->napa_obj = segment;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        data->func_name = segment;
    } else
        throw errors::unreadable_error(
            "Read CSV",
            "Can't read line """ + line + """");
    if (getline(inp, segment, ';')) {
        data->grade = segment;
    }
    if (getline(inp, segment, ';')) {
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
