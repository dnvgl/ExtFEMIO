/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF PBARL cards.

   Detailed description
   */
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    const char _EXTFEMIO_UNUSED(cID_bdf_cards_pbarl[]) =
        "@(#) $Id$";
}

#include <memory>

#include "bdf/cards.h"
#include "bdf/errors.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;
using bdf::types::entry_type;
using bdf::type_bounds::bound;

namespace {
    auto const cd0 = make_shared<double>(0.);
}

bdf::types::card pbarl::head = bdf::types::card("PBARL");

namespace {
    auto const name = make_shared<std::string>("MSCBML0");
    auto const bound_GROUP = make_shared<bound<std::string>>(
        nullptr, nullptr, name);
}
entry_type<std::string> pbarl::form_GROUP("GROUP", bound_GROUP);
namespace {
    set<std::string> const allowed({"T", "TW", "I", "L", "ROD", "TUBE",
                "CHAN", "BOX", "BAR", "CROSS", "H", "T1", "I1",
                "CHAN1", "Z", "CHAN2", "T2", "BOX1", "HEXA", "HAT",
                "HAT1", "DBOX"});
    auto const bound_TYPE = make_shared<bound<std::string>>(allowed);
}
entry_type<std::string> pbarl::form_TYPE("TYPE", bound_TYPE);
namespace {
    auto const bound_DIM = make_shared<bound<double>>(cd0);
}
entry_type<double> pbarl::form_DIM("DIM", bound_DIM);
namespace {
    auto const bound_NSM = make_shared<bound<double>>(nullptr, nullptr, cd0);
}
entry_type<double> pbarl::form_NSM("NSM", bound_NSM);

pbarl::pbarl(list<std::string> const &inp) :
bar_prop(inp) {
    this->pbarl::read(inp);
}

pbarl::pbarl(long const *PID, long const *MID,
             std::string const *GROUP, std::string const *TYPE,
             std::vector<double> const *DIM,
             double const *NSM/*=nullptr*/) :
        bar_prop(PID, MID), GROUP(GROUP), TYPE(TYPE), NSM(NSM) {
    this->DIM.assign(DIM->begin(), DIM->end()),
    this->pbarl::check_data();
}

void pbarl::read(list<std::string> const &inp) {

    size_t i;
    // ReSharper disable once CppJoinDeclarationAndAssignment
    size_t dim_num;

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
    // ReSharper disable once CppJoinDeclarationAndAssignment
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

cards::types pbarl::card_type() const {
    return types::PBARL;
};

void pbarl::collect_outdata(
    list<std::unique_ptr<format_entry> > &res) const {
    if (!PID) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_PID, PID)));
    res.push_back(unique_ptr<format_entry>(format<long>(form_MID, MID)));

    res.push_back(
        unique_ptr<format_entry>(
            bool(GROUP) ?
            format<std::string>(form_GROUP, GROUP) :
            format(empty)));
    res.push_back(unique_ptr<format_entry>(format<std::string>(form_TYPE, TYPE)));
    for (auto i = 0;i<4;i++ )
        res.push_back(unique_ptr<format_entry>(format(empty)));
    for (auto &pos : DIM)
        res.push_back(unique_ptr<format_entry>(
                          format<double>(form_DIM, pos)));
    if (bool(NSM))
        res.push_back(
            unique_ptr<format_entry>(
                format<double>(form_NSM, NSM)));
}

bdf::cards::__base::card const &pbarl::operator()(list<std::string> const &inp) {
    this->pbarl::read(inp);
    return *this;
}

bdf::cards::__base::card const &pbarl::operator() (
    long const *PID, long const *MID,
    std::string const *GROUP, std::string  const *TYPE,
    vector<double> const *DIM, double const *NSM/*=nullptr*/) {
    this->bar_prop::operator() (PID, MID);
    this->GROUP(GROUP);
    this->TYPE(TYPE);
    this->DIM.assign(DIM->begin(), DIM->end());
    this->NSM(NSM);
    this->pbarl::check_data();
    return *this;
}

void pbarl::check_data() {
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
