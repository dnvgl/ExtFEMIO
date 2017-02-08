/**
   \file bdf/bdf_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definition for Nastran BDF cards.

   Detailed description
*/

#include "StdAfx.h"

#include "extfem_misc.h"

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
    void const _stderr_report(std::string const &msg) {
        std::cerr << msg << std::endl;
    }

    void const _stdout_report(std::string const &msg) {
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

void const (*cards::note_report)(std::string const &) = &_stdout_report;

void const (*cards::info_report)(std::string const &) = &_stderr_report;

void const (*cards::warn_report)(std::string const &) = &_stderr_report;

void const (*cards::error_report)(std::string const &) = &_stderr_report;

cards::__base::card::card(std::list<std::string> const &inp) {}

cards::__base::card::card(void) {}

cards::__base::card::~card(void) {}

bdf::types::empty cards::__base::card::empty = bdf::types::empty();

std::set<char> const cards::__base::card::free_form_cont({'+', '*', ','});

cards::__base::card const &cards::__base::card::operator() (
    std::list<std::string> const &inp) {
    this->read(inp);
    return *this;
}

std::string cards::__base::card::format_outlist(
    std::list<std::unique_ptr<format_entry> > const &en) const {

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
    std::string head;

    res.clear();

    bool first = true;

    for (auto pos=inp.begin(); pos!=inp.end(); ++pos) {
        head = dnvgl::extfem::string::string(pos->substr(0, 8)).trim();
        // Free Field Format
        if (head.find(',') != std::string::npos) {
            if (first) {
                res.push_back(dnvgl::extfem::string::string(
                                  head.substr(0, head.find(','))).trim("*"));
            }
            auto tmp(dnvgl::extfem::string::string(*pos).trim(" \t\n"));
            tmp = tmp.substr(tmp.find(',')+1);

            auto tail(tmp.substr(tmp.rfind(',')+1));

            while (tail.length() == 0 ||
                   free_form_cont.find(tail.at(0)) != free_form_cont.end()) {
                if (tail.length() != 0)
                    tmp = tmp.substr(0, tmp.rfind(',')+1);
                ++pos;
                tmp.append(extfem::string::string(
                               pos->substr(pos->find(',')+1)).trim(" \t\n"));
                tail = tmp.substr(tmp.rfind(',')+1);
            }
            while (tmp.find(',') != std::string::npos) {
                res.push_back(
                    extfem::string::string(
                        tmp.substr(0, tmp.find(','))).trim(" \n\t"));
                tmp = tmp.substr(tmp.find(',')+1);
            }
            res.push_back(tmp);
            first = false;
            // Long Field Format
        } else {
            if (first) {
                res.push_back(extfem::string::string(head).trim("\t\n*"));
            }
            if (head.length() > 0 && head.back() == '*') {
                std::string tmp(pos->length() > 8 ? pos->substr(8) : "");
                tmp.resize(64, ' ');
                if (++pos != inp.end()) {
                    if (pos->length() > 8)
                        tmp += extfem::string::string((pos)->substr(8)).trim("\t\n");
                } else {
                    pos--;
                    std::ostringstream msg(
                        "Long Field Format: Missing continuation line for record:\n",
                        std::ostringstream::ate);
                    for (auto l : inp) msg << "--> " << l << std::endl;
                    (*warn_report)(msg.str());
                }
                tmp.resize(128, ' ');
                for (int i=0; i<8; ++i) {
                    res.push_back(
                        extfem::string::string(tmp.substr(i*16, 16)).trim(" \t\n"));
                }
                // Short Field Format
            } else {
                auto tmp(*pos);
                tmp.resize(80, ' ');
                tmp = tmp.substr(8);
                for (int i=0; i<8; ++i) {
                    res.push_back(extfem::string::string(tmp.substr(i*8, 8)).trim(" \t\n"));
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
    std::unique_ptr<cards::__base::card> &res) {

    res = nullptr;

    if (inp.empty()) {
        res = std::make_unique<bdf::cards::unknown>(inp);
        return;
    }

    try {
        switch (cardtype_map.at(inp.front())) {
        case cards::types::GRID:
            res = std::make_unique<bdf::cards::grid>(inp);
            break;
        case cards::types::CTRIA3:
            res = std::make_unique<bdf::cards::ctria3>(inp);
            break;
        case cards::types::CQUAD4:
            res = std::make_unique<bdf::cards::cquad4>(inp);
            break;
        case cards::types::CBEAM:
            res = std::make_unique<bdf::cards::cbeam>(inp);
            break;
        case cards::types::CBAR:
            res = std::make_unique<bdf::cards::cbar>(inp);
            break;
        case cards::types::CROD:
            res = std::make_unique<bdf::cards::crod>(inp);
            break;
        case cards::types::PSHELL:
            res = std::make_unique<bdf::cards::pshell>(inp);
            break;
        case cards::types::PBEAM:
            res = std::make_unique<bdf::cards::pbeam>(inp);
            break;
        case cards::types::PBEAML:
            res = std::make_unique<bdf::cards::pbeaml>(inp);
            break;
        case cards::types::PBAR:
            res = std::make_unique<bdf::cards::pbar>(inp);
            break;
        case cards::types::PBARL:
            res = std::make_unique<bdf::cards::pbarl>(inp);
            break;
        case cards::types::PROD:
            res = std::make_unique<bdf::cards::prod>(inp);
            break;
        case cards::types::MAT1:
            res = std::make_unique<bdf::cards::mat1>(inp);
            break;
        case cards::types::MAT2:
            res = std::make_unique<bdf::cards::mat2>(inp);
            break;
        case cards::types::ENDDATA:
            res = std::make_unique<bdf::cards::enddata>(inp);
            break;
        case cards::types::FORCE:
            res = std::make_unique<bdf::cards::force>(inp);
            break;
        case cards::types::MOMENT:
            res = std::make_unique<bdf::cards::moment>(inp);
            break;
        case cards::types::CMASS2:
            res = std::make_unique<bdf::cards::cmass2>(inp);
            break;
        case cards::types::CMASS4:
            res = std::make_unique<bdf::cards::cmass4>(inp);
            break;
        case cards::types::GRAV:
            res = std::make_unique<bdf::cards::grav>(inp);
            break;
        case cards::types::LOAD:
            res = std::make_unique<bdf::cards::load>(inp);
            break;
        case cards::types::PARAM:
            res = std::make_unique<bdf::cards::param>(inp);
            break;
            /// Elements only supported to allow counting.
        case cards::types::CAABSF:
        case cards::types::CAERO1:
        case cards::types::CAERO2:
        case cards::types::CAERO3:
        case cards::types::CAERO4:
        case cards::types::CAERO5:
        case cards::types::CAXIF2:
        case cards::types::CAXIF3:
        case cards::types::CAXIF4:
        case cards::types::CBEND:
        case cards::types::CBUSH1D:
        case cards::types::CBUSH:
        case cards::types::CBUTT:
        case cards::types::CCONEAX:
        case cards::types::CCRSFIL:
        case cards::types::CDAMP1:
        case cards::types::CDAMP1D:
        case cards::types::CDAMP2:
        case cards::types::CDAMP2D:
        case cards::types::CDAMP3:
        case cards::types::CDAMP4:
        case cards::types::CDAMP5:
        case cards::types::CDUM1:
        case cards::types::CDUM2:
        case cards::types::CDUM3:
        case cards::types::CDUM4:
        case cards::types::CDUM5:
        case cards::types::CDUM6:
        case cards::types::CDUM7:
        case cards::types::CDUM8:
        case cards::types::CDUM9:
        case cards::types::CELAS1:
        case cards::types::CELAS1D:
        case cards::types::CELAS2:
        case cards::types::CELAS2D:
        case cards::types::CELAS3:
        case cards::types::CELAS4:
        case cards::types::CFILLET:
        case cards::types::CFLUID2:
        case cards::types::CFLUID3:
        case cards::types::CFLUID4:
        case cards::types::CGAP:
        case cards::types::CHACAB:
        case cards::types::CHACBR:
        case cards::types::CHBDYE:
        case cards::types::CHBDYG:
        case cards::types::CHBDYP:
        case cards::types::CHEXA:
        case cards::types::CMASS1:
        case cards::types::CMASS3:
        case cards::types::COMBWLD:
        case cards::types::CONM1:
        case cards::types::CONM2:
        case cards::types::CONROD:
        case cards::types::CPENTA:
        case cards::types::CQUAD8:
        case cards::types::CQUAD:
        case cards::types::CQUADR:
        case cards::types::CQUADX:
        case cards::types::CRAC2D:
        case cards::types::CRAC3D:
        case cards::types::CSHEAR:
        case cards::types::CSLOT3:
        case cards::types::CSLOT4:
        case cards::types::CSPOT:
        case cards::types::CTETRA:
        case cards::types::CTRIA6:
        case cards::types::CTRIAR:
        case cards::types::CTRIAX6:
        case cards::types::CTRIAX:
        case cards::types::CTUBE:
        case cards::types::CVISC:
        case cards::types::ELEMENT:
        case cards::types::GENEL:
        case cards::types::GMINTC:
        case cards::types::GMINTS:
        case cards::types::PLOTEL:
        case cards::types::RBAR1:
        case cards::types::RBAR:
        case cards::types::RBE1:
        case cards::types::RBE2:
        case cards::types::RBE3:
        case cards::types::RBE3D:
        case cards::types::RJOINT:
        case cards::types::RROD:
        case cards::types::RSPLINE:
        case cards::types::RSSCON:
        case cards::types::RTRPLT1:
        case cards::types::RTRPLT:
        case cards::types::SPLINE1:
        case cards::types::SPLINE2:
        case cards::types::SPLINE3:
        case cards::types::SPLINE4:
        case cards::types::SPLINE5:
            res = std::make_unique<bdf::cards::__base::element>(inp);
            break;
            /// These are not real card types, they can't be returned
        case cards::types::UNKNOWN:
        case cards::types::BEAM_PROP:
        case cards::types::BAR_PROP:
        case cards::types::BEAM_BASE:
        case cards::types::CAXIFi:
            res = std::make_unique<bdf::cards::unknown>(inp);
        }
    } catch (std::out_of_range) {
        res = std::make_unique<bdf::cards::unknown>(inp);
    }
}

unknown::unknown(std::list<std::string> const &inp) :
        card(inp), content(inp) {};

cards::types const unknown::card_type(void) const {
    return types::UNKNOWN;
}

void unknown::collect_outdata(
    std::list<std::unique_ptr<format_entry> > &res) const {
    throw errors::error("UNKNOWN", "can't write UNKNOWN.");
    return;
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
