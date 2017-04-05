/**
   \file bdf/bdf_header_case_control_begin_bulk.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of the BDF case cotrol "BEGIN BULK" entries.

   Detailed description
   */

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_begin_bulk[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

begin_bulk::begin_bulk() {}

std::ostream &begin_bulk::put(std::ostream &os) const {
    return os << "BEGIN BULK" << std::endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
