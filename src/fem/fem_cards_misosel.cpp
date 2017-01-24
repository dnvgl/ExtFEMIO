/**
   \file fem/fem_cards_misosel.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `MISOSEL` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_misosel[]
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

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::types;

using namespace dnvgl::extfem::fem::cards;

const fem::types::card misosel::head("MISOSEL");

// const entry_type<long> misosel::_form_MATNO("MATNO");
const entry_type<double> misosel::_form_YOUNG("YOUNG");
const entry_type<double> misosel::_form_POISS("POISS");
const entry_type<double> misosel::_form_RHO("RHO");
const entry_type<double> misosel::_form_DAMP("DAMP");
const entry_type<double> misosel::_form_ALPHA("ALPHA");
const entry_type<double> misosel::_form_DUMMY("DUMMY");
const entry_type<double> misosel::_form_YIELD("YIELD");

misosel::misosel(const vector<std::string> &inp, size_t const &len) :
        material(inp, len) {
    read(inp, len);
}

void misosel::read(const vector<std::string> &inp, size_t const &len) {
    __base::material::read(inp, len);
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

misosel::misosel(void) :
        misosel(-1, 0., 0., 0., 0., 0.) {}

misosel::misosel(const long &MATNO,
                 const double &YOUNG,
                 const double &POISS,
                 const double &RHO,
                 const double &DAMP,
                 const double &ALPHA,
                 const double &DUMMY/*=0.*/,
                 const double &YIELD/*=0.*/) :
        __base::material(MATNO), YOUNG(YOUNG), POISS(POISS),
        RHO(RHO), DAMP(DAMP), ALPHA(ALPHA), DUMMY(DUMMY),
        YIELD(YIELD) {}

cards::__base::card const &misosel::operator() (
    long const &MATNO,
    double const &YOUNG,
    double const &POISS,
    double const &RHO,
    double const &DAMP,
    double const &ALPHA,
    double const &DUMMY/*=0.*/,
    double const &YIELD/*=0.*/) {
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

const dnvgl::extfem::fem::cards::types
misosel::card_type(void) const {return types::MISOSEL;}

ostream &misosel::put(ostream& os) const {
    if (MATNO == -1) return os;
    os << misosel::head.format()
       << _form_MATNO.format(MATNO) << _form_YOUNG.format(YOUNG)
       << _form_POISS.format(POISS) << _form_RHO.format(RHO) << endl
       << dnvgl::extfem::fem::types::card().format()
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
