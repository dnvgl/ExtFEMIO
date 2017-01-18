/**
   \file fem/fem_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definitions for Sesam FEM cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
    char const cID_fem_cards[]
#ifdef __GNUC__
    __attribute__ ((__unused__))
#endif
        = "@(#) $Id$";
}

#include <limits>

#include "fem/cards.h"
#include "fem/errors.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
char static THIS_FILE[] = __FILE__;
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace dnvgl::extfem::fem;
using namespace dnvgl::extfem::fem::cards;

namespace {
    char const initVals[3] = { '+', '*', ',' };

    void const _stderr_report(std::string const &msg) {
        cerr << msg << endl;
    }

    void const _stdout_report(std::string const &msg) {
        cout << msg << endl;
    }
}

void const (*cards::note_report)(std::string const &) = &_stdout_report;
void const (*cards::info_report)(std::string const &) = &_stderr_report;
void const (*cards::warn_report)(std::string const &) = &_stderr_report;
void const (*cards::error_report)(std::string const &) = &_stderr_report;

unknown::unknown(list<std::string> const &inp) :
        cards::__base::card(inp), content(inp) {};

cards::types const
unknown::card_type(void) const { return cards::types::UNKNOWN; }

ostream &unknown::put(ostream &os) const {
    throw errors::error("can't write UNKNOWN.");
    return os;
}

map<std::string, cards::types> const cardtype_map({
        // UNKNOWN,
        {"DATE", cards::types::DATE},
        {"GCOORD", cards::types::GCOORD},
        {"GNODE", cards::types::GNODE},
        {"IDENT", cards::types::IDENT},
        {"IEND", cards::types::IEND},
        {"GELMNT1", cards::types::GELMNT1},
        {"GELREF1", cards::types::GELREF1},
        {"GBARM", cards::types::GBARM},
        {"GBEAMG", cards::types::GBEAMG},
        {"GECCEN", cards::types::GECCEN},
        {"GELTH", cards::types::GELTH},
        {"GIORH", cards::types::GIORH},
        {"GLSEC", cards::types::GLSEC},
        {"GPIPE", cards::types::GPIPE},
        {"GUSYI", cards::types::GUSYI},
        {"BELFIX", cards::types::BELFIX},
        {"BLDEP", cards::types::BLDEP},
        {"BNBCD", cards::types::BNBCD},
        {"BNDISPL", cards::types::BNDISPL},
        {"BNLOAD", cards::types::BNLOAD},
        {"MGSPRNG", cards::types::MGSPRNG},
        {"GSETMEMB", cards::types::GSETMEMB},
        {"GUNIVEC", cards::types::GUNIVEC},
        {"MISOSEL", cards::types::MISOSEL},
        {"MORSMEL", cards::types::MORSMEL},
        {"TDSETNAM", cards::types::TDSETNAM},
        {"TDSUPNAM", cards::types::TDSUPNAM},
        {"TEXT", cards::types::TEXT},
        {"TDLOAD", cards::types::TDLOAD},
        {"BSELL", cards::types::BSELL},
        {"GELMNT2", cards::types::GELMNT2},
        {"HSUPSTAT", cards::types::HSUPSTAT},
        {"HSUPTRAN", cards::types::HSUPTRAN},
        {"HIERARCH", cards::types::HIERARCH},
        {"BEUSLO", cards::types::BEUSLO}});

cards::__base::card::card(list<std::string> const &inp) {}

cards::__base::card::card() {}

cards::__base::card::~card(void) {}

fem::types::empty const cards::__base::card::empty = fem::types::empty();

fem::types::card const cards::__base::card::head = fem::types::card("<DUMMY>");

void cards::__base::card::card_split(
    list<std::string> const &inp, list<std::string> &res) {
    std::string head;

    bool first = true;

    res.clear();

    for (auto &pos : inp) {
        head = extfem::string::string(pos.substr(0, 8)).trim();
        if (first)
            res.push_back(string::string(head).trim("\t\n"));
        std::string tmp(string::string(pos).trim("\t\n"));
        tmp.resize(80, ' ');
        tmp = tmp.substr(8);
        for (int i=0; i<4; ++i)
            res.push_back(tmp.substr(i*16, 16));
        first = false;
    }
}

fem::types::entry_type<long> const
cards::__base::geoprop::_form_GEONO("GEONO");

set<long> cards::__base::geoprop::used_geono;
long cards::__base::geoprop::geono_maxset = 0;

void cards::__base::geoprop::set_geono(long const &GEONO/*=0*/) {
    if (GEONO < 0) {
        this->GEONO = GEONO;
        return;
    }
    if (GEONO == 0) {
        for (long i = geono_maxset + 1; i < numeric_limits<long>::max(); i++) {
            if (!used_geono.count(i)) {
                geono_maxset = i;
                used_geono.insert(GEONO);
                this->GEONO = i;
                return;
            }
        }
    }
    if (used_geono.count(GEONO)) {
        ostringstream msg("GEONO ", ostringstream::ate);
        msg << GEONO << " value used twice.";
            throw errors::usage_error("GEONO", msg.str());
    }
    used_geono.insert(GEONO);
    this->GEONO = GEONO;
}

cards::__base::geoprop::geoprop(void) :
        card(), GEONO(-1) {}

cards::__base::geoprop::geoprop(long const &GEONO) :
        card() {
    set_geono(GEONO);
}

cards::__base::geoprop::geoprop(list<std::string> const &inp) :
        card(inp) {
    auto pos = inp.begin();
    set_geono(_form_GEONO(*(++pos)));
}

void cards::__base::geoprop::reset_geono(void) {
    geono_maxset = 0;
    used_geono.clear();
}


cards::__base::beam_prop::beam_prop(list<std::string> const &inp) :
        geoprop(inp) {}

cards::__base::beam_prop::beam_prop() :
        geoprop() {}

cards::__base::beam_prop::beam_prop(long const &GEONO) :
        geoprop(GEONO) {}

cards::__base::material::material(list<std::string> const &inp) :
        card(inp) {}

cards::__base::material::material() :
        __base::material(-1) {}

cards::__base::material::material(long const &MATNO) :
        card(), MATNO(MATNO) {}

fem::types::entry_type<long> const
cards::__base::material::_form_MATNO("MATNO");

void
cards::dispatch(list<std::string> const &inp,
                unique_ptr<cards::__base::card> &res) {

    try {
        std::string key(inp.front());
        switch (cardtype_map.at(key)) {
        case cards::types::DATE:
            res = make_unique<fem::cards::date>(inp);
            break;
        case cards::types::GCOORD:
            res = make_unique<fem::cards::gcoord>(inp);
            break;
        case cards::types::GNODE:
            res = make_unique<fem::cards::gnode>(inp);
            break;
        case cards::types::GBARM:
            res = make_unique<fem::cards::gbarm>(inp);
            break;
        case cards::types::GBEAMG:
            res = make_unique<fem::cards::gbeamg>(inp);
            break;
        case cards::types::GECCEN:
            res = make_unique<fem::cards::geccen>(inp);
            break;
        case cards::types::GELTH:
            res = make_unique<fem::cards::gelth>(inp);
            break;
        case cards::types::GIORH:
            res = make_unique<fem::cards::giorh>(inp);
            break;
        case cards::types::GLSEC:
            res = make_unique<fem::cards::glsec>(inp);
            break;
        case cards::types::GPIPE:
            res = make_unique<fem::cards::gpipe>(inp);
            break;
        case cards::types::GUSYI:
            res = make_unique<fem::cards::gusyi>(inp);
            break;
        case cards::types::BELFIX:
            res = make_unique<fem::cards::belfix>(inp);
            break;
        case cards::types::IDENT:
            res = make_unique<fem::cards::ident>(inp);
            break;
        case cards::types::IEND:
            res = make_unique<fem::cards::iend>(inp);
            break;
        case cards::types::GELMNT1:
            res = make_unique<fem::cards::gelmnt1>(inp);
            break;
        case cards::types::GELREF1:
            res = make_unique<fem::cards::gelref1>(inp);
            break;
        case cards::types::BLDEP:
            res = make_unique<fem::cards::bldep>(inp);
            break;
        case cards::types::BNBCD:
            res = make_unique<fem::cards::bnbcd>(inp);
            break;
        case cards::types::BNDISPL:
            res = make_unique<fem::cards::bndispl>(inp);
            break;
        case cards::types::BNLOAD:
            res = make_unique<fem::cards::bnload>(inp);
            break;
        case cards::types::MGSPRNG:
            res = make_unique<fem::cards::mgsprng>(inp);
            break;
        case cards::types::GSETMEMB:
            res = make_unique<fem::cards::gsetmemb>(inp);
            break;
        case cards::types::GUNIVEC:
            res = make_unique<fem::cards::gunivec>(inp);
            break;
        case cards::types::MISOSEL:
            res = make_unique<fem::cards::misosel>(inp);
            break;
        case cards::types::MORSMEL:
            res = make_unique<fem::cards::morsmel>(inp);
            break;
        case cards::types::TEXT:
            res = make_unique<fem::cards::text>(inp);
            break;
        case cards::types::TDSETNAM:
            res = make_unique<fem::cards::tdsetnam>(inp);
            break;
        case cards::types::TDSUPNAM:
            res = make_unique<fem::cards::tdsupnam>(inp);
            break;
        case cards::types::TDLOAD:
            res = make_unique<fem::cards::tdload>(inp);
            break;
        case cards::types::BSELL:
            res = make_unique<fem::cards::bsell>(inp);
            break;
        case cards::types::GELMNT2:
            res = make_unique<fem::cards::gelmnt2>(inp);
            break;
        case cards::types::HSUPSTAT:
            res = make_unique<fem::cards::hsupstat>(inp);
            break;
        case cards::types::HSUPTRAN:
            res = make_unique<fem::cards::hsuptran>(inp);
            break;
        case cards::types::HIERARCH:
            res = make_unique<fem::cards::hierarch>(inp);
            break;
        case cards::types::BEUSLO:
            res = make_unique<fem::cards::beuslo>(inp);
            break;
            // These are not real card types, they can't be returned
        case cards::types::UNKNOWN:
            res = make_unique<fem::cards::unknown>(inp);
        }
    } catch (out_of_range) {
        res = make_unique<fem::cards::unknown>(inp);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
