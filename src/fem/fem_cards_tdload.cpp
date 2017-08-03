/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `TDLOAD` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_tdload[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#ifdef max
#undef max
#endif // max

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

card const tdload::head("TDLOAD");

entry_type<long> const tdload::_form_NFIELD("NFIELD");
entry_type<long> const tdload::_form_ILREF("ILREF");
entry_type<long> const tdload::_form_CODNAM("CODNAM");
entry_type<long> const tdload::_form_CODTXT("CODTXT");
entry_type<std::string> const tdload::_form_SET_NAME(
    "SET_NAME", type_bounds::bound<std::string>(""));
entry_type<std::string> const tdload::_form_CONT("CONT");

tdload::tdload(vector<std::string> const &inp, size_t const len) {
    tdload::read(inp, len);
}

void tdload::read(vector<std::string> const &inp, size_t const len) {
    if (len < 5)
        throw errors::parse_error(
            "TDLOAD", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    if (NFIELD != 4) {
        ostringstream msg(
            "Only NFIELD values of 4 are supported, "
            "but got value of ",
            ostringstream::ate);
        msg << NFIELD;
        errors::parse_error("TDLOAD", msg.str());
    }
    ILREF = _form_ILREF(inp.at(2));
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
    };
    for (long i=0; i < (nltxt * 4); i += 4) {
        CONT.push_back(_form_CONT(
                           inp.at(i + 9), inp.at(i + 10),
                           inp.at(i + 11), inp.at(i + 12)));
        CONT.back().resize(nctxt, ' ');
    }
}

tdload::tdload() : tdload(0, -1, 0, {}) {}

tdload::tdload(long const NFIELD, long const ILREF, long const CODNAM,
               long const CODTXT, std::string const &SET_NAME,
               vector<std::string> const &CONT) :
        card(), NFIELD(NFIELD), ILREF(ILREF),
        CODNAM(CODNAM), CODTXT(CODTXT),
        SET_NAME(SET_NAME), CONT(CONT) {
    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    div_val = ldiv(CODTXT, 100);
    nltxt = div_val.quot;
    nctxt = div_val.rem;
}

tdload::tdload(long const ILREF, std::string const &SET_NAME,
               vector<std::string> const &CONT/*={}*/) :
        card(), NFIELD(4), ILREF(ILREF),
        SET_NAME(SET_NAME), CONT(CONT) {

    nlnam = true;
    ncnam = long(SET_NAME.size());
    CODNAM = 100 + ncnam;
    nltxt = long(CONT.size());
    nctxt = 0;
    if (CONT.size()>0) {
        for (auto &p : CONT)
            nctxt = max(nctxt, long(p.size()));
        for (auto &p : this->CONT)
            p.resize(nctxt, ' ');
    }
    CODTXT = (100 * nltxt) + nctxt;
}

tdload::tdload(long const NFIELD, long const ILREF, long const CODNAM,
               std::string const &SET_NAME) :
        tdload(NFIELD, ILREF, CODNAM, 0, SET_NAME, {}) {}

cards::__base::card const &tdload::operator() (
    long const NFIELD, long const ILREF, long const CODNAM, long const CODTXT,
    std::string const &SET_NAME, vector<std::string> const &CONT) {
    this->NFIELD = NFIELD;
    this->ILREF = ILREF;
    this->CODNAM = CODNAM;
    this->CODTXT = CODTXT;
    this->SET_NAME = SET_NAME;
    this->CONT = CONT;
    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    div_val = ldiv(CODTXT, 100);
    nltxt = div_val.quot;
    nctxt = div_val.rem;
    return *this;
}

cards::__base::card const &tdload::operator() (
    long const ILREF, std::string const &SET_NAME,
    vector<std::string> const &CONT/*={}*/) {
    nlnam = true;
    ncnam = long(SET_NAME.size());
    CODNAM = 100 + ncnam;
    nltxt = long(CONT.size());
    nctxt = 0;
    if (CONT.size()>0) {
        for (auto &p : CONT)
            nctxt = max(nctxt, long(p.size()));
        for (auto &p : this->CONT)
            p.resize(nctxt, ' ');
    }
    CODTXT = (100 * nltxt) + nctxt;
    return (*this)(4, ILREF, 100 + ncnam, CODTXT, SET_NAME, CONT);
}

cards::__base::card const &tdload::operator() (
    long const NFIELD, long const ILREF, long const CODNAM,
    std::string const &SET_NAME) {
    return (*this)(NFIELD, ILREF, CODNAM, 0, SET_NAME, {});
}

cards::types tdload::card_type() const {
    return types::TDLOAD;
};

ostream &tdload::put(ostream& os) const {
    if (ILREF == -1) return os;
    os << head.format()
       << _form_NFIELD.format(NFIELD) << _form_ILREF.format(ILREF)
       << _form_CODNAM.format(CODNAM) << _form_CODTXT.format(CODTXT) << endl;
    if (nlnam)
        os << fem::types::card().format()
           << _form_SET_NAME.format(SET_NAME, ncnam+8) << endl;
    for (auto p : CONT)
        os << fem::types::card().format()
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
