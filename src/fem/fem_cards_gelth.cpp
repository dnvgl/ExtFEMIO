/**
   \file fem/fem_cards_gelth.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GELTH` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_gelth[]
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

const fem::types::card gelth::head("GELTH");


// const entry_type<long> gelth::_form_GEONO("GENO");
const entry_type<double> gelth::_form_TH("TH");
const entry_type<long> gelth::_form_NINT("NINT");

gelth::gelth(const vector<std::string> &inp, size_t const &len) :
        geoprop(inp, len) {
    read(inp, len);
}

void gelth::read(const vector<std::string> &inp, size_t const &len) {
    std::string static const empty{"                "};

    if (len < 4)
        throw errors::parse_error(
            "GELTH", "Illegal number of entries.");

    TH = _form_TH(inp.at(2));
    if (len > 3 && inp.at(3) != empty)
        NINT = _form_NINT(inp[3]);
    else
        NINT = {0};
}

gelth::gelth(void) :
        gelth(-1, 0.) {}

gelth::gelth(
    const long &GEONO,
    const double &TH, const long &NINT/*=0*/) :
        geoprop(GEONO), TH(TH), NINT(NINT) {}

gelth::gelth(
    const double &TH, const long &NINT/*=0*/) :
        gelth(0, TH, NINT) {}

cards::__base::card const &gelth::operator() (
    long const &GEONO, double const &TH,
    long const &NINT/*=0*/) {
    geoprop::set_geono(GEONO);
    this->TH = TH;
    this->NINT = NINT;
    return *this;
}

cards::__base::card const &gelth::operator() (
    double const &TH, long const &NINT/*=0*/) {
    return (*this)(0, TH, NINT);
}

const dnvgl::extfem::fem::cards::types
gelth::card_type(void) const {return types::GELTH;}

std::ostream &gelth::put(std::ostream& os) const {
    if (GEONO == -1) return os;
    os << gelth::head.format()
       << _form_GEONO.format(GEONO)
       << _form_TH.format(TH);
    if (NINT)
        os << _form_NINT.format(NINT);
    os << std::endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
