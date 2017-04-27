/**
   \file fem/fem_cards_giorhr.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GIORHR` cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_giorhr[] _EXTFEMIO_UNUSED =
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
using namespace cards;
using namespace types;

card const giorhr::head("GIORHR");

entry_type<double> const giorhr::_form_HZ("HZ");
entry_type<double> const giorhr::_form_TY("TY");
entry_type<double> const giorhr::_form_BT("BT");
entry_type<double> const giorhr::_form_TT("TT");
entry_type<double> const giorhr::_form_BB("BB");
entry_type<double> const giorhr::_form_TB("TB");
entry_type<double> const giorhr::_form_SFY("SFY");
entry_type<double> const giorhr::_form_SFZ("SFZ");
entry_type<double> const giorhr::_form_RT("RT");
entry_type<double> const giorhr::_form_RB("RB");
entry_type<long> const giorhr::_form_NLOBYT("NLOBYT");
entry_type<long> const giorhr::_form_NLOBYB("NLOBYB");
entry_type<long> const giorhr::_form_NLOBZ("NLOBZ");


giorhr::giorhr(vector<std::string> const &inp, size_t const len) :
        beam_prop(inp, len, false) {
    giorhr::read(inp, len);
}

void giorhr::read(vector<std::string> const &inp, size_t const len) {
    std::string static const empty("                ");

    if (len < 12)
        throw errors::parse_error(
            "GIORHR", "Illegal number of entries.");

    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    BT = _form_BT(inp.at(4));
    TT = _form_TT(inp.at(5));
    BB = _form_BB(inp.at(6));
    TB = _form_TB(inp.at(7));
    SFY = _form_SFY(inp.at(8));
    SFZ = _form_SFZ(inp.at(9));
    RT = _form_RT(inp.at(10));
    RB = _form_RB(inp.at(11));
    if (len > 12 && inp.at(12) != empty)
        NLOBYT = _form_NLOBYT(inp[12]);
    else
        NLOBYT = {0};
    if (len > 13 && inp.at(13) != empty)
        NLOBYB = _form_NLOBYB(inp[13]);
    else
        NLOBYB = {0};
    if (len > 14 && inp.at(14) != empty)
        NLOBZ = _form_NLOBZ(inp[14]);
    else
        NLOBZ = {0};
}

giorhr::giorhr(long const GEONO,
               double const HZ, double const TY, double const BT,
               double const TT, double const BB, double const TB,
               double const SFY, double const SFZ,
               double const RT, double const RB,
               long const NLOBYT, long const NLOBYB,
               long const NLOBZ) :
        beam_prop(GEONO, false),
        HZ(HZ), TY(TY), BT(BT), TT(TT), BB(BB), TB(TB),
        SFY(SFY), SFZ(SFZ), RT(RT), RB(RB),
        NLOBYT(NLOBYT), NLOBYB(NLOBYB), NLOBZ(NLOBZ) {}

cards::__base::card const &giorhr::operator() (
    long const GEONO,
    double const HZ, double const TY, double const BT,
    double const TT, double const BB, double const TB,
    double const SFY, double const SFZ,
    double const RT, double const RB,
    long const NLOBYT, long const NLOBYB, long const NLOBZ) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->TY = TY;
    this->BT = BT;
    this->TT = TT;
    this->BB = BB;
    this->TB = TB;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->RT = RT;
    this->RB = RB;
    this->NLOBYT = NLOBYT;
    this->NLOBYB = NLOBYB;
    this->NLOBZ = NLOBZ;
    return *this;
}

cards::types giorhr::card_type() const {
    return types::GIORHR;
}

ostream &giorhr::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_TY.format(TY) << _form_BT.format(BT) << endl
       << fem::types::card().format()
       << _form_TT.format(TT) << _form_BB.format(BB)
       << _form_TB.format(TB) << _form_SFY.format(SFY) << endl
       << fem::types::card().format()
       << _form_SFZ.format(SFZ) << _form_RT.format(RT)
       << _form_RB.format(RB);
    if ((NLOBYT || NLOBYB || NLOBZ))
        os << _form_NLOBYT.format(NLOBYT) << endl
           << fem::types::card().format()
           << _form_NLOBYB.format(NLOBYB) << _form_NLOBZ.format(NLOBZ);
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
