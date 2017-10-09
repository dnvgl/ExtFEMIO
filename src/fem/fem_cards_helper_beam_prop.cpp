/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Implementing fem::cards::__base::beam_prop class.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_fem_cards_helper_beam_prop[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace cards;

unordered_set<long> cards::__base::beam_prop::used_gbeamg;
unordered_set<long> cards::__base::beam_prop::used_cross_desc;

cards::__base::beam_prop::beam_prop(
    vector<std::string> const &inp, size_t const len) {
    geoprop::read(inp, len);
}

cards::__base::beam_prop::beam_prop(
    vector<std::string> const &inp, size_t const len, bool const is_gbeamg) {
    read(inp, len, is_gbeamg);
}

cards::__base::beam_prop::beam_prop(
    long const GEONO, bool const is_gbeamg/*=false*/) {
    set_geono(GEONO, is_gbeamg);
}

void cards::__base::beam_prop::reset_geono() {
    used_gbeamg.clear();
    used_cross_desc.clear();
}

void cards::__base::beam_prop::set_geono(
    long const GEONO/*=0*/, bool const is_gbeamg/*=false*/) {
    if (GEONO < 0) {
        return geoprop::set_geono(GEONO);
    }
    if (GEONO == 0) {
        geoprop::set_geono(GEONO);
        if (is_gbeamg)
            used_gbeamg.insert(GEONO);
        else
            used_cross_desc.insert(GEONO);
        return;
    }
    if (is_gbeamg) {
        if (used_cross_desc.count(GEONO)){
            this->GEONO = GEONO;
        } else {
            geoprop::set_geono(GEONO);
        }
        used_gbeamg.insert(GEONO);
    } else {
        if (used_gbeamg.count(GEONO)){
            this->GEONO = GEONO;
        } else {
            geoprop::set_geono(GEONO);
        }
        used_cross_desc.insert(GEONO);;
    }
}

void cards::__base::beam_prop::read(
    vector<std::string> const &inp, size_t const len, bool const is_gbeamg) {
    if (len < 2)
        throw errors::parse_error(
            "CARD", "Illegal number of entries.");

    set_geono(_form_GEONO(inp.at(1)), is_gbeamg);
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make test"
// End:
