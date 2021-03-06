/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `TEXT` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards_text[]) =
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

card const text::head("TEXT");

entry_type<long> const text::_form_TYPE("TYPE");
entry_type<long> const text::_form_SUBTYPE("SUBTYPE");
entry_type<long> const text::_form_NRECS("NRECS");
entry_type<long> const text::_form_NBYTE("NBYTE");
entry_type<std::string> const text::_form_CONT("CONT");

text::text(vector<std::string> const &inp, size_t const len) :
        card(types::TEXT) {
    text::read(inp, len);
}

void text::read(vector<std::string> const &inp, size_t const len) {
    if (len < 9)
        throw errors::parse_error(
            "TEXT", "Illegal number of entries.");

    TYPE = _form_TYPE(inp.at(1));
    SUBTYPE = _form_SUBTYPE(inp.at(2));
    NRECS = _form_NRECS(inp.at(3));
    NBYTE = _form_NBYTE(inp.at(4));

    for (size_t i = 0; i < static_cast<size_t>(NRECS * 4); i += 4) {
        CONT.push_back(_form_CONT(
                           inp.at(5 + i), inp.at(6 + i),
                           inp.at(7 + i), inp.at(8 + i)));
        CONT.back().resize(NBYTE, ' ');
    }
}

text::text() : text(-1, 0, 0, 0, {}) {}

text::text(long const TYPE, long const SUBTYPE, long const NRECS,
           long const NBYTE, vector<std::string> const &CONT) :
        card(types::TEXT),
        TYPE(TYPE), SUBTYPE(SUBTYPE), NRECS(NRECS),
        NBYTE(NBYTE), CONT(CONT) {
    for (auto &p : this->CONT)
        p.resize(NBYTE-8, ' ');
}

text::text(long const TYPE, long const SUBTYPE,
           vector<std::string> const &CONT) :
        card(types::TEXT),
        TYPE(TYPE), SUBTYPE(SUBTYPE), CONT(CONT) {
    NRECS = static_cast<long>(this->CONT.size());
    NBYTE = 0;
    for (auto &p : this->CONT)
        NBYTE = max(NBYTE, long(p.size()));
    for (auto &p : this->CONT)
        p.resize(NBYTE, ' ');
    NBYTE += 8;
}

cards::__base::card const &text::operator() (
    long const TYPE, long const SUBTYPE, long const NRECS, long const NBYTE,
    vector<std::string> const &CONT) {
    this->TYPE = TYPE;
    this->SUBTYPE = SUBTYPE;
    this->NRECS = NRECS;
    this->NBYTE = NBYTE;
    this->CONT = CONT;
    for (auto &p : this->CONT)
        p.resize(NBYTE-8, ' ');
    return *this;
}

cards::__base::card const &text::operator() (
    long const TYPE, long const SUBTYPE, vector<std::string> const &CONT) {
    this->TYPE = TYPE;
    this->SUBTYPE = SUBTYPE;
    this->CONT = CONT;
    NRECS = static_cast<long>(this->CONT.size());
    NBYTE = 0;
    for (auto &p : this->CONT)
        NBYTE = max(NBYTE, long(p.size()));
    for (auto &p : this->CONT)
        p.resize(NBYTE, ' ');
    NBYTE += 8;
    return *this;
}

ostream &text::put(ostream& os) const {
    if (TYPE == -1) return os;
    os << head.format()
       << _form_TYPE.format(TYPE) << _form_SUBTYPE.format(SUBTYPE)
       << _form_NRECS.format(NRECS) << _form_NBYTE.format(NBYTE) << endl;
    for (auto const p : CONT)
        os << fem::types::card().format()
           << _form_CONT.format(p, NBYTE) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
