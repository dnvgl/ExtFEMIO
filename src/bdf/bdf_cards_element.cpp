/**
   \file bdf_cards_element.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Common definitions for Nastran BDF element describing cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_bdf_cards_element[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <sstream>
#include <functional>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::bdf;

using dnvgl::extfem::bdf::types::entry_type;
using namespace dnvgl::extfem::bdf::type_bounds;

using namespace dnvgl::extfem::bdf::cards;
using namespace dnvgl::extfem::bdf::cards::__base;

namespace {
    static const long cl1 = 1;
}

bdf::types::card element::head = bdf::types::card("CBAR");

const entry_type<long> element::form_EID("EID", bound<long>(&cl1));

element::element(std::list<std::string> const &inp) :
card(inp) {
    this->read(inp);
}

element::element(long const *EID) : card(), EID(EID) {}

void element::collect_outdata(
    std::list<std::unique_ptr<format_entry> >&) const {
    throw errors::error("ELEMENT", "can't write write generic ELEMENT.");
    return;
}

void element::read(std::list<std::string> const &inp) {
    auto pos = inp.begin();

    if (inp.size() < 2)
        throw errors::parse_error(
        "ELEMENT", "Illegal number of entries.");

    ++pos;
    form_EID.set_value(EID, *(pos++));
}

const dnvgl::extfem::bdf::cards::types
element::card_type(void) const {
    return types::ELEMENT;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
