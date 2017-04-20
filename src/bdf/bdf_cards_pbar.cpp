/**
   \file bdf/bdf_cards_pbar.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBAR cards.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_bdf_cards_pbar[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <memory>

#include "bdf/cards.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
    double const cd0 = 0.;
}

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;
using bdf::types::entry_type;;

entry_type<double> const pbar::form_A(
    "A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_I1(
    "I1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_I2(
    "I2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_J(
    "J", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_NSM(
    "NSM", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_C1(
    "C1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_C2(
    "C2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_D1(
    "D1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_D2(
    "D2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_E1(
    "E1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_E2(
    "E2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_F1(
    "F1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_F2(
    "F2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));
entry_type<double> const pbar::form_K1(
    "K1", bdf::type_bounds::bound<double>(
    nullptr, nullptr, nullptr, true));
entry_type<double> const pbar::form_K2(
    "K2", bdf::type_bounds::bound<double>(
    nullptr, nullptr, nullptr, true));
entry_type<double> const pbar::form_I12(
    "I12", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));

pbar::pbar(list<std::string> const &inp) :
bar_prop(inp) {
    this->pbar::read(inp);
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
    throw not_implemented(__FILE__, __LINE__, "can't write PBAR.");
}

cards::__base::card const &pbar::operator() (list<std::string> const &inp) {
    this->pbar::read(inp);
    return *this;
}

void pbar::check_data() const {
    this->bar_prop::check_data();
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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
