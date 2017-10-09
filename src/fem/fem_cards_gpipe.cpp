/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GPIPE` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_fem_cards_gpipe[]) =
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

card const gpipe::head("GPIPE");

entry_type<double> const gpipe::_form_DI("DI");
entry_type<double> const gpipe::_form_DY("DY");
entry_type<double> const gpipe::_form_T("T");
entry_type<double> const gpipe::_form_SFY("SFY");
entry_type<double> const gpipe::_form_SFZ("SFZ");
entry_type<long> const gpipe::_form_NCIR("NCIR");
entry_type<long> const gpipe::_form_NRAD("NRAD");

gpipe::gpipe(vector<std::string> const &inp, size_t const len) :
        beam_prop(inp, len, false) {
    gpipe::read(inp, len);
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

gpipe::gpipe() : gpipe(-1, 0., 0., 0., 0., 0.) {}

gpipe::gpipe(long const GEONO,
             double const DI, double const DY, double const T,
             double const SFY, double const SFZ,
             long const NCIR, long const NRAD) :
        beam_prop(GEONO, false),
        DI(DI), DY(DY), T(T),
        SFY(SFY), SFZ(SFZ),
        NCIR(NCIR), NRAD(NRAD) {}

cards::__base::card const &gpipe::operator() (
    long const GEONO,
    double const DI, double const DY, double const T,
    double const SFY, double const SFZ,
    long const NCIR, long const NRAD) {
    set_geono(GEONO, false);
    this->DI = DI;
    this->DY = DY;
    this->T = T;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->NCIR = NCIR;
    this->NRAD = NRAD;
    return *this;
}

cards::types gpipe::card_type() const {
    return types::GPIPE;
}

ostream &gpipe::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << _form_DI.format(DI)
       << _form_DY.format(DY) << _form_T.format(T) << endl
       << fem::types::card().format()
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
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
