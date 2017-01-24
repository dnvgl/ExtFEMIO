/**
   \file fem/fem_cards_bsell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BSELL` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    char const cID_fem_cards_bsell[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
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

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

fem::types::card const bsell::head("BSELL");

entry_type<long> const bsell::_form_LC("LC");
entry_type<long> const bsell::_form_SUBNO("SUBNO");
entry_type<long> const bsell::_form_LLC("LLC");
entry_type<double> const bsell::_form_FACT("FACT");

bsell::bsell(std::vector<std::string> const &inp, size_t const &len) {
    read(inp, len);
}

void bsell::read(std::vector<std::string> const &inp, size_t const &len) {
    static const std::string empty(16, ' ');

    long tmp;

    if (len < 7)
        throw errors::parse_error(
            "BSELL", "Illegal number of entries.");

    auto pos = inp.begin();

    ++pos;

    LC = _form_LC(*(pos++));
    SUBNO = _form_SUBNO(*(pos++));

    pos++;
    pos++;
    size_t i{5};
    while (len > i) {
        i += 2;
        if (*pos == empty)
            break;
        tmp = _form_LLC(*pos++);
        if (tmp == 0) break;
        LLC.push_back(tmp);
        FACT.push_back(_form_FACT(*(pos++)));
    }
}

bsell::bsell(void) :
        bsell(-1, 0, {}, {}) {}

bsell::bsell(long const &LC,
             long const &SUBNO,
             std::vector<long> const &LLC,
             std::vector<double> const &FACT) :
        card(), LC(LC), SUBNO(SUBNO), LLC(LLC), FACT(FACT) {}

cards::__base::card const &bsell::operator()(
    long const &LC,
    long const &SUBNO,
    std::vector<long> const &LLC,
    std::vector<double> const &FACT) {
    this->LC = LC;
    this->SUBNO = SUBNO;
    this->LLC = LLC;
    this->FACT = FACT;
    return *this;
}

dnvgl::extfem::fem::cards::types const
bsell::card_type(void) const {
    return types::BSELL;
}

std::ostream &bsell::put(std::ostream& os) const {
    if (this->LC == -1) return os;
    os << bsell::head.format()
       << this->_form_LC.format(this->LC)
       << this->_form_SUBNO.format(this->SUBNO)
       << this->empty.format()
       << this->empty.format()
       << std::endl;
    for (size_t i = 0; i < this->LLC.size(); i+=2) {
        os << dnvgl::extfem::fem::types::card().format()
           << this->_form_LLC.format(this->LLC[i])
           << this->_form_FACT.format(this->FACT[i]);
        if (i+1 < this->LLC.size())
            os << this->_form_LLC.format(this->LLC[i+1])
               << this->_form_FACT.format(this->FACT[i+1]);
        os << std::endl;
    }
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
