/**
   \file bdf/bdf_header_case_control_load.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implemention of LOAD for case control.

   Detailed description
   */

#include "StdAfx.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_load[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

load::load(long const &n) : n(n) {}

std::ostream &load::put(std::ostream &os) const {
    os << "LOAD = " << this->n;
    return os << std::endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
