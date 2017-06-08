/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for boundaries for BDF types.

   Classes help ensure values in correct range.
*/
// ReSharper disable once CppUnusedIncludeDirective
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_type_bounds[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/types.h"

using namespace dnvgl::extfem::bdf::type_bounds;

bool __base::type_bound::has_min() const {
    return _has_min;
}

void __base::type_bound::got_min() {
    _has_min = true;
}

bool __base::type_bound::has_max() const {
    return _has_max;
}

void __base::type_bound::got_max() {
    _has_max = true;
}

void __base::type_bound::got_default() {
    _has_default = true;
}

bool __base::type_bound::has_default() const {
    return _has_default;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_bounds --use-colour no)"
// End:
