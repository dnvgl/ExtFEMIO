/**
   \file bdf/bdf_cards.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definition for Nastran BDF cards.

   Detailed description
*/

#include "StdAfx.h"

#define _EXTFEMIO_EXPORT_IMPL

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#include "bdf/cards.h"
#include "bdf/errors.h"
#include "extfem_string.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace ::std;
using namespace ::dnvgl;
using namespace extfem;
using namespace bdf::cards;

bdf::cards::card::card(const deque<::std::string> &inp) {}

bdf::cards::card::card() {}

namespace {
   const char initVals[3] = { '+', '*', ',' };
}

bdf::types::empty card::empty = bdf::types::empty();

namespace {
   const void _stderr_warn(std::string &msg) {
      std::cerr << msg << std::endl;
   }
}

namespace dnvgl {
   namespace extfem {
      namespace bdf{
         namespace cards{
            EXTFEMIO_API const void(*warn_report)(std::string&) = &_stderr_warn;
                        
            bdf::types::card card::head = bdf::types::card("<DUMMY>");

            ::std::ostream
               &operator<<(::std::ostream &os, const enddata &card){
               std::deque<std::unique_ptr<format_entry>> entries;
               
               entries.push_back(format(enddata::head));
               os << card.format_outlist(entries) << std::endl;
               return os;
            }
         }
      }
   }
}


const set<char> card::free_form_cont(initVals, initVals + 3);

std::string card::format_outlist(
   const ::std::deque<::std::unique_ptr<format_entry>> &en) const {

   unsigned long i = 0;
   ::std::ostringstream res("");

   try {
      for (auto &p : en) {
         if (++i > 9) {
            i = 2;
            res << ::std::endl << bdf::types::card("").format(nullptr);
         }
         res << p->first->format(p->second);
      }
   } catch (errors::form_error) {
      unsigned long lines = 0;
      res.seekp(0);
      i = 0;
      bdf::types::base::out_form = bdf::types::LONG;
      for (auto &p : en) {
         if (++i > 5) {
            lines += 1;
            i = 2;
            res << ::std::endl << bdf::types::card("").format(nullptr);
         }
         res << p->first->format(p->second);
      }
      if (!(lines%2))
         res << ::std::endl << bdf::types::card("").format(nullptr);
      bdf::types::base::out_form = bdf::types::SHORT;
   }
   return res.str();
}

namespace {
   const size_t map_pairs_num = 14;
   const pair<std::string, types> map_pairs[map_pairs_num] = {
      pair<std::string, types>("GRID", GRID),
      pair<std::string, types>("MAT1", MAT1),
      pair<std::string, types>("CTRIA3", CTRIA3),
      pair<std::string, types>("CQUAD4", CQUAD4),
      pair<std::string, types>("PSHELL", PSHELL),
      pair<std::string, types>("CBEAM", CBEAM),
      pair<std::string, types>("PBEAM", PBEAM),
      pair<std::string, types>("PBEAML", PBEAML),
      pair<std::string, types>("CBAR", CBAR),
      pair<std::string, types>("PBAR", PBAR),
      pair<std::string, types>("PBARL", PBARL),
      pair<std::string, types>("CROD", CROD),
      pair<std::string, types>("PROD", PROD),
      pair<std::string, types>("ENDDATA", ENDDATA)};
}

const map<std::string, types> cardtype_map(
   map_pairs, map_pairs + map_pairs_num);

void
card::card_split(const deque<std::string> &inp,
                 deque<::std::string> &res) {
   ::std::string head;

   res.clear();

   bool first = true;

   for (auto pos=inp.begin(); pos<inp.end(); ++pos) {
      head = extfem::string::string(pos->substr(0, 8)).trim();
      // Free Field Format
      if (head.find(',') != ::std::string::npos) {
         if (first) {
            res.push_back(extfem::string::string(head.substr(0, head.find(','))).trim("*"));
         }
         auto tmp(extfem::string::string(*pos).trim(" \t\n"));
         tmp = tmp.substr(tmp.find(',')+1);

         auto tail(tmp.substr(tmp.rfind(',')+1));

         while (tail.length() == 0 || free_form_cont.find(tail.at(0)) != free_form_cont.end()) {
            if (tail.length() != 0)
               tmp = tmp.substr(0, tmp.rfind(',')+1);
            ++pos;
            tmp.append(extfem::string::string(pos->substr(pos->find(',')+1)).trim(" \t\n"));
            tail = tmp.substr(tmp.rfind(',')+1);
         }
         while (tmp.find(',') != ::std::string::npos) {
            res.push_back(extfem::string::string(tmp.substr(0, tmp.find(','))).trim(" \n\t"));
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
            ::std::string tmp(pos->length() > 8 ? pos->substr(8) : "");
            tmp.resize(64, ' ');
            if ((pos + 1) != inp.end()) {
               if ((++pos)->length() > 8)
                  tmp += extfem::string::string((pos)->substr(8)).trim("\t\n");
            } else {
               std::ostringstream msg("Long Field Format: Missing continuation line for record:\n", std::ostringstream::ate);
               for (auto l : inp) msg << "--> " << l << std::endl;
               (*warn_report)(msg.str());
            }
            tmp.resize(128, ' ');
            for (int i=0; i<8; ++i) {
               res.push_back(extfem::string::string(tmp.substr(i*16, 16)).trim(" \t\n"));
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

void
bdf::cards::dispatch(const deque<std::string> &inp, std::unique_ptr<bdf::cards::card> &res) {

   res = nullptr;

   try {
      ::std::string key(inp.at(0));
      switch (cardtype_map.at(key)) {
      case GRID:
         res = ::std::make_unique<bdf::cards::grid>(inp);
         break;
      case CTRIA3:
         res = ::std::make_unique<bdf::cards::ctria3>(inp);
         break;
      case CQUAD4:
         res = ::std::make_unique<bdf::cards::cquad4>(inp);
         break;
      case CBEAM:
         res = ::std::make_unique<bdf::cards::cbeam>(inp);
         break;
      case CBAR:
         res = ::std::make_unique<bdf::cards::cbar>(inp);
         break;
      case CROD:
         res = ::std::make_unique<bdf::cards::crod>(inp);
         break;
      case PSHELL:
         res = ::std::make_unique<bdf::cards::pshell>(inp);
         break;
      case PBEAM:
         res = ::std::make_unique<bdf::cards::pbeam>(inp);
         break;
      case PBEAML:
         res = ::std::make_unique<bdf::cards::pbeaml>(inp);
         break;
      case PBAR:
         res = ::std::make_unique<bdf::cards::pbar>(inp);
         break;
      case PBARL:
         res = ::std::make_unique<bdf::cards::pbarl>(inp);
         break;
      case PROD:
         res = ::std::make_unique<bdf::cards::prod>(inp);
         break;
      case MAT1:
         res = ::std::make_unique<bdf::cards::mat1>(inp);
         break;
      case MAT2:
         res = ::std::make_unique<bdf::cards::mat2>(inp);
         break;
      case ENDDATA:
         res = ::std::make_unique<bdf::cards::enddata>(inp);
         break;
      case FORCE:
         res = ::std::make_unique<bdf::cards::force>(inp);
         break;
      case MOMENT:
         res = ::std::make_unique<bdf::cards::moment>(inp);
         break;
      case LOAD:
         res = ::std::make_unique<bdf::cards::load>(inp);
         break;
      // These are not real card types, they can't be returned
      case UNKNOWN:
      case BEAM_PROP:
      case BAR_PROP:
      case BEAM_BASE:
         res = ::std::make_unique<bdf::cards::unknown>(inp);
      }
   } catch (out_of_range) {
      res = ::std::make_unique<bdf::cards::unknown>(inp);
   }
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j 8"
// End:
