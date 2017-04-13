/**
\file bdf/bdf_cards_mat.cpp
\author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
\copyright Copyright © 2016 by DNV GL SE
\brief Common definitions for Nastran BDF MAT1 and MAT2 cards.

Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_mat[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <list>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
    const long cl0 = 0, cl1 = 1;
    const double cd0 = 0., cd05 = 0.5, cd_1 = -1.;
}

using namespace dnvgl::extfem::bdf;

using types::entry_type;
using namespace type_bounds;

using namespace cards::__base;

const entry_type<long> mat::form_MID(
    "MID", bound<long>(&cl1));
const entry_type<double> mat::form_G(
    "G", bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> mat::form_RHO(
    "RHO", bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_A(
    "A", bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_TREF(
    "TREF", bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_GE(
    "GE", bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> mat::form_ST(
    "ST", bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> mat::form_SC(
    "SC", bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<double> mat::form_SS(
    "SS", bound<double>(&cd0, nullptr, nullptr, true));
const entry_type<long> mat::form_MCSID(
    "MCSID", bound<long>(&cl0, nullptr, nullptr, true));

mat::mat(const std::list<std::string> &inp) : card(inp) {}

mat::mat() : card() {}

mat::mat(long *MID, double *RHO/*=nullptr*/, double *TREF/*=nullptr*/,
         double *GE/*=nullptr*/, double *ST/*=nullptr*/, double *SC/*=nullptr*/,
         double *SS/*=nullptr*/, long *MCSID/*=nullptr*/) :
        card(),
        MID{MID}, RHO(RHO), TREF{TREF}, GE{GE},
        ST{ST}, SC{SC}, SS{SS}, MCSID{MCSID} {}

void mat::operator() (
    long *MID, double *RHO/*=nullptr*/, double *TREF/*=nullptr*/,
    double *GE/*=nullptr*/, double *ST/*=nullptr*/, double *SC/*=nullptr*/,
    double *SS/*=nullptr*/, long *MCSID/*=nullptr*/) {
    this->MID(MID);
    this->RHO(RHO);
    this->TREF(TREF);
    this->GE(GE);
    this->ST(ST);
    this->SC(SC);
    this->SS(SS);
    this->MCSID(MCSID);
    return;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//           (make -C ../../cbuild test ||
//            ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
