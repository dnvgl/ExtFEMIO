/**
   \file bdf/bdf_cards_momforce_base.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Common definitions for Nastran BDF `FORCE` and `MOMENT` cards.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

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

namespace {
    long static const cl0 = 0, cl1 = 1;
    double static const cd0 = 0.;
}


using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

using bdf::types::entry_type;
using namespace type_bounds;

entry_type<long> const cards::__base::momforce::form_SID(
    "SID", bound<long>(&cl1));
entry_type<long> const cards::__base::momforce::form_G(
    "G", bound<long>(&cl1));
entry_type<long> const cards::__base::momforce::form_CID(
    "CID", bound<long>(&cl0, nullptr, &cl0));
entry_type<double> const cards::__base::momforce::form_F("F");
entry_type<double> const cards::__base::momforce::form_N1(
    "N1", bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const cards::__base::momforce::form_N2(
    "N2", bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const cards::__base::momforce::form_N3(
    "N3", bound<double>(nullptr, nullptr, &cd0));

cards::__base::momforce::momforce(void) : card() {}

cards::__base::momforce::momforce(std::list<std::string> const &inp) :
card(inp) {
    this->read(inp);
}

cards::__base::momforce::momforce(
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2, double const *N3) :
    SID(*SID), G(*G), CID(*CID), F(*F), N1(N1), N2(N2), N3(N3) {}

cards::__base::card const &cards::__base::momforce::operator() (
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2/*=nullptr*/,
    double const *N3/*=nullptr*/) {
    this->SID = *SID;
    this->G = *G;
    this->CID = *CID;
    this->F = *F;
    this->N1 = N1;
    if (N2)
        this->N2 = N2;
    else
        this->N2 = nullptr;
    if (N3)
        this->N3 = N3;
    else
        this->N3 = nullptr;
    return *this;
}


void cards::__base::momforce::read(std::list<std::string> const &inp) {

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
        form_SID.set_value(SID, *(pos++));
        break;
    default:
        throw errors::parse_error("FORCE/MOMENT", "Illegal number of entries.");
    }
}

void cards::__base::momforce::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    if (static_cast<long>(SID) <= 0) return;

    res.push_back(get_head());

    res.push_back(format<long>(form_SID, SID));
    res.push_back(format<long>(form_G, G));
    res.push_back(format<long>(form_CID, CID));
    res.push_back(format<double>(form_F, F));
    res.push_back(format<double>(form_N1, N1));
    if (N2 || N3)
        res.push_back(format<double>(form_N2, N2));
    if (N3)
        res.push_back(format<double>(form_N3, N3));
    return;
}

force::force(void) :
cards::__base::momforce(&cl0, &cl0, &cl0, &cd0, &cd0, &cd0, &cd0) {}

force::force(std::list<std::string> const &inp) :
cards::__base::momforce(inp) {}

force::force(
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2/*=nullptr*/, double const *N3/*=nullptr*/) :
    cards::__base::momforce(SID, G, CID, F, N1, N2, N3) {};

bdf::types::card force::head = bdf::types::card("FORCE");

std::unique_ptr<format_entry> force::get_head(void) const {
    return format(force::head);
}

cards::types const force::card_type(void) const {
    return types::FORCE;
}

moment::moment(void) :
cards::__base::momforce(&cl0, &cl0, &cl0, &cd0, &cd0, &cd0, &cd0) {}

moment::moment(std::list<std::string> const &inp) :
cards::__base::momforce(inp) {}

moment::moment(
    long const *SID, long const *G, long const *CID,
    double const *F,
    double const *N1, double const *N2/*=nullptr*/, double const *N3/*=nullptr*/) :
    cards::__base::momforce(SID, G, CID, F, N1, N2, N3) {};

bdf::types::card moment::head = bdf::types::card("MOMENT");

std::unique_ptr<format_entry> moment::get_head(void) const {
    return format(moment::head);
}

cards::types const moment::card_type(void) const {
    return types::MOMENT;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
