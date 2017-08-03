/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definitions for Sesam FEM cards.

   Detailed description
*/

#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const cID_fem_cards[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

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
using namespace fem;
using namespace cards;

namespace {
    void _stderr_report(std::string const &msg) {
        cerr << msg << endl;
    }

    void _stdout_report(std::string const &msg) {
        cout << msg << endl;
    }
}

void (*cards::note_report)(std::string const &) = &_stdout_report;
void (*cards::info_report)(std::string const &) = &_stderr_report;
void (*cards::warn_report)(std::string const &) = &_stderr_report;
void (*cards::error_report)(std::string const &) = &_stderr_report;

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
        {"GBOX", cards::types::GBOX},
        {"GCHAN", cards::types::GCHAN},
        {"GCHANR", cards::types::GCHANR},
        {"GDOBO", cards::types::GDOBO},
        {"GECC", cards::types::GECC},
        {"GECCEN", cards::types::GECCEN},
        {"GELTH", cards::types::GELTH},
        {"GIORH", cards::types::GIORH},
        {"GIORHR", cards::types::GIORHR},
        {"GLSEC", cards::types::GLSEC},
        {"GLSECR", cards::types::GLSECR},
        {"GPIPE", cards::types::GPIPE},
        {"GTONP", cards::types::GTONP},
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

std::ostream &operator<< (ostream &os, cards::types const cardtype) {
    switch (cardtype) {
    case cards::types::UNKNOWN: return os << "UNKNOWN";
    case cards::types::DATE: return os << "DATE";
    case cards::types::GCOORD: return os << "GCOORD";
    case cards::types::GNODE: return os << "GNODE";
    case cards::types::IDENT: return os << "IDENT";
    case cards::types::IEND: return os << "IEND";
    case cards::types::GELMNT1: return os << "GELMNT1";
    case cards::types::GELREF1: return os << "GELREF1";
    case cards::types::GBARM: return os << "GBARM";
    case cards::types::GBEAMG: return os << "GBEAMG";
    case cards::types::GECC: return os << "GECC";
    case cards::types::GECCEN: return os << "GECCEN";
    case cards::types::GELTH: return os << "GELTH";
    case cards::types::GBOX: return os << "GBOX";
    case cards::types::GCHAN: return os << "GCHAN";
    case cards::types::GCHANR: return os << "GCHANR";
    case cards::types::GDOBO: return os << "GDOBO";
    case cards::types::GIORH: return os << "GIORH";
    case cards::types::GIORHR: return os << "GIORHR";
    case cards::types::GLSEC: return os << "GLSEC";
    case cards::types::GLSECR: return os << "GLSECR";
    case cards::types::GPIPE: return os << "GPIPE";
    case cards::types::GTONP: return os << "GTONP";
    case cards::types::GUSYI: return os << "GUSYI";
    case cards::types::BELFIX: return os << "BELFIX";
    case cards::types::BLDEP: return os << "BLDEP";
    case cards::types::BNBCD: return os << "BNBCD";
    case cards::types::BNDISPL: return os << "BNDISPL";
    case cards::types::BNLOAD: return os << "BNLOAD";
    case cards::types::MGSPRNG: return os << "MGSPRNG";
    case cards::types::GSETMEMB: return os << "GSETMEMB";
    case cards::types::GUNIVEC: return os << "GUNIVEC";
    case cards::types::MISOSEL: return os << "MISOSEL";
    case cards::types::MORSMEL: return os << "MORSMEL";
    case cards::types::TDSETNAM: return os << "TDSETNAM";
    case cards::types::TDSUPNAM: return os << "TDSUPNAM";
    case cards::types::TEXT: return os << "TEXT";
    case cards::types::TDLOAD: return os << "TDLOAD";
    case cards::types::BSELL: return os << "BSELL";
    case cards::types::GELMNT2: return os << "GELMNT2";
    case cards::types::HSUPSTAT: return os << "HSUPSTAT";
    case cards::types::HSUPTRAN: return os << "HSUPTRAN";
    case cards::types::HIERARCH: return os << "HIERARCH";
    case cards::types::BEUSLO: return os << "BEUSLO";
    // omit default case to trigger compiler warning for missing cases
    }
    return os << static_cast<size_t>(cardtype);
}

fem::types::empty const cards::__base::card::empty = fem::types::empty();

fem::types::card const cards::__base::card::head = fem::types::card("<DUMMY>");

size_t cards::__base::card::card_split(
    vector<std::string> const &inp, size_t const ilen,
    vector<std::string> &res) {
    std::string static head(8, '\0');
    std::string static tmp(80, '\0');
    bool first = true;
    size_t olen{0};

    for (size_t i{0}; i < ilen; i++) {

        if (first) {
            head.assign(string::string(inp.at(i).substr(0, 8)).trim());
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
        for (size_t i1=0; i1<4; ++i1) {
            try {
                res.at(olen).assign(tmp.substr(i1*16, 16));
            } catch (out_of_range) {
                res.emplace_back(tmp.substr(i1*16, 16));
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
    material::read(inp, len);
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
                unique_ptr<__base::card> &res) {
    static std::string key("");

    try {
        key.assign(inp.front());
        switch (cardtype_map.at(key)) {
        case types::DATE:
            res = make_unique<date>(inp, len);
            break;
        case types::GCOORD:
            res = make_unique<gcoord>(inp, len);
            break;
        case types::GNODE:
            res = make_unique<gnode>(inp, len);
            break;
        case types::GBARM:
            res = make_unique<gbarm>(inp, len);
            break;
        case types::GBEAMG:
            res = make_unique<gbeamg>(inp, len);
            break;
        case types::GECC:
            res = make_unique<gecc>(inp, len);
            break;
        case types::GECCEN:
            res = make_unique<geccen>(inp, len);
            break;
        case types::GELTH:
            res = make_unique<gelth>(inp, len);
            break;
        case types::GBOX:
            res = make_unique<gbox>(inp, len);
            break;
        case types::GCHAN:
            res = make_unique<gchan>(inp, len);
            break;
        case types::GCHANR:
            res = make_unique<gchanr>(inp, len);
            break;
        case types::GDOBO:
            res = make_unique<gdobo>(inp, len);
            break;
        case types::GIORH:
            res = make_unique<giorh>(inp, len);
            break;
        case types::GIORHR:
            res = make_unique<giorhr>(inp, len);
            break;
        case types::GLSEC:
            res = make_unique<glsec>(inp, len);
            break;
        case types::GLSECR:
            res = make_unique<glsecr>(inp, len);
            break;
        case types::GPIPE:
            res = make_unique<gpipe>(inp, len);
            break;
        case types::GTONP:
            res = make_unique<gtonp>(inp, len);
            break;
        case types::GUSYI:
            res = make_unique<gusyi>(inp, len);
            break;
        case types::BELFIX:
            res = make_unique<belfix>(inp, len);
            break;
        case types::IDENT:
            res = make_unique<ident>(inp, len);
            break;
        case types::IEND:
            res = make_unique<iend>(inp, len);
            break;
        case types::GELMNT1:
            res = make_unique<gelmnt1>(inp, len);
            break;
        case types::GELREF1:
            res = make_unique<gelref1>(inp, len);
            break;
        case types::BLDEP:
            res = make_unique<bldep>(inp, len);
            break;
        case types::BNBCD:
            res = make_unique<bnbcd>(inp, len);
            break;
        case types::BNDISPL:
            res = make_unique<bndispl>(inp, len);
            break;
        case types::BNLOAD:
            res = make_unique<bnload>(inp, len);
            break;
        case types::MGSPRNG:
            res = make_unique<mgsprng>(inp, len);
            break;
        case types::GSETMEMB:
            res = make_unique<gsetmemb>(inp, len);
            break;
        case types::GUNIVEC:
            res = make_unique<gunivec>(inp, len);
            break;
        case types::MISOSEL:
            res = make_unique<misosel>(inp, len);
            break;
        case types::MORSMEL:
            res = make_unique<morsmel>(inp, len);
            break;
        case types::TEXT:
            res = make_unique<text>(inp, len);
            break;
        case types::TDSETNAM:
            res = make_unique<tdsetnam>(inp, len);
            break;
        case types::TDSUPNAM:
            res = make_unique<tdsupnam>(inp, len);
            break;
        case types::TDLOAD:
            res = make_unique<tdload>(inp, len);
            break;
        case types::BSELL:
            res = make_unique<bsell>(inp, len);
            break;
        case types::GELMNT2:
            res = make_unique<gelmnt2>(inp, len);
            break;
        case types::HSUPSTAT:
            res = make_unique<hsupstat>(inp, len);
            break;
        case types::HSUPTRAN:
            res = make_unique<hsuptran>(inp, len);
            break;
        case types::HIERARCH:
            res = make_unique<hierarch>(inp, len);
            break;
        case types::BEUSLO:
            res = make_unique<beuslo>(inp, len);
            break;
            // These are not real card types, they can't be returned
        case types::UNKNOWN:
            res = make_unique<unknown>(inp, len);
        }
    } catch (out_of_range) {
        res = make_unique<unknown>(inp, len);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
