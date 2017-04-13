/**
   \file bdf/bdf_cards_crod.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Defintions for Patran CROD cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    const char cID_bdf_cards_crod[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
    const long cl1 = 1;
}

using namespace dnvgl::extfem::bdf;

using types::entry_type;
using namespace cards;

// const entry_type<long> crod::form_EID(
//    "EID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> crod::form_PID("PID");
const entry_type<long> crod::form_G1("G1");
const entry_type<long> crod::form_G2("G2");

crod::crod(std::list<std::string> const &inp) :
element(inp) {
    this->crod::read(inp);
}

cards::types crod::card_type() const {
    return types::CROD;
}

void crod::read(std::list<std::string> const &inp) {
    auto pos = inp.rbegin();

    switch (inp.size() - 1) {
    case 8:
        ++pos;
    case 7:
        ++pos;
    case 6:
        ++pos;
    case 5:
        ++pos;
    case 4:
        form_G2.set_value(G2, *(pos++));
        form_G1.set_value(G1, *(pos++));
        form_PID.set_value(PID, *(pos));
        break;
    default:
        throw errors::parse_error(
            "CROD", "Illegal number of entries for CROD");
    }
}

__base::card const& crod::operator()(
    long const* EID, long const* PID, long const* G1, long const* G2) const {
    NOT_IMPLEMENTED(nullptr);
}

void crod::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    NOT_IMPLEMENTED("Can't write CROD.");
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
