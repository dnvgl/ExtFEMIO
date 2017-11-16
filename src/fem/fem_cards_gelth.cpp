/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GELTH` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_fem_cards_gelth[]) =
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

card const gelth::head("GELTH");

// const entry_type<long> gelth::_form_GEONO("GENO");
entry_type<double> const gelth::_form_TH("TH");
entry_type<long> const gelth::_form_NINT("NINT");

gelth::gelth(const vector<std::string> &inp, size_t const len) :
        geoprop(inp, len) {
    __base::card::this_type = types::GELTH;
    gelth::read(inp, len);
}

void gelth::read(const vector<std::string> &inp, size_t const len) {
    std::string static const empty{"                "};

    if (len < 4)
        throw errors::parse_error(
            "GELTH", "Illegal number of entries.");

    TH = _form_TH(inp.at(2));
    if (len > 3 && inp.at(3) != empty)
        NINT = _form_NINT(inp[3]);
    else
        NINT = {0};
}

gelth::gelth() : gelth(-1, 0.) {}

gelth::gelth(
    long const GEONO,
    double const TH, long const NINT/*=0*/) :
        geoprop(GEONO), TH(TH), NINT(NINT) {
    __base::card::this_type = types::GELTH;
}

gelth::gelth(
    double const TH, long const NINT/*=0*/) :
        gelth(0, TH, NINT) {}

cards::__base::card const &gelth::operator() (
    long const GEONO, double const TH,
    long const NINT/*=0*/) {
    set_geono(GEONO);
    this->TH = TH;
    this->NINT = NINT;
    return *this;
}

cards::__base::card const &gelth::operator() (
    double const TH, long const NINT/*=0*/) {
    return (*this)(0, TH, NINT);
}

ostream &gelth::put(ostream& os) const {
    if (GEONO == -1) return os;
    os << head.format()
       << _form_GEONO.format(GEONO)
       << _form_TH.format(TH);
    if (NINT)
        os << _form_NINT.format(NINT);
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
