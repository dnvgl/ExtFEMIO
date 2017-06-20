/**
   \file
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
using bdf::type_bounds::bound;

namespace {
    auto const cd0_ = make_shared<double>(0.);
    auto const cd1_ = make_shared<double>(1.);
    auto const cd0 = cd0_.get();
    auto const cd1 = cd1_.get();
     // const double cd0 = 0., cd1 = 1.;
}

bdf::types::card pbeam::head = bdf::types::card("PBEAM");

entry_type<double> pbeam::form_A("A");
entry_type<double> pbeam::form_I1("I1");
entry_type<double> pbeam::form_I2("I2");
namespace {
    auto const bound_I12_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_I12 = bound_I12_.get();
}
entry_type<double> pbeam::form_I12("I12", bound_I12);
namespace {
    auto const bound_J_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_J = bound_J_.get();
}
entry_type<double> pbeam::form_J("J", bound_J);
namespace {
    auto const bound_NSM_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_NSM = bound_NSM_.get();
}
entry_type<double> pbeam::form_NSM("NSM", bound_NSM);
namespace {
    auto const bound_C1_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_C1 = bound_C1_.get();
}
entry_type<double> pbeam::form_C1("C1", bound_C1);
namespace {
    auto const bound_C2_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_C2 = bound_C2_.get();
}
entry_type<double> pbeam::form_C2("C2", bound_C2);
namespace {
    auto const bound_D1_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_D1 = bound_D1_.get();
}
entry_type<double> pbeam::form_D1("D1", bound_D1);
namespace {
    auto const bound_D2_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_D2 = bound_D2_.get();
}
entry_type<double> pbeam::form_D2("D2", bound_D2);
namespace {
    auto const bound_E1_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_E1 = bound_E1_.get();
}
entry_type<double> pbeam::form_E1("E1", bound_E1);
namespace {
    auto const bound_E2_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_E2 = bound_E2_.get();
}
entry_type<double> pbeam::form_E2("E2", bound_E2);
namespace {
    auto const bound_F1_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_F1 = bound_F1_.get();
}
entry_type<double> pbeam::form_F1("F1", bound_F1);
namespace {
    auto const bound_F2_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_F2 = bound_F2_.get();
}
entry_type<double> pbeam::form_F2("F2", bound_F2);
// fields that might appear more than once
namespace {
    set<std::string> const SO_set({"YES", "YESA", "NO"});
    auto const bound_SO_ = make_shared<bound<std::string>>(SO_set);
    auto const bound_SO = bound_SO_.get();
}
entry_type<std::string> pbeam::form_SO("SO", bound_SO);
namespace {
    auto const bound_X_XB_ = make_shared<bound<double>>(cd0, nullptr, cd1);
    auto const bound_X_XB = bound_X_XB_.get();
}
entry_type<double> pbeam::form_X_XB("X/XB", bound_X_XB);
// fields_finish
namespace {
    auto const bound_K1_ = make_shared<bound<double>>(nullptr, nullptr, cd1);
    auto const bound_K1 = bound_K1_.get();
}
entry_type<double> pbeam::form_K1("K1", bound_K1);
namespace {
    auto const bound_K2_ = make_shared<bound<double>>(nullptr, nullptr, cd1);
    auto const bound_K2 = bound_K2_.get();
}
entry_type<double> pbeam::form_K2("K2", bound_K2);
namespace {
    auto const bound_S1_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_S1 = bound_S1_.get();
}
entry_type<double> pbeam::form_S1("S1", bound_S1);
namespace {
    auto const bound_S2_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_S2 = bound_S2_.get();
}
entry_type<double> pbeam::form_S2("S2", bound_S2);
namespace {
    auto const bound_NSI_A_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_NSI_A = bound_NSI_A_.get();
}
entry_type<double> pbeam::form_NSI_A("NSI_A", bound_NSI_A);
namespace {
    auto const bound_NSI_B_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_NSI_B = bound_NSI_B_.get();
}
entry_type<double> pbeam::form_NSI_B("NSI_B", bound_NSI_B);
namespace {
    auto const bound_CW_A_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_CW_A = bound_CW_A_.get();
}
entry_type<double> pbeam::form_CW_A("CW_A", bound_CW_A);
namespace {
    auto const bound_CW_B_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_CW_B = bound_CW_B_.get();
}
entry_type<double> pbeam::form_CW_B("CW_B", bound_CW_B);
namespace {
    auto const bound_M1_A_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_M1_A = bound_M1_A_.get();
}
entry_type<double> pbeam::form_M1_A("M1_A", bound_M1_A);
namespace {
    auto const bound_M2_A_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_M2_A = bound_M2_A_.get();
}
entry_type<double> pbeam::form_M2_A("M2_A", bound_M2_A);
namespace {
    auto const bound_M1_B_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_M1_B = bound_M1_B_.get();
}
entry_type<double> pbeam::form_M1_B("M1_B", bound_M1_B);
namespace {
    auto const bound_M2_B_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_M2_B = bound_M2_B_.get();
}
entry_type<double> pbeam::form_M2_B("M2_B", bound_M2_B);
namespace {
    auto const bound_N1_A_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_N1_A = bound_N1_A_.get();
}
entry_type<double> pbeam::form_N1_A("N1_A", bound_N1_A);
namespace {
    auto const bound_N2_A_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_N2_A = bound_N2_A_.get();
}
entry_type<double> pbeam::form_N2_A("N2_A", bound_N2_A);
namespace {
    auto const bound_N1_B_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_N1_B = bound_N1_B_.get();
}
entry_type<double> pbeam::form_N1_B("N1_B", bound_N1_B);
namespace {
    auto const bound_N2_B_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_N2_B = bound_N2_B_.get();
}
entry_type<double> pbeam::form_N2_B("N2_B",bound_N2_B);

pbeam::pbeam(list<std::string> const &inp) :
beam_prop(inp) {
    this->pbeam::read(inp);
}

pbeam::pbeam(long const *PID, long const *MID,
             vector<double> const *A,
             vector<double> const *I1,
             vector<double> const *I2,
             vector<double> const *I12,
             vector<double> const *J,
             vector<double> const *NSM,
             vector<double> const *C1,
             vector<double> const *C2,
             vector<double> const *D1,
             vector<double> const *D2,
             vector<double> const *E1,
             vector<double> const *E2,
             vector<double> const *F1,
             vector<double> const *F2,
             vector<std::string> const *SO,
             vector<double> const *X_XB,
             double const *K1, double const *K2,
             double const *S1, double const *S2,
             double const *NSI_A, double const *NSI_B,
             double const *CW_A, double const *CW_B,
             double const *M1_A, double const *M2_A,
             double const *M1_B, double const *M2_B,
             double const *N1_A, double const *N2_A,
             double const *N1_B, double const *N2_B) :
        beam_prop(PID, MID),
        A(*A), I1(*I1), I2(*I2),
        K1(K1), K2(K2), S1(S1), S2(S2), NSI_A(NSI_A), NSI_B(NSI_B),
        CW_A(CW_A), CW_B(CW_B),
        M1_A(M1_A), M2_A(M2_A), M1_B(M1_B), M2_B(M2_B),
        N1_A(N1_A), N2_A(N2_A), N1_B(N1_B), N2_B(N2_B) {
   if (I12 != nullptr) this->I12.assign((*I12).begin(), (*I12).end());
    if (J != nullptr)  this->J.assign((*J).begin(), (*J).end());
    if (NSM != nullptr) this->NSM.assign(NSM->begin(), NSM->end());
    if (C1 != nullptr) this->C1.assign((*C1).begin(), (*C1).end());
    if (C2 != nullptr) this->C2.assign((*C2).begin(), (*C2).end());
    if (D1 != nullptr) this->D1.assign((*D1).begin(), (*D1).end());
    if (D2 != nullptr) this->D2.assign((*D2).begin(), (*D2).end());
    if (E1 != nullptr) this->E1.assign((*E1).begin(), (*E1).end());
    if (E2 != nullptr) this->E2.assign((*E2).begin(), (*E2).end());
    if (F1 != nullptr) this->F1.assign((*F1).begin(), (*F1).end());
    if (F2 != nullptr) this->F2.assign((*F2).begin(), (*F2).end());

    if (this->A.size() > 1) {
        this->SO.assign((*SO).begin(), (*SO).end());
        this->X_XB.assign((*X_XB).begin(), (*X_XB).end());
    } else {
        this->SO.clear();
        this->X_XB.clear();
    }
    this->pbeam::check_data();
}

void pbeam::read(list<std::string> const &inp) {

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
    list<std::unique_ptr<format_entry> > &res) const {
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

    bool has_tail(bool(K1) || bool(K2) || bool(S1) || bool(S2) ||
                  bool(NSI_A) || bool(NSI_B) || bool(CW_A) || bool(CW_B) ||
                  bool(M1_A) || bool(M2_A) || bool(M1_B) || bool(M2_B) ||
                  bool(N1_A) || bool(N2_A) || bool(N1_B) || bool(N2_B));

    res.push_back(unique_ptr<format_entry>(format<double>(form_A, &(*pos_A++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_I1, &(*pos_I1++))));
    res.push_back(unique_ptr<format_entry>(format<double>(form_I2, &(*pos_I2++))));
    if (has_tail || I12.size()>0 || J.size()>0 || NSM.size()>0 ||
        C1.size()>0 || C2.size()>0 || D1.size()>0 || D2.size()>0 ||
        E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          I12.size()>0 ?
                          format<double>(form_I12, &(*pos_I12++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || J.size()>0 || NSM.size()>0 ||
        C1.size()>0 || C2.size()>0 || D1.size()>0 || D2.size()>0 ||
        E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          J.size()>0 ?
                          format<double>(form_J, &(*pos_J++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || NSM.size()>0 ||
        C1.size()>0 || C2.size()>0 || D1.size()>0 || D2.size()>0 ||
        E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          NSM.size()>0 ?
                          format<double>(form_NSM, &(*pos_NSM++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || C1.size()>0 || C2.size()>0 || D1.size()>0 || D2.size()>0 ||
        E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          C1.size()>0 ?
                          format<double>(form_C1, &(*pos_C1++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || C2.size()>0 || D1.size()>0 || D2.size()>0 ||
        E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          C2.size()>0 ?
                          format<double>(form_C2, &(*pos_C2++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || D1.size()>0 || D2.size()>0 ||
        E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          D1.size()>0 ?
                          format<double>(form_D1, &(*pos_D1++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || D2.size()>0 ||
        E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          D2.size()>0 ?
                          format<double>(form_D2, &(*pos_D2++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || E1.size()>0 || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          E1.size()>0 ?
                          format<double>(form_E1, &(*pos_E1++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || E2.size()>0 || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          E2.size()>0 ?
                          format<double>(form_E2, &(*pos_E2++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || F1.size()>0 || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          F1.size()>0 ?
                          format<double>(form_F1, &(*pos_F1++)) :
                          format(empty)));
    else goto cont;
    if (has_tail || F2.size()>0)
        res.push_back(unique_ptr<format_entry>(
                          F2.size()>0 ?
                          format<double>(form_F2, &(*pos_F2++)) :
                          format(empty)));

    while (pos_A != A.end()) {
        res.push_back(unique_ptr<format_entry>(format<std::string>(form_SO, (*pos_SO++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_X_XB, &(*pos_X_XB++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_A, &(*pos_A++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_I1, &(*pos_I1++))));
        res.push_back(unique_ptr<format_entry>(format<double>(form_I2, &(*pos_I2++))));
        if (has_tail || pos_A != A.end() || pos_I12 != I12.end() || pos_J != J.end() ||
            pos_NSM != NSM.end() || pos_C1 != C1.end() || pos_C2 != C2.end() ||
            pos_D1 != D1.end() || pos_D2 != D2.end() || pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_I12 != I12.end() ?
                              format<double>(form_I12, &(*pos_I12++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() || pos_J != J.end() ||
            pos_NSM != NSM.end() || pos_C1 != C1.end() || pos_C2 != C2.end() ||
            pos_D1 != D1.end() || pos_D2 != D2.end() || pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_J != J.end() ?
                              format<double>(form_J, &(*pos_J++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_NSM != NSM.end() || pos_C1 != C1.end() || pos_C2 != C2.end() ||
            pos_D1 != D1.end() || pos_D2 != D2.end() || pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_NSM != NSM.end() ?
                              format<double>(form_NSM, &(*pos_NSM++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_C1 != C1.end() || pos_C2 != C2.end() ||
            pos_D1 != D1.end() || pos_D2 != D2.end() || pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_C1 != C1.end() ?
                              format<double>(form_C1, &(*pos_C1++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_C2 != C2.end() ||
            pos_D1 != D1.end() || pos_D2 != D2.end() || pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_C2 != C2.end() ?
                              format<double>(form_C2, &(*pos_C2++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_D1 != D1.end() || pos_D2 != D2.end() || pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_D1 != D1.end() ?
                              format<double>(form_D1, &(*pos_D1++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_D2 != D2.end() || pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_D2 != D2.end() ?
                              format<double>(form_D2, &(*pos_D2++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_E1 != E1.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_E1 != E1.end() ?
                              format<double>(form_E1, &(*pos_E1++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_E2 != E2.end() || pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_E2 != E2.end() ?
                              format<double>(form_E2, &(*pos_E2++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() ||
            pos_F1 != F1.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_F1 != F1.end() ?
                              format<double>(form_F1, &(*pos_F1++)) :
                              format(empty)));
        else continue;
        if (has_tail || pos_A != A.end() || pos_F2 != F2.end())
            res.push_back(unique_ptr<format_entry>(
                              pos_F2 != F2.end() ?
                              format<double>(form_F2, &(*pos_F2++)) :
                              format(empty)));
    }

    if (bool(K1) || bool(K2) || bool(S1) || bool(S2) || bool(NSI_A) ||
        bool(NSI_B) || bool(CW_A) || bool(CW_B) || bool(M1_A) || bool(M2_A) ||
        bool(M1_B) || bool(M2_B) || bool(N1_A) || bool(N2_A) || bool(N1_B) ||
        bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(K1) ?
                          format<double>(form_K1, K1) :
                          format(empty)));
    else goto cont;
    if (bool(K2) || bool(S1) || bool(S2) || bool(NSI_A) || bool(NSI_B) ||
        bool(CW_A) || bool(CW_B) || bool(M1_A) || bool(M2_A) || bool(M1_B) ||
        bool(M2_B) || bool(N1_A) || bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(K2) ?
                          format<double>(form_K2, K2) :
                          format(empty)));
    else goto cont;
    if (bool(S1) || bool(S2) || bool(NSI_A) || bool(NSI_B) || bool(CW_A) ||
        bool(CW_B) || bool(M1_A) || bool(M2_A) || bool(M1_B) || bool(M2_B) ||
        bool(N1_A) || bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(S1) ?
                          format<double>(form_S1, S1) :
                          format(empty)));
    else goto cont;
    if (bool(S2) || bool(NSI_A) || bool(NSI_B) || bool(CW_A) || bool(CW_B) ||
        bool(M1_A) || bool(M2_A) || bool(M1_B) || bool(M2_B) || bool(N1_A) ||
        bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(S2) ?
                          format<double>(form_S2, S2) :
                          format(empty)));
    else goto cont;
    if (bool(NSI_A) || bool(NSI_B) || bool(CW_A) || bool(CW_B) || bool(M1_A) ||
        bool(M2_A) || bool(M1_B) || bool(M2_B) || bool(N1_A) || bool(N2_A) ||
        bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(NSI_A) ?
                          format<double>(form_NSI_A, NSI_A) :
                          format(empty)));
    else goto cont;
    if (bool(NSI_B) || bool(CW_A) || bool(CW_B) || bool(M1_A) || bool(M2_A) ||
        bool(M1_B) || bool(M2_B) || bool(N1_A) || bool(N2_A) || bool(N1_B) ||
        bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(NSI_B) ?
                          format<double>(form_NSI_B, NSI_B) :
                          format(empty)));
    else goto cont;
    if (bool(CW_A) || bool(CW_B) || bool(M1_A) || bool(M2_A) || bool(M1_B) ||
        bool(M2_B) || bool(N1_A) || bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(CW_A) ?
                          format<double>(form_CW_A, CW_A) :
                          format(empty)));
    else goto cont;
    if (bool(CW_B) || bool(M1_A) || bool(M2_A) || bool(M1_B) || bool(M2_B) ||
        bool(N1_A) || bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(CW_B) ?
                          format<double>(form_CW_B, CW_B) :
                          format(empty)));
    else goto cont;
    if (bool(M1_A) || bool(M2_A) || bool(M1_B) || bool(M2_B) || bool(N1_A) ||
        bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(M1_A) ?
                          format<double>(form_M1_A, M1_A) :
                          format(empty)));
    else goto cont;
    if (bool(M2_A) || bool(M1_B) || bool(M2_B) || bool(N1_A) || bool(N2_A) ||
        bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(M2_A) ?
                          format<double>(form_M2_A, M2_A) :
                          format(empty)));
    else goto cont;
    if (bool(M1_B) || bool(M2_B) || bool(N1_A) || bool(N2_A) || bool(N1_B) ||
        bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(M1_B) ?
                          format<double>(form_M1_B, M1_B) :
                          format(empty)));
    else goto cont;
    if (bool(M2_B) || bool(N1_A) || bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(M2_B) ?
                          format<double>(form_M2_B, M2_B) :
                          format(empty)));
    else goto cont;
    if (bool(N1_A) || bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(N1_A) ?
                          format<double>(form_N1_A, N1_A) :
                          format(empty)));
    else goto cont;
    if (bool(N2_A) || bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(N2_A) ?
                          format<double>(form_N2_A, N2_A) :
                          format(empty)));
    else goto cont;
    if (bool(N1_B) || bool(N2_B))
        res.push_back(unique_ptr<format_entry>(
                          bool(N1_B) ?
                          format<double>(form_N1_B, N1_B) :
                          format(empty)));
    else goto cont;
    if (bool(N2_B))
        res.push_back(unique_ptr<format_entry>(format<double>(form_N2_B, N2_B)));
cont:
    return;
}

void pbeam::check_data() {
    size_t base_size{A.size()};
    if (I1.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for I1");
    if (I2.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for I2");
    if (I12.size() && I12.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for I12");
    if (J.size() && J.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for J");
    if (NSM.size() && NSM.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for NSM");
    if (C1.size() && C1.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for C1");
    if (C2.size() && C2.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for C2");
    if (D1.size() && D1.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for D1");
    if (D2.size() && D2.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for D2");
    if (E1.size() && E1.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for E1");
    if (E2.size() && E2.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for E2");
    if (F1.size() && F1.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for F1");
    if (F2.size() && F2.size() != base_size)
        throw errors::form_error("PBEAM", "wrong size for F2");

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

bdf::cards::__base::card const &pbeam::operator() (
    list<std::string> const &inp) {
    this->pbeam::read(inp);
    return *this;
}

bdf::cards::__base::card const &pbeam::operator() (
    long const *PID, long const *MID,
    vector<double> const *A,
    vector<double> const *I1,
    vector<double> const *I2,
    vector<double> const *I12,
    vector<double> const *J,
    vector<double> const *NSM,
    vector<double> const *C1,
    vector<double> const *C2,
    vector<double> const *D1,
    vector<double> const *D2,
    vector<double> const *E1,
    vector<double> const *E2,
    vector<double> const *F1,
    vector<double> const *F2,
    vector<std::string> const *SO,
    vector<double> const *X_XB,
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
    if (I12 != nullptr) this->I12.assign(I12->begin(), I12->end());
    if (J != nullptr) this->J.assign(J->begin(), J->end());
    if (NSM != nullptr) this->NSM.assign(NSM->begin(), NSM->end());
    if (C1 != nullptr) this->C1.assign(C1->begin(), C1->end());
    if (C2 != nullptr) this->C2.assign(C2->begin(), C2->end());
    if (D1 != nullptr) this->D1.assign(D1->begin(), D1->end());
    if (D2 != nullptr) this->D2.assign(D2->begin(), D2->end());
    if (E1 != nullptr) this->E1.assign(E1->begin(), E1->end());
    if (E2 != nullptr) this->E2.assign(E2->begin(), E2->end());
    if (F1 != nullptr) this->F1.assign(F1->begin(), F1->end());
    if (F2 != nullptr) this->F2.assign(F2->begin(), F2->end());
    if ((*A).size()>1) {
        this->SO.assign(SO->begin(), SO->end());
        this->X_XB.assign(X_XB->begin(), X_XB->end());
    } else {
        this->SO.clear();
        this->X_XB.clear();
    }
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
