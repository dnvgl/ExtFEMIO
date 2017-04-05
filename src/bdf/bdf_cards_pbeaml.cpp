/**
   \file bdf/bdf_cards_pbeaml.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBEAML cards.

   Detailed description
   */
#include "StdAfx.h"

#include "extfem_misc.h"

// ID:
namespace {
    const char cID_bdf_cards_pbeaml[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <memory>

#include "bdf/cards.h"
#include "bdf/errors.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace {
    const double cd0 = 0., cd1 = 1.;
}

using namespace dnvgl::extfem;
using namespace bdf::cards;

using bdf::types::entry_type;

const entry_type<std::string> pbeaml::form_GROUP(
    "GROUP", bdf::type_bounds::bound<std::string>("MSCBML0"));
const entry_type<std::string> pbeaml::form_TYPE(
    "TYPE", bdf::type_bounds::bound<std::string>({
    "T", "TW", "I", "L", "ROD", "TUBE", "CHAN", "BOX", "BAR", "CROSS",
    "H", "T1", "I1", "CHAN1", "Z", "CHAN2", "T2", "BOX1", "HEXA",
    "HAT", "HAT1", "DBOX"}));
const entry_type<double> pbeaml::form_DIM(
    "DIM", bdf::type_bounds::bound<double>(
    &cd0));
const entry_type<double> pbeaml::form_NSM(
    "NSM", bdf::type_bounds::bound<double>(
    nullptr, nullptr, &cd0));
const entry_type<std::string> pbeaml::form_SO(
    "SO", bdf::type_bounds::bound<std::string>({"YES", "NO"}, "YES"));
const entry_type<double> pbeaml::form_X_XB(
    "X/XB", bdf::type_bounds::bound<double>(
    &cd0, nullptr,
    &cd1));

pbeaml::pbeaml(const std::list<std::string> &inp) :
beam_prop(inp) {
    this->pbeaml::read(inp);
}

void pbeaml::read(std::list<std::string> const & inp) {

    size_t dim_num;
    size_t i, j{0};

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
        "PBEAML", "Currently only GROUP==MSCBML0 is supported.");
    if (pos == inp.end()) goto invalid;
    form_TYPE.set_value(TYPE, *(pos++));
    if (pos == inp.end()) goto invalid;
    if (dimnum1.find(TYPE.value) != dimnum1.end())
        dim_num = 1;
    else if (dimnum2.find(TYPE.value) != dimnum2.end())
        dim_num = 2;
    else if (dimnum3.find(TYPE.value) != dimnum3.end())
        dim_num = 3;
    else if (dimnum4.find(TYPE.value) != dimnum4.end())
        dim_num = 4;
    else if (dimnum5.find(TYPE.value) != dimnum5.end())
        dim_num = 5;
    else if (dimnum6.find(TYPE.value) != dimnum6.end())
        dim_num = 6;
    else if (dimnum10.find(TYPE.value) != dimnum10.end())
        dim_num = 10;
    else
        throw errors::parse_error(
        "PBEAML", "Unknown beam type " + TYPE.value + ".");

    ++pos;
    for (i = 1; i < 4; i++) {
        if (pos == inp.end()) goto invalid;
        ++pos;
    }

    // DIM.push_back(new std::list<dnvgl::extfem::bdf::double> >);
    DIM.push_back(std::vector<double>());
    for (i = 0; i < dim_num; i++) {
        if (pos == inp.end()) goto invalid;
        (DIM[0]).push_back(form_DIM(*(pos++)));
    }
    if (pos == inp.end()) goto end;
    NSM.push_back(form_NSM(*(pos++)));

    // Read further cross section definitions for tapered beams. The
    // 'goto's are used because SO, and X/XB have default values. This
    // code is required because it is valid to have only one cross
    // section description defined with attached empty cells. Then the
    // code first assumes that more definitions are defined, using
    // default values for SO and X/XB, only to determine that no DIMs
    // are defined, so no further cross sections are available and
    // cleaning up SO and X/XB afterwards. This should raise an error
    // when SO and/or X/XB are given, but no DIM's, but it does not.
    while (pos != inp.end()) {
        if (pos == inp.end()) goto end;
        j++;
        // DIM.push_back(new std::list<dnvgl::extfem::bdf::types::entry_value<double> >);
        DIM.push_back(std::vector<double>());
        try {
            SO.push_back(form_SO(*(pos++)));
        } catch (errors::error) {
            goto clean_SO;
        };
        if (pos == inp.end()) goto clean_X_XB;
        try {
            X_XB.push_back(form_X_XB(*(pos++)));
        } catch (errors::error) {
            goto clean_X_XB;
        }
        if (pos == inp.end()) goto clean;
        try {
            (DIM[j]).push_back(form_DIM(*(pos++)));
        } catch (errors::error) {
            goto clean;
        }
        for (i = 1; i < dim_num; i++) {
            if (pos == inp.end()) goto invalid;
            (DIM[j]).push_back(form_DIM(*(pos++)));
        }
        if (pos == inp.end()) goto end;
        NSM.push_back(form_NSM(*(pos++)));
    }

    goto end;

invalid:
    throw errors::parse_error("PBEAML", "Illegal number of entries.");
clean:
    X_XB.pop_back();
clean_X_XB:
    SO.pop_back();
clean_SO:
    DIM.pop_back();
end:;
}

types pbeaml::card_type() const {
    return types::PBEAML;
};

void pbeaml::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    throw std::not_implemented(__FILE__, __LINE__, "can't write PBEAML.");
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
