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
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_cards[]) =
        "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/errors.h"
#include "extfem_string.h"

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

namespace {
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
            {"BEUSLO", cards::types::BEUSLO},
            {"TDMATER", cards::types::TDMATER},
            {"TDSECT", cards::types::TDSECT},
            {"TSLAYER", cards::types::TSLAYER},
            {"ACFD", cards::types::ACFD},
            {"ADDATA", cards::types::ADDATA},
            {"BEISTE", cards::types::BEISTE},
            {"BELLAX", cards::types::BELLAX},
            {"BELLO2", cards::types::BELLO2},
            {"BELOAD1", cards::types::BELOAD1},
            {"BEDRAG1", cards::types::BEDRAG1},
            {"BEMASS1", cards::types::BEMASS1},
            {"BEUVLO", cards::types::BEUVLO},
            {"BEWAKIN", cards::types::BEWAKIN},
            {"BEWALO1", cards::types::BEWALO1},
            {"BGRAV", cards::types::BGRAV},
            {"BNACCLO", cards::types::BNACCLO},
            {"BNDOF", cards::types::BNDOF},
            {"BNINCO", cards::types::BNINCO},
            {"BNLOAX", cards::types::BNLOAX},
            {"BNMASS", cards::types::BNMASS},
            {"BNTEMP", cards::types::BNTEMP},
            {"BNTRCOS", cards::types::BNTRCOS},
            {"BNWALO", cards::types::BNWALO},
            {"BRIGAC", cards::types::BRIGAC},
            {"BRIGDI", cards::types::BRIGDI},
            {"BRIGVE", cards::types::BRIGVE},
            {"BQDP", cards::types::BQDP},
            {"GCROINT", cards::types::GCROINT},
            {"GELINT", cards::types::GELINT},
            {"GELSTRP", cards::types::GELSTRP},
            {"GLMASS", cards::types::GLMASS},
            {"GSEPxxxx", cards::types::GSEPxxxx},
            {"GSEPSPEC", cards::types::GSEPSPEC},
            {"GSLAYER", cards::types::GSLAYER},
            {"GSLxxxxx", cards::types::GSLxxxxx},
            {"GSLPLATE", cards::types::GSLPLATE},
            {"GSLSTIFF", cards::types::GSLSTIFF},
            {"MAXDMP", cards::types::MAXDMP},
            {"MAXSPR", cards::types::MAXSPR},
            {"MCNT", cards::types::MCNT},
            {"MGDAMP", cards::types::MGDAMP},
            {"MGLDAMP", cards::types::MGLDAMP},
            {"MGLMASS", cards::types::MGLMASS},
            {"MGMASS", cards::types::MGMASS},
            {"MISOAL", cards::types::MISOAL},
            {"MISOEML", cards::types::MISOEML},
            {"MISOHL", cards::types::MISOHL},
            {"MISOHNL", cards::types::MISOHNL},
            {"MISOPL", cards::types::MISOPL},
            {"MISTEL", cards::types::MISTEL},
            {"MORSSEL", cards::types::MORSSEL},
            {"MORSSOL", cards::types::MORSSOL},
            {"MSHGLSP", cards::types::MSHGLSP},
            {"MTEMP", cards::types::MTEMP},
            {"MTENONL", cards::types::MTENONL},
            {"MTRMEL", cards::types::MTRMEL},
            {"MTRSEL", cards::types::MTRSEL},
            {"MTRSOL", cards::types::MTRSOL},
            {"AMATRIX", cards::types::AMATRIX},
            {"AMDACCL", cards::types::AMDACCL},
            {"AMDDAMP", cards::types::AMDDAMP},
            {"AMDDISP", cards::types::AMDDISP},
            {"AMDFREQ", cards::types::AMDFREQ},
            {"AMDLOAD", cards::types::AMDLOAD},
            {"AMDMASS", cards::types::AMDMASS},
            {"AMDSTIFF", cards::types::AMDSTIFF},
            {"AMDVELO", cards::types::AMDVELO},
            /// Undocumented cards (from failed imports)
            {"TDSCONC", cards::types::TDSCONC},
            {"SCONCEPT", cards::types::SCONCEPT},
            {"SCONMESH", cards::types::SCONMESH},
            {"UNITS", cards::types::UNITS}});
}

