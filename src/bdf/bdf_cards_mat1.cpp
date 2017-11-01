/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF MAT1 cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_bdf_cards_mat1[]) =
        "@(#) $Id$";
}

#include <list>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
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
using namespace type_bounds;
using namespace cards;

using bdf::types::entry_type;

namespace {
    auto const cd0 = make_shared<double>(0.);
    auto const cd05 = make_shared<double>(0.5);
    auto const cd_1 = make_shared<double>(-1.);
}

bdf::types::card mat1::head = bdf::types::card("MAT1");

namespace {
    auto const bound_E = make_shared<bound<double>>(
        cd0, nullptr, nullptr, true);
}
entry_type<double> mat1::form_E("E", bound_E);
namespace {
    auto const bound_NU = make_shared<bound<double>>(cd_1, cd05, nullptr, true);
}
entry_type<double> mat1::form_NU("NU", bound_NU);

mat1::mat1(list<std::string> const &inp) :
mat(inp) {
    this->mat1::read(inp);
}

void mat1::read(list<std::string> const &inp) {

    form_MCSID.set_value(MCSID, "");
    form_SS.set_value(SS, "");
    form_SC.set_value(SC, "");
    form_ST.set_value(ST, "");
    form_GE.set_value(GE, "");
    form_TREF.set_value(TREF, "");
    form_A.set_value(A, "");
    form_RHO.set_value(RHO, "");
    form_NU.set_value(NU, "");
    form_G.set_value(G, "");

    auto pos = inp.rbegin();

    switch (inp.size() - 1) {
    case 16:
        ++pos;
    case 15:
        ++pos;
    case 14:
        ++pos;
    case 13:
        ++pos;
    case 12:
        form_MCSID.set_value(MCSID, *(pos++));
    case 11:
        form_SS.set_value(SS, *(pos++));
    case 10:
        form_SC.set_value(SC, *(pos++));
    case 9:
        form_ST.set_value(ST, *(pos++));
    case 8:
        form_GE.set_value(GE, *(pos++));
    case 7:
        form_TREF.set_value(TREF, *(pos++));
    case 6:
        form_A.set_value(A, *(pos++));
    case 5:
        form_RHO.set_value(RHO, *(pos++));
    case 4:
        form_NU.set_value(NU, *(pos++));
    case 3:
        form_G.set_value(G, *(pos++));
    case 2:
        form_E.set_value(E, *(pos++));
        form_MID.set_value(MID, *(pos));
        break;
    default:
        throw errors::parse_error("MAT1", "Illegal number of entries.");
    }

    if (bool(A) && !bool(TREF)) form_TREF.set_value(TREF, "");

    // remark 2
    if (!(bool(E) || bool(G)))
        throw errors::parse_error(
        "MAT1", "Either G or E has to be given.");
    if (!bool(NU)) {
        if (!bool(E)) {
            NU.value = 0.;
            NU.is_value = true;
            E.value = 0.;
            E.is_value = true;
        } else if (!bool(G)) {
            NU.value = 0.;
            NU.is_value = true;
            G.value = 0.;
            G.is_value = true;
        } else {
            NU.value = (double(E) / 2. / double(G)) - 1.;
            NU.is_value = true;
        }
    } else if (!bool(E)) {
        E.value = 2. * (1 + double(NU)) * double(G);
        E.is_value = true;
    } else if (!bool(G)) {
        G.value = double(E) / (2. * (1 + double(NU)));
        G.is_value = true;
    }
}

mat1::mat1(long *MID, double *E, double *G, double *NU, double *RHO,
           double *A, double *TREF, double *GE, double *ST,
           double *SC, double *SS, long *MCSID) :
        mat(MID, RHO, TREF, GE, ST, SC, SS, MCSID), E{E}, G{G}, NU{NU}, A{A} {
            this->mat1::check_data();
}

cards::__base::card const &mat1::operator() (const list<std::string> &inp) {
    this->mat1::read(inp);
    return *this;
}

cards::__base::card const &mat1::operator() (
    long *MID, double *E, double *G, double *NU,
    double *RHO/*=nullptr*/, double *A/*=nullptr*/,
    double *TREF/*=nullptr*/, double *GE/*=nullptr*/,
    double *ST/*=nullptr*/, double *SC/*=nullptr*/,
    double *SS/*=nullptr*/, long *MCSID/*=nullptr*/) {
    this->mat::operator() (MID, RHO, TREF, GE, ST, SC, SS, MCSID);
    this->E(E);
    this->G(G);
    this->NU(NU);
    this->A(A);
    this->mat1::check_data();
    return *this;
}

cards::types mat1::card_type() const {
    return types::MAT1;
};

void mat1::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    if (!bool(MID)) return;
    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_MID, MID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_E, E)));
    if (bool(G))
        res.push_back(unique_ptr<format_entry>(format<double>(form_G, G)));
    else
        res.push_back(unique_ptr<format_entry>(format(empty)));
    if (bool(NU))
        res.push_back(unique_ptr<format_entry>(format<double>(form_NU, NU)));
    else
        res.push_back(unique_ptr<format_entry>(format(empty)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_RHO, RHO)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_A, A)));
    if (bool(TREF))
        res.push_back(unique_ptr<format_entry>(format<double>(form_TREF, TREF)));
    else
        res.push_back(unique_ptr<format_entry>(format(empty)));
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

void mat1::check_data() {
    this->mat::check_data();
    if (E) mat1::form_E.check(E);
    if (NU) mat1::form_NU.check(NU);
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
