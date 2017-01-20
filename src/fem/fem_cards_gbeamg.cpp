/**
   \file fem/fem_cards_gbeamg.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GBEAMG` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_gbeamg[]
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

const fem::types::card gbeamg::head("GBEAMG");

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

gbeamg::gbeamg(const vector<std::string> &inp, size_t const &len) {
    read(inp, len);
}

void gbeamg::read(const vector<std::string> &inp, size_t const &len) {
    __base::beam_prop::read(inp, len);
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

    if (len != 17 && len != 5)
        throw errors::parse_error(
            "GBEAMG", "Illegal number of entries.");

    auto pos = inp.begin();

    ++pos;
    GEONO = _form_GEONO(*(pos++));
    ++pos;
    AREA = _form_AREA(*(pos++));
    if (len == 17) {
        IX = _form_IX(*(pos++));
        IY = _form_IY(*(pos++));
        IZ = _form_IZ(*(pos++));
        IYZ = _form_IYZ(*(pos++));
        WXMIN = _form_WXMIN(*(pos++));
        WYMIN = _form_WYMIN(*(pos++));
        WZMIN = _form_WZMIN(*(pos++));
        SHARY = _form_SHARY(*(pos++));
        SHARZ = _form_SHARZ(*(pos++));
        SHCENY = _form_SHCENY(*(pos++));
        SHCENZ = _form_SHCENZ(*(pos++));
        SY = _form_SY(*(pos++));
        SZ = _form_SZ(*(pos++));
    }
}

gbeamg::gbeamg(void) :
        gbeamg(-1, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
               0., 0., 0.) {}

gbeamg::gbeamg(
    const long &GEONO,
    const double &AREA,
    const double &IX, const double &IY, const double &IZ, const double &IYZ,
    const double &WXMIN, const double &WYMIN, const double &WZMIN,
    const double &SHARY, const double &SHARZ,
    const double &SHCENY, const double &SHCENZ,
    const double &SY, const double &SZ) :
        __base::beam_prop(),
        AREA(AREA), IX(IX), IY(IY), IZ(IZ), IYZ(IYZ),
        WXMIN(WXMIN), WYMIN(WYMIN), WZMIN(WZMIN),
        SHARY(SHARY), SHARZ(SHARZ),
        SHCENY(SHCENY), SHCENZ(SHCENZ), SY(SY),
        SZ(SZ) {
    this->GEONO = GEONO;
}

gbeamg::gbeamg(double const &AREA) :
    __base::beam_prop(0), AREA(AREA), IX{0}, IY{0}, IZ{0}, IYZ{0},
    WXMIN{0}, WYMIN{0}, WZMIN{0}, SHARY{0}, SHARZ{0}, SHCENY{0}, SHCENZ{0},
    SY{0}, SZ{0} {}

cards::__base::card const &gbeamg::operator() (
    long const &GEONO,
    double const &AREA,
    double const &IX, double const &IY, double const &IZ, double const &IYZ,
    double const &WXMIN, double const &WYMIN, double const &WZMIN,
    double const &SHARY, double const &SHARZ,
    double const &SHCENY, double const &SHCENZ,
    double const &SY, double const &SZ) {
    set_geono(GEONO);
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

cards::__base::card const &gbeamg::operator() (double const &AREA) {
    set_geono();
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


const dnvgl::extfem::fem::cards::types
gbeamg::card_type(void) const {return types::GBEAMG;}

std::ostream &gbeamg::put(std::ostream& os) const {
    if (this->GEONO == -1) return os;
    os << gbeamg::head.format()
       << this->_form_GEONO.format(this->GEONO)
       << this->empty.format()
       << this->_form_AREA.format(this->AREA)
       << this->_form_IX.format(this->IX) << std::endl;

    if (IX == 0. && IY == 0. && IZ == 0. && IYZ == 0. &&
        WXMIN == 0. && WYMIN == 0. && WZMIN == 0. &&
        SHARY == 0. && SHARZ == 0. && SHCENY == 0. && SHCENZ == 0. &&
        SY == 0. && SZ == 0.)
        return os; // Only area value given for ELTYP 10 (truss element)

    os << fem::types::card("").format()
       << this->_form_IY.format(this->IY)
       << this->_form_IZ.format(this->IZ)
       << this->_form_IYZ.format(this->IYZ)
       << this->_form_WXMIN.format(this->WXMIN)
       << std::endl << fem::types::card("").format()
       << this->_form_WYMIN.format(this->WYMIN)
       << this->_form_WZMIN.format(this->WZMIN)
       << this->_form_SHARY.format(this->SHARY)
       << this->_form_SHARZ.format(this->SHARZ)
       << std::endl << fem::types::card("").format()
       << this->_form_SHCENY.format(this->SHCENY)
       << this->_form_SHCENZ.format(this->SHCENZ)
       << this->_form_SY.format(this->SY)
       << this->_form_SZ.format(this->SZ) << std::endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
