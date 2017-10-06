/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GLSECR` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_fem_cards_glsecr[]) =
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

card const glsecr::head("GLSECR");

entry_type<double> const glsecr::_form_HZ("HZ");
entry_type<double> const glsecr::_form_TY("TY");
entry_type<double> const glsecr::_form_BY("BY");
entry_type<double> const glsecr::_form_TZ("TZ");
entry_type<double> const glsecr::_form_SFY("SFY");
entry_type<double> const glsecr::_form_SFZ("SFZ");
entry_type<long> const glsecr::_form_K("K");
entry_type<double> const glsecr::_form_R("R");
entry_type<long> const glsecr::_form_NLOBY("NLOBY");
entry_type<long> const glsecr::_form_NLOBZ("NLOBZ");

glsecr::glsecr() : glsecr(-1, 0., 0., 0., 0., 0., 0., 0, 0.) {}

glsecr::glsecr(const vector<std::string> &inp, size_t const len) :
        beam_prop(inp, len, false) {
    glsecr::read(inp, len);
}

glsecr::glsecr(
    long const GEONO,
    double const HZ, double const TY,
    double const BY, double const TZ,
    double const SFY, double const SFZ,
    long const K, double const R,
    long const NLOBY, long const NLOBZ) :
        beam_prop(GEONO, false),
        HZ{HZ}, TY{TY}, BY{BY}, TZ{TZ}, SFY{SFY}, SFZ{SFZ}, K{K}, R{R},
        NLOBY{NLOBY}, NLOBZ{NLOBZ} {}

cards::types glsecr::card_type() const {
    return types::GLSECR;
}

cards::__base::card const &glsecr::operator() (
    long const GEONO,
    double const HZ, double const TY,
    double const BY, double const TZ,
    double const SFY, double const SFZ,
    long const K, double const R,
    long const NLOBY, long const NLOBZ) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->TY = TY;
    this->BY = BY;
    this->TZ = TZ;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->K = K;
    this->R = R;
    this->NLOBY = NLOBY;
    this->NLOBZ = NLOBZ;
    return *this;
}

void glsecr::read(const vector<std::string> &inp, size_t const len) {
    std::string static const empty{"                "};
    if (len < 10)
        throw errors::parse_error(
            "GLSECR", "Illegal number of entries.");

    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    BY = _form_BY(inp.at(4));
    TZ = _form_TZ(inp.at(5));
    SFY = _form_SFY(inp.at(6));
    SFZ = _form_SFZ(inp.at(7));
    K = _form_K(inp.at(8));
    R = _form_R(inp.at(9));
    if (len >= 11 && inp.at(10) != empty)
        NLOBY = _form_NLOBY(inp[10]);
    else
        NLOBY = {0};
    if (len >= 12 && inp.at(11) != empty)
        NLOBZ = _form_NLOBZ(inp[11]);
    else
        NLOBZ = {0};
}

ostream &glsecr::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_TY.format(TY) << _form_BY.format(BY) << endl
       << fem::types::card().format()
       << _form_TZ.format(TZ) << _form_SFY.format(SFY)
       << _form_SFZ.format(SFZ) << _form_K.format(K) << endl
       << fem::types::card().format()
       << _form_R.format(R);
    if ((NLOBY || NLOBZ))
        os << _form_NLOBY.format(NLOBY) << _form_NLOBZ.format(NLOBZ);
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
