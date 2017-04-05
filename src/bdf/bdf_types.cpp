/**
   \file bdf/bdf_types.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_types[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <iomanip>
#include <locale>

#ifdef __GNUC__
#include "config.h"
#endif

#include "bdf/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace bdf::types;

std::istringstream base::conv;

base::base(const std::string &name) : name(name) {};

base::~base() {}

out_form_type base::out_form = out_form_type::SHORT;

imbue_helper::imbue_helper(const std::locale &loc) : base("") {
    conv.imbue(loc);
}

bdf_types imbue_helper::type() const {
    return bdf_types::None;
}

std::string imbue_helper::format(const void*) const {
    return "";
}

card::card(const std::string &name) : base(name) {}

bdf_types card::type() const {
    return bdf_types::None;
}

/// std::set input and output locale for conv and outp
static imbue_helper _imbue_helper(std::locale::classic());

std::string card::format(const void* d) const {
    std::ostringstream outp;

    outp << resetiosflags(std::ios::adjustfield);
    switch (out_form) {
    case out_form_type::LONG:
        outp << setiosflags(std::ios::left) << std::setfill(' ')
            << std::setw(8) << (name + "*");
        break;
    case out_form_type::SHORT:
        outp << setiosflags(std::ios_base::left) << std::setfill(' ')
            << std::setw(8) << name;
        break;
    case out_form_type::FREE:
        outp << name;
        break;
    }

    return outp.str();
}

empty::empty() : base("<empty>") {}

bdf_types empty::type() const {
    return bdf_types::None;
};

std::string empty::format(const void* d) const {
    std::ostringstream outp;

    switch (out_form) {
    case out_form_type::LONG:
    case out_form_type::SHORT:
        outp << std::setfill(' ') << std::setw(long(out_form)) << " ";
        break;
    case out_form_type::FREE:
        break;
    }
    return outp.str();
}

// Local Variables:
// mode: c++
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// coding: utf-8
// End:
