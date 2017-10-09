/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `HIERARCH` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_fem_cards_hierarch[]) =
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

card const hierarch::head("HIERARCH");

entry_type<long> const hierarch::_form_NFIELD("NFIELD");
entry_type<long> const hierarch::_form_IHREF("IHREF");
entry_type<long> const hierarch::_form_ISELTY("ISELTY");
entry_type<long> const hierarch::_form_INDSEL("INDSEL");
entry_type<long> const hierarch::_form_ISLEVL("ISLEVL");
entry_type<long> const hierarch::_form_ITREF("ITREF");
entry_type<long> const hierarch::_form_IHPREF("IHPREF");
entry_type<long> const hierarch::_form_NSUB("NSUB");
entry_type<long> const hierarch::_form_IHSREF("IHSREF");

hierarch::hierarch(vector<std::string> const &inp, size_t const len) {
    hierarch::read(inp, len);
}

void hierarch::read(vector<std::string> const &inp, size_t const len) {
    if (len < 10)
        throw errors::parse_error(
            "HIERARCH", "Illegal number of entries.");

    NFIELD = _form_NFIELD(inp.at(1));
    IHREF = _form_IHREF(inp.at(2));
    ISELTY = _form_ISELTY(inp.at(3));
    INDSEL = _form_INDSEL(inp.at(4));
    ISLEVL = _form_ISLEVL(inp.at(5));
    ITREF = _form_ITREF(inp.at(6));
    IHPREF = _form_IHPREF(inp.at(7));
    NSUB = _form_NSUB(inp.at(8));
    for (long i = 0; i < NSUB; i++)
        IHSREFi.push_back(_form_IHSREF(inp.at(9 + i)));
}

hierarch::hierarch() : hierarch(-1, 0, 0, 0, 0, 0, 0, {}) {}

hierarch::hierarch(
    long const NFIELD, long const IHREF, long const ISELTY, long const INDSEL,
    long const ISLEVL, long const ITREF, long const IHPREF, long const NSUB,
    vector<long> const &IHSREF) :
        card(), NFIELD(NFIELD), IHREF(IHREF), ISELTY(ISELTY), INDSEL(INDSEL),
        ISLEVL(ISLEVL), ITREF(ITREF), IHPREF(IHPREF), NSUB(NSUB),
        IHSREFi(IHSREF) {
    if (this->IHSREFi.size() != size_t(this->NSUB))
        throw errors::usage_error(
            "HIERARCH", "IHSREF not of size NSUB");
}

hierarch::hierarch(
    long const NFIELD, long const IHREF, long const ISELTY, long const INDSEL,
    long const ISLEVL, long const ITREF, long const IHPREF,
    vector<long> const &IHSREF) :
        card(), NFIELD(NFIELD), IHREF(IHREF), ISELTY(ISELTY),
        INDSEL(INDSEL), ISLEVL(ISLEVL), ITREF(ITREF),
        IHPREF(IHPREF), IHSREFi(IHSREF) {
    this->NSUB = long(this->IHSREFi.size());
}

cards::types hierarch::card_type() const {
    return types::HIERARCH;
}

ostream &hierarch::put(ostream& os) const {
    if (NFIELD == -1) return os;
    os << head.format()
       << _form_NFIELD.format(NFIELD) << _form_IHREF.format(IHREF)
       << _form_ISELTY.format(ISELTY) << _form_INDSEL.format(INDSEL) << endl
       << fem::types::card().format()
       << _form_ISLEVL.format(ISLEVL) << _form_ITREF.format(ITREF)
       << _form_IHPREF.format(IHPREF) << _form_NSUB.format(NSUB);
    for (int i = 0; i<NSUB; i++) {
        if (!(i % 4))
            os << endl << fem::types::card().format();
        os << _form_IHSREF.format(IHSREFi[i]);
    }
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
