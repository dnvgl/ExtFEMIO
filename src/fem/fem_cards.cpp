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

namespace {
   const size_t map_pair_entries = 8;
   const pair<::std::string, types> map_pairs[map_pair_entries] = {
      // UNKNOWN,
      pair<::std::string, types>("DATE", fem::cards::DATE),
      pair<::std::string, types>("GCOORD", GCOORD),
      pair<::std::string, types>("GNODE", GNODE),
      pair<::std::string, types>("IDENT", IDENT),
      pair<::std::string, types>("IEND", IEND),
      pair<::std::string, types>("GELMNT1", GELMNT1),
      pair<::std::string, types>("GELREF1", GELREF1),
      // pair<::std::string, types>("GBARM", GBARM),
      // pair<::std::string, types>("GBEAMG", GBEAMG),
      // pair<::std::string, types>("GECCEN", GECCEN),
      // pair<::std::string, types>("GELTH", GELTH),
      // pair<::std::string, types>("GIORH", GIORH),
      // pair<::std::string, types>("GLSEC", GLSEC),
      // pair<::std::string, types>("GPIPE", GPIPE),
      // pair<::std::string, types>("BLDEP", BLDEP),
      // pair<::std::string, types>("BNBCD", BNBCD),
      // pair<::std::string, types>("BNDISPL", BNDISPL),
      // pair<::std::string, types>("BNLOAD", BNLOAD),
      // pair<::std::string, types>("MGSPRNG", MGSPRNG),
      // pair<::std::string, types>("GSETMEMB", GSETMEMB),
      // pair<::std::string, types>("GUNIVEC", GUNIVEC),
      // pair<::std::string, types>("MISOSEL", MISOSEL),
      // pair<::std::string, types>("TDSETNAM", TDSETNAM),
      pair<::std::string, types>("TEXT", TEXT),
      // pair<::std::string, types>("TDLOAD", TDLOAD),
   };
}

const map<::std::string, types>
   cardtype_map(map_pairs, map_pairs + map_pair_entries);

deque<::std::string>
card::card_split(deque<::std::string> const &inp) {
   deque<::std::string> res;
   ::std::string head;

   bool first = true;

   for (auto &pos : inp) {
      head = extfem::string::string(pos.substr(0, 8)).trim();
      if (first) {
         res.push_back(extfem::string::string(head).trim("\t\n"));
      }
      auto tmp(pos);
      tmp.resize(80, ' ');
      tmp = tmp.substr(8);
      for (int i=0; i<4; ++i) {
         res.push_back(tmp.substr(i*16, 16));
      }
      first = false;
   }
   return res;
}

void
fem::cards::dispatch(const deque<::std::string> &inp,
                     ::std::unique_ptr<fem::cards::card> &res) {

   try {
      ::std::string key(inp.at(0));
      switch (cardtype_map.at(key)) {
      case DATE:
         res = ::std::make_unique<fem::cards::date>(inp);
         break;
      case GCOORD:
         res = ::std::make_unique<fem::cards::gcoord>(inp);
         break;
      case GNODE:
         res = ::std::make_unique<fem::cards::gnode>(inp);
         break;
      case IDENT:
         res = ::std::make_unique<fem::cards::ident>(inp);
         break;
      case IEND:
         res = ::std::make_unique<fem::cards::iend>(inp);
         break;
      case GELMNT1:
         res = ::std::make_unique<fem::cards::gelmnt1>(inp);
         break;
      case GELREF1:
         res = ::std::make_unique<fem::cards::gelref1>(inp);
         break;
      case TEXT:
         res = ::std::make_unique<fem::cards::text>(inp);
         break;
         // These are not real card types, they can't be returned
      case UNKNOWN:
         res = nullptr;
      }
   } catch (out_of_range) {
      res = ::std::make_unique<fem::cards::unknown>(inp);
   }
}


// Local Variables:
// mode: c++
// ispell-local-dictionary: "english"
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../.. check -j8"
// End:
