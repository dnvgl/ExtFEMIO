/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `TDSUPNAM` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_fem_cards_tdsupnam[]) =
        "@(#) $Id$";
}

#ifdef max
#undef max
#endif // max

#include "fem/cards.h"
#include "fem/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

card const tdsupnam::head("TDSUPNAM");

entry_type<long> const tdsupnam::_form_NFIELD("NFIELD");
entry_type<long> const tdsupnam::_form_IHREF("IHREF");
entry_type<long> const tdsupnam::_form_CODNAM("CODNAM");
entry_type<long> const tdsupnam::_form_CODTXT("CODTXT");
entry_type<std::string> const tdsupnam::_form_SUP_NAME("SUP_NAME");
entry_type<std::string> const tdsupnam::_form_CONT("CONT");

tdsupnam::tdsupnam(vector<std::string> const &inp, size_t const len) {
    tdsupnam::read(inp, len);
}

void tdsupnam::read(vector<std::string> const &inp, size_t const len) {
    if (len < 9)
        throw errors::parse_error(
            "TDSUPNAM", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    if (NFIELD != 4) {
        ostringstream msg(
            "Only NFIELD values of 4 are supported, "
            "but got value of ",
            ostringstream::ate);
        msg << NFIELD;
        errors::parse_error("TDSUPNAM", msg.str());
    }
    IHREF = _form_IHREF(inp.at(2));
    CODNAM = _form_CODNAM(inp.at(3));
    CODTXT = _form_CODTXT(inp.at(4));

    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    div_val = ldiv(CODTXT, 100);
    nltxt = div_val.quot;
    nctxt = div_val.rem;

    if (nlnam) {
        SUP_NAME = _form_SUP_NAME(
            inp.at(5), inp.at(6), inp.at(7), inp.at(8));
        SUP_NAME.resize(ncnam, ' ');
    }
    for (long i=0; i < (nltxt * 4); i += 4) {
        CONT.push_back(_form_CONT(
                           inp.at(i + 9), inp.at(i + 10),
                           inp.at(i + 11), inp.at(i + 12)));
        CONT.back().resize(nctxt, ' ');
    }
}

tdsupnam::tdsupnam() : tdsupnam(-1, 0, 0, 0, {}, {}) {}

tdsupnam::tdsupnam(long const NFIELD, long const IHREF, long const CODNAM,
                   long const CODTXT, std::string const &SUP_NAME,
                   vector<std::string> const &CONT) :
        card(), NFIELD(NFIELD), IHREF(IHREF),
        CODNAM(CODNAM), CODTXT(CODTXT),
        SUP_NAME(SUP_NAME), CONT(CONT) {
    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    div_val = ldiv(CODTXT, 100);
    nltxt = div_val.quot;
    nctxt = div_val.rem;
}

tdsupnam::tdsupnam(long const IHREF, std::string const &SUP_NAME,
                   vector<std::string> const &CONT) :
        card(), NFIELD(4), IHREF(IHREF),
        SUP_NAME(SUP_NAME), CONT(CONT) {

    nlnam = true;
    ncnam = long(SUP_NAME.size());
    CODNAM = 100 + ncnam;
    nltxt = long(CONT.size());
    nctxt = 0;
    for (auto &p : CONT)
        nctxt = max(nctxt, long(p.size()));
    for (auto &p : this->CONT)
        p.resize(nctxt, ' ');
    CODTXT = (100 * nltxt) + nctxt;
}

tdsupnam::tdsupnam(long const NFIELD, long const IHREF, long const CODNAM,
                   std::string const &SUP_NAME) :
        card() , NFIELD(NFIELD), IHREF(IHREF),
        CODNAM(CODNAM), CODTXT(0),
        SUP_NAME(SUP_NAME), CONT() {
    auto div_val = ldiv(CODNAM, 100);
    nlnam = div_val.quot != 0;
    ncnam = div_val.rem;
    nltxt = 0;
    nctxt = 0;
}

tdsupnam::tdsupnam(long const IHREF, std::string const &SUP_NAME) :
        card() , NFIELD(4), IHREF(IHREF),
        CODTXT(0),
        SUP_NAME(SUP_NAME), CONT() {
    nlnam = true;
    ncnam = long(SUP_NAME.size());
    CODNAM = 100 + ncnam;
    nltxt = 0;
    nctxt = 0;
}

cards::types tdsupnam::card_type() const {
    return types::TDSUPNAM;
}

ostream &tdsupnam::put(ostream& os) const {
    if (NFIELD == -1) return os;
    os << head.format()
       << _form_NFIELD.format(NFIELD) << _form_IHREF.format(IHREF)
       << _form_CODNAM.format(CODNAM) << _form_CODTXT.format(CODTXT) << endl;
    if (nlnam)
        os << fem::types::card().format()
           << _form_SUP_NAME.format(SUP_NAME, ncnam+8) <<endl;
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
