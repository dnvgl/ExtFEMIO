/**
   \file bdf_cards_cmass4.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Definitions for Nastran BDF CMASS4 cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_cmass4[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <cassert>

#include "bdf/cards.h"
#include "bdf/types.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
    long static const cl0 = 0;
    long static const cl1 = 1;
}

using dnvgl::extfem::bdf::types::entry_type;
using dnvgl::extfem::bdf::types::entry_value;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

// entry_type<long> const cmass4::form_EID(
//    "EID", bdf::type_bounds::bound<long>(&cl1));
entry_type<double> const cmass4::form_M("M");
entry_type<long> const cmass4::form_S1("S1");
entry_type<long> const cmass4::form_S2("S2");

cmass4::cmass4(void) :
element(nullptr),
M(nullptr), S1(nullptr), S2(nullptr) {}

cmass4::cmass4(std::list<std::string> const &inp) :
element(inp) {
    this->read(inp);
}

cmass4::cmass4(long const *EID, double const *M,
               long const *S1, long const *S2/*=nullptr*/) :
               element(EID),
               M(M), S1(S1), S2(S2) {
    if (((long)this->EID < 1l) || ((long)this->EID > 100000000l))
        throw errors::error("CMASS4", "EID not in valid range");
}

cards::__base::card const &cmass4::operator() (
    long const *EID, double const *M,
    long const *S1, long const *S2/*=nullptr*/) {
    this->EID = EID;
    this->M = *M;
    this->S1 = *S1;
    if (S2)
        this->S2 = *S2;
    else
        this->S2 = nullptr;
    return *this;
}

bdf::types::card cmass4::head = bdf::types::card("CMASS4");

void cmass4::read(std::list<std::string> const &inp) {
    auto pos = inp.begin();

    if (pos == inp.end()) goto invalid;
    ++pos;
    if (pos == inp.end()) goto invalid;
    form_EID.set_value(EID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_M.set_value(M, *(pos++));
    if (pos == inp.end()) goto end;
    form_S1.set_value(S1, *(pos++));
    if (pos == inp.end()) goto end;
    form_S2.set_value(S2, *(pos++));
    goto end;

invalid:
    throw errors::parse_error("CMASS4", "Illegal number of entries.");
end:;
}

cards::types const cmass4::card_type(void) const {
    return types::CMASS4;
}

void cmass4::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {

    if (static_cast<long>(EID) <= 0)
        return;

    res.push_back(format(cmass4::head));

    res.push_back(format<long>(form_EID, EID));
    res.push_back(format<double>(form_M, M));
    if (S1 || S2)
        res.push_back(format<long>(form_S1, S1));
    if (S2)
        res.push_back(format<long>(form_S2, S2));

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
