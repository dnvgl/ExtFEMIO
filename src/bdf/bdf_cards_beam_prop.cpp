/**
   \file bdf/bdf_cards_beam_prop.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF PBEAM and PBEAML cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_beam_prop[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"

#include <cstdlib>
#include <memory>

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem::bdf;

using dnvgl::extfem::bdf::types::entry_type;
using namespace dnvgl::extfem::bdf::type_bounds;

using namespace dnvgl::extfem::bdf::cards::__base;

beam_base::beam_base(const std::list<std::string> &inp) :
__base::card(inp) {}

const dnvgl::extfem::bdf::cards::types
beam_base::card_type(void) const {
    return types::BEAM_BASE;
}

beam_prop::beam_prop(const std::list<std::string> &inp) :
beam_base(inp) {}

const dnvgl::extfem::bdf::cards::types
beam_prop::card_type(void) const {
    return types::BEAM_PROP;
}

namespace {
    static const long cl1 = 1;
}

const entry_type<long> beam_base::form_PID(
    "PID", bound<long>(&cl1));

const entry_type<long> beam_base::form_MID(
    "MID", bound<long>(&cl1, nullptr, nullptr, true));

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
