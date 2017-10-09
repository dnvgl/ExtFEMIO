/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BEUSLO` cards.

   Detailed description
   */

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_beuslo[]) =
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
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace types;

using namespace cards;

card const beuslo::head("BEUSLO");

entry_type<long> const beuslo::_form_LLC("LLC");
entry_type<long> const beuslo::_form_LOTYP("LOTYP");
entry_type<bool> const beuslo::_form_COMPLX("COMPLX");
entry_type<long> const beuslo::_form_LAYER("LAYER");
entry_type<long> const beuslo::_form_ELNO("ELNO");
entry_type<long> const beuslo::_form_NDOF("NDOF");
entry_type<long> const beuslo::_form_INTNO("INTNO");
entry_type<long> const beuslo::_form_SIDE("SIDE");
entry_type<double> const beuslo::_form_RLOAD("RLOAD");
entry_type<double> const beuslo::_form_ILOAD("ILOAD");

beuslo::beuslo(vector<std::string> const &inp, size_t const len) {
    beuslo::read(inp, len);
}

void beuslo::read(vector<std::string> const &inp, size_t const len) {
    if (len < 10)
        throw errors::parse_error(
        "BEUSLO", "Illegal number of entries.");

    LLC = _form_LLC(inp.at(1));
    LOTYP = _form_LOTYP(inp.at(2));
    COMPLX = _form_COMPLX(inp.at(3));
    LAYER = _form_LAYER(inp.at(4));
    ELNO = _form_ELNO(inp.at(5));
    NDOF = _form_NDOF(inp.at(6));
    INTNO = _form_INTNO(inp.at(7));
    SIDE = _form_SIDE(inp.at(8));
    for (size_t i{0}; i < static_cast<size_t>(NDOF); i++)
        RLOADi.push_back(_form_RLOAD(inp.at(9 + i)));
    if (COMPLX)
        for (size_t i{0}; i < static_cast<size_t>(NDOF); i++)
            ILOADi.push_back(_form_ILOAD(inp.at(9 + NDOF + i)));
}

beuslo::beuslo() :
        beuslo(-1, 0, false, 0, 0, 0, 0, 0, {}, {}) {}

beuslo::beuslo(
    long const LLC, long const LOTYP, bool const COMPLX, long const LAYER,
    long const ELNO, long const NDOF, long const INTNO, long const SIDE,
    const vector<double> &RLOAD, const vector<double> &ILOAD) :
    card(), LLC(LLC), LOTYP(LOTYP), COMPLX(COMPLX),
    LAYER(LAYER), ELNO(ELNO), NDOF(NDOF), INTNO(INTNO),
    SIDE(SIDE), RLOADi(RLOAD), ILOADi(ILOAD) {
    if (!this->COMPLX && this->ILOADi.size() > 0)
        throw errors::usage_error(
        "BEUSLO", "ILOAD data given with COMPLX == false");
    else if (this->COMPLX  && this->ILOADi.size() == 0)
        throw errors::usage_error(
        "BEUSLO", "no ILOAD data given with COMPLX == True");
    if (this->RLOADi.size() != size_t(this->NDOF))
        throw errors::usage_error(
        "BEUSLO", "RLOAD not of size NDOF");
    if (this->ILOADi.size() > 0 &&
        this->ILOADi.size() != size_t(this->NDOF))
        throw errors::usage_error(
        "BEUSLO", "ILOAD not of size NDOF");
}

beuslo::beuslo(
    long const LLC, long const LOTYP, bool const COMPLX, long const LAYER,
    long const ELNO, long const INTNO, long const SIDE,
    const vector<double> &RLOAD, const vector<double> &ILOAD) :
    beuslo(LLC, LOTYP, COMPLX, LAYER, ELNO, static_cast<long>(RLOAD.size()),
    INTNO, SIDE, RLOAD, ILOAD) {}

beuslo::beuslo(
    long const LLC, long const LOTYP, long const LAYER, long const ELNO,
    long const NDOF, long const INTNO, long const SIDE,
    const vector<double> &RLOAD, const vector<double> &ILOAD) :
    beuslo(LLC, LOTYP, ILOAD.size() > 0, LAYER, ELNO, NDOF, INTNO,
    SIDE, RLOAD, ILOAD) {}

beuslo::beuslo(
    long const LLC, long const LOTYP, long const LAYER, long const ELNO,
    long const INTNO, long const SIDE, const vector<double> &RLOAD,
    const vector<double> &ILOAD) :
    beuslo(LLC, LOTYP, ILOAD.size() > 0, LAYER, ELNO,
    static_cast<long>(RLOAD.size()), INTNO, SIDE, RLOAD, ILOAD) {}

cards::types beuslo::card_type() const {
    return types::BEUSLO;
}

ostream &beuslo::put(ostream &os) const {
    if (LLC == -1) return os;
    os << head.format()
        << _form_LLC.format(LLC) << _form_LOTYP.format(LOTYP)
        << _form_COMPLX.format(COMPLX) << _form_LAYER.format(LAYER) << endl
        << fem::types::card().format()
        << _form_ELNO.format(ELNO) << _form_NDOF.format(NDOF)
        << _form_INTNO.format(INTNO) << _form_SIDE.format(SIDE) << endl
        << fem::types::card().format();
    size_t num{0};
    for (int i{0}; i < NDOF; i++) {
        if (!(num++ % 4) && num != 1)
            os << endl
            << fem::types::card().format();
        os << _form_RLOAD.format(RLOADi.at(i));
    }
    if (COMPLX) {
        for (size_t i{0}; i < static_cast<size_t>(NDOF); i++) {
            if (!(num++ % 4))
                os << endl << fem::types::card().format();
            os << _form_ILOAD.format(ILOADi.at(i));
        }
    }
    os << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
