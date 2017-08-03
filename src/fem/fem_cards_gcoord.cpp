/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `GCOORD` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_cards_gcoord[] _EXTFEMIO_UNUSED =
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
using namespace cards;
using namespace types;

const card gcoord::head("GCOORD");

const entry_type<long> gcoord::_form_NODENO("NODENO");
const entry_type<double> gcoord::_form_XCOORD("XCOORD");
const entry_type<double> gcoord::_form_YCOORD("YCOORD");
const entry_type<double> gcoord::_form_ZCOORD("ZCOORD");

gcoord::gcoord(const vector<std::string> &inp, size_t const len) {
    this->gcoord::read(inp, len);
}

void gcoord::read(const vector<std::string> &inp, size_t const len) {
    if (len < 5)
        throw errors::parse_error(
            "GCOORD", "Illegal number of entries.");

    NODENO = _form_NODENO(inp.at(1));
    XCOORD = _form_XCOORD(inp.at(2));
    YCOORD = _form_YCOORD(inp.at(3));
    ZCOORD = _form_ZCOORD(inp.at(4));
}

gcoord::gcoord() : gcoord(-1, 0., 0., 0.) {}

gcoord::gcoord(
    long const NODENO,
    double const XCOORD, double const YCOORD, double const ZCOORD) :
        NODENO(NODENO),
        XCOORD(XCOORD), YCOORD(YCOORD), ZCOORD(ZCOORD) {}

 cards::types
gcoord::card_type() const {return types::GCOORD;}

ostream &gcoord::put(ostream& os) const {
    if (NODENO == -1) return os;
    os << head.format()
       << _form_NODENO.format(NODENO)
       << _form_XCOORD.format(XCOORD)
       << _form_YCOORD.format(YCOORD)
       << _form_ZCOORD.format(ZCOORD);
    return os << endl;
}

cards::__base::card const &gcoord::operator() (
    long const NODENO,
    double const XCOORD, double const YCOORD, double const ZCOORD) {
    this->NODENO = NODENO;
    this->XCOORD = XCOORD;
    this->YCOORD = YCOORD;
    this->ZCOORD = ZCOORD;
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
