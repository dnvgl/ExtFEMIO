/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GDOBO` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_fem_cards_gdobo[]) =
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

card const gdobo::head("GDOBO");

entry_type<double> const gdobo::_form_HZ("HZ");
entry_type<double> const gdobo::_form_TY("TY");
entry_type<double> const gdobo::_form_BY("BY");
entry_type<double> const gdobo::_form_TT("TT");
entry_type<double> const gdobo::_form_TB("TB");
entry_type<double> const gdobo::_form_SFY("SFY");
entry_type<double> const gdobo::_form_SFZ("SFZ");
entry_type<long> const gdobo::_form_NLOBY("NLOBY");
entry_type<long> const gdobo::_form_NLOBZ("NLOBZ");

gdobo::gdobo() : gdobo(-1, 0., 0., 0., 0., 0., 0., 0.) {}

gdobo::gdobo(vector<std::string> const &inp, size_t const len) :
        beam_prop(inp, len, false) {
    gdobo::read(inp, len);
}

gdobo::gdobo(long const GEONO,
             double const HZ, double const TY, double const BY,
             double const TT, double const TB,
             double const SFY, double const SFZ,
             long const NLOBY, long const NLOBZ) :
        beam_prop(GEONO),
        HZ{HZ}, TY{TY}, BY{BY}, TT{TT}, TB{TB}, SFY{SFY}, SFZ{SFZ},
        NLOBY{NLOBY}, NLOBZ{NLOBZ} {}

cards::types gdobo::card_type() const {
    return types::GDOBO;
}

cards::__base::card const &gdobo::operator() (
    long const GEONO,
    double const HZ, double const TY, double const BY,
    double const TT, double const TB,
    double const SFY, double const SFZ,
    long const NLOBY, long const NLOBZ) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->TY = TY;
    this->BY = BY;
    this->TT = TT;
    this->TB = TB;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->NLOBY = NLOBY;
    this->NLOBZ = NLOBZ;
    return *this;
}

ostream &gdobo::put(ostream &os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_TY.format(TY) << _form_BY.format(BY) << endl
       << fem::types::card("").format()
       << _form_TT.format(TT) << _form_TB.format(TB)
       << _form_SFY.format(SFY) << _form_SFZ.format(SFZ) << endl;
    if ((NLOBY || NLOBZ))
        os << fem::types::card("").format()
           << _form_NLOBY.format(NLOBY) << _form_NLOBZ.format(NLOBZ) << endl;
    return os;
};

void gdobo::read(vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 9)
        throw errors::parse_error(
            "DOBO", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    BY = _form_BY(inp.at(4));
    TT = _form_TT(inp.at(5));
    TB = _form_TB(inp.at(6));
    SFY = _form_SFY(inp.at(7));
    SFZ = _form_SFZ(inp.at(8));
    if (len < 10) {
        NLOBY = {0};
        NLOBZ = {0};
        return;
    }
    if (inp.at(9) != empty)
        NLOBY = _form_NLOBY(inp [9]);
    else
        NLOBY = {0};
    if (len > 11 && inp.at(10) != empty)
        NLOBZ = _form_NLOBZ(inp[10]);
    else
        NLOBZ = {0};
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
