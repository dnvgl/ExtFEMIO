/**
   \file fem/fem_types.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for SESAM FEM data entry types.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_types[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "config.h"

#include "fem/types.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::fem::types;

__base::b_type::b_type(const std::string &name) : name(name) {}

std::istringstream __base::b_type::conv;

/// std::set input and output locale for conv
static __base::imbue_helper _imbue_helper(std::locale::classic());

__base::imbue_helper::imbue_helper(std::locale const &loc) : b_type("") {
    conv.imbue(loc);
}

fem_types __base::imbue_helper::type(void) const {
    return fem_types::None;
}

std::string __base::imbue_helper::format(void const*) const {
    return "";
}

card::card(std::string const &name) : __base::b_type(name) {}

card::card(void) : __base::b_type("") {}

std::string card::format() const {
    std::ostringstream res;
    res.setf(std::ios_base::left, std::ios_base::adjustfield);
    res.fill(' ');
    res.width(8);
    res << name;
    return res.str();
}

empty::empty(void) : __base::b_type("") {}

fem_types empty::type(void) const {return fem_types::None;}

std::string empty::format() const {
    std::ostringstream res;
    res.fill(' ');
    res.width(16);
    res << "            0.00";
    return res.str();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
