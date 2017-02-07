/**
   \file fem/fem_cards_bsell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BSELL` cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_bsell[] _EXTFEMIO_UNUSED =
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

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;
using namespace cards;

fem::types::card const bsell::head("BSELL");

entry_type<long> const bsell::_form_LC("LC");
entry_type<long> const bsell::_form_SUBNO("SUBNO");
entry_type<long> const bsell::_form_LLC("LLC");
entry_type<double> const bsell::_form_FACT("FACT");

bsell::bsell(vector<std::string> const &inp, size_t const len) {
    read(inp, len);
}

void bsell::read(vector<std::string> const &inp, size_t const len) {
    static const std::string empty(16, ' ');

    long tmp;

    if (len < 7)
        throw errors::parse_error(
            "BSELL", "Illegal number of entries.");

    LC = _form_LC(inp.at(1));
    SUBNO = _form_SUBNO(inp.at(2));

    for (size_t i{5}; i < len; i += 2) {
        if (inp.at(i) == empty) break;
        tmp = _form_LLC(inp.at(i));
        if (tmp == 0) break;
        LLC.push_back(tmp);
        FACT.push_back(_form_FACT(inp.at(i + 1)));
    }
}

bsell::bsell(void) :
        bsell(-1, 0, {}, {}) {}

bsell::bsell(
    long const LC, long const SUBNO, vector<long> const &LLC,
    vector<double> const &FACT) :
        card(), LC(LC), SUBNO(SUBNO), LLC(LLC), FACT(FACT) {}

cards::__base::card const &bsell::operator()(
    long const LC, long const SUBNO, vector<long> const &LLC,
    vector<double> const &FACT) {
    this->LC = LC;
    this->SUBNO = SUBNO;
    this->LLC = LLC;
    this->FACT = FACT;
    return *this;
}

fem::cards::types const bsell::card_type(void) const {
    return types::BSELL;
}

ostream &bsell::put(ostream& os) const {
    if (LC == -1) return os;
    os << bsell::head.format()
       << _form_LC.format(LC) << _form_SUBNO.format(SUBNO)
       << empty.format() << empty.format() << endl;
    for (size_t i{0}; i < LLC.size(); i += 2) {
        os << dnvgl::extfem::fem::types::card().format()
           << _form_LLC.format(LLC.at(i)) << _form_FACT.format(FACT.at(i));
        if (i+1 < LLC.size())
            os << _form_LLC.format(LLC.at(i+1))
               << _form_FACT.format(FACT.at(i+1));
        os << endl;
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
