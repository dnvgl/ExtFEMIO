/**
   \file bdf/bdf_cards_bar_prop.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF PBAR and PBARL cards.

   Detailed description
*/
#include "StdAfx.h"
#include "extfem_misc.h"

// ID:
namespace {
   const char cID_bdf_cards_bar_prop[] _EXTFEMIO_UNUSED =
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

namespace {
   static const long cl1 = 1;
}

using namespace dnvgl::extfem::bdf;

using types::entry_type;
using namespace type_bounds;

using namespace dnvgl::extfem::bdf::cards::__base;

const entry_type<long> bar_prop::form_PID("PID", bound<long>(&cl1));
const entry_type<long> bar_prop::form_MID("MID", bound<long>(
    &cl1, nullptr, nullptr, true));

bar_prop::bar_prop(const std::list<std::string> &inp) :
card(inp) {}

const dnvgl::extfem::bdf::cards::types
bar_prop::card_type(void) const {
    return types::BAR_PROP;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
