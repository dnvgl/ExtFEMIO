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

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

using bdf::types::entry_type;
using bdf::types::entry_value;

namespace {
    const double cd0 = 0., cd1 = 1.;
}

bdf::types::card pbeaml::head = bdf::types::card("PBEAML");

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

pbeaml::pbeaml(const list<std::string> &inp) :
beam_prop(inp) {
    this->pbeaml::read(inp);
}

pbeaml::pbeaml(long const *PID, long const *MID,
               std::string const *GROUP,
               std::string const *TYPE,
               vector<vector<double>> const *DIM,
               vector<double> const *NSM,
               vector<std::string> const *SO,
               vector<double> const *X_XB) :
        beam_prop(PID, MID), GROUP(*GROUP), TYPE(*TYPE) {
    this->DIM.resize(DIM->size());
    for (size_t i = 0; i < DIM->size(); i++) {
        this->DIM[i].resize((*DIM)[i].size(), entry_value<double>(nullptr));
        for (size_t j = 0; j < (*DIM)[i].size(); j++)
            this->DIM[i][j]((*DIM)[i][j]);
    }
    this->NSM.resize(NSM->size(), entry_value<double>(nullptr));
    for (size_t i = 0; i < NSM->size(); i++)
        this->NSM[i]((*NSM)[i]);
    this->SO.resize(SO->size(), entry_value<std::string>(nullptr));
    for (size_t i = 0; i < SO->size(); i++)
        this->SO[i]((*SO)[i]);
    this->X_XB.resize(X_XB->size(), entry_value<double>(nullptr));
    for (size_t i = 0; i < X_XB->size(); i++)
        this->X_XB[i]((*X_XB)[i]);
    this->beam_prop::check_data();
    this->pbeaml::check_data();
}

void pbeaml::read(list<std::string> const & inp) {

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
    dim_num = this->l_geom::get_dim(TYPE.value);
    if (dim_num < 1)
        throw errors::parse_error(
            "PBEAML", "Unknown beam type " + TYPE.value + ".");

    ++pos;
    for (i = 1; i < 4; i++) {
        if (pos == inp.end()) goto invalid;
        ++pos;
    }

    // DIM.push_back(new vector<dnvgl::extfem::bdf::double> >);
    DIM.push_back(vector<bdf::types::entry_value<double>>());
    for (i = 0; i < dim_num; i++) {
        if (pos == inp.end()) goto invalid;
        DIM.front().push_back(form_DIM(*(pos++)));
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
        // DIM.push_back(new vector<dnvgl::extfem::bdf::types::entry_value<double> >);
        DIM.push_back(vector<bdf::types::entry_value<double>>());
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
            DIM.back().push_back(form_DIM(*(pos++)));
        } catch (errors::error) {
            goto clean;
        }
        for (i = 1; i < dim_num; i++) {
            if (pos == inp.end()) goto invalid;
            DIM.back().push_back(form_DIM(*(pos++)));
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

cards::types pbeaml::card_type() const {
    return cards::types::PBEAML;
};

void pbeaml::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    if (!PID) return;

    auto pos_DIM(DIM.begin());
    auto pos_NSM(NSM.begin());
    auto pos_SO(SO.begin());
    auto pos_X_XB(X_XB.begin());

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID, MID)));

    res.push_back(unique_ptr<format_entry>(
                      bool(GROUP) ?
                      format<std::string>(form_GROUP, GROUP) :
                      format(empty)));
    res.push_back(unique_ptr<format_entry>(format<std::string>(form_TYPE, TYPE)));
    for (auto i = 0;i<4;i++ )
        res.push_back(unique_ptr<format_entry>(format(empty)));

    for (size_t i{0}; i < pos_DIM->size(); i++)
             res.push_back(unique_ptr<format_entry>(
                               format<double>(form_DIM, (*pos_DIM)[i])));
    pos_DIM++;
    int cnt{0};
    while (cnt < 13 &&
           (pos_DIM != DIM.end() || pos_NSM != NSM.end() ||
            pos_SO != SO.end() || pos_X_XB != X_XB.end())) {
        cnt++;
        res.push_back(unique_ptr<format_entry>(
                          pos_NSM != NSM.end() ?
                          format<double>(form_NSM, (*(pos_NSM++))) :
                          format(empty)));
        if (pos_DIM != DIM.end() || pos_NSM != NSM.end() ||
            pos_SO != SO.end() || pos_X_XB != X_XB.end()) {
            res.push_back(unique_ptr<format_entry>(
                              pos_SO != SO.end() ?
                              format<std::string>(form_SO, (*(pos_SO++))) :
                              format(empty)));
        }
        if (pos_DIM != DIM.end() || pos_NSM != NSM.end() ||
            pos_SO != SO.end() || pos_X_XB != X_XB.end()) {
            res.push_back(unique_ptr<format_entry>(
                              pos_X_XB != X_XB.end() ?
                              format<double>(form_X_XB, (*(pos_X_XB++))) :
                              format(empty)));
        }
    }
}