cards::__base::card::card(types const this_type) : this_type(this_type) {}

cards::__base::card::card(std::vector<std::string> const &inp, size_t const len) :
        card(types::UNKNOWN) {
    if (len>0) {
        std::string const name{inp[0]};
        __base::card::this_type = cardtype_map.at(name);
    }
}

void cards::__base::card::read(vector<std::string> const &inp, size_t const len) {
    if (len>0) {
        try {
            this_type = cardtype_map.at(inp[0]);
        } catch (out_of_range) {
            this_type = types::UNKNOWN;
        }
    }
}

std::ostream &cards::__base::card::put(std::ostream &os) const {
    ostringstream type_s(ostringstream::ate);
    type_s << this_type;
    fem::types::card const head(type_s.str());
    os << head.format()
       << "NOT YET SUPPORTED" << endl;
    return os;
}

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
    case cards::types::TDMATER: return os << "TDMATER";
    case cards::types::TDSECT: return os << "TDSECT";
    case cards::types::TSLAYER: return os << "TSLAYER";
    case cards::types::ACFD: return os << "ACFD";
    case cards::types::ADDATA: return os << "ADDATA";
    case cards::types::BEISTE: return os << "BEISTE";
    case cards::types::BELLAX: return os << "BELLAX";
    case cards::types::BELLO2: return os << "BELLO2";
    case cards::types::BELOAD1: return os << "BELOAD1";
    case cards::types::BEDRAG1: return os << "BEDRAG1";
    case cards::types::BEMASS1: return os << "BEMASS1";
    case cards::types::BEUVLO: return os << "BEUVLO";
    case cards::types::BEWAKIN: return os << "BEWAKIN";
    case cards::types::BEWALO1: return os << "BEWALO1";
    case cards::types::BGRAV: return os << "BGRAV";
    case cards::types::BNACCLO: return os << "BNACCLO";
    case cards::types::BNDOF: return os << "BNDOF";
    case cards::types::BNINCO: return os << "BNINCO";
    case cards::types::BNLOAX: return os << "BNLOAX";
    case cards::types::BNMASS: return os << "BNMASS";
    case cards::types::BNTEMP: return os << "BNTEMP";
    case cards::types::BNTRCOS: return os << "BNTRCOS";
    case cards::types::BNWALO: return os << "BNWALO";
    case cards::types::BRIGAC: return os << "BRIGAC";
    case cards::types::BRIGDI: return os << "BRIGDI";
    case cards::types::BRIGVE: return os << "BRIGVE";
    case cards::types::BQDP: return os << "BQDP";
    case cards::types::GCROINT: return os << "GCROINT";
    case cards::types::GELINT: return os << "GELINT";
    case cards::types::GELSTRP: return os << "GELSTRP";
    case cards::types::GLMASS: return os << "GLMASS";
    case cards::types::GSEPxxxx: return os << "GSEPxxxx";
    case cards::types::GSEPSPEC: return os << "GSEPSPEC";
    case cards::types::GSLAYER: return os << "GSLAYER";
    case cards::types::GSLxxxxx: return os << "GSLxxxxx";
    case cards::types::GSLPLATE: return os << "GSLPLATE";
    case cards::types::GSLSTIFF: return os << "GSLSTIFF";
    case cards::types::MAXDMP: return os << "MAXDMP";
    case cards::types::MAXSPR: return os << "MAXSPR";
    case cards::types::MCNT: return os << "MCNT";
    case cards::types::MGDAMP: return os << "MGDAMP";
    case cards::types::MGLDAMP: return os << "MGLDAMP";
    case cards::types::MGLMASS: return os << "MGLMASS";
    case cards::types::MGMASS: return os << "MGMASS";
    case cards::types::MISOAL: return os << "MISOAL";
    case cards::types::MISOEML: return os << "MISOEML";
    case cards::types::MISOHL: return os << "MISOHL";
    case cards::types::MISOHNL: return os << "MISOHNL";
    case cards::types::MISOPL: return os << "MISOPL";
    case cards::types::MISTEL: return os << "MISTEL";
    case cards::types::MORSSEL: return os << "MORSSEL";
    case cards::types::MORSSOL: return os << "MORSSOL";
    case cards::types::MSHGLSP: return os << "MSHGLSP";
    case cards::types::MTEMP: return os << "MTEMP";
    case cards::types::MTENONL: return os << "MTENONL";
    case cards::types::MTRMEL: return os << "MTRMEL";
    case cards::types::MTRSEL: return os << "MTRSEL";
    case cards::types::MTRSOL: return os << "MTRSOL";
    case cards::types::AMATRIX: return os << "AMATRIX";
    case cards::types::AMDACCL: return os << "AMDACCL";
    case cards::types::AMDDAMP: return os << "AMDDAMP";
    case cards::types::AMDDISP: return os << "AMDDISP";
    case cards::types::AMDFREQ: return os << "AMDFREQ";
    case cards::types::AMDLOAD: return os << "AMDLOAD";
    case cards::types::AMDMASS: return os << "AMDMASS";
    case cards::types::AMDSTIFF: return os << "AMDSTIFF";
    case cards::types::AMDVELO: return os << "AMDVELO";
    case cards::types::TDSCONC: return os << "TDSCONC";
    case cards::types::SCONCEPT: return os << "SCONCEPT";
    case cards::types::SCONMESH: return os << "SCONMESH";
    case cards::types::UNITS: return os << "UNITS";

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
    vector<std::string> const &inp, size_t const len) :
        card(types::UNKNOWN) {
    material::read(inp, len);
}

