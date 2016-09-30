/**
   \file bdf/bdf_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definition for Nastran BDF cards.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   char const cID_bdf_cards[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
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
   char const initVals[3] = { '+', '*', ',' };

   void const _stderr_report(std::string const &msg) {
      std::cerr << msg << std::endl;
   }

   void const _stdout_report(std::string const &msg) {
      std::cout << msg << std::endl;
   }

   size_t const map_pairs_num = 116;
   std::pair<std::string, cards::types> const map_pairs[map_pairs_num] = {
      std::pair<std::string, cards::types>("GRID", cards::types::GRID),
      std::pair<std::string, cards::types>("MAT1", cards::types::MAT1),
      std::pair<std::string, cards::types>("CTRIA3", cards::types::CTRIA3),
      std::pair<std::string, cards::types>("CQUAD4", cards::types::CQUAD4),
      std::pair<std::string, cards::types>("PSHELL", cards::types::PSHELL),
      std::pair<std::string, cards::types>("CBEAM", cards::types::CBEAM),
      std::pair<std::string, cards::types>("PBEAM", cards::types::PBEAM),
      std::pair<std::string, cards::types>("PBEAML", cards::types::PBEAML),
      std::pair<std::string, cards::types>("CBAR", cards::types::CBAR),
      std::pair<std::string, cards::types>("PBAR", cards::types::PBAR),
      std::pair<std::string, cards::types>("PBARL", cards::types::PBARL),
      std::pair<std::string, cards::types>("CROD", cards::types::CROD),
      std::pair<std::string, cards::types>("PROD", cards::types::PROD),
      std::pair<std::string, cards::types>("ENDDATA", cards::types::ENDDATA),
      std::pair<std::string, cards::types>("MAT2", cards::types::MAT2),
      std::pair<std::string, cards::types>("FORCE", cards::types::FORCE),
      std::pair<std::string, cards::types>("MOMENT", cards::types::MOMENT),
      std::pair<std::string, cards::types>("CMASS2", cards::types::CMASS2),
      std::pair<std::string, cards::types>("CMASS4", cards::types::CMASS4),
      std::pair<std::string, cards::types>("GRAV", cards::types::GRAV),
      std::pair<std::string, cards::types>("LOAD", cards::types::LOAD),
      std::pair<std::string, cards::types>("CAABSF", cards::types::CAABSF),
      std::pair<std::string, cards::types>("CAERO1", cards::types::CAERO1),
      std::pair<std::string, cards::types>("CAERO2", cards::types::CAERO2),
      std::pair<std::string, cards::types>("CAERO3", cards::types::CAERO3),
      std::pair<std::string, cards::types>("CAERO4", cards::types::CAERO4),
      std::pair<std::string, cards::types>("CAERO5", cards::types::CAERO5),
      std::pair<std::string, cards::types>("CAXIF2", cards::types::CAXIF2),
      std::pair<std::string, cards::types>("CAXIF3", cards::types::CAXIF3),
      std::pair<std::string, cards::types>("CAXIF4", cards::types::CAXIF4),
      std::pair<std::string, cards::types>("CAXIFi", cards::types::CAXIFi),
      std::pair<std::string, cards::types>("CBEND", cards::types::CBEND),
      std::pair<std::string, cards::types>("CBUSH1D", cards::types::CBUSH1D),
      std::pair<std::string, cards::types>("CBUSH", cards::types::CBUSH),
      std::pair<std::string, cards::types>("CBUTT", cards::types::CBUTT),
      std::pair<std::string, cards::types>("CCONEAX", cards::types::CCONEAX),
      std::pair<std::string, cards::types>("CCRSFIL", cards::types::CCRSFIL),
      std::pair<std::string, cards::types>("CDAMP1", cards::types::CDAMP1),
      std::pair<std::string, cards::types>("CDAMP1D", cards::types::CDAMP1D),
      std::pair<std::string, cards::types>("CDAMP2", cards::types::CDAMP2),
      std::pair<std::string, cards::types>("CDAMP2D", cards::types::CDAMP2D),
      std::pair<std::string, cards::types>("CDAMP3", cards::types::CDAMP3),
      std::pair<std::string, cards::types>("CDAMP4", cards::types::CDAMP4),
      std::pair<std::string, cards::types>("CDAMP5", cards::types::CDAMP5),
      std::pair<std::string, cards::types>("CDUM1", cards::types::CDUM1),
      std::pair<std::string, cards::types>("CDUM2", cards::types::CDUM2),
      std::pair<std::string, cards::types>("CDUM3", cards::types::CDUM3),
      std::pair<std::string, cards::types>("CDUM4", cards::types::CDUM4),
      std::pair<std::string, cards::types>("CDUM5", cards::types::CDUM5),
      std::pair<std::string, cards::types>("CDUM6", cards::types::CDUM6),
      std::pair<std::string, cards::types>("CDUM7", cards::types::CDUM7),
      std::pair<std::string, cards::types>("CDUM8", cards::types::CDUM8),
      std::pair<std::string, cards::types>("CDUM9", cards::types::CDUM9),
      std::pair<std::string, cards::types>("CELAS1", cards::types::CELAS1),
      std::pair<std::string, cards::types>("CELAS1D", cards::types::CELAS1D),
      std::pair<std::string, cards::types>("CELAS2", cards::types::CELAS2),
      std::pair<std::string, cards::types>("CELAS2D", cards::types::CELAS2D),
      std::pair<std::string, cards::types>("CELAS3", cards::types::CELAS3),
      std::pair<std::string, cards::types>("CELAS4", cards::types::CELAS4),
      std::pair<std::string, cards::types>("CFILLET", cards::types::CFILLET),
      std::pair<std::string, cards::types>("CFLUID2", cards::types::CFLUID2),
      std::pair<std::string, cards::types>("CFLUID3", cards::types::CFLUID3),
      std::pair<std::string, cards::types>("CFLUID4", cards::types::CFLUID4),
      std::pair<std::string, cards::types>("CGAP", cards::types::CGAP),
      std::pair<std::string, cards::types>("CHACAB", cards::types::CHACAB),
      std::pair<std::string, cards::types>("CHACBR", cards::types::CHACBR),
      std::pair<std::string, cards::types>("CHBDYE", cards::types::CHBDYE),
      std::pair<std::string, cards::types>("CHBDYG", cards::types::CHBDYG),
      std::pair<std::string, cards::types>("CHBDYP", cards::types::CHBDYP),
      std::pair<std::string, cards::types>("CHEXA", cards::types::CHEXA),
      std::pair<std::string, cards::types>("CMASS1", cards::types::CMASS1),
      std::pair<std::string, cards::types>("CMASS3", cards::types::CMASS3),
      std::pair<std::string, cards::types>("COMBWLD", cards::types::COMBWLD),
      std::pair<std::string, cards::types>("CONM1", cards::types::CONM1),
      std::pair<std::string, cards::types>("CONM2", cards::types::CONM2),
      std::pair<std::string, cards::types>("CONROD", cards::types::CONROD),
      std::pair<std::string, cards::types>("CPENTA", cards::types::CPENTA),
      std::pair<std::string, cards::types>("CQUAD8", cards::types::CQUAD8),
      std::pair<std::string, cards::types>("CQUAD", cards::types::CQUAD),
      std::pair<std::string, cards::types>("CQUADR", cards::types::CQUADR),
      std::pair<std::string, cards::types>("CQUADX", cards::types::CQUADX),
      std::pair<std::string, cards::types>("CRAC2D", cards::types::CRAC2D),
      std::pair<std::string, cards::types>("CRAC3D", cards::types::CRAC3D),
      std::pair<std::string, cards::types>("CSHEAR", cards::types::CSHEAR),
      std::pair<std::string, cards::types>("CSLOT3", cards::types::CSLOT3),
      std::pair<std::string, cards::types>("CSLOT4", cards::types::CSLOT4),
      std::pair<std::string, cards::types>("CSPOT", cards::types::CSPOT),
      std::pair<std::string, cards::types>("CTETRA", cards::types::CTETRA),
      std::pair<std::string, cards::types>("CTRIA6", cards::types::CTRIA6),
      std::pair<std::string, cards::types>("CTRIAR", cards::types::CTRIAR),
      std::pair<std::string, cards::types>("CTRIAX6", cards::types::CTRIAX6),
      std::pair<std::string, cards::types>("CTRIAX", cards::types::CTRIAX),
      std::pair<std::string, cards::types>("CTUBE", cards::types::CTUBE),
      std::pair<std::string, cards::types>("CVISC", cards::types::CVISC),
      std::pair<std::string, cards::types>("ELEMENT", cards::types::ELEMENT),
      std::pair<std::string, cards::types>("GENEL", cards::types::GENEL),
      std::pair<std::string, cards::types>("GMINTC", cards::types::GMINTC),
      std::pair<std::string, cards::types>("GMINTS", cards::types::GMINTS),
      std::pair<std::string, cards::types>("PLOTEL", cards::types::PLOTEL),
      std::pair<std::string, cards::types>("RBAR1", cards::types::RBAR1),
      std::pair<std::string, cards::types>("RBAR", cards::types::RBAR),
      std::pair<std::string, cards::types>("RBE1", cards::types::RBE1),
      std::pair<std::string, cards::types>("RBE2", cards::types::RBE2),
      std::pair<std::string, cards::types>("RBE3", cards::types::RBE3),
      std::pair<std::string, cards::types>("RBE3D", cards::types::RBE3D),
      std::pair<std::string, cards::types>("RJOINT", cards::types::RJOINT),
      std::pair<std::string, cards::types>("RROD", cards::types::RROD),
      std::pair<std::string, cards::types>("RSPLINE", cards::types::RSPLINE),
      std::pair<std::string, cards::types>("RSSCON", cards::types::RSSCON),
      std::pair<std::string, cards::types>("RTRPLT1", cards::types::RTRPLT1),
      std::pair<std::string, cards::types>("RTRPLT", cards::types::RTRPLT),
      std::pair<std::string, cards::types>("SPLINE1", cards::types::SPLINE1),
      std::pair<std::string, cards::types>("SPLINE2", cards::types::SPLINE2),
      std::pair<std::string, cards::types>("SPLINE3", cards::types::SPLINE3),
      std::pair<std::string, cards::types>("SPLINE4", cards::types::SPLINE4),
      std::pair<std::string, cards::types>("SPLINE5", cards::types::SPLINE5)};

   std::map<std::string, cards::types> const cardtype_map(
      map_pairs, map_pairs + map_pairs_num);
}

void const (*cards::note_report)(std::string const &) = &_stdout_report;

void const (*cards::info_report)(std::string const &) = &_stderr_report;

void const (*cards::warn_report)(std::string const &) = &_stderr_report;

void const (*cards::error_report)(std::string const &) = &_stderr_report;

cards::__base::card::card(std::list<std::string> const &inp) {}

cards::__base::card::card() {}

bdf::types::empty cards::__base::card::empty = bdf::types::empty();

std::set<char> const cards::__base::card::free_form_cont(
   initVals, initVals + 3);

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
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
