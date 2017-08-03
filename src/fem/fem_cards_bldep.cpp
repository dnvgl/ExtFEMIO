/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Processing Sesam FEM `BLDEP` cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_fem_cards_bldep[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <cassert>

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
using namespace cards;

const card bldep::head("BLDEP");

const entry_type<long> bldep::_form_NODENO("NODENO");
const entry_type<long> bldep::_form_CNOD("CNOD");
const entry_type<long> bldep::_form_NDDOF("NDDOF");
const entry_type<long> bldep::_form_NDEP("NDEP");
const entry_type<long> bldep::_form_DEPDOF("DEPDOF");
const entry_type<long> bldep::_form_INDEPDOF("INDEPDOF");
const entry_type<double> bldep::_form_b("b");

bldep::bldep(const vector<std::string> &inp, size_t const len) {
    bldep::read(inp, len);
}

void bldep::read(const vector<std::string> &inp, size_t const len) {
    if (len < 9)
        throw errors::parse_error(
            "BLDEP", "Illegal number of entries.");

    NODENO = _form_NODENO(inp.at(1));
    CNOD = _form_CNOD(inp.at(2));
    NDDOF = _form_NDDOF(inp.at(3));
    NDEP = _form_NDEP(inp.at(4));
    if (NDDOF == 0) NDDOF = NDEP;

    for (long i{0}; i < NDEP * 4; i += 4) {
        DEPDOF.push_back(_form_DEPDOF(inp.at(i + 5)));
        INDEPDOF.push_back(_form_INDEPDOF(inp.at(i + 6)));
        b.push_back(_form_b(inp.at(i + 7)));
    }
}

bldep::bldep() :
        bldep(-1, 0, 0, 0, {}, {}, {}) {}

bldep::bldep(
    long const NODENO, long const CNOD, long const NDDOF, long const NDEP,
    vector<long> const &DEPDOF, vector<long> const &INDEPDOF,
    vector<double> const &b) :
        NODENO(NODENO), CNOD(CNOD), NDDOF(NDDOF), NDEP(NDEP),
        DEPDOF(DEPDOF), INDEPDOF(INDEPDOF), b(b) {
    assert(DEPDOF.size() == INDEPDOF.size());
    assert(DEPDOF.size() == b.size());
}

bldep::bldep(
    long const NODENO, long const CNOD, long const NDDOF,
    vector<long> const &DEPDOF, vector<long> const &INDEPDOF,
    vector<double> const &b) :
        bldep(NODENO, CNOD, NDDOF,
              static_cast<long>(DEPDOF.size()),
              DEPDOF, INDEPDOF, b) {}

bldep::bldep(
    long const NODENO, long const CNOD,
    vector<long> const &DEPDOF, vector<long> const &INDEPDOF,
    vector<double> const &b) :
        bldep(NODENO, CNOD, static_cast<long>(DEPDOF.size()),
              static_cast<long>(DEPDOF.size()),
              DEPDOF, INDEPDOF, b) {}

cards::types bldep::card_type() const {
    return types::BLDEP;
}

ostream &bldep::put(ostream& os) const {
    if (NODENO == -1) return os;
    os << head.format()
       << _form_NODENO.format(NODENO) << _form_CNOD.format(CNOD)
       << _form_NDDOF.format(NDDOF) << _form_NDEP.format(NDEP) << endl;
    for (size_t i{0}; i < static_cast<size_t>(NDEP); i++)
        os << fem::types::card().format()
           << _form_DEPDOF.format(DEPDOF.at(i))
           << _form_INDEPDOF.format(INDEPDOF.at(i))
           << _form_b.format(b.at(i)) << empty.format() << endl;
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
