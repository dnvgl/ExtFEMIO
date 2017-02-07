/**
   \file extfem_misc.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implementation of some base extfem functionality.

   Detailed description
*/

#include "StdAfx.h"
#include "extfem_misc.h"

// ID:
namespace {
    const char cID_extfem_misc[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "config.h"

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::__base;

outline::outline(void) {}

outline::~outline(void) {}

std::ostream &outline::operator<<(std::ostream &os) {
    return this->put(os);
}

std::ostream &dnvgl::extfem::__base::operator<<(std::ostream &os, outline const &val) {
    return val.put(os);
}

std::string dnvgl::extfem::version(void) {
    return "ExtFEMIO, Ver. " ExtFEMIO_VERSION;
}

std::string dnvgl::extfem::build_data(void) {
    return __DATE__ ", " __TIME__;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&make -C ../cbuild test"
// End:
