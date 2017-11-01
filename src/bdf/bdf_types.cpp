/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran Bulk data entry types.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_bdf_types[]) =
        "@(#) $Id$";
}

#include <iomanip>
#include <locale>

#ifdef __GNUC__
#include "config.h"
#endif

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

using namespace dnvgl::extfem;
using namespace bdf::types;

istringstream base::conv;

base::base(const std::string &name) : name(name) {};

out_form_type base::out_form = out_form_type::SHORT;

ImbueHelper::ImbueHelper(const locale &loc) : base("") {
    conv.imbue(loc);
}

bdf_types ImbueHelper::type() const {
    return bdf_types::None;
}

std::string ImbueHelper::format(const void*) const {
    return "";
}

card::card(const std::string &name) : base(name) {}

bdf_types card::type() const {
    return bdf_types::None;
}

std::string card::format(const void* d) const {
    ostringstream outp;

    outp << resetiosflags(ios::adjustfield);
    switch (out_form) {
    case out_form_type::LONG:
        outp << setiosflags(ios::left) << setfill(' ')
            << setw(8) << (name + "*");
        break;
    case out_form_type::SHORT:
        outp << setiosflags(ios_base::left) << setfill(' ')
            << setw(8) << name;
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
}

std::string empty::format(const void* d) const {
    ostringstream outp;

    switch (out_form) {
    case out_form_type::LONG:
    case out_form_type::SHORT:
        outp << setfill(' ') << setw(long(out_form)) << " ";
        break;
    case out_form_type::FREE:
        break;
    }
    return outp.str();
}

rstring::rstring(const std::string &name) :
        cont(name) {}

bdf_types rstring::type() const {
    return bdf_types::None;
}

std::string rstring::format(const void*) const {
    ostringstream outp;

    switch (out_form) {
    case out_form_type::LONG:
    case out_form_type::SHORT:
        outp << setfill(' ') << setw(long(out_form)) << std::left << cont;
        break;
    case out_form_type::FREE:
        outp << cont;
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
