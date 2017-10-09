/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `IEND` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_iend[]) =
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

card const iend::head("IEND");

entry_type<long> const iend::_form_CONT("SLEVEL");

iend::iend(vector<std::string> const &inp, size_t const len) {
    iend::read(inp, len);
}

void iend::read(vector<std::string> const &inp, size_t const len) {
    if (len < 2)
        throw errors::parse_error(
            "IEND", "Illegal number of entries.");

    CONT = _form_CONT(inp.at(1));
}

iend::iend() : iend(-1) {}

iend::iend(long const CONT) : CONT(CONT) {}

cards::types iend::card_type() const {
    return types::IEND;
}

ostream &iend::put(ostream& os) const {
    if (CONT == -1) return os;
    os << head.format()
       << _form_CONT.format(CONT) << empty.format()
       << empty.format() << empty.format() << endl;

    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
