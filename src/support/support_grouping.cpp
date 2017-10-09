/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implement base functionality for processing grouping information for
       FE file import.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_support_grouping[]) =
        "@(#) $Id$";
}

#include "support/grouping.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

CElemInfo::CElemInfo() :
        CElemInfo(-1, 0, "", "", "", 0.) {}

CElemInfo::CElemInfo(long const &id) :
        CElemInfo(id, 0, "", "", "", 0.) {}

CElemInfo::CElemInfo(long const &id, long const &nnodes,
                     std::string const &napa_obj, std::string const &func_name,
                     std::string const &grade, double const &yield) :
        id(id), nnodes(nnodes), napa_obj(napa_obj), func_name(func_name),
        grade(grade), yield(yield) {}

double const &grp_info::yield(long const &id) {
    return (*this)[id].yield;
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
