/**
   \file bdf/bdf_cards_pshell.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PSHELL cards.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_pshell[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/errors.h"

#include <memory>

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
    const long cl1 = 1, cl_1 = -1;
    const double cd0 = 0., cd1 = 1., cd833 = .833333;
}

bdf::types::card pshell::head = bdf::types::card("PSHELL");

// const entry_type<long> pshell::form_PID(
//     "PID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> pshell::form_MID1(
    "MID1",
    bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));
const entry_type<double> pshell::form_T(
    "T",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<long> pshell::form_MID2(
    "MID2",
    bdf::type_bounds::bound<long>(&cl_1, nullptr, nullptr, true));
const entry_type<double> pshell::form_12I_T__3(
    "12I/T**3",
    bdf::type_bounds::bound<double>(&cd0, nullptr, &cd1));
const entry_type<long> pshell::form_MID3(
    "MID3",
    bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));
const entry_type<double> pshell::form_TS_T(
    "TS/T", bdf::type_bounds::bound<double>(&cd0, nullptr, &cd833));
const entry_type<double> pshell::form_NSM(
    "NSM",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pshell::form_Z1(
    "Z1",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pshell::form_Z2(
    "Z2",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<long> pshell::form_MID4(
    "MID4",
    bdf::type_bounds::bound<long>(&cl1, nullptr, nullptr, true));

pshell::pshell() : property() {}

pshell::pshell(const std::list<std::string> &inp) :
        property(inp) {
    this->pshell::read(inp);
}

pshell::pshell(long const *PID, long const *MID1,
               double const *T/*=nullptr*/, long const *MID2/*=nullptr*/,
               double const *x12I_T__3/*=nullptr*/, // 12 I / T**3
               long const *MID3/*=nullptr*/,
               double const *TS_T/*=nullptr*/, // TS / T
               double const *NSM/*=nullptr*/,
               double const *Z1/*=nullptr*/, double const *Z2/*=nullptr*/,
               long const *MID4/*=nullptr*/) : property(PID),
    MID1(MID1), T(T), MID2(MID2), x12I_T__3(x12I_T__3), MID3(MID3),
    TS_T(TS_T), NSM(NSM), Z1(Z1), Z2(Z2), MID4(MID4) {
    this->pshell::check_data();
}

void pshell::read(const std::list<std::string> &inp) {
    auto pos = inp.rbegin();

    form_MID4.set_value(MID4, "");
    form_Z2.set_value(Z2, "");
    form_Z1.set_value(Z1, "");
    form_NSM.set_value(NSM, "");
    form_TS_T.set_value(TS_T, "");
    form_MID3.set_value(MID3, "");

    switch (inp.size() - 1) {
    case 16:
        ++pos;
    case 15:
        ++pos;
    case 14:
        ++pos;
    case 13:
        ++pos;
    case 12:
        ++pos;
    case 11:
        form_MID4.set_value(MID4, *(pos++));
    case 10:
        form_Z2.set_value(Z2, *(pos++));
    case 9:
        form_Z1.set_value(Z1, *(pos++));
    case 8:
        form_NSM.set_value(NSM, *(pos++));
    case 7:
        form_TS_T.set_value(TS_T, *(pos++));
    case 6:
        form_MID3.set_value(MID3, *(pos++));
    case 5:
        form_12I_T__3.set_value(x12I_T__3, *(pos++));
        form_MID2.set_value(MID2, *(pos++));
        form_T.set_value(T, *(pos++));
        form_MID1.set_value(MID1, *pos);
        // form_PID.set_value(PID, *pos);
        break;
    default:
        throw errors::parse_error("PSHELL", "Illegal number of entries.");
    }
}

cards::types pshell::card_type() const {
    return cards::types::PSHELL;
};

card const &pshell::operator() (
    long const *PID, long const *MID1, double const *T/*=nullptr*/,
    long const *MID2/*=nullptr*/, double const *x12I_T__3/*=nullptr*/, // 12 I / T**3
    long const *MID3/*=nullptr*/,
    double const *TS_T/*=nullptr*/, // TS / T
    double const *NSM/*=nullptr*/,
    double const *Z1/*=nullptr*/, double const *Z2/*=nullptr*/,
    long const *MID4/*=nullptr*/) {
    this->property::operator() (PID);
    this->MID1(MID1);
    this->T(T);
    this->MID2(MID2);
    this->x12I_T__3(x12I_T__3);
    this->MID3(MID3);
    this->TS_T(TS_T);
    this->NSM(NSM);
    this->Z1(Z1);
    this->Z2(Z2);
    this->MID4(MID4);
    this->pshell::check_data();
    return *this;
}

void pshell::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    if (!PID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID1, MID1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_T, T)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID2, MID2)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_12I_T__3, x12I_T__3)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID3, MID3)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_TS_T, TS_T)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_NSM, NSM)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_Z1, Z1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_Z2, Z2)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID4, MID4)));
}

void pshell::check_data() const {
    this->property::check_data();
    if (MID1) form_MID1.check(this->MID1);
    if (T) form_T.check(this->T);
    if (MID2) form_MID2.check(this->MID2);
    if (x12I_T__3) form_12I_T__3.check(this->x12I_T__3);
    if (MID3) form_MID3.check(this->MID3);
    if (TS_T) form_TS_T.check(this->TS_T);
    if (NSM) form_NSM.check(this->NSM);
    if (Z1) form_Z1.check(this->Z1);
    if (Z2) form_Z2.check(this->Z2);
    if (MID4) form_MID4.check(this->MID4);
}

cards::__base::card const &pshell::operator() (list<std::string> const &inp) {
    this->property::read(inp);
    this->pshell::read(inp);
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
