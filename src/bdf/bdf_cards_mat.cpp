/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Common definitions for Nastran BDF MAT1 and MAT2 cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf_cards_mat[]) =
        "@(#) $Id$";
}

#include <list>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"

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

using namespace dnvgl::extfem::bdf;

using types::entry_type;
using namespace type_bounds;

using namespace cards::__base;

namespace {
    auto const cl0 = make_shared<long>(0);
    auto const cl1 = make_shared<long>(1);
    auto const cd0 = make_shared<double>(0.);
    auto const cd05 = make_shared<double>(0.5);
    auto const cd_1 = make_shared<double>(-1.);

    auto const bound_MID = make_shared<bound<long>>(cl1);
}
entry_type<long> mat::form_MID("MID", bound_MID);
namespace {
    auto const bound_G = make_shared<bound<double>>(cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_G("G", bound_G);
namespace {
    auto const bound_RHO = make_shared<bound<double>>(cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_RHO("RHO", bound_RHO);
namespace {
    auto const bound_A = make_shared<bound<double>>(cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_A("A", bound_A);
namespace {
    auto const bound_TREF = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_TREF("TREF", bound_TREF);
namespace {
    auto const bound_GE = make_shared<bound<double>>(cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_GE("GE", bound_GE);
namespace {
    auto const bound_ST = make_shared<bound<double>>(cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_ST("ST", bound_ST);
namespace {
    auto const bound_SC = make_shared<bound<double>>(cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_SC("SC", bound_SC);
namespace {
    auto const bound_SS = make_shared<bound<double>>(cd0, nullptr, nullptr, true);
}
entry_type<double> mat::form_SS("SS", bound_SS);
namespace {
    auto const bound_MCSID = make_shared<bound<long>>(
        cl0, nullptr, nullptr, true);
}
entry_type<long> mat::form_MCSID("MCSID", bound_MCSID);

mat::mat(const list<std::string> &inp) : card(inp) {}

mat::mat(long *MID, double *RHO/*=nullptr*/, double *TREF/*=nullptr*/,
         double *GE/*=nullptr*/, double *ST/*=nullptr*/, double *SC/*=nullptr*/,
         double *SS/*=nullptr*/, long *MCSID/*=nullptr*/) :
        card(),
        MID{MID}, RHO(RHO), TREF{TREF}, GE{GE},
        ST{ST}, SC{SC}, SS{SS}, MCSID{MCSID} {
            this->mat::check_data();
}

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
    this->mat::check_data();
    return;
}

void mat::check_data() {
    if (MID) mat::form_MID.check(MID);
    if (RHO) mat::form_RHO.check(RHO);
    if (TREF) mat::form_TREF.check(TREF);
    if (GE) mat::form_GE.check(GE);
    if (ST) mat::form_ST.check(ST);
    if (SC) mat::form_SC.check(SC);
    if (SS) mat::form_SS.check(SS);
    if (MCSID) mat::form_MCSID.check(MCSID);
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//           (make -C ../../cbuild test ||
//            ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
