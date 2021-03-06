/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GNODE` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards_gnode[]) =
        "@(#) $Id$";
}

#include <algorithm>

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
using namespace cards;
using namespace types;


card const gnode::head("GNODE");

entry_type<long> const gnode::_form_NODEX("NODEX");
entry_type<long> const gnode::_form_NODENO("NODENO");
entry_type<long> const gnode::_form_NDOF("NDOF");
entry_type<vector<int> > const gnode::_form_ODOF("ODOF");

gnode::gnode(const vector<std::string> &inp, size_t const len) :
        card(types::GNODE) {
    gnode::read(inp, len);
}

gnode::~gnode() {
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

gnode::gnode() : gnode(-1, 0, {}) {}

gnode::gnode(
    long const NODEX, long const NODENO, long const NDOF,
    vector<int> const &ODOF) :
        card(types::GNODE),
        NODEX(NODEX), NODENO(NODENO), NDOF(NDOF),
        ODOF(ODOF.begin(), ODOF.end()) {
    sort(this->ODOF.begin(), this->ODOF.end());
};

gnode::gnode(
    long const NODEX, long const NODENO, vector<int> const &ODOF) :
        gnode(NODEX, NODENO, static_cast<long>(ODOF.size()), ODOF) {}

ostream &gnode::put(ostream& os) const {
    if (NODEX == -1) return os;
    os << head.format()
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
