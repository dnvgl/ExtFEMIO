/**
   \file bdf_cards_element.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Common definitions for Nastran BDF element describing cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    char const cID_bdf_cards_element[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

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
using namespace bdf;

using types::entry_type;
using namespace type_bounds;

using namespace cards;
using namespace cards::__base;

namespace {
    const long cl1 = 1;
}

bdf::types::card element::head = bdf::types::card("CBAR");

const entry_type<long> element::form_EID("EID", bound<long>(&cl1));

element::element(std::list<std::string> const &inp) :
card(inp) {
    this->element::read(inp);
}

element::element(long const *EID) : card(), EID(EID) {}

void element::collect_outdata(
    std::list<std::unique_ptr<format_entry> >&) const {
    throw std::not_implemented(__FILE__, __LINE__, "can't write write generic ELEMENT.");
}

void element::read(std::list<std::string> const &inp) {
    auto pos = inp.begin();

    if (inp.size() < 2)
        throw errors::parse_error(
        "ELEMENT", "Illegal number of entries.");

    ++pos;
    form_EID.set_value(EID, *(pos++));
}

cards::types element::card_type() const {
    return types::ELEMENT;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
