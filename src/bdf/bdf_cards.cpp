// Copyright © 2015 by DNV GL SE

// Purpose: Base definition for Nastran BDF cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

#include "StdAfx.h"

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

using namespace ::std;
using namespace ::dnvgl;
using namespace extfem;
using namespace bdf::cards;

bdf::cards::card::card(const deque<std::string> &inp) {}

bdf::cards::card::card() {}

namespace {
  const char initVals[3] = { '+', '*', ',' };
}

bdf::types::empty card::empty = bdf::types::empty();

bdf::types::card card::head = bdf::types::card("<DUMMY>");

const set<char> card::free_form_cont(initVals, initVals + 3);

std::string card::format_outlist(
  const ::std::deque<std::unique_ptr<format_entry>> &en) const {

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

deque<std::string> card::card_split(deque<std::string> const &inp) {
  deque<std::string> res;
  ::std::string head;

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
        ::std::string tmp(pos->substr(8));
        tmp.resize(64, ' ');
        if ((++pos)->length() > 8)
            tmp += extfem::string::string((pos)->substr(8)).trim("\t\n");
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
  return res;
}

std::unique_ptr<bdf::cards::card> bdf::cards::dispatch(const deque<std::string> &inp) {

  try {
    ::std::string key(inp.at(0));
    switch (cardtype_map.at(key)) {
    case GRID:
      return ::std::make_unique<bdf::cards::grid>(inp);
    case CTRIA3:
      return ::std::make_unique<bdf::cards::ctria3>(inp);
    case CQUAD4:
      return ::std::make_unique<bdf::cards::cquad4>(inp);
    case CBEAM:
      return ::std::make_unique<bdf::cards::cbeam>(inp);
    case CBAR:
      return ::std::make_unique<bdf::cards::cbar>(inp);
    case CROD:
      return ::std::make_unique<bdf::cards::crod>(inp);
    case PSHELL:
      return ::std::make_unique<bdf::cards::pshell>(inp);
    case PBEAM:
      return ::std::make_unique<bdf::cards::pbeam>(inp);
    case PBEAML:
      return ::std::make_unique<bdf::cards::pbeaml>(inp);
    case PBAR:
      return ::std::make_unique<bdf::cards::pbar>(inp);
    case PBARL:
      return ::std::make_unique<bdf::cards::pbarl>(inp);
    case PROD:
      return ::std::make_unique<bdf::cards::prod>(inp);
    case MAT1:
      return ::std::make_unique<bdf::cards::mat1>(inp);
    case ENDDATA:
      return ::std::make_unique<bdf::cards::enddata>(inp);
    case FORCE:
      return ::std::make_unique<bdf::cards::force>(inp);
    case MOMENT:
      return ::std::make_unique<bdf::cards::moment>(inp);
    case LOAD:
      return ::std::make_unique<bdf::cards::load>(inp);
    // These are not real card types, they can't be returned
    case UNKNOWN:
    case BEAM_PROP:
    case BAR_PROP:
    case BEAM_BASE:
      return nullptr;
    }
  } catch (out_of_range) {
    return ::std::make_unique<bdf::cards::unknown>(inp);
  }
  return nullptr;
}

// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. doxyfile.stamp check -j 8"
// End:
