/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PSHELL cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

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
using type_bounds::bound;

namespace {
    auto const cl0_ = make_shared<long>(0);
    auto const cl1_ = make_shared<long>(1);
    auto const cl_1_ = make_shared<long>(-1);
    auto const cd0_ = make_shared<double>(0.);
    auto const cd1_ = make_shared<double>(1.);
    auto const cd833_ = make_shared<double>(.833333);

    auto const cl0 = cl0_.get();
    auto const cl1 = cl1_.get();
    auto const cl_1 = cl_1_.get();
    auto const cd0 = cd0_.get();
    auto const cd1 = cd1_.get();
    auto const cd833 = cd833_.get();
}

bdf::types::card pshell::head = bdf::types::card("PSHELL");

// entry_type<long> pshell::form_PID(
//     "PID", bound<long>(cl1));
namespace {
    auto const bound_MID1_ = make_shared<bound<long>>(
        cl0, nullptr, nullptr, true);
    auto const bound_MID1 = bound_MID1_.get();
}
entry_type<long> pshell::form_MID1("MID1", bound_MID1);
namespace {
    auto const bound_T_ = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
    auto const bound_T = bound_T_.get();
}
entry_type<double> pshell::form_T("T", bound_T);
namespace {
    auto const bound_MID2_ = make_shared<bound<long>>(
        cl_1, nullptr, nullptr, true);
    auto const bound_MID2 = bound_MID2_.get();
}
entry_type<long> pshell::form_MID2("MID2", bound_MID2);
namespace {
    auto const bound_12I_T__3_ = make_shared<bound<double>>(
        cd0, nullptr, cd1, true);
    auto const bound_12I_T__3 = bound_12I_T__3_.get();
}
entry_type<double> pshell::form_12I_T__3("12I/T**3", bound_12I_T__3);
namespace {
    auto const bound_MID3_ = make_shared<bound<long>>(
        cl1, nullptr, nullptr, true);
    auto const bound_MID3 = bound_MID3_.get();
}
entry_type<long> pshell::form_MID3("MID3", bound_MID3);
namespace {
    auto const bound_TS_T_ = make_shared<bound<double>>(
        cd0, nullptr, cd833, true);
    auto const bound_TS_T = bound_TS_T_.get();
}
entry_type<double> pshell::form_TS_T("TS/T", bound_TS_T);
namespace {
    auto const bound_NSM_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_NSM = bound_NSM_.get();
}
entry_type<double> pshell::form_NSM("NSM", bound_NSM);
namespace {
    auto const bound_Z1_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_Z1 = bound_Z1_.get();
}
entry_type<double> pshell::form_Z1("Z1", bound_Z1);
namespace {
    auto const bound_Z2_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_Z2 = bound_Z2_.get();
}
entry_type<double> pshell::form_Z2("Z2", bound_Z2);
namespace {
    auto const bound_MID4_ = make_shared<bound<long>>(
        cl1, nullptr, nullptr, true);
    auto const bound_MID4 = bound_MID4_.get();
}
entry_type<long> pshell::form_MID4("MID4", bound_MID4);

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
    if(T || MID2 || x12I_T__3 || MID3 || TS_T || NSM || Z1 || Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(format<double>(form_T, T)));
    if(MID2 || x12I_T__3 || MID3 || TS_T || NSM || Z1 || Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(format<long>(form_MID2, MID2)));
    if(x12I_T__3 || MID3 || TS_T || NSM || Z1 || Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(
                          format<double>(form_12I_T__3, x12I_T__3)));
    if(MID3 || TS_T || NSM || Z1 || Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(format<long>(form_MID3, MID3)));
    if(TS_T || NSM || Z1 || Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(format<double>(form_TS_T, TS_T)));
    if(NSM || Z1 || Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(format<double>(form_NSM, NSM)));
    if(Z1 || Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(format<double>(form_Z1, Z1)));
    if(Z2 || MID4)
        res.push_back(unique_ptr<format_entry>(format<double>(form_Z2, Z2)));
    if(MID4)
        res.push_back(unique_ptr<format_entry>(format<long>(form_MID4, MID4)));
}

void pshell::check_data() {
    // this->property::check_data();
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
