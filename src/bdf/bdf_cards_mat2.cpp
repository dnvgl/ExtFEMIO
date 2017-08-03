/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF MAT2 cards.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_bdf_cards_mat2[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

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

using bdf::types::entry_type;

namespace {
    const long cl0 = 0, cl1 = 1;
    const double cd0 = 0., cd05 = 0.5, cd_1 = -1.;
}

bdf::types::card mat2::head = bdf::types::card("MAT2");

mat2::mat2(list<std::string> const &inp) :
mat(inp) {
    this->mat2::read(inp);
}

cards::__base::card const &mat2::operator() (const list<std::string> &inp) {
    this->mat2::read(inp);
    return *this;
}

mat2::mat2(long *MID, double *G11, double *G12, double *G13,
           double *G22, double *G23, double *G33, double *RHO,
           double *A1, double *A2, double *A3, double *TREF,
           double *GE, double *ST/*=nullptr*/, double *SC/*=nullptr*/,
           double *SS/*=nullptr*/, long *MCSID/*=nullptr*/) :
        mat(MID, RHO, TREF, GE, ST, SC, SS, MCSID),
        G11(G11),G12(G12), G13(G13), G22(G22),
        G23(G23), G33(G33), A1(A1), A2(A2), A3(A3) {
    this->mat2::check_data();
}


cards::__base::card const &mat2::operator()(
    long *MID,
    double *G11, double *G12, double *G13, double *G22, double *G23,
    double *G33,
    double *RHO,
    double *A1, double *A2, double *A3,
    double *TREF, double *GE,
    double *ST/*=nullptr*/, double *SC/*=nullptr*/, double *SS/*=nullptr*/,
    long *MCSID/*=nullptr*/) {
    this->mat::operator() (MID, RHO, TREF, GE, ST, SC, SS, MCSID);
    this->G11(G11);
    this->G12(G12);
    this->G13(G13);
    this->G22(G22);
    this->G23(G23);
    this->G33(G33);
    this->A1(A1);
    this->A2(A2);
    this->A3(A3);
    this->mat2::check_data();
    return *this;
}

void mat2::read(list<std::string> const &inp) {
    mat::form_MCSID.set_value(MCSID, "");
    mat::form_SS.set_value(SS, "");
    mat::form_SC.set_value(SC, "");
    mat::form_ST.set_value(ST, "");
    mat::form_GE.set_value(GE, "");
    mat::form_TREF.set_value(TREF, "");
    mat::form_A.set_value(A1, "");
    mat::form_A.set_value(A2, "");
    mat::form_A.set_value(A3, "");
    mat::form_RHO.set_value(RHO, "");
    mat::form_G.set_value(G33, "");
    mat::form_G.set_value(G23, "");
    mat::form_G.set_value(G22, "");
    mat::form_G.set_value(G13, "");
    mat::form_G.set_value(G12, "");
    mat::form_G.set_value(G11, "");

    auto pos = inp.rbegin();

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
        ++pos;
    case 18:
        ++pos;
    case 17:
        form_MCSID.set_value(MCSID, *(pos++));
    case 16:
        form_SS.set_value(SS, *(pos++));
    case 15:
        form_SC.set_value(SC, *(pos++));
    case 14:
        form_ST.set_value(ST, *(pos++));
    case 13:
        form_GE.set_value(GE, *(pos++));
    case 12:
        form_TREF.set_value(TREF, *(pos++));
    case 11:
        form_A.set_value(A3, *(pos++));
    case 10:
        form_A.set_value(A2, *(pos++));
    case 9:
        form_A.set_value(A1, *(pos++));
    case 8:
        form_RHO.set_value(RHO, *(pos++));
    case 7:
        form_G.set_value(G33, *(pos++));
    case 6:
        form_G.set_value(G23, *(pos++));
    case 5:
        form_G.set_value(G22, *(pos++));
    case 4:
        form_G.set_value(G13, *(pos++));
    case 3:
        form_G.set_value(G12, *(pos++));
    case 2:
        form_G.set_value(G11, *(pos++));
        form_MID.set_value(MID, *(pos));
        break;
    default:
        throw errors::parse_error("MAT2", "Illegal number of entries.");
    }

    if ((bool(A1) || bool(A2) || bool(A3)) && !bool(TREF))
        form_TREF.set_value(TREF, "");
}

cards::types mat2::card_type() const {
    return types::MAT2;
};

void mat2::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    if (long(MID) == 0)
        return;
    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_MID, MID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_G, G11)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_G, G12)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_G, G13)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_G, G22)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_G, G23)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_G, G33)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_RHO, RHO)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_A, A1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_A, A2)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_A, A3)));
    res.push_back(unique_ptr<format_entry>(
                      bool(TREF) ?
                      format<double>(form_TREF, TREF) :
                      format(empty)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_GE, GE)));
    if (bool(ST) || bool(SC) || bool(SS) || bool(MCSID))
        res.push_back(unique_ptr<format_entry>(
                          bool(ST) ?
                          format<double>(form_ST, ST) :
                          format(empty)));
    else goto finish;
    if (bool(SC) || bool(SS) || bool(MCSID))
        res.push_back(unique_ptr<format_entry>(
                          bool(SC) ?
                          format<double>(form_SC, SC) :
                          format(empty)));
    else goto finish;
    if (bool(SS) || bool(MCSID))
        res.push_back(unique_ptr<format_entry>(
                          bool(SS) ?
                          format<double>(form_SS, SS) :
                          format(empty)));
    else goto finish;
    if (bool(MCSID))
        res.push_back(unique_ptr<format_entry>(format<long>(form_MCSID, MCSID)));

finish:return;
}

void mat2::check_data() {
    this->mat::check_data();
    if (A1) mat::form_A.check(A1);
    if (A2) mat::form_A.check(A2);
    if (A3) mat::form_A.check(A3);
    if (G33) mat::form_G.check(G33);
    if (G23) mat::form_G.check(G23);
    if (G22) mat::form_G.check(G22);
    if (G13) mat::form_G.check(G13);
    if (G12) mat::form_G.check(G12);
    if (G11) mat::form_G.check(G11);
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
