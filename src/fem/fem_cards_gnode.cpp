/**
   \file fem/fem_cards_gnode.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GNODE` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_gnode[] _EXTFEMIO_UNUSED =
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
using namespace cards;
using namespace types;


fem::types::card const gnode::head("GNODE");

entry_type<long> const gnode::_form_NODEX("NODEX");
entry_type<long> const gnode::_form_NODENO("NODENO");
entry_type<long> const gnode::_form_NDOF("NDOF");
entry_type<vector<int> > const gnode::_form_ODOF("ODOF");

gnode::gnode(const vector<std::string> &inp, size_t const len) {
    read(inp, len);
}

gnode::~gnode(void) {
    ODOF.clear();
}

void gnode::read(const vector<std::string> &inp, size_t const len) {
    if (len < 5)
        throw errors::parse_error(
            "GNODE", "Illegal number of entries.");

    NODEX = _form_NODEX(inp.at(1));
    NODENO = _form_NODENO(inp.at(2));
    NDOF = _form_NDOF(inp.at(3));
    _form_ODOF(ODOF, inp.at(4));
}

gnode::gnode(void) :
        gnode(-1, 0, {}) {}

gnode::gnode(
    long const NODEX, long const NODENO, long const NDOF,
    vector<int> const &ODOF) :
        card(),
        NODEX(NODEX), NODENO(NODENO), NDOF(NDOF),
        ODOF(ODOF.begin(), ODOF.end()) {
    sort(this->ODOF.begin(), this->ODOF.end());
};

gnode::gnode(
    long const NODEX, long const NODENO, vector<int> const &ODOF) :
        gnode(NODEX, NODENO, static_cast<long>(ODOF.size()), ODOF) {}

dnvgl::extfem::fem::cards::types const
gnode::card_type(void) const {
    return types::GNODE;
}

ostream &gnode::put(ostream& os) const {
    if (NODEX == -1) return os;
    os << gnode::head.format()
       << _form_NODEX.format(NODEX) << _form_NODENO.format(NODENO)
       << _form_NDOF.format(NDOF) << _form_ODOF.format(this->ODOF) << endl;

    return os;
}

cards::__base::card const &gnode::operator() (
    long const NODEX, long const NODENO, long const NDOF,
    vector<int> const &ODOF) {
    this->NODEX = NODEX;
    this->NODENO = NODENO;
    this->NDOF = NDOF;
    this->ODOF = ODOF;
    sort(this->ODOF.begin(), this->ODOF.end());
    return *this;
}

cards::__base::card const &gnode::operator() (
    long const NODEX, long const NODENO, vector<int> const &ODOF) {
    return (*this)(NODEX, NODENO, static_cast<long>(ODOF.size()), ODOF);
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
