/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

   Detailed description
*/
// ReSharper disable once CppUnusedIncludeDirective
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf_types_int[]) =
        "@(#) $Id$";
}

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

#ifdef HAVE_BOOST_REGEX_HPP
using boost::regex;
#else
using std::regex;
#endif

const regex dnvgl::extfem::bdf::types::int_re(
   "[[:space:]]*[\\+-]?[[:digit:]]+[[:space:]]*");

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_types --use-colour no)"
// coding: utf-8
// End:
