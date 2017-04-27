/**
   \file fem/fem_cards_hsupstat.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `HSUPSTAT` cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_cards_hsupstat[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

card const hsupstat::head("HSUPSTAT");

entry_type<long> const hsupstat::_form_NFIELD("NFIELD");
entry_type<long> const hsupstat::_form_ISELTY("ISELTY");
entry_type<long> const hsupstat::_form_NIDOF("NIDOF");
entry_type<long> const hsupstat::_form_NRDOF("NRDOF");
entry_type<long> const hsupstat::_form_NBAND("NBAND");
entry_type<long> const hsupstat::_form_NELT("NELT");
entry_type<long> const hsupstat::_form_LINDEP("LINDEP");
entry_type<long> const hsupstat::_form_RELOADC("RELOADC");
entry_type<long> const hsupstat::_form_COMPLC("COMPLC");

hsupstat::hsupstat(const vector<std::string> &inp, size_t const len) {
    hsupstat::read(inp, len);
}

void hsupstat::read(const vector<std::string> &inp, size_t const len) {
    if (len < 10)
        throw errors::parse_error(
            "HSUPSTAT", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    ISELTY = _form_ISELTY(inp.at(2));
    NIDOF = _form_NIDOF(inp.at(3));
    NRDOF = _form_NRDOF(inp.at(4));
    NBAND = _form_NBAND(inp.at(5));
    NELT = _form_NELT(inp.at(6));
    LINDEP = _form_LINDEP(inp.at(7));
    RELOADC = _form_RELOADC(inp.at(8));
    COMPLC = _form_COMPLC(inp.at(9));
}

hsupstat::hsupstat() : hsupstat(-1, 0, 0, 0, 0, 0, 0, 0, 0) {}

hsupstat::hsupstat(long const NFIELD, long const ISELTY, long const NIDOF,
                   long const NRDOF, long const NBAND, long const NELT,
                   long const LINDEP, long const RELOADC, long const COMPLC) :
        card(), NFIELD(NFIELD), ISELTY(ISELTY), NIDOF(NIDOF), NRDOF(NRDOF),
        NBAND(NBAND), NELT(NELT), LINDEP(LINDEP), RELOADC(RELOADC),
        COMPLC(COMPLC) {}

cards::types hsupstat::card_type() const {
    return types::HSUPSTAT;
}

ostream &hsupstat::put(ostream& os) const {
    if (NFIELD == -1) return os;
    os << head.format()
       << _form_NFIELD.format(NFIELD) << _form_ISELTY.format(ISELTY)
       << _form_NIDOF.format(NIDOF) << _form_NRDOF.format(NRDOF) << endl
       << fem::types::card().format()
       << _form_NBAND.format(NBAND) << _form_NELT.format(NELT)
       << _form_LINDEP.format(LINDEP) << _form_RELOADC.format(RELOADC) << endl
       << fem::types::card().format()
       << _form_COMPLC.format(COMPLC) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
