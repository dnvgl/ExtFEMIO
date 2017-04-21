/**
   \file fem/fem_type_bounds.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Implementation of type bounds for Seasam FEM IO.

   Detailed description
   */
// ReSharper disable once CppUnusedIncludeDirective
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_type_bounds[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "fem/type_bounds.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem::type_bounds;

base::~base() {};

bool base::has_min() const {
    return _has_min;
}

void base::got_min() {
    _has_min = true;
}

bool base::has_max() const {
    return _has_max;
}

void base::got_max() {
    _has_max = true;
}

void base::got_default() {
    _has_default = true;
}


base::base() :
_has_min(false), _has_max(false), _has_default(false) {}

bool base::has_default() const {
    return _has_default;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
