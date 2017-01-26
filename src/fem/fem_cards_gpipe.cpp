/**
   \file fem/fem_cards_gpipe.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GPIPE` cards.

   Detailed description
*/
#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_gpipe[]
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
using namespace fem;
using namespace types;

using namespace dnvgl::extfem::fem::cards;

fem::types::card const gpipe::head("GPIPE");

entry_type<double> const gpipe::_form_DI("DI");
entry_type<double> const gpipe::_form_DY("DY");
entry_type<double> const gpipe::_form_T("T");
entry_type<double> const gpipe::_form_SFY("SFY");
entry_type<double> const gpipe::_form_SFZ("SFZ");
entry_type<long> const gpipe::_form_NCIR("NCIR");
entry_type<long> const gpipe::_form_NRAD("NRAD");

gpipe::gpipe(vector<std::string> const &inp, size_t const len) :
        __base::beam_prop(inp, len, false) {
    read(inp, len);
}

void gpipe::read(vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};
    if (len < 7)
        throw errors::parse_error(
            "GPIPE", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    DI = _form_DI(inp.at(2));
    DY = _form_DY(inp.at(3));
    T = _form_T(inp.at(4));
    SFY = _form_SFY(inp.at(5));
    SFZ = _form_SFZ(inp.at(6));
    if (len > 7 && inp.at(7) != empty)
        NCIR = _form_NCIR(inp[7]);
    else
        NCIR = {0};

    if (len > 8 && inp.at(8) != empty)
        NRAD = _form_NRAD(inp[8]);
    else
        NRAD = {0};
}

gpipe::gpipe(void) :
        gpipe(-1, 0., 0., 0., 0., 0.) {}

gpipe::gpipe(long const GEONO, double const DI,
             double const DY,
             double const T, double const SFY,
             double const SFZ,
             long const NCIR/*=0*/, long const NRAD/*=0*/) :
        __base::beam_prop(GEONO),
        DI(DI), DY(DY), T(T),
        SFY(SFY), SFZ(SFZ),
        NCIR(NCIR), NRAD(NRAD) {}

dnvgl::extfem::fem::cards::types const
gpipe::card_type(void) const {
    return types::GPIPE;
}

ostream &gpipe::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << gpipe::head.format()
       << _form_GEONO.format(GEONO) << _form_DI.format(DI)
       << _form_DY.format(DY) << _form_T.format(T) << endl
       << dnvgl::extfem::fem::types::card().format()
       << _form_SFY.format(SFY) << _form_SFZ.format(SFZ);
    if ((NCIR || NRAD))
        os << _form_NCIR.format(NCIR) << _form_NRAD.format(NRAD);
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
