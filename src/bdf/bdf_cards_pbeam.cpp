/**
   \file bdf/bdf_cards_pbeam.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBEAM cards.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_pbeam[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/type_bounds.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef _C2
#undef _C2
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

using bdf::types::entry_type;

namespace {
    const double cd0 = 0., cd1 = 1.;
}

bdf::types::card pbeam::head = bdf::types::card("PBEAM");

const entry_type<double> pbeam::form_A("A");
const entry_type<double> pbeam::form_I1("I1");
const entry_type<double> pbeam::form_I2("I2");
const entry_type<double> pbeam::form_I12(
    "I12", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_J(
    "J", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_NSM(
    "NSM", bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_C1(
    "C1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_C2(
    "C2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_D1(
    "D1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_D2(
    "D2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_E1(
    "E1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_E2(
    "E2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_F1(
    "F1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_F2(
    "F2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
// fields that might appear more than once
namespace {
    const std::set<std::string> SO_set({"YES", "YESA", "NO"});
}
const entry_type<std::string> pbeam::form_SO(
    "SO", bdf::type_bounds::bound<std::string>(SO_set));
const entry_type<double> pbeam::form_X_XB(
    "X/XB", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
// fields_finish
const entry_type<double> pbeam::form_K1(
    "K1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd1));
const entry_type<double> pbeam::form_K2(
    "K2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd1));
const entry_type<double> pbeam::form_S1(
    "S1", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_S2(
    "S2", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_NSI_A(
    "NSI_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_NSI_B(
    "NSI_B",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_CW_A(
    "CW_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_CW_B(
    "CW_B",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_M1_A(
    "M1_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_M2_A(
    "M2_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_M1_B(
    "M1_B",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_M2_B(
    "M2_B",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_N1_A(
    "N1_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_N2_A(
    "N2_A", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> pbeam::form_N1_B(
    "N1_B",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> pbeam::form_N2_B(
    "N2_B",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));

pbeam::pbeam(std::list<std::string> const &inp) :
beam_prop(inp) {
    this->pbeam::read(inp);
}

pbeam::pbeam() : beam_prop() {}

pbeam::pbeam(long const *EID, long const *PID,
             std::list<double> const *A,
             std::list<double> const *I1,
             std::list<double> const *I2,
             std::list<double> const *I12,
             std::list<double> const *J,
             std::list<double> const *NSM,
             std::list<double> const *C1,
             std::list<double> const *C2,
             std::list<double> const *D1,
             std::list<double> const *D2,
             std::list<double> const *E1,
             std::list<double> const *E2,
             std::list<double> const *F1,
             std::list<double> const *F2,
             std::list<std::string> const *SO,
             std::list<double> const *X_XB,
             double const *K1, double const *K2,
             double const *S1, double const *S2,
             double const *NSI_A, double const *NSI_B,
             double const *CW_A, double const *CW_B,
             double const *M1_A, double const *M2_A,
             double const *M1_B, double const *M2_B,
             double const *N1_A, double const *N2_A,
             double const *N1_B, double const *N2_B) :
        beam_prop(EID, PID),
        A(*A), I1(*I1), I2(*I2), I12(*I12), J(*J), NSM(*NSM),
        C1(*C1), C2(*C2), D1(*D1), D2(*D2), E1(*E1), E2(*E2), F1(*F1), F2(*F2),
        SO((*SO).begin(), (*SO).end()), X_XB(*X_XB),
        K1(*K1), K2(*K2), S1(*S1), S2(*S2), NSI_A(*NSI_A), NSI_B(*NSI_B),
        CW_A(*CW_A), CW_B(*CW_B),
        M1_A(M1_A), M2_A(M2_A), M1_B(M1_B), M2_B(M2_B),
        N1_A(N1_A), N2_A(N2_A), N1_B(N1_B), N2_B(N2_B)
{
    this->beam_prop::check_data();
    this->pbeam::check_data();
}

void pbeam::read(std::list<std::string> const &inp) {

    auto pos = inp.rbegin();

    auto div_val = ldiv(static_cast<long>(inp.size()) - 1, 16);

    auto block_cnt = div_val.quot;
    auto block_rem = div_val.rem;

    std::deque<std::string> _SO;
    std::deque<double> _X_XB;
    std::deque<double> _A;
    std::deque<double> _I1, _I2, _I12;
    std::deque<double> _J;
    std::deque<double> _NSM;
    std::deque<double> _C1, _C2;
    std::deque<double> _D1, _D2;
    std::deque<double> _E1, _E2;
    std::deque<double> _F1, _F2;

    form_K1.set_value(K1, "");
    form_S1.set_value(S1, "");
    form_S2.set_value(S2, "");
    form_NSI_A.set_value(NSI_A, "");
    form_NSI_B.set_value(NSI_B, "");
    form_CW_A.set_value(CW_A, "");
    form_CW_B.set_value(CW_B, "");
    form_M1_A.set_value(M1_A, "");
    form_M2_A.set_value(M2_A, "");
    form_M1_B.set_value(M1_B, "");
    form_M2_B.set_value(M2_B, "");
    form_N1_A.set_value(N1_A, "");
    form_N2_A.set_value(N2_A, "");
    form_N1_B.set_value(N1_B, "");
    form_N2_B.set_value(N2_B, "");

    if (block_rem == 0) {
        block_rem = 16;
    }

    if (block_cnt > 1) {
        switch (block_rem) {
        default:
            throw errors::parse_error("PBEAM", "Illegal number of entries.");
        case 16:
            form_N2_B.set_value(N2_B, *(pos++));
        case 15:
            form_N1_B.set_value(N1_B, *(pos++));
        case 14:
            form_N2_A.set_value(N2_A, *(pos++));
        case 13:
            form_N1_A.set_value(N1_A, *(pos++));
        case 12:
            form_M2_B.set_value(M2_B, *(pos++));
        case 11:
            form_M1_B.set_value(M1_B, *(pos++));
        case 10:
            form_M2_A.set_value(M2_A, *(pos++));
        case 9:
            form_M1_A.set_value(M1_A, *(pos++));
        case 8:
            form_CW_B.set_value(CW_B, *(pos++));
        case 7:
            form_CW_A.set_value(CW_A, *(pos++));
        case 6:
            form_NSI_B.set_value(NSI_B, *(pos++));
        case 5:
            form_NSI_A.set_value(NSI_A, *(pos++));
        case 4:
            form_S2.set_value(S2, *(pos++));
        case 3:
            form_S1.set_value(S1, *(pos++));
        case 2:
            form_K2.set_value(K2, *(pos++));
        case 1:
            form_K1.set_value(K1, *(pos++));
        }
        block_rem = 16;
    }

    for (size_t i = block_cnt; i > 2; --i) {
        switch (block_rem) {
        default:
            throw errors::parse_error("PBEAM", "Illegal number of entries.");
        case 16:
            _F2.push_front(form_F2(*(pos++)));
        case 15:
            _F1.push_front(form_F1(*(pos++)));
        case 14:
            _E2.push_front(form_E2(*(pos++)));
        case 13:
            _E1.push_front(form_E1(*(pos++)));
        case 12:
            _D2.push_front(form_D2(*(pos++)));
        case 11:
            _D1.push_front(form_D1(*(pos++)));
        case 10:
            _C2.push_front(form_C2(*(pos++)));
        case 9:
            _C1.push_front(form_C1(*(pos++)));
        case 8:
            _NSM.push_front(form_NSM(*(pos++)));
            _J.push_front(form_J(*(pos++)));
            _I12.push_front(form_I12(*(pos++)));
            _I2.push_front(form_I2(*(pos++)));
            _I1.push_front(form_I1(*(pos++)));
            _A.push_front(form_A(*(pos++)));
            _X_XB.push_front(form_X_XB(*(pos++)));
            _SO.push_front(form_SO(*(pos++)));
        }
    }

    switch (block_rem) {
    case 16:
        _F2.push_front(form_F2(*(pos++)));
    case 15:
        _F1.push_front(form_F1(*(pos++)));
    case 14:
        _E2.push_front(form_E2(*(pos++)));
    case 13:
        _E1.push_front(form_E1(*(pos++)));
    case 12:
        _D2.push_front(form_D2(*(pos++)));
    case 11:
        _D1.push_front(form_D1(*(pos++)));
    case 10:
        _C2.push_front(form_C2(*(pos++)));
    case 9:
        _C1.push_front(form_C1(*(pos++)));
    case 8:
        _NSM.push_front(form_NSM(*(pos++)));
    case 7:
        _J.push_front(form_J(*(pos++)));
    case 6:
        _I12.push_front(form_I12(*(pos++)));
    case 5:
        _I2.push_front(form_I2(*(pos++)));
        _I1.push_front(form_I1(*(pos++)));
        _A.push_front(form_A(*(pos++)));
        form_MID.set_value(MID, *(pos++));
        form_PID.set_value(PID, *(pos));
        break;
    default:
        throw errors::parse_error("PBEAM", "Illegal number of entries.");
    }
    if (_J.size() == 0)
        _J.push_front(bdf::types::entry_value<double>());
    SO.resize(_SO.size(), bdf::types::entry_value<std::string>(""));
    copy(_SO.begin(), _SO.end(), SO.begin());
    X_XB.resize(_X_XB.size());
    copy(_X_XB.begin(), _X_XB.end(), X_XB.begin());
    A.resize(_A.size());
    copy(_A.begin(), _A.end(), A.begin());
    I1.resize(_I1.size());
    copy(_I1.begin(), _I1.end(), I1.begin());
    I2.resize(_I2.size());
    copy(_I2.begin(), _I2.end(), I2.begin());
    I12.resize(_I12.size());
    copy(_I12.begin(), _I12.end(), I12.begin());
    J.resize(_J.size());
    copy(_J.begin(), _J.end(), J.begin());
    NSM.resize(_NSM.size());
    copy(_NSM.begin(), _NSM.end(), NSM.begin());
    C1.resize(_C1.size());
    copy(_C1.begin(), _C1.end(), C1.begin());
    C2.resize(_C2.size());
    copy(_C2.begin(), _C2.end(), C2.begin());
    D1.resize(_D1.size());
    copy(_D1.begin(), _D1.end(), D1.begin());
    D2.resize(_D2.size());
    copy(_D2.begin(), _D2.end(), D2.begin());
    E1.resize(_E1.size());
    copy(_E1.begin(), _E1.end(), E1.begin());
    E2.resize(_E2.size());
    copy(_E2.begin(), _E2.end(), E2.begin());
    F1.resize(_F1.size());
    copy(_F1.begin(), _F1.end(), F1.begin());
    F2.resize(_F2.size());
    copy(_F2.begin(), _F2.end(), F2.begin());
}

cards::types pbeam::card_type() const {
    return cards::types::PBEAM;
};

void pbeam::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    if (!PID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID, MID)));

    auto pos_A  (A.begin());
    auto pos_I1 (I1.begin());
    auto pos_I2 (I2.begin());
    auto pos_I12(I12.begin());
    auto pos_J  (J.begin());
    auto pos_NSM(NSM.begin());
    auto pos_C1 (C1.begin());
    auto pos_C2 (C2.begin());
    auto pos_D1 (D1.begin());
    auto pos_D2 (D2.begin());
    auto pos_E1 (E1.begin());
    auto pos_E2 (E2.begin());
    auto pos_F1 (F1.begin());
    auto pos_F2 (F2.begin());
    auto pos_SO (SO.begin());
    auto pos_X_XB (X_XB.begin());


    res.push_back(unique_ptr<format_entry>(format<double>(form_A, &(*pos_A++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_I1, &(*pos_I1++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_I2, &(*pos_I2++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_I12, &(*pos_I12++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_J, &(*pos_J++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_NSM, &(*pos_NSM++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_C1, &(*pos_C1++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_C2, &(*pos_C2++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_D1, &(*pos_D1++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_D2, &(*pos_D2++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_E1, &(*pos_E1++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_E2, &(*pos_E2++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_F1, &(*pos_F1++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_F2, &(*pos_F2++))));

    while (pos_A != A.end()) {
        res.push_back(unique_ptr<format_entry>(format<std::string>(form_SO, (*pos_SO++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_X_XB, &(*pos_X_XB++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_A, &(*pos_A++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_I1, &(*pos_I1++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_I2, &(*pos_I2++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_I12, &(*pos_I12++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_J, &(*pos_J++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_NSM, &(*pos_NSM++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_C1, &(*pos_C1++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_C2, &(*pos_C2++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_D1, &(*pos_D1++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_D2, &(*pos_D2++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_E1, &(*pos_E1++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_E2, &(*pos_E2++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_F1, &(*pos_F1++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_F2, &(*pos_F2++))));
    }

    res.push_back(unique_ptr<format_entry>(format<double>(form_K1, K1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_K2, K2)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_S1, S1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_S2, S2)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_NSI_A, NSI_A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_NSI_B, NSI_B)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_CW_A, CW_A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_CW_B, CW_B)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_M1_A, M1_A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_M2_A, M2_A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_M1_B, M1_B)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_M2_B, M2_B)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_N1_A, N1_A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_N2_A, N2_A)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_N1_B, N1_B)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_N2_B, N2_B)));
}

void pbeam::check_data() const {
    this->beam_prop::check_data();
    size_t base_size{A.size()};
    if (I1.size() != base_size) throw errors::form_error("PBEAM", "wrong size for I1");
    if (I2.size() != base_size) throw errors::form_error("PBEAM", "wrong size for I");
    if (I12.size() != base_size) throw errors::form_error("PBEAM", "wrong size for I");
    if (J.size() != base_size) throw errors::form_error("PBEAM", "wrong size for J");
    if (NSM.size() != base_size) throw errors::form_error("PBEAM", "wrong size for NSM");
    if (C1.size() != base_size) throw errors::form_error("PBEAM", "wrong size for C1");
    if (C2.size() != base_size) throw errors::form_error("PBEAM", "wrong size for C2");
    if (D1.size() != base_size) throw errors::form_error("PBEAM", "wrong size for D1");
    if (D2.size() != base_size) throw errors::form_error("PBEAM", "wrong size for D2");
    if (E1.size() != base_size) throw errors::form_error("PBEAM", "wrong size for E1");
    if (E2.size() != base_size) throw errors::form_error("PBEAM", "wrong size for E2");
    if (F1.size() != base_size) throw errors::form_error("PBEAM", "wrong size for F1");
    if (F2.size() != base_size) throw errors::form_error("PBEAM", "wrong size for F2");

    if (base_size && SO.size() != base_size-1)
        throw errors::form_error("PBEAM", "wrong size for SO");
    if (base_size && X_XB.size() != base_size-1)
        throw errors::form_error("PBEAM", "wrong size for X_XB");

    if (A.size()>0) for (auto pos : A) pbeam::form_A.check(pos);
    if (I1.size()>0) for (auto pos : I1) pbeam::form_I1.check(pos);
    if (I2.size()>0) for (auto pos : I2) pbeam::form_I2.check(pos);
    if (I12.size()>0) for (auto pos : I12) pbeam::form_I12.check(pos);
    if (J.size()>0) for (auto pos : J) pbeam::form_J.check(pos);
    if (NSM.size()>0) for (auto pos : NSM) pbeam::form_NSM.check(pos);
    if (C1.size()>0) for (auto pos : C1) pbeam::form_C1.check(pos);
    if (C2.size()>0) for (auto pos : C2) pbeam::form_C2.check(pos);
    if (D1.size()>0) for (auto pos : D1) pbeam::form_D1.check(pos);
    if (D2.size()>0) for (auto pos : D2) pbeam::form_D2.check(pos);
    if (E1.size()>0) for (auto pos : E1) pbeam::form_E1.check(pos);
    if (E2.size()>0) for (auto pos : E2) pbeam::form_E2.check(pos);
    if (F1.size()>0) for (auto pos : F1) pbeam::form_F1.check(pos);
    if (F2.size()>0) for (auto pos : F2) pbeam::form_F2.check(pos);
    if (SO.size()>0) for (auto pos : SO) pbeam::form_SO.check(pos);
    if (X_XB.size()>0) for (auto pos : X_XB) pbeam::form_X_XB.check(pos);
    if (K1) pbeam::form_K1.check(K1);
    if (K2) pbeam::form_K2.check(K2);
    if (S1) pbeam::form_S1.check(S1);
    if (S2) pbeam::form_S2.check(S2);
    if (NSI_A) pbeam::form_NSI_A.check(NSI_A);
    if (NSI_B) pbeam::form_NSI_B.check(NSI_B);
    if (CW_A) pbeam::form_CW_A.check(CW_A);
    if (CW_B) pbeam::form_CW_B.check(CW_B);
    if (M1_A) pbeam::form_M1_A.check(M1_A);
    if (M2_A) pbeam::form_M2_A.check(M2_A);
    if (M1_B) pbeam::form_M1_B.check(M1_B);
    if (M2_B) pbeam::form_M2_B.check(M2_B);
    if (N1_A) pbeam::form_N1_A.check(N1_A);
    if (N2_A) pbeam::form_N2_A.check(N2_A);
    if (N1_B) pbeam::form_N1_B.check(N1_B);
    if (N2_B) pbeam::form_N2_B.check(N2_B);
}

bdf::cards::__base::card const &pbeam::operator()(list<std::string> const &inp) {
    this->pbeam::read(inp);
    return *this;
}

bdf::cards::__base::card const &pbeam::operator() (
    long const *PID, long const *MID,
    std::list<double> const *A,
    std::list<double> const *I1,
    std::list<double> const *I2,
    std::list<double> const *I12,
    std::list<double> const *J,
    std::list<double> const *NSM,
    std::list<double> const *C1,
    std::list<double> const *C2,
    std::list<double> const *D1,
    std::list<double> const *D2,
    std::list<double> const *E1,
    std::list<double> const *E2,
    std::list<double> const *F1,
    std::list<double> const *F2,
    std::list<std::string> const *SO,
    std::list<double> const *X_XB,
    double const *K1, double const *K2,
    double const *S1, double const *S2,
    double const *NSI_A, double const *NSI_B,
    double const *CW_A, double const *CW_B,
    double const *M1_A, double const *M2_A,
    double const *M1_B, double const *M2_B,
    double const *N1_A, double const *N2_A,
    double const *N1_B, double const *N2_B) {
    this->beam_prop::operator() (PID, MID);
    this->A.assign(A->begin(), A->end());
    this->I1.assign(I1->begin(), I1->end());
    this->I2.assign(I2->begin(), I2->end());
    this->I12.assign(I12->begin(), I12->end());
    this->J.assign(J->begin(), J->end());
    this->NSM.assign(NSM->begin(), NSM->end());
    this->C1.assign(C1->begin(), C1->end());
    this->C2.assign(C2->begin(), C2->end());
    this->D1.assign(D1->begin(), D1->end());
    this->D2.assign(D2->begin(), D2->end());
    this->E1.assign(E1->begin(), E1->end());
    this->E2.assign(E2->begin(), E2->end());
    this->F1.assign(F1->begin(), F1->end());
    this->F2.assign(F2->begin(), F2->end());
    this->SO.assign(SO->begin(), SO->end());
    this->X_XB.assign(X_XB->begin(), X_XB->end());
    this->K1(K1);
    this->K2(K2);
    this->S1(S1);
    this->S2(S2);
    this->NSI_A(NSI_A);
    this->NSI_B(NSI_B);
    this->CW_A(CW_A);
    this->CW_B(CW_B);
    this->M1_A(M1_A);
    this->M2_A(M2_A);
    this->M1_B(M1_B);
    this->M2_B(M2_B);
    this->N1_A(N1_A);
    this->N2_A(N2_A);
    this->N1_B(N1_B);
    this->N2_B(N2_B);
    this->beam_base::check_data();
    this->pbeam::check_data();
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
