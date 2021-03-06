/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Definitions for Nastran BDF LOAD cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_bdf_cards_load[]) =
        "@(#) $Id$";
}

#include <cassert>
#include <utility>

#include "bdf/cards.h"
#include "bdf/types.h"
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
using namespace rel_ops;

namespace {
    auto const cl1 = make_shared<long>(1);
}

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

using bdf::types::entry_type;
using bdf::types::entry_value;
using type_bounds::bound;

namespace {
    auto const bound_SID = make_shared<bound<long>>(cl1);
}
entry_type<long> load::form_SID("SID", bound_SID);
entry_type<double> load::form_S("S");
entry_type<double> load::form_Si("Si");
namespace {
    auto const bound_Li = make_shared<bound<long>>(cl1);
}
entry_type<long> load::form_Li("Li", bound_Li);

load::load(list<std::string> const &inp) : card(inp) {
    this->load::read(inp);
}

load::load(long const *SID, double const *S,
           vector<double> const *Si, vector<long> const *Li) :
        card(), SID(*SID), S(*S), Si(), Li() {
    if (Si)
        copy(Si->begin(), Si->end(), back_inserter(this->Si));
    if (Li)
        copy(Li->begin(), Li->end(), back_inserter(this->Li));
}

cards::__base::card const &load::operator() (
    long const *SID, double const *S,
    vector<double> const *Si, vector<long> const *Li) {

    this->Si.clear();
    this->Li.clear();

    this->SID = *SID;
    this->S = *S;
    if (Si)
        copy(Si->begin(), Si->end(), back_inserter(this->Si));
    if (Li)
        copy(Li->begin(), Li->end(), back_inserter(this->Li));
    return *this;
}

bdf::types::card load::head = bdf::types::card("LOAD");

cards::types load::card_type() const {
    return types::LOAD;
}

void load::read(list<std::string> const &inp) {
    auto pos = inp.begin();

    Si.clear();
    Li.clear();

    if (pos == inp.end()) goto invalid;
    ++pos;
    if (pos == inp.end()) goto invalid;
    form_SID.set_value(SID, *(pos++));
    if (pos == inp.end()) goto invalid;
    form_S.set_value(S, *(pos++));
    if (pos == inp.end()) goto invalid;
    while ((pos != inp.end()) && (*pos != "")) {
        Si.push_back(form_Si(*(pos++)));
        if (pos == inp.end()) goto invalid;
        Li.push_back(form_Li(*(pos++)));
    }
    goto end;

invalid:
    throw errors::parse_error("LOAD", "Illegal number of entries.");
end:;
}

void load::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {

    if (static_cast<long>(SID) <= 0) return;

    res.push_back(unique_ptr<format_entry>(format(head)));

    res.push_back(unique_ptr<format_entry>(format<long>(form_SID, SID)));
    res.push_back(unique_ptr<format_entry>(format<double>(form_S, S)));

    assert(Si.size() == Li.size());

    auto pS = Si.begin();
    for (auto pL = Li.begin(); pL != Li.end(); ++pL) {
        res.push_back(unique_ptr<format_entry>(format<double>(form_Si, &(*pS))));
        res.push_back(unique_ptr<format_entry>(format<long>(form_Li, &(*pL))));
        ++pS;
    }
    return;
}

void load::check_data() {
    if (SID) load::form_SID.check(SID);
    if (S) load::form_S.check(S);
    if (Si.size())
        for (auto pos : Si)
            load::form_Si.check(pos);
    if (Li.size())
        for (auto pos : Li)
            load::form_Li.check(pos);
}

cards::__base::card const &cards::load::operator() (
    list<std::string> const &inp) {
    this->load::read(inp);
    return *this;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//    (make -C ../../cbuild test ;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
