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
     //  char const initVals[3] = { '+', '*', ',' };

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

unordered_map<std::string, cards::types> const cardtype_map({
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

cards::__base::card::card() {}

cards::__base::card::~card(void) {}

fem::types::empty const cards::__base::card::empty = fem::types::empty();

fem::types::card const cards::__base::card::head = fem::types::card("<DUMMY>");

size_t cards::__base::card::card_split(
    vector<std::string> const &inp, size_t const ilen,
    vector<std::string> &res) {
    std::string static head(8, '\0');
    std::string static tmp(80, '\0');
    bool first = true;
    size_t olen{0};
    ;

    for (size_t i{0}; i < ilen; i++) {

        head.assign(extfem::string::string(inp.at(i).substr(0, 8)).trim());
        if (first) {
            first = false;
            try {
                res.at(olen).assign(string::string(head).trim("\t\n"));
            } catch (out_of_range) {
                res.emplace_back(string::string(head).trim("\t\n"));
            }
            ++olen;
        }
        tmp.assign(string::string(inp.at(i)).trim("\t\n"));
        tmp.resize(80, ' ');
        tmp.assign(tmp.substr(8));
        for (size_t i=0; i<4; ++i) {
            try {
                res.at(olen).assign(tmp.substr(i*16, 16));
            } catch (out_of_range) {
                res.emplace_back(tmp.substr(i*16, 16));
            }
            ++olen;
        }
    }
    return olen;
}

cards::__base::card const &cards::__base::card::operator() (
    vector<std::string> const &inp, size_t const len) {
    this->read(inp, len);
    return *this;
}

cards::__base::material::material(
    vector<std::string> const &inp, size_t const len) {
    read(inp, len);
}

cards::__base::material::material(long const MATNO) :
        card(), MATNO(MATNO) {}

fem::types::entry_type<long> const
cards::__base::material::_form_MATNO("MATNO");

void cards::__base::material::read(
    vector<std::string> const &inp, size_t const len) {
    if (len < 2)
        throw errors::parse_error(
            "material", "Illegal number of entries.");

    MATNO = _form_MATNO(inp.at(1));
}

cards::__base::card const &cards::__base::material::operator() (
    vector<std::string> const &inp, size_t const len) {
    material::read(inp, len);
    this->read(inp, len);
    return *this;
}

void
cards::dispatch(vector<std::string> const &inp, size_t const len,
                unique_ptr<cards::__base::card> &res) {
    static std::string key("");

    try {
        key.assign(inp.front());
        switch (cardtype_map.at(key)) {
        case cards::types::DATE:
            res = make_unique<fem::cards::date>(inp, len);
            break;
        case cards::types::GCOORD:
            res = make_unique<fem::cards::gcoord>(inp, len);
            break;
        case cards::types::GNODE:
            res = make_unique<fem::cards::gnode>(inp, len);
            break;
        case cards::types::GBARM:
            res = make_unique<fem::cards::gbarm>(inp, len);
            break;
        case cards::types::GBEAMG:
            res = make_unique<fem::cards::gbeamg>(inp, len);
            break;
        case cards::types::GECCEN:
            res = make_unique<fem::cards::geccen>(inp, len);
            break;
        case cards::types::GELTH:
            res = make_unique<fem::cards::gelth>(inp, len);
            break;
        case cards::types::GIORH:
            res = make_unique<fem::cards::giorh>(inp, len);
            break;
        case cards::types::GLSEC:
            res = make_unique<fem::cards::glsec>(inp, len);
            break;
        case cards::types::GPIPE:
            res = make_unique<fem::cards::gpipe>(inp, len);
            break;
        case cards::types::GUSYI:
            res = make_unique<fem::cards::gusyi>(inp, len);
            break;
        case cards::types::BELFIX:
            res = make_unique<fem::cards::belfix>(inp, len);
            break;
        case cards::types::IDENT:
            res = make_unique<fem::cards::ident>(inp, len);
            break;
        case cards::types::IEND:
            res = make_unique<fem::cards::iend>(inp, len);
            break;
        case cards::types::GELMNT1:
            res = make_unique<fem::cards::gelmnt1>(inp, len);
            break;
        case cards::types::GELREF1:
            res = make_unique<fem::cards::gelref1>(inp, len);
            break;
        case cards::types::BLDEP:
            res = make_unique<fem::cards::bldep>(inp, len);
            break;
        case cards::types::BNBCD:
            res = make_unique<fem::cards::bnbcd>(inp, len);
            break;
        case cards::types::BNDISPL:
            res = make_unique<fem::cards::bndispl>(inp, len);
            break;
        case cards::types::BNLOAD:
            res = make_unique<fem::cards::bnload>(inp, len);
            break;
        case cards::types::MGSPRNG:
            res = make_unique<fem::cards::mgsprng>(inp, len);
            break;
        case cards::types::GSETMEMB:
            res = make_unique<fem::cards::gsetmemb>(inp, len);
            break;
        case cards::types::GUNIVEC:
            res = make_unique<fem::cards::gunivec>(inp, len);
            break;
        case cards::types::MISOSEL:
            res = make_unique<fem::cards::misosel>(inp, len);
            break;
        case cards::types::MORSMEL:
            res = make_unique<fem::cards::morsmel>(inp, len);
            break;
        case cards::types::TEXT:
            res = make_unique<fem::cards::text>(inp, len);
            break;
        case cards::types::TDSETNAM:
            res = make_unique<fem::cards::tdsetnam>(inp, len);
            break;
        case cards::types::TDSUPNAM:
            res = make_unique<fem::cards::tdsupnam>(inp, len);
            break;
        case cards::types::TDLOAD:
            res = make_unique<fem::cards::tdload>(inp, len);
            break;
        case cards::types::BSELL:
            res = make_unique<fem::cards::bsell>(inp, len);
            break;
        case cards::types::GELMNT2:
            res = make_unique<fem::cards::gelmnt2>(inp, len);
            break;
        case cards::types::HSUPSTAT:
            res = make_unique<fem::cards::hsupstat>(inp, len);
            break;
        case cards::types::HSUPTRAN:
            res = make_unique<fem::cards::hsuptran>(inp, len);
            break;
        case cards::types::HIERARCH:
            res = make_unique<fem::cards::hierarch>(inp, len);
            break;
        case cards::types::BEUSLO:
            res = make_unique<fem::cards::beuslo>(inp, len);
            break;
            // These are not real card types, they can't be returned
        case cards::types::UNKNOWN:
            res = make_unique<fem::cards::unknown>(inp, len);
        }
    } catch (out_of_range) {
        res = make_unique<fem::cards::unknown>(inp, len);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
