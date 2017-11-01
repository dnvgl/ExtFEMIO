/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBAR cards.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_bdf_cards_pbar[]) =
        "@(#) $Id$";
}

#include <memory>

#include "bdf/cards.h"
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

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;
using bdf::types::entry_type;
using bdf::type_bounds::bound;

namespace {
    auto const cd0 = make_shared<double>(0.);
}

bdf::types::card pbar::head = bdf::types::card("PBAR");

namespace {
    auto const bound_A = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_A(
    "A", bound_A);
namespace {
    auto const bound_I1 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_I1("I1", bound_I1);
namespace {
    auto const bound_I2 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_I2("I2", bound_I2);
namespace {
    auto const bound_J = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_J("J", bound_J);
namespace {
    auto const bound_NSM = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_NSM("NSM", bound_NSM);
namespace {
    auto const bound_C1 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_C1("C1", bound_C1);
namespace {
    auto const bound_C2 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_C2("C2", bound_C2);
namespace {
    auto const bound_D1 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_D1("D1", bound_D1);
namespace {
    auto const bound_D2 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_D2("D2", bound_D2);
namespace {
    auto const bound_E1 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_E1("E1", bound_E1);
namespace {
    auto const bound_E2 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_E2("E2", bound_E2);
namespace {
    auto const bound_F1 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_F1("F1", bound_F1);
namespace {
    auto const bound_F2 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_F2("F2", bound_F2);
namespace {
    auto const bound_K1 = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
}
entry_type<double> pbar::form_K1("K1", bound_K1);
namespace {
    auto const bound_K2 = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
}
entry_type<double> pbar::form_K2("K2", bound_K2);
namespace {
    auto const bound_I12 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbar::form_I12("I12", bound_I12);

pbar::pbar(list<std::string> const &inp) :
bar_prop(inp) {
    this->pbar::read(inp);
}

pbar::pbar(long const *PID, long const *MID,
           double const *A, double const *I1, double const *I2,
           double const *J/*=nullptr*/, double const *NSM/*=nullptr*/,
           double const *C1/*=nullptr*/, double const *C2/*=nullptr*/,
           double const *D1/*=nullptr*/, double const *D2/*=nullptr*/,
           double const *E1/*=nullptr*/, double const *E2/*=nullptr*/,
           double const *F1/*=nullptr*/, double const *F2/*=nullptr*/,
           double const *K1/*=nullptr*/, double const *K2/*=nullptr*/,
           double const *I12/*=nullptr*/) :
        bar_prop(PID, MID), A(A), I1(I1), I2(I2), J(J), NSM(NSM),
        C1(C1), C2(C2), D1(D1), D2(D2), E1(E1), E2(E2), F1(F1), F2(F2),
        K1(K1), K2(K2), I12(I12) {
    this->pbar::check_data();
}

void pbar::read(list<std::string> const &inp) {

    auto pos = inp.rbegin();

    form_A.set_value(A, "");
    form_I1.set_value(I1, "");
    form_I2.set_value(I2, "");
    form_J.set_value(J, "");
    form_NSM.set_value(NSM, "");
    form_C1.set_value(C1, "");
    form_C2.set_value(C2, "");
    form_D1.set_value(D1, "");
    form_D2.set_value(D2, "");
    form_E1.set_value(E1, "");
    form_E2.set_value(E2, "");
    form_F1.set_value(F1, "");
    form_F2.set_value(F2, "");
    form_K1.set_value(K1, "");
    form_K2.set_value(K2, "");
    form_I12.set_value(I12, "");

    switch (inp.size() - 1) {
    case 24:
        ++pos;
    case 23:
        ++pos;
    case 22:
        ++pos;
    case 21:
        ++pos;
    case 20:
        ++pos;
    case 19:
        form_I12.set_value(I12, *(pos++));
    case 18:
        form_K2.set_value(K2, *(pos++));
    case 17:
        form_K1.set_value(K1, *(pos++));
    case 16:
        form_F2.set_value(F2, *(pos++));
    case 15:
        form_F1.set_value(F1, *(pos++));
    case 14:
        form_E2.set_value(E2, *(pos++));
    case 13:
        form_E1.set_value(E1, *(pos++));
    case 12:
        form_D2.set_value(D2, *(pos++));
    case 11:
        form_D1.set_value(D1, *(pos++));
    case 10:
        form_C2.set_value(C2, *(pos++));
    case 9:
        form_C1.set_value(C1, *(pos++));
    case 8:
        ++pos;
    case 7:
        form_NSM.set_value(NSM, *(pos++));
    case 6:
        form_J.set_value(J, *(pos++));
    case 5:
        form_I2.set_value(I2, *(pos++));
    case 4:
        form_I1.set_value(I1, *(pos++));
    case 3:
        form_A.set_value(A, *(pos++));
    case 2:
        form_MID.set_value(MID, *(pos++));
        form_PID.set_value(PID, *(pos));
        break;
    default:
        throw errors::parse_error(
            "PBAR.", "Illegal number of entries.");
    }

    if (!J.is_value) {
        J.is_value = true;
        J.value = (I1.value + I2.value) / 2.;
    }
}

cards::types pbar::card_type() const {
    return cards::types::PBAR;
};

void pbar::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
        if (!PID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID, MID)));

    res.push_back(unique_ptr<format_entry>(format<double>(form_A, A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_I1, I1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_I2, I2)));
    if (bool(J) || bool(NSM) ||
        bool(C1) || bool(C2) || bool(D1) || bool(D2) ||
        bool(E1) || bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(J) ?
                          format<double>(form_J, J) :
                          format(empty)));
    else goto cont;
    if (bool(NSM) ||
        bool(C1) || bool(C2) || bool(D1) || bool(D2) ||
        bool(E1) || bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(NSM) ?
                          format<double>(form_NSM, NSM) :
                          format(empty)));
    else goto cont;
    if (bool(C1) || bool(C2) || bool(D1) || bool(D2) ||
        bool(E1) || bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(C1) ?
                          format<double>(form_C1, C1) :
                          format(empty)));
    else goto cont;
    if (bool(C2) || bool(D1) || bool(D2) ||
        bool(E1) || bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(C2) ?
                          format<double>(form_C2, C2) :
                          format(empty)));
    else goto cont;
    if (bool(D1) || bool(D2) ||
        bool(E1) || bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(D1) ?
                          format<double>(form_D1, D1) :
                          format(empty)));
    else goto cont;
    if (bool(D2) ||
        bool(E1) || bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(D2) ?
                          format<double>(form_D2, D2) :
                          format(empty)));
    else goto cont;
    if (bool(E1) || bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(E1) ?
                          format<double>(form_E1, E1) :
                          format(empty)));
    else goto cont;
    if (bool(E2) || bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(E2) ?
                          format<double>(form_E2, E2) :
                          format(empty)));
    else goto cont;
    if (bool(F1) || bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(F1) ?
                          format<double>(form_F1, F1) :
                          format(empty)));
    else goto cont;
    if (bool(F2) ||
        bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(F2) ?
                          format<double>(form_F2, F2) :
                          format(empty)));
    else goto cont;

    if (bool(K1) || bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(K1) ?
                          format<double>(form_K1, K1) :
                          format(empty)));
    else goto cont;
    if (bool(K2) || bool(I12))
        res.push_back(unique_ptr<format_entry>(
                          bool(K2) ?
                          format<double>(form_K2, K2) :
                          format(empty)));
    else goto cont;
    if (bool(I12))
        res.push_back(unique_ptr<format_entry>(format<double>(form_I12, I12)));
cont:
    return;}

cards::__base::card const &pbar::operator() (list<std::string> const &inp) {
    this->pbar::read(inp);
    return *this;
}

cards::__base::card const &pbar::operator() (
    long const *PID, long const *MID, double const *A,
    double const *I1, double const *I2,
    double const *J/*=nullptr*/, double const *NSM/*=nullptr*/,
    double const *C1/*=nullptr*/, double const *C2/*=nullptr*/,
    double const *D1/*=nullptr*/, double const *D2/*=nullptr*/,
    double const *E1/*=nullptr*/, double const *E2/*=nullptr*/,
    double const *F1/*=nullptr*/, double const *F2/*=nullptr*/,
    double const *K1/*=nullptr*/, double const *K2/*=nullptr*/,
    double const *I12/*=nullptr*/) {
    this->bar_prop::operator()(PID, MID);
    this->A(A);
    this->I1(I1);
    this->I2(I2);
    this->J(J);
    this->NSM(NSM);
    this->C1(C1);
    this->C2(C2);
    this->D1(D1);
    this->D2(D2);
    this->E1(E1);
    this->E2(E2);
    this->F1(F1);
    this->F2(F2);
    this->K1(K1);
    this->K2(K2);
    this->I12(I12);
    // this->bar_prop::check_data();
    this->pbar::check_data();
    return *this;
}

void pbar::check_data() {
    // this->bar_prop::check_data();
    if (A) pbar::form_A.check(A);
    if (I1) pbar::form_I1.check(I1);
    if (I2) pbar::form_I2.check(I2);
    if (J) pbar::form_J.check(J);
    if (NSM) pbar::form_NSM.check(NSM);
    if (C1) pbar::form_C1.check(C1);
    if (C2) pbar::form_C2.check(C2);
    if (D1) pbar::form_D1.check(D1);
    if (D2) pbar::form_D2.check(D2);
    if (E1) pbar::form_E1.check(E1);
    if (E2) pbar::form_E2.check(E2);
    if (F1) pbar::form_F1.check(F1);
    if (F2) pbar::form_F2.check(F2);
    if (K1) pbar::form_K1.check(K1);
    if (K2) pbar::form_K2.check(K2);
    if (I12) pbar::form_I12.check(I12);
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//  (make -C ../../cbuild test;
//   ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
