/**
   \file bdf/bdf_cards_properties.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Base property capabilities for BDF.

   Detailed description
*/

#include "StdAfx.h"

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

namespace {
   const long cl1 = 1;
}

const entry_type<long> property::form_PID("PID", bound<long>(&cl1));

property::property(long const *PID) : card(), PID(PID) {
    this->property::check_data();
}

property::property(list<std::string> const &inp) : card(inp) {
    this->property::read(inp);
}

void property::read(std::list<std::string> const &inp) {
    auto pos = inp.begin();

    if (inp.size() < 2)
        throw errors::parse_error(
            "PARAMETER", "Illegal number of entries.");

    form_PID.set_value(PID, *(++pos));
}

void property::check_data() const {
    if (PID) property::form_PID.check(PID);
}

card const &property::operator() (list<std::string> const &inp) {
    this->property::read(inp);
    return *this;
}

card const &property::operator() (long const *PID) {
    this->PID(PID);
    this->property::check_data();
    return *this;
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
