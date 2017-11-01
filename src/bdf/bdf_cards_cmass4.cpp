/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF CMASS4 cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_bdf_cards_cmass4[]) =
        "@(#) $Id$";
}

#include <cassert>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

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

using dnvgl::extfem::bdf::types::entry_type;
using dnvgl::extfem::bdf::types::entry_value;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

// entry_type<long> cmass4::form_EID(
//    "EID", bdf::type_bounds::bound<long>(&cl1));
entry_type<double> cmass4::form_M("M");
entry_type<long> cmass4::form_S1("S1");
entry_type<long> cmass4::form_S2("S2");

cmass4::cmass4(list<std::string> const &inp) :
        element(inp) {
    this->cmass4::read(inp);
}

cmass4::cmass4(long *EID, double *M, long *S1, long *S2/*=nullptr*/) :
               element(EID), M(M), S1(S1), S2(S2) {
    this->cmass4::check_data();
}

cards::__base::card const &cmass4::operator() (
    long const *EID, double const *M,
    long const *S1, long const *S2/*=nullptr*/) {
    this->element::operator()(EID);
    this->M(M);
    this->S1(S1);
    this->S2(S2);
    this->cmass4::check_data();
    return *this;
}

cards::__base::card const &cmass4::operator() (
    double const *M,
    long const *S1, long const *S2/*=nullptr*/) {
    long xEID{1};
    this->element::operator()(&xEID);
    this->M(M);
    this->S1(S1);
    this->S2(S2);
    this->cmass4::check_data();
    return *this;
}

bdf::types::card cmass4::head = bdf::types::card("CMASS4");

void cmass4::read(list<std::string> const &inp) {
    auto pos = inp.begin();

    if (pos == inp.end()) goto invalid;
    ++pos;
    if (pos == inp.end()) goto invalid;
    form_EID.set_value(EID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_M.set_value(M, *(pos++));
    if (pos == inp.end()) goto end;
    form_S1.set_value(S1, *(pos++));
    if (pos == inp.end()) goto end;
    form_S2.set_value(S2, *(pos));
    goto end;

invalid:
    throw errors::parse_error("CMASS4", "Illegal number of entries.");
end:;
}

cards::types cmass4::card_type() const {
    return types::CMASS4;
}

void cmass4::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {

    if (static_cast<long>(EID) <= 0)
        return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_M, M)));
    if (S1 || S2)
        res.push_back(unique_ptr<format_entry>(format<long>(form_S1, S1)));
    if (S2)
        res.push_back(unique_ptr<format_entry>(format<long>(form_S2, S2)));

    return;
}

void cmass4::check_data() {
    if(M) form_M.check(M);
    if(S1) form_S1.check(S1);
    if(S2) form_S2.check(S2);
}

cards::__base::card const &cmass4::operator()(list<std::string> const &inp) {
    this->element::read(inp);
    this->cmass4::read(inp);
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
