/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PROD cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_prod[] _EXTFEMIO_UNUSED =
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
using namespace cards;
using type_bounds::bound;
using bdf::types::entry_type;

/// Constant values used in bound definitions.
namespace {
    auto const cl1_ = make_shared<long>(1);
    auto const cd0_ = make_shared<double>(0.);
    auto const cl1 = cl1_.get();
    auto const cd0 = cd0_.get();
}

bdf::types::card prod::head = bdf::types::card("PROD");

// PID is defined in parent class.
// const entry_type<long> prod::form_PID(
//     "PID", bound<long>(cl1));
namespace {
    auto const bound_MID_ = make_shared<bound<long>>(cl1);
    auto const bound_MID = bound_MID_.get();
}
entry_type<long> prod::form_MID("MID", bound_MID);
entry_type<double> prod::form_A("A");
namespace {
    auto const bound_J_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_J = bound_J_.get();
    }
entry_type<double> prod::form_J("J", bound_J);
namespace {
    auto const bound_C_ = make_shared<bound<double>>(nullptr, nullptr, cd0, true);
    auto const bound_C = bound_C_.get();
}
entry_type<double> prod::form_C("C", bound_C);
namespace {
    auto const bound_NSM_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_NSM = bound_NSM_.get();
}
entry_type<double> prod::form_NSM("NSM", bound_NSM);

prod::prod(list<std::string> const &inp) :
        property(inp) {
    this->prod::read(inp);
}

prod::prod(long *PID, long *MID,
           double *A, double *J, double *C, double *NSM) :
        property(PID), MID(MID), A(A), J(J), C(C), NSM(NSM) {
    this->prod::check_data();
}

void prod::read(list<std::string> const &inp) {

    auto pos = inp.rbegin();

    form_J.set_value(J, "");
    form_C.set_value(C, "");
    form_NSM.set_value(NSM, "");

    switch (inp.size() - 1) {
    case 8:
        ++pos;
    case 7:
        ++pos;
    case 6:
        form_NSM.set_value(NSM, *(pos++));
    case 5:
        form_C.set_value(C, *(pos++));
    case 4:
        form_J.set_value(J, *(pos++));
    case 3:
        form_A.set_value(A, *(pos++));
        form_MID.set_value(MID, *pos);
        // form_PID.set_value(PID, *(pos));
        break;
    default:
        throw errors::parse_error(
            "PROD.", "Illegal number of entries.");
    }

    if (!C.is_value) form_C.set_value(C, "");
}

cards::types prod::card_type() const {
    return cards::types::PROD;
}

void prod::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
        if (!PID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID, MID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_A, A)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(J) ? format<double>(form_J, J) : format(empty)));
    res.push_back(
        unique_ptr<format_entry>(
            bool(C) ? format<double>(form_C, C) : format(empty)));
    if(bool(NSM))
        res.push_back(unique_ptr<format_entry>(format<double>(form_NSM, NSM)));
}

void prod::check_data() {
    // this->property::check_data();
    if (MID) prod::form_MID.check(MID);
    if (A) prod::form_A.check(A);
    if (J) prod::form_J.check(J);
    if (C) prod::form_C.check(C);
    if (NSM) prod::form_NSM.check(NSM);
}

cards::__base::card const &prod::operator() (list<std::string> const &inp) {
    this->property::read(inp);
    this->prod::read(inp);
    return *this;
}

cards::__base::card const &prod::operator() (
    long *PID, long *MID,
    double *A, double *J, double *C, double *NSM) {
    this->property::operator()(PID);
    this->MID(MID);
    this->A(A);
    this->J(J);
    this->C(C);
    this->NSM(NSM);
    this->prod::check_data();
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
