/**
   \file fem/fem_cards_misosel.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `MISOSEL` cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_misosel[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

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

card const misosel::head("MISOSEL");

// entry_type<long> const misosel::_form_MATNO("MATNO");
entry_type<double> const misosel::_form_YOUNG("YOUNG");
entry_type<double> const misosel::_form_POISS("POISS");
entry_type<double> const misosel::_form_RHO("RHO");
entry_type<double> const misosel::_form_DAMP("DAMP");
entry_type<double> const misosel::_form_ALPHA("ALPHA");
entry_type<double> const misosel::_form_DUMMY("DUMMY");
entry_type<double> const misosel::_form_YIELD("YIELD");

misosel::misosel(vector<std::string> const &inp, size_t const len) :
        material(inp, len) {
    misosel::read(inp, len);
}

void misosel::read(vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 7)
        throw errors::parse_error(
            "MISOSEL", "Illegal number of entries.");

    MATNO = _form_MATNO(inp.at(1));
    YOUNG = _form_YOUNG(inp.at(2));
    POISS = _form_POISS(inp.at(3));
    RHO = _form_RHO(inp.at(4));
    DAMP = _form_DAMP(inp.at(5));
    ALPHA = _form_ALPHA(inp.at(6));
    if (len > 7 && inp.at(7) != empty)
        DUMMY = _form_DUMMY(inp[7]);
    else
        DUMMY = {0.};
    if (len > 8 && inp.at(8) != empty)
        YIELD = _form_YIELD(inp[8]);
    else
        YIELD = {0.};}

misosel::misosel() :
        misosel(-1, 0., 0., 0., 0., 0.) {}

misosel::misosel(long const MATNO, double const YOUNG,
                 double const POISS, double const RHO,
                 double const DAMP, double const ALPHA,
                 double const DUMMY/*=0.*/, double const YIELD/*=0.*/) :
        material(MATNO), YOUNG(YOUNG), POISS(POISS),
        RHO(RHO), DAMP(DAMP), ALPHA(ALPHA), DUMMY(DUMMY),
        YIELD(YIELD) {}

cards::__base::card const &misosel::operator() (
    vector<std::string> const &inp, size_t const len) {
    material::read(inp, len);
    read(inp, len);
    return *this;
}

cards::__base::card const &misosel::operator() (
    long const MATNO, double const YOUNG, double const POISS,
    double const RHO, double const DAMP, double const ALPHA,
    double const DUMMY/*=0.*/, double const YIELD/*=0.*/) {
    this->MATNO = MATNO;
    this->YOUNG = YOUNG;
    this->POISS = POISS;
    this->RHO = RHO;
    this->DAMP = DAMP;
    this->ALPHA = ALPHA;
    this->DUMMY = DUMMY;
    this->YIELD = YIELD;
    return *this;
}

cards::types misosel::card_type() const {
    return types::MISOSEL;
}

ostream &misosel::put(ostream& os) const {
    if (MATNO == -1) return os;
    os << head.format()
       << _form_MATNO.format(MATNO) << _form_YOUNG.format(YOUNG)
       << _form_POISS.format(POISS) << _form_RHO.format(RHO) << endl
       << fem::types::card().format()
       << _form_DAMP.format(DAMP) << _form_ALPHA.format(ALPHA);
    if ((DUMMY || YIELD))
        os << _form_DUMMY.format(DUMMY) << _form_YIELD.format(YIELD);
    os << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
