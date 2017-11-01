/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GECCEN` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_geccen[]) =
        "@(#) $Id$";
}

#include <cassert>

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

const card geccen::head("GECCEN");


// const entry_type<long> geccen::_form_ECCNO("ECCNO");
const entry_type<double> geccen::_form_EX("EX");
const entry_type<double> geccen::_form_EY("EY");
const entry_type<double> geccen::_form_EZ("EZ");

geccen::geccen() : geccen(-1, 0., 0., 0.) {}

geccen::geccen(geccen const *that) :
        geccen(that->ECCNO, that->EX, that->EY, that->EZ) {}

geccen::geccen(const vector<std::string> &inp, size_t const len) {
    geccen::read(inp, len);
}

void geccen::read(const vector<std::string> &inp, size_t const len) {
    eccno::read(inp, len);
    if (len < 5)
        throw errors::parse_error(
            "GECCEN", "Illegal number of entries.");

    // ECCNO = _form_ECCNO(inp.at(1));
    EX = _form_EX(inp.at(2));
    EY = _form_EY(inp.at(3));
    EZ = _form_EZ(inp.at(4));
}

geccen::geccen(
    long const ECCNO,
    double const EX, double const EY, double const EZ) :
        eccno(ECCNO), EX(EX), EY(EY), EZ(EZ) {}

cards::types geccen::card_type() const {
    return types::GECCEN;
}

ostream &geccen::put(ostream& os) const {
    if (ECCNO == -1) return os;
    os << head.format()
       << _form_ECCNO.format(ECCNO)
       << _form_EX.format(EX)
       << _form_EY.format(EY)
       << _form_EZ.format(EZ);
    return os << endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
