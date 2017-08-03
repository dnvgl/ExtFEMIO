/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `HSUPTRAN` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_cards_hsuptran[] _EXTFEMIO_UNUSED =
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

card const hsuptran::head("HSUPTRAN");

entry_type<long> const hsuptran::_form_NFIELD("NFIELD");
entry_type<long> const hsuptran::_form_ITREF("ITREF");
entry_type<double> const hsuptran::_form_T("T");

hsuptran::hsuptran(const vector<std::string> &inp, size_t const len) {
    hsuptran::read(inp, len);
}

void hsuptran::read(const vector<std::string> &inp, size_t const len) {
    if (len < 15)
        throw errors::parse_error(
            "HSUPTRAN", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    ITREF = _form_ITREF(inp.at(2));
    T[0][0] = _form_T(inp.at(3));
    T[0][1] = _form_T(inp.at(4));
    T[0][2] = _form_T(inp.at(5));
    T[0][3] = _form_T(inp.at(6));
    T[1][0] = _form_T(inp.at(7));
    T[1][1] = _form_T(inp.at(8));
    T[1][2] = _form_T(inp.at(9));
    T[1][3] = _form_T(inp.at(10));
    T[2][0] = _form_T(inp.at(11));
    T[2][1] = _form_T(inp.at(12));
    T[2][2] = _form_T(inp.at(13));
    T[2][3] = _form_T(inp.at(14));
    T[3][0] = _form_T(inp.at(15));
    T[3][1] = _form_T(inp.at(16));
    T[3][2] = _form_T(inp.at(17));
    T[3][3] = _form_T(inp.at(18));
}

hsuptran::hsuptran() : hsuptran(-1, 0, nullptr) {}


hsuptran::hsuptran(
    long const NFIELD, long const ITREF,
    double const T11, double const T21, double const T31, double const T41,
    double const T12, double const T22, double const T32, double const T42,
    double const T13, double const T23, double const T33, double const T43,
    double const T14, double const T24, double const T34, double const T44) :
        card(), NFIELD(NFIELD), ITREF(ITREF) {

    T[0][0] = T11;
    T[0][1] = T21;
    T[0][2] = T31;
    T[0][3] = T41;
    T[1][0] = T12;
    T[1][1] = T22;
    T[1][2] = T32;
    T[1][3] = T42;
    T[2][0] = T13;
    T[2][1] = T23;
    T[2][2] = T33;
    T[2][3] = T43;
    T[3][0] = T14;
    T[3][1] = T24;
    T[3][2] = T34;
    T[3][3] = T44;
}

hsuptran::hsuptran(
    long const NFIELD, long const ITREF, double const T[4][4]) :
        card(), NFIELD(NFIELD), ITREF(ITREF) {
    if (this->NFIELD != -1)
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                this->T[i][j] = T[i][j];
}

cards::types hsuptran::card_type() const {
    return types::HSUPTRAN;
}

ostream &hsuptran::put(ostream& os) const {
    if (NFIELD == -1) return os;
    os << head.format()
       << _form_NFIELD.format(NFIELD) << _form_ITREF.format(ITREF)
       << _form_T.format(T[0][0]) << _form_T.format(T[0][1]) << endl
       << fem::types::card().format()
       << _form_T.format(T[0][2]) << _form_T.format(T[0][3])
       << _form_T.format(T[1][0]) << _form_T.format(T[1][1]) << endl
       << fem::types::card().format()
       << _form_T.format(T[1][2]) << _form_T.format(T[1][3])
       << _form_T.format(T[2][0]) << _form_T.format(T[2][1]) << endl
       << fem::types::card().format()
       << _form_T.format(T[2][2]) << _form_T.format(T[2][3])
       << _form_T.format(T[3][0]) << _form_T.format(T[3][1]) << endl
       << fem::types::card().format()
       << _form_T.format(T[3][2]) << _form_T.format(T[3][3]) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
