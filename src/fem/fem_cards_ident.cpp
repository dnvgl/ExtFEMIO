/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `IDENT` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_fem_cards_ident[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/types.h"
#include "fem/errors.h"

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

card const ident::head("IDENT");

entry_type<long> const ident::_form_SLEVEL("SLEVEL");
entry_type<long> const ident::_form_SELTYP("SELTYP");
entry_type<long> const ident::_form_SELMOD("SELMOD");

ident::ident(const vector<std::string> &inp, size_t const len) :
        __base::card(types::IDENT) {
    ident::read(inp, len);
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
        throw errors::parse_error(
            "IDENT", "Error in selmod, value not 0, 2, or 3.");
    }
}

ident::ident() : ident(-1, 0, mod_type::INVALID) {}

ident::ident(
    long const SLEVEL, long const SELTYP, mod_type const SELMOD) :
        __base::card(types::IDENT),
        SLEVEL(SLEVEL), SELTYP(SELTYP), SELMOD(SELMOD) {};

ostream &ident::put(ostream& os) const {
    if (SELMOD == mod_type::INVALID) return os;
    os << head.format()
       << _form_SLEVEL.format(SLEVEL) << _form_SELTYP.format(SELTYP)
       << _form_SELMOD.format(static_cast<long>(SELMOD)) << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
