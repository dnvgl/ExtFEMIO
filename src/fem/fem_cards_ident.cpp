/**
   \file fem/fem_cards_ident.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `IDENT` cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    const char cID_fem_cards_ident[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#include <memory>

#include "fem/cards.h"
#include "fem/types.h"
#include "fem/errors.h"

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

fem::types::card const ident::head("IDENT");

entry_type<long> const ident::_form_SLEVEL("SLEVEL");
entry_type<long> const ident::_form_SELTYP("SELTYP");
entry_type<long> const ident::_form_SELMOD("SELMOD");

ident::ident(const vector<std::string> &inp, size_t const len) {
    read(inp, len);
}

void ident::read(const vector<std::string> &inp, size_t const len) {
    if (len < 5)
        throw errors::parse_error(
            "IDENT", "Illegal number of entries.");

    SLEVEL = _form_SLEVEL(inp.at(1));
    SELTYP = _form_SELTYP(inp.at(2));
    switch (_form_SELMOD(inp.at(3))) {
    case 0:
    case 3:
        SELMOD = mod_type::DIM_3D;
        break;
    case 2:
        SELMOD = mod_type::DIM_2D;
        break;
    default:
        throw dnvgl::extfem::fem::errors::parse_error(
            "IDENT", "Error in selmod, value not 0, 2, or 3.");
    }
}

ident::ident(void) :
        ident(-1, 0, ident::mod_type::INVALID) {}

ident::ident(long const SLEVEL, long const SELTYP,
             ident::mod_type const SELMOD) :
        SLEVEL(SLEVEL), SELTYP(SELTYP), SELMOD(SELMOD) {};

cards::types const ident::card_type(void) const {
    return types::IDENT;
}

ostream &ident::put(ostream& os) const {
    if (SELMOD == ident::mod_type::INVALID) return os;
    os << ident::head.format()
       << _form_SLEVEL.format(SLEVEL)
       << _form_SELTYP.format(SELTYP)
       << _form_SELMOD.format(static_cast<long>(SELMOD));
    return os << endl;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
