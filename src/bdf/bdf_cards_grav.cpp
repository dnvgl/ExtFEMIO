/**
   \file bdf/bdf_cards_grav.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF GRAV cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

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

namespace {
   long static const cl0 = 0;
   long static const cl1 = 1;
}

using dnvgl::extfem::bdf::types::entry_type;
using dnvgl::extfem::bdf::types::entry_value;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

entry_type<long> const grav::form_SID(
    "SID", bdf::type_bounds::bound<long>(&cl1));
entry_type<long> const grav::form_CID(
    "CID", bdf::type_bounds::bound<long>(&cl0));
entry_type<double> const grav::form_A("A");
entry_type<double> const grav::form_Ni("Ni");
entry_type<long> const grav::form_MB(
    "MB",
    bdf::type_bounds::bound<long>(nullptr, nullptr, &cl0));

grav::grav(std::list<std::string> const &inp) :
card(inp) {
    this->read(inp);
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
           std::vector<double> const *N,
           long const *MB/*=nullptr*/) :
           grav(SID, CID, A, &(*N)[0], &(*N)[1], &(*N)[2], MB) {
    if (N->size() != 3)
        throw errors::error("GRAV", "N requires 3 entries.");
}

cards::__base::card const &grav::operator() (
    long const *SID, long const *CID,
    double const *A,
    std::vector<double> const *N,
    long const *MB/*=nullptr*/) {
    this->SID = *SID;
    this->CID = *CID;
    this->A = *A;
    this->N1 = (*N)[0];
    if (N->size() > 1)
        this->N2 = (*N)[1];
    else
        this->N2 = nullptr;
    if (N->size() > 2)
        this->N3 = (*N)[2];
    else
        this->N3 = nullptr;
    if (MB)
        this->MB = *MB;
    else
        this->MB = nullptr;
    return *this;
}

cards::__base::card const &grav::operator() (
    long const *SID, long const *CID,
    double const *A,
    double const *N1, double const*N2, double const *N3,
    long const *MB/*=nullptr*/) {
    this->SID = *SID;
    this->CID = *CID;
    this->A = *A;
    this->N1 = *N1;
    this->N2 = *N2;
    this->N3 = *N3;
    if (MB)
        this->MB = *MB;
    else
        this->MB = nullptr;
    return *this;
}

bdf::types::card grav::head = bdf::types::card("GRAV");

void grav::read(std::list<std::string> const &inp) {
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
    form_MB.set_value(MB, *(pos++));
    goto end;

invalid:
    throw errors::parse_error("GRAV", "Illegal number of entries.");
end:;
}

cards::types const grav::card_type(void) const {
    return types::GRAV;
}

void grav::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    if (static_cast<long>(SID) <= 0) return;
    res.push_back(format(grav::head));

    res.push_back(format<long>(form_SID, SID));
    res.push_back(format<long>(form_CID, CID));
    res.push_back(format<double>(form_A, A));
    res.push_back(format<double>(form_Ni, N1));
    res.push_back(format<double>(form_Ni, N2));
    res.push_back(format<double>(form_Ni, N3));
    if (MB)
        res.push_back(format<long>(form_MB, MB));

    return;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
