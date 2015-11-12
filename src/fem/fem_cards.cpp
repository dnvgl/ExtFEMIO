// Copyright © 2015 by DNV GL SE

// Purpose: Base definitions for Sesam FEM cards.

// Author Berthold Höllmann <berthold.hoellmann@dnvgl.com>

// ID:
namespace {
  const char  cID[]
#ifdef __GNUC__
  __attribute__ ((__unused__))
#endif
    = "@(#) $Id$";
}

#include "fem/cards.h"
#include "fem/errors.h"
#include "extfem_string.h"

using namespace ::std;
using namespace ::dnvgl;
using namespace extfem;
using namespace fem::cards;

card::card(const deque<::std::string> &inp) {}

card::card() {}

namespace {
  const char initVals[3] = { '+', '*', ',' };
}

fem::types::empty card::empty = fem::types::empty();

fem::types::card card::head = fem::types::card("<DUMMY>");

::std::string card::format_outlist(
  const ::std::deque<::std::unique_ptr<format_entry>> &en) const {

  unsigned long i = 0;
  ::std::ostringstream res("");

  for (auto &p : en) {
    if (++i > 9) {
      i = 2;
      res << ::std::endl << fem::types::card("").format(nullptr);
    }

    res << p->first->format(p->second);
  }
  return res.str();
}

namespace {
  const size_t map_pair_entries = 1;
  const pair<::std::string, types> map_pairs[map_pair_entries] = {
    pair<::std::string, types>("IDENT", IDENT),
  };
}

const map<::std::string, types>
  cardtype_map(map_pairs, map_pairs + map_pair_entries);

deque<::std::string>
card::card_split(deque<::std::string> const &inp) {
  deque<::std::string> res;
  ::std::string head;

  bool first = true;

  for (auto pos=inp.begin(); pos<inp.end(); ++pos) {
    head = extfem::string::string(pos->substr(0, 8)).trim();
    if (first) {
      res.push_back(extfem::string::string(head).trim("\t\n*"));
    }
    if (head.length() > 0) {
      ::std::string tmp(pos->substr(8));
      tmp.resize(64, ' ');
      if (pos->length() > 8)
        tmp += (pos)->substr(8);
      tmp.resize(128, ' ');
      for (int i=0; i<4; ++i)
        res.push_back(tmp.substr(i*16, 16));
      first = false;
    }
  }
  return res;
}

::std::unique_ptr<fem::cards::card>
fem::cards::dispatch(const deque<::std::string> &inp) {

  try {
    ::std::string key(inp.at(0));
    switch (cardtype_map.at(key)) {
    case IDENT:
      return ::std::make_unique<fem::cards::ident>(inp);
    // These are not real card types, they can't be returned
    case UNKNOWN:
      return nullptr;
    }
  } catch (out_of_range) {
    return ::std::make_unique<fem::cards::unknown>(inp);
  }
  return nullptr;
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
