/**
   \file bdf/bdf_cards_pbarl.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBARL cards.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_pbarl[] _EXTFEMIO_UNUSED =
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
    const double cd0 = 0;
}

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf::cards;
using bdf::types::entry_type;

entry_type<std::string> const pbarl::form_GROUP(
    "GROUP", bdf::type_bounds::bound<std::string>("MSCBML0"));
entry_type<std::string> const pbarl::form_TYPE(
    "TYPE", bdf::type_bounds::bound<std::string>({
    "T", "TW", "I", "L", "ROD", "TUBE", "CHAN", "BOX", "BAR", "CROSS",
    "H", "T1", "I1", "CHAN1", "Z", "CHAN2", "T2", "BOX1", "HEXA",
    "HAT", "HAT1", "DBOX"}));
entry_type<double> const pbarl::form_DIM(
    "DIM", bdf::type_bounds::bound<double>(&cd0));
entry_type<double> const pbarl::form_NSM(
    "NSM", bdf::type_bounds::bound<double>(nullptr, nullptr, &cd0));

pbarl::pbarl(list<std::string> const &inp) :
bar_prop(inp) {
    this->pbarl::read(inp);
}

void pbarl::read(list<std::string> const &inp) {

    size_t dim_num;
    size_t i;

    auto pos = inp.begin();

    if (pos == inp.end()) goto invalid;
    ++pos;
    if (pos == inp.end()) goto invalid;
    form_PID.set_value(PID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_MID.set_value(MID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_GROUP.set_value(GROUP, *(pos++));
    if (GROUP.value != "MSCBML0")
        throw errors::parse_error(
        "PBARL", "Currently only GROUP==MSCBML0 is supported.");
    if (pos == inp.end()) goto invalid;
    form_TYPE.set_value(TYPE, *(pos++));
    if (pos == inp.end()) goto invalid;
    dim_num = this->l_geom::get_dim(TYPE.value);
    if (dim_num < 1)
        throw errors::parse_error(
            "PBARL", "Unknown beam type " + TYPE.value + ".");

    ++pos;
    for (i = 1; i < 4; i++) {
        if (pos == inp.end()) goto invalid;
        ++pos;
    }

    for (i = 0; i < dim_num; i++) {
        if (pos == inp.end()) goto invalid;
        DIM.push_back(form_DIM(*(pos++)));
    }
    if (pos == inp.end()) goto end;
    form_NSM.set_value(NSM, *(pos));

    goto end;

invalid:
    throw errors::parse_error("PBARL", "Illegal number of entries.");
end:;
}

types pbarl::card_type() const {
    return types::PBARL;
};

void pbarl::collect_outdata(
    list<std::unique_ptr<format_entry> > &res) const {
    throw std::not_implemented(__FILE__, __LINE__, "can't write PBARL.");
}

bdf::cards::__base::card const &pbarl::operator()(list<std::string> const &inp) {
    this->pbarl::read(inp);
    return *this;
}

void pbarl::check_data() const {
    this->bar_prop::check_data();
    if (GROUP) pbarl::form_GROUP.check(GROUP);
    if (TYPE) pbarl::form_TYPE.check(TYPE);
    if (DIM.size()>0) for (auto pos : DIM) pbarl::form_DIM.check(pos);
    if (NSM) pbarl::form_NSM.check(NSM);
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test ||
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
