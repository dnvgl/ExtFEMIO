/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GTONP` cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards_gtonp[] _EXTFEMIO_UNUSED =
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

card const gtonp::head("GTONP");

entry_type<double> const gtonp::_form_HZ("HZ");
entry_type<double> const gtonp::_form_TY("TY");
entry_type<double> const gtonp::_form_BT("BT");
entry_type<double> const gtonp::_form_TT("TT");
entry_type<double> const gtonp::_form_BP("BP");
entry_type<double> const gtonp::_form_TP("TP");
entry_type<double> const gtonp::_form_SFY("SFY");
entry_type<double> const gtonp::_form_SFZ("SFZ");
entry_type<long> const gtonp::_form_NLOBYT("NLOBYT");
entry_type<long> const gtonp::_form_NLOBYB("NLOBYB");
entry_type<long> const gtonp::_form_NLOBZ("NLOBZ");

gtonp::gtonp(const vector<std::string> &inp, size_t const len) :
        beam_prop(inp, len, false) {
    gtonp::read(inp, len);
}

void gtonp::read(const vector<std::string> &inp, size_t const len) {
    std::string static const empty{"                "};
    if (len < 10)
        throw errors::parse_error(
            "GTONP", "Illegal number of entries.");

    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    BT = _form_BT(inp.at(4));
    TT = _form_TT(inp.at(5));
    BP = _form_BP(inp.at(6));
    TP = _form_TP(inp.at(7));
    SFY = _form_SFY(inp.at(8));
    SFZ = _form_SFZ(inp.at(9));
    if (len >= 10 && inp.at(10) != empty)
        NLOBYT = _form_NLOBYT(inp[10]);
    else
        NLOBYT = {0};
    if (len >= 11 && inp.at(11) != empty)
        NLOBYB = _form_NLOBYB(inp[11]);
    else
        NLOBYB = {0};
    if (len >= 12 && inp.at(12) != empty)
        NLOBZ = _form_NLOBZ(inp[12]);
    else
        NLOBZ = {0};
}

gtonp::gtonp() : gtonp(-1, 0., 0., 0., 0., 0., 0., 0., 0.) {}

gtonp::gtonp(
    long const GEONO,
    double const HZ, double const TY, double const BT, double const TT,
    double const BP, double const TP,
    double const SFY, double const SFZ,
    long const NLOBYT, long const NLOBYB, long const NLOBZ) :
        beam_prop(GEONO, false),
        HZ(HZ), TY(TY), BT(BT), TT(TT), BP(BP), TP(TP),
        SFY(SFY), SFZ(SFZ),
        NLOBYT(NLOBYT), NLOBYB(NLOBYB), NLOBZ(NLOBZ) {}

cards::__base::card const &gtonp::operator() (
    long const GEONO,
    double const HZ, double const TY, double const BT, double const TT,
    double const BP, double const TP,
    double const SFY, double const SFZ,
    long const NLOBYT, long const NLOBYB, long const NLOBZ) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->TY = TY;
    this->BT = BT;
    this->TT = TT;
    this->BP = BP;
    this->TP = TP;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->NLOBYT = NLOBYT;
    this->NLOBYB = NLOBYB;
    this->NLOBZ = NLOBZ;
    return *this;
}

cards::types
gtonp::card_type() const {
    return types::GTONP;
}

ostream &gtonp::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_TY.format(TY) << _form_BT.format(BT) << endl
       << fem::types::card().format()
       << _form_TT.format(TT) << _form_BP.format(BP)
       << _form_TP.format(TP) << _form_SFY.format(SFY) << endl
       << fem::types::card().format()
       << _form_SFZ.format(SFZ);
    if ((NLOBYT || NLOBYB || NLOBZ))
        os << _form_NLOBYT.format(NLOBYT) << _form_NLOBYB.format(NLOBYB)
           << _form_NLOBZ.format(NLOBZ);
    os << endl;
    return os;
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
