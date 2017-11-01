/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Handling entry_type classes.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_bdf_entry_type[]) =
        "@(#) $Id$";
}

#include "bdf/types.h"

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

using namespace dnvgl::extfem::bdf;
using namespace types;

template <typename _Ty>
const bdf_types entry_type<_Ty>::_type = bdf_types::None;

template <>
const bdf_types entry_type<long>::_type = bdf_types::Int;

template <>
const bdf_types entry_type<double>::_type = bdf_types::Float;

template <>
const bdf_types entry_type<std::string>::_type = bdf_types::Str;

template <>
const bdf_types entry_type<std::complex<double>>::_type = bdf_types::Complex;

template <>
const bdf_types entry_type<std::vector<int>>::_type = bdf_types::List;

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_types --use-colour no;
//    ../../cbuild/tests/test_bdf_bounds --use-colour no)"
// End:
