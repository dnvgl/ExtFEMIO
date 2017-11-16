/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `MISOSEL` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards_misosel[]) =
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

card const misosel::head("MISOSEL");

// entry_type<long> const misosel::_form_MATNO("MATNO");
entry_type<double> const misosel::_form_YOUNG("YOUNG");
entry_type<double> const misosel::_form_POISS("POISS");
entry_type<double> const misosel::_form_RHO("RHO");
entry_type<double> const misosel::_form_DAMP("DAMP");
entry_type<double> const misosel::_form_ALPHA("ALPHA");
entry_type<double> const misosel::_form_DUMMY("DUMMY");
entry_type<double> const misosel::_form_YIELD("YIELD");

misosel::misosel(vector<std::string> const &inp, size_t const len) :
        material(inp, len) {
    __base::card::this_type = types::MISOSEL;
    misosel::read(inp, len);
}

void misosel::read(vector<std::string> const &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 7)
        throw errors::parse_error(
            "MISOSEL", "Illegal number of entries.");

    MATNO = _form_MATNO(inp.at(1));
    YOUNG = _form_YOUNG(inp.at(2));
    POISS = _form_POISS(inp.at(3));
    RHO = _form_RHO(inp.at(4));
    DAMP = _form_DAMP(inp.at(5));
    ALPHA = _form_ALPHA(inp.at(6));
    if (len > 7 && inp.at(7) != empty)
        DUMMY = _form_DUMMY(inp[7]);
    else
        DUMMY = {0.};
    if (len > 8 && inp.at(8) != empty)
        YIELD = _form_YIELD(inp[8]);
    else
        YIELD = {0.};}

misosel::misosel() : misosel(-1, 0., 0., 0., 0., 0.) {}

misosel::misosel(long const MATNO, double const YOUNG,
                 double const POISS, double const RHO,
                 double const DAMP, double const ALPHA,
                 double const DUMMY/*=0.*/, double const YIELD/*=0.*/) :
        material(MATNO), YOUNG(YOUNG), POISS(POISS),
        RHO(RHO), DAMP(DAMP), ALPHA(ALPHA), DUMMY(DUMMY),
        YIELD(YIELD) {
    __base::card::this_type = types::MISOSEL;
}

cards::__base::card const &misosel::operator() (
    vector<std::string> const &inp, size_t const len) {
    material::read(inp, len);
    read(inp, len);
    return *this;
}

cards::__base::card const &misosel::operator() (
    long const MATNO, double const YOUNG, double const POISS,
    double const RHO, double const DAMP, double const ALPHA,
    double const DUMMY/*=0.*/, double const YIELD/*=0.*/) {
    this->MATNO = MATNO;
    this->YOUNG = YOUNG;
    this->POISS = POISS;
    this->RHO = RHO;
    this->DAMP = DAMP;
    this->ALPHA = ALPHA;
    this->DUMMY = DUMMY;
    this->YIELD = YIELD;
    return *this;
}

ostream &misosel::put(ostream& os) const {
    if (MATNO == -1) return os;
    os << head.format()
       << _form_MATNO.format(MATNO) << _form_YOUNG.format(YOUNG)
       << _form_POISS.format(POISS) << _form_RHO.format(RHO) << endl
       << fem::types::card().format()
       << _form_DAMP.format(DAMP) << _form_ALPHA.format(ALPHA);
    if ((DUMMY || YIELD))
        os << _form_DUMMY.format(DUMMY) << _form_YIELD.format(YIELD);
    os << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//     (make -C ../../cbuild test;
//      ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
