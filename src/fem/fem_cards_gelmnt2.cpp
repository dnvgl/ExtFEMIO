/**
   \file fem/fem_cards_gelmnt2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `GELMNT2` cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_cards_gelmnt2[] _EXTFEMIO_UNUSED
        = "@(#) $Id$";
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

card const gelmnt2::head("GELMNT2");

entry_type<long> const gelmnt2::_form_SUBNO("SUBNO");
entry_type<long> const gelmnt2::_form_SLEVEL("SLEVEL");
entry_type<long> const gelmnt2::_form_STYPE("STYPE");
entry_type<long> const gelmnt2::_form_ADDNO("ADDNO");
entry_type<double> const gelmnt2::_form_T("T");
entry_type<long> const gelmnt2::_form_NNOD("NNOD");
entry_type<long> const gelmnt2::_form_NOD("NOD");

gelmnt2::gelmnt2(const vector<std::string> &inp, size_t const len) {
    gelmnt2::read(inp, len);
}

void gelmnt2::read(const vector<std::string> &inp, size_t const len) {
    if (len < 18)
        throw errors::parse_error(
            "GELMNT2", "Illegal number of entries.");

    SUBNO = _form_SUBNO(inp.at(1));
    SLEVEL = _form_SLEVEL(inp.at(2));
    STYPE = _form_STYPE(inp.at(3));
    ADDNO = _form_ADDNO(inp.at(4));
    for (size_t i{0}; i<4; i++)
        for (size_t j{0}; j<3; j++)
            T[i][j] = _form_T(inp.at(5 + i * 3 + j));
    for (size_t i{0}; i<3; i++)
        T[i][3] = 0.;
    T[3][3] = 1.;
    NNOD = _form_NNOD(inp.at(17));
    for (size_t i{0}; i<static_cast<size_t>(NNOD); i++)
        NOD.push_back(_form_NOD(inp.at(18 + i)));
}

gelmnt2::gelmnt2() : gelmnt2(-1, 0, 0, 0, nullptr, 0, {}) {}

gelmnt2::gelmnt2(
    long const SUBNO, long const SLEVEL, long const STYPE, long const ADDNO,
    const double T[4][4], long const NNOD, const vector<long> &NOD) :
        card(), SUBNO(SUBNO), SLEVEL(SLEVEL), STYPE(STYPE),
        ADDNO(ADDNO), NNOD(NNOD), NOD(NOD) {
    if (this->NOD.size() != size_t(this->NNOD))
        throw errors::usage_error(
            "GELMNT2", "NOD not of size NNOD");
    if (T)
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                this->T[j][i] = T[j][i];
}

gelmnt2::gelmnt2(
    long const SUBNO, long const SLEVEL, long const STYPE, long const ADDNO,
    double const T[4][4], vector<long> const &NOD) :
        gelmnt2(SUBNO, SLEVEL, STYPE, ADDNO, T,
                static_cast<long>(NOD.size()), NOD) {}

gelmnt2::gelmnt2(
    long const SUBNO, long const SLEVEL, long const STYPE, long const ADDNO,
    double const T11, double const T21, double const T31, double const T12,
    double const T22, double const T32, double const T13, double const T23,
    double const T33, double const T14, double const T24, double const T34,
    long const NNOD, vector<long> const &NOD) :
        card(), SUBNO(SUBNO), SLEVEL(SLEVEL), STYPE(STYPE),
        ADDNO(ADDNO), NNOD(NNOD), NOD(NOD) {
    if (this->NOD.size() != size_t(this->NNOD))
        throw errors::usage_error(
            "GELREF2","NOD not of size NNOD");
    T[0][0] = T11;
    T[1][0] = T21;
    T[2][0] = T31;
    T[3][0] = 0.;
    T[0][1] = T12;
    T[1][1] = T22;
    T[2][1] = T32;
    T[3][1] = 0.;
    T[0][2] = T13;
    T[1][2] = T23;
    T[2][2] = T33;
    T[3][2] = 0.;
    T[0][3] = T14;
    T[1][3] = T24;
    T[2][3] = T34;
    T[3][3] = 1.;
}

gelmnt2::gelmnt2(
    long const SUBNO, long const SLEVEL, long const STYPE, long const ADDNO,
    double const T11, double const T21, double const T31, double const T12,
    double const T22, double const T32, double const T13, double const T23,
    double const T33, double const T14, double const T24, double const T34,
    vector<long> const &NOD) :
        card(), SUBNO(SUBNO), SLEVEL(SLEVEL), STYPE(STYPE),
        ADDNO(ADDNO), NOD(NOD) {
    NNOD = long(this->NOD.size());
    T[0][0] = T11;
    T[1][0] = T21;
    T[2][0] = T31;
    T[3][0] = 0.;
    T[0][1] = T12;
    T[1][1] = T22;
    T[2][1] = T32;
    T[3][1] = 0.;
    T[0][2] = T13;
    T[1][2] = T23;
    T[2][2] = T33;
    T[3][2] = 0.;
    T[0][3] = T14;
    T[1][3] = T24;
    T[2][3] = T34;
    T[3][3] = 1.;
}

cards::types gelmnt2::card_type() const {
    return types::GELMNT2;
}

ostream &gelmnt2::put(ostream& os) const {
    if (SUBNO == -1) return os;
    os << head.format()
       << _form_SUBNO.format(SUBNO) << _form_SLEVEL.format(SLEVEL)
       << _form_STYPE.format(STYPE) << _form_ADDNO.format(ADDNO) << endl
       << fem::types::card().format()
       << _form_T.format(T[0][0]) << _form_T.format(T[1][0])
       << _form_T.format(T[2][0]) << _form_T.format(T[0][1]) << endl
       << fem::types::card().format()
       << _form_T.format(T[1][1]) << _form_T.format(T[2][1])
       << _form_T.format(T[0][2]) << _form_T.format(T[1][2]) << endl
       << fem::types::card().format()
       << _form_T.format(T[2][2]) << _form_T.format(T[0][3])
       << _form_T.format(T[1][3]) << _form_T.format(T[2][3]) << endl
       << fem::types::card().format()
       << _form_NNOD.format(NNOD);
    size_t num = 1;
    for (int i = 0; i<NNOD; i++) {
        if (!(num++ % 4))
            os << endl << fem::types::card().format();
        os << _form_NOD.format(NOD[i]);
    }
    return os << endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
