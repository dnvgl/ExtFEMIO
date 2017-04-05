/**
   \file bdf/bdf_cards_prod.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PROD cards.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_prod[] _EXTFEMIO_UNUSED =
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

namespace {
    const long cl1 = 1;
    const double cd0 = 0.;
}

using namespace dnvgl::extfem;
using namespace bdf::cards;

using bdf::types::entry_type;

const entry_type<long> prod::form_PID(
    "PID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<long> prod::form_MID(
    "MID", bdf::type_bounds::bound<long>(&cl1));
const entry_type<double> prod::form_A("A");
const entry_type<double> prod::form_J(
    "J",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));
const entry_type<double> prod::form_C(
    "C", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));
const entry_type<double> prod::form_NSM(
    "J",
    bdf::type_bounds::bound<double>(nullptr, nullptr, nullptr, true));

prod::prod(std::list<std::string> const &inp) :
card(inp) {
    this->prod::read(inp);
}

void prod::read(std::list<std::string> const &inp) {

    auto pos = inp.rbegin();

    form_J.set_value(J, "");
    form_C.set_value(C, "");
    form_NSM.set_value(NSM, "");

    switch (inp.size() - 1) {
    case 8:
        ++pos;
    case 7:
        ++pos;
    case 6:
        form_NSM.set_value(NSM, *(pos++));
    case 5:
        form_C.set_value(C, *(pos++));
    case 4:
        form_J.set_value(J, *(pos++));
    case 3:
        form_A.set_value(A, *(pos++));
        form_MID.set_value(MID, *(pos++));
        form_PID.set_value(PID, *(pos));
        break;
    default:
        throw errors::parse_error(
            "CBAR.", "Illegal number of entries.");
    }

    if (!C.is_value) form_C.set_value(C, "");
}

types prod::card_type() const {
    return types::PROD;
}

void prod::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    throw std::not_implemented(__FILE__, __LINE__, "can't write PROD.");
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
