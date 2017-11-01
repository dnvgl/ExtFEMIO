/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Read FE grouping from Nastran session file;

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_support_grouping_ses[]) =
        "@(#) $Id$";
}

#include "support/grouping.h"

using namespace dnvgl::extfem::support::GroupInfo;

Session::Session(std::istream const &inp) : grp_info() {}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_support_grouping --use-colour no)"
// End:
