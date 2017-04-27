/**
   \file bdf/bdf_cards_cquad4.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF CQUAD4 cards.

   Detailed description
*/
#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"

// ID:
namespace {
    const char cID_bdf_cards_cquad4[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/errors.h"

#include <memory>

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

bdf::types::card cquad4::head = bdf::types::card("CQUAD4");

cquad4::cquad4(std::list<std::string> const &inp) :
        shell(inp) {
    this->cquad4::read(inp);
}

cquad4::cquad4(long const *EID, long const *PID,
               long const *G1, long const *G2, long const *G3, long const *G4,
               double const *THETA/*=nullptr*/,
               double const *ZOFFS/*=nullptr*/,
               long const *TFLAG/*=nullptr*/,
               double const *T1/*=nullptr*/, double const *T2/*=nullptr*/,
               double const *T3/*=nullptr*/, double const *T4/*=nullptr*/) :
        shell(EID, PID, G1, G2, G3, G3, THETA,ZOFFS, TFLAG,
              T1, T2, T3, T4) {}

cquad4::cquad4(long const *EID, long const *PID,
               long const *G1, long const *G2, long const *G3, long const *G4,
               long const *MCID,
               double const *ZOFFS/*=nullptr*/,
               long const *TFLAG/*=nullptr*/,
               double const *T1/*=nullptr*/, double const *T2/*=nullptr*/,
               double const *T3/*=nullptr*/, double const *T4/*=nullptr*/) :
        shell(EID, PID, G1, G2, G3, G4, MCID, ZOFFS, TFLAG,
              T1, T2, T3, T4) {}

void cquad4::read(std::list<std::string> const &inp) {
    auto pos = inp.rbegin();

    form_THETA.set_value(THETA, "");
    form_ZOFFS.set_value(ZOFFS, "");
    form_TFLAG.set_value(TFLAG, "");
    form_T1.set_value(T1, "");
    form_T2.set_value(T2, "");
    form_T3.set_value(T3, "");
    form_T4.set_value(T4, "");

    switch (inp.size() - 1) {
    case 16:
        ++pos;
    case 15:
        ++pos;
    case 14:
        form_T4.set_value(T4, *(pos++));
    case 13:
        form_T3.set_value(T3, *(pos++));
    case 12:
        form_T2.set_value(T2, *(pos++));
    case 11:
        form_T1.set_value(T1, *(pos++));
    case 10:
        form_TFLAG.set_value(TFLAG, *(pos++));
    case 9:
        ++pos;
    case 8:
        form_ZOFFS.set_value(ZOFFS, *(pos++));
    case 7:
        try {
            form_THETA.set_value(THETA, *pos);
            MCID.is_value = false;
            choose_mcid_theta = CHOOSE_MCID_THETA::has_THETA;
        } catch (errors::float_error) {
            try {
                form_MCID.set_value(MCID, *pos);
                form_THETA.set_value(THETA, "");
                choose_mcid_theta = CHOOSE_MCID_THETA::has_MCID;
            } catch (errors::int_error) {
                THETA.is_value = true;
                THETA.value = 0.;
                MCID.is_value = false;
                choose_mcid_theta = CHOOSE_MCID_THETA::has_THETA;
            }
        }
        ++pos;
    case 6:
        form_G4.set_value(G4, *(pos++));
        form_G3.set_value(G3, *(pos++));
        form_G2.set_value(G2, *(pos++));
        form_G1.set_value(G1, *(pos++));
        form_PID.set_value(PID, *(pos));
        // form_EID.set_value(EID, *pos);
        break;
    default:
        throw errors::parse_error(
            "CQUAD4", "Illegal number of entries.");
    }

    if (!THETA.is_value && !MCID.is_value)
        form_THETA.set_value(THETA, "");
    if (TFLAG.is_value) {
        if (!T1.is_value) form_T1.set_value(T1, "");
        if (!T2.is_value) form_T2.set_value(T2, "");
        if (!T3.is_value) form_T3.set_value(T3, "");
        if (!T4.is_value) form_T4.set_value(T4, "");
    }
}

cards::types cquad4::card_type() const {
    return types::CQUAD4;
}

cards::__base::card const &cquad4::operator() (std::list<std::string> const &inp) {
    this->cquad4::read(inp);
    return *this;
}

cards::__base::card const &cquad4::operator() (
    long const *EID, long const *PID,
    long const *G1, long const *G2, long const *G3, long const *G4,
    double const *THETA/*=nullptr*/,
    double const *ZOFFS/*=nullptr*/,
    long const *TFLAG/*=nullptr*/,
    double const *T1/*=nullptr*/, double const *T2/*=nullptr*/,
    double const *T3/*=nullptr*/, double const *T4/*=nullptr*/) {
    this->shell::operator() (EID, PID, G1, G2, G3, G4, THETA,ZOFFS, TFLAG,
                             T1, T2, T3, T4);
    return *this;
}

cards::__base::card const &cquad4::operator() (
    long const *EID, long const *PID,
    long const *G1, long const *G2, long const *G3, long const *G4,
    long const *MCID,
    double const *ZOFFS/*=nullptr*/,
    long const *TFLAG/*=nullptr*/,
    double const *T1/*=nullptr*/, double const *T2/*=nullptr*/,
    double const *T3/*=nullptr*/, double const *T4/*=nullptr*/) {
    this->shell::operator() (EID, PID, G1, G2, G3, G4, MCID, ZOFFS, TFLAG,
                             T1, T2, T3, T4);
    return *this;
}

void cquad4::collect_outdata(
    std::list<std::unique_ptr<format_entry>> &res) const {
    if (!bool(EID) || choose_mcid_theta == CHOOSE_MCID_THETA::UNDEF)
        return;
    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G1, G1)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G2, G2)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G3, G3)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_G4, G4)));
    if (choose_mcid_theta == CHOOSE_MCID_THETA::has_MCID)
        res.push_back(unique_ptr<format_entry>(format<long>(form_MCID, MCID)));
    else
        res.push_back(unique_ptr<format_entry>(format<double>(form_THETA, THETA)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_ZOFFS, ZOFFS)));
    if (bool(TFLAG) || bool(T1) || bool(T2) || bool(T3) || bool(T4)) {
        res.push_back(unique_ptr<format_entry>(format(empty)));
        if (bool(TFLAG))
            res.push_back(unique_ptr<format_entry>(format<long>(form_TFLAG, TFLAG)));
        else
            res.push_back(unique_ptr<format_entry>(format(empty)));
    } else goto finish;
    if (bool(T1))
        res.push_back(unique_ptr<format_entry>(format<double>(form_T1, T1)));
    else
        res.push_back(unique_ptr<format_entry>(format(empty)));
    if (bool(T2))
        res.push_back(unique_ptr<format_entry>(format<double>(form_T2, T2)));
    else
        res.push_back(unique_ptr<format_entry>(format(empty)));
    if (bool(T3))
        res.push_back(unique_ptr<format_entry>(format<double>(form_T3, T3)));
    else
        res.push_back(unique_ptr<format_entry>(format(empty)));
    if (bool(T4))
        res.push_back(unique_ptr<format_entry>(format<double>(form_T4, T4)));
    else
        res.push_back(unique_ptr<format_entry>(format(empty)));

finish:return;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
