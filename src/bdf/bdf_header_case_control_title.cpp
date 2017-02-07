/**
   \file bdf/bdf_header_case_control_title.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for CASE TITLE

   Detailed description
   */

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_bdf_header_case_control_title[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

title::title(std::string const &title) :
name(title) {}

std::ostream &title::put(std::ostream &os) const {
    return os << "TITLE = " << this->name << std::endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
