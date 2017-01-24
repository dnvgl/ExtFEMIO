/**
   \file fem/fem_cards_text.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `TEXT` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    char const cID_fem_cards_text[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
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

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

fem::types::card const text::head("TEXT");

entry_type<long> const text::_form_TYPE("TYPE");
entry_type<long> const text::_form_SUBTYPE("SUBTYPE");
entry_type<long> const text::_form_NRECS("NRECS");
entry_type<long> const text::_form_NBYTE("NBYTE");
entry_type<std::string> const text::_form_CONT("CONT");

text::text(vector<std::string> const &inp, size_t const &len) {
    read(inp, len);
}

void text::read(vector<std::string> const &inp, size_t const &len) {
    if (len < 9)
        throw errors::parse_error(
            "TEXT", "Illegal number of entries.");

    TYPE = _form_TYPE(inp.at(1));
    SUBTYPE = _form_SUBTYPE(inp.at(1));
    NRECS = _form_NRECS(inp.at(3));
    NBYTE = _form_NBYTE(inp.at(4));

    std::string pos_0;
    std::string pos_1;
    std::string pos_2;
    std::string pos_3;
    size_t index;
    index = 4;
    for (long i = 0; i < NRECS; i++) {
        try {
            if (++index < len)
                pos_0.assign(inp.at(index));
            else
                pos_0.assign(8, ' ');
            if (++index < len)
                pos_1.assign(inp.at(index));
            else
                pos_1.assign(8, ' ');
            if (++index < len)
                pos_2.assign(inp.at(index));
            else
                pos_2.assign(8, ' ');
            if (++index < len)
                pos_3.assign(inp.at(index));
            else
                pos_3.assign(8, ' ');
        } catch (std::out_of_range) {
        }
        std::string cont = _form_CONT(
            pos_0, pos_1, pos_2, pos_3);
        cont.resize(NBYTE, ' ');
        CONT.push_back(cont);
    }
}

text::text(void) :
        text(-1, 0, 0, 0, {}) {}

text::text(long const &TYPE, long const &SUBTYPE,
           long const &NRECS, long const &NBYTE,
           std::vector<std::string> const &CONT) :
        card(),
        TYPE(TYPE), SUBTYPE(SUBTYPE), NRECS(NRECS),
        NBYTE(NBYTE), CONT(CONT) {
    for (auto &p : this->CONT)
        p.resize(NBYTE-8, ' ');
}

text::text(long const &TYPE, long const &SUBTYPE,
           std::vector<std::string> const &CONT) :
        card(),
        TYPE(TYPE), SUBTYPE(SUBTYPE), CONT(CONT) {
    NRECS = static_cast<long>(this->CONT.size());
    NBYTE = 0;
    for (auto &p : this->CONT)
        NBYTE = std::max(NBYTE, (long)p.size());
    for (auto &p : this->CONT)
        p.resize(NBYTE, ' ');
    NBYTE += 8;
}

cards::__base::card const &text::operator() (
    long const &TYPE, long const &SUBTYPE,
    long const &NRECS, long const &NBYTE,
    std::vector<std::string> const &CONT) {
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
    long const &TYPE, long const &SUBTYPE,
    std::vector<std::string> const &CONT) {
    this->TYPE = TYPE;
    this->SUBTYPE = SUBTYPE;
    this->CONT = CONT;
    NRECS = static_cast<long>(this->CONT.size());
    NBYTE = 0;
    for (auto &p : this->CONT)
        NBYTE = std::max(NBYTE, (long)p.size());
    for (auto &p : this->CONT)
        p.resize(NBYTE, ' ');
    NBYTE += 8;
    return *this;
}

cards::types const
text::card_type(void) const { return types::TEXT; };

std::ostream &text::put(std::ostream& os) const {
    if (this->TYPE == -1) return os;
    os << text::head.format()
       << this->_form_TYPE.format(this->TYPE)
       << this->_form_SUBTYPE.format(this->SUBTYPE)
       << this->_form_NRECS.format(this->NRECS)
       << this->_form_NBYTE.format(this->NBYTE) << std::endl;
    for (auto p : this->CONT)
        os << dnvgl::extfem::fem::types::card().format()
           << this->_form_CONT.format(p, this->NBYTE)
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
