/**
   \file fem_cards_gchan.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2017 by DNV GL SE
   \brief Processing Sesam FEM `GCHAN` cards.

   Detailed description
*/

// ID:
namespace {
   char const cID_fem_cards_gchan[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "fem/cards.h"

#include "fem/cards.h"

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
using namespace dnvgl::extfem::fem::types;

using namespace dnvgl::extfem::fem::cards;

fem::types::card const gchan::head("GCHAN");

fem::types::entry_type<double> const gchan::_form_HZ("HZ");
fem::types::entry_type<double> const gchan::_form_TY("TY");
fem::types::entry_type<double> const gchan::_form_BY("BY");
fem::types::entry_type<double> const gchan::_form_TZ("TZ");
fem::types::entry_type<double> const gchan::_form_SFY("SFY");
fem::types::entry_type<double> const gchan::_form_SFZ("SFZ");
fem::types::entry_type<long> const gchan::_form_K("K");
fem::types::entry_type<long> const gchan::_form_NLOBY("NLOBY");
fem::types::entry_type<long> const gchan::_form_NLOBZ("NLOBZ");

gchan::gchan(void) :
        gchan(-1, 0., 0., 0., 0., 0., 0., 0) {}

gchan::gchan(vector<std::string> const &inp, size_t const len) :
        __base::beam_prop(inp, len, false) {
    read(inp, len);
}

gchan::gchan(long const GEONO,
             double const HZ, double const TY, double const BY,
             double const TZ, double const SFY, double const SFZ,
             long const K, long const NLOBY/*=0*/, long const NLOBZ/*=0*/) :
        __base::beam_prop(GEONO),
        HZ{HZ}, TY{TY}, BY{BY}, TZ {TZ}, SFY{SFY}, SFZ{SFZ}, K{K},
        NLOBY{NLOBY}, NLOBZ{NLOBZ} {}

fem::cards::types const gchan::card_type(void) const {
    return types::GCHAN;
}

cards::__base::card const &gchan::operator() (
    long const GEONO,
    double const HZ, double const TY, double const BY,
    double const TZ, double const SFY, double const SFZ,
    long const K, long const NLOBY/*=0*/, long const NLOBZ/*=0*/) {
    set_geono(GEONO, false);
    this->HZ = HZ;
    this->TY = TY;
    this->BY = BY;
    this->TZ = TZ;
    this->SFY = SFY;
    this->SFZ = SFZ;
    this->K = K;
    this->NLOBY = NLOBY;
    this->NLOBZ = NLOBZ;
    return *this;
}

ostream &gchan::put(ostream &os) const {
    if (GEONO == -1) return os;
    os << gchan::head.format()
       << _form_GEONO.format(GEONO) << _form_HZ.format(HZ)
       << _form_TY.format(TY) << _form_BY.format(BY) << endl
       << fem::types::card("").format()
       << _form_TZ.format(TZ) << _form_SFY.format(SFY)
       << _form_SFZ.format(SFZ) << endl << fem::types::card("").format()
       << _form_K.format(K);
    if ((NLOBY || NLOBZ))
        os << _form_NLOBY.format(NLOBY) << _form_NLOBZ.format(NLOBZ);
    return os << endl;
};

void gchan::read(
    vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 10)
        throw errors::parse_error(
            "GCHAN", "Illegal number of entries.");

    // GEONO = _form_GEONO(inp.at(1));
    HZ = _form_HZ(inp.at(2));
    TY = _form_TY(inp.at(3));
    BY = _form_BY(inp.at(4));
    TZ = _form_TZ(inp.at(5));
    SFY = _form_SFY(inp.at(6));
    SFZ = _form_SFZ(inp.at(7));
    K= _form_K(inp.at(9));
    if (inp.at(10) != empty)
        NLOBY = _form_NLOBY(inp [10]);
    else
        NLOBY = {0};
    if (len > 12 && inp.at(11) != empty)
        NLOBZ = _form_NLOBZ(inp[11]);
    else
        NLOBZ = {0};
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
