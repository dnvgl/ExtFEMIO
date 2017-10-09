/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Implemention of LOAD for case control.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf_header_case_control_load[]) =
        "@(#) $Id$";
}

#include "bdf/header.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace dnvgl::extfem::bdf::header::case_control;

load::load(long const n) : n(n) {}

std::ostream &load::put(std::ostream &os) const {
    os.imbue(std::locale::classic());
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
