/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Processing Sesam FEM `BSELL` cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards_bsell[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/types.h"

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
using namespace fem;
using namespace types;
using namespace cards;

card const bsell::head("BSELL");

entry_type<long> const bsell::_form_LC("LC");
entry_type<long> const bsell::_form_SUBNO("SUBNO");
entry_type<long> const bsell::_form_LLC("LLC");
entry_type<double> const bsell::_form_FACT("FACT");

bsell::bsell(vector<std::string> const &inp, size_t const len) :
    card(types::BSELL) {
    bsell::read(inp, len);
}

void bsell::read(vector<std::string> const &inp, size_t const len) {
    static const std::string empty(16, ' ');

    if (len < 7)
        throw errors::parse_error(
            "BSELL", "Illegal number of entries.");

    LC = _form_LC(inp.at(1));
    SUBNO = _form_SUBNO(inp.at(2));

    for (size_t i{5}; i < len; i += 2) {
        if (inp.at(i) == empty) break;
        long tmp{_form_LLC(inp.at(i))};
        if (tmp == 0) break;
        LLC.push_back(tmp);
        FACT.push_back(_form_FACT(inp.at(i + 1)));
    }
}

bsell::bsell() :
        bsell(-1, 0, {}, {}) {}

bsell::bsell(
    long const LC, long const SUBNO, vector<long> const &LLC,
    vector<double> const &FACT) :
        card(types::BSELL), LC(LC), SUBNO(SUBNO), LLC(LLC), FACT(FACT) {}

cards::__base::card const &bsell::operator()(
    long const LC, long const SUBNO, vector<long> const &LLC,
    vector<double> const &FACT) {
    this->LC = LC;
    this->SUBNO = SUBNO;
    this->LLC = LLC;
    this->FACT = FACT;
    return *this;
}

ostream &bsell::put(ostream& os) const {
    if (LC == -1) return os;
    os << head.format()
       << _form_LC.format(LC) << _form_SUBNO.format(SUBNO)
       << empty.format() << empty.format() << endl;
    for (size_t i{0}; i < LLC.size(); i += 2) {
        os << fem::types::card().format()
           << _form_LLC.format(LLC.at(i)) << _form_FACT.format(FACT.at(i));
        if (i+1 < LLC.size())
            os << _form_LLC.format(LLC.at(i+1))
               << _form_FACT.format(FACT.at(i+1));
        os << endl;
    }
    return os;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
