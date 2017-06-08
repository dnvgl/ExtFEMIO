/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF GRID cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_grid[] _EXTFEMIO_UNUSED =
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
   const long cl0 = 0, cl1 = 1, cl_1 = -1, cl_2 = -2;
   const long cl1e8 = 100000000 - 1;
   const double cd0 = 0.;
}

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;
using namespace type_bounds;

using bdf::types::entry_type;

bdf::types::card grid::head = bdf::types::card("GRID");

namespace {
    auto const bound_ID_ = make_shared<bound<long>>(&cl1, &cl1e8);
    auto const bound_ID = bound_ID_.get();
}
entry_type<long> grid::form_ID("ID", bound_ID);
namespace {
    auto const bound_CP_ = make_shared<bound<long>>(&cl0, nullptr, nullptr, true);
    auto const bound_CP = bound_CP_.get();
}
entry_type<long> grid::form_CP("CP", bound_CP);
namespace {
    auto const bound_X1_ = make_shared<bound<double>>(nullptr, nullptr, &cd0);
    auto const bound_X1 = bound_X1_.get();
}
entry_type<double> grid::form_X1("X1", bound_X1);
namespace {
    auto const bound_X2_ = make_shared<bound<double>>(nullptr, nullptr, &cd0);
    auto const bound_X2 = bound_X2_.get();
}
entry_type<double> grid::form_X2("X2", bound_X2);
namespace {
    auto const bound_X3_ = make_shared<bound<double>>(nullptr, nullptr, &cd0);
    auto const bound_X3 = bound_X3_.get();
}
entry_type<double> grid::form_X3("X3", bound_X3);
namespace {
    auto const bound_CD_ = make_shared<bound<long>>(&cl_1, nullptr, nullptr, true);
    auto const bound_CD = bound_CD_.get();
}
entry_type<long> grid::form_CD("CD", bound_CD);
entry_type<vector<int>> grid::form_PS("PS");
namespace {
    auto const bound_SEID_ = make_shared<bound<long>>(&cl_1, nullptr, &cl0);
    auto const bound_SEID = bound_SEID_.get();
}
entry_type<long> grid::form_SEID("SEID", bound_SEID);

grid::grid(list<std::string> const &inp) :
card(inp) {
    this->grid::read(inp);
}

grid::grid(long const &ID, long const &CP,
           double const &X1, double const &X2, double const &X3) :
card(),
ID(ID), CP(CP), X1(X1), X2(X2), X3(X3),
CD(), PS(), SEID() {}

grid::grid(long const *ID, long const *CP,
           double const *X1, double const *X2, double const *X3,
           long const *CD, vector<int> const *PS, long const *SEID) :
        card(), ID(ID), CP(CP), X1(X1), X2(X2), X3(X3),
        CD(CD), PS(PS), SEID(SEID) {}

cards::types grid::card_type() const {
    return types::GRID;
}

cards::__base::card const &grid::operator()(list<std::string> const &inp) {
    this->grid::read(inp);
    return *this;
}

cards::__base::card const &grid::operator()(
    long const *ID, long const *CP,
    double const *X1, double const *X2, double const *X3,
    long const *CD, vector<int> const *PS,
    long const *SEID) {
    this->ID(ID);
    this->CP(CP);
    this->X1(X1);
    this->X2(X2);
    this->X3(X3);
    this->CD(CD);
    this->PS(PS);
    this->SEID(SEID);
    return *this;
}

cards::__base::card const &grid::operator()(
    long const &ID, long const &CP,
    double const &X1, double const &X2, double const &X3) {
    this->ID(ID);
    this->CP(CP);
    this->X1(X1);
    this->X2(X2);
    this->X3(X3);
    this->CD(nullptr);
    this->PS(nullptr);
    this->SEID(nullptr);
    return *this;
}

void grid::read(list<std::string> const &inp) {
    auto pos = inp.rbegin();

    form_SEID.set_value(SEID, "");
    form_PS.set_value(PS, "");
    form_CD.set_value(CD, "");

    switch (inp.size() - 1) {
    case 8:
        form_SEID.set_value(SEID, *(pos++));
    case 7:
        form_PS.set_value(PS, *(pos++));
    case 6:
        form_CD.set_value(CD, *(pos++));
    case 5:
        form_X3.set_value(X3, *(pos++));
        form_X2.set_value(X2, *(pos++));
        form_X1.set_value(X1, *(pos++));
        form_CP.set_value(CP, *(pos++));
        form_ID.set_value(ID, *pos);
        break;
    default:
        throw errors::parse_error("GRID", "Illegal number of entries.");
    }
}

void grid::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    if (!bool(ID))
        return;
    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_ID, ID)));
    res.push_back(unique_ptr<format_entry>(
                      bool(CP) ?
                      format<long>(form_CP, CP) :
                      format(empty)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_X1, X1)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_X2, X2)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_X3, X3)));
    if (bool(CD) || bool(PS) || bool(SEID)) {
        res.push_back(unique_ptr<format_entry>(
                          bool(CD) ?
                          format<long>(form_CD, CD) :
                          format(empty)));
    } else goto finish;
    if (bool(PS) || bool(SEID)) {
        res.push_back(unique_ptr<format_entry>(
                          bool(PS) ?
                          format<vector<int>>(form_PS, PS) :
                          format(empty)));
    } else goto finish;
    if (bool(SEID))
        res.push_back(unique_ptr<format_entry>(format<long>(form_SEID, SEID)));
finish:return;
}

void grid::check_data() {
    if (ID) form_ID.check(ID);
    if (CP) form_CP.check(CP);
    if (X1) form_X1.check(X1);
    if (X2) form_X2.check(X2);
    if (X3) form_X3.check(X3);
    if (CD) form_CD.check(CD);
    if (PS) form_PS.check(PS);
    if (SEID) form_SEID.check(SEID);
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
