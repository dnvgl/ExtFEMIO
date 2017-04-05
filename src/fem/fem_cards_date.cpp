/**
   \file fem/fem_cards_date.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `DATE` cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_cards_date[] _EXTFEMIO_UNUSED = 
        "@(#) $Id$";
}

#ifdef max
#undef max
#endif // max

#include <memory>

#include "fem/cards.h"
#include "fem/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

card const date::head("DATE");

entry_type<long> const date::_form_TYPE("TYPE");
entry_type<long> const date::_form_SUBTYPE("SUBTYPE");
entry_type<long> const date::_form_NRECS("NRECS");
entry_type<long> const date::_form_NBYTE("NBYTE");
entry_type<std::string> const date::_form_CONT("CONT");

date::date(std::vector<std::string> const &inp, size_t const len) {
    date::read(inp, len);
}

void date::read(std::vector<std::string> const &inp, size_t const len) {

    if (len < 9)
        throw errors::parse_error(
            "DATE", "Illegal number of entries.");

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

date::date() :
        date(-1, 0, 0, 0, {}) {}

date::date(long const TYPE, long const SUBTYPE,
           long const NRECS, long const NBYTE,
           std::vector<std::string> const &CONT) :
        TYPE(TYPE), SUBTYPE(SUBTYPE), NRECS(NRECS),
        NBYTE(NBYTE), CONT(CONT) {
    for (auto &p : this->CONT)
        p.resize(NBYTE-8, ' ');
}

date::date(long const TYPE, long const SUBTYPE,
           std::vector<std::string> const &CONT) :
        card(),
        TYPE(TYPE), SUBTYPE(SUBTYPE), CONT(CONT) {
    NRECS = static_cast<long>(this->CONT.size());
    NBYTE = 0;
    for (auto &p : this->CONT)
        NBYTE = std::max(NBYTE, long(p.size()));
    for (auto &p : this->CONT)
        p.resize(NBYTE, ' ');
    NBYTE += 8;
}

cards::types date::card_type() const {
    return types::DATE;
};

std::ostream &date::put(std::ostream& os) const {
    if (TYPE == -1) return os;
    os << head.format()
       << _form_TYPE.format(TYPE)
       << _form_SUBTYPE.format(SUBTYPE)
       << _form_NRECS.format(NRECS)
       << _form_NBYTE.format(NBYTE) << std::endl;
    for (auto p : CONT)
        os << fem::types::card().format()
           << _form_CONT.format(p, NBYTE)
           << std::endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
