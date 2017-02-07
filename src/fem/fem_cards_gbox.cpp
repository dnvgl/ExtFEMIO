/**
   \file fem_cards_gbox.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GBOX` cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_gbox[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "fem/cards.h"

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

fem::types::card const gbox::head("GBOX");

entry_type<double> const gbox::_form_HZ("HZ");
entry_type<double> const gbox::_form_TY("TY");
entry_type<double> const gbox::_form_TB("TB");
entry_type<double> const gbox::_form_TT("TT");
entry_type<double> const gbox::_form_BY("BY");
entry_type<double> const gbox::_form_SFY("SFY");
entry_type<double> const gbox::_form_SFZ("SFZ");
entry_type<long> const gbox::_form_NLOBY("NLOBY");
entry_type<long> const gbox::_form_NLOBZ("NLOBZ");



gbox::gbox(void) :
        gbox(-1, 0., 0., 0., 0., 0., 0., 0.) {}

gbox::gbox(vector<std::string> const &inp, size_t const len) :
        __base::beam_prop(inp, len, false) {
    read(inp, len);
}

gbox::gbox(long const GEONO,
           double const HZ, double const TY, double const TB,
           double const TT, double const BY,
           double const SFY, double const SFZ,
           long const NLOBY/*=0*/, long const NLOBZ/*=0*/) :
        __base::beam_prop(GEONO),
        HZ{HZ}, TY{TY}, TB{TB}, TT{TT}, BY{BY}, SFY{SFY}, SFZ{SFZ},
        NLOBY{NLOBY}, NLOBZ{NLOBZ} {}

cards::types const gbox::card_type(void) const {
    return types::GBOX;
}

cards::__base::card const &gbox::operator() (
    long const GEONO,
    double const HZ, double const TY, double const TB,
    double const TT, double const BY,
    double const SFY, double const SFZ,
    long const NLOBY/*=0*/, long const NLOBZ/*=0*/) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->TY = TY;
    this->TB = TB;
    this->TT = TT;
    this->BY = BY;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->NLOBY = NLOBY;
    this->NLOBZ = NLOBZ;
    return *this;
}

ostream &gbox::put(ostream &os) const {
    if (GEONO == -1) return os;
    os << gbox::head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_TY.format(TY) << _form_TB.format(TB) << endl
       << fem::types::card("").format()
       << _form_TT.format(TT) << _form_BY.format(BY)
       << _form_SFY.format(SFY) << _form_SFZ.format(SFZ) << endl;
    if ((NLOBY || NLOBZ))
        os << fem::types::card("").format()
           << _form_NLOBY.format(NLOBY) << _form_NLOBZ.format(NLOBZ) << endl;
    return os;
}

void gbox::read(vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 9)
        throw errors::parse_error(
            "GBARM", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    TB = _form_TB(inp.at(4));
    TT = _form_TT(inp.at(5));
    BY = _form_BY(inp.at(6));
    SFY = _form_SFY(inp.at(7));
    SFZ = _form_SFZ(inp.at(8));
    if (len < 10) {
        NLOBY = {0};
        NLOBZ = {0};
        return;
    }
    if (inp.at(9) != empty)
        NLOBY = _form_NLOBY(inp.at(9));
    else
        NLOBY = {0};
    if (len > 11 && inp.at(10) != empty)
        NLOBZ = _form_NLOBZ(inp.at(10));
    else
        NLOBZ = {0};
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_fem_cards --use-colour no)
// End:
