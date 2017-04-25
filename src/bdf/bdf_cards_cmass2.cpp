/**
   \file bdf/bdf_cards_cmass2.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF CMASS2 cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    char const cID_bdf_cards_cmass2[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <cassert>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
   long const cl1 = 1;
   long const cl0 = 0;
   double const cd0 = 0.;
}

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace type_bounds;
using namespace cards;
using namespace cards::__base;

using bdf::types::entry_type;

// entry_type<long> const cmass2::form_EID(
//    "EID", bdf::type_bounds::bound<long>(&cl1));
entry_type<double> const cmass2::form_M("M");
entry_type<long> const cmass2::form_G1(
   "G1", bound<long>(nullptr, nullptr, nullptr, true));
entry_type<vector<int> > const cmass2::form_C1("C1");
entry_type<long> const cmass2::form_G2(
   "G2", bound<long>(nullptr, nullptr, nullptr, true));
entry_type<vector<int> > const cmass2::form_C2("C2");

cmass2::cmass2() :
   element(nullptr),
   M(nullptr), G1(nullptr), C1(nullptr),
   G2(nullptr), C2(nullptr) {}

cmass2::cmass2(list<std::string> const &inp) :
element(inp) {
    this->cmass2::read(inp);
}

cmass2::cmass2(long const *EID, double const *M,
               long const *G1, vector<int> const *C1,
               long const *G2/*=nullptr*/, vector<int> const *C2/*=nullptr*/) :
               element(EID),
               M(M), G1(G1), C1(C1), G2(G2), C2(C2) {
    if (long(this->EID) < 1l || long(this->EID) > 100000000l)
        throw errors::error("CMASS2", "EID not in valid range");
    if (this->G1 && this->C1.value.size() == 0)
        throw errors::error("CMASS2", "G1 requires C1 value");
    if (this->G2 && this->C2.value.size() == 0)
        throw errors::error("CMASS2", "G2 requires C2 value");
}

card const &cmass2::operator() (
    long const *EID, double const *M,
    long const *G1, vector<int> const *C1,
    long const *G2/*=nullptr*/, vector<int> const *C2/*=nullptr*/) {
    this->element::operator() (EID);
    this->M(M);
    this->G1(G1);
    this->C1(C1);
    this->G2(G2);
    this->C2(C2);
    this->cmass2::check_data();
    return *this;
}

bdf::types::card cmass2::head = bdf::types::card("CMASS2");

void cmass2::read(list<std::string> const &inp) {
    auto pos = inp.begin();

    form_G1.set_value(G1, "");
    form_C1.set_value(C1, "");
    form_G2.set_value(G2, "");
    form_C2.set_value(C2, "");

    if (pos == inp.end()) goto invalid;
    ++pos;
    if (pos == inp.end()) goto invalid;
    form_EID.set_value(EID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_M.set_value(M, *(pos++));
    if (pos == inp.end()) goto end;
    form_G1.set_value(G1, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_C1.set_value(C1, *(pos++));
    if (pos == inp.end()) goto end;
    form_G2.set_value(G2, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_C2.set_value(C2, *pos);
    goto end;

invalid:
    throw errors::parse_error("CMASS2", "Illegal number of entries.");
end:;
}

cards::types cmass2::card_type() const {
    return types::CMASS2;
}

void cmass2::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {

    if (!EID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_M, M)));
    if (G1 || G2) {
        res.push_back(unique_ptr<format_entry>(format<long>(form_G1, G1)));
        res.push_back(
            unique_ptr<format_entry>(format<vector<int> >(form_C1, C1)));
    }
    if (G2) {
        res.push_back(unique_ptr<format_entry>(format<long>(form_G2, G2)));
        res.push_back(
            unique_ptr<format_entry>(format<vector<int> >(form_C2, C2)));
    }

    return;
}

cards::__base::card const &cmass2::operator()(list<std::string> const &inp) {
    this->element::read(inp);
    this->cmass2::read(inp);
    return *this;
}

void cmass2::check_data() const {
    this->element::check_data();
    if(M)  form_M.check(M);
    if(G1) form_G1.check(G1);
    if(C1) form_C1.check(C1);
    if(G2) form_G2.check(G2);
    if(C2) form_C2.check(C2);
}
// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
