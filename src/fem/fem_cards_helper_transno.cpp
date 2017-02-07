/**
   \file fem_cards_helper_transno.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Implementing the fem::cards::__base::transno class.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_helper_transno[]_EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "fem/cards.h"

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

fem::types::entry_type<long> const
cards::__base::transno::_form_TRANSNO("TRANSNO");

unordered_set<long> cards::__base::transno::used_transno;
long cards::__base::transno::transno_maxset = 0;

void cards::__base::transno::set_transno(long const TRANSNO/*=0*/) {
    if (TRANSNO < 0) {
        this->TRANSNO = TRANSNO;
        return;
    }
    if (TRANSNO == 0) {
        for (long i = transno_maxset + 1; i < numeric_limits<long>::max(); i++) {
            if (!used_transno.count(i)) {
                transno_maxset = i;
                used_transno.insert(TRANSNO);
                this->TRANSNO = i;
                return;
            }
        }
    }
    if (used_transno.count(TRANSNO)) {
        ostringstream msg("TRANSNO ", ostringstream::ate);
        msg << TRANSNO << " value used twice.";
        throw errors::usage_error("TRANSNO", msg.str());
    }
    used_transno.insert(TRANSNO);
    this->TRANSNO = TRANSNO;
}

cards::__base::transno::transno(void) :
        card(), TRANSNO(-1) {}

cards::__base::transno::transno(long const TRANSNO) :
        card() {
    set_transno(TRANSNO);
}

cards::__base::transno::transno(
    vector<std::string> const &inp, size_t const len) {
    read(inp, len);
}

void cards::__base::transno::read(
    vector<std::string> const &inp, size_t const len) {
    if (len < 2)
        throw errors::parse_error(
            "CARD", "Illegal number of entries.");

    set_transno(_form_TRANSNO(inp.at(1)));
}

// cards::__base::card const &cards::__base::transno::operator() (
//     vector<std::string> const &inp, size_t const len) {
//     read(inp, len);
//     this->read(inp, len);
//     return *this;
// }

void cards::__base::transno::reset_transno(void) {
    transno_maxset = 0;
    used_transno.clear();
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
