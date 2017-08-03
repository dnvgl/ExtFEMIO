/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GBARM` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_cards_gbarm[] _EXTFEMIO_UNUSED =
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

card const gbarm::head("GBARM");

entry_type<double> const gbarm::_form_HZ("HZ");
entry_type<double> const gbarm::_form_BT("BT");
entry_type<double> const gbarm::_form_BB("BB");
entry_type<double> const gbarm::_form_SFY("SFY");
entry_type<double> const gbarm::_form_SFZ("SFZ");
entry_type<long> const gbarm::_form_NLOBY("NLOBY");
entry_type<long> const gbarm::_form_NLOBZ("NLOBZ");

gbarm::gbarm(vector<std::string> const &inp, size_t const len)  :
        beam_prop(inp, len, false) {
    gbarm::read(inp, len);
}

void gbarm::read(vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 7)
        throw errors::parse_error(
            "GBARM", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    HZ = _form_HZ(inp.at(2));
    BT = _form_BT(inp.at(3));
    BB = _form_BB(inp.at(4));
    SFY = _form_SFY(inp.at(5));
    SFZ = _form_SFZ(inp.at(6));
    if (len > 7 && inp.at(7) != empty)
        NLOBY = _form_NLOBY(inp.at(7));
    else
        NLOBY = {0};
    if (len > 8 && inp.at(8) != empty)
        NLOBZ = _form_NLOBZ(inp.at(8));
    else
        NLOBZ = {0};
}

gbarm::gbarm() :
        gbarm(-1, 0, 0, 0, 0, 0, 0, 0) {}

gbarm::gbarm(
    long const GEONO,
    double const HZ, double const BT, double const BB,
    double const SFY, double const SFZ,
    long const NLOBY, long const NLOBZ) :
        beam_prop(GEONO), HZ(HZ), BT(BT), BB(BB),
        SFY(SFY), SFZ(SFZ), NLOBY(NLOBY), NLOBZ(NLOBZ) {}

cards::__base::card const &gbarm::operator() (
    long const GEONO,
    double const HZ, double const BT, double const BB,
    double const SFY, double const SFZ,
    long const NLOBY, long const NLOBZ) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->BT = BT;
    this->BB = BB;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->NLOBY = NLOBY;
    this->NLOBZ = NLOBZ;
    return *this;
}

cards::types gbarm::card_type() const {
    return types::GBARM;
}

ostream &gbarm::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_BT.format(BT) << _form_BB.format(BB) << endl
       << fem::types::card("").format()
       << _form_SFY.format(SFY) << _form_SFZ.format(SFZ);
    if ((NLOBY || NLOBZ))
        os << _form_NLOBY.format(NLOBY) << _form_NLOBZ.format(NLOBZ);
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
