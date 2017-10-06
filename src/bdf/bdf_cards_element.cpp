/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Common definitions for Nastran BDF element describing cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_bdf_cards_element[]) =
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

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;
using namespace cards::__base;

using bdf::types::entry_type;

namespace {
    auto const cl0 = make_shared<long>(0);
    auto const cl1 = make_shared<long>(1);
}

namespace {
    auto const bound_EID = make_shared<bound_unique<long>>(cl1, nullptr, cl0);
}

entry_type<long> element::form_EID("EID", bound_EID);

element::element(list<std::string> const &inp) : card(inp) {
    this->element::read(inp);
}

element::element(long *EID) : card(), EID(EID) {
    this->element::check_data();
}

card const &element::operator() (long const *EID) {
    this->EID(EID);
    this->element::check_data();
    return *this;
}

card const &element::operator() (list<std::string> const &inp) {
    this->element::read(inp);
    return *this;
}

void element::collect_outdata(
    list<unique_ptr<format_entry> >&) const {
    NOT_IMPLEMENTED("Can't write write generic ELEMENT.");
}

void element::check_data() {
    this->EID = element::form_EID.check(this->EID);
}

void element::read(list<std::string> const &inp) {
    auto pos = inp.begin();

    if (inp.size() < 2)
        throw errors::parse_error(
        "ELEMENT", "Illegal number of entries.");

    form_EID.set_value(EID, *(++pos));
}

cards::types element::card_type() const {
    return types::ELEMENT;
}

void element::reset() {
    __base::card::reset();
    form_EID.reset();
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
