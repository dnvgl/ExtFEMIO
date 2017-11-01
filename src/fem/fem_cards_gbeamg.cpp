/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GBEAMG` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_gbeamg[]) =
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
using namespace cards;
using namespace types;

const card gbeamg::head("GBEAMG");

const entry_type<double> gbeamg::_form_AREA("AREA");
const entry_type<double> gbeamg::_form_IX("IX");
const entry_type<double> gbeamg::_form_IY("IY");
const entry_type<double> gbeamg::_form_IZ("IZ");
const entry_type<double> gbeamg::_form_IYZ("IYZ");
const entry_type<double> gbeamg::_form_WXMIN("WXMIN");
const entry_type<double> gbeamg::_form_WYMIN("WYMIN");
const entry_type<double> gbeamg::_form_WZMIN("WZMIN");
const entry_type<double> gbeamg::_form_SHARY("SHARY");
const entry_type<double> gbeamg::_form_SHARZ("SHARZ");
const entry_type<double> gbeamg::_form_SHCENY("SHCENY");
const entry_type<double> gbeamg::_form_SHCENZ("SHCENZ");
const entry_type<double> gbeamg::_form_SY("SY");
const entry_type<double> gbeamg::_form_SZ("SZ");

gbeamg::gbeamg(const vector<std::string> &inp, size_t const len) :
        beam_prop(inp, len, true) {
    gbeamg::read(inp, len);
}

void gbeamg::read(const vector<std::string> &inp, size_t const len) {
    if (len != 17 && len != 5)
        throw errors::parse_error(
            "GBEAMG", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    AREA = _form_AREA(inp.at(3));
    if (len == 17) {
        IX = _form_IX(inp.at(4));
        IY = _form_IY(inp.at(5));
        IZ = _form_IZ(inp.at(6));
        IYZ = _form_IYZ(inp.at(7));
        WXMIN = _form_WXMIN(inp.at(8));
        WYMIN = _form_WYMIN(inp.at(9));
        WZMIN = _form_WZMIN(inp.at(10));
        SHARY = _form_SHARY(inp.at(11));
        SHARZ = _form_SHARZ(inp.at(12));
        SHCENY = _form_SHCENY(inp.at(13));
        SHCENZ = _form_SHCENZ(inp.at(14));
        SY = _form_SY(inp.at(15));
        SZ = _form_SZ(inp.at(16));
    } else {
        IX = {0};
        IY = {0};
        IZ = {0};
        IYZ = {0};
        WXMIN = {0};
        WYMIN = {0};
        WZMIN = {0};
        SHARY = {0};
        SHARZ = {0};
        SHCENY = {0};
        SHCENZ = {0};
        SY = {0};
        SZ = {0};
    }
}

gbeamg::gbeamg() :
        gbeamg(-1, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
               0., 0., 0.) {}

gbeamg::gbeamg(
    long const GEONO,
    double const AREA,
    double const IX, double const IY, double const IZ, double const IYZ,
    double const WXMIN, double const WYMIN, double const WZMIN,
    double const SHARY, double const SHARZ,
    double const SHCENY, double const SHCENZ,
    double const SY, double const SZ) :
        beam_prop(GEONO, true),
        AREA(AREA), IX(IX), IY(IY), IZ(IZ), IYZ(IYZ),
        WXMIN(WXMIN), WYMIN(WYMIN), WZMIN(WZMIN),
        SHARY(SHARY), SHARZ(SHARZ),
        SHCENY(SHCENY), SHCENZ(SHCENZ), SY(SY),
        SZ(SZ) {}

gbeamg::gbeamg(long const GEONO, double const AREA) :
        beam_prop(GEONO, true), AREA(AREA), IX{0}, IY{0}, IZ{0}, IYZ{0},
    WXMIN{0}, WYMIN{0}, WZMIN{0}, SHARY{0}, SHARZ{0}, SHCENY{0}, SHCENZ{0},
    SY{0}, SZ{0} {}

gbeamg::gbeamg(double const AREA) :
    beam_prop(0), AREA(AREA), IX{0}, IY{0}, IZ{0}, IYZ{0},
    WXMIN{0}, WYMIN{0}, WZMIN{0}, SHARY{0}, SHARZ{0}, SHCENY{0}, SHCENZ{0},
    SY{0}, SZ{0} {}

// cards::__base::card const &gbeamg::operator() (
//     vector<std::string> const &inp, size_t const len) {
//     cards::__base::beam_prop::read(inp, len);
//     read(inp, len);
//     return *this;
// }

cards::__base::card const &gbeamg::operator() (
    long const GEONO,
    double const AREA,
    double const IX, double const IY, double const IZ, double const IYZ,
    double const WXMIN, double const WYMIN, double const WZMIN,
    double const SHARY, double const SHARZ,
    double const SHCENY, double const SHCENZ,
    double const SY, double const SZ) {
    set_geono(GEONO, true);
    this->AREA = AREA;
    this->IX = IX;
    this->IY = IY;
    this->IZ = IZ;
    this->IYZ = IYZ;
    this->WXMIN = WXMIN;
    this->WYMIN = WYMIN;
    this->WZMIN = WZMIN;
    this->SHARY = SHARY;
    this->SHARZ = SHARZ;
    this->SHCENY = SHCENY;
    this->SHCENZ = SHCENZ;
    this->SY = SY;
    this->SZ = SZ;
    return *this;
}

cards::__base::card const &gbeamg::operator() (double const AREA) {
    set_geono(0, true);
    this->AREA = AREA;
    this->IX = {0};
    this->IY = {0};
    this->IZ = {0};
    this->IYZ = {0};
    this->WXMIN = {0};
    this->WYMIN = {0};
    this->WZMIN = {0};
    this->SHARY = {0};
    this->SHARZ = {0};
    this->SHCENY = {0};
    this->SHCENZ = {0};
    this->SY = {0};
    this->SZ = {0};
    return *this;

}

cards::__base::card const &gbeamg::operator() (
    long const GEONO, double const AREA) {
    set_geono(GEONO, true);
    this->AREA = AREA;
    this->IX = {0};
    this->IY = {0};
    this->IZ = {0};
    this->IYZ = {0};
    this->WXMIN = {0};
    this->WYMIN = {0};
    this->WZMIN = {0};
    this->SHARY = {0};
    this->SHARZ = {0};
    this->SHCENY = {0};
    this->SHCENZ = {0};
    this->SY = {0};
    this->SZ = {0};
    return *this;

}

cards::types gbeamg::card_type() const {
    return types::GBEAMG;
}

ostream &gbeamg::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << empty.format()
       << _form_AREA.format(AREA) << _form_IX.format(IX) << endl;

    if (IX == 0. && IY == 0. && IZ == 0. && IYZ == 0. &&
        WXMIN == 0. && WYMIN == 0. && WZMIN == 0. &&
        SHARY == 0. && SHARZ == 0. && SHCENY == 0. && SHCENZ == 0. &&
        SY == 0. && SZ == 0.)
        return os; // Only area value given for ELTYP 10 (truss element)

    os << fem::types::card("").format()
       << _form_IY.format(IY) << _form_IZ.format(IZ)
       << _form_IYZ.format(IYZ) << _form_WXMIN.format(WXMIN) << endl
       << fem::types::card("").format()
       << _form_WYMIN.format(WYMIN) << _form_WZMIN.format(WZMIN)
       << _form_SHARY.format(SHARY) << _form_SHARZ.format(SHARZ) << endl
       << fem::types::card("").format()
       << _form_SHCENY.format(SHCENY) << _form_SHCENZ.format(SHCENZ)
       << _form_SY.format(SY) << _form_SZ.format(SZ) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
