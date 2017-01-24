/**
   \file fem/fem_cards_gbarm.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GBARM` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char cID_fem_cards_gbarm[]
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
using namespace dnvgl::extfem::fem::cards;
using namespace dnvgl::extfem::fem::types;

const fem::types::card gbarm::head("GBARM");

const entry_type<double> gbarm::_form_HZ("HZ");
const entry_type<double> gbarm::_form_BT("BT");
const entry_type<double> gbarm::_form_BB("BB");
const entry_type<double> gbarm::_form_SFY("SFY");
const entry_type<double> gbarm::_form_SFZ("SFZ");
const entry_type<long> gbarm::_form_NLOBY("NLOBY");
const entry_type<long> gbarm::_form_NLOBZ("NLOBZ");

gbarm::gbarm(const vector<std::string> &inp, size_t const &len) {
    read(inp, len);
}

void gbarm::read(const vector<std::string> &inp, size_t const &len) {
    std::string static const empty{"                "};

    __base::beam_prop::read(inp, len);
    NLOBY = {0};
    NLOBZ = {0};

    if (len < 7)
        throw errors::parse_error(
            "GBARM", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    HZ = _form_HZ(inp.at(2));
    BT = _form_BT(inp.at(3));
    BB = _form_BB(inp.at(4));
    SFY = _form_SFY(inp.at(5));
    SFZ = _form_SFZ(inp.at(6));
    size_t i{7};
    if (i >= len) return;
    if (inp.at(i) != empty)
        NLOBY = _form_NLOBY(inp.at(i));
    if (++i < len && inp.at(i) != empty)
        NLOBZ = _form_NLOBZ(inp.at(i));
}

gbarm::gbarm(void) :
        gbarm(-1, 0, 0, 0, 0, 0, 0, 0) {}

gbarm::gbarm(
    const long &GEONO,
    const double &HZ, const double &BT, const double &BB,
    const double &SFY, const double &SFZ,
    const long &NLOBY/*=0*/, const long &NLOBZ/*=0*/) :
        __base::beam_prop(GEONO), HZ(HZ), BT(BT), BB(BB),
        SFY(SFY), SFZ(SFZ), NLOBY(NLOBY), NLOBZ(NLOBZ) {}

const dnvgl::extfem::fem::cards::types
gbarm::card_type(void) const {return types::GBARM;}

ostream &gbarm::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << gbarm::head.format()
       << _form_GEONO.format(GEONO)
       << _form_HZ.format(HZ)
       << _form_BT.format(BT)
       << _form_BB.format(BB)
       << endl << fem::types::card("").format()
       << _form_SFY.format(SFY)
       << _form_SFZ.format(SFZ);
    if ((NLOBY || NLOBZ))
        os << _form_NLOBY.format(NLOBY)
           << _form_NLOBZ.format(NLOBZ);
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
