/**
   \file bdf/bdf_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definition for Nastran BDF cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"
#include "bdf/cards_elements.h"
#include "bdf/cards_loads.h"

// ID:
namespace {
    char const cID_bdf_cards[] _EXTFEMIO_UNUSED =
        "@(#) $Id$";
}

#include <string>
#include <iostream>

#include "bdf/cards.h"
#include "bdf/errors.h"
#include "extfem_string.h"

#if defined(__AFX_H__) && defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

namespace {
    void _stderr_report(std::string const &msg) {
        std::cerr << msg << std::endl;
    }

    void _stdout_report(std::string const &msg) {
        std::cout << msg << std::endl;
    }

    std::map<std::string, cards::types> const cardtype_map({
        {"GRID", cards::types::GRID},
        {"MAT1", cards::types::MAT1},
        {"CTRIA3", cards::types::CTRIA3},
        {"CQUAD4", cards::types::CQUAD4},
        {"PSHELL", cards::types::PSHELL},
        {"CBEAM", cards::types::CBEAM},
        {"PBEAM", cards::types::PBEAM},
        {"PBEAML", cards::types::PBEAML},
        {"CBAR", cards::types::CBAR},
        {"PBAR", cards::types::PBAR},
        {"PBARL", cards::types::PBARL},
        {"CROD", cards::types::CROD},
        {"PROD", cards::types::PROD},
        {"ENDDATA", cards::types::ENDDATA},
        {"MAT2", cards::types::MAT2},
        {"FORCE", cards::types::FORCE},
        {"MOMENT", cards::types::MOMENT},
        {"CMASS2", cards::types::CMASS2},
        {"CMASS4", cards::types::CMASS4},
        {"GRAV", cards::types::GRAV},
        {"LOAD", cards::types::LOAD},
        {"CAABSF", cards::types::CAABSF},
        {"CAERO1", cards::types::CAERO1},
        {"CAERO2", cards::types::CAERO2},
        {"CAERO3", cards::types::CAERO3},
        {"CAERO4", cards::types::CAERO4},
        {"CAERO5", cards::types::CAERO5},
        {"CAXIF2", cards::types::CAXIF2},
        {"CAXIF3", cards::types::CAXIF3},
        {"CAXIF4", cards::types::CAXIF4},
        {"CAXIFi", cards::types::CAXIFi},
        {"CBEND", cards::types::CBEND},
        {"CBUSH1D", cards::types::CBUSH1D},
        {"CBUSH", cards::types::CBUSH},
        {"CBUTT", cards::types::CBUTT},
        {"CCONEAX", cards::types::CCONEAX},
        {"CCRSFIL", cards::types::CCRSFIL},
        {"CDAMP1", cards::types::CDAMP1},
        {"CDAMP1D", cards::types::CDAMP1D},
        {"CDAMP2", cards::types::CDAMP2},
        {"CDAMP2D", cards::types::CDAMP2D},
        {"CDAMP3", cards::types::CDAMP3},
        {"CDAMP4", cards::types::CDAMP4},
        {"CDAMP5", cards::types::CDAMP5},
        {"CDUM1", cards::types::CDUM1},
        {"CDUM2", cards::types::CDUM2},
        {"CDUM3", cards::types::CDUM3},
        {"CDUM4", cards::types::CDUM4},
        {"CDUM5", cards::types::CDUM5},
        {"CDUM6", cards::types::CDUM6},
        {"CDUM7", cards::types::CDUM7},
        {"CDUM8", cards::types::CDUM8},
        {"CDUM9", cards::types::CDUM9},
        {"CELAS1", cards::types::CELAS1},
        {"CELAS1D", cards::types::CELAS1D},
        {"CELAS2", cards::types::CELAS2},
        {"CELAS2D", cards::types::CELAS2D},
        {"CELAS3", cards::types::CELAS3},
        {"CELAS4", cards::types::CELAS4},
        {"CFILLET", cards::types::CFILLET},
        {"CFLUID2", cards::types::CFLUID2},
        {"CFLUID3", cards::types::CFLUID3},
        {"CFLUID4", cards::types::CFLUID4},
        {"CGAP", cards::types::CGAP},
        {"CHACAB", cards::types::CHACAB},
        {"CHACBR", cards::types::CHACBR},
        {"CHBDYE", cards::types::CHBDYE},
        {"CHBDYG", cards::types::CHBDYG},
        {"CHBDYP", cards::types::CHBDYP},
        {"CHEXA", cards::types::CHEXA},
        {"CMASS1", cards::types::CMASS1},
        {"CMASS3", cards::types::CMASS3},
        {"COMBWLD", cards::types::COMBWLD},
        {"CONM1", cards::types::CONM1},
        {"CONM2", cards::types::CONM2},
        {"CONROD", cards::types::CONROD},
        {"CPENTA", cards::types::CPENTA},
        {"CQUAD8", cards::types::CQUAD8},
        {"CQUAD", cards::types::CQUAD},
        {"CQUADR", cards::types::CQUADR},
        {"CQUADX", cards::types::CQUADX},
        {"CRAC2D", cards::types::CRAC2D},
        {"CRAC3D", cards::types::CRAC3D},
        {"CSHEAR", cards::types::CSHEAR},
        {"CSLOT3", cards::types::CSLOT3},
        {"CSLOT4", cards::types::CSLOT4},
        {"CSPOT", cards::types::CSPOT},
        {"CTETRA", cards::types::CTETRA},
        {"CTRIA6", cards::types::CTRIA6},
        {"CTRIAR", cards::types::CTRIAR},
        {"CTRIAX6", cards::types::CTRIAX6},
        {"CTRIAX", cards::types::CTRIAX},
        {"CTUBE", cards::types::CTUBE},
        {"CVISC", cards::types::CVISC},
        {"ELEMENT", cards::types::ELEMENT},
        {"GENEL", cards::types::GENEL},
        {"GMINTC", cards::types::GMINTC},
        {"GMINTS", cards::types::GMINTS},
        {"PLOTEL", cards::types::PLOTEL},
        {"RBAR1", cards::types::RBAR1},
        {"RBAR", cards::types::RBAR},
        {"RBE1", cards::types::RBE1},
        {"RBE2", cards::types::RBE2},
        {"RBE3", cards::types::RBE3},
        {"RBE3D", cards::types::RBE3D},
        {"RJOINT", cards::types::RJOINT},
        {"RROD", cards::types::RROD},
        {"RSPLINE", cards::types::RSPLINE},
        {"RSSCON", cards::types::RSSCON},
        {"RTRPLT1", cards::types::RTRPLT1},
        {"RTRPLT", cards::types::RTRPLT},
        {"SPLINE1", cards::types::SPLINE1},
        {"SPLINE2", cards::types::SPLINE2},
        {"SPLINE3", cards::types::SPLINE3},
        {"SPLINE4", cards::types::SPLINE4},
        {"SPLINE5", cards::types::SPLINE5}});
}

void (*cards::note_report)(std::string const &) = &_stdout_report;

void (*cards::info_report)(std::string const &) = &_stderr_report;

void (*cards::warn_report)(std::string const &) = &_stderr_report;

void (*cards::error_report)(std::string const &) = &_stderr_report;

cards::__base::card::card(std::list<std::string> const &inp) {}

cards::__base::card::card() {}

cards::__base::card::~card() {}

bdf::types::empty cards::__base::card::empty = bdf::types::empty();

std::set<char> const cards::__base::card::free_form_cont({'+', '*', ','});

cards::__base::card const &cards::__base::card::operator() (
    std::list<std::string> const &inp) {
    this->read(inp);
    return *this;
}

std::string cards::__base::card::format_outlist(
    std::list<std::unique_ptr<format_entry> > const &en) {

    unsigned long i = 0;
    std::ostringstream res("");

    try {
        for (auto &p : en) {
            if (++i > 9) {
                i = 2;
                res << std::endl << bdf::types::card("").format(nullptr);
            }
            res << p->first->format(p->second);
        }
    } catch (errors::form_error) {
        unsigned long lines = 0;
        res.seekp(0);
        i = 0;
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        for (auto &p : en) {
            if (++i > 5) {
                lines += 1;
                i = 2;
                res << std::endl << bdf::types::card("").format(nullptr);
            }
            res << p->first->format(p->second);
        }
        if (!(lines%2))
            res << std::endl << bdf::types::card("").format(nullptr);
        bdf::types::base::out_form = bdf::types::out_form_type::SHORT;
    }
    return res.str();
}

bdf::types::card cards::__base::card::head = bdf::types::card("<DUMMY>");

void cards::__base::card::card_split(
    std::list<std::string> const &inp, std::list<std::string> &res) {

    res.clear();

    bool first{true};

    for (auto pos=inp.begin(); pos!=inp.end(); ++pos) {
        std::string head = string::string(pos->substr(0, 8)).trim();
        // Free Field Format
        if (head.find(',') != std::string::npos) {
            if (first) {
                res.push_back(string::string(
                                  head.substr(0, head.find(','))).trim("*"));
            }
            auto tmp(string::string(*pos).trim(" \t\n"));
            tmp = string::string(tmp.substr(tmp.find(',') + 1));

            auto tail(tmp.substr(tmp.rfind(',')+1));

            while (tail.length() == 0 ||
                   free_form_cont.find(tail.at(0)) != free_form_cont.end()) {
                if (tail.length() != 0)
                    tmp = string::string(tmp.substr(0, tmp.rfind(',') + 1));
                ++pos;
                tmp.append(string::string(
                               pos->substr(pos->find(',')+1)).trim(" \t\n"));
                tail = tmp.substr(tmp.rfind(',')+1);
            }
            while (tmp.find(',') != std::string::npos) {
                res.push_back(
                    string::string(
                        tmp.substr(0, tmp.find(','))).trim(" \n\t"));
                tmp = string::string(tmp.substr(tmp.find(',') + 1));
            }
            res.push_back(tmp);
            first = false;
            // Long Field Format
        } else {
            if (first) {
                res.push_back(string::string(head).trim("\t\n*"));
            }
            if (head.length() > 0 && head.back() == '*') {
                std::string tmp(pos->length() > 8 ? pos->substr(8) : "");
                tmp.resize(64, ' ');
                if (++pos != inp.end()) {
                    if (pos->length() > 8)
                        tmp += string::string((pos)->substr(8)).trim("\t\n");
                } else {
                    --pos;
                    std::ostringstream msg(
                        "Long Field Format: Missing continuation line for record:\n",
                        std::ostringstream::ate);
                    for (auto l : inp) msg << "--> " << l << std::endl;
                    (*warn_report)(msg.str());
                }
                tmp.resize(128, ' ');
                for (int i=0; i<8; ++i) {
                    res.push_back(
                        string::string(tmp.substr(i*16, 16)).trim(" \t\n"));
                }
                // Short Field Format
            } else {
                auto tmp(*pos);
                tmp.resize(80, ' ');
                tmp = tmp.substr(8);
                for (int i=0; i<8; ++i) {
                    res.push_back(string::string(tmp.substr(i*8, 8)).trim(" \t\n"));
                }
            }
            first = false;
        }
    }
}

std::ostream &cards::__base::card::put(std::ostream &os) const {

    std::list<std::unique_ptr<format_entry> > entries;

    this->collect_outdata(entries);

    if (entries.size()>0)
        os << this->format_outlist(entries) << std::endl;

    return os;
}

void cards::dispatch(
    std::list<std::string> const &inp,
    std::unique_ptr<__base::card> &res) {

    res = nullptr;

    if (inp.empty()) {
        res = std::make_unique<unknown>(inp);
        return;
    }

    try {
        switch (cardtype_map.at(inp.front())) {
        case types::GRID:
            res = std::make_unique<grid>(inp);
            break;
        case types::CTRIA3:
            res = std::make_unique<ctria3>(inp);
            break;
        case types::CQUAD4:
            res = std::make_unique<cquad4>(inp);
            break;
        case types::CBEAM:
            res = std::make_unique<cbeam>(inp);
            break;
        case types::CBAR:
            res = std::make_unique<cbar>(inp);
            break;
        case types::CROD:
            res = std::make_unique<crod>(inp);
            break;
        case types::PSHELL:
            res = std::make_unique<pshell>(inp);
            break;
        case types::PBEAM:
            res = std::make_unique<pbeam>(inp);
            break;
        case types::PBEAML:
            res = std::make_unique<pbeaml>(inp);
            break;
        case types::PBAR:
            res = std::make_unique<pbar>(inp);
            break;
        case types::PBARL:
            res = std::make_unique<pbarl>(inp);
            break;
        case types::PROD:
            res = std::make_unique<prod>(inp);
            break;
        case types::MAT1:
            res = std::make_unique<mat1>(inp);
            break;
        case types::MAT2:
            res = std::make_unique<mat2>(inp);
            break;
        case types::ENDDATA:
            res = std::make_unique<enddata>(inp);
            break;
        case types::FORCE:
            res = std::make_unique<force>(inp);
            break;
        case types::MOMENT:
            res = std::make_unique<moment>(inp);
            break;
        case types::CMASS2:
            res = std::make_unique<cmass2>(inp);
            break;
        case types::CMASS4:
            res = std::make_unique<cmass4>(inp);
            break;
        case types::GRAV:
            res = std::make_unique<grav>(inp);
            break;
        case types::LOAD:
            res = std::make_unique<load>(inp);
            break;
        case types::PARAM:
            res = std::make_unique<param>(inp);
            break;
            /// Elements only supported to allow counting.
        case types::CAABSF:
        case types::CAERO1:
        case types::CAERO2:
        case types::CAERO3:
        case types::CAERO4:
        case types::CAERO5:
        case types::CAXIF2:
        case types::CAXIF3:
        case types::CAXIF4:
        case types::CBEND:
        case types::CBUSH1D:
        case types::CBUSH:
        case types::CBUTT:
        case types::CCONEAX:
        case types::CCRSFIL:
        case types::CDAMP1:
        case types::CDAMP1D:
        case types::CDAMP2:
        case types::CDAMP2D:
        case types::CDAMP3:
        case types::CDAMP4:
        case types::CDAMP5:
        case types::CDUM1:
        case types::CDUM2:
        case types::CDUM3:
        case types::CDUM4:
        case types::CDUM5:
        case types::CDUM6:
        case types::CDUM7:
        case types::CDUM8:
        case types::CDUM9:
        case types::CELAS1:
        case types::CELAS1D:
        case types::CELAS2:
        case types::CELAS2D:
        case types::CELAS3:
        case types::CELAS4:
        case types::CFILLET:
        case types::CFLUID2:
        case types::CFLUID3:
        case types::CFLUID4:
        case types::CGAP:
        case types::CHACAB:
        case types::CHACBR:
        case types::CHBDYE:
        case types::CHBDYG:
        case types::CHBDYP:
        case types::CHEXA:
        case types::CMASS1:
        case types::CMASS3:
        case types::COMBWLD:
        case types::CONM1:
        case types::CONM2:
        case types::CONROD:
        case types::CPENTA:
        case types::CQUAD8:
        case types::CQUAD:
        case types::CQUADR:
        case types::CQUADX:
        case types::CRAC2D:
        case types::CRAC3D:
        case types::CSHEAR:
        case types::CSLOT3:
        case types::CSLOT4:
        case types::CSPOT:
        case types::CTETRA:
        case types::CTRIA6:
        case types::CTRIAR:
        case types::CTRIAX6:
        case types::CTRIAX:
        case types::CTUBE:
        case types::CVISC:
        case types::ELEMENT:
        case types::GENEL:
        case types::GMINTC:
        case types::GMINTS:
        case types::PLOTEL:
        case types::RBAR1:
        case types::RBAR:
        case types::RBE1:
        case types::RBE2:
        case types::RBE3:
        case types::RBE3D:
        case types::RJOINT:
        case types::RROD:
        case types::RSPLINE:
        case types::RSSCON:
        case types::RTRPLT1:
        case types::RTRPLT:
        case types::SPLINE1:
        case types::SPLINE2:
        case types::SPLINE3:
        case types::SPLINE4:
        case types::SPLINE5:
            res = std::make_unique<__base::element>(inp);
            break;
            /// These are not real card types, they can't be returned
        case types::UNKNOWN:
        case types::BEAM_PROP:
        case types::BAR_PROP:
        case types::BEAM_BASE:
        case types::CAXIFi:
            res = std::make_unique<unknown>(inp);
        }
    } catch (std::out_of_range) {
        res = std::make_unique<unknown>(inp);
    }
}

unknown::unknown(std::list<std::string> const &inp) :
        card(inp), content(inp) {};

cards::types unknown::card_type() const {
    return types::UNKNOWN;
}

void unknown::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    throw errors::error("UNKNOWN", "can't write UNKNOWN.");
}

void unknown::read(std::list<std::string> const &inp) {
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