cards::__base::material::material(long const MATNO) :
        card(types::UNKNOWN), MATNO(MATNO) {}

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

cards::types cards::__base::card::card_type() {
    return this_type;
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
        case types::TDMATER:
        case types::TDSECT:
        case types::TSLAYER:
        case types::ACFD:
        case types::ADDATA:
        case types::BEISTE:
        case types::BELLAX:
        case types::BELLO2:
        case types::BELOAD1:
        case types::BEDRAG1:
        case types::BEMASS1:
        case types::BEUVLO:
        case types::BEWAKIN:
        case types::BEWALO1:
        case types::BGRAV:
        case types::BNACCLO:
        case types::BNDOF:
        case types::BNINCO:
        case types::BNLOAX:
        case types::BNMASS:
        case types::BNTEMP:
        case types::BNTRCOS:
        case types::BNWALO:
        case types::BRIGAC:
        case types::BRIGDI:
        case types::BRIGVE:
        case types::BQDP:
        case types::GCROINT:
        case types::GELINT:
        case types::GELSTRP:
        case types::GLMASS:
        case types::GSEPxxxx:
        case types::GSEPSPEC:
        case types::GSLAYER:
        case types::GSLxxxxx:
        case types::GSLPLATE:
        case types::GSLSTIFF:
        case types::MAXDMP:
        case types::MAXSPR:
        case types::MCNT:
        case types::MGDAMP:
        case types::MGLDAMP:
        case types::MGLMASS:
        case types::MGMASS:
        case types::MISOAL:
        case types::MISOEML:
        case types::MISOHL:
        case types::MISOHNL:
        case types::MISOPL:
        case types::MISTEL:
        case types::MORSSEL:
        case types::MORSSOL:
        case types::MSHGLSP:
        case types::MTEMP:
        case types::MTENONL:
        case types::MTRMEL:
        case types::MTRSEL:
        case types::MTRSOL:
        case types::AMATRIX:
        case types::AMDACCL:
        case types::AMDDAMP:
        case types::AMDDISP:
        case types::AMDFREQ:
        case types::AMDLOAD:
        case types::AMDMASS:
        case types::AMDSTIFF:
        case types::AMDVELO:
        case types::TDSCONC:
        case types::SCONCEPT:
        case types::SCONMESH:
        case types::UNITS:
        case types::UNKNOWN:
            res = make_unique<__base::card>(inp, len);
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
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_fem_cards --use-colour no)"
// End:
