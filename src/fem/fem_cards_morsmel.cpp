/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `MORSMEL` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards_morsmel[]) =
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

card const morsmel::head("MORSMEL");

// entry_type<long> const morsmel::_form_MATNO("MATNO");
entry_type<double> const morsmel::_form_Q1("Q1");
entry_type<double> const morsmel::_form_Q2("Q2");
entry_type<double> const morsmel::_form_Q3("Q3");
entry_type<double> const morsmel::_form_RHO("RHO");
entry_type<double> const morsmel::_form_D11("D11");
entry_type<double> const morsmel::_form_D21("D21");
entry_type<double> const morsmel::_form_D22("D22");
entry_type<double> const morsmel::_form_D31("D31");
entry_type<double> const morsmel::_form_D32("D32");
entry_type<double> const morsmel::_form_D33("D33");
entry_type<double> const morsmel::_form_PS1("PS1");
entry_type<double> const morsmel::_form_PS2("PS2");
entry_type<double> const morsmel::_form_DAMP1("DAMP1");
entry_type<double> const morsmel::_form_DAMP2("DAMP2");
entry_type<double> const morsmel::_form_ALPHA1("ALPHA1");
entry_type<double> const morsmel::_form_ALPHA2("ALPHA2");

morsmel::morsmel(vector<std::string> const &inp, size_t const len) :
        material(inp, len) {
    morsmel::read(inp, len);
}

void morsmel::read(vector<std::string> const &inp, size_t const len) {
    if (len < 17)
        throw errors::parse_error(
            "MORSMEL", "Illegal number of entries.");

    Q1 = _form_Q1(inp.at(2));
    Q2 = _form_Q2(inp.at(3));
    Q3 = _form_Q3(inp.at(4));
    RHO = _form_RHO(inp.at(5));
    D11 = _form_D11(inp.at(6));
    D21 = _form_D21(inp.at(7));
    D22 = _form_D22(inp.at(8));
    D31 = _form_D31(inp.at(9));
    D32 = _form_D32(inp.at(10));
    D33 = _form_D33(inp.at(11));
    PS1 = _form_PS1(inp.at(12));
    PS2 = _form_PS2(inp.at(13));
    DAMP1 = _form_DAMP1(inp.at(14));
    DAMP2 = _form_DAMP2(inp.at(15));
    ALPHA1 = _form_ALPHA1(inp.at(16));
    ALPHA2 = _form_ALPHA2(inp.at(17));
}

morsmel::morsmel() :
        morsmel(-1, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
                0., 0., 0., 0., 0.) {}

morsmel::morsmel(long const MATNO,
                 double const Q1, double const Q2, double const Q3,
                 double const RHO,
                 double const D11, double const D21, double const D22,
                 double const D31, double const D32, double const D33,
                 double const PS1, double const PS2,
                 double const DAMP1, double const DAMP2,
                 double const ALPHA1, double const ALPHA2) :
        material(MATNO), Q1(Q1), Q2(Q2), Q3(Q3),
    RHO(RHO),
    D11(D11), D21(D21), D22(D22), D31(D31), D32(D32),
    D33(D33),
    PS1(PS1), PS2(PS2),
    DAMP1(DAMP1), DAMP2(DAMP2),
    ALPHA1(ALPHA1), ALPHA2(ALPHA2) {}

cards::__base::card const &morsmel::operator() (
    vector<std::string> const &inp, size_t const len) {
    material::read(inp, len);
    read(inp, len);
    return *this;
}

cards::types morsmel::card_type() const {
    return types::MORSMEL;
}

ostream &morsmel::put(ostream& os) const {
    if (MATNO == -1) return os;
    os << head.format()
       << _form_MATNO.format(MATNO) << _form_Q1.format(Q1)
       << _form_Q2.format(Q2) << _form_Q3.format(Q3) << endl
       << fem::types::card().format()
       << _form_RHO.format(RHO) << _form_D11.format(D11)
       << _form_D21.format(D21) << _form_D22.format(D22) << endl
       << fem::types::card().format()
       << _form_D31.format(D31) << _form_D32.format(D32)
       << _form_D33.format(D33) << _form_PS1.format(PS1) << endl
       << fem::types::card().format()
       << _form_PS2.format(PS2) << _form_DAMP1.format(DAMP1)
       << _form_DAMP2.format(DAMP2) << _form_ALPHA1.format(ALPHA1) << endl
       << fem::types::card().format()
       << _form_ALPHA2.format(ALPHA2) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
