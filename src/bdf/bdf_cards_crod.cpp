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

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;
using namespace cards::__base;

using bdf::types::entry_type;

namespace {
   long const cl1 = 1;
}

bdf::types::card crod::head = bdf::types::card("CROD");

// const entry_type<long> crod::form_EID(
//    "EID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> crod::form_PID(
    "PID", bound<long>(&cl1, nullptr, nullptr, true));
const entry_type<long> crod::form_G1("G1", bound<long>(&cl1));
const entry_type<long> crod::form_G2("G2", bound<long>(&cl1));

crod::crod() : element(), PID(nullptr), G1(), G2() {}

crod::crod(list<std::string> const &inp) :
element(inp) {
    this->crod::read(inp);
}

crod::crod(long const* EID, long const* PID, long const* G1, long const* G2) :
        element(EID), PID(PID ? PID : EID), G1(G1), G2(G2) {
    this->crod::check_data();
}

cards::types crod::card_type() const {
    return types::CROD;
}

void crod::read(list<std::string> const &inp) {
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
    if (!PID) PID(EID);
}

card const& crod::operator() (
    long const* EID, long const* PID, long const* G1, long const* G2) {
    this->element::operator()(EID);
    if (PID)
        this->PID(PID);
    else
        this->PID(EID);
    this->G1(G1);
    this->G2(G2);
    this->crod::check_data();
    return *this;
}

void crod::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    if (!EID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G1, G1)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G2, G2)));
}

void crod::check_data() const {
    this->element::check_data();
    if (PID) form_PID.check(this->PID);
    if (G1) form_G1.check(this->G1);
    if (G2) form_G2.check(this->G2);
}

cards::__base::card const &crod::operator()(list<std::string> const &inp) {
    this->element::read(inp);
    this->crod::read(inp);
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test ;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
