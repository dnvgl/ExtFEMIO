/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF GRAV cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    char const cID_bdf_cards_grav[] _EXTFEMIO_UNUSED =
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

using namespace std;

using dnvgl::extfem::bdf::types::entry_type;
using dnvgl::extfem::bdf::types::entry_value;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;
using namespace type_bounds;

namespace {
    auto const cl0_ = make_shared<long>(0);
    auto const cl1_ = make_shared<long>(1);
    auto const cl0 = cl0_.get();
    auto const cl1 = cl1_.get();

    auto const bound_SID_ = make_shared<bound<long>>(cl1);
    auto const bound_SID = bound_SID_.get();
}
entry_type<long> grav::form_SID("SID", bound_SID);
namespace {
    auto const bound_CID_ = make_shared<bound<long>>(cl0);
    auto const bound_CID = bound_CID_.get();
}
entry_type<long> grav::form_CID("CID", bound_CID);
entry_type<double> grav::form_A("A");
entry_type<double> grav::form_Ni("Ni");
namespace {
    auto const bound_MB_ = make_shared<bound<long>>(nullptr, nullptr, cl0);
    auto const bound_MB = bound_MB_.get();
}
entry_type<long> grav::form_MB("MB", bound_MB);

grav::grav(list<std::string> const &inp) :
card(inp) {
    this->grav::read(inp);
}

grav::grav() :
        card(),
        SID(), CID(), A(), N1(), N2(), N3(), MB() {}

grav::grav(long const *SID, long const *CID, double const *A,
           double const *N1, double const *N2, double const *N3,
           long const *MB/*=nullptr*/) :
           card(),
           SID(SID), CID(CID), A(A), N1(N1), N2(N2), N3(N3), MB(MB) {}

grav::grav(long const *SID, long const *CID, double const *A,
           vector<double> const *N,
           long const *MB/*=nullptr*/) :
           grav(SID, CID, A, &(*N)[0], &(*N)[1], &(*N)[2], MB) {
    if (N->size() != 3)
        throw errors::error("GRAV", "N requires 3 entries.");
}

cards::__base::card const &grav::operator() (
    long const *SID, long const *CID,
    double const *A,
    vector<double> const *N,
    long const *MB/*=nullptr*/) {
    this->SID(SID);
    this->CID(CID);
    this->A(A);
    this->N1((*N)[0]);
    this->N2(N->size() > 1 ? &(*N)[1] : nullptr);
    this->N3(N->size() > 2 ? &(*N)[2] : nullptr);
    this->MB(MB);
    this->grav::check_data();
    return *this;
}

cards::__base::card const &grav::operator() (
    long const *SID, long const *CID,
    double const *A,
    double const *N1, double const*N2, double const *N3,
    long const *MB/*=nullptr*/) {
    this->SID(SID);
    this->CID(CID);
    this->A(A);
    this->N1(N1);
    this->N2(N2);
    this->N3(N3);
    this->MB(MB);
    this->grav::check_data();
    return *this;
}

bdf::types::card grav::head = bdf::types::card("GRAV");

void grav::read(list<std::string> const &inp) {
    auto pos = inp.begin();

    if (pos == inp.end()) goto invalid;
    ++pos;
    if (pos == inp.end()) goto invalid;
    form_SID.set_value(SID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_CID.set_value(CID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_A.set_value(A, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_Ni.set_value(N1, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_Ni.set_value(N2, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_Ni.set_value(N3, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_MB.set_value(MB, *(pos));
    goto end;

invalid:
    throw errors::parse_error("GRAV", "Illegal number of entries.");
end:;
}

cards::types grav::card_type() const {
    return types::GRAV;
}

void grav::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    if (static_cast<long>(SID) <= 0) return;
    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_SID, SID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_CID, CID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_A, A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_Ni, N1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_Ni, N2)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_Ni, N3)));
    if (MB)
        res.push_back(unique_ptr<format_entry>(format<long>(form_MB, MB)));
}

void grav::check_data() {
    if (SID) form_SID.check(SID);
    if (CID) form_CID.check(CID);
    if (A) form_A.check(A);
    if (N1) form_Ni.check(N1);
    if (N2) form_Ni.check(N2);
    if (N3) form_Ni.check(N3);
    if (MB) form_MB.check( MB);
}

cards::__base::card const &grav::operator()(list<std::string> const &inp) {
    this->grav::read(inp);
    return *this;
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
