/**
   \file bdf/bdf_header_case_control_subtitle.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation for BDF SUBTILE case control entry.

   Detailed description
   */

#include "StdAfx.h"

// ID:
namespace {
    const char cID_bdf_header_case_control_subtitle[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/header.h"

using namespace dnvgl::extfem::bdf::header::case_control;

subtitle::subtitle(std::string const &title) :
title(title) {}

std::ostream &subtitle::put(std::ostream &os) const {
    os << "SUBTITLE = " << this->title;
    return os << std::endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