void pbeaml::check_data() const {
    this->beam_prop::check_data();
    size_t base_size{DIM.size()};
    size_t dim_num = this->l_geom::get_dim(TYPE.value);

    if (base_size < 1)
        throw errors::form_error("PBEAML", "requires at least one station");
    if (NSM.size() != base_size)
        throw errors::form_error("PBEAML", "wrong size for NSM");
    if (SO.size() != base_size - 1 && SO.size() != base_size)
        throw errors::form_error("PBEAML", "wrong size for SO");
    if (X_XB.size() != base_size - 1)
        throw errors::form_error("PBEAML", "wrong size for X/XB");
    if (GROUP) pbeaml::form_GROUP.check(GROUP);
    if (TYPE) pbeaml::form_TYPE.check(TYPE);
    for (auto pos : DIM) {
        if (pos.size() != dim_num)
            throw errors::form_error("PBEAML", "wrong number of dimension in DIM");
        for (auto ppos : pos)
            pbeaml::form_DIM.check(ppos);
    }
    if (NSM.size() > 0)
        for (auto pos : NSM)
            pbeaml::form_NSM.check(pos);
    if (SO.size() > 0)
        for (auto pos : SO)
            pbeaml::form_SO.check(pos);
    if (X_XB.size() > 0)
        for (auto pos : X_XB)
            pbeaml::form_X_XB.check(pos);
 }

cards::__base::card const &pbeaml::operator() (list<std::string> const &inp) {
    this->pbeaml::read(inp);
    return *this;
}

cards::__base::card const &pbeaml::operator() (
    long const *PID, long const *MID,
    std::string const *GROUP,
    std::string const *TYPE,
    vector<vector<double>> const *DIM,
    vector<double> const *NSM,
    vector<std::string> const *SO,
    vector<double> const *X_XB) {
    this->beam_prop::operator() (PID, MID);
    this->GROUP(GROUP);
    this->TYPE(TYPE);
    this->DIM.resize(DIM->size());
    for (size_t i = 0; i < DIM->size(); i++) {
        this->DIM[i].resize((*DIM)[i].size(), entry_value<double>(nullptr));
        for (size_t j = 0; j < (*DIM)[i].size(); j++)
            this->DIM[i][j]((*DIM)[i][j]);
    }
    this->NSM.resize(NSM->size(), entry_value<double>(nullptr));
    for (size_t i = 0; i < NSM->size(); i++)
        this->NSM[i]((*NSM)[i]);
    this->SO.resize(SO->size(), entry_value<std::string>(nullptr));
    for (size_t i = 0; i < SO->size(); i++)
        this->SO[i]((*SO)[i]);
    this->X_XB.resize(X_XB->size(), entry_value<double>(nullptr));
    for (size_t i = 0; i < X_XB->size(); i++)
        this->X_XB[i]((*X_XB)[i]);
    this->beam_prop::check_data();
    this->pbeaml::check_data();
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
// (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
