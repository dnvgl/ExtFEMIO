/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Base property capabilities for BDF.

   Detailed description
*/

#include "extfemio_stdafx.h"

// ID:
namespace {
   char const cID_bdf_cards_properties[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "bdf/cards.h"

using namespace std;

using namespace dnvgl::extfem::bdf;
using namespace type_bounds;
using namespace cards::__base;

using types::entry_type;
using cards::format_entry;

namespace {
    auto const cl1 = make_shared<long>(1);
}

namespace {
    auto const bound_PID = make_shared<bound_unique<long>>(cl1);
}
entry_type<long> property::form_PID("PID", bound_PID);

property::property(list<std::string> const &inp) : card(inp) {
    this->property::read(inp);
}

property::property(long const *PID) : card(), PID(PID) {
    this->PID = form_PID.check(this->PID);
}

card const &property::operator() (long const *PID) {
    this->PID(PID);
    this->property::check_data();
    return *this;
}

card const &property::operator() (list<std::string> const &inp) {
    this->property::read(inp);
    return *this;
}

void property::collect_outdata(
    list<unique_ptr<format_entry> >&) const {
    NOT_IMPLEMENTED("Can't write write generic PROPERTY.");
}

void property::check_data() {
    this->PID = property::form_PID.check(this->PID);
}

void property::read(list<std::string> const &inp) {
    auto pos = inp.begin();

    if (inp.size() < 2)
        throw errors::parse_error(
            "PARAMETER", "Illegal number of entries.");

    form_PID.set_value(PID, *(++pos));
}

cards::types property::card_type() const {
    return types::PROPERTY;
}

void property::reset() {
    __base::card::reset();
    form_PID.reset();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test ;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
