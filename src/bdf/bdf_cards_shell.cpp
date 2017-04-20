/**
   \file bdf/bdf_cards_shell.cpp
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

namespace {
    const long cl0 = 0, cl1 = 1;
    const double cd0 = 0., cd1 = 1.;
}

using namespace dnvgl::extfem;
using namespace bdf;

using types::entry_type;

using namespace cards::__base;

// const entry_type<long> shell::form_EID(
//    "EID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> shell::form_PID(
    "PID",
    type_bounds::bound<long>(&cl1, nullptr, nullptr, true));
const entry_type<long> shell::form_G1(
    "G1", type_bounds::bound<long>(&cl1));
const entry_type<long> shell::form_G2(
    "G2", type_bounds::bound<long>(&cl1));
const entry_type<long> shell::form_G3(
    "G3", type_bounds::bound<long>(&cl1));
const entry_type<long> shell::form_G4(
    "G4", type_bounds::bound<long>(&cl1));
const entry_type<long> shell::form_MCID(
    "MCID", type_bounds::bound<long>(&cl0));
const entry_type<double> shell::form_THETA(
    "MCID", type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> shell::form_ZOFFS(
    "ZOFFS", type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<long> shell::form_TFLAG(
    "TFLAG", type_bounds::bound<long>(&cl0, &cl1, nullptr, true));
const entry_type<double> shell::form_T1(
    "T1", type_bounds::bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> shell::form_T2(
    "T2", type_bounds::bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> shell::form_T3(
    "T3", type_bounds::bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> shell::form_T4(
    "T4", type_bounds::bound<double>(&cd0, nullptr, nullptr, true));

shell::shell() : element(nullptr), choose_mcid_theta() {}

shell::shell(const std::list<std::string> &inp) :
    element(inp), choose_mcid_theta(CHOOSE_MCID_THETA::UNDEF) {
    this->shell::check_data();
}

shell::shell(long const *EID) :
        element(EID), choose_mcid_theta(CHOOSE_MCID_THETA::UNDEF) {
    this->shell::check_data();
}

shell::shell(long const *EID, long const *PID,
             long const *G1, long const *G2,
             long const *G3, long const *G4,
             double const *THETA,
             double const *ZOFFS, long const *TFLAG,
             double const *T1, double const *T2,
             double const *T3, double const *T4) :
        element(EID), choose_mcid_theta(CHOOSE_MCID_THETA::has_THETA),
        PID(PID), G1(G1), G2(G2), G3(G3), G4(G4),
        THETA(THETA), ZOFFS(ZOFFS), TFLAG(TFLAG),
        T1(T1), T2(T2), T3(T3), T4(T4) {
    this->shell::check_data();
}

shell::shell(long const *EID, long const *PID,
             long const *G1, long const *G2,
             long const *G3, long const *G4,
             long const *MCID,
             double const *ZOFFS, long const *TFLAG,
             double const *T1, double const *T2,
             double const *T3, double const *T4) :
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

void shell::check_data() const {
    this->element::check_data();
    if (PID) form_PID.check(this->PID);
    if (G1) form_G1.check(this->G1);
    if (G2) form_G2.check(this->G2);
    if (G3) form_G3.check(this->G3);
    if (G4) form_G4.check(this->G4);
    if (THETA) form_THETA.check(this->THETA);
    if (ZOFFS) form_ZOFFS.check(this->ZOFFS);
    if (TFLAG) form_TFLAG.check(this->TFLAG);
    if (T1) form_T1.check(this->T1);
    if (T2) form_T2.check(this->T2);
    if (T3) form_T3.check(this->T3);
    if (T4) form_T4.check(this->T4);
}
// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
