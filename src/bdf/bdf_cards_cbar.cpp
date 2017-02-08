/**
   \file bdf/bdf_cards_cbar.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Defintions for Patran CBAR cards.

   Detailed description
*/
#include "StdAfx.h"
#include "extfem_misc.h"

// ID:
namespace {
    char const cID_bdf_cards_cbar[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <sstream>
#include <functional>
#include <memory>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#ifdef W2A
#undef W2A
#endif

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
   long static const cl1 = 1;
   double static const cd0 = 0.;
}

bdf::types::card cbar::head = bdf::types::card("CBAR");

// entry_type<long> const cbar::form_EID(
//    "EID", bound<long>(&cl1));
entry_type<long> const cbar::form_PID("PID");
entry_type<long> const cbar::form_GA("GA");
entry_type<long> const cbar::form_GB("GB");
entry_type<double> const cbar::form_X1("X1");
entry_type<long> const cbar::form_G0("G0", bound<long>(&cl1));
entry_type<double> const cbar::form_X2(
    "X2", bound<double>(nullptr, nullptr, nullptr, true));
entry_type<double> const cbar::form_X3(
    "X3", bound<double>(nullptr, nullptr, nullptr, true));
entry_type<std::string> const cbar::form_OFFT(
    "OFFT", bound<std::string>({
    "GGG", "BGG", "GGO", "BGO", "GOG", "BOG", "GOO", "BOO"}, "GGG"));
entry_type<list<int> > const cbar::form_PA("PA");
entry_type<list<int> > const cbar::form_PB("PB");
entry_type<double> const cbar::form_W1A(
    "W1A", bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const cbar::form_W2A(
    "W2A", bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const cbar::form_W3A(
    "W3A", bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const cbar::form_W1B(
    "W1B", bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const cbar::form_W2B(
    "W2B", bound<double>(nullptr, nullptr, &cd0));
entry_type<double> const cbar::form_W3B(
    "W3B", bound<double>(nullptr, nullptr, &cd0));

cbar::cbar(list<std::string> const &inp) :
element(inp) {
    this->read(inp);
}

cbar::cbar(
    long const *EID, long const *PID,
    long const *GA, long const *GB,
    double const *X1, double const *X2, double const *X3,
    std::string const *OFFT,
    list<int> const *PA,
    list<int> const *PB,
    double const *W1A, double const *W2A,
    double const *W3A, double const *W1B,
    double const *W2B, double const *W3B) :
    element(EID),
    choose_dir_code(CHOOSE_DIR_CODE::has_DVEC), PID(*PID),
    GA(*GA), GB(*GB), X1(*X1), G0(nullptr), X2(*X2), X3(*X3),
    OFFT(OFFT),
    PA(PA), PB(PB),
    W1A(W1A), W2A(W2A), W3A(W3A),
    W1B(W1B), W2B(W2B), W3B(W3B) {}

cbar::cbar(
    long const *EID, long const *PID,
    long const *GA, long const *GB, long const *G0,
    std::string const *OFFT,
    list<int> const *PA, list<int> const *PB,
    double const *W1A, double const *W2A,
    double const *W3A, double const *W1B,
    double const *W2B, double const *W3B) :
    element(EID),
    choose_dir_code(CHOOSE_DIR_CODE::has_DCODE), PID(*PID),
    GA(*GA), GB(*GB), X1(), G0(*G0), X2(), X3(),
    OFFT(OFFT),
    PA(PA), PB(PB),
    W1A(W1A), W2A(W2A), W3A(W3A),
    W1B(W1B), W2B(W2B), W3B(W3B) {}

cards::types const cbar::card_type(void) const {
    return cards::types::CBAR;
}

void cbar::read(list<std::string> const &inp) {
    auto pos = inp.rbegin();

    switch (inp.size() - 1) {
    case 16:
        form_W3B.set_value(W3B, *(pos++));
    case 15:
        form_W2B.set_value(W2B, *(pos++));
    case 14:
        form_W1B.set_value(W1B, *(pos++));
    case 13:
        form_W3A.set_value(W3A, *(pos++));
    case 12:
        form_W2A.set_value(W2A, *(pos++));
    case 11:
        form_W1A.set_value(W1A, *(pos++));
    case 10:
        form_PB.set_value(PB, *(pos++));
    case 9:
        form_PA.set_value(PA, *(pos++));
    case 8:
        form_OFFT.set_value(OFFT, *(pos++));
    case 7:
        form_X3.set_value(X3, *(pos++));
    case 6:
        form_X2.set_value(X2, *(pos++));
    case 5:
        try {
            form_X1.set_value(X1, *pos);
            if (!X2.is_value || !X3.is_value) {
                throw errors::parse_error(
                    "CBAR", "Incomplete direction vector.");
            }
            G0.is_value = false;
            choose_dir_code = CHOOSE_DIR_CODE::has_DVEC;
        } catch (errors::float_error) {
            form_G0.set_value(G0, *pos);
            X1.is_value = false;
            choose_dir_code = CHOOSE_DIR_CODE::has_DCODE;
        }
        ++pos;
        form_GB.set_value(GB, *(pos++));
        form_GA.set_value(GA, *(pos++));
        form_PID.set_value(PID, *(pos++));
        // form_EID.set_value(EID, *(pos++));
        break;
    default:
        throw errors::parse_error(
            "CBAR", "Illegal number of entries.");
    }
}

void cbar::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    res.push_back(unique_ptr<format_entry>(format(cbar::head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_EID, EID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_GA, GA)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_GB, GB)));
    if (choose_dir_code == CHOOSE_DIR_CODE::has_DCODE) {
        res.push_back(unique_ptr<format_entry>(format<long>(form_G0, G0)));
        if ((bool)OFFT || (bool)PA || (bool)PB || (bool)W1A || (bool)W2A ||
            (bool)W3A || (bool)W1B || (bool)W2B || (bool)W3B) {
            res.push_back(unique_ptr<format_entry>(format(cbar::empty)));
            res.push_back(unique_ptr<format_entry>(format(cbar::empty)));
        }
    } else {
        res.push_back(unique_ptr<format_entry>(format<double>(form_X1, X1)));
        res.push_back(unique_ptr<format_entry>(format<double>(form_X2, X2)));
        res.push_back(unique_ptr<format_entry>(format<double>(form_X3, X3)));
    }

    if ((bool)OFFT || (bool)PA || (bool)PB || (bool)W1A || (bool)W2A ||
        (bool)W3A || (bool)W1B || (bool)W2B || (bool)W3B)
        res.push_back(
            unique_ptr<format_entry>(format<std::string>(form_OFFT, OFFT)));
    else goto cont;

    if ((bool)PA || (bool)PB || (bool)W1A || (bool)W2A || (bool)W3A ||
        (bool)W1B || (bool)W2B || (bool)W3B)
        res.push_back(
            unique_ptr<format_entry>(format<list<int> >(form_PA, PA)));
    else goto cont;
    if ((bool)PB || (bool)W1A || (bool)W2A || (bool)W3A || (bool)W1B ||
        (bool)W2B || (bool)W3B)
        res.push_back(
            unique_ptr<format_entry>(format<list<int> >(form_PB, PB)));
    else goto cont;
    if ((bool)W1A || (bool)W2A || (bool)W3A || (bool)W1B || (bool)W2B ||
        (bool)W3B)
        res.push_back(unique_ptr<format_entry>(format<double>(form_W1A, W1A)));
    else goto cont;
    if ((bool)W2A || (bool)W3A || (bool)W1B || (bool)W2B || (bool)W3B)
        res.push_back(unique_ptr<format_entry>(format<double>(form_W2A, W2A)));
    else goto cont;
    if ((bool)W3A || (bool)W1B || (bool)W2B || (bool)W3B)
        res.push_back(unique_ptr<format_entry>(format<double>(form_W3A, W3A)));
    else goto cont;
    if ((bool)W1B || (bool)W2B || (bool)W3B)
        res.push_back(unique_ptr<format_entry>(format<double>(form_W1B, W1B)));
    else goto cont;
    if ((bool)W2B || (bool)W3B)
        res.push_back(unique_ptr<format_entry>(format<double>(form_W2B, W2B)));
    else goto cont;
    if ((bool)W3B)
        res.push_back(unique_ptr<format_entry>(format<double>(form_W3B, W3B)));
cont:
    return;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
