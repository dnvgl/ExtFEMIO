/**
   \file fem/fem_cards_gsetmemb.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GSETMEMB` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_gsetmemb[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <memory>
#include <algorithm>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef min
#undef min
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::types;
using namespace dnvgl::extfem::fem::cards;

fem::types::card const gsetmemb::head("GSETMEMB");

entry_type<long> const gsetmemb::_form_NFIELD("NFIELD");
entry_type<long> const gsetmemb::_form_ISREF("ISREF");
entry_type<long> const gsetmemb::_form_INDEX("INDEX");
entry_type<long> const gsetmemb::_form_ISTYPE("ISTYPE");
entry_type<long> const gsetmemb::_form_ISORIG("ISORIG");
entry_type<long> const gsetmemb::_form_IRMEMB("IRMEMB");

gsetmemb::gsetmemb(const vector<std::string> &inp, size_t const len) {
    read(inp, len);
}

void gsetmemb::read(const vector<std::string> &inp, size_t const len) {
    if (len < 7)
        throw errors::parse_error(
            "GSETMEMB", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    ISREF = _form_ISREF(inp.at(2));
    INDEX = _form_INDEX(inp.at(3));
    ISTYPE = gsetmemb::to_types(_form_ISTYPE(inp.at(4)));
    ISORIG = gsetmemb::to_origins(_form_ISORIG(inp.at(5)));
    IRMEMB.resize(NFIELD - 5);
    for (long i = 0; i < NFIELD - 5; i++)
        IRMEMB[i] = _form_IRMEMB(inp.at(6 + i));
}

gsetmemb::gsetmemb(void) :
        gsetmemb(-1, 0, 0, types::UNDEF_TYPE, origins::UNDEF_ORIGIN) {}

gsetmemb::gsetmemb(
    long const NFIELD, long const ISREF, long const INDEX, gsetmemb::types const ISTYPE,
    gsetmemb::origins const ISORIG, vector<long> const &IRMEMB/*={}*/) :
        card(), NFIELD(NFIELD), ISREF(ISREF), INDEX(INDEX),
        ISTYPE(ISTYPE), ISORIG(ISORIG), IRMEMB(IRMEMB) {}

gsetmemb::gsetmemb(
    long const ISREF, long const INDEX, gsetmemb::types const ISTYPE,
    gsetmemb::origins const ISORIG, vector<long> const &IRMEMB/*={}*/) :
        gsetmemb((long)IRMEMB.size() + 5, ISREF, INDEX,
                 ISTYPE, ISORIG, IRMEMB) {}

gsetmemb::gsetmemb(
    long const ISREF, gsetmemb::types const ISTYPE,
    gsetmemb::origins const ISORIG, vector<long> const &IRMEMB/*={}*/) :
        gsetmemb((long)IRMEMB.size() + 5, ISREF, 1,
                 ISTYPE, ISORIG, IRMEMB) {}

const fem::cards::types gsetmemb::card_type(void) const {
    return cards::types::GSETMEMB;
}

ostream &gsetmemb::put(ostream& os) const {
    list<int>::size_type cnt = 0;
    list<int>::size_type field = 0;
    int pos = 0;
    long index = INDEX;
    bool first = true;
    if (NFIELD == -1) return os;
    while (first || cnt < IRMEMB.size()) {
        first = false;
        if (lldiv(field, 1024).rem == 0) {
            if (field > 1) os << endl;
            os << gsetmemb::head.format()
               << _form_NFIELD.format(
                   static_cast<long>(
                       min(IRMEMB.size() - cnt + 5,
                           static_cast<vector<long int>::size_type>(1024))))
               << _form_ISREF.format(ISREF) << _form_INDEX.format(index++)
               << _form_ISTYPE.format(static_cast<long>(ISTYPE)) << endl
               << dnvgl::extfem::fem::types::card().format()
               << _form_ISORIG.format(static_cast<long>(ISORIG));
            field += 5;
            pos = 1;
        }
        if (pos++ == 4) {
            os << endl << dnvgl::extfem::fem::types::card().format();
            pos = 1;
        }
        if (cnt >= IRMEMB.size()) break;
        os << _form_IRMEMB.format(IRMEMB[cnt++]);
        field++;
    }
    os << endl;
    return os;
}

unordered_map<long, gsetmemb::types> const
gsetmemb::types_map({
        {1, gsetmemb::types::NODE_SET},
        {2, gsetmemb::types::ELEM_SET}});

unordered_map<long, gsetmemb::origins> const
gsetmemb::origins_map({
        {0, gsetmemb::origins::UNDEF_ORIGIN},
        {1, gsetmemb::origins::POINT_ORIGIN},
        {2, gsetmemb::origins::LINE_OR_CURVE_ORIGIN},
        {3, gsetmemb::origins::SURFACE_ORIGIN},
        {4, gsetmemb::origins::BODY_ORIGIN}});

gsetmemb::types gsetmemb::to_types(long const inp) {
    try {
        return gsetmemb::types_map.at(inp);
    } catch (out_of_range) {
        ostringstream msg("");
        msg << inp << ": Illegal value for ISTYPE." << endl;
        throw errors::parse_error(
            "GSETMEMB", msg.str());
    }
}

gsetmemb::origins gsetmemb::to_origins(long const inp) {
    try {
        return gsetmemb::origins_map.at(inp);
    } catch (out_of_range) {
        ostringstream msg("");
        msg << inp << ": Illegal value for ISORIG." << endl;
        throw errors::parse_error(
            "GSETMEMB", msg.str());
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
