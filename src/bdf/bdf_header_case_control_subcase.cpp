/**
   \file bdf/bdf_header_case_control_subcase.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for CASE SUBCASE

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_subcase[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

long subcase::max_n = 0;

subcase::subcase(long const &n) :
n(n) {
    max_n = std::max(n, max_n);
}

subcase::subcase() :
n(max_n + 1) {
    max_n += 1;
}

std::ostream &subcase::put(std::ostream &os) const {
    return os << "SUBCASE = " << this->n << std::endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
