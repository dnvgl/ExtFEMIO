/**
   \file fem/fem_cards_iend.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `IEND` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_iend[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#include <memory>

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
using namespace dnvgl::extfem::fem::cards;

const fem::types::card iend::head("IEND");

const entry_type<long> iend::_form_CONT("SLEVEL");

iend::iend(const vector<std::string> &inp, size_t const &len) {
    read(inp, len);
}

void iend::read(const vector<std::string> &inp, size_t const &len) {
    if (len < 2)
        throw errors::parse_error(
            "IEND", "Illegal number of entries.");

    auto pos = inp.begin();

    ++pos;
    CONT = _form_CONT(inp.at(1));
}

iend::iend(void) : iend(-1) {}

iend::iend(const long &CONT) : CONT(CONT) {}

const cards::types
iend::card_type(void) const { return types::IEND; };

ostream &iend::put(ostream& os) const {
    if (CONT == -1) return os;
    os << iend::head.format()
       << _form_CONT.format(CONT) << iend::empty.format()
       << iend::empty.format() << iend::empty.format() << endl;

    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
