/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GSETMEMB` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_fem_cards_gsetmemb[]) =
        "@(#) $Id$";
}

#include <algorithm>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

#ifdef min
#undef min
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

card const gsetmemb::head("GSETMEMB");

entry_type<long> const gsetmemb::_form_NFIELD("NFIELD");
entry_type<long> const gsetmemb::_form_ISREF("ISREF");
entry_type<long> const gsetmemb::_form_INDEX("INDEX");
entry_type<long> const gsetmemb::_form_ISTYPE("ISTYPE");
entry_type<long> const gsetmemb::_form_ISORIG("ISORIG");
entry_type<long> const gsetmemb::_form_IRMEMB("IRMEMB");

gsetmemb::gsetmemb(const vector<std::string> &inp, size_t const len) {
    gsetmemb::read(inp, len);
}

void gsetmemb::read(const vector<std::string> &inp, size_t const len) {
    if (len < 7)
        throw errors::parse_error(
            "GSETMEMB", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    ISREF = _form_ISREF(inp.at(2));
    INDEX = _form_INDEX(inp.at(3));
    ISTYPE = to_types(_form_ISTYPE(inp.at(4)));
    ISORIG = to_origins(_form_ISORIG(inp.at(5)));
    IRMEMB.resize(NFIELD - 5);
    for (long i = 0; i < NFIELD - 5; i++)
        IRMEMB[i] = _form_IRMEMB(inp.at(6 + i));
}

gsetmemb::gsetmemb() :
        gsetmemb(-1, 0, 0, types::UNDEF_TYPE, origins::UNDEF_ORIGIN) {}

gsetmemb::gsetmemb(
    long const NFIELD, long const ISREF, long const INDEX, types const ISTYPE,
    origins const ISORIG, vector<long> const &IRMEMB/*={}*/) :
        card(), NFIELD(NFIELD), ISREF(ISREF), INDEX(INDEX),
        ISTYPE(ISTYPE), ISORIG(ISORIG), IRMEMB(IRMEMB) {}

gsetmemb::gsetmemb(
    long const ISREF, long const INDEX, types const ISTYPE,
    origins const ISORIG, vector<long> const &IRMEMB/*={}*/) :
        gsetmemb(long(IRMEMB.size()) + 5, ISREF, INDEX,
                 ISTYPE, ISORIG, IRMEMB) {}

gsetmemb::gsetmemb(
    long const ISREF, types const ISTYPE,
    origins const ISORIG, vector<long> const &IRMEMB/*={}*/) :
        gsetmemb(long(IRMEMB.size()) + 5, ISREF, 1,
                 ISTYPE, ISORIG, IRMEMB) {}

cards::types gsetmemb::card_type() const {
    return cards::types::GSETMEMB;
}

ostream &gsetmemb::put(ostream& os) const {
    vector<int>::size_type cnt = 0;
    vector<int>::size_type field = 0;
    int pos = 0;
    long index = INDEX;
    bool first = true;
    if (NFIELD == -1) return os;
    while (first || cnt < IRMEMB.size()) {
        first = false;
        if (lldiv(field, 1024).rem == 0) {
            if (field > 1) os << endl;
            os << head.format()
               << _form_NFIELD.format(
                   static_cast<long>(
                       min(IRMEMB.size() - cnt + 5,
                           static_cast<vector<long int>::size_type>(1024))))
               << _form_ISREF.format(ISREF) << _form_INDEX.format(index++)
               << _form_ISTYPE.format(static_cast<long>(ISTYPE)) << endl
               << fem::types::card().format()
               << _form_ISORIG.format(static_cast<long>(ISORIG));
            field += 5;
            pos = 1;
        }
        if (pos++ == 4) {
            os << endl << fem::types::card().format();
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
        {1, types::NODE_SET},
        {2, types::ELEM_SET}});

unordered_map<long, gsetmemb::origins> const
gsetmemb::origins_map({
        {0, origins::UNDEF_ORIGIN},
        {1, origins::POINT_ORIGIN},
        {2, origins::LINE_OR_CURVE_ORIGIN},
        {3, origins::SURFACE_ORIGIN},
        {4, origins::BODY_ORIGIN}});

gsetmemb::types gsetmemb::to_types(long const inp) {
    try {
        return types_map.at(inp);
    } catch (out_of_range) {
        ostringstream msg("");
        msg << inp << ": Illegal value for ISTYPE." << endl;
        throw errors::parse_error(
            "GSETMEMB", msg.str());
    }
}

gsetmemb::origins gsetmemb::to_origins(long const inp) {
    try {
        return origins_map.at(inp);
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
