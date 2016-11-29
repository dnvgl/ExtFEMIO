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

gbeamg::gbeamg(const std::list<std::string> &inp) :
        __base::beam_prop() {

    if (inp.size() < 17)
        throw errors::parse_error(
            "GBEAMG", "Illegal number of entries.");

    auto pos = inp.begin();

    ++pos;
    GEONO = _form_GEONO(*(pos++));
    ++pos;
    AREA = _form_AREA(*(pos++));
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

const dnvgl::extfem::fem::cards::types
gbeamg::card_type(void) const {return types::GBEAMG;}

std::ostream &gbeamg::put(std::ostream& os) const {
    if (this->GEONO == -1) return os;
    os << gbeamg::head.format()
       << this->_form_GEONO.format(this->GEONO)
       << this->empty.format()
       << this->_form_AREA.format(this->AREA)
       << this->_form_IX.format(this->IX)
       << std::endl << fem::types::card("").format()
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
