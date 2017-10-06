/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF `FORCE` and `MOMENT` cards.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    char const cID_bdf_cards_momforce_base[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

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
using namespace cards;
using namespace cards::__base;

using bdf::types::entry_type;
using type_bounds::bound;

namespace {
    auto const cl0 = make_shared<long>(0);
    auto const cl1 = make_shared<long>(1);
    auto const cd0 = make_shared<double>(0.);
}

namespace {
    auto const bound_SID = make_shared<bound<long>>(cl1);
}
entry_type<long> momforce::form_SID("SID", bound_SID);
namespace {
    auto const bound_G = make_shared<bound<long>>(cl1);
}
entry_type<long> momforce::form_G("G", bound_G);
namespace {
    auto const bound_CID = make_shared<bound<long>>(cl0, nullptr, cl0);
}
entry_type<long> momforce::form_CID("CID", bound_CID);
entry_type<double> momforce::form_F("F");
namespace {
    auto const bound_N1 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> momforce::form_N1("N1", bound_N1);
namespace {
    auto const bound_N2 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> momforce::form_N2("N2", bound_N2);
namespace {
    auto const bound_N3 = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> momforce::form_N3("N3", bound_N3);

momforce::momforce(list<std::string> const &inp) : card(inp) {
    this->momforce::read(inp);
}

momforce::momforce(
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2, double const *N3) :
        card(),
        SID(*SID), G(*G), CID(*CID), F(*F), N1(N1), N2(N2), N3(N3) {
    this->momforce::check_data();
}

card const &momforce::operator() (
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2/*=nullptr*/,
    double const *N3/*=nullptr*/) {
    this->momforce::SID(SID);
    this->momforce::G(G);
    this->momforce::CID(CID);
    this->momforce::F(F);
    this->momforce::N1(N1);
    this->momforce::N2(N2);
    this->momforce::N3(N3);
    this->momforce::check_data();
    return *this;
}

void momforce::read(list<std::string> const &inp) {

    auto pos = inp.rbegin();

    form_N2.set_value(N2, "");
    form_N3.set_value(N3, "");

    switch (inp.size() - 1) {
    case 8:
        ++pos;
    case 7:
        form_N3.set_value(N3, *(pos++));
    case 6:
        form_N2.set_value(N2, *(pos++));
    case 5:
        form_N1.set_value(N1, *(pos++));
        if (N1 == 0. && N2 == 0. && N3 == 0.) {
            throw errors::parse_error(
                "FORCE/MOMENT", "At least one of N1, N2, and N3 has to be != 0..");
        }
        form_F.set_value(F, *(pos++));
        form_CID.set_value(CID, *(pos++));
        form_G.set_value(G, *(pos++));
        form_SID.set_value(SID, *(pos));
        break;
    default:
        throw errors::parse_error("FORCE/MOMENT", "Illegal number of entries.");
    }
}

void momforce::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    if (static_cast<long>(SID) <= 0) return;

    res.push_back(unique_ptr<format_entry>(get_head()));

    res.push_back(unique_ptr<format_entry>(format<long>(form_SID, SID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G, G)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_CID, CID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_F, F)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_N1, N1)));
    if (N2 || N3)
        res.push_back(unique_ptr<format_entry>(format<double>(form_N2, N2)));
    if (N3)
        res.push_back(unique_ptr<format_entry>(format<double>(form_N3, N3)));
    return;
}

void momforce::check_data() {
    if (SID) momforce::form_SID.check(SID);
    if (G) momforce::form_G.check(G);
    if (CID) momforce::form_CID.check(CID);
    if (F) momforce::form_F.check(F);
    if (N1) momforce::form_N1.check(N1);
    if (N2) momforce::form_N2.check(N2);
    if (N3) momforce::form_N3.check(N3);
}

card const &momforce::operator() (
    list<std::string> const &inp) {
    this->momforce::read(inp);
    return *this;
}

force::force(list<std::string> const &inp) : momforce(inp) {}

force::force(
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2/*=nullptr*/, double const *N3/*=nullptr*/) :
    momforce(SID, G, CID, F, N1, N2, N3) {};

bdf::types::card force::head = bdf::types::card("FORCE");

format_entry *force::get_head() const {
    return format(head);
}

cards::types force::card_type() const {
    return types::FORCE;
}

moment::moment(list<std::string> const &inp) : momforce(inp) {}

moment::moment(
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2/*=nullptr*/, double const *N3/*=nullptr*/) :
    momforce(SID, G, CID, F, N1, N2, N3) {};

bdf::types::card moment::head = bdf::types::card("MOMENT");

format_entry *moment::get_head() const {
    return format(head);
}

cards::types moment::card_type() const {
    return types::MOMENT;
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
