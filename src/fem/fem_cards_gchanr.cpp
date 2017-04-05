/**
   \file fem_cards_gchanr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GCHANR` cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_gchanr[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "fem/cards.h"

#include <memory>

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

card const gchanr::head("GCHANR");

entry_type<double> const gchanr::_form_HZ("HZ");
entry_type<double> const gchanr::_form_TY("TY");
entry_type<double> const gchanr::_form_BY("BY");
entry_type<double> const gchanr::_form_TZ("TZ");
entry_type<double> const gchanr::_form_SFY("SFY");
entry_type<double> const gchanr::_form_SFZ("SFZ");
entry_type<long> const gchanr::_form_K("K");
entry_type<double> const gchanr::_form_R("R");
entry_type<long> const gchanr::_form_NLOBY("NLOBY");
entry_type<long> const gchanr::_form_NLOBZ("NLOBZ");

gchanr::gchanr() :
        gchanr(-1, 0., 0., 0., 0., 0., 0., 0, 0.) {}

gchanr::gchanr(vector<std::string> const &inp, size_t const len) :
        beam_prop(inp, len, false) {
    gchanr::read(inp, len);
}

gchanr::gchanr(long const GEONO,
             double const HZ, double const TY, double const BY,
             double const TZ, double const SFY, double const SFZ,
               long const K, double const R,
               long const NLOBY/*=0*/, long const NLOBZ/*=0*/) :
        beam_prop(GEONO),
        HZ{HZ}, TY{TY}, BY{BY}, TZ {TZ}, SFY{SFY}, SFZ{SFZ}, K{K}, R{R},
        NLOBY{NLOBY}, NLOBZ{NLOBZ} {}

cards::types gchanr::card_type() const {
    return types::GCHANR;
}

cards::__base::card const &gchanr::operator() (
    long const GEONO,
    double const HZ, double const TY, double const BY,
    double const TZ, double const SFY, double const SFZ,
    long const K, double const R,
    long const NLOBY, long const NLOBZ) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->TY = TY;
    this->BY = BY;
    this->TZ = TZ;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->K = K;
    this->R = R;
    this->NLOBY = NLOBY;
    this->NLOBZ = NLOBZ;
    return *this;
}

ostream &gchanr::put(ostream &os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_TY.format(TY) << _form_BY.format(BY) << endl
       << fem::types::card("").format()
       << _form_TZ.format(TZ) << _form_SFY.format(SFY)
       << _form_SFZ.format(SFZ) << endl << fem::types::card("").format()
       << _form_K.format(K) << _form_R.format(R);
    if ((NLOBY || NLOBZ))
        os << _form_NLOBY.format(NLOBY) << _form_NLOBZ.format(NLOBZ);
    return os << endl;
};

void gchanr::read(
    vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 11)
        throw errors::parse_error(
            "GCHARNR", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    BY = _form_BY(inp.at(4));
    TZ = _form_TZ(inp.at(5));
    SFY = _form_SFY(inp.at(6));
    SFZ = _form_SFZ(inp.at(7));
    K = _form_K(inp.at(9));
    R = _form_R(inp.at(10));
    if (len > 11 && inp.at(11) != empty)
        NLOBY = _form_NLOBY(inp [11]);
    else
        NLOBY = {0};
    if (len > 12 && inp.at(12) != empty)
        NLOBZ = _form_NLOBZ(inp[12]);
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
//    ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
