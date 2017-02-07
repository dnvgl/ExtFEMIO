/**
   \file fem/fem_cards_tdsetnam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `TDSETNAM` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_tdsetnam[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#ifdef max
#undef max
#endif // max

#include <memory>

#include "fem/cards.h"
#include "fem/types.h"
#include "extfem_misc.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace dnvgl::extfem::fem::cards;

fem::types::card const tdsetnam::head("TDSETNAM");

entry_type<long> const tdsetnam::_form_NFIELD("NFIELD");
entry_type<long> const tdsetnam::_form_ISREF("ISREF");
entry_type<long> const tdsetnam::_form_CODNAM("CODNAM");
entry_type<long> const tdsetnam::_form_CODTXT("CODTXT");
entry_type<std::string> const tdsetnam::_form_SET_NAME("SET_NAME");
entry_type<std::string> const tdsetnam::_form_CONT("CONT");

tdsetnam::tdsetnam(vector<std::string> const &inp, size_t const len) {
    read(inp, len);
}

void tdsetnam::read(vector<std::string> const &inp, size_t const len) {
    if (len < 9)
        throw errors::parse_error(
            "TDSETNAM", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    if (NFIELD != 4) {
        ostringstream msg(
            "Only NFIELD values of 4 are supported, "
            "but got value of ",
            ostringstream::ate);
        msg << NFIELD;
        errors::parse_error("TDSETNAM", msg.str());
    }
    ISREF = _form_ISREF(inp.at(2));
    CODNAM = _form_CODNAM(inp.at(3));
    CODTXT = _form_CODTXT(inp.at(4));

    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    div_val = ldiv(CODTXT, 100);
    nltxt = div_val.quot;
    nctxt = div_val.rem;

    if (nlnam) {
        SET_NAME = _form_SET_NAME(
            inp.at(5), inp.at(6), inp.at(7), inp.at(8));
        SET_NAME.resize(ncnam, ' ');
    }
    for (long i=0; i < (nltxt * 4); i += 4) {
        CONT.push_back(_form_CONT(
                           inp.at(i + 9), inp.at(i + 10),
                           inp.at(i + 11), inp.at(i + 12)));
        CONT.back().resize(nctxt, ' ');
    }
}

tdsetnam::tdsetnam(void) :
        tdsetnam(-1, 0, 0, 0, "", {}) {}

tdsetnam::tdsetnam(long const NFIELD, long const ISREF, long const CODNAM,
                   long const CODTXT, std::string const &SET_NAME,
                   vector<std::string> const &CONT) :
        card(), NFIELD(NFIELD), ISREF(ISREF),
        CODNAM(CODNAM), CODTXT(CODTXT),
        SET_NAME(SET_NAME), CONT(CONT) {
    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    div_val = ldiv(CODTXT, 100);
    nltxt = div_val.quot;
    nctxt = div_val.rem;
}

tdsetnam::tdsetnam(long const ISREF, std::string const &SET_NAME,
                   vector<std::string> const &CONT) :
        card(), NFIELD(4), ISREF(ISREF), SET_NAME(SET_NAME), CONT(CONT) {

    nlnam = true;
    ncnam = (long)SET_NAME.size();
    CODNAM = 100 + ncnam;
    nltxt = (long)CONT.size();
    nctxt = 0;
    for (auto &p : CONT)
        nctxt = max(nctxt, (long)p.size());
    for (auto &p : this->CONT)
        p.resize(nctxt, ' ');
    CODTXT = (100 * nltxt) + nctxt;
}

tdsetnam::tdsetnam(long const NFIELD, long const ISREF, long const CODNAM,
                   std::string const &SET_NAME) :
        card() , NFIELD(NFIELD), ISREF(ISREF), CODNAM(CODNAM), CODTXT(0),
        SET_NAME(SET_NAME), CONT() {
    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    nltxt = 0;
    nctxt = 0;
}

tdsetnam::tdsetnam(long const ISREF, std::string const &SET_NAME) :
        card() , NFIELD(4), ISREF(ISREF), CODTXT(0), SET_NAME(SET_NAME),
        CONT() {
    nlnam = true;
    ncnam = (long)SET_NAME.size();
    CODNAM = 100 + ncnam;
    nltxt = 0;
    nctxt = 0;
}

fem::cards::types const tdsetnam::card_type(void) const {
    return types::TDSETNAM;
};

ostream &tdsetnam::put(ostream& os) const {
    if (NFIELD == -1) return os;
    os << tdsetnam::head.format()
       << _form_NFIELD.format(NFIELD) << _form_ISREF.format(ISREF)
       << _form_CODNAM.format(CODNAM) << _form_CODTXT.format(CODTXT) << endl;
    if (nlnam)
        os << dnvgl::extfem::fem::types::card().format()
           << _form_SET_NAME.format(SET_NAME, ncnam+8) << endl;
    for (auto p : CONT)
        os << dnvgl::extfem::fem::types::card().format()
           << _form_CONT.format(p, nctxt+8) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
