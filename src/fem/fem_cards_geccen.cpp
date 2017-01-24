/**
   \file fem/fem_cards_geccen.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GECCEN` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_geccen[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#include <memory>
#include <algorithm>
#include <cassert>

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
using namespace dnvgl::extfem::fem::cards;

const fem::types::card geccen::head("GECCEN");


const entry_type<long> geccen::_form_ECCNO("ECCNO");
const entry_type<double> geccen::_form_EX("EX");
const entry_type<double> geccen::_form_EY("EY");
const entry_type<double> geccen::_form_EZ("EZ");

geccen::geccen(void) : geccen(-1, 0., 0., 0.) {}

geccen::geccen(geccen const *that) :
        geccen(that->ECCNO, that->EX, that->EY, that->EZ) {}

geccen::geccen(const vector<std::string> &inp, size_t const &len) {
    read(inp, len);
}

void geccen::read(const vector<std::string> &inp, size_t const &len) {
    if (len < 5)
        throw errors::parse_error(
            "GECCEN", "Illegal number of entries.");

    ECCNO = _form_ECCNO(inp.at(1));
    EX = _form_EX(inp.at(2));
    EY = _form_EY(inp.at(3));
    EZ = _form_EZ(inp.at(4));
}

geccen::geccen(
    long const &ECCNO,
    double const &EX, double const &EY, double const &EZ) :
        card(), ECCNO(ECCNO), EX(EX), EY(EY), EZ(EZ) {}

geccen::geccen(long const &ECCNO,
               std::vector<double> const &pos) :
        card(), ECCNO(ECCNO), EX(0.), EY(0.), EZ(0.) {
    assert(pos.size() == 3);
    EX = pos[0];
    EY = pos[1];
    EZ = pos[2];
}

const dnvgl::extfem::fem::cards::types
geccen::card_type(void) const {return types::GECCEN;}

std::ostream &geccen::put(std::ostream& os) const {
    if (ECCNO == -1) return os;
    os << geccen::head.format()
       << _form_ECCNO.format(ECCNO)
       << _form_EX.format(EX)
       << _form_EY.format(EY)
       << _form_EZ.format(EZ);
    return os << std::endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
