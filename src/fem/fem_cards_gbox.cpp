/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GBOX` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards_gbox[]) =
        "@(#) $Id$";
}
#include "fem/cards.h"
#include "fem/types.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

using namespace cards;

card const gbox::head("GBOX");

entry_type<double> const gbox::_form_HZ("HZ");
entry_type<double> const gbox::_form_TY("TY");
entry_type<double> const gbox::_form_TB("TB");
entry_type<double> const gbox::_form_TT("TT");
entry_type<double> const gbox::_form_BY("BY");
entry_type<double> const gbox::_form_SFY("SFY");
entry_type<double> const gbox::_form_SFZ("SFZ");
entry_type<long> const gbox::_form_NLOBY("NLOBY");
entry_type<long> const gbox::_form_NLOBZ("NLOBZ");

gbox::gbox() :
        gbox(-1, 0., 0., 0., 0., 0., 0., 0.) {}

gbox::gbox(vector<std::string> const &inp, size_t const len) :
        beam_prop(inp, len, false) {
    __base::card::this_type = types::GBOX;
    gbox::read(inp, len);
}

gbox::gbox(long const GEONO,
           double const HZ, double const TY, double const TB,
           double const TT, double const BY,
           double const SFY, double const SFZ,
           long const NLOBY, long const NLOBZ) :
        beam_prop(GEONO),
        HZ{HZ}, TY{TY}, TB{TB}, TT{TT}, BY{BY}, SFY{SFY}, SFZ{SFZ},
        NLOBY{NLOBY}, NLOBZ{NLOBZ} {
    __base::card::this_type = types::GBOX;
}

cards::__base::card const &gbox::operator() (
    long const GEONO,
    double const HZ, double const TY, double const TB,
    double const TT, double const BY,
    double const SFY, double const SFZ,
    long const NLOBY, long const NLOBZ) {
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
    os << head.format()
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
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_fem_cards --use-colour no)""
// End:
