/**
   \file
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
    if (property::used_pid.find(*PID) != property::used_pid.end()) {
        throw errors::usage_error("PROPERTY", "Non unique id.");
    }
    this->property::check_data();
    property::used_pid.insert(*PID);
}

property::property(list<std::string> const &inp) : card(inp) {
    this->property::read(inp);
    if (property::used_pid.find(PID) != property::used_pid.end()) {
        throw errors::usage_error("PROPERTY", "Non unique id.");
    }
    property::used_pid.insert(PID);
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
    if (property::used_pid.find(PID) != property::used_pid.end()) {
        throw errors::usage_error("PROPERTY", "Non unique id.");
    }
    property::used_pid.insert(PID);
    return *this;
}

card const &property::operator() (long const *PID) {
    if (property::used_pid.find(*PID) != property::used_pid.end()) {
        throw errors::usage_error("PROPERTY", "Non unique id.");
    }
    property::used_pid.insert(*PID);
    this->PID(PID);
    this->property::check_data();
    return *this;
}

unordered_set<long> property::used_pid;

long property::max_id{0};

long property::nextId() {
    while (property::used_pid.find(++property::max_id) != property::used_pid.end()) {}
    used_pid.insert(property::max_id);
    return property::max_id;
}

void property::resetIds() {
    property::used_pid.clear();
    property::max_id = {0};
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
