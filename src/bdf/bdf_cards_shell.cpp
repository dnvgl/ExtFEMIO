/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF CTRIA3 and CQUAD4 cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    const char cID_bdf_cards_shell[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using type_bounds::bound;
using types::entry_type;

namespace {
    auto const cl0_ = make_shared<long>(0);
    auto const cl1_ = make_shared<long>(1);
    auto const cd0_ = make_shared<double>(0.);
    auto const cd1_ = make_shared<double>(1.);

    auto const cl0 = cl0_.get();
    auto const cl1 = cl1_.get();
    auto const cd0 = cd0_.get();
    auto const cd1 = cd1_.get();
}

using namespace cards::__base;

// entry_type<long> shell::form_EID(
//    "EID", bound<long>(cl1));
namespace {
    auto const bound_PID_ = make_shared<bound<long>>(
        cl1, nullptr, nullptr, true);
    auto const bound_PID = bound_PID_.get();
}
entry_type<long> shell::form_PID("PID", bound_PID);
namespace {
    auto const bound_G1_ = make_shared<bound<long>>(cl1);
    auto const bound_G1 = bound_G1_.get();
}
entry_type<long> shell::form_G1("G1", bound_G1);
namespace {
    auto const bound_G2_ = make_shared<bound<long>>(cl1);
    auto const bound_G2 = bound_G2_.get();
}
entry_type<long> shell::form_G2("G2", bound_G2);
namespace {
    auto const bound_G3_ = make_shared<bound<long>>(cl1);
    auto const bound_G3 = bound_G3_.get();
}
entry_type<long> shell::form_G3("G3", bound_G3);
namespace {
    auto const bound_G4_ = make_shared<bound<long>>(cl1);
    auto const bound_G4 = bound_G4_.get();
}
entry_type<long> shell::form_G4("G4", bound_G4);
namespace {
    auto const bound_MCID_ = make_shared<bound<long>>(cl0);
    auto const bound_MCID = bound_MCID_.get();
}
entry_type<long> shell::form_MCID("MCID", bound_MCID);
namespace {
    auto const bound_THETA_ = make_shared<bound<double>>(nullptr, nullptr, cd0);
    auto const bound_THETA = bound_THETA_.get();
}
entry_type<double> shell::form_THETA("MCID", bound_THETA);
namespace {
    auto const bound_ZOFFS_ = make_shared<bound<double>>(
        nullptr, nullptr, nullptr, true);
    auto const bound_ZOFFS = bound_ZOFFS_.get();
}
entry_type<double> shell::form_ZOFFS("ZOFFS", bound_ZOFFS);
namespace {
    auto const bound_TFLAG_ = make_shared<bound<long>>(cl0, cl1, nullptr, true);
    auto const bound_TFLAG = bound_TFLAG_.get();
}
entry_type<long> shell::form_TFLAG("TFLAG", bound_TFLAG);
namespace {
    auto const bound_T1_ = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
    auto const bound_T1 = bound_T1_.get();
}
entry_type<double> shell::form_T1("T1", bound_T1);
namespace {
    auto const bound_T2_ = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
    auto const bound_T2 = bound_T2_.get();
}
entry_type<double> shell::form_T2("T2", bound_T2);
namespace {
    auto const bound_T3_ = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
    auto const bound_T3 = bound_T3_.get();
}
entry_type<double> shell::form_T3("T3", bound_T3);
namespace {
    auto const bound_T4_ = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
    auto const bound_T4 = bound_T4_.get();
}
entry_type<double> shell::form_T4("T4", bound_T4);

shell::shell() : element(), choose_mcid_theta() {}

shell::shell(const list<std::string> &inp) :
    element(inp), choose_mcid_theta(CHOOSE_MCID_THETA::UNDEF) {
    this->shell::check_data();
}

shell::shell(long *EID) :
        element(EID), choose_mcid_theta(CHOOSE_MCID_THETA::UNDEF) {
    this->shell::check_data();
}

shell::shell(long *EID, long *PID, long *G1, long *G2, long *G3, long *G4,
             double *THETA, double *ZOFFS, long *TFLAG,
             double *T1, double *T2, double *T3, double *T4) :
        element(EID), choose_mcid_theta(CHOOSE_MCID_THETA::has_THETA),
        PID(PID), G1(G1), G2(G2), G3(G3), G4(G4),
        THETA(THETA), ZOFFS(ZOFFS), TFLAG(TFLAG),
        T1(T1), T2(T2), T3(T3), T4(T4) {
    this->shell::check_data();
}

shell::shell(long *EID, long *PID, long *G1, long *G2, long *G3, long *G4,
             long *MCID, double *ZOFFS, long *TFLAG,
             double *T1, double *T2, double *T3, double *T4) :
        element(EID), choose_mcid_theta(CHOOSE_MCID_THETA::has_MCID),
        PID(PID), G1(G1), G2(G2), G3(G3), G4(G4),
        MCID(MCID), ZOFFS(ZOFFS), TFLAG(TFLAG),
        T1(T1), T2(T2), T3(T3), T4(T4) {
    this->shell::check_data();
}

cards::__base::card const &shell::operator() (
    long const *EID, long const *PID,
    long const *G1, long const *G2,
    long const *G3, long const *G4,
    double const *THETA,
    double const *ZOFFS, long const *TFLAG,
    double const *T1, double const *T2,
    double const *T3, double const *T4) {
    this->element::operator() (EID);
    choose_mcid_theta = CHOOSE_MCID_THETA::has_THETA;
    this->PID(PID);
    this->G1(G1);
    this->G2(G2);
    this->G3(G3);
    this->G4(G4);
    this->THETA(THETA);
    this->ZOFFS(ZOFFS);
    this->TFLAG(TFLAG);
    this->T1(T1);
    this->T2(T2);
    this->T3(T3);
    this->T4(T4) ;
    this->shell::check_data();
    return *this;
}

cards::__base::card const &shell::operator() (
    long const *EID, long const *PID,
    long const *G1, long const *G2,
    long const *G3, long const *G4,
    long const *MCID,
    double const *ZOFFS, long const *TFLAG,
    double const *T1, double const *T2,
    double const *T3, double const *T4) {
    this->element::operator() (EID);
    choose_mcid_theta = CHOOSE_MCID_THETA::has_MCID;
    this->PID(PID);
    this->G1(G1);
    this->G2(G2);
    this->G3(G3);
    this->G4(G4);
    this->MCID(MCID);
    this->ZOFFS(ZOFFS);
    this->TFLAG(TFLAG);
    this->T1(T1);
    this->T2(T2);
    this->T3(T3);
    this->T4(T4);
    this->shell::check_data();
    return *this;
}

void shell::check_data() {
    // this->element::check_data();
    if (this->PID) form_PID.check(this->PID);
    if (this->G1) form_G1.check(this->G1);
    if (this->G2) form_G2.check(this->G2);
    if (this->G3) form_G3.check(this->G3);
    if (this->G4) form_G4.check(this->G4);
    if (this->THETA) form_THETA.check(this->THETA);
    if (this->ZOFFS) form_ZOFFS.check(this->ZOFFS);
    if (this->TFLAG) form_TFLAG.check(this->TFLAG);
    if (this->T1) form_T1.check(this->T1);
    if (this->T2) form_T2.check(this->T2);
    if (this->T3) form_T3.check(this->T3);
    if (this->T4) form_T4.check(this->T4);
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
