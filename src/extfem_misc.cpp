/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of some base extfem functionality.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"
#include "config.h"

// ID:
namespace {
    const char cID_extfem_misc[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

// ReSharper disable once CppUnusedIncludeDirective
#include "config.h"

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::__base;

std::ostream &outline::operator<<(std::ostream &os) const {
    return this->put(os);
}

std::not_implemented::not_implemented(
    const char* fname, const size_t& line, const char* error/*=nullptr*/) {
    ostringstream msg("", ostringstream::ate);
    if (line != 0 && strlen(fname) > 0)
        msg << fname << ":" << line << ":";
    if (error != nullptr)
        msg << error << " ";
    msg << "Functionality not yet implemented!";
    errorMessage = msg.str();
}

const char* std::not_implemented::what() const _EXTFEMIO_NOEXCEPT {
    return errorMessage.c_str();
}

std::ostream &operator<<(std::ostream &os, outline const &val) {
    return val.put(os);
}

std::string dnvgl::extfem::version() {
    return "ExtFEMIO, Ver. " ExtFEMIO_VERSION;
}

std::string dnvgl::extfem::build_data() {
    return __DATE__ ", " __TIME__;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
