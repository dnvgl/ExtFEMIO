/**
   \file support_grouping_ses.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Read FE grouping from Nastran session file;

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_support_grouping_ses[] _EXTFEMIO_UNUSED =
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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
