/**
   \file fem_cards_helper_geoprop.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Code for fem::cards::__base::geoprop helper class.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_helper_geoprop[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "fem/cards.h"

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace cards;

fem::types::entry_type<long> const
cards::__base::geoprop::_form_GEONO("GEONO");

unordered_set<long> cards::__base::geoprop::used_geono;
long cards::__base::geoprop::geono_maxset = 0;

void cards::__base::geoprop::set_geono(long const GEONO/*=0*/) {
    if (GEONO < 0) {
        this->GEONO = GEONO;
        return;
    }
    if (GEONO == 0) {
        for (long i = geono_maxset + 1; i < numeric_limits<long>::max(); i++) {
            if (!used_geono.count(i)) {
                geono_maxset = i;
                used_geono.insert(GEONO);
                this->GEONO = i;
                return;
            }
        }
    }
    if (used_geono.count(GEONO)) {
        ostringstream msg("GEONO ", ostringstream::ate);
        msg << GEONO << " value used twice.";
        throw errors::usage_error("GEONO", msg.str());
    }
    used_geono.insert(GEONO);
    this->GEONO = GEONO;
}

cards::__base::geoprop::geoprop() :
        card(), GEONO(-1) {}

cards::__base::geoprop::geoprop(long const GEONO) :
        card() {
    set_geono(GEONO);
}

cards::__base::geoprop::geoprop(
    vector<std::string> const &inp, size_t const len) {
    read(inp, len);
}

void cards::__base::geoprop::read(
    vector<std::string> const &inp, size_t const len) {
    if (len < 2)
        throw errors::parse_error(
            "CARD", "Illegal number of entries.");

    set_geono(_form_GEONO(inp.at(1)));
}

cards::__base::card const &cards::__base::geoprop::operator() (
    vector<std::string> const &inp, size_t const len) {
    read(inp, len);
    this->read(inp, len);
    return *this;
}

void cards::__base::geoprop::reset_geono() {
    geono_maxset = 0;
    used_geono.clear();
    beam_prop::reset_geono();
    transno::reset_transno();
    eccno::reset_eccno();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
